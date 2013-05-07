//*============================================================================
//EffectFire.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "EffectFire.h"
#include "Common/Application.h"


//============================================================================
//�R���X�g���N�^
//============================================================================
//[input]
//	pName:�t�@�C����
//	pDataName:�f�[�^�t�@�C����
//	vPos:�ʒu
//===========================================================================
CEffectFire::CEffectFire( const char *pName, const char *pDataName, Math::Vector2D vPos )
:CEffect( pName, pDataName, vPos )
{
	m_ExistCount = 0;
	m_eType = TYPE_BOMB;
	m_eState = STATE_NONE;
}

//============================================================================
//�R���X�g���N�^
//============================================================================
//[input]
//	pName:�t�@�C����
//	pDataName:�f�[�^�t�@�C����
//	vPos:�ʒu
//===========================================================================
CEffectFire::CEffectFire( const char *pName, const char *pDataName, CGameObject *pObj )
:CEffect( pName, pDataName, Math::Vector2D( 0, 0 ) ),
 m_pTargetObj( pObj )
{
	m_ExistCount = 0;
	m_eType = TYPE_BOMB;
	m_eState = STATE_NONE;
}



//============================================================================
//�f�X�g���N�^
//============================================================================
CEffectFire::~CEffectFire(void)
{
	printf("EffectFire:Remove\n");
}

//============================================================================
//����
//============================================================================
void CEffectFire::Exec()
{
	if( m_pTargetObj != NULL )
	{
		m_vPos = m_pTargetObj->GetPos() + Math::Vector2D( 105, 0 );

//		���̃I�u�W�F�N�g����������폜
		if( m_pTargetObj->GetRemoveFlag() )
		{
			this->SetRemoveFlag( true );
		}
	}

	CEffect::Exec();

}
