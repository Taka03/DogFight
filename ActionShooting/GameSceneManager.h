//*============================================================================
//GameSceneManager.h
//*============================================================================
/**
* �Q�[���V�[���Ǘ��N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "SceneBase.h"
#include <map>

//=============================================================================
//class
//=============================================================================
class CGameSceneManager
{
	private:
	
		sp<CSceneBase> m_spCurScene;///<@brief ���݂̃V�[��
		sp<CSceneBase> m_spNextScene;///<@brief ���̃V�[��
		//eSceneState m_eSceneState;///<@brief �V�[���̏��
		
		bool m_IsDemo;///<@brief �f������
		
	public:
		
		/**
		* @brief �R���X�g���N�^
		*/
		CGameSceneManager( );
		
		/**
		* @brief �f�X�g���N�^
		*/
		~CGameSceneManager();
		
		/**
		* @brief �X�V
		*/
		void Update();
		
		
	public:
	
		/**
		* @brief ���݂̃V�[���̐ݒ�
		* @param pScene �V�[��
		*/
		void SetCurrentScene( CSceneBase *pScene );
		
		/**
		* @brief ���̃V�[���̐ݒ�
		* @param pScene �V�[��
		*/
		void SetNextScene( CSceneBase *pScene );
		
		/**
		 *
		 * @brief �f���t���O�̐ݒ�
		 * @param IsDemo �f���t���O
		 */
		void SetDemoFlag( const bool IsDemo )
		{
			m_IsDemo = IsDemo;
		}
		
	public:

		/**
		 * �f���t���O�̎擾
		 * @return �f���t���O
		 */
		bool GetDemoFlag() const
		{
			return m_IsDemo;
		}

};
