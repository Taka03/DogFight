//*============================================================================
//Missile.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "Missile.h"
#include "ResourceManager.h"

//=============================================================================
//variable
//=============================================================================
int CMissile::m_BulletNum = 0;

//============================================================================
//�R���X�g���N�^
//============================================================================
//[input]
//	pName:�t�@�C����
//	pDataName:�f�[�^�t�@�C����
//	vPos:�ʒu
//===========================================================================
CMissile::CMissile( const char *pName, const char *pDataName, Math::Vector2D vPos )
:CBullet( pName, pDataName, vPos ),
 m_TargetPos( 0, 0 )
{
	m_vInitPos = vPos;
	
	m_eType = CGameObject::TYPE_MISSILE;
	
	m_fSpeed = 2;
	
}

//============================================================================
//�f�X�g���N�^
//============================================================================
CMissile::~CMissile(void)
{
}

//============================================================================
//�ړ�
//============================================================================
void CMissile::Move()
{
	sp<CGameObject> spObj = CCommonObject::GetResMgr()->FindObject( "Player" );
	
	if( spObj != NULL )
	{	
		m_TargetPos = spObj->GetPos();
	}
	
	else
	{
		m_TargetPos = Math::Vector2D( 0, 0 );
	}	
		
	
	Sint32 TargetAngle = Math::ATan2( m_TargetPos.x - m_vPos.x, m_TargetPos.y - m_vPos.y );
	
	m_vPos.x += Math::Cos( TargetAngle ) * m_fSpeed;
	m_vPos.y += Math::Sin( TargetAngle ) * m_fSpeed;
	
	//��ʊO�ɂ�������폜
	if( m_vPos.x < 0 )
	{
		this->SetRemoveFlag( true );		
	}
	
	if( m_vPos.y < 0 )
	{
		this->SetRemoveFlag( true );		
	}
	
	if( m_vPos.y > SCREEN_HEIGHT )
	{
		this->SetRemoveFlag( true );		
	}
	
	if( m_vPos.x > SCREEN_WIDTH )
	{
		this->SetRemoveFlag( true );		
	}
	
}

//============================================================================
//�����蔻�菈��
//============================================================================
//[input]
//	spObj:���肷��I�u�W�F�N�g
//============================================================================
void CMissile::HitExec( sp<CGameObject> spObj )
{
	if( spObj->GetType() == CGameObject::TYPE_BULLET )
	{
		this->SetRemoveFlag( true );
	}
}
//============================================================================
//�ړ��␳
//============================================================================
//void CMissile::MoveAdjust()
//{
//
//}
//
