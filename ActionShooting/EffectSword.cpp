//*============================================================================
//EffectSword.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "EffectSword.h"
#include "Common/Application.h"
#include "ResourceManager.h"
#include "CommonObject.h"

//=============================================================================
//variable
//=============================================================================
Uint32 CEffectSword::m_HitCount = 0;

//============================================================================
//�R���X�g���N�^
//============================================================================
//[input]
//	pName:�t�@�C����
//	pDataName:�f�[�^�t�@�C����
//	vPos:�ʒu
//===========================================================================
CEffectSword::CEffectSword( const char *pName, const char *pDataName, Math::Vector2D vPos )
:CEffect( pName, pDataName, vPos )
{
	m_ExistCount = 0;
	
#if 0
		m_HitCount++;

		//���U��
		if( m_HitCount % m_DivNum.y == 0 )
		{
			m_eType = CGameObject::TYPE_SWORD_STRONG;
		}

		//��U��
		else
		{
			m_eType = CGameObject::TYPE_SWORD_WEAK;
		}

#else

		m_HitCount++;

		m_eType = CGameObject::TYPE_SWORD_WEAK;
#endif"
}


//============================================================================
//�f�X�g���N�^
//============================================================================
CEffectSword::~CEffectSword(void)
{
}

//============================================================================
//����
//============================================================================
void CEffectSword::Exec()
{
	sp<CGameObject> spObj = CCommonObject::GetResMgr()->FindObject( "Player" );
	
	Math::Vector2D vPos( 0, 0 );
	
	const int SLASH_NUM = 2;
	
	Math::Vector2D vAddPos[SLASH_NUM] =
	{
		Math::Vector2D( -5, -32 ),
		Math::Vector2D( 0, -28 ),
		//Math::Vector2D( -4, -32 ),
	};
	
	
	if( spObj != NULL )
	{
		vPos = spObj->GetPos() + vAddPos[ ( m_HitCount + 1 ) %SLASH_NUM];
	}
	
	else
	{
		vPos = Math::Vector2D( 0, 0 );	
	}
	
	m_vPos = vPos;
	
	if( ++m_ExistCount > 2 )
	{	
		m_AnimCount++;	
		m_ExistCount = 0;
	}
		
	m_Anim.x = m_AnimCount % m_DivNum.x;
	
	m_Anim.y = ( m_HitCount + 1 ) % (m_DivNum.y - 1);
	
	if( m_Anim.x == m_DivNum.x - 1 )
	{
		m_eState = STATE_DIED;	
	}
	
	m_DstRect.Set( m_vPos.x, m_vPos.y, m_fSize.x, m_fSize.y );
	
	m_SrcRect.Set( m_Anim.x * m_fSize.x, m_Anim.y * m_fSize.y, m_fSize.x, m_fSize.y );
	
	m_Color.r = 255;
	m_Color.g = 0;

	//�`��
	CSprite::DrawRequest();
	
	//��Ԗ��̏���
	StateExec();
	
}

//============================================================================
//�����蔻�菈��
//============================================================================
//[input]
//	spObj:���肷��I�u�W�F�N�g
//============================================================================
void CEffectSword::HitExec( sp<CGameObject> spObj )
{
}



