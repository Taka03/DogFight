//*============================================================================
//EffectPhoton.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "EffectPhoton.h"
#include "Common/Application.h"
#include "Gauge.h"
#include "ResourceManager.h"
#include "Player.h"


//============================================================================
//コンストラクタ
//============================================================================
//[input]
//	pName:ファイル名
//	pDataName:データファイル名
//	vPos:位置
//===========================================================================
CEffectPhoton::CEffectPhoton( const char *pName, const char *pDataName, Math::Vector2D vPos )
:CEffect( pName, pDataName, vPos )
{
	m_ExistCount = 0;
	//m_eType = TYPE_BOMB;
	m_eState = STATE_NONE;
}


//============================================================================
//デストラクタ
//============================================================================
CEffectPhoton::~CEffectPhoton(void)
{
	printf("EffectPhoton:Remove\n");
}

//============================================================================
//レンダリング
//============================================================================
void CEffectPhoton::Rendering()
{
	if( CPlayer::GetHyperMode() )
	{
		Renderer::IRender *pRender = CCommonObject::GetAppli()->GetRenderer();

		pRender->FillRect( Math::Rect2DF(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT ), CColor( 0, 0, 0, 128 ) );


		pRender->SetDrawType( DRAW_TYPE_ADD );

		CSprite::Rendering();

		pRender->SetDrawType( DRAW_TYPE_NORMAL );

	}
}

//============================================================================
//処理
//============================================================================
void CEffectPhoton::Exec()
{
	Math::Matrix matWorld;
	Math::Matrix matTemp;


	matWorld.Identity();
	matTemp.Identity();


	sp<CGameObject> spObj = CCommonObject::GetResMgr()->FindObject( "Player" );	
	
	if( spObj != NULL )
	{
		m_vPos = spObj->GetPos();
	}
	
	float fGauge = CGauge::GetGaugeVal();
	
	const float fGAUGE_MAX = 100.0f;


	m_fScale.x = fGauge / fGAUGE_MAX;

	m_fScale.y = fGauge / fGAUGE_MAX;

	if( fGauge <= 0.0f )
	{
		this->SetRemoveFlag( true );
	}
	
	/*アニメーションの設定*/
	SetAnimation();

	//移動処理
	if( !this->GetStopFlag() )
	{
		Move();
	}

	//状態毎の処理
	StateExec();

	/*描画元*/
	m_SrcRect.Set( m_Anim.x * m_fSize.x, m_Anim.y * m_fSize.y, m_fSize.x, m_fSize.y );

	matTemp.Scaling( m_fScale.x, m_fScale.y, 1.0f );

	matWorld.Multiply( matTemp );

	//Math::Vector2D vPos( -12, -24 );

	Math::Vector2D vPos( m_fSize.x / 4 + 12, m_fSize.y / 4 + 4 );

	matTemp.Translation( m_vPos.x + vPos.x, m_vPos.y + vPos.y, 1.0f );

	matWorld.Multiply( matTemp );



	m_pSpr->Begin();



	m_pSpr->DrawSquareMatrix( matWorld ,m_SrcRect, m_Color );



	m_pSpr->End();


}





