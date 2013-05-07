//*============================================================================
//gameobject.h
//*============================================================================
/**
* �Q�[���I�u�W�F�N�g�N���X
*/

#pragma once

//=============================================================================
//include
//=============================================================================
#include "CommonObject.h"
#include <string>

//=============================================================================
//variable
//=============================================================================
class CGameObject;

//=============================================================================
//namespace
//=============================================================================
using namespace std;

//=============================================================================
//class
//=============================================================================
//[desc]
//	�Q�[���I�u�W�F�N�g�p�N���X
//=============================================================================
class CGameObject 
{
	public:
	
		//�I�u�W�F�N�g�^�C�v
		enum eObjectType
		{
			TYPE_PLAYER,//�v���C���[
			TYPE_ENEMY,//�G
			TYPE_BULLET,//�v���C���[�̒e
			TYPE_EBULLET,//�G�̒e
			TYPE_MISSILE,//�~�T�C��
			TYPE_SWORD_WEAK,//���G�t�F�N�g(��)
			TYPE_SWORD_STRONG,//���G�t�F�N�g(��)
			TYPE_BOMB,//�{��
		};
	
	protected:
	
		string m_strFileName;///<@brief �t�@�C����
		
		string m_strDataName;///<@brief �f�[�^
		
		bool m_IsStop;///<@brief �Î~����t���O
		bool m_IsVisible;///<@brief �\������t���O
		bool m_IsRemoved;///<@brief �폜����t���O
		
		eObjectType m_eType;///<@brief �I�u�W�F�N�g�^�C�v
		
	public:
	
		/**
		* @brief �R���X�g���N�^
		* @param pName �t�@�C����
		*/
		CGameObject( const char *pName );
		
		/**
		* @brief �f�X�g���N�^
		*/
		virtual ~CGameObject();
		
		/**
		* @brief ������
		*/
		virtual void Init() = 0;
		
		
		/**
		* @brief ����
		*/
		virtual void Exec() = 0;
		
		/**
		* @brief �����_�����O����
		*/
		virtual void Rendering() = 0;
		
		/**
		* @brief �����蔻�菈��
		* @param spObj ���肷��I�u�W�F�N�g
		*/
		virtual bool HitCheck( sp<CGameObject> spObj ) = 0;
		
		
		/**
		* @brief �����������̏���
		* @param spObj ���肷��I�u�W�F�N�g
		*/
		virtual void HitExec( sp<CGameObject> spObj ) = 0;
		
		
		/**
		* @brief �t�@�C���ǂݍ���
		*/
		virtual bool Load() = 0;
		
		/**
		* @brief �p�����[�^�[�ǂݍ���
		*/
		virtual void LoadParameter( const char *pDataName ){};
		
	/*Set�n*/
	public:
	
		//�f�[�^���̐ݒ�
		void SetDataName( string strDataName )
		{
			m_strDataName = strDataName;
		}
		
		/**
		* @brief �\���t���O�̐ݒ�
		* @param IsVisible �ݒ肷��\���t���O
		*/
		void SetVisibleFlag( bool IsVisible )
		{
			m_IsVisible = IsVisible;
		}
		
		/**
		* @brief �Î~�t���O�̐ݒ�
		* @param IsStop �ݒ肷��Î~�t���O
		*/
		void SetStopFlag( bool IsStop )
		{
			m_IsStop = IsStop;
		}
		
		/**
		* @brief �폜�t���O�̎擾
		* @param IsRemoved ���肷��폜�t���O
		*/
		void SetRemoveFlag( bool IsRemoved )
		{
			m_IsRemoved = IsRemoved;
		}
		
		/**
		* @brief �L�����N�^�[��Ԃ̐ݒ�
		* @param eState �ݒ肷��L�����N�^�[���
		*/
		//void SetState( eCharaState eState )
		//{
		//	m_eState = eState;
		//}
		
		
		
	/*Get�n*/
	public:
	
		/**
		* @brief �t�@�C�����̎擾
		* @return �t�@�C����
		*/
		string GetFileName() const
		{
			return m_strFileName;
		}
		
		/**
		* @brief �f�[�^���̎擾
		* @return �f�[�^��
		*/
		string GetDataName() const
		{
			return m_strDataName;
		}
		
		/**
		* @brief �\���t���O�̎擾
		* @return �\���t���O
		*/
		bool GetVisibleFlag() const
		{
			return m_IsVisible;
		}
		
		/**
		* @brief �Î~�t���O�̎擾
		* @return �Î~�t���O
		*/
		bool GetStopFlag() const
		{
			return m_IsStop;
		}
		
		/**
		* @brief �폜�t���O�̎擾
		* @return �폜�t���O
		*/
		bool GetRemoveFlag() const
		{
			return m_IsRemoved;
		}
		
		/**
		* @brief �I�u�W�F�N�g�^�C�v�̎擾
		* @return �I�u�W�F�N�g�^�C�v
		*/
		eObjectType GetType() const
		{
			return m_eType;
		}
		
		/**
		* @brief �����蔻��̈�̎擾
		* @return �����蔻��̈�
		*/
		virtual Math::Rect2DF GetHitRect() const
		{ 
			return Math::Rect2DF( 0, 0, 0, 0 ); 
		};
		
		
};
