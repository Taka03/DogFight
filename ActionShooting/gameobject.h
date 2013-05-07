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
#include <vector>

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
			TYPE_BLOWENEMY,//������΂���Ă���G
			TYPE_BULLET,//�v���C���[�̒e
			TYPE_EBULLET,//�G�̒e
			TYPE_MISSILE,//�~�T�C��
			TYPE_SWORD_WEAK,//���G�t�F�N�g(��)
			TYPE_SWORD_STRONG,//���G�t�F�N�g(��)
			TYPE_BOMB,//�{��
			TYPE_CHAINBOMB,//�U���{��
		};
	
	protected:
	
		Math::Vector2D m_vPos;///<@brief �ʒu
		Sint32 m_Angle;///<@brief ��]�p�x
		Math::Point2DF m_fScale;///<@brief �g�k��
		
		Math::Vector2D m_vInitPos;///<@brief �����ʒu
		Sint32 m_InitAngle;///<@brief �����p�x
		Math::Point2DF m_fInitScale;///<@brief �����g�k��
	
		string m_strFileName;///<@brief �t�@�C����
		
		string m_strDataName;///<@brief �f�[�^��
		
		bool m_IsStop;///<@brief �Î~����t���O
		bool m_IsVisible;///<@brief �\������t���O
		bool m_IsRemoved;///<@brief �폜����t���O
		
		bool m_IsRemEnd;///<@brief �V�[���I���Ɠ����ɍ폜���邩

		bool m_IsHit;///<@brief �����蔻��t���O
		
		eObjectType m_eType;///<@brief �I�u�W�F�N�g�^�C�v
		
		sp<CGameObject> m_spTargetObj;///@brief �^�[�Q�b�g�I�u�W�F�N�g
		
	public:
	
		/**
		* @brief �R���X�g���N�^
		* @param pName �t�@�C����
		* @param pDataName �f�[�^�t�@�C����
		*/
		CGameObject( const char *pName, const char *pDataName );
		
		/**
		 * @brief �R���X�g���N�^
		 * @param vecStr
		 * @return
		 */
		CGameObject( vector<string> vecStr );

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
		void SetDataName( const string strDataName )
		{
			m_strDataName = strDataName;
		}
		
		/**
		* @brief �\���t���O�̐ݒ�
		* @param IsVisible �ݒ肷��\���t���O
		*/
		void SetVisibleFlag( const bool IsVisible )
		{
			m_IsVisible = IsVisible;
		}
		
		/**
		* @brief �Î~�t���O�̐ݒ�
		* @param IsStop �ݒ肷��Î~�t���O
		*/
		void SetStopFlag( const bool IsStop )
		{
			m_IsStop = IsStop;
		}
		
		/**
		* @brief �폜�t���O�̐ݒ�
		* @param IsRemoved ���肷��폜�t���O
		*/
		void SetRemoveFlag( const bool IsRemoved )
		{
			m_IsRemoved = IsRemoved;
		}
		
		/**
		 * @brief �V�[���Ɠ����ɍ폜���邩�t���O�̐ݒ�
		 * @param IsEnd�@�V�[���Ɠ����ɍ폜���邩�t���O
		 */
		void SetRemEndFlag( const bool IsEnd )
		{
			m_IsRemEnd = IsEnd;
		}

		/**
		* @brief �ʒu�̐ݒ�
		* @param vPos �ݒ肷��ʒu
		*/
		void SetPosition( const Math::Vector2D vPos )
		{
			m_vPos = vPos;
		}
	
		/**
		* @brief ��]�p�x�̐ݒ�
		* @param Angle �ݒ肷��p�x
		*/
		void SetAngle( const Sint32 Angle )
		{
			m_Angle = Angle;
		}
		
		//�`�悷�镶���̐ݒ�		
		virtual void SetDrawString( string str ){};
		
		void SetHitFlag( bool flag )
		{
			m_IsHit = flag;
		}
		
		void SetTargetObj( sp<CGameObject> spObj )
		{
			m_spTargetObj = spObj;
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
		* @brief �ʒu�̎擾
		* @return �ʒu
		*/
		Math::Vector2D GetPos() const
		{
			return m_vPos;
		}
		
		/**
		* @brief ��]�p�x�̎擾
		* @return ��]�p�x
		*/
		Sint32 GetAngle() const
		{
			return m_Angle;
		}
		
		/**
		* @brief �g�k�̎擾
		* @return �g�k
		*/
		Math::Point2DF GetScale() const
		{
			return m_fScale;
		}
		
		/**
		* @brief �����ʒu�̎擾
		* @return �����ʒu
		*/
		Math::Vector2D GetInitPos() const
		{
			return m_vInitPos;
		}
	
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
		 * @brief �V�[���Ɠ����ɍ폜���邩�t���O�̎擾
		 * @return �V�[���Ɠ����ɍ폜���邩�t���O
		 */
		bool GetRemEndFlag() const
		{
			return m_IsRemEnd;
		}

		/**
		* @brief �����蔻��t���O�̎擾
		* @return �����蔻��t���O
		*/
		bool GetHitFlag() const
		{
			return m_IsHit;
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
		
		sp<CGameObject> GetTargetObj() const
		{
			return m_spTargetObj;
		}
		
		virtual bool GetBlowFlag() const
		{
			return false;
		}
		
		virtual void SubLife( int Life )
		{
			
		}
		
		
};
