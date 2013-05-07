//*============================================================================
//HitFont.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "HitFont.h"
#include "CommonObject.h"
#include "Common/Application.h"
#include "FileLoader.h"
#include "Selene.h"
#include "SceneGameMain.h"


//=============================================================================
//�R���X�g���N�^
//=============================================================================
//[input]
//	pName:�f�[�^��
//	pDataName:�f�[�^��
//===========================================================================
CHitFont::CHitFont( const char *pName, const char *pDataName )
:CFontSprite( pName, pDataName ),
 m_IsMaxHit( false )

{
	LoadParameter( pDataName );

	m_fScale.x = 1;
	m_fScale.y = 1;
}

//============================================================================
//�f�X�g���N�^
//============================================================================
CHitFont::~CHitFont(void)
{

}

//============================================================================
//������
//============================================================================
void CHitFont::Init()
{

}

//============================================================================
//����
//============================================================================
void CHitFont::Exec()
{
	#if 0
		if( m_pFontSpr != NULL )
		{
		
			m_pFontSpr->Begin();

			Draw();

			m_pFontSpr->End();

		}
		
	#else


		stringstream ss("");

		if( m_IsMaxHit )
		{
			ss << CSceneGameMain::GetMaxHitCount();

		}

		else
		{
			ss << CSceneGameMain::GetHitCount();

			if( CSceneGameMain::GetHitCount() == 0 )
			{
				this->SetVisibleFlag( false );
			}

			else
			{
				this->SetVisibleFlag( true );
			}

			this->SetPosition( Math::Vector2D( this->GetInitPos().x - ss.str().size() * 15,
												this->GetInitPos().y ) );


		}

		this->SetDrawString( ss.str() );




		CFontSprite::Exec();
		
	#endif


}

//============================================================================
//�p�����[�^�[�̓ǂݍ���
//============================================================================
//[input]
//	pFileName:�t�@�C����
//===========================================================================
void CHitFont::LoadParameter( const char *pFileName )
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
	SetParameter( m_IsMaxHit, vecStr.at( 2 ) );

}

//=============================================================================
//�`��
//=============================================================================
void CHitFont::Draw()
{
	//m_pFontSpr->DrawStringScale()

	//m_pFontSpr->draws

}




