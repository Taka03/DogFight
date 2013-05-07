//*============================================================================
//Effect.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "Effect.h"

//============================================================================
//コンストラクタ
//============================================================================
//[input]
//	pName:ファイル名
//	pDataName:データファイル名
//===========================================================================
CEffect::CEffect( const char *pName, const char *pDataName, Math::Vector2D vPos )
:CCharacter( pName, pDataName ),
 m_eState( STATE_NONE )
{
	m_vPos = vPos;
	
	Init();
}

//============================================================================
//デストラクタ
//============================================================================
CEffect::~CEffect(void)
{
}

//============================================================================
//移動
//============================================================================
void CEffect::Move()
{
	
}

//============================================================================
//当たり判定処理
//============================================================================
//[input]
//	spObj:判定するオブジェクト
//============================================================================
void CEffect::HitExec( sp<CGameObject> spObj )
{
}

//============================================================================
//状態毎の処理
//============================================================================
void CEffect::StateExec()
{
	switch( m_eState )
	{
		//何もない状態
		case STATE_NONE:
		{
			
			break;
		}
		
		//死んだ状態
		case STATE_DIED:
		{
			this->SetRemoveFlag( true );
			break;
		}
		
	}
}

bool CEffect::HitCheck( sp<CGameObject> spObj )
{
	return false;
}





