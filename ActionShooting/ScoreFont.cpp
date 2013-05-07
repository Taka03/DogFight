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
//コンストラクタ
//=============================================================================
//[input]
//	pName:データ名
//	pDataName:データ名
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
//デストラクタ
//============================================================================
CScoreFont::~CScoreFont(void)
{

}

//============================================================================
//初期化
//============================================================================
void CScoreFont::Init()
{

}

//============================================================================
//処理
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

		const int MAX_SCORE_SIZE = 5;//スコアの最大桁数
	
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
//パラメーターの読み込み
//============================================================================
//[input]
//	pFileName:ファイル名
//===========================================================================
void CScoreFont::LoadParameter( const char *pFileName )
{
	CFileLoader FileLoad( pFileName );

	//文字列の分割読み込み
	vector< string > vecStr = CFileLoader::SplitString( FileLoad.GetStrList().at( 0 ), "," );

	//----------------------------------------------------------------------------
	//位置の設定
	//----------------------------------------------------------------------------
	SetParameter( m_vInitPos.x, vecStr.at( 0 ) );

	SetParameter( m_vInitPos.y, vecStr.at( 1 ) );

	//----------------------------------------------------------------------------
	//文字の設定
	//----------------------------------------------------------------------------
	SetParameter( m_IsHighScore, vecStr.at( 2 ) );

}

//=============================================================================
//描画
//=============================================================================
void CScoreFont::Draw()
{
	//m_pFontSpr->DrawStringScale()

	//m_pFontSpr->draws

}




