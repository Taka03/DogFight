//*============================================================================
//ScreenController.h
//*============================================================================
//[history]
//	08/11/23�@�쐬
//[author]
//	Taka
//============================================================================
#pragma once

//=============================================================================
//include
//=============================================================================
#include "common.h"

//=============================================================================
//class
//=============================================================================
//[desc]
//	�X�N���[������p�N���X
//=============================================================================
class CScreenController
{
	public:
		
		
		enum eScreenState
		{
			STATE_STANDBY,
			STATE_FADEIN,
			STATE_FADEOUT,
		};
		
	private:
	
		Renderer::IRender *m_pRender;//�����_�[�p�f�o�C�X
		CColor			  m_Color;//�F
		eScreenState	  m_eScreenState;//�X�N���[���̏��
		Sint32			  m_Time;//�^�C���J�E���^�[
		Sint32			  m_TimeLast;//�ő�^�C��
		
	private:
	
		void FadeIn();//�t�F�[�h�C��
		void FadeOut();//�t�F�[�h�A�E�g

		
	public:
	
		CScreenController(){};//�R���X�g���N�^
		CScreenController( Renderer::IRender *pRender );//�R���X�g���N�^
		virtual ~CScreenController();//�f�X�g���N�^
		
		virtual void Exec();//����
		
		virtual void SetFadeIn( Sint32 Time, CColor Color );//�t�F�[�h�C���̐ݒ�
		virtual void SetFadeOut( Sint32 Time, CColor Color );//�t�F�[�h�A�E�g�̐ݒ�
		virtual Bool IsFade( void );//�t�F�[�h�����ǂ���
		
	public:
	
		
		
	
	
};


