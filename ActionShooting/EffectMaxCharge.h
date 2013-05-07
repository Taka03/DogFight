//*============================================================================
//EffectMaxCharge.h
//*============================================================================
/**
* �G�t�F�N�g(�ő�`���[�W)�N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "Effect.h"

//=============================================================================
//class
//=============================================================================
class CEffectMaxCharge :	public CEffect
{
	private:

		int m_ExistCount;///<@brief ���݃J�E���^�[
		Math::Vector2D m_vAdjPos;///<@brief
		bool m_IsAdd;///<@brief ���Z���邩
		bool m_IsBlend;
		Sint32 m_Alpha;///<@brief �A���t�@�l

	public:

		/**
		* @brief �R���X�g���N�^
		* @param pName �t�@�C����
		* @param pDataName �f�[�^��
		* @param vPos �ݒ肷��ʒu
		*/
		CEffectMaxCharge( const char *pName, const char *pDataName, Math::Vector2D vPos );

		/**
		* @brief �f�X�g���N�^
		*/
		~CEffectMaxCharge(void);


		/**
		 * @brief �����_�����O
		 */
		void Rendering();

		/**
		 * @brief �A�j���[�V�����̐ݒ�
		 */
		virtual void SetAnimation();

		/**
		 * @brief �p�����[�^�[�̓ǂݍ���
		 * @param pFileName �t�@�C����
		 */
		virtual void LoadParameter( const char *pFileName );



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
