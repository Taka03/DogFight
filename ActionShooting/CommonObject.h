//*============================================================================
//CommonObject.h
//*============================================================================
/**
* ���ʃI�u�W�F�N�g�N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "common.h"

//=============================================================================
//variable
//=============================================================================
class CGameSceneManager;
class CSoundManager;
class CResourceManager;
class CApplication;
class CJoyPad;

//=============================================================================
//class
//=============================================================================
//[Desc]
//	���ʃI�u�W�F�N�g�p�N���X
//=============================================================================
class CCommonObject
{
	public:
	
		/**
		* @brief �R���X�g���N�^
		*/
		CCommonObject(void);
		
		/**
		* @brief �f�X�g���N�^
		*/
		~CCommonObject(void);
		
	private:
	
		static CApplication *m_pApp;///<@brief �A�v���P�[�V�����N���X
		static CResourceManager *m_pResMgr;///<@brief ���\�[�X�Ǘ��N���X
		static CSoundManager *m_pSndMgr;///<@brief �T�E���h�Ǘ��N���X
		static CGameSceneManager *m_pGameSceneMgr;///<@brief �Q�[���V�[���Ǘ��N���X
		static CJoyPad *m_pJoyPad;///<@brief �W���C�p�b�h�N���X
		
	public:
	
		/**
		* @brief ����������
		*/
		static void Initialize();
		
		/**
		* @brief �I������
		*/
		static void Finalize();
	
	public:
	
		/*�T�E���h�Ǘ��N���X�̎擾*/
		static CSoundManager *GetSoundMgr(); 
		
		/**
		* @brief ���\�[�X�Ǘ��N���X�̎擾
		* @return ���\�[�X�Ǘ��N���X
		*/		
		static CResourceManager *GetResMgr();
		
		/**
		* @brief �A�v���P�[�V�����N���X�̎擾
		* @return �A�v���P�[�V�����N���X
		*/		
		static CApplication *GetAppli();
		
		////�}�E�X�N���X�̎擾
		//static CMouse *GetMouse();
		
		/**
		* @brief �W���C�p�b�h�N���X�̎擾
		* @return �W���C�p�b�h�N���X
		*/		
		static CJoyPad *GetJoyPad();
		
		/**
		* @brief �Q�[���V�[���}�l�[�W���̎擾
		* @return �Q�[���V�[���}�l�[�W��
		*/		
		static CGameSceneManager *GetGameSceneMgr();
};
