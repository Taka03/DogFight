//*============================================================================
//EffectBomb.h
//*============================================================================
/**
* �G�t�F�N�g(����)�N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "Effect.h"

//=============================================================================
//class
//=============================================================================
class CEffectBomb :	public CEffect
{
	private:
	
		int m_ExistCount;///<@brief ���݃J�E���^�[
		CGameObject *m_pEnemyObj;///@brief �G�I�u�W�F�N�g(�����p)
		
	public:
		
		static Uint32 m_Cnt;

	
	public:
		
		/**
		* @brief �R���X�g���N�^
		* @param pName �t�@�C����
		* @param pDataName �f�[�^��
		* @param vPos �ݒ肷��ʒu
		*/
		CEffectBomb( const char *pName, const char *pDataName, Math::Vector2D vPos );
		
		/**
		* @brief �R���X�g���N�^
		* @param pName �t�@�C����
		* @param pDataName �f�[�^��
		* @param vPos �ݒ肷��ʒu
		*/
		CEffectBomb( const char *pName, const char *pDataName, CGameObject *pObj );
		
		
		/**
		* @brief �f�X�g���N�^
		*/
		~CEffectBomb(void);
		
		/**
		* @brief ����
		*/
		void Exec();
		
		/**
		* @brief �����������̏���
		* @param spObj ���肷��L����
		*/
		virtual void HitExec( sp<CGameObject> spObj);
		
		/**
		* @brief ��Ԗ��̏���
		*/
//		virtual void StateExec();
		
	
	//Set�n
	public:
		
		
		
	//Get�n
	public:
	
		
};
