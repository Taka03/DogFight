//*============================================================================
//EffectSlash.h
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
class CEffectSlash :	public CEffect
{
	private:

		int m_ExistCount;///<@brief ���݃J�E���^�[
		CGameObject *m_pTargetObj;
		Math::Vector2D m_vEffPos;

	public:

		/**
		* @brief �R���X�g���N�^
		* @param pName �t�@�C����
		* @param pDataName �f�[�^��
		* @param vPos �ݒ肷��ʒu
		*/
		CEffectSlash( const char *pName, const char *pDataName, Math::Vector2D vPos );

		/**
		* @brief �R���X�g���N�^
		* @param pName �t�@�C����
		* @param pDataName �f�[�^��
		* @param vPos �ݒ肷��ʒu
		*/
		CEffectSlash( const char *pName, const char *pDataName, CGameObject *pObj );


		/**
		* @brief �f�X�g���N�^
		*/
		~CEffectSlash(void);

		/**
		* @brief ����
		*/
		void Exec();

		/**
		 * @brief �A�j���[�V�����̐ݒ�
		 */
		void SetAnimation();

		/**
		* @brief ��Ԗ��̏���
		*/
//		virtual void StateExec();


	//Set�n
	public:



	//Get�n
	public:


};
