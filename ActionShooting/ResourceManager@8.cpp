//*============================================================================
//ResourceManager.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "ResourceManager.h"
#include "Factory2D.h"
#include "PathStrAnalizer.h"
#include "SoundManager.h"
#include "SoundFactory.h"
#include "dixsmartptr.h"
//#include "MouseSprite.h"

//============================================================================
//�R���X�g���N�^
//============================================================================
CResourceManager::CResourceManager( ) 
: m_Page(0)
{
	for( int i = 0;i < QUE_MAX;++i )
	{
		m_pQueTop[i] = NULL;
	}
	
	m_mapDraw.clear();
	
	/*�X���b�h�̍쐬*/
	m_Thread.Create( LoadProc, (void*)this );
	
	printf("BOOT ResourceManager\n");
}	

//============================================================================
//�f�X�g���N�^
//============================================================================
CResourceManager::~CResourceManager()
{
	printf("ABORT ResourceManager\n");
	
	/*�I��*/
	m_Event.Set();
	
	/*�X���b�h�̏I���҂�*/
	while( !m_Thread.WaitForExit() )
	{
		Sleep( 100 );
	}
	
	//�`�惊�X�g�̏���
	RemoveAll();
	
	printf("EXIT ResourceManager\n");
	
}

//============================================================================
//�I�u�W�F�N�g�̎擾
//============================================================================
//[input]
//	pName:�f�[�^��
//[return]
//	�擾�����I�u�W�F�N�g
//===========================================================================
sp<CGameObject> CResourceManager::FindObject( const char *pName )
{
	//���b�N���|����
	Thread::CAutoLock Lock( m_CS );

	return m_mapDraw[pName];
}

//============================================================================
//�I�u�W�F�N�g�̃��X�g�ǉ�
//============================================================================
//[input]
//	pDataName:�f�[�^��
//	spGameObj:�Q�[���I�u�W�F�N�g
//===========================================================================
void CResourceManager::AppendList( string strDataName, sp<CGameObject> spGameObj )
{
	m_CS.Enter();
	
	//�p�����[�^�[�̓ǂݍ���
	//pGameObj->LoadParameter( pGameObj->GetDataName() );
	
	//�}�b�v�ɒǉ�
	m_mapDraw.insert( make_pair( strDataName, spGameObj ) );
	
	m_CS.Leave();
}


//============================================================================
//�I�u�W�F�N�g�̏���
//============================================================================
//[input]
//	pDataName:�f�[�^��
//============================================================================
void CResourceManager::RemoveObject( const char *pDataName )
{
	m_CS.Enter();
	
	while( m_itDraw != m_mapDraw.end() )
	{
		if( m_itDraw->first.compare( pDataName ) == 0 )
		{
			printf("REMOVE OBJECT[%s]", pDataName );
			
			sp<CGameObject> spTemp( m_itDraw->second );
			spTemp->SetRemoveFlag( true );
			
			break;
			
		}
		
		else
		{
			m_itDraw++;
		}
	}
	
	m_CS.Leave();
	
}

//============================================================================
//���ׂẴI�u�W�F�N�g�̏���
//============================================================================
void CResourceManager::RemoveAll()
{
	m_mapDraw.clear();
}

//============================================================================
//�I�u�W�F�N�g�̒ǉ�
//============================================================================
//[input]
//	pFile:�ǉ�����f�[�^
//===========================================================================
void CResourceManager::Push( CFileData *pFile )
{
	/*�I��������������?*/
	if( m_Event.IsSignal() )
	{
		return;
	}
	
	//�I�[�g���b�N
	Thread::CAutoLock Lock( m_CS );
	
	/*�擪*/
	if( m_pQueTop[m_Page] == NULL )
	{
		m_pQueTop[m_Page] = pFile;
	}
	
	/*���X�g�̒ǉ�*/
	else
	{
		CFileData *pData = m_pQueTop[m_Page];
		
		while( pData->GetNext() != NULL )
		{
			pData = pData->GetNext();
		}
		
		pData->SetNext( pFile );
	}
	
	pFile->SetNext( NULL );
	
	printf("CResourceManager :PUSH [%s]\n", pFile->GetDataName().c_str() );
	
}

//============================================================================
//�ǂݍ��ݒ����ǂ�������
//============================================================================
//[return]
//	�ǂݍ��ݒ����ǂ���(true:�ǂݍ��ݒ�)
//===========================================================================
Bool CResourceManager::IsLoading()
{
	//�I�[�g���b�N
	Thread::CAutoLock Lock( m_CS );
	
	if( m_pQueTop[0] != NULL )
	{
		return true;
	}
	
	if( m_pQueTop[1] != NULL )
	{
		return true;
	}
	
	return false;
}


//============================================================================
//�N��
//============================================================================
void CResourceManager::Run()
{
	for(;;)
	{
		CFileData *pFile = NULL;
		Sint32 ActivePage = -1;
		
		/*�I���`�F�b�N*/
		if( m_Event.IsSignal() )
		{
			break;
		}
		
		/*����擾���郊�X�g���擾*/
		m_CS.Enter();
		
		/*���ꂩ�珈������y�[�W*/
		ActivePage = m_Page;
		
		/*�y�[�W�؂�ւ�*/
		m_Page = 1 - m_Page;
		
		/*�擪���擾*/
		pFile = m_pQueTop[ActivePage];
		
		m_CS.Leave();
		
		if( pFile == NULL )
		{
			::Sleep( 250 );
			
			continue;
		}
		
		while( pFile != NULL )
		{
			/*���\�[�X�^�C�v�𔻕�*/
			CheckType( pFile );
			
			/*�����擾*/
			CFileData *pNext = pFile->GetNext();
			
			/*���݂̂��̂��폜*/
			delete pFile;
			
			pFile = pNext;
			
		}
		
		/*���X�g������*/
		m_pQueTop[ActivePage] = NULL;
		
	}
	
	//----------------------------------------------------------------------------
	//�L���[�̒��g���N���A
	//----------------------------------------------------------------------------
	for( Sint32 i = 0;i < QUE_MAX;++i )
	{
		CFileData *pFile = m_pQueTop[i];
		
		while( pFile != NULL )
		{
			CFileData *pNext = pFile->GetNext();
			delete pFile ;
			pFile = pNext;
		}
		
		m_pQueTop[i] = NULL;
	}

	
}

//============================================================================
//�^�C�v�̔���
//============================================================================
//[input]
//	pFile:���肷��f�[�^
//===========================================================================
void CResourceManager::CheckType( CFileData *pFile )
{
	
	
	TCHAR *pName =  (TCHAR *)( pFile->GetFileName().c_str() );
	
	Dix::PathStrAnalizer PSA( pName );
	
	//�g���q���擾
	string strExtName = PSA.getExtName();
	
	//���֌W�̏ꍇ
	if( strExtName == "wav" || strExtName == "ogg" )
	{
		//���̎擾
		CSoundObject *pSoundObj = CSoundFactory::GetSound( pFile );
		
		sp<CSoundObject> spSndObj( pSoundObj );
		
		//�T�E���h���X�g�ɒǉ�
		CCommonObject::GetSoundMgr()->AppendSoundList( pFile->GetDataName().c_str(), spSndObj );
		
	}
	
	//���̑��I�u�W�F�N�g�̏ꍇ
	else
	{
		//2D�I�u�W�F�N�g�̎擾
		CGameObject *pObj = CFactory2D::Get2DObject( pFile );
		
		sp<CGameObject> spObj;
		
		spObj.SetPtr( pObj );
		
		//���\�[�X�̓o�^
		AppendList( pFile->GetDataName(), spObj );
		
	}
	
}

//============================================================================
//�S���\�[�X�̃����_�����O
//============================================================================
void CResourceManager::RenderingAll()
{
	//���b�N���|����
	Thread::CAutoLock Lock( m_CS );
	
	map< string, sp<CGameObject> >::iterator it = m_mapDraw.begin();
	
	while( it != m_mapDraw.end() )
	{
		sp<CGameObject> spGameObj( it->second );
		
		//�\���t���O�������Ă����烌���_�����O
		if( spGameObj->GetVisibleFlag() )
		{	
			spGameObj->Rendering();
		}
		
		it++;
		
	}
}

//============================================================================
//�S���\�[�X�̏���
//============================================================================
void CResourceManager::ExecAll()
{
	//���b�N���|����
	Thread::CAutoLock Lock( m_CS );
	
	//map< string, CGameObject *>::iterator it = m_mapDraw.begin();
	//
	//for( it = m_mapDraw.begin(); it != m_mapDraw.end();it++ )
	//{
	//	CDrawObject *pDrawObj = dynamic_cast<CDrawObject *>( it->second );
	//	
	//	pDrawObj->Exec();
	//}
}

//============================================================================
//�X�V
//============================================================================
void CResourceManager::Update()
{
	//���b�N���|����
	Thread::CAutoLock Lock( m_CS );
	
	m_itDraw = m_mapDraw.begin();
	
	
	while( m_itDraw != m_mapDraw.end() )
	{
		
		
		sp<CGameObject> spGameObj( m_itDraw->second );
		
		spGameObj->Exec();
		
		if( spGameObj->GetRemoveFlag() )
		{
			m_mapDraw.erase( m_itDraw++ );
			
		}
		
		else
		{
			++m_itDraw;
		}
		
	}
	

}


//============================================================================
//�S���\�[�X�̓����蔻��
//============================================================================
void CResourceManager::HitCheckAll()
{
	//while( m_itDraw != m_mapDraw.end() )
	//{
	//	
	//	//sp<CGameObject> spGameObj( m_itDraw->second );

	//	//spDrawObj->HitCheck( spDrawObj2 );

	//	m_itDraw++;
	//	
	//}
	
}


//============================================================================
//���[�h�p�X���b�h
//============================================================================
//[input]
//	pData:���s�f�[�^
//===========================================================================
void CResourceManager::LoadProc( void *pData )
{
	//�g�p����CPU�ԍ�
	System::SetThreadCPUNo( 1 );
	
	//�N��
	( (CResourceManager*)pData)->Run();

}



					
									


