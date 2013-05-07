//*============================================================================
//EffectFlash.h
//*============================================================================
/**
* �G�t�F�N�g(�_��)�N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "Effect.h"

//=============================================================================
//class
//=============================================================================
class CEffectFlash :	public CEffect
{
	private:
	
		int m_ExistCount;///<@brief ���݃J�E���^�[
		
	public:
		
		/**
		* @brief �R���X�g���N�^
		* @param pName �t�@�C����
		* @param pDataName �f�[�^��
		* @param vPos �ݒ肷��ʒu
		*/
		CEffectFlash( const char *pName, const char *pDataName, Math::Vector2D vPos );
		
		/**
		* @brief �f�X�g���N�^
		*/
		~CEffectFlash(void);
		
		/**
		* @brief ����
		*/
		void Exec();
		
		/**
		* @brief �����������̏���
		* @param spObj ���肷��L����
		*/
		virtual void HitExec( sp<CGameObject> spObj );
		
		/**
		* @brief ��Ԗ��̏���
		*/
//		virtual void StateExec();
		
	
	//Set�n
	public:
		
		
		
	//Get�n
	public:
	
		
};
