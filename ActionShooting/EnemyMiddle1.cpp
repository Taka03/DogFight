//*============================================================================
//EnemyMiddle1.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "EnemyMiddle1.h"
#include "ResourceManager.h"
#include "Bullet.h"
#include "Common/Application.h"
#include "SceneGameMain.h"

//=============================================================================
//variable
//=============================================================================
Uint32 CEnemyMiddle1::m_ExistNum = 0;


//============================================================================
//�R���X�g���N�^
//============================================================================
//[input]
//	pName:�t�@�C����
//	pDataName:�f�[�^�t�@�C����
//	vPos:�ݒ肷��ʒu
//===========================================================================
CEnemyMiddle1::CEnemyMiddle1( const char *pName, const char *pDataName, Math::Vector2D vPos )
:CEnemy( pName, pDataName, vPos )
{
	m_ExistNum++;
	
	m_eEnemyType = TYPE_MIDDLE;
	
	m_ID = m_ExistNum;
	
	stringstream ss("");
	
	ss << "PlEnemy_Cannon" << m_ExistNum;
	
	m_fSize.x = 104;
	m_fSize.y = 98;
	
	//sp<CGameObject> spObj( this );
	
	//�C��ǉ�
	CCommonObject::GetResMgr()->Push( new CFileData( "enemy_middle_1_cannon.png", ss.str().c_str(),
													 "ENE_CANNON", "enemycannon.csv",
													  this ) );
	
	ss << "PlEnemy_Fire" << m_ExistNum;

	CCommonObject::GetResMgr()->Push( new CFileData( "enemy_middle_fire.png", ss.str().c_str(),
													 "EFFECT_FR", "enemymidfire.csv",
													  this ) );


}

//============================================================================
//�f�X�g���N�^
//============================================================================
CEnemyMiddle1::~CEnemyMiddle1(void)
{
}

//============================================================================
//�ړ��␳
//============================================================================
void CEnemyMiddle1::MoveAdjust()
{
	if( m_vPos.x < -m_fSize.x )
	{
		this->SetRemoveFlag( true );
	}
}

