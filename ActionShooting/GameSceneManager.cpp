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
//�R���X�g���N�^
//=============================================================================
CGameSceneManager::CGameSceneManager() : m_IsDemo( true ),
m_spCurScene( NULL ),
m_spNextScene( NULL )
{
	
	SetCurrentScene( new CSceneTitle("settingtitle_.csv") );
	m_spNextScene = m_spCurScene;
	
}

//=============================================================================
//�f�X�g���N�^
//=============================================================================
CGameSceneManager::~CGameSceneManager()
{
	m_spCurScene = NULL;
	m_spNextScene = NULL;
}

//=============================================================================
//�X�V
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
//���݂̃V�[���̐ݒ�
//============================================================================
//[input]
//	pScene:�V�[��
//============================================================================
void CGameSceneManager::SetCurrentScene( CSceneBase *pScene )
{
	sp<CSceneBase> spScene( pScene );
	
	//���݂̃V�[���̐ݒ�
	m_spCurScene = spScene;
}

//============================================================================
//���̃V�[���̐ݒ�
//============================================================================
//[input]
//	pScene:�V�[��
//============================================================================
void CGameSceneManager::SetNextScene( CSceneBase *pScene )
{
	sp<CSceneBase> spScene( pScene );
	
	//���݂̃V�[���̐ݒ�
	m_spNextScene = spScene;
}

