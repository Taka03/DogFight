//*============================================================================
//EnemyCurve.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "EnemyCurve.h"
#include "ResourceManager.h"
#include "Bullet.h"
#include "Common/Application.h"
#include "SceneGameMain.h"

const int SHOT_MAX = 3;

//============================================================================
//�R���X�g���N�^
//============================================================================
//[input]
//	pName:�t�@�C����
//	pDataName:�f�[�^�t�@�C����
//	vPos:�ݒ肷��ʒu
//===========================================================================
CEnemyCurve::CEnemyCurve( const char *pName, const char *pDataName, Math::Vector2D vPos )
:CEnemy( pName, pDataName, vPos ),
 m_RollAngle( 0 ),
 m_IsShoot( false ),
 m_ShotNum( 0 ),
 m_StreamCount( 0 )
{
	m_vInitPos = vPos;
}

//============================================================================
//�f�X�g���N�^
//============================================================================
CEnemyCurve::~CEnemyCurve(void)
{
}

//============================================================================
//�ړ�
//============================================================================
void CEnemyCurve::Move()
{
	m_fSize.x = 64;
	m_fSize.y = 64;	
	
	Shoot();
	
	if( m_vPos.x < 0 )
	{
		this->SetRemoveFlag( true );

	}
	
	if( m_vPos.y > SCREEN_HEIGHT )
	{
		this->SetRemoveFlag( true );
	}

	
	m_RollAngle += DEG_TO_ANGLE( 2 );
	
	//m_Scroll --;


	m_vPos.x = Math::Cos( m_RollAngle ) * 300 + SCREEN_WIDTH;
	m_vPos.y = -Math::Sin( m_RollAngle ) * 305 + SCREEN_HEIGHT/ 2;
	
}

//============================================================================
//�V���b�g����
//============================================================================
void CEnemyCurve::Shoot()
{
	static int count = 0;
	
	string str("");
	
	if( !m_IsShoot && ++m_ShootCount > 30 )
	{
		m_ShootCount = 0;
	}
	
	//�e�������o��
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
//�ړ��␳
//============================================================================
void CEnemyCurve::MoveAdjust()
{
	
}






