//*============================================================================
//enemy.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "enemy.h"
#include "ResourceManager.h"
#include "Bullet.h"
#include "Common/Application.h"
#include "SceneGameMain.h"
#include "FileLoader.h"
#include "SoundManager.h"

//============================================================================
//コンストラクタ
//============================================================================
//[input]
//	pName:ファイル名
//	pDataName:データファイル名
//  vPos 設定する位置
//===========================================================================
CEnemy::CEnemy( const char *pName, const char *pDataName, Math::Vector2D vPos )
:CCharacter( pName, pDataName ),
 m_eState( STATE_NONE ),
 m_eMovePat( MOVE_STRAIGHT ),
 m_eShotPat( SHOT_NONE ),
 m_ShootCount( 30 ),
 m_Scroll( SCREEN_WIDTH ),
 m_eEnemyType( TYPE_SMALL ),
 m_RollAngle( DEG_TO_ANGLE( 90 ) ),
 m_StateTime( 0 ),
 m_IsShoot( false ),
 m_IsDamaged( false ),
 m_IsBlowed( false ),
 m_IsDead( false ),
 m_IsSwordDamage( true ),
 m_ShotNum( 0 ),
 m_MaxShot( 1 ),
 m_StreamCount( 0 ),
 m_StreamTime( 10 ),
 m_ShotTime( 0 ),
 m_DeadTime( 0 ),
 m_BombDamage( 4 ),
 m_IsSlash( false ),
 m_IsSlashEnd( false )
{
	m_eState = STATE_NONE;

	m_vPos = vPos;
	
	sp<CGameObject> spObj = CCommonObject::GetResMgr()->FindObject( "Player" );
	
	if( spObj != NULL )
	{	
		m_vTargetPos = spObj->GetPos();
	}
	
	else
	{
		m_vTargetPos = Math::Vector2D( 0, 0 );
	}
	
	m_vCenterPos = Math::Vector2D( 32, 32 );
	
	m_eType = CCharacter::TYPE_ENEMY;
	
	LoadParameter( pDataName );
	
	m_vInitPos = vPos;
	
	CFileLoader FileLoad( "sworddamage.csv" );
	
	vector< string > vecStr = CFileLoader::SplitString( FileLoad.GetStrList().at( 0 ), "," );
	
	SetParameter( m_IsSwordDamage, vecStr.at( 0 ) );
	
}

//============================================================================
//デストラクタ
//============================================================================
CEnemy::~CEnemy(void)
{
}

//============================================================================
//パラメーターの読み込み
//============================================================================
//[input]
//	pFileName:ファイル名
//===========================================================================
void CEnemy::LoadParameter( const char *pFileName )
{
	CFileLoader FileLoad( pFileName );
	
	vector< string > vecStr = CFileLoader::SplitString( FileLoad.GetStrList().at( 0 ), "," );
	
	//----------------------------------------------
	//位置の設定
	//----------------------------------------------
	SetParameter( m_vInitPos.x, vecStr.at( 0 ) );
	
	SetParameter( m_vInitPos.y, vecStr.at( 1 ) );
	
	//----------------------------------------------
	//角度の設定
	//----------------------------------------------
	SetParameter( m_InitAngle, vecStr.at( 2 ) );
	
	//----------------------------------------------
	//拡縮率の設定
	//----------------------------------------------
	SetParameter( m_fInitScale.x, vecStr.at( 3 ) );
	
	SetParameter( m_fInitScale.y, vecStr.at( 4 ) );
	
	//----------------------------------------------
	//分割数の設定
	//----------------------------------------------
	SetParameter( m_DivNum.x, vecStr.at( 5 ) );
	
	SetParameter( m_DivNum.y, vecStr.at( 6 ) );
	
	//----------------------------------------------
	//アニメーションの設定
	//----------------------------------------------
	SetParameter( m_IsAnim, vecStr.at( 7 ) );
	
	SetParameter( m_AnimTime, vecStr.at( 8 ) );
	
	//----------------------------------------------
	//ゲームの設定
	//----------------------------------------------
	SetParameter( m_Life, vecStr.at( 9 ) );
	
	SetParameter( m_Score, vecStr.at( 10 ) );
	
	//----------------------------------------------
	//パターンの設定
	//----------------------------------------------
	SetParameter( (int&)m_eMovePat, vecStr.at( 11 ) );
	
	SetParameter( (int&)m_eShotPat, vecStr.at( 12 ) );
	
	//----------------------------------------------
	//移動スピードの設定
	//----------------------------------------------
	SetParameter( m_fSpeed, vecStr.at( 13 ) );
	
	//----------------------------------------------
	//弾の設定
	//----------------------------------------------
	SetParameter( m_ShotTime, vecStr.at( 14 ) );
	
	//弾の最大数の設定
	SetParameter( m_MaxShot, vecStr.at( 15 ) );
	
	
	
	
}

//============================================================================
//移動
//============================================================================
void CEnemy::Move()
{
	Shoot();
	
	MovePatExec();
	
	#if defined( DEBUG ) | ( _DEBUG )
	
		//Renderer::IRender *pRender
	
	#endif
	
}

//============================================================================
//ショット処理
//============================================================================
void CEnemy::Shoot()
{
	string str("");
	
	if( !m_IsShoot )
	{
		m_ShootCount--;
	}
	
	//弾を撃ち出す
	if( m_ShootCount == 0 )
	{
		m_IsShoot = true;
	}	
	
	if( m_IsShoot )
	{
		if( ++m_StreamCount >= m_StreamTime )
		{
			m_StreamCount = 0;
			
			ShotPatExec();
			
			m_ShotNum++;
		}
		
		if( m_ShotNum >= m_MaxShot )
		{
			//const int MAX_TIME = 10;
			
			m_ShootCount = m_ShotTime;
			
			m_ShotNum = 0;
			m_IsShoot = false;
		}
	
	}
}

//============================================================================
//アニメーションの設定
//============================================================================
void CEnemy::SetAnimation()
{
	if( m_IsDamaged )
	{
		const int HIT_FLASH_TIME = 2;
		
		/*アニメーションカウンタの増加*/
		if( ++m_AnimCount > HIT_FLASH_TIME )
		{
			m_AnimCount = 0;
			m_Anim.x += m_AnimSpeed;
		}
		
		if( m_Anim.x >= m_DivNum.x )
		{
			m_IsDamaged = false;
			m_Anim.x = 0;
		}
		
	}
}


//============================================================================
//移動補正
//============================================================================
void CEnemy::MoveAdjust()
{
	if( m_vPos.x < -m_fSize.x )
	{
		this->SetRemoveFlag( true );
		
	}
	
	//if( m_vPos.y > SCREEN_HEIGHT )
	//{
	//	this->SetRemoveFlag( true );
	//}
}

//============================================================================
//移動パターンの処理
//============================================================================
void CEnemy::MovePatExec()
{
	switch( m_eMovePat )
	{
		case MOVE_STRAIGHT:
		{
			MovePatStraight();
			break;
		}
		
		case MOVE_ROLL:
		{
			MovePatRoll();
			break;
		}
		
		case MOVE_CURVE:
		{
			MovePatCurve();
			break;
		}
		
		case MOVE_AIMING:
		{
			MovePatAiming();
			break;
		}
	}
}

void CEnemy::MovePatStraight()
{
	m_vPos.x -= m_fSpeed;
}

void CEnemy::MovePatRoll()
{
	m_RollAngle += DEG_TO_ANGLE( 3 );
	
	m_Scroll --;

	m_vPos.x = Math::Cos( m_RollAngle ) * 100 + m_Scroll;
	m_vPos.y = Math::Sin( m_RollAngle ) * 100 + m_vInitPos.y;

}

void CEnemy::MovePatCurve()
{
	m_RollAngle += DEG_TO_ANGLE( 2 );
	
	m_vPos.x = Math::Cos( m_RollAngle ) * 300 + m_vInitPos.x;
	
	if( m_vInitPos.y < SCREEN_HEIGHT / 2 )
	{
		m_vPos.y = -Math::Sin( m_RollAngle ) * 305 + SCREEN_HEIGHT/ 2;
	}
	
	else
	{
		m_vPos.y = Math::Sin( m_RollAngle ) * 305 + SCREEN_HEIGHT/ 2;
	}

}

void CEnemy::MovePatAiming()
{
	Sint32 TargetAngle = Math::ATan2( m_vTargetPos.x - m_vInitPos.x, m_vTargetPos.y - m_vInitPos.y );
	
	m_vPos.x += Math::Cos( TargetAngle ) * m_fSpeed;
	m_vPos.y += Math::Sin( TargetAngle ) * m_fSpeed;
}

//============================================================================
//ショットパターンの処理
//============================================================================
void CEnemy::ShotPatExec()
{
	switch( m_eShotPat )
	{
		//弾を撃たない
		case SHOT_NONE:
		{
			break;
		}
		
		//直進弾
		case SHOT_STRAIGHT:
		{
			ShotPatStraight();
			break;
		}
		
		//自機狙い弾
		case SHOT_AIMSHOOT:
		{
			ShotPatAimShoot();
			break;
		}
		
		//誘導弾
		case SHOT_MISSILE:
		{
			ShotPatMissile();
			break;
		}
	}	
}

//============================================================================
//ショットパターンの処理
//============================================================================
void CEnemy::ShotPatStraight()
{
	static int count = 0;
	
	stringstream ss(" ");
	
	ss << "PlEnemy_Bullet" << count;
	
	string str = ss.str();
	
	CCommonObject::GetResMgr()->Push( new CFileData("enemy_bullet_red.png", str.c_str(), 
													"EBULLET", "enemybullet.csv", m_vPos ) );
	
	++count;
}

void CEnemy::ShotPatAimShoot()
{
	static int count = 0;
	
	stringstream ss(" ");
	
	ss << "PlEnemy_AimBullet" << count;
	
	string str = ss.str();
	
	CCommonObject::GetResMgr()->Push( new CFileData("enemy_bullet_red.png", str.c_str(), 
													"AIMSHOOT", "enemybullet.csv", m_vPos ) );
	
	++count;
}

void CEnemy::ShotPatMissile()
{
	static int count = 0;
	
	stringstream ss(" ");
	
	ss << "PlEnemy_Missile" << count;
	
	string str = ss.str();
	
	CCommonObject::GetResMgr()->Push( new CFileData("enemy_bullet_red.png", str.c_str(), 
													"MISSILE", "enemybullet.csv", m_vPos ) );
	
	++count;
}

//============================================================================
//当たり判定処理
//============================================================================
//[input]
//	spObj:判定するオブジェクト
//============================================================================
void CEnemy::HitExec( sp<CGameObject> spObj )
{
	static int count = 0;
	static int count2 = 0;

	if( spObj != NULL )
	{
		//弾に当たった場合
		if( spObj->GetType() == CGameObject::TYPE_BULLET )
		{
			m_IsDamaged = true;

			m_Life--;

			stringstream ss("");

			ss << "PlaBurst" << count;

			string str = ss.str();

			//弾を消す
			spObj->SetVisibleFlag( false );

			CCommonObject::GetResMgr()->Push( new CFileData("player_bullet_burst.png", str.c_str(),
															"EFFECT_BT", "effectburst.csv", this->GetPos() ) );

			//		ゲージの増加
			CGauge::AddGauge( CPlayer::GetGaugeAddShot() );


			spObj->SetRemoveFlag( true );

			++count;

			m_IsSlash = false;


		}
		
		//エフェクト(剣(弱))の場合
		else if( spObj->GetType() == CGameObject::TYPE_SWORD_WEAK )
		{
			m_IsDamaged = true;

			if( m_IsSwordDamage )
			{
				m_Life --;
			}


	//		ゲージの増加
			CGauge::AddGauge( CPlayer::GetGaugeAdd() );

			//ヒット時間のリセット
			CSceneGameMain::SetHitTime( 0 );

			const int STOP_TIME = 60;//止まっている時間

			m_StateTime = STOP_TIME;

			m_eState = STATE_DAMAGE_SWORD_W;

			m_IsSlash = true;


	
	
		}
		
		//エフェクト(剣(強))の場合
		else if( spObj->GetType() == CGameObject::TYPE_SWORD_STRONG )
		{
			m_IsDamaged = true;

			if( m_IsSwordDamage )
			{
				m_Life --;
			}

			
	
	
			//ヒット時間のリセット
			CSceneGameMain::SetHitTime( 0 );

			const int BLOW_TIME = 60;

			m_StateTime = BLOW_TIME;

			m_eState = STATE_DAMAGE_SWORD_S;
		}
		
		//エフェクト(爆発)の場合
		else if( spObj->GetType() == CGameObject::TYPE_CHAINBOMB )
		{
			m_IsDamaged = true;

			m_IsSlash = true;

			m_Life -= m_BombDamage;

			m_eState = STATE_DAMAGE_BOMB;
		}
		
		else if( spObj->GetType() == CGameObject::TYPE_BLOWENEMY )
		{
			m_eState = STATE_NONE;
		}
		
		//吹き飛ばされている敵の場合
		else if( spObj->GetType() == CGameObject::TYPE_ENEMY && spObj->GetBlowFlag() )
		{



			//m_Life -= 4;

			const int BLOW_TIME = 60;

			m_StateTime = BLOW_TIME;

			m_eState = STATE_DAMAGE_SWORD_S;
			
		}
	}
		
}

//============================================================================
//状態毎の処理
//============================================================================
void CEnemy::StateExec()
{
	//ライフが無くなったら死亡
	if( m_Life <= 0 )
	{
		m_IsDead = true;

		m_DeadCount++;
	}
	
	switch( m_eState )
	{
		//何もない状態
		case STATE_NONE:
		{
			m_IsBlowed = false;
			
			this->SetStopFlag( false );
			
			
			break;
		}
		
		//ダメージを受けている時(ショット)
		case STATE_DAMAGE_SHOT:
		{
			
			m_eState = STATE_NONE;
			
			
			break;
		}
		
		//ダメージを受けている時(近接攻撃(弱))
		case STATE_DAMAGE_SWORD_W:
		{
			static int count2 = 0;

			stringstream ss("");

			ss << "PlaSlash" << count2;

			string str = ss.str();




			if( m_StateTime == 60 )
			{
				CCommonObject::GetResMgr()->Push( new CFileData("player_slash_hit.png", str.c_str(),
																				"EFFECT_SL", "effectslash.csv", this->GetPos() ) );
				count2++;
			}

			--m_StateTime;

			//this->SetStopFlag( true );
			
			if( m_StateTime < 0 )
			{

				m_eState = STATE_NONE;
				
				
			}
			
			break;
		}
		
		//ダメージを受けている時(近接攻撃(強))
		case STATE_DAMAGE_SWORD_S:
		{
			if( m_eEnemyType == TYPE_SMALL )
			{	
				const int BLOW_SPEED =  10;
				
				m_vPos.x += BLOW_SPEED;
				
				m_Angle += DEG_TO_ANGLE( 60 );
				
				if( m_vPos.x >= SCREEN_WIDTH - m_fSize.x * 2 )
				{
					m_IsDead = true;

				}
			}
			
			else if( m_eEnemyType == TYPE_MIDDLE )
			{
				this->SetStopFlag( true );
				
				if( --m_StateTime < 0 )
				{
					
					m_eState = STATE_NONE;
				}
			}			
			//if( --m_StateTime < 0 )
			//{
			//	m_eState = STATE_DAMAGE_SWORD_W;
			//	
			//	const int STOP_TIME = 60;//止まっている時間
			//	
			//	m_StateTime = STOP_TIME;
			//	
			//	m_IsBlowed = false;
			//	
			//	
			//}
			//
			break;
		}
		
		//爆発しているとき
		case STATE_DAMAGE_BOMB:
		{
			
			m_eState = STATE_NONE;
			
			break;
		}
		
		//死んだ状態
		case STATE_DIED:
		{
			
		
			//if( ++m_DeadTime > 30 )
			//{ 												
			//	m_DeadTime = 0;
			//}
			
			break;
		}
		
	}
	
	if( m_IsDead /*&& m_DeadCount > 10 */ )
	{
		static int count = 0;
		

		//爆発エフェクトを表示
		stringstream ss(" ");
		
		string str;
		
		ss << "PlaBomb" << count;
		
		str = ss.str();
		
		//if( m_DeadTime == 0 )
		//{

		//=============================================================================
		//ハイパーモード時は誘爆にする
		//=============================================================================
		if( m_eEnemyType == TYPE_SMALL )
		{
			if( CPlayer::GetHyperMode() && m_IsSlash  )
			{
				CCommonObject::GetResMgr()->Push( new CFileData("bomb.png", str.c_str(),
																"EFFECT_TB", "effectbomb.csv", this->GetPos() ) );

			}

			else
			{
				CCommonObject::GetResMgr()->Push( new CFileData("bomb.png", str.c_str(),
																"EFFECT_B", "effectbomb.csv", this->GetPos() ) );

			}
		}

		else if( m_eEnemyType == TYPE_MIDDLE )
		{
			if( CPlayer::GetHyperMode() && m_IsSlash )
			{
				CCommonObject::GetResMgr()->Push( new CFileData("bomb.png", str.c_str(),
																"EFFECT_TB", "effectbombmiddle.csv", this->GetPos() ) );

			}

			else
			{

				CCommonObject::GetResMgr()->Push( new CFileData("bomb.png", str.c_str(),
																"EFFECT_B", "effectbombmiddle.csv", this->GetPos() ) );
			}
		}
//	}
														
		count++;		
		
		CSceneGameMain::SetHitTime( 0 );
		
		CSceneGameMain::AddHitCount();
		
		int AddScore = 2 * CSceneGameMain::GetHitCount();//追加スコア
		
		//スコアを加算
		CSceneGameMain::AddScore( m_Score + AddScore );
		
		m_IsDamaged = true;
		
		//爆発音の再生
		CCommonObject::GetSoundMgr()->Play("BombEnemy");
		
		this->SetRemoveFlag( true );
		
	}
	
	
	
	
}




