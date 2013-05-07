//*============================================================================
//ReadyTex.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "ReadyTex.h"
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
CReadyTex::CReadyTex( const char *pName, const char *pDataName )
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
CReadyTex::~CReadyTex(void)
{
}

//============================================================================
//処理
//============================================================================
void CReadyTex::Exec()
{
	++m_ExistCount;

	if( m_ExistCount < 60 * 1 )
	{
		m_fScale.x -= 0.2f;
		m_fScale.y -= 0.2f;

		if( m_fScale.x <= 1.0f && m_fScale.y <= 1.0f )
		{
			m_fScale = m_fInitScale;
		}

		m_Anim.y = 0;
	}

	else if( m_ExistCount < 60 * 2 )
	{
		m_fScale.x -= 0.2f;
		m_fScale.y -= 0.2f;

		if( m_fScale.x <= 1.0f && m_fScale.y <= 1.0f )
		{
			m_fScale = m_fInitScale;
		}



		m_Anim.y = 1;
	}

	else if( m_ExistCount < 60 * 3 )
	{
		m_fScale.x -= 0.2f;
		m_fScale.y -= 0.2f;

		if( m_fScale.x <= 1.0f && m_fScale.y <= 1.0f )
		{
			m_fScale = m_fInitScale;
		}

		m_Anim.y = 2;
	}

	else if( m_ExistCount < 60 * 4 )
	{
		m_Anim.y = 3;
	}

	else if( m_ExistCount > 60 * 4 )
	{
		this->SetVisibleFlag( false );
	}


	CSprite::Exec();


}

//============================================================================
//当たり判定
//============================================================================
//[input]
//	spObj:判定するオブジェクト
//[return]
//	当たっているか
//===========================================================================
bool CReadyTex::HitCheck( sp<CGameObject> spObj )
{
	return false;
}
