//*============================================================================
//Game.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "Game.h"
#include "Common/Application.h"
#include <fstream>
#include "Sprite.h"
#include "FontSprite.h"
#include "FileData.h"
#include "ResourceManager.h"
#include "GameSceneManager.h"
#include "joypad.h"


//=============================================================================
//コンストラクタ
//=============================================================================
CGame::CGame() 
{
}

//=============================================================================
//デストラクタ
//=============================================================================
CGame::~CGame()
{
	
}

//=============================================================================
//ゲーム開始
//=============================================================================
void CGame::Run()
{
	//メモリリーク検出
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	//シーンの更新
	CCommonObject::GetGameSceneMgr()->Update();
	
	//パッドの情報更新
	CCommonObject::GetJoyPad()->Update();
	
	//リソースの更新
	CCommonObject::GetResMgr()->Update();
	

	
	
}

//=============================================================================
//ロード画面の描画
//=============================================================================
void CGame::DrawNowLoading()
{
	Renderer::IRender *pRender = CCommonObject::GetAppli()->GetRenderer();	
	ICore *pCore = CCommonObject::GetAppli()->GetCore();
	
	const char *pLoadStr[] =
	{
		"NowLoading",
		"NowLoading.",
		"NowLoading..",
		"NowLoading...",
		
	};
	
	static int count = 0;
	
	if( pCore->GetSyncCount() % 60 == 0 )
	{
		count++;
		
		if( count > 3 )
		{
			count = 0;
		}
	}
	
	pRender->DrawTextLayer( 1, Math::Point2DI( 500, SCREEN_HEIGHT - 50 ), 
													  CColor( 255, 255, 255 ), pLoadStr[count] );
	
	
}



