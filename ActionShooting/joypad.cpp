//*============================================================================
//joypad.cpp
//*============================================================================

//============================================================================
//include
//============================================================================
#include "joypad.h"
#include <fstream>
#include <vector>

Peripheral::IInputController *CJoyPad::m_pController = NULL;

//============================================================================
//コンストラクタ
//============================================================================
CJoyPad::CJoyPad() :m_pJoystick(NULL)
{

}

//============================================================================
//デストラクタ
//============================================================================
CJoyPad::~CJoyPad()
{
	SAFE_RELEASE( m_pJoystick );
	SAFE_RELEASE( m_pController );
	
}

//============================================================================
//デバイスの作成
//============================================================================
//[input]
//	pCore:コアデバイス
//============================================================================
void CJoyPad::CreateDevice( ICore *pCore )
{
	if( pCore != NULL )
	{	
		m_pController = pCore->GetInputController( 0, 30, 5 );
		m_pJoystick = pCore->GetJoystick( 0 );
	}
	
	//初期化
	Initialize();
	
}

//============================================================================
//初期化
//============================================================================
void CJoyPad::Initialize( )
{
	if( m_pController != NULL )
	{
		//std::ifstream ifs("keydata.csv");
		//
		//const int MAX_BUTTON = 9;
		//
		//for( int i = 0;i < MAX_BUTTON;++i )
		//{
		//	int Key = 0;
		//	
		//	ifs >> Key;
		//	
		//	m_pController->SetButton( (eInputButtonType)(i+16), (ePadButtonType)(Key) );
		//}
		
		//---------------------------------------------
		//ボタンの設定
		//---------------------------------------------
		m_pController->SetButton( BUTTON_01, PAD_BUTTON_01 );
		m_pController->SetButton( BUTTON_02, PAD_BUTTON_02 );
		m_pController->SetButton( BUTTON_03, PAD_BUTTON_09 );
		m_pController->SetButton( BUTTON_04, PAD_BUTTON_03 );
		m_pController->SetButton( BUTTON_05, PAD_BUTTON_04 );
		
		//---------------------------------------------
		//軸の設定
		//---------------------------------------------
		m_pController->SetAxisX( AXIS_TYPE_01, PAD_AXIS_POSITION, PAD_AXIS_X );
		m_pController->SetAxisY( AXIS_TYPE_01, PAD_AXIS_POSITION, PAD_AXIS_Y );
		
		//---------------------------------------------
		//代替ボタンの設定
		//---------------------------------------------
		m_pController->SetAlias(BUTTON_01, SELENE_VK_Z);
		m_pController->SetAlias(BUTTON_02, SELENE_VK_X);
		m_pController->SetAlias(BUTTON_03, SELENE_VK_S);
		m_pController->SetAlias(BUTTON_04, SELENE_VK_V);
		m_pController->SetAlias(BUTTON_05, SELENE_VK_C);
		m_pController->SetAlias(BUTTON_06, SELENE_VK_A);
		
		
		m_pController->SetAlias(BUTTON_AXIS1_UP, SELENE_VK_UP);
		m_pController->SetAlias(BUTTON_AXIS1_DOWN, SELENE_VK_DOWN);
		m_pController->SetAlias(BUTTON_AXIS1_LEFT, SELENE_VK_LEFT);
		m_pController->SetAlias(BUTTON_AXIS1_RIGHT, SELENE_VK_RIGHT);
		
	}
	
}

//============================================================================
//パッドの更新
//============================================================================
void CJoyPad::Update()
{
	m_pController->Refresh();
}

//============================================================================
//参照カウンタの増加
//============================================================================
void CJoyPad::AddRef()
{
	m_pController->AddRef();
	m_pJoystick->AddRef();
}



