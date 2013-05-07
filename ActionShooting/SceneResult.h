//*============================================================================
//SceneResult.h
//*============================================================================
/**
* ���U���g�N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "SceneBase.h"

//=============================================================================
//class
//=============================================================================
class CSceneResult :public CSceneBase
{
	private:


	public:

		/**
		* @brief �R���X�g���N�^
		* @param pDataName �f�[�^�t�@�C����
		*/
		CSceneResult( const char *pDataName );

		/**
		* @brief �f�X�g���N�^
		*/
		virtual ~CSceneResult(void);

		/**
		* @brief ������
		*/
		virtual void Init();

		/**
		* @brief �ҋ@��
		*/
		virtual void Idle();


		///**
		//* @brief �X�V
		//* @return ���݂̃V�[���̏��
		//*/
		//virtual eSceneState Update();
		//
		/**
		* @brief �I��
		*/
		virtual void End();


};
