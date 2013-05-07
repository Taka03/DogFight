//*============================================================================
//SceneResult.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "SceneResult.h"
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
CSceneResult::CSceneResult( const char *pDataName )
:CSceneBase( pDataName )
{
	//リソースファイルの読み込み
	LoadResourceFile( pDataName );



}

//============================================================================
//デストラクタ
//============================================================================
CSceneResult::~CSceneResult(void)
{
	m_mapResource.clear();
}

//============================================================================
//初期化
//============================================================================
void CSceneResult::Init()
{
	//次のシーンに移動
	if( !CCommonObject::GetResMgr()->IsLoading() )
	{
//		CCommonObject::GetResMgr()->FindObject("TitleFont")->SetDrawString( "Push A Button" );

		//CCommonObject::GetResMgr()->FindObject("ResultFont")->SetDrawString("Game  Over");

//		CCommonObject::GetResMgr()->FindObject("R_ScoreFont")->SetDrawString( CSceneGameMain::GetStrScore() );

//		CCommonObject::GetResMgr()->FindObject("MaxHitFont")->SetDrawString( CSceneGameMain::GetStrMaxHit() );

		//ハイスコアを更新いかんによって、表示を変更
//		CCommonObject::GetResMgr()->FindObject("NewRecordFont")->SetVisibleFlag
//		( CSceneGameMain::GetUpdateScore() );
//
//		CCommonObject::GetGameSceneMgr()->SetDemoFlag( true );


		SetState( &CSceneBase::Idle );
	}

}

//============================================================================
//待機中
//============================================================================
void CSceneResult::Idle()
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


	multiset<int> setScore = CSceneGameMain::GetSetScore();

	multiset<int>::reverse_iterator rit = setScore.rbegin();

	int Temp = 0;

	while( rit != setScore.rend() )
	{


		//printf("%d\n", *rit );

		pRender->DrawTextLayer( 1,  Math::Point2DI( 0, 100 + Temp ), CColor( 0, 0, 0 ), "Rank:%d", *rit );

		Temp += 20;

		++rit;
	}



	//ボタンを押したら次のシーンに移動
	if( pCtrl->GetState( BUTTON_STATE_PUSH, BUTTON_01 ) )
	{

		SetState( &CSceneBase::End );

	}

}

//============================================================================
//終了処理
//============================================================================
void CSceneResult::End()
{
	CCommonObject::GetGameSceneMgr()->SetNextScene( new CSceneTitle("settingtitle.csv") );

	SetState( &CSceneBase::Init );

}


