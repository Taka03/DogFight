//*============================================================================
//EnemyPattern.cpp
//*============================================================================


//=============================================================================
//include
//=============================================================================
#include "EnemyPattern.h"
#include "ResourceManager.h"
#include "FileLoader.h"

//=============================================================================
//variable
//=============================================================================
Uint32 CEnemyPattern::m_SmallEnemyNum = 0;


//=============================================================================
//コンストラクタ
//=============================================================================
CEnemyPattern::CEnemyPattern( tagPattern Pat ) :
m_EnemyPat( Pat ),
m_Counter( 0 ),
m_EnemyCount( 0 ),
m_CurPat( 0 ),
m_Angle( DEG_TO_ANGLE( 270 ) ),
m_IsRemoved( false )
{
	Selene::Math::Matrix matTemp;





	matTemp.RotationAxis(0, Math::Vector3D(0, 0, 0) );
}

//=============================================================================
//デストラクタ
//=============================================================================
CEnemyPattern::~CEnemyPattern(void)
{
}



//=============================================================================
//敵の生成処理
//=============================================================================
void CEnemyPattern::Exec()
{
	//m_ePat = static_cast<eEnemyPat>( m_vecPattern.at( m_CurPat ).m_Pattern );
	
	switch( m_EnemyPat.m_Pattern )
	{
		case PAT_STEP:
		{
			MoveStep();
			
			break;
		}
		
		case PAT_ROLL:
		{
			MoveRoll();
			
			break;
		}
		
		case PAT_CURVE:
		{
			MoveCurve();
			
			break;
		}
		
		case PAT_STRAIGHT:
		{
			MoveStraight( );
			
			break;
		}
		
		case PAT_AIMING:
		{
			MoveAiming();
			
			break;
		}
		
		case PAT_MIDDLE:
		{
			MoveMiddleEnemy();
			
			break;
			
		}
	}
}

//=============================================================================
//階段状の移動
//=============================================================================
void CEnemyPattern::MoveStep()
{
	Math::Vector2D vCurPos( m_EnemyPat.m_vPos );
	Uint32 IntervalTime = m_EnemyPat.m_Interval;
	
	if( ++m_Counter % IntervalTime == 0 )
	{	
		m_Angle += DEG_TO_ANGLE( 10 );
		
		Math::Vector2D vPos( vCurPos.x, vCurPos.x / 2.0f + Math::Sin( m_Angle ) * (vCurPos.y / 2.0f) );
		
		stringstream ss("");
		
		//m_EnemyCount++;
		
		ss << "PlEnemySmall" << m_SmallEnemyNum;
		
		string str = ss.str();
		
		CCommonObject::GetResMgr()->Push( new CFileData("enemy_small_1.png", str.c_str(),
														  "ENEMY", "enemy.csv", vPos ) );
														  
		++m_SmallEnemyNum;
		
		++m_EnemyCount;
		
		if( m_EnemyCount > m_EnemyPat.m_EnemyNum - 1 )
		{
			this->SetRemoveFlag( true );
		}
	}
			
}

//=============================================================================
//TODO:回転の移動
//=============================================================================
void CEnemyPattern::MoveRoll()
{
	//Math::Vector2D vPos( m_vecPattern.at( m_CurPat ).m_vPos );
	
	static int count = 0;
	
	static int MiddleCount = 0;
	
	stringstream ss("");
	
	if( m_EnemyCount == 0 )
	{
		Math::Vector2D vPos( 1000 , 200 );

		
		ss << "PlEnemyMid" << CEnemyMiddle1::GetExistNum();
		
		MiddleCount = count;
		
		string str = ss.str();
		
		//CCommonObject::GetResMgr()->Push( new CFileData("enemy_middle_1.png", str.c_str(), 
		//													"ENE_MID_1", "enemymiddle1.csv", vPos ) );
		
		
	}
	
	if( ++m_EnemyCount > 60 * 3)
	//if( m_EnemyCount == 0 )
	{	
		ss.clear();
		
		//ss << "EnemyMid" << CEnemyMiddle1::GetExistNum() - 1;
		//
		//sp<CGameObject> spObj = CCommonObject::GetResMgr()->FindObject( ss.str().c_str() );
		//
		//Math::Vector2D vPos = spObj->GetPos();
		
		//for( int i = 0;i < 4;++i )
		//{
			//Sint32 Angle = DEG_TO_ANGLE( 180 * (i % 2) );
			//
			//Math::Vector2D vPos( 800 + 20 * Math::Cos( Angle ), 400 + 20 * Math::Sin( Angle ) );
			
		Math::Vector2D vPos( 800, 400 );
		
		ss.clear();
		
		ss << "PlEnemySmall" << count;
		
		string str = ss.str();
		
		
		CCommonObject::GetResMgr()->Push( new CFileData("enemy_small_1.png", str.c_str(), 
															"ENEMY", "enemyroll.csv", vPos ) );
									
		++count;
			
		//}
		
		m_EnemyCount = 1;
																
// 
	}	
			

}

//=============================================================================
//カーブの移動
//=============================================================================
void CEnemyPattern::MoveCurve()
{
	Math::Vector2D vPos( m_EnemyPat.m_vPos );
	
	Uint32 IntervalTime = m_EnemyPat.m_Interval;
	
	stringstream ss("");
	
	static int count = 0;
	
	if( ++m_Counter % IntervalTime == 0 )
	{	
		
		ss << "PlEnemySmall" << m_SmallEnemyNum;
		
		string str = ss.str();
		
		if( count % 3 == 2 )
		{
			CCommonObject::GetResMgr()->Push( new CFileData("enemy_small_2.png", str.c_str(),
															  "ENE_SMALL_2", "enemycurve1.csv", vPos ) );
		}																			
		
		else
		{
			CCommonObject::GetResMgr()->Push( new CFileData("enemy_small_1.png", str.c_str(), 
																"ENEMY", "enemycurve2.csv", vPos ) );
		}																			
															
									
		++m_SmallEnemyNum;
		
		++m_EnemyCount;
		
		++count;
		
		if( m_EnemyCount > m_EnemyPat.m_EnemyNum - 1 )
		{
			this->SetRemoveFlag( true );
		}
																	
	}	

}

//=============================================================================
//直進
//=============================================================================
void CEnemyPattern::MoveStraight( )
{
	Math::Vector2D vPos( m_EnemyPat.m_vPos );
	
	Uint32 IntervalTime = m_EnemyPat.m_Interval;
	
	stringstream ss("");
	
	if( ++m_Counter % IntervalTime == 0 )
	{	
		ss << "PlEnemySmall" << m_SmallEnemyNum;
		
		string str = ss.str();
		
		CCommonObject::GetResMgr()->Push( new CFileData("enemy_small_1.png", str.c_str(), 
																	"ENEMY", "enemystraight.csv", vPos ) );
																	
		++m_SmallEnemyNum;
		
		++m_EnemyCount;
		
		if( m_EnemyCount > m_EnemyPat.m_EnemyNum - 1 )
		{
			this->SetRemoveFlag( true );
		}
		
	}	

}

//=============================================================================
//自機狙いの移動
//=============================================================================
void CEnemyPattern::MoveAiming()
{
	Math::Vector2D vPos( m_EnemyPat.m_vPos);
	
	Uint32 IntervalTime = m_EnemyPat.m_Interval;
	
	static int count = 0;
	
	stringstream ss("");
	
	if( ++m_Counter % IntervalTime == 0 )
	{	
		ss << "PlEnemySmall" << m_SmallEnemyNum;
		
		string str = ss.str();
		
		CCommonObject::GetResMgr()->Push( new CFileData("enemy_small_1.png", str.c_str(), 
																	"ENEMY", "enemyaiming.csv", vPos ) );
																	
		++m_SmallEnemyNum;
		
		++m_EnemyCount;
		
		if( m_EnemyCount > m_EnemyPat.m_EnemyNum - 1 )
		{
			this->SetRemoveFlag( true );
		}
																
	}	


}

//=============================================================================
//自機狙いの移動
//=============================================================================
void CEnemyPattern::MoveMiddleEnemy()
{
	Math::Vector2D vPos( m_EnemyPat.m_vPos );
	
	Uint32 IntervalTime = m_EnemyPat.m_Interval;
	
	stringstream ss("");
	
	
	if( ++m_Counter % IntervalTime == 0 )
	{	
		ss << "PlEnemyMiddle" << CEnemyMiddle1::GetExistNum();
		
		string str = ss.str();
		
		CCommonObject::GetResMgr()->Push( new CFileData("enemy_middle_1.png", str.c_str(), 
														"ENE_MID_1", "enemymiddle1.csv", vPos ) );
																	
		++m_EnemyCount;
		
		if( m_EnemyCount > m_EnemyPat.m_EnemyNum - 1 )
		{
			this->SetRemoveFlag( true );
		}
																
	}	
														
														
	
}






