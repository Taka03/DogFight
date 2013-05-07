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
//�R���X�g���N�^
//============================================================================
//[input]
//	pName:�t�@�C����
//	pDataName:�f�[�^�t�@�C����
//	vPos:�ݒ肷��ʒu
//===========================================================================
CEnemyCannon::CEnemyCannon( const char *pName, const char *pDataName, Math::Vector2D vPos )
:CEnemy( pName, pDataName, vPos )
{
	
	m_fSize.x = 48;
	m_fSize.y = 48;
	
	m_vCenterPos = Math::Vector2D( 32, 16 );
	
}

//============================================================================
//�R���X�g���N�^
//============================================================================
//[input]
//	pName:�t�@�C����
//	pDataName:�f�[�^�t�@�C����
//	vPos:�ݒ肷��ʒu
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
//�f�X�g���N�^
//============================================================================
CEnemyCannon::~CEnemyCannon(void)
{
}

//============================================================================
//�ړ�
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
	
		//�v���C���[�I�u�W�F�N�g���擾
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
		
		//�p�x�̐ݒ�
		m_Angle = Angle;
		
	}
	
	else
	{
		this->SetRemoveFlag( true );
	}
}

