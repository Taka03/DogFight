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
//�R���X�g���N�^
//============================================================================
//[input]
//	pDataName:�f�[�^�t�@�C����
//============================================================================
CSceneTitle::CSceneTitle( const char *pDataName )
:CSceneBase( pDataName ),
 pSpr( NULL )
{
	CCommonObject::GetResMgr()->SetDrawMap( m_mapResource );
	
	//TODO:�t�@�C���ǂݍ��݁B�ЂƂ̃t�@�C���ŁA��������悤�ɂ���
	CFileLoader FileLoad( "test.csv" );

	int Size = FileLoad.GetStrList().size();

	for( int i = 0;i < Size;++i )
	{
		vector<string> vecStr = CFileLoader::SplitString( FileLoad.GetStrList().at(i), "," );

//		���\�[�X�}�l�[�W���ɒǉ�
		CCommonObject::GetResMgr()->Push( new CSprite( vecStr ) );


	}


	//pSpr = new CSprite( "enemy_small_1.png", "enemyroll.csv" );
	

	
	//���\�[�X�t�@�C���̓ǂݍ���
	//LoadResourceFile( pDataName );

}

//============================================================================
//�f�X�g���N�^
//============================================================================
CSceneTitle::~CSceneTitle(void)
{
	SAFE_DELETE( pSpr );
}

//============================================================================
//�I�u�W�F�N�g�̒ǉ�
//============================================================================
bool CSceneTitle::InitObject()
{
	//CCommonObject::GetResMgr()->Push( new CPlayer( "player.png", "player.csv" ) );

	//CCommonObject::GetResMgr()->Push( new CBackGraphic("shooting_stage1_1a.png", "stage1_1front.csv" ) );




	return true;
}

//============================================================================
//������
//============================================================================
void CSceneTitle::Init()
{
//	���\�[�X�̒ǉ�
	if( InitObject() )
	{
	
		//���̃V�[���Ɉړ�
		SetState( &CSceneBase::Idle );
	}
	
}

//============================================================================
//�ҋ@��
//============================================================================
void CSceneTitle::Idle()
{
	::Peripheral::IInputController *pCtrl = CCommonObject::GetJoyPad()->GetController();
	
	Renderer::IRender *pRender = CCommonObject::GetAppli()->GetRenderer();
	
	
	//��ʂ̃N���A
	pRender->Clear( );
		
	//�`��J�n
	pRender->Begin();	
	
	//CCommonObject::GetSoundMgr()->Play("Stage1BGM");
	
	
	//�`��^�C�v�̐ݒ�
	//pRender->SetDrawType( DRAW_TYPE_ADD );
	
	//�`��^�C�v�̐ݒ�
	//pRender->SetDrawType( DRAW_TYPE_BLEND );
	
	pRender->SetDrawType( DRAW_TYPE_NORMAL );	
	
	//�S���\�[�X�̃����_�����O
	CCommonObject::GetResMgr()->RenderingAll();
	
	
	
	
	//�`��I��
	pRender->End();	
	


	//�q�b�g���̕\��
	//DrawHitCount();
	
	//�{�^�����������玟�̃V�[���Ɉړ�
	if( pCtrl->GetState( BUTTON_STATE_PUSH, BUTTON_03 ) )
	{
		CCommonObject::GetGameSceneMgr()->SetNextScene( new CSceneTutorial("settingtutorial.csv") );
		
		
		SetState( &CSceneBase::End );
		
		//CCommonObject::GetSoundMgr()->Play("PushStart");
		
	}
	
}

//============================================================================
//�I������
//============================================================================
void CSceneTitle::End()
{
	//CCommonObject::GetGameSceneMgr()->AppendScene( "Game", new CSceneGameMain("setting.csv") );
	//
	//CCommonObject::GetGameSceneMgr()->SetCurrentScene( "Game" );
	
	
	SetState( &CSceneBase::Init );

}


