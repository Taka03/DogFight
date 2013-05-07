//*============================================================================
//EnemyCurve.h
//*============================================================================
/**
* �G(�J�[�u)�N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "enemy.h"

//=============================================================================
//class
//=============================================================================
class CEnemyCurve :	public CEnemy
{
	private:
	
		Sint32 m_RollAngle;///<@brief ��]�p�x
		bool m_IsShoot;///<@brief �V���b�g����t���O
		Uint32 m_ShotNum;///<@brief �V���b�g��
		Uint32 m_StreamCount;///<@brief �A���Ԋu
	
	public:
		
		/**
		* @brief �R���X�g���N�^
		* @param pName �t�@�C����
		* @param pDataName �f�[�^��
		* @param vPos �ݒ肷��ʒu
		*/
		CEnemyCurve( const char *pName, const char *pDataName, Math::Vector2D vPos );
		
		/**
		* @brief �f�X�g���N�^
		*/
		~CEnemyCurve(void);
		
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
