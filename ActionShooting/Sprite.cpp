//*============================================================================
//Sprite.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "Sprite.h"
#include "CommonObject.h"
#include "Common/Application.h"
#include "FileLoader.h"
#include "ResourceManager.h"
#include <map>

//============================================================================
//�R���X�g���N�^
//============================================================================
//[input]
//	pName:�t�@�C����
//	pDataName:�f�[�^�t�@�C����
//===========================================================================
CSprite::CSprite( const char *pName, const char *pDataName )  
:m_pTex(NULL),
 m_pSpr(NULL),
 m_vCenterPos( 8, 8 ),
 m_DivNum( 1, 1 ),
 m_AnimTime( 5 ),
 m_AnimCount( 0 ),
 m_Anim( 0, 0 ),
 m_AnimNum( 0 ),
 m_fSize( 0, 0 ),
 m_HitRect( 0, 0, 0, 0 ),
 m_DstRect( 0, 0, 0, 0 ),
 m_SrcRect( 0, 0, 0, 0 ),
 m_IsAnim( false ),
 m_IsAuto( true ),
 m_IsReverse( true ),
 m_AnimSpeed( 1 ),
 m_Color( 255, 255, 255 ),
 m_AdjHitRect( 0, 0, 0, 0 ),
 CGameObject( pName, pDataName )
{
	_ASSERT( m_DivNum.x > 0 );
	_ASSERT( m_DivNum.y > 0 );
	
	//�p�����[�^�[�̓ǂݍ���
	this->LoadParameter( pDataName );
	
	//�ǂݍ���
	Load();
	
	//������
	Init();
	
}

//============================================================================
//�R���X�g���N�^
//============================================================================
//[input]
//	LineNo:�s��
//===========================================================================
CSprite::CSprite( vector<string> vecStr )
:m_pTex(NULL),
 m_pSpr(NULL),
 m_vCenterPos( 8, 8 ),
 m_DivNum( 1, 1 ),
 m_AnimTime( 5 ),
 m_AnimCount( 0 ),
 m_Anim( 0, 0 ),
 m_AnimNum( 0 ),
 m_fSize( 0, 0 ),
 m_HitRect( 0, 0, 0, 0 ),
 m_DstRect( 0, 0, 0, 0 ),
 m_SrcRect( 0, 0, 0, 0 ),
 m_IsAnim( false ),
 m_IsAuto( true ),
 m_IsReverse( true ),
 m_AnimSpeed( 1 ),
 m_fBlendRate( 0 ),
 m_Color( 255, 255, 255 ),
 m_AdjHitRect( 0, 0, 0, 0 ),
 CGameObject( vecStr )
{
	_ASSERT( m_DivNum.x > 0 );
	_ASSERT( m_DivNum.y > 0 );

	if( m_DivNum.x < 0 )
	{
		m_DivNum.x = 1;
	}

	if( m_DivNum.y < 0 )
	{
		m_DivNum.y = 1;
	}

	//�p�����[�^�[�̓ǂݍ���
	this->LoadParameter( vecStr );

	//�ǂݍ���
	Load();

	//������
	Init();

}

//============================================================================
//�f�X�g���N�^
//============================================================================
CSprite::~CSprite(void)
{
	SAFE_RELEASE( m_pSpr );
	SAFE_RELEASE( m_pTex );
}

//============================================================================
//������
//============================================================================
void CSprite::Init()
{
	m_vPos = m_vInitPos;
	
	m_Angle = m_InitAngle;
	
	m_fScale = m_fInitScale;
	
}

//============================================================================
//�t�@�C���ǂݍ���
//============================================================================
//[return]
//	�t�@�C���ǂݍ��݂ɐ���������
//===========================================================================
bool CSprite::Load( )
{
	Renderer::IRender *pRender = CCommonObject::GetAppli()->GetRenderer();
	File::IFileManager *pFileMgr = CCommonObject::GetAppli()->GetFileMgr();
	
	pFileMgr->SetCurrentPath("Texture");
	
	const char *pFileName = m_strFileName.c_str();
	
	printf("LOAD TEXTURE[%s]", pFileName );
	
	//�e�N�X�`���t�@�C���̐���(����t�@�C�����������畡��)
	m_pTex = pRender->CreateTextureFromFile( pFileName );

	_ASSERT( m_pTex );
	
	//�ǂݍ��݂Ɏ��s?
	if( m_pTex->IsInvalid() )
	{
		return false;
	}
	
	printf( "                 : -> %s\n", m_pTex->IsInvalid() ? "Failed" : "Succeeded" );
	
	/*�T�C�Y�̐ݒ�*/
	m_fSize.x = toF( m_pTex->GetOriginalSize().x / m_DivNum.x );
	m_fSize.y = toF( m_pTex->GetOriginalSize().y / m_DivNum.y );
	
	m_SrcRect.Set( 0, 0, m_fSize.x, m_fSize.y ),
	
	/*�X�v���C�g�̐���*/
	CreateSprite( pRender, 500 );
	
	return true;
	
}

//============================================================================
//�p�����[�^�[�̓ǂݍ���
//============================================================================
//[input]
//	pFileName:�t�@�C����
//===========================================================================
void CSprite::LoadParameter( const char *pFileName )
{
	CFileLoader FileLoad( pFileName );
	
	vector< string > vecStr = CFileLoader::SplitString( FileLoad.GetStrList().at( 0 ), "," );
	
	//----------------------------------------------
	//�ʒu�̐ݒ�
	//----------------------------------------------
	SetParameter( m_vInitPos.x, vecStr.at( 0 ) );
	
	SetParameter( m_vInitPos.y, vecStr.at( 1 ) );
	
	//----------------------------------------------
	//�p�x�̐ݒ�
	//----------------------------------------------
	SetParameter( m_InitAngle, vecStr.at( 2 ) );
	
	//----------------------------------------------
	//�s�����x�̐ݒ�
	//----------------------------------------------
	SetParameter( m_Alpha, vecStr.at( 3 ) );


	//----------------------------------------------
	//�g�k���̐ݒ�
	//----------------------------------------------
	SetParameter( m_fInitScale.x, vecStr.at( 4 ) );
	
	SetParameter( m_fInitScale.y, vecStr.at( 5 ) );
	
	//----------------------------------------------
	//�������̐ݒ�
	//----------------------------------------------
	SetParameter( m_DivNum.x, vecStr.at( 6 ) );
	
	SetParameter( m_DivNum.y, vecStr.at( 7 ) );
	
	//----------------------------------------------
	//�A�j���[�V�����̐ݒ�
	//----------------------------------------------
	SetParameter( m_IsAnim, vecStr.at( 8 ) );
	
	SetParameter( m_AnimTime, vecStr.at( 9 ) );
	
}

//============================================================================
//�p�����[�^�[�̓ǂݍ���
//============================================================================
//[input]
//	vecStr:
//===========================================================================
void CSprite::LoadParameter( vector<string> vecStr )
{
	//----------------------------------------------
	//�t�@�C�����̐ݒ�
	//----------------------------------------------
	SetParameter( m_strFileName, vecStr.at( 0 ) );

	//----------------------------------------------
	//�f�[�^�t�@�C�����̐ݒ�
	//----------------------------------------------
	SetParameter( m_strDataName, vecStr.at( 1 ) );

	//----------------------------------------------
	//�ʒu�̐ݒ�
	//----------------------------------------------
	SetParameter( m_vInitPos.x, vecStr.at( 2 ) );

	SetParameter( m_vInitPos.y, vecStr.at( 3 ) );

	//----------------------------------------------
	//�p�x�̐ݒ�
	//----------------------------------------------
	SetParameter( m_InitAngle, vecStr.at( 4 ) );

	//----------------------------------------------
	//�s�����x�̐ݒ�
	//----------------------------------------------
	SetParameter( m_Alpha, vecStr.at( 5 ) );

	//----------------------------------------------
	//�g�k���̐ݒ�
	//----------------------------------------------
	SetParameter( m_fInitScale.x, vecStr.at( 6 ) );

	SetParameter( m_fInitScale.y, vecStr.at( 7 ) );

	//----------------------------------------------
	//�������̐ݒ�
	//----------------------------------------------
	SetParameter( m_DivNum.x, vecStr.at( 8 ) );

	SetParameter( m_DivNum.y, vecStr.at( 9 ) );

	//----------------------------------------------
	//�A�j���[�V�����̐ݒ�
	//----------------------------------------------
	//SetParameter( m_IsAnim, vecStr.at( 8 ) );

	//SetParameter( m_AnimTime, vecStr.at( 9 ) );

}

//============================================================================
//�X�v���C�g�̐���
//============================================================================
//[input]
//	pRender:�����_���[�p�f�o�C�X
//	Num:�X�v���C�g��
//===========================================================================
void CSprite::CreateSprite( Renderer::IRender *pRender, Uint32 Num )
{
	m_pSpr = pRender->CreateSprite2D( Num, m_pTex ); 
	
	_ASSERT( m_pSpr );
		
}

//============================================================================
//����
//============================================================================
void CSprite::Exec()
{
	/*�A�j���[�V�����̐ݒ�*/
	SetAnimation();
	
	/*�`���*/
	m_DstRect.Set( m_vPos.x, m_vPos.y, m_fSize.x * m_fScale.x, m_fSize.y * m_fScale.y );
	
	/*�`�挳*/
	m_SrcRect.Set( m_Anim.x * m_fSize.x, m_Anim.y * m_fSize.y, m_fSize.x, m_fSize.y );
	
	//�`�惊�N�G�X�g
	DrawRequest();
	
	map< string, sp<CGameObject> > mapDraw;
	
	mapDraw.clear();
	
	mapDraw = CCommonObject::GetResMgr()->GetDrawMap();

	map< string, sp<CGameObject> >::iterator it = mapDraw.begin();




#if defined( DEBUG ) | ( _DEBUG )

	Peripheral::IKeyboard *pKey = CCommonObject::GetAppli()->GetCore()->GetKeyboard();


	static bool IsHit = true;

	if( pKey->GetKeyData( SELENE_VK_Q ) )
	{
		IsHit = !IsHit;
	}



#endif

#if defined( DEBUG ) | ( _DEBUG )

	if( IsHit )
#endif
	{

		while( it != mapDraw.end() )
		{
			sp<CGameObject> spObj( it->second );
			
			bool IsThis = ( this->GetPos().x > 0 && this->GetPos().x < SCREEN_WIDTH - this->GetSize().x && this->GetPos().y > 0 
							&& this->GetPos().y < SCREEN_HEIGHT - this->GetSize().y );
			
				if( this->HitCheck( spObj ) )
				{
					this->HitExec( spObj );
				}
			

			it++;
		}
	}



	
}



//============================================================================
//�`�惊�N�G�X�g
//============================================================================
void CSprite::DrawRequest()
{
	/*�����蔻��̈�̃Z�b�g*/
	m_HitRect.Set( m_vPos.x + m_AdjHitRect.x, m_vPos.y + m_AdjHitRect.y, 
				   m_fSize.x * m_fScale.x - m_AdjHitRect.w, 
				   m_fSize.y * m_fScale.y - m_AdjHitRect.h );
	
	/*�`��J�n*/
	m_pSpr->Begin();
	
	m_Color.a = m_Alpha;	
	

	
	
	/*��]�t���`��*/
	m_pSpr->DrawSquareRotateC( m_DstRect, m_SrcRect, 
	Math::Vector3D( m_vPos.x + m_vCenterPos.x, m_vPos.y + m_vCenterPos.y, 0 ), m_Color, m_Angle );
	
	/*�`��I��*/
	m_pSpr->End();
}

//============================================================================
//�����_�����O
//============================================================================
void CSprite::Rendering( )
{
	m_pSpr->Rendering();
}

//============================================================================
//�O���[�X�P�[���`��
//============================================================================
//[input]
//	pRender:�����_���[�p�f�o�C�X
//===========================================================================
void CSprite::DrawGrayScale( Renderer::IRender *pRender )
{
	if( m_pTex != NULL )
	{
		Math::Rect2DF Dst( m_vPos.x, m_vPos.y, m_fSize.x, m_fSize.y );
		
		Math::Rect2DF Src( 0, 0, m_fSize.x, m_fSize.y );
		
		pRender->DrawGrayscale( Dst, CColor( 255, 254, 255 ), Src, m_pTex );
		
		
	}
}

//============================================================================
//�A�j���[�V�����̐ݒ�
//============================================================================
void CSprite::SetAnimation()
{
	if( m_IsAnim )
	{
		/*�A�j���[�V�����J�E���^�̑���*/
		if( ++m_AnimCount > m_AnimTime )
		{
			m_AnimCount = 0;
			m_Anim.x += m_AnimSpeed;
		}
		 
		if( m_Anim.x >= m_DivNum.x )
		{
			m_Anim.x = 0;
		}
		
	}
	
}

//============================================================================
//�����蔻��
//============================================================================
//[input]
//	spObj:����I�u�W�F�N�g
//[return]
// �������Ă��邩�ǂ���
//============================================================================
bool CSprite::HitCheck( sp<CGameObject> spObj )
{
	if( spObj != NULL && this != NULL )
	{
		if( spObj->GetVisibleFlag() && this->GetVisibleFlag() )
		{
			if( Collision::Rect_Rect( this->GetHitRect(), spObj->GetHitRect() )  )
			{
				return true;
			}
			
			

			else
			{
				return false;
			}
		}
	}
	
	return false;
}
