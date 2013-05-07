//*============================================================================
//EnemyCannon.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "EnemyCannon.h"
#include "ResourceManager.h"
#include "Bullet.h"
#include "Common/Application.h"
#include "SceneGameMain.h"
#include "EnemyMiddle1.h"

//============================================================================
//コンストラクタ
//============================================================================
//[input]
//	pName:ファイル名
//	pDataName:データファイル名
//	vPos:設定する位置
//===========================================================================
CEnemyCannon::CEnemyCannon( const char *pName, const char *pDataName, Math::Vector2D vPos )
:CEnemy( pName, pDataName, vPos )
{
	
	m_fSize.x = 48;
	m_fSize.y = 48;
	
	m_vCenterPos = Math::Vector2D( 32, 16 );
	
}

//============================================================================
//コンストラクタ
//============================================================================
//[input]
//	pName:ファイル名
//	pDataName:データファイル名
//	vPos:設定する位置
//===========================================================================
CEnemyCannon::CEnemyCannon( const char *pName, const char *pDataName, CGameObject *pObj/*sp<CGameObject> spObj*/ )
:CEnemy( pName, pDataName, Math::Vector2D( 0, 0 ) ),
 m_pTargetObj( pObj )
{
	
	m_fSize.x = 48;
	m_fSize.y = 48;
	
	m_vCenterPos = Math::Vector2D( 32, 16 );
	
}


//============================================================================
//デストラクタ
//============================================================================
CEnemyCannon::~CEnemyCannon(void)
{
}

//============================================================================
//移動
//============================================================================
void CEnemyCannon::Move()
{
	CEnemy::Shoot();
	
	if( !m_pTargetObj->GetRemoveFlag() )
	{	
		if( m_pTargetObj != NULL )
		{	
			m_vPos = m_pTargetObj->GetPos() + Math::Vector2D( 48 - 16, 49 - 16 );
		}
	
		//プレイヤーオブジェクトを取得
		sp<CGameObject> spObj = CCommonObject::GetResMgr()->FindObject( "Player" );
		
		Math::Vector2D vTargetPos( 0, 0 );
		
		if( spObj != NULL )
		{
			vTargetPos = spObj->GetPos();
		}
		
		else
		{
			vTargetPos = Math::Vector2D( 0, 0 );
		}
		
		Sint32 Angle = Math::ATan2( GetPos().x - vTargetPos.x , GetPos().y - vTargetPos.y );
		
		//角度の設定
		m_Angle = Angle;
		
	}
	
	else
	{
		this->SetRemoveFlag( true );
	}
}

