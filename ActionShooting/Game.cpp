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
//�R���X�g���N�^
//=============================================================================
CGame::CGame() 
{
}

//=============================================================================
//�f�X�g���N�^
//=============================================================================
CGame::~CGame()
{
	
}

//=============================================================================
//�Q�[���J�n
//=============================================================================
void CGame::Run()
{
	//���������[�N���o
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	//�V�[���̍X�V
	CCommonObject::GetGameSceneMgr()->Update();
	
	//�p�b�h�̏��X�V
	CCommonObject::GetJoyPad()->Update();
	
	//���\�[�X�̍X�V
	CCommonObject::GetResMgr()->Update();
	

	
	
}

//=============================================================================
//���[�h��ʂ̕`��
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



