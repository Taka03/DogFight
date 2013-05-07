//*============================================================================
//SceneTutorial.h
//*============================================================================
/**
* �`���[�g���A���N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "SceneBase.h"

//=============================================================================
//class
//=============================================================================
class CSceneTutorial :public CSceneBase
{
	private:

			Sint32 m_PushCount;


	public:

		/**
		* @brief �R���X�g���N�^
		* @param pDataName �f�[�^�t�@�C����
		*/
		CSceneTutorial( const char *pDataName );

		/**
		* @brief �f�X�g���N�^
		*/
		virtual ~CSceneTutorial(void);

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
