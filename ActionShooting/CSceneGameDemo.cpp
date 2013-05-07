//*============================================================================
//CSceneGameDemo.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "CSceneGameDemo.h"
#include "SceneTitle.h"
#include "CommonObject.h"
#include "ResourceManager.h"
#include "GameSceneManager.h"
#include "joypad.h"
#include "Common/Application.h"
#include "SceneGameMain.h"



//============================================================================
//コンストラクタ
//============================================================================
//[input]
//	pDataName:データファイル名
//============================================================================
CSceneGameDemo::CSceneGameDemo( const char *pDataName )
:CSceneBase( pDataName ),
 m_SceneCounter( 0 ),
 m_SceneTime( 60 * 4 )

{
	//CCommonObject::GetResMgr()->SetDrawMap( m_mapResource );

	//リソースファイルの読み込み
	//LoadResourceFile( pDataName );

}

//============================================================================
//デストラクタ
//============================================================================
CSceneGameDemo::~CSceneGameDemo(void)
{
	m_mapResource.clear();
}

//============================================================================
//初期化
//============================================================================
void CSceneGameDemo::Init()
{
	CCommonObject::GetGameSceneMgr()->SetDemoFlag( true );

	//次のシーンに移動
	if( !CCommonObject::GetResMgr()->IsLoading() )
	{

		SetState( &CSceneBase::Idle );
	}

}

//============================================================================
//待機中
//============================================================================
void CSceneGameDemo::Idle()
{
	::Peripheral::IInputController *pCtrl = CCommonObject::GetJoyPad()->GetController();

	Renderer::IRender *pRender = CCommonObject::GetAppli()->GetRenderer();

	//画面のクリア
	pRender->Clear( );

	//描画開始
	pRender->Begin();

	//描画タイプの設定
	pRender->SetDrawType( DRAW_TYPE_NORMAL );

	//全リソースのレンダリング
	//CCommonObject::GetResMgr()->RenderingAll();

	//描画終了
	pRender->End();

	//if( ++m_SceneCounter >= m_SceneTime )
	//{
	////	一定時間経ったら、次のシーンに移動
	//	SetState( &CSceneBase::End );
	//}



}

//============================================================================
//終了処理
//============================================================================
void CSceneGameDemo::End()
{
	CCommonObject::GetGameSceneMgr()->SetNextScene( new CSceneGameMain("setting.csv") );

	SetState( &CSceneBase::Init );

}


