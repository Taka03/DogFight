//*============================================================================
//ScoreFont.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "ScoreFont.h"
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
CScoreFont::CScoreFont( const char *pName, const char *pDataName )
:CFontSprite( pName, pDataName ),
 m_IsHighScore( false )

{
	LoadParameter( pDataName );

	m_fScale.x = 1;
	m_fScale.y = 1;
}

//============================================================================
//�f�X�g���N�^
//============================================================================
CScoreFont::~CScoreFont(void)
{

}

//============================================================================
//������
//============================================================================
void CScoreFont::Init()
{

}

//============================================================================
//����
//============================================================================
void CScoreFont::Exec()
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

		const int MAX_SCORE_SIZE = 5;//�X�R�A�̍ő包��
	
		if( m_IsHighScore )
		{
			ss << CSceneGameMain::GetHighScore();

			if( ss.str().size() < MAX_SCORE_SIZE )
			{
				string str("");

				for( int i = ss.str().size();i < MAX_SCORE_SIZE;++i )
				{
					str += "0";
				}

				ss.str("");

				ss << str << CSceneGameMain::GetHighScore();
			}

		}

		else
		{
			ss << CSceneGameMain::GetGameScore();

			if( ss.str().size() < MAX_SCORE_SIZE )
			{
				string str("");

				for( int i = ss.str().size();i < MAX_SCORE_SIZE;++i )
				{
					str += "0";
				}

				ss.str("");

				ss << str << CSceneGameMain::GetGameScore();
			}
		}

		SetDrawString(ss.str());

		CFontSprite::Exec();
		
	#endif


}

//============================================================================
//�p�����[�^�[�̓ǂݍ���
//============================================================================
//[input]
//	pFileName:�t�@�C����
//===========================================================================
void CScoreFont::LoadParameter( const char *pFileName )
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
	SetParameter( m_IsHighScore, vecStr.at( 2 ) );

}

//=============================================================================
//�`��
//=============================================================================
void CScoreFont::Draw()
{
	//m_pFontSpr->DrawStringScale()

	//m_pFontSpr->draws

}




