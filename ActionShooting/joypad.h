//*============================================================================
//joypad.h
//*============================================================================
/**
* �W���C�p�b�h�N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "common.h"

//=============================================================================
//class
//=============================================================================
//[desc]
//	�W���C�p�b�h�p�N���X
//=============================================================================
class CJoyPad 
{
	public:
	
	private:
	
		static Peripheral::IInputController *m_pController;//�R���g���[���[�p�f�o�C�X
		Peripheral::IJoystick		 *m_pJoystick;//�W���C�X�e�B�b�N�p�f�o�C�X
		
	public:
	
		/**
		* @brief �R���X�g���N�^
		*/
		CJoyPad();
		
		/**
		* @brief �f�X�g���N�^
		*/
		virtual ~CJoyPad();
		
	public:
	
		/**
		* @brief �f�o�C�X�̍쐬
		* @param pCore �R�A�f�o�C�X
		*/
		void CreateDevice( ICore *pCore );
		
		/**
		* @brief ������
		*/
		void Initialize();	
		
		/**
		* @brief �X�V
		*/
		void Update();
		
		/**
		* @brief �Q�ƃJ�E���^����
		*/
		void AddRef();
		
	/*Get�n*/
	public:
	
		/**
		* @brief �R���g���[���[�p�f�o�C�X�̎擾
		* @return �R���g���[���[�p�f�o�C�X
		*/		
		Peripheral::IInputController *GetController() const
		{
			return m_pController;
		}
		
		/**
		* @brief �W���C�X�e�B�b�N�p�f�o�C�X�̎擾
		* @return �W���C�X�e�B�b�N�p�f�o�C�X
		*/		
		Peripheral::IJoystick *GetJoyStick() const
		{
			return m_pJoystick;
		}

};
