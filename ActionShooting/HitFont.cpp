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
//コンストラクタ
//=============================================================================
//[input]
//	pName:データ名
//	pDataName:データ名
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
//デストラクタ
//============================================================================
CHitFont::~CHitFont(void)
{

}

//============================================================================
//初期化
//============================================================================
void CHitFont::Init()
{

}

//============================================================================
//処理
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
//パラメーターの読み込み
//============================================================================
//[input]
//	pFileName:ファイル名
//===========================================================================
void CHitFont::LoadParameter( const char *pFileName )
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
	SetParameter( m_IsMaxHit, vecStr.at( 2 ) );

}

//=============================================================================
//描画
//=============================================================================
void CHitFont::Draw()
{
	//m_pFontSpr->DrawStringScale()

	//m_pFontSpr->draws

}




