//*============================================================================
//SceneTutorial.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "SceneTutorial.h"
#include "SceneTitle.h"
#include "CommonObject.h"
#include "ResourceManager.h"
#include "GameSceneManager.h"
#include "joypad.h"
#include "Common/Application.h"
#include "SceneGameMain.h"
#include "CSceneGameDemo.h"


//============================================================================
//コンストラクタ
//============================================================================
//[input]
//	pDataName:データファイル名
//============================================================================
CSceneTutorial::CSceneTutorial( const char *pDataName )
:CSceneBase( pDataName ),
 m_PushCount( 0 )
{
	//リソースファイルの読み込み
	LoadResourceFile( pDataName );
	

}

//============================================================================
//デストラクタ
//============================================================================
CSceneTutorial::~CSceneTutorial(void)
{

}

//============================================================================
//初期化
//============================================================================
void CSceneTutorial::Init()
{
#if 1
	//次のシーンに移動
	if( !CCommonObject::GetResMgr()->IsLoading() )
	{
		
		SetState( &CSceneBase::Idle );
	}
#endif


}

//============================================================================
//待機中
//============================================================================
void CSceneTutorial::Idle()
{
	::Peripheral::IInputController *pCtrl = CCommonObject::GetJoyPad()->GetController();
	
	Renderer::IRender *pRender = CCommonObject::GetAppli()->GetRenderer();
	
	//画面のクリア
	pRender->Clear( );
		
	//描画開始
	pRender->Begin();	
	
	//描画タイプの設定
	//pRender->SetDrawType( DRAW_TYPE_ADD );
	
	//描画タイプの設定
	pRender->SetDrawType( DRAW_TYPE_NORMAL );
	


	//全リソースのレンダリング
	CCommonObject::GetResMgr()->RenderingAll();
	
	#if defined( DEBUG ) | (_DEBUG)

		
	#endif

	//描画終了
	pRender->End();

	const int TUT_MAX = 2;//チュートリアルの枚数

	const char *pTemp[TUT_MAX] =
	{
		 "TutorialFront",
		 "TutorialBack",
	};
	

	//ボタンを押したら次のシーンに移動
	if( pCtrl->GetState( BUTTON_STATE_PUSH, BUTTON_03 ) || pCtrl->GetState( BUTTON_STATE_PUSH, BUTTON_01 ) )
	{	

		CCommonObject::GetResMgr()->FindObject(pTemp[m_PushCount])->SetVisibleFlag( false );


		m_PushCount++;

	}
	
	if( m_PushCount == TUT_MAX )
	{
		SetState( &CSceneBase::End );
	}


}

//============================================================================
//終了処理
//============================================================================
void CSceneTutorial::End()
{
	CCommonObject::GetGameSceneMgr()->SetNextScene( new CSceneGameDemo("settingdemo.csv") );
	
	SetState( &CSceneBase::Init );

}


