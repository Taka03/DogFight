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
//�R���X�g���N�^
//============================================================================
//[input]
//	pDataName:�f�[�^�t�@�C����
//============================================================================
CSceneResult::CSceneResult( const char *pDataName )
:CSceneBase( pDataName )
{
	//���\�[�X�t�@�C���̓ǂݍ���
	LoadResourceFile( pDataName );



}

//============================================================================
//�f�X�g���N�^
//============================================================================
CSceneResult::~CSceneResult(void)
{
	m_mapResource.clear();
}

//============================================================================
//������
//============================================================================
void CSceneResult::Init()
{
	//���̃V�[���Ɉړ�
	if( !CCommonObject::GetResMgr()->IsLoading() )
	{
//		CCommonObject::GetResMgr()->FindObject("TitleFont")->SetDrawString( "Push A Button" );

		//CCommonObject::GetResMgr()->FindObject("ResultFont")->SetDrawString("Game  Over");

//		CCommonObject::GetResMgr()->FindObject("R_ScoreFont")->SetDrawString( CSceneGameMain::GetStrScore() );

//		CCommonObject::GetResMgr()->FindObject("MaxHitFont")->SetDrawString( CSceneGameMain::GetStrMaxHit() );

		//�n�C�X�R�A���X�V������ɂ���āA�\����ύX
//		CCommonObject::GetResMgr()->FindObject("NewRecordFont")->SetVisibleFlag
//		( CSceneGameMain::GetUpdateScore() );
//
//		CCommonObject::GetGameSceneMgr()->SetDemoFlag( true );


		SetState( &CSceneBase::Idle );
	}

}

//============================================================================
//�ҋ@��
//============================================================================
void CSceneResult::Idle()
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



	//�{�^�����������玟�̃V�[���Ɉړ�
	if( pCtrl->GetState( BUTTON_STATE_PUSH, BUTTON_01 ) )
	{

		SetState( &CSceneBase::End );

	}

}

//============================================================================
//�I������
//============================================================================
void CSceneResult::End()
{
	CCommonObject::GetGameSceneMgr()->SetNextScene( new CSceneTitle("settingtitle.csv") );

	SetState( &CSceneBase::Init );

}


