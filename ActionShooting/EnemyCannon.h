//*============================================================================
//EnemyCannon.h
//*============================================================================
/**
* �G(�C��)�N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "enemy.h"

//=============================================================================
//class
//=============================================================================
class CEnemyCannon :	public CEnemy
{
	private:
	
		//sp<CGameObject> m_spTargetObj;
		CGameObject *m_pTargetObj;
	
	public:
		
		/**
		* @brief �R���X�g���N�^
		* @param pName �t�@�C����
		* @param pDataName �f�[�^��
		* @param vPos �ݒ肷��ʒu
		*/
		CEnemyCannon( const char *pName, const char *pDataName, Math::Vector2D vPos );
		
		/**
		* @brief �R���X�g���N�^
		* @param pName �t�@�C����
		* @param pDataName �f�[�^��
		* @param vPos �ݒ肷��ʒu
		*/
		CEnemyCannon( const char *pName, const char *pDataName, CGameObject *pObj );
		
		
		/**
		* @brief �f�X�g���N�^
		*/
		~CEnemyCannon(void);
		
		/**
		* @brief �ړ�����
		*/
		void Move();
		
		void MoveAdjust(){};
		
		/**
		* @brief �V���b�g����
		*/
		//void Shoot();
		
		
};
