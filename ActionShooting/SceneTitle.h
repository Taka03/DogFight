//*============================================================================
//SceneTitle.h
//*============================================================================
/**
* �^�C�g���N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "SceneBase.h"
#include "Sprite.h"

//=============================================================================
//class
//=============================================================================
class CSceneTitle :public CSceneBase
{
	private:

		CSprite *pSpr;

	protected:

		/**
		 * �I�u�W�F�N�g�̒ǉ�
		 * @return �I�u�W�F�N�g�̒ǉ����I��������
		 */
		virtual bool InitObject();

		/**
		* @brief ������
		*/
		virtual void Init();

		/**
		* @brief �ҋ@��
		*/
		virtual void Idle();

		/**
		* @brief �I��
		*/
		virtual void End();
	
		
	
	public:
	
		/**
		* @brief �R���X�g���N�^
		* @param pDataName �f�[�^�t�@�C����
		*/
		CSceneTitle( const char *pDataName );
		
		/**
		* @brief �f�X�g���N�^
		*/
		virtual ~CSceneTitle(void);
		
		
		
		///**
		//* @brief �X�V
		//* @return ���݂̃V�[���̏��
		//*/
		//virtual eSceneState Update();
		//
		
		

};
