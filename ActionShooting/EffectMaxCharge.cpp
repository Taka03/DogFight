//*============================================================================
//EffectMaxCharge.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "EffectMaxCharge.h"
#include "Common/Application.h"
#include "Gauge.h"
#include "ResourceManager.h"
#include "Player.h"
#include "FileLoader.h"


//============================================================================
//コンストラクタ
//============================================================================
//[input]
//	pName:ファイル名
//	pDataName:データファイル名
//	vPos:位置
//===========================================================================
CEffectMaxCharge::CEffectMaxCharge( const char *pName, const char *pDataName, Math::Vector2D vPos )
:CEffect( pName, pDataName, vPos ),
 m_vAdjPos( 0, 0 ),
 m_IsAdd( false ),
 m_Alpha( 255 )
{
	m_ExistCount = 0;
	//m_eType = TYPE_BOMB;
	m_eState = STATE_NONE;
	
	LoadParameter( pDataName );
}


//============================================================================
//デストラクタ
//============================================================================
CEffectMaxCharge::~CEffectMaxCharge(void)
{
	printf("EffectMaxCharge:Remove\n");
}

//============================================================================
//レンダリング
//============================================================================
void CEffectMaxCharge::Rendering()
{
	Renderer::IRender *pRender = CCommonObject::GetAppli()->GetRenderer();
	
	if( m_IsAdd )
	{
		pRender->SetDrawType( DRAW_TYPE_ADD );

	
		CSprite::Rendering();

		pRender->SetDrawType( DRAW_TYPE_NORMAL );

	}
	
	else if( m_IsBlend )
	{
		pRender->SetDrawType( DRAW_TYPE_BLEND );

	
		CSprite::Rendering();

		pRender->SetDrawType( DRAW_TYPE_NORMAL );	
	}

	else
	{
		CSprite::Rendering();
	}
	
	
	
}

//============================================================================
//処理
//============================================================================
void CEffectMaxCharge::Exec()
{
	sp<CGameObject> spObj = CCommonObject::GetResMgr()->FindObject( "Player" );	
	
	if( spObj != NULL )
	{
		m_vPos = spObj->GetPos() + m_vAdjPos;
	}
	
	m_Color.a = m_Alpha;

	CEffect::Exec();

}

//============================================================================
//パラメーターの読み込み
//============================================================================
void CEffectMaxCharge::LoadParameter( const char *pFileName )
{
	CFileLoader FileLoad( pFileName );

	vector< string > vecStr = CFileLoader::SplitString( FileLoad.GetStrList().at( 0 ), "," );

	//----------------------------------------------
	//位置の設定
	//----------------------------------------------
	SetParameter( m_vInitPos.x, vecStr.at( 0 ) );

	SetParameter( m_vInitPos.y, vecStr.at( 1 ) );

	//----------------------------------------------
	//角度の設定
	//----------------------------------------------
	SetParameter( m_InitAngle, vecStr.at( 2 ) );

	//----------------------------------------------
	//拡縮率の設定
	//----------------------------------------------
	SetParameter( m_fInitScale.x, vecStr.at( 3 ) );

	SetParameter( m_fInitScale.y, vecStr.at( 4 ) );

	//----------------------------------------------
	//分割数の設定
	//----------------------------------------------
	SetParameter( m_DivNum.x, vecStr.at( 5 ) );

	SetParameter( m_DivNum.y, vecStr.at( 6 ) );

	//----------------------------------------------
	//アニメーションの設定
	//----------------------------------------------
	SetParameter( m_IsAnim, vecStr.at( 7 ) );

	SetParameter( m_AnimTime, vecStr.at( 8 ) );

	//----------------------------------------------
	//ずらす座標の設定
	//----------------------------------------------
	SetParameter( m_vAdjPos.x, vecStr.at( 9 ) );

	SetParameter( m_vAdjPos.y, vecStr.at( 10 ) );

	//----------------------------------------------
	//加算の設定
	//----------------------------------------------
	SetParameter( m_IsAdd, vecStr.at(11) );
	
	SetParameter( m_IsBlend, vecStr.at(12) );	

	SetParameter( m_Alpha, vecStr.at( 13 ) );




}

//============================================================================
//アニメーションの設定
//============================================================================
void CEffectMaxCharge::SetAnimation()
{
	const int ANIM_NUM = 6;

	int Anim[ANIM_NUM] =
	{
	  2,
	  3,
	  3,
	  4,
	  5,
	  6,
	};

	/*アニメーションカウンタの増加*/
	if( ++m_AnimCount > Anim[m_Anim.x] )
	{
		m_AnimCount = 0;
		m_Anim.x += m_AnimSpeed;
	}

	if( m_Anim.x >= m_DivNum.x )
	{
		this->SetRemoveFlag(true);
	}


}






