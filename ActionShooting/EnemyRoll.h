//*============================================================================
//EnemyRoll.h
//*============================================================================
/**
* �G(��]����)�N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "enemy.h"

//=============================================================================
//class
//=============================================================================
class CEnemyRoll :	public CEnemy
{
	private:
	
		Sint32 m_Scroll;///<@brief �X�N���[��
		Sint32 m_ScrollY;
	
	public:
		
		/**
		* @brief �R���X�g���N�^
		* @param pName �t�@�C����
		* @param pDataName �f�[�^��
		* @param vPos �ݒ肷��ʒu
		*/
		CEnemyRoll( const char *pName, const char *pDataName, Math::Vector2D vPos );
		
		/**
		* @brief �f�X�g���N�^
		*/
		~CEnemyRoll(void);
		
		/**
		* @brief �ړ�����
		*/
		void Move();
		
		/**
		* @brief �V���b�g����
		*/
		void Shoot();
		
		/**
		* @brief �ړ��␳
		*/
		void MoveAdjust();
		
	public:
	
		/**
		* @brief �L�����N�^�[��Ԃ̐ݒ�
		* @param eState �ݒ肷��L�����N�^�[���
		*/
		void SetState( eEnemyState eState )
		{
			m_eState = eState;
		}
	
};
