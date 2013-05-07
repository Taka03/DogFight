//*============================================================================
//GameFont.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "GameFont.h"
#include "joypad.h"
#include "ResourceManager.h"
#include "Bullet.h"
#include "FileLoader.h"



//=============================================================================
//variable
//=============================================================================


//============================================================================
//コンストラクタ
//============================================================================
//[input]
//	pName:ファイル名
//	pDataName:データファイル名
//===========================================================================
CGameFont::CGameFont( const char *pName, const char *pDataName )
:CSprite( pName, pDataName ),
 m_ExistCount( 0 )

{

	//パラメーターの読み込み
	LoadParameter( pDataName );

	Init();


}

//============================================================================
//デストラクタ
//============================================================================
CGameFont::~CGameFont(void)
{
}

//============================================================================
//処理
//============================================================================
void CGameFont::DrawRequest()
{
	m_pSpr->Begin();
	
	Math::Vector2D vPos[] =
	{
		 Math::Vector2D( 272, 16 ),
		 Math::Vector2D( 576, 0 ),
		 Math::Vector2D( 272, 0 ),
	};


	for( int i = 0;i < m_DivNum.y;++i )
	{
		m_DstRect.Set( vPos[i].x, vPos[i].y, m_fSize.x, m_fSize.y );
		m_SrcRect.Set( 0, toF(i) * m_fSize.y, m_fSize.x, m_fSize.y );

		m_pSpr->DrawSquare( m_DstRect, m_SrcRect, m_Color );

	}

	m_pSpr->End();
}

//============================================================================
//当たり判定
//============================================================================
//[input]
//	spObj:判定するオブジェクト
//[return]
//	当たっているか
//===========================================================================
bool CGameFont::HitCheck( sp<CGameObject> spObj )
{
	return false;
}
