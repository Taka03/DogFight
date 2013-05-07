//*============================================================================
//EffectShot.h
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
class CEffectShot :	public CEffect
{
	private:

		int m_ExistCount;///<@brief ���݃J�E���^�[
		int m_ShotCount;

	public:

		/**
		* @brief �R���X�g���N�^
		* @param pName �t�@�C����
		* @param pDataName �f�[�^��
		* @param vPos �ݒ肷��ʒu
		*/
		CEffectShot( const char *pName, const char *pDataName, Math::Vector2D vPos );

		/**
		* @brief �f�X�g���N�^
		*/
		~CEffectShot(void);

		/**
		* @brief ����
		*/
		void Exec();

		/**
		 *
		 */
		virtual void SetAnimation();

		/**
		* @brief ��Ԗ��̏���
		*/
//		virtual void StateExec();


	//Set�n
	public:



	//Get�n
	public:


};
