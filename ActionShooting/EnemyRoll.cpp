//*============================================================================
//EnemyRoll.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "EnemyRoll.h"
#include "ResourceManager.h"
#include "Bullet.h"
#include "Common/Application.h"
#include "SceneGameMain.h"

const int SHOT_MAX = 3;

//============================================================================
//コンストラクタ
//============================================================================
//[input]
//	pName:ファイル名
//	pDataName:データファイル名
//	vPos:設定する位置
//===========================================================================
CEnemyRoll::CEnemyRoll( const char *pName, const char *pDataName, Math::Vector2D vPos )
:CEnemy( pName, pDataName, vPos ),
 m_Scroll( toI( vPos.x ) ),
 m_ScrollY( 0 )
{
	m_vInitPos = vPos;
	
}

//============================================================================
//デストラクタ
//============================================================================
CEnemyRoll::~CEnemyRoll(void)
{
}

//============================================================================
//移動
//============================================================================
void CEnemyRoll::Move()
{
	m_fSize.x = 64;
	m_fSize.y = 64;	
	
	Shoot();
	
	if( m_vPos.x < 0 )
	{
		this->SetRemoveFlag( true );
		//m_vPos.x = SCREEN_WIDTH;
		//
		//Math::CRandom Rand( CCommonObject::GetAppli()->GetCore()->GetSyncCount() );
		//
		//m_vPos.y = Rand.GetFloat( 0, SCREEN_HEIGHT );
		
	}
	
	m_RollAngle += DEG_TO_ANGLE( 2 );

	m_Scroll --;

	m_vPos.x = Math::Cos( m_RollAngle ) * 100 + m_Scroll;
	m_vPos.y = Math::Sin( m_RollAngle ) * 100 + m_vInitPos.y;

}

//============================================================================
//ショット処理
//============================================================================
void CEnemyRoll::Shoot()
{
	static int count = 0;
	
	string str("");
	
	if( !m_IsShoot && ++m_ShootCount > 30 )
	{
		m_ShootCount = 0;
	}
	
	//弾を撃ち出す
	if( m_ShootCount == 0 )
	{
		m_IsShoot = true;
	}	
	
	if( m_IsShoot )
	{
		if( ++m_StreamCount % 30 == 0 )
		{
			stringstream ss(" ");
			
			ss << "Enemy_Bullet" << count;
			
			str = ss.str();
			
			Math::Vector2D vPos( m_vPos.x + Math::Cos( m_Angle ) * 2,
								 m_vPos.y - Math::Sin( m_Angle ) * 2 );
			
			CCommonObject::GetResMgr()->Push( new CFileData("enemy_bullet_red.png", str.c_str(), 
															"AIMSHOOT", "enemybullet.csv", m_vPos ) );
			count++;
			
			m_ShotNum++;
		}
		
		if( m_ShotNum > SHOT_MAX )
		{
			m_ShotNum = 0;
			m_IsShoot = false;
		}
	
	}
}

//============================================================================
//移動補正
//============================================================================
void CEnemyRoll::MoveAdjust()
{
	
}






