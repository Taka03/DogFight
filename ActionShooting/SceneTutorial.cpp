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
//�R���X�g���N�^
//============================================================================
//[input]
//	pDataName:�f�[�^�t�@�C����
//============================================================================
CSceneTutorial::CSceneTutorial( const char *pDataName )
:CSceneBase( pDataName ),
 m_PushCount( 0 )
{
	//���\�[�X�t�@�C���̓ǂݍ���
	LoadResourceFile( pDataName );
	

}

//============================================================================
//�f�X�g���N�^
//============================================================================
CSceneTutorial::~CSceneTutorial(void)
{

}

//============================================================================
//������
//============================================================================
void CSceneTutorial::Init()
{
#if 1
	//���̃V�[���Ɉړ�
	if( !CCommonObject::GetResMgr()->IsLoading() )
	{
		
		SetState( &CSceneBase::Idle );
	}
#endif


}

//============================================================================
//�ҋ@��
//============================================================================
void CSceneTutorial::Idle()
{
	::Peripheral::IInputController *pCtrl = CCommonObject::GetJoyPad()->GetController();
	
	Renderer::IRender *pRender = CCommonObject::GetAppli()->GetRenderer();
	
	//��ʂ̃N���A
	pRender->Clear( );
		
	//�`��J�n
	pRender->Begin();	
	
	//�`��^�C�v�̐ݒ�
	//pRender->SetDrawType( DRAW_TYPE_ADD );
	
	//�`��^�C�v�̐ݒ�
	pRender->SetDrawType( DRAW_TYPE_NORMAL );
	


	//�S���\�[�X�̃����_�����O
	CCommonObject::GetResMgr()->RenderingAll();
	
	#if defined( DEBUG ) | (_DEBUG)

		
	#endif

	//�`��I��
	pRender->End();

	const int TUT_MAX = 2;//�`���[�g���A���̖���

	const char *pTemp[TUT_MAX] =
	{
		 "TutorialFront",
		 "TutorialBack",
	};
	

	//�{�^�����������玟�̃V�[���Ɉړ�
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
//�I������
//============================================================================
void CSceneTutorial::End()
{
	CCommonObject::GetGameSceneMgr()->SetNextScene( new CSceneGameDemo("settingdemo.csv") );
	
	SetState( &CSceneBase::Init );

}


