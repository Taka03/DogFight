//*============================================================================
//EnemyMiddle1.h
//*============================================================================
/**
* �G(���^�@1)�N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "enemy.h"

//=============================================================================
//class
//=============================================================================
class CEnemyMiddle1 :	public CEnemy
{
	private:
	
		static Uint32 m_ExistNum;///<@brief �o���G��
		
		Uint32 m_ID;///<@brief ���ʔԍ�
		
		//CEnemyCannon
		
	public:
		
		/**
		* @brief �R���X�g���N�^
		* @param pName �t�@�C����
		* @param pDataName �f�[�^��
		* @param vPos �ݒ肷��ʒu
		*/
		CEnemyMiddle1( const char *pName, const char *pDataName, Math::Vector2D vPos );
		
		/**
		* @brief �f�X�g���N�^
		*/
		~CEnemyMiddle1(void);
		
		/**
		* @brief �ړ��␳
		*/
		void MoveAdjust();
		
		/**
		* @brief ��ԏ���
		*/
		//void StateExec();
		
		
	public:
	
		/**
		* @brief �o���G���̎擾
		* @return �o���G��
		*/
		static int GetExistNum()
		{
			return m_ExistNum;
		}
		
		
};
