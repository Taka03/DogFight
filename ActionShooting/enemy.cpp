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
//�R���X�g���N�^
//============================================================================
//[input]
//	pName:�t�@�C����
//	pDataName:�f�[�^�t�@�C����
//  vPos �ݒ肷��ʒu
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
//�f�X�g���N�^
//============================================================================
CEnemy::~CEnemy(void)
{
}

//============================================================================
//�p�����[�^�[�̓ǂݍ���
//============================================================================
//[input]
//	pFileName:�t�@�C����
//===========================================================================
void CEnemy::LoadParameter( const char *pFileName )
{
	CFileLoader FileLoad( pFileName );
	
	vector< string > vecStr = CFileLoader::SplitString( FileLoad.GetStrList().at( 0 ), "," );
	
	//----------------------------------------------
	//�ʒu�̐ݒ�
	//----------------------------------------------
	SetParameter( m_vInitPos.x, vecStr.at( 0 ) );
	
	SetParameter( m_vInitPos.y, vecStr.at( 1 ) );
	
	//----------------------------------------------
	//�p�x�̐ݒ�
	//----------------------------------------------
	SetParameter( m_InitAngle, vecStr.at( 2 ) );
	
	//----------------------------------------------
	//�g�k���̐ݒ�
	//----------------------------------------------
	SetParameter( m_fInitScale.x, vecStr.at( 3 ) );
	
	SetParameter( m_fInitScale.y, vecStr.at( 4 ) );
	
	//----------------------------------------------
	//�������̐ݒ�
	//----------------------------------------------
	SetParameter( m_DivNum.x, vecStr.at( 5 ) );
	
	SetParameter( m_DivNum.y, vecStr.at( 6 ) );
	
	//----------------------------------------------
	//�A�j���[�V�����̐ݒ�
	//----------------------------------------------
	SetParameter( m_IsAnim, vecStr.at( 7 ) );
	
	SetParameter( m_AnimTime, vecStr.at( 8 ) );
	
	//----------------------------------------------
	//�Q�[���̐ݒ�
	//----------------------------------------------
	SetParameter( m_Life, vecStr.at( 9 ) );
	
	SetParameter( m_Score, vecStr.at( 10 ) );
	
	//----------------------------------------------
	//�p�^�[���̐ݒ�
	//----------------------------------------------
	SetParameter( (int&)m_eMovePat, vecStr.at( 11 ) );
	
	SetParameter( (int&)m_eShotPat, vecStr.at( 12 ) );
	
	//----------------------------------------------
	//�ړ��X�s�[�h�̐ݒ�
	//----------------------------------------------
	SetParameter( m_fSpeed, vecStr.at( 13 ) );
	
	//----------------------------------------------
	//�e�̐ݒ�
	//----------------------------------------------
	SetParameter( m_ShotTime, vecStr.at( 14 ) );
	
	//�e�̍ő吔�̐ݒ�
	SetParameter( m_MaxShot, vecStr.at( 15 ) );
	
	
	
	
}

//============================================================================
//�ړ�
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
//�V���b�g����
//============================================================================
void CEnemy::Shoot()
{
	string str("");
	
	if( !m_IsShoot )
	{
		m_ShootCount--;
	}
	
	//�e�������o��
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
//�A�j���[�V�����̐ݒ�
//============================================================================
void CEnemy::SetAnimation()
{
	if( m_IsDamaged )
	{
		const int HIT_FLASH_TIME = 2;
		
		/*�A�j���[�V�����J�E���^�̑���*/
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
//�ړ��␳
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
//�ړ��p�^�[���̏���
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
//�V���b�g�p�^�[���̏���
//============================================================================
void CEnemy::ShotPatExec()
{
	switch( m_eShotPat )
	{
		//�e�������Ȃ�
		case SHOT_NONE:
		{
			break;
		}
		
		//���i�e
		case SHOT_STRAIGHT:
		{
			ShotPatStraight();
			break;
		}
		
		//���@�_���e
		case SHOT_AIMSHOOT:
		{
			ShotPatAimShoot();
			break;
		}
		
		//�U���e
		case SHOT_MISSILE:
		{
			ShotPatMissile();
			break;
		}
	}	
}

//============================================================================
//�V���b�g�p�^�[���̏���
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
//�����蔻�菈��
//============================================================================
//[input]
//	spObj:���肷��I�u�W�F�N�g
//============================================================================
void CEnemy::HitExec( sp<CGameObject> spObj )
{
	static int count = 0;
	static int count2 = 0;

	if( spObj != NULL )
	{
		//�e�ɓ��������ꍇ
		if( spObj->GetType() == CGameObject::TYPE_BULLET )
		{
			m_IsDamaged = true;

			m_Life--;

			stringstream ss("");

			ss << "PlaBurst" << count;

			string str = ss.str();

			//�e������
			spObj->SetVisibleFlag( false );

			CCommonObject::GetResMgr()->Push( new CFileData("player_bullet_burst.png", str.c_str(),
															"EFFECT_BT", "effectburst.csv", this->GetPos() ) );

			//		�Q�[�W�̑���
			CGauge::AddGauge( CPlayer::GetGaugeAddShot() );


			spObj->SetRemoveFlag( true );

			++count;

			m_IsSlash = false;


		}
		
		//�G�t�F�N�g(��(��))�̏ꍇ
		else if( spObj->GetType() == CGameObject::TYPE_SWORD_WEAK )
		{
			m_IsDamaged = true;

			if( m_IsSwordDamage )
			{
				m_Life --;
			}


	//		�Q�[�W�̑���
			CGauge::AddGauge( CPlayer::GetGaugeAdd() );

			//�q�b�g���Ԃ̃��Z�b�g
			CSceneGameMain::SetHitTime( 0 );

			const int STOP_TIME = 60;//�~�܂��Ă��鎞��

			m_StateTime = STOP_TIME;

			m_eState = STATE_DAMAGE_SWORD_W;

			m_IsSlash = true;


	
	
		}
		
		//�G�t�F�N�g(��(��))�̏ꍇ
		else if( spObj->GetType() == CGameObject::TYPE_SWORD_STRONG )
		{
			m_IsDamaged = true;

			if( m_IsSwordDamage )
			{
				m_Life --;
			}

			
	
	
			//�q�b�g���Ԃ̃��Z�b�g
			CSceneGameMain::SetHitTime( 0 );

			const int BLOW_TIME = 60;

			m_StateTime = BLOW_TIME;

			m_eState = STATE_DAMAGE_SWORD_S;
		}
		
		//�G�t�F�N�g(����)�̏ꍇ
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
		
		//������΂���Ă���G�̏ꍇ
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
//��Ԗ��̏���
//============================================================================
void CEnemy::StateExec()
{
	//���C�t�������Ȃ����玀�S
	if( m_Life <= 0 )
	{
		m_IsDead = true;

		m_DeadCount++;
	}
	
	switch( m_eState )
	{
		//�����Ȃ����
		case STATE_NONE:
		{
			m_IsBlowed = false;
			
			this->SetStopFlag( false );
			
			
			break;
		}
		
		//�_���[�W���󂯂Ă��鎞(�V���b�g)
		case STATE_DAMAGE_SHOT:
		{
			
			m_eState = STATE_NONE;
			
			
			break;
		}
		
		//�_���[�W���󂯂Ă��鎞(�ߐڍU��(��))
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
		
		//�_���[�W���󂯂Ă��鎞(�ߐڍU��(��))
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
			//	const int STOP_TIME = 60;//�~�܂��Ă��鎞��
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
		
		//�������Ă���Ƃ�
		case STATE_DAMAGE_BOMB:
		{
			
			m_eState = STATE_NONE;
			
			break;
		}
		
		//���񂾏��
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
		

		//�����G�t�F�N�g��\��
		stringstream ss(" ");
		
		string str;
		
		ss << "PlaBomb" << count;
		
		str = ss.str();
		
		//if( m_DeadTime == 0 )
		//{

		//=============================================================================
		//�n�C�p�[���[�h���͗U���ɂ���
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
		
		int AddScore = 2 * CSceneGameMain::GetHitCount();//�ǉ��X�R�A
		
		//�X�R�A�����Z
		CSceneGameMain::AddScore( m_Score + AddScore );
		
		m_IsDamaged = true;
		
		//�������̍Đ�
		CCommonObject::GetSoundMgr()->Play("BombEnemy");
		
		this->SetRemoveFlag( true );
		
	}
	
	
	
	
}




