//*============================================================================
//EffectFlash.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "EffectFlash.h"
#include "Common/Application.h"


//============================================================================
//コンストラクタ
//============================================================================
//[input]
//	pName:ファイル名
//	pDataName:データファイル名
//	vPos:位置
//===========================================================================
CEffectFlash::CEffectFlash( const char *pName, const char *pDataName, Math::Vector2D vPos )
:CEffect( pName, pDataName, vPos )
{
	m_ExistCount = 0;
	m_eType = TYPE_CHAINBOMB;
	m_eState = STATE_NONE;
}


//============================================================================
//デストラクタ
//============================================================================
CEffectFlash::~CEffectFlash(void)
{
	printf("EffectFlash:Remove\n");
}

//============================================================================
//処理
//============================================================================
void CEffectFlash::Exec()
{
	
	if( ++m_ExistCount > 5 )
	{
		m_eState = STATE_DIED;	
	}
	
	CEffect::Exec();
	
}



//============================================================================
//当たり判定処理
//============================================================================
//[input]
//	spObj:判定するオブジェクト
//============================================================================
void CEffectFlash::HitExec( sp<CGameObject> spObj )
{
	//弾と当たっていたら弾を消去
	if( spObj->GetType() == CGameObject::TYPE_EBULLET )
	{
		spObj->SetRemoveFlag( true );
	}
}



