//*============================================================================
//Missile.h
//*============================================================================
/**
* �U���e�N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "Bullet.h"

//=============================================================================
//class
//=============================================================================
class CMissile :	public CBullet
{
	private:
	
		static int m_BulletNum;///<@brief �e�̐�
		
		Math::Vector2D m_TargetPos;///<@brief �^�[�Q�b�g�̈ʒu
		
	public:
	
		/**
		* @brief �R���X�g���N�^
		* @param pName �t�@�C����
		* @param pDataName �f�[�^��
		* @param vPos �ݒ肷��ʒu
		*/
		CMissile( const char *pName, const char *pDataName, Math::Vector2D vPos );
		
		/**
		* @brief �f�X�g���N�^
		*/
		virtual ~CMissile(void);
		
		/**
		* @brief �ړ�����
		*/
		void Move();
		
		/**
		* @brief �����������̏���
		* @param spObj ���肷��I�u�W�F�N�g
		*/
		virtual void HitExec( sp<CGameObject> spObj );
		
		///**
		//* @brief �ړ��␳
		//*/
		//void MoveAdjust();
		
		/**
		* @brief ���݂̒e�̐��̎擾
		* @return ���݂̒e�̐�
		*/
		static int GetBulletNum()
		{
			return m_BulletNum;
		}
};
