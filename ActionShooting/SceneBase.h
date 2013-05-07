//*============================================================================
//SceneBase.h
//*============================================================================
/**
* �V�[����{�N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "common.h"
#include <vector>
#include <map>

//=============================================================================
//variable
//=============================================================================
//class CGameObject;

//=============================================================================
//class
//=============================================================================
class CSceneBase
{
	public:
	
		enum eSceneState
		{
			SCENE_STANDBY,
			SCENE_FADEIN,
			SCENE_FADEOUT,
			SCENE_FINISH,
		};///<@brief �V�[�����
		
	
	protected:
	
		map< string, sp<CGameObject> > m_mapResource;///<@brief ���\�[�X�}�b�v

		void (CSceneBase::*m_pStateFunc)(void);///<@brief �V�[���̏�ԕω�
		
		eSceneState m_eSceneState;///<@brief �V�[���̏��
		
		string m_ResName;///<@brief ���\�[�X��

	protected:
	
		/**
		* @brief ���\�[�X�t�@�C���̓ǂݍ���
		* @param pDataName �f�[�^�t�@�C����
		* @return ���[�h������������
		*/
		bool LoadResourceFile( const char *pDataName );
		
		/**
		 * �I�u�W�F�N�g�̒ǉ�
		 * @return �I�u�W�F�N�g�̒ǉ����I��������
		 */
		virtual bool InitObject(){ return false; };


	public:

		/**
		* @brief �R���X�g���N�^
		* @param pDataName �f�[�^�t�@�C����
		*/
		CSceneBase( const char *pDataName );

		/**
		* @brief �f�X�g���N�^
		*/
		virtual ~CSceneBase(void);

		/**
		* @brief ������
		*/
		virtual void Init() = 0;

		/**
		* @brief �ҋ@��
		*/
		virtual void Idle() = 0;

		/**
		* @brief �I��
		*/
		virtual void End() = 0;

		
		
		/**
		* @brief �X�V
		* @return ���݂̃V�[���̏��
		*/
		eSceneState Update();
		
		
	public:
	
		/*��Ԃ̃Z�b�g*/
		void SetState( void ( CSceneBase::*pState_Func )(void) )
		{
			m_pStateFunc = pState_Func;
		}
	
		
};
