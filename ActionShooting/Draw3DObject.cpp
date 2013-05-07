//*===========================================================================
//Draw3DObject.cpp
//*===========================================================================

//============================================================================
//include
//============================================================================
#include "Draw3DObject.h"
#include "FileLoader.h"

//============================================================================
//�R���X�g���N�^
//============================================================================
//[input]
//	pName:�t�@�C����
//	pDataName:�f�[�^��
//===========================================================================
CDraw3DObject::CDraw3DObject( const char *pName, const char *pDataName ) 
: CDrawObject( pName ),
  m_vPos( 0, 0, 0 ),
  m_vInitPos( m_vPos ),
  m_Rot( 0, 0, 0 ),
  m_InitRot( m_Rot ),
  m_fScale( 1.0f, 1.0f, 1.0f ),
  m_fInitScale( m_fScale ),
  m_ActorIndex( SCREEN_MAIN )
{
	
	LoadParameter( pDataName );
}

//=============================================================================
//�f�X�g���N�^
//=============================================================================
CDraw3DObject::~CDraw3DObject(void)
{
}

//=============================================================================
//������
//=============================================================================
void CDraw3DObject::Init()
{
	m_vPos = m_vInitPos;
	m_Rot = m_InitRot;
	m_fScale = m_fInitScale;
}


//=============================================================================
//����
//=============================================================================
void CDraw3DObject::Exec()
{
}

//=============================================================================
//�ړ�����
//=============================================================================
void CDraw3DObject::MoveExec()
{
}



//=============================================================================
//�����_�����O
//=============================================================================
void CDraw3DObject::Rendering( )
{
	
}

//=============================================================================
//�p�����[�^�[�̓ǂݍ���
//=============================================================================
//[input]
//	pDataName:�f�[�^�t�@�C����
//[return]
//	�t�@�C���ǂݍ��݂ɐ���������
//=============================================================================
void CDraw3DObject::LoadParameter( const char *pDataName )
{
	//TOFIX:�ł���΃t�@�C���ЂƂЂƂ���Ȃ��āA���̃t�@�C���ЂƂł��ׂēǂݍ��߂�悤��
	//HOWTO:�C���f�b�N�X����āASplitString��at�����Ő؂蕪����Ƃ�
	CFileLoader FileLoad( pDataName );
	
	//������̕����ǂݍ���
	vector< string > vecStr = CFileLoader::SplitString( FileLoad.GetStrList().at( 0 ), "," );
	
	//�t�@�C�����̎擾
	SetParameter( m_strFileName, vecStr.at( 0 ) );
	
	//----------------------------------------------------------------------------
	//�ʒu�̐ݒ�
	//----------------------------------------------------------------------------
	SetParameter( m_vInitPos.x, vecStr.at( 1 ) );
	
	SetParameter( m_vInitPos.y, vecStr.at( 2 ) );
	
	SetParameter( m_vInitPos.z, vecStr.at( 3 ) );
	
	//----------------------------------------------------------------------------
	//�p�x�̐ݒ�
	//----------------------------------------------------------------------------
	SetParameter( m_InitRot.x, vecStr.at( 4 ) );
	
	SetParameter( m_InitRot.y, vecStr.at( 5 ) );
	
	SetParameter( m_InitRot.z, vecStr.at( 6 ) );
	
	//----------------------------------------------------------------------------
	//�g�k�̐ݒ�
	//----------------------------------------------------------------------------
	SetParameter( m_fInitScale.x, vecStr.at( 7 ) );
	
	SetParameter( m_fInitScale.y, vecStr.at( 8 ) );
	
	SetParameter( m_fInitScale.z, vecStr.at( 9 ) );
}


//=============================================================================
//�A�N�^�[�̐���
//=============================================================================
//[input]
//	pSceneMgr:�V�[���Ǘ��p�f�o�C�X
//=============================================================================
void CDraw3DObject::CreateActor( int index, Scene::ISceneManager *pSceneMgr )
{
}


//=============================================================================
//�����蔻��̃`�F�b�N
//=============================================================================
//[input/output]
//	ppChara:���肷��L����
//[return]
//	�����������ǂ���
//=============================================================================
bool CDraw3DObject::HitCheck( CDraw3DObject **ppChara )
{
	//list<ListData>::iterator i;
	//
	//for( i = m_ObjectList.begin();i != m_ObjectList.end();++i )
	//{
	//	CDraw3DObject *obj = dynamic_cast<CDraw3DObject *>( i->gameobj );
	//	
	//	if( obj->GetObjectType() == OBJ_ENEMY && this->HitCheck( &obj ) )
	//	{
	//		*ppChara = obj;
	//		return true;
	//	}
	//		
	//}
	
	return false;
}

//=============================================================================
//�����蔻��̃`�F�b�N
//=============================================================================
//[input]
//	vRay:����p�̃��C
//[return]
//	�����������ǂ���
//=============================================================================
bool CDraw3DObject::HitCheck( Collision::CLine3D &vRay )
{
	//list<ListData>::iterator i;
	//
	//for( i = m_ObjectList.begin();i != m_ObjectList.end();++i )
	//{
	//	CDraw3DObject *pChara = dynamic_cast<CDraw3DObject *>( i->gameobj );
	//	
	//	if( pChara->HitCheck( vRay ) )
	//	{
	//		return true;
	//	}
	//}
	
	return false;
}

//=============================================================================
//�����蔻��̃`�F�b�N
//=============================================================================
//[input]
//	vRay:����p�̃��C
//	ppHitObj:���������I�u�W�F�N�g�̎擾
//[output]
//	obj:�Փ˂����I�u�W�F�N�g	
//[return]
//	�����������ǂ���
//=============================================================================
bool CDraw3DObject::HitCheck( Selene::Collision::CLine3D &vRay, CDraw3DObject **ppHitObj )
{
	//list<ListData>::iterator i;
	//
	//for( i = m_ObjectList.begin();i != m_ObjectList.end();++i )
	//{
	//	CDraw3DObject *pChara = dynamic_cast<CDraw3DObject *>( i->gameobj );
	//	
	//	if( pChara->HitCheck( vRay ) )
	//	{
	//		*ppHitObj = pChara;
	//		return true;
	//	}
	//}
	
	return false;
}


//=============================================================================
//�����蔻��̃`�F�b�N
//=============================================================================
//[input]
//	vRay:����p�̃��C
//	Out:�Փ˔���̌���
//[return]
//	�����������ǂ���
//=============================================================================
bool CDraw3DObject::HitCheck( Collision::CLine3D &vRay, Renderer::SCollisionResult &Out )
{
	//list<ListData>::iterator i;
	//
	//for( i = m_ObjectList.begin();i != m_ObjectList.end();++i )
	//{
	//	CDraw3DObject *pChara = dynamic_cast<CDraw3DObject *>( i->gameobj );
	//	
	//	if( pChara->HitCheck( vRay, Out ) )
	//	{
	//		return true;
	//	}
	//}
	
	return false;
}

//=============================================================================
//�����蔻��̃`�F�b�N
//=============================================================================
//[input]
//	vRay:����p�̃��C
//	Out:�Փ˔���̌���
//[output]
//	ppHitObj:���������I�u�W�F�N�g
//[return]
//	�����������ǂ���
//=============================================================================
bool CDraw3DObject::HitCheck( Collision::CLine3D &vRay, Renderer::SCollisionResult &Out, CDraw3DObject **ppHitObj )
{
	//list<ListData>::iterator i;
	//
	//for( i = m_ObjectList.begin();i != m_ObjectList.end();++i )
	//{
	//	CDraw3DObject *pChara = dynamic_cast<CDraw3DObject *>( i->gameobj );
	//	
	//	if( pChara->HitCheck( vRay, Out ) )
	//	{
	//		*ppHitObj = pChara;
	//		
	//		return true;
	//	}
	//}
	
	return false;
}

//=============================================================================
//�A�N�^�[�C���f�b�N�X�̃Z�b�g
//=============================================================================
//[input]
//	index:�ݒ肷��C���f�b�N�X
//=============================================================================
void CDraw3DObject::SetActorIndex( int index )
{
	m_ActorIndex = index;
	//list<ListData>::iterator i;
	//
	//for( i = m_ObjectList.begin();i != m_ObjectList.end();++i )
	//{
	//	CDraw3DObject *pChara = dynamic_cast<CDraw3DObject *>( i->gameobj );
	//	
	//	pChara->SetActorIndex( index );		
	//}
}
