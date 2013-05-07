//*============================================================================
//PauseFont.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "PauseFont.h"
#include "CommonObject.h"
#include "Common/Application.h"
#include "FileLoader.h"
#include "Selene.h"
#include "joypad.h"
#include "SceneGameMain.h"

//=============================================================================
//コンストラクタ
//=============================================================================
//[input]
//	pName:データ名
//	pDataName:データ名
//===========================================================================
CPauseFont::CPauseFont( const char *pName, const char *pDataName )
:
#ifdef USE_SPRITE
CSprite( pName, pDataName ),

#else
CFontSprite( pName, pDataName ),
#endif
 m_Cursor( 0 )

{
	m_fScale.x = 1;
	m_fScale.y = 1;
	
	this->SetVisibleFlag( false );
	
	
}

//============================================================================
//デストラクタ
//============================================================================
CPauseFont::~CPauseFont(void)
{

}

//============================================================================
//初期化
//============================================================================
void CPauseFont::Init()
{

}

//============================================================================
//レンダリング
//============================================================================
void CPauseFont::Rendering()
{
	if( CSceneGameMain::GetPauseFlag() )
	{
		Renderer::IRender *pRender = CCommonObject::GetAppli()->GetRenderer();

		pRender->SetDrawType( DRAW_TYPE_BLEND );

		pRender->FillRect( Math::Rect2DF( 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT ), CColor( 0, 0, 0, 128 ) );

		pRender->SetDrawType( DRAW_TYPE_NORMAL );


	}

#ifdef USE_SPRITE

	CSprite::Rendering();

	m_pSpr->Begin();

	m_DstRect.Set( m_vPos.x, m_vPos.y, m_fSize.x, m_fSize.y );

	m_SrcRect.Set( 0, 0, m_fSize.x, m_fSize.y );

	m_pSpr->DrawSquare( m_DstRect, m_SrcRect, m_Color );






	for( int i = 0;i < MENU_MAX;++i )
	{

		m_SrcRect.Set( 0, toF( i + 1 ) * m_fSize.y, m_fSize.x, m_fSize.y );

			
		Math::Matrix matWorld;
		Math::Matrix matTemp;


		matWorld.Identity();
		matTemp.Identity();

		Math::Vector2D vPos( 400, toF( i + 1 ) * ( m_fSize.y ) + 100 );

	

//		カーソルが選択されているとき
		if( m_Cursor == i )
		{
			static int count = 0;

			const float fMAX_SCALE = 0.1f;

			count += DEG_TO_ANGLE(10);

//			m_fScale.x = Abs( Math::Sin(count) + 1.0f ) * fMAX_SCALE;
//			m_fScale.y = Abs( Math::Sin(count) + 1.0f ) * fMAX_SCALE;

			m_fScale.x = (Math::Sin(count) ) * fMAX_SCALE + 1.5f;
			m_fScale.y = (Math::Sin(count) ) * fMAX_SCALE + 1.5f;

//			m_DstRect.Set( m_vPos.x, m_vPos.y + toF( i + 1 ) * ( m_fSize.y ),
//							m_fScale.x *m_fSize.x, m_fScale.y * m_fSize.y );
		

			matTemp.Scaling( m_fScale.x, m_fScale.y, 1.0f );

			matWorld.Multiply( matTemp );

			matTemp.Translation( m_vPos.x + vPos.x, m_vPos.y + vPos.y, 1.0f );

			matWorld.Multiply( matTemp );

			m_pSpr->DrawSquareMatrix( matWorld ,m_SrcRect, CColor( 255, 0, 0 ) );
			


		}

		else
		{


			m_DstRect.Set( m_vPos.x, m_vPos.y + toF( i + 1 ) * ( m_fSize.y ), m_fSize.x, m_fSize.y );

			m_pSpr->DrawSquare( m_DstRect, m_SrcRect, CColor( 255, 255, 255 ) );
			/*matTemp.Scaling( 1.0f, 1.0f, 1.0f );

			matWorld.Multiply( matTemp );

			matTemp.Translation( m_vPos.x + vPos.x, m_vPos.y + vPos.y, 1.0f );

			matWorld.Multiply( matTemp );
			
			
			m_pSpr->DrawSquareMatrix( matWorld ,m_SrcRect, CColor( 255, 0, 0 ) );*/			

		}
	}

	m_pSpr->End();

#else
	CFontSprite::Rendering();


	m_pFontSpr->Begin( 3 );
	

	const char *pStr[MENU_MAX] =
	{
		 "RETURNTOGAME",
		 "RETRY",
	};//メニュー名
	
	Math::Point2DF Pos( m_vPos.x, m_vPos.y );


	m_pFontSpr->DrawString( "PAUSE", Pos, CColor( 255, 255, 255) );

	for( int i = 0;i < MENU_MAX;++i )
	{
//		カーソルが選択されていたら、色を変更
		if( m_Cursor == i )
		{
			m_pFontSpr->DrawString( pStr[i], Pos + Math::Point2DF( 0, 10 * (i + 1 ) ), CColor( 255, 0, 0 ) );
		}

		else
		{
			m_pFontSpr->DrawString( pStr[i], Pos + Math::Point2DF( 0, 10 * (i + 1 ) ), CColor( 255, 255, 255 ) );
		}

	}
	


	m_pFontSpr->End();
#endif



}

//============================================================================
//処理
//============================================================================
void CPauseFont::Exec()
{

}

//=============================================================================
//描画
//=============================================================================
void CPauseFont::Draw()
{
	


}




