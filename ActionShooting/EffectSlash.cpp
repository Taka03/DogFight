//*============================================================================
//EffectSlash.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "EffectSlash.h"
#include "Common/Application.h"


//============================================================================
//コンストラクタ
//============================================================================
//[input]
//	pName:ファイル名
//	pDataName:データファイル名
//	vPos:位置
//===========================================================================
CEffectSlash::CEffectSlash( const char *pName, const char *pDataName, Math::Vector2D vPos )
:CEffect( pName, pDataName, vPos )
{
	m_vPos = vPos;
	m_ExistCount = 0;
	m_eType = TYPE_BOMB;
	m_eState = STATE_NONE;
}

//============================================================================
//コンストラクタ
//============================================================================
//[input]
//	pName:ファイル名
//	pDataName:データファイル名
//	vPos:位置
//===========================================================================
CEffectSlash::CEffectSlash( const char *pName, const char *pDataName, CGameObject *pObj )
:CEffect( pName, pDataName, Math::Vector2D( 0, 0 ) ),
 m_pTargetObj( pObj )

{
	m_ExistCount = 0;
	m_eType = TYPE_BOMB;
	m_eState = STATE_NONE;

}



//============================================================================
//デストラクタ
//============================================================================
CEffectSlash::~CEffectSlash(void)
{
	printf("EffectSlash:Remove\n");
}

//============================================================================
//処理
//============================================================================
void CEffectSlash::Exec()
{

	CEffect::Exec();


}

//============================================================================
//アニメーションの設定
//============================================================================
void CEffectSlash::SetAnimation()
{
	const int ANIM_MAX = 4;

	int Anim[ANIM_MAX] =
	{
		 2,
		 2,
		 2,
		 3,
	};


	/*アニメーションカウンタの増加*/
	if( ++m_AnimCount > Anim[m_Anim.x] )
	{
		m_AnimCount = 0;
		m_Anim.x += m_AnimSpeed;
	}

	if( m_Anim.x >= m_DivNum.x )
	{
		this->SetRemoveFlag( true );
	}



}
