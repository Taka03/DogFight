//*============================================================================
//CSceneGameDemo.h
//*============================================================================
/**
* �Q�[���f���N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "SceneBase.h"

//=============================================================================
//class
//=============================================================================
class CSceneGameDemo :public CSceneBase
{
	private:

		int m_SceneCounter;///<@brief �V�[���J�E���^�[
		int m_SceneTime;///<@brief �V�[���ڍs����

	public:

		/**
		* @brief �R���X�g���N�^
		* @param pDataName �f�[�^�t�@�C����
		*/
		CSceneGameDemo( const char *pDataName );

		/**
		* @brief �f�X�g���N�^
		*/
		virtual ~CSceneGameDemo(void);

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
