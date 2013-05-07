//*============================================================================
//SceneTitle.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "SceneTitle.h"
#include "CommonObject.h"
#include "GameSceneManager.h"
#include "CSceneGameDemo.h"
#include "joypad.h"
#include "Common/Application.h"
#include "ResourceManager.h"
#include "SoundManager.h"
#include "SceneTutorial.h"
#include "FileLoader.h"

//============================================================================
//コンストラクタ
//============================================================================
//[input]
//	pDataName:データファイル名
//============================================================================
CSceneTitle::CSceneTitle( const char *pDataName )
:CSceneBase( pDataName ),
 pSpr( NULL )
{
	CCommonObject::GetResMgr()->SetDrawMap( m_mapResource );
	
	//TODO:ファイル読み込み。ひとつのファイルで、完結するようにする
	CFileLoader FileLoad( "test.csv" );

	int Size = FileLoad.GetStrList().size();

	for( int i = 0;i < Size;++i )
	{
		vector<string> vecStr = CFileLoader::SplitString( FileLoad.GetStrList().at(i), "," );

//		リソースマネージャに追加
		CCommonObject::GetResMgr()->Push( new CSprite( vecStr ) );


	}


	//pSpr = new CSprite( "enemy_small_1.png", "enemyroll.csv" );
	

	
	//リソースファイルの読み込み
	//LoadResourceFile( pDataName );

}

//============================================================================
//デストラクタ
//============================================================================
CSceneTitle::~CSceneTitle(void)
{
	SAFE_DELETE( pSpr );
}

//============================================================================
//オブジェクトの追加
//============================================================================
bool CSceneTitle::InitObject()
{
	//CCommonObject::GetResMgr()->Push( new CPlayer( "player.png", "player.csv" ) );

	//CCommonObject::GetResMgr()->Push( new CBackGraphic("shooting_stage1_1a.png", "stage1_1front.csv" ) );




	return true;
}

//============================================================================
//初期化
//============================================================================
void CSceneTitle::Init()
{
//	リソースの追加
	if( InitObject() )
	{
	
		//次のシーンに移動
		SetState( &CSceneBase::Idle );
	}
	
}

//============================================================================
//待機中
//============================================================================
void CSceneTitle::Idle()
{
	::Peripheral::IInputController *pCtrl = CCommonObject::GetJoyPad()->GetController();
	
	Renderer::IRender *pRender = CCommonObject::GetAppli()->GetRenderer();
	
	
	//画面のクリア
	pRender->Clear( );
		
	//描画開始
	pRender->Begin();	
	
	//CCommonObject::GetSoundMgr()->Play("Stage1BGM");
	
	
	//描画タイプの設定
	//pRender->SetDrawType( DRAW_TYPE_ADD );
	
	//描画タイプの設定
	//pRender->SetDrawType( DRAW_TYPE_BLEND );
	
	pRender->SetDrawType( DRAW_TYPE_NORMAL );	
	
	//全リソースのレンダリング
	CCommonObject::GetResMgr()->RenderingAll();
	
	
	
	
	//描画終了
	pRender->End();	
	


	//ヒット数の表示
	//DrawHitCount();
	
	//ボタンを押したら次のシーンに移動
	if( pCtrl->GetState( BUTTON_STATE_PUSH, BUTTON_03 ) )
	{
		CCommonObject::GetGameSceneMgr()->SetNextScene( new CSceneTutorial("settingtutorial.csv") );
		
		
		SetState( &CSceneBase::End );
		
		//CCommonObject::GetSoundMgr()->Play("PushStart");
		
	}
	
}

//============================================================================
//終了処理
//============================================================================
void CSceneTitle::End()
{
	//CCommonObject::GetGameSceneMgr()->AppendScene( "Game", new CSceneGameMain("setting.csv") );
	//
	//CCommonObject::GetGameSceneMgr()->SetCurrentScene( "Game" );
	
	
	SetState( &CSceneBase::Init );

}


