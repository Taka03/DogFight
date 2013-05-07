//*============================================================================
//EffectPhoton.h
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
class CEffectPhoton :	public CEffect
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
		CEffectPhoton( const char *pName, const char *pDataName, Math::Vector2D vPos );

		/**
		* @brief �f�X�g���N�^
		*/
		~CEffectPhoton(void);


		/**
		 * @brief �����_�����O
		 */
		void Rendering();

		/**
		* @brief ����
		*/
		void Exec();

		/**
		* @brief ��Ԗ��̏���
		*/
//		virtual void StateExec();


	//Set�n
	public:



	//Get�n
	public:


};
