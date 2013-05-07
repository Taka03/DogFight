//*============================================================================
//Character.h
//*============================================================================
/**
* �L�����N�^�[�N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "sprite.h"

//=============================================================================
//class
//=============================================================================
class CCharacter :	public CSprite
{
	protected:
	
		float m_fSpeed;///<@brief �ړ��X�s�[�h
		
	private:
	
		/**
		* @brief �ړ��␳
		*/
		virtual void MoveAdjust();
	
		
	public:
		
		/**
		* @brief �R���X�g���N�^
		* @param pName �t�@�C����
		* @param pDataName �f�[�^��
		*/
		CCharacter( const char *pName, const char *pDataName );
		
		/**
		* @brief �f�X�g���N�^
		*/
		virtual ~CCharacter(void);
		
		/**
		* @brief �ړ�����
		*/
		virtual void Move(){};
		
		/**
		* @brief ����
		*/
		void Exec();
		
		/**
		* @brief �p�����[�^�[�̓ǂݍ���
		* @param pFileName �t�@�C����
		*/
		void LoadParameter( const char *pFileName ){};
		
		/**
		* @brief �A�j���[�V�����̐ݒ�
		*/
		virtual void SetAnimation();
		
		/**
		* @brief �����������̏���
		* @param spObj ���肷��I�u�W�F�N�g
		*/
		virtual void HitExec( sp<CGameObject> spObj ){};
		
		/**
		* @brief ��Ԗ��̏���
		*/
		virtual void StateExec();
		
		
	//Set�n
	public:
	
		/**
		* @brief �L�����N�^�[��Ԃ̐ݒ�
		* @param eState �ݒ肷��L�����N�^�[���
		*/
		//void SetState( eCharaState eState )
		//{
		//	m_eState = eState;
		//}
	
	//Get�n
	public:
	
		
		
		///**
		//* @brief �L�����N�^�[��Ԃ̎擾
		//* @return �L�����N�^�[���
		//*/
		//eCharaState GetState() const
		//{
		//	return m_eState;
		//}
		
};
