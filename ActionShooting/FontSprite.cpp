//*============================================================================
//FontSprite.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "FontSprite.h"
#include "CommonObject.h"
#include "Common/Application.h"
#include "FileLoader.h"


//============================================================================
//�R���X�g���N�^
//============================================================================
//[input]
//	pName:�f�[�^��
//	pDataName:�f�[�^��
//===========================================================================
CFontSprite::CFontSprite( const char *pName, const char *pDataName ) 
:m_pFontSpr(NULL),
 m_IsFlash( false ),
 m_FlashCount( 0 ),
 m_Counter( 0 ),
  CGameObject( pName, pDataName )
{
	m_vecText.clear();
	
	m_FontColor = CColor( 255, 255, 255 );
	
	m_HitRect.Set( 0.0f, 0.0f, 0.0f, 0.0f );
	
	m_RefCount = 0;
	
	m_StrCount = 1;
	
	m_IsTextEnd = false;
	
	Load();
	
	LoadParameter( pDataName );
	
	Init();
	
	m_fScale.x = 2.0f;
	m_fScale.y = 2.0f;

}

//============================================================================
//�f�X�g���N�^
//============================================================================
CFontSprite::~CFontSprite(void)
{
	SAFE_RELEASE( m_pFontSpr );
}

//============================================================================
//������
//============================================================================
void CFontSprite::Init()
{
	m_vPos = m_vInitPos;
}

//============================================================================
//�t�@�C���ǂݍ���
//============================================================================
bool CFontSprite::Load(  )
{
	Renderer::IRender *pRender = CCommonObject::GetAppli()->GetRenderer();
	File::IFileManager *pFileMgr = CCommonObject::GetAppli()->GetFileMgr();
	
	pFileMgr->SetCurrentPath("Font");
	
	printf("LOAD FONT[%s]", m_strFileName.c_str() );
	
	m_pFontSpr = pRender->CreateFontSprite2DFromFile( m_strFileName.c_str(), "tga", 1024 );
	
	if( m_pFontSpr->IsInvalid() )
	{
		return false;
	}
	
	printf( "                 : -> %s\n", m_pFontSpr->IsInvalid() ? "Failed" : "Succeeded" );
	
	return true;
}

//============================================================================
//�p�����[�^�[�̓ǂݍ���
//============================================================================
//[input]
//	pFileName:�t�@�C����
//===========================================================================
void CFontSprite::LoadParameter( const char *pFileName )
{
	CFileLoader FileLoad( pFileName );
	
	//������̕����ǂݍ���
	vector< string > vecStr = CFileLoader::SplitString( FileLoad.GetStrList().at( 0 ), "," );
	
	//----------------------------------------------------------------------------
	//�ʒu�̐ݒ�
	//----------------------------------------------------------------------------
	SetParameter( m_vInitPos.x, vecStr.at( 0 ) );
	
	SetParameter( m_vInitPos.y, vecStr.at( 1 ) );
	
	//----------------------------------------------------------------------------
	//�����̐ݒ�
	//----------------------------------------------------------------------------
	SetParameter( m_Str, vecStr.at( 2 ) );
	
	//----------------------------------------------------------------------------
	//�_�ł����邩
	//----------------------------------------------------------------------------
	SetParameter( m_IsFlash, vecStr.at( 3 ) );
	
	//----------------------------------------------------------------------------
	//�_�ŕp�x
	//----------------------------------------------------------------------------
	SetParameter( m_FlashCount, vecStr.at( 4 ) );
	
	
}


//============================================================================
//����
//============================================================================
void CFontSprite::Exec()
{
	if( m_pFontSpr != NULL )
	{
		/*�`��J�n*/
		m_pFontSpr->Begin(3);
		
		/*�`��L���[�ɒǉ�*/
		//m_pFontSpr->DrawStringScale( m_Str.c_str(), Math::Point2DF( m_vPos.x, m_vPos.y), m_fScale, m_FontColor );
		m_pFontSpr->DrawString( m_Str.c_str(), Math::Point2DF( m_vPos.x, m_vPos.y ), m_FontColor );
		
		/*�`��I��*/
		m_pFontSpr->End();
		
		
		
		
	}	
}

//============================================================================
//�����_�����O
//============================================================================
void CFontSprite::Rendering()
{
	if( m_IsFlash )
	{
		if( ++m_Counter < m_FlashCount )
		{
			m_pFontSpr->Rendering();
		}
		
		else if( m_Counter > m_FlashCount * 2 )
		{
			m_Counter = 0;
		}
	}
	
	
	else
	{
		m_pFontSpr->Rendering();
	}
	
}


//============================================================================
//�\�����镶���̐ݒ�
//============================================================================
//[input]
//	str:�ݒ肷�镶����
//===========================================================================
void CFontSprite::SetDrawString(std::string str)
{
	m_Str = str;
}

