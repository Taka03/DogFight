//*============================================================================
//CSceneGameDemo.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "CSceneGameDemo.h"
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
CSceneGameDemo::CSceneGameDemo( const char *pDataName )
:CSceneBase( pDataName ),
 m_SceneCounter( 0 ),
 m_SceneTime( 60 * 4 )

{
	//CCommonObject::GetResMgr()->SetDrawMap( m_mapResource );

	//���\�[�X�t�@�C���̓ǂݍ���
	//LoadResourceFile( pDataName );

}

//============================================================================
//�f�X�g���N�^
//============================================================================
CSceneGameDemo::~CSceneGameDemo(void)
{
	m_mapResource.clear();
}

//============================================================================
//������
//============================================================================
void CSceneGameDemo::Init()
{
	CCommonObject::GetGameSceneMgr()->SetDemoFlag( true );

	//���̃V�[���Ɉړ�
	if( !CCommonObject::GetResMgr()->IsLoading() )
	{

		SetState( &CSceneBase::Idle );
	}

}

//============================================================================
//�ҋ@��
//============================================================================
void CSceneGameDemo::Idle()
{
	::Peripheral::IInputController *pCtrl = CCommonObject::GetJoyPad()->GetController();

	Renderer::IRender *pRender = CCommonObject::GetAppli()->GetRenderer();

	//��ʂ̃N���A
	pRender->Clear( );

	//�`��J�n
	pRender->Begin();

	//�`��^�C�v�̐ݒ�
	pRender->SetDrawType( DRAW_TYPE_NORMAL );

	//�S���\�[�X�̃����_�����O
	//CCommonObject::GetResMgr()->RenderingAll();

	//�`��I��
	pRender->End();

	//if( ++m_SceneCounter >= m_SceneTime )
	//{
	////	��莞�Ԍo������A���̃V�[���Ɉړ�
	//	SetState( &CSceneBase::End );
	//}



}

//============================================================================
//�I������
//============================================================================
void CSceneGameDemo::End()
{
	CCommonObject::GetGameSceneMgr()->SetNextScene( new CSceneGameMain("setting.csv") );

	SetState( &CSceneBase::Init );

}


