//*============================================================================
//EffectSword.h
//*============================================================================
/**
* �G�t�F�N�g(��)�N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "Effect.h"

//=============================================================================
//class
//=============================================================================
class CEffectSword :	public CEffect
{
	private:
	
		int m_ExistCount;
		
		static Uint32 m_HitCount;///<@brief �q�b�g��
	
	public:
		
		/**
		* @brief �R���X�g���N�^
		* @param pName �t�@�C����
		* @param pDataName �f�[�^��
		* @param vPos �ݒ肷��ʒu
		*/
		CEffectSword( const char *pName, const char *pDataName, Math::Vector2D vPos );
		
		/**
		* @brief �f�X�g���N�^
		*/
		~CEffectSword(void);
		
		/**
		* @brief ����
		*/
		void Exec();
		
		/**
		* @brief �����������̏���
		* @param spObj ���肷��I�u�W�F�N�g
		*/
		virtual void HitExec( sp<CGameObject> spObj );
		
		/**
		* @brief ��Ԗ��̏���
		*/
//		virtual void StateExec();
		
	
	//Set�n
	public:
		
		/**
		* @brief �q�b�g�J�E���g�̐ݒ�
		* @param count �ݒ肷��q�b�g�J�E���g
		*/
		static void SetHitCount( const Uint32 count )
		{
			m_HitCount = count;
		}
		
		/**
		* @brief �q�b�g�J�E���g�̑���
		*/
		static void AddHitCount( )
		{
			++m_HitCount;
		}
		
	//Get�n
	public:
	
		
};
