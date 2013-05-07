//*============================================================================
//EffectShot.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "EffectShot.h"
#include "Common/Application.h"
#include "ResourceManager.h"

//============================================================================
//コンストラクタ
//============================================================================
//[input]
//	pName:ファイル名
//	pDataName:データファイル名
//	vPos:位置
//===========================================================================
CEffectShot::CEffectShot( const char *pName, const char *pDataName, Math::Vector2D vPos )
:CEffect( pName, pDataName, vPos ),
 m_ShotCount( 0 )
{
	m_ExistCount = 0;
	m_eType = TYPE_BOMB;
	m_eState = STATE_NONE;
}


//============================================================================
//デストラクタ
//============================================================================
CEffectShot::~CEffectShot(void)
{
	printf("EffectShot:Remove\n");
}

//============================================================================
//処理
//============================================================================
void CEffectShot::Exec()
{
	sp<CGameObject> spObj = CCommonObject::GetResMgr()->FindObject("Player");

	Math::Vector2D vPos( 67, 0 );

	if( spObj != NULL )
	{	
		m_vPos = spObj->GetPos() + vPos;
	}

	CEffect::Exec();

}

void CEffectShot::SetAnimation()
{
	if( m_IsAnim )
	{
		/*アニメーションカウンタの増加*/
		if( ++m_AnimCount > m_AnimTime )
		{

			m_AnimCount = 0;

//			ショットカウントが偶数のときのみアニメーション増加
			if( m_ShotCount % 2 == 0 )
			{
				this->SetVisibleFlag( true );
				m_Anim.x += m_AnimSpeed;
			}

			else
			{
				this->SetVisibleFlag( false );
			}

			m_ShotCount++;
		}



		if( m_Anim.x >= m_DivNum.x - 1 )
		{
			this->SetRemoveFlag( true );
			m_Anim.x = 0;
		}

	}

}

