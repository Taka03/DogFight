//*============================================================================
//ScreenController.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "ScreenController.h"

namespace
{
	Math::Rect2DF ScreenRect( 0.0f, 0.0f, toF( SCREEN_WIDTH ), toF( SCREEN_HEIGHT ) );
}

//=============================================================================
//�R���X�g���N�^
//=============================================================================
CScreenController::CScreenController( Renderer::IRender *pRender )
	: m_pRender		( pRender ),
	  m_eScreenState( STATE_STANDBY ),
	  m_Color		( 0, 0, 0, 0 ),
	  m_Time		( 0 ),
	  m_TimeLast	( 0 )
{
	m_pRender->AddRef();
}

//=============================================================================
//�f�X�g���N�^
//=============================================================================
CScreenController::~CScreenController()
{
	SAFE_RELEASE( m_pRender );
}

//=============================================================================
//����
//=============================================================================
void CScreenController::Exec()
{
	switch( m_eScreenState )
	{
		case STATE_STANDBY:
		{
			break;
		}
		
		/*�t�F�[�h�C��*/
		case STATE_FADEIN:
		{
			FadeIn();
			break;
		}
		
		/*�t�F�[�h�A�E�g*/
		case STATE_FADEOUT:
		{
			FadeOut();
			break;
		}
	}
}

//=============================================================================
//�t�F�[�h�C��
//=============================================================================
void CScreenController::FadeIn()
{
	m_Color.a = (Uint8)( ::Interpolation::Flat( 255L, 0L, m_TimeLast, m_Time ) );
	
	m_pRender->SetDrawType( DRAW_TYPE_BLEND );
	
	/*��ʑS�̂𕢂�*/
	m_pRender->FillRect( ScreenRect, m_Color );
	
	// �^�C�}�[�{
	if ( ++m_Time > m_TimeLast )
	{
		m_eScreenState = STATE_STANDBY;
	}
	
}

//=============================================================================
//�t�F�[�h�A�E�g
//=============================================================================
void CScreenController::FadeOut()
{
	m_Color.a = (Uint8)( ::Interpolation::Flat( 0L, 255L, m_TimeLast, m_Time ) );
	
	m_pRender->SetDrawType( DRAW_TYPE_BLEND );
	
	/*��ʑS�̂𕢂�*/
	m_pRender->FillRect( ScreenRect, m_Color );
	
	// �^�C�}�[�{
	if ( ++m_Time > m_TimeLast )
	{
		m_eScreenState = STATE_STANDBY;
	}
}

//=============================================================================
//�t�F�[�h�C���̐ݒ�
//=============================================================================
//[input]
//	Time:�t�F�[�h�C������
//	Color:�`�悷��F
//=============================================================================
void CScreenController::SetFadeIn( Sint32 Time, CColor Color )
{
	m_eScreenState = STATE_FADEIN;
	m_Color = Color;
	m_TimeLast = Time;
	m_Time = 0;
}

//=============================================================================
//�t�F�[�h�A�E�g�̐ݒ�
//=============================================================================
//[input]
//	Time:�t�F�[�h�A�E�g����
//	Color:�`�悷��F
//=============================================================================
void CScreenController::SetFadeOut( Sint32 Time, CColor Color )
{
	m_eScreenState = STATE_FADEOUT;
	m_TimeLast = Time;
	m_Time = 0;
}

//=============================================================================
//�t�F�[�h�����ǂ���
//=============================================================================
Bool CScreenController::IsFade()
{
	return m_eScreenState != STATE_STANDBY;
}









