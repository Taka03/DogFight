//*============================================================================
//AimShoot.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "AimShoot.h"
#include "ResourceManager.h"

//=============================================================================
//variable
//=============================================================================
int CAimShoot::m_BulletNum = 0;

//============================================================================
//コンストラクタ
//============================================================================
//[input]
//	pName:ファイル名
//	pDataName:データファイル名
//	vPos:位置
//===========================================================================
CAimShoot::CAimShoot( const char *pName, const char *pDataName, Math::Vector2D vPos )
:CBullet( pName, pDataName, vPos ),
 m_TargetPos( 0, 0 )
{
	m_vInitPos = vPos;

	m_eType = CGameObject::TYPE_EBULLET;

	sp<CGameObject> spObj = CCommonObject::GetResMgr()->FindObject( "Player" );

	if( spObj != NULL )
	{
		m_TargetPos = spObj->GetPos();
	}

	else
	{
		m_TargetPos = Math::Vector2D( 0, 0 );
	}

	m_fSpeed = 5;

}


//============================================================================
//デストラクタ
//============================================================================
CAimShoot::~CAimShoot(void)
{
}

//============================================================================
//移動
//============================================================================
void CAimShoot::Move()
{
	Sint32 TargetAngle = Math::ATan2( m_TargetPos.x - m_vInitPos.x, m_TargetPos.y - m_vInitPos.y );

	m_vPos.x += Math::Cos( TargetAngle ) * m_fSpeed;
	m_vPos.y += Math::Sin( TargetAngle ) * m_fSpeed;


	Renderer::IRender *pRender = CCommonObject::GetAppli()->GetRenderer();
	
	#if defined( DEBUG ) | (_DEBUG)

		//pRender->DrawTextLayer( 1, Math::Point2DI( 0, 20 ), CColor( 255, 255, 255 ), "Angle:%d", TargetAngle );

	#endif


}

//============================================================================
//当たり判定処理
//============================================================================
//[input]
//	spObj:判定するオブジェクト
//============================================================================
void CAimShoot::HitExec( sp<CGameObject> spObj )
{

}
//============================================================================
//移動補正
//============================================================================
void CAimShoot::MoveAdjust()
{
	//画面外にいったら削除
	if( m_vPos.x < 0 )
	{
		this->SetRemoveFlag( true );
	}

	if( m_vPos.x > SCREEN_WIDTH )
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

}

