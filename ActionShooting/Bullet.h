//*============================================================================
//Character.h
//*============================================================================
/**
* �e�N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "character.h"

//=============================================================================
//class
//=============================================================================
class CBullet :	public CCharacter
{
	public:
	
		enum eBulletState
		{
			STATE_NONE,//�����Ȃ����
			STATE_DIED,//���S���
		};///<@brief �e�̏��
	
	private:
	
		static int m_BulletNum;///<@brief �e�̐�
		
	protected:
	
		eBulletState m_eState;///<@brief �e�̏��
		
	public:
		/**
		* @brief �R���X�g���N�^
		* @param pName �t�@�C����
		* @param pDataName �f�[�^��
		* @param vPos �ݒ肷��ʒu
		*/
		CBullet( const char *pName, const char *pDataName, Math::Vector2D vPos );
		
		/**
		* @brief �f�X�g���N�^
		*/
		virtual ~CBullet(void);
		
		/**
		* @brief �ړ�����
		*/
		void Move();
		
		/**
		 * ����
		 */
		//void Exec();

		/**
		* @brief �����������̏���
		* @param spObj ���肷��I�u�W�F�N�g
		*/
		virtual void HitExec( sp<CGameObject> spObj );
		
		/**
		* @brief ��ԏ���
		*/
		virtual void StateExec(){};
		
		/**
		* @brief �ړ��␳
		*/
		void MoveAdjust();
		
		/**
		* @brief ���݂̒e�̐��̎擾
		* @return ���݂̒e�̐�
		*/
		static int GetBulletNum()
		{
			return m_BulletNum;
		}
};
