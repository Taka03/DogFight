//*============================================================================
//SceneGameOver.h
//*============================================================================
/**
* �Q�[���I�[�o�[�N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "SceneBase.h"

//=============================================================================
//class
//=============================================================================
class CSceneGameOver :public CSceneBase
{
	private:

	
	
	public:
	
		/**
		* @brief �R���X�g���N�^
		* @param pDataName �f�[�^�t�@�C����
		*/
		CSceneGameOver( const char *pDataName );
		
		/**
		* @brief �f�X�g���N�^
		*/
		virtual ~CSceneGameOver(void);
		
		/**
		* @brief ������
		*/
		virtual void Init();
		
		/**
		* @brief �ҋ@��
		*/
		virtual void Idle();
		
		/**
		 * @brief ���O����
		 */
		//virtual void InputName();



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
