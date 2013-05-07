//*============================================================================
//EffectTrBomb.h
//*============================================================================
/**
* �G�t�F�N�g(�U��)�N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "EffectBomb.h"

//=============================================================================
//class
//=============================================================================
class CEffectTrBomb :	public CEffectBomb
{
	private:

	public:

		/**
		* @brief �R���X�g���N�^
		* @param pName �t�@�C����
		* @param pDataName �f�[�^��
		* @param vPos �ݒ肷��ʒu
		*/
		CEffectTrBomb( const char *pName, const char *pDataName, Math::Vector2D vPos );

		/**
		* @brief �R���X�g���N�^
		* @param pName �t�@�C����
		* @param pDataName �f�[�^��
		* @param vPos �ݒ肷��ʒu
		*/
		CEffectTrBomb( const char *pName, const char *pDataName, CGameObject *pObj );


		/**
		* @brief �f�X�g���N�^
		*/
		~CEffectTrBomb(void);


		/**
		* @brief ��Ԗ��̏���
		*/
//		virtual void StateExec();


	//Set�n
	public:



	//Get�n
	public:


};
