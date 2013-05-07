//*============================================================================
//GameSceneManager.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "GameSceneManager.h"
#include "SceneGameMain.h"
#include "SceneTitle.h"
#include "SceneGameOver.h"

//=============================================================================
//コンストラクタ
//=============================================================================
CGameSceneManager::CGameSceneManager() : m_IsDemo( true ),
m_spCurScene( NULL ),
m_spNextScene( NULL )
{
	
	SetCurrentScene( new CSceneTitle("settingtitle_.csv") );
	m_spNextScene = m_spCurScene;
	
}

//=============================================================================
//デストラクタ
//=============================================================================
CGameSceneManager::~CGameSceneManager()
{
	m_spCurScene = NULL;
	m_spNextScene = NULL;
}

//=============================================================================
//更新
//=============================================================================
void CGameSceneManager::Update()
{
	m_spCurScene->Update();
	
	if( m_spCurScene.GetPtr() != m_spNextScene.GetPtr() )
	{
		m_spCurScene = m_spNextScene;
	}
	
}

//============================================================================
//現在のシーンの設定
//============================================================================
//[input]
//	pScene:シーン
//============================================================================
void CGameSceneManager::SetCurrentScene( CSceneBase *pScene )
{
	sp<CSceneBase> spScene( pScene );
	
	//現在のシーンの設定
	m_spCurScene = spScene;
}

//============================================================================
//次のシーンの設定
//============================================================================
//[input]
//	pScene:シーン
//============================================================================
void CGameSceneManager::SetNextScene( CSceneBase *pScene )
{
	sp<CSceneBase> spScene( pScene );
	
	//現在のシーンの設定
	m_spNextScene = spScene;
}

