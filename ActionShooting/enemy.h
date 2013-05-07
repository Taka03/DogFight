//*============================================================================
//enemy.h
//*============================================================================
/**
* �G�N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "character.h"

//=============================================================================
//class
//=============================================================================
class CEnemy :	public CCharacter
{
	
	protected:
	
		enum eEnemyState
		{
			STATE_NONE,//�����Ȃ����
			STATE_DAMAGE_SHOT,//�_���[�W���󂯂Ă�����(�V���b�g)
			STATE_DAMAGE_SWORD_W,//�_���[�W���󂯂Ă�����(��)
			STATE_DAMAGE_SWORD_S,//�_���[�W���󂯂Ă�����(��)
			STATE_DAMAGE_BOMB,////�_���[�W���󂯂Ă�����(�{��)
			STATE_DIED,//���񂾏��
		};///<@brief �L�����N�^�[�̏��
		
		enum eMovePat
		{
			MOVE_STRAIGHT,//���i
			MOVE_ROLL, //��]
			MOVE_CURVE, //�J�[�u
			MOVE_AIMING, //���@�_��
		};///<@brief �ړ��p�^�[��
		
		enum eShotPat
		{
			SHOT_NONE, //�e�������Ȃ�
			SHOT_STRAIGHT,//���i�e
			SHOT_AIMSHOOT, //���@�_���e
			SHOT_MISSILE, //�U���e
		};///<@brief �V���b�g�p�^�[��
		
		enum eEnemyType
		{
			TYPE_SMALL,
			TYPE_MIDDLE,
		};///<@brief �G�̃^�C�v
		
		
	protected:
	
		int m_ShootCount;///<@brief �e�������o���J�E���^�[
		int m_Score;///<@brief �X�R�A
		Sint32 m_Scroll;///<@brief �X�N���[��
		Sint32 m_Life;///<@brief ���C�t
		Sint32 m_StateTime;///<@brief ��ԃJ�E���^�[
		bool m_IsDamaged;///<@brief �_���[�W���󂯂Ă��邩
		bool m_IsBlowed;///@brief ������΂���Ă��邩
		bool m_IsDead;///@brief ���S����t���O
		
		bool m_IsShoot;///<@brief �V���b�g����t���O
		Uint32 m_ShotNum;///<@brief �V���b�g��
		Uint32 m_MaxShot;///<@brief �ő�V���b�g��
		Uint32 m_StreamCount;///<@brief �A���J�E���^�[
		Uint32 m_ShotTime;///<@brief �e���o������
		
		Uint32 m_StreamTime;///<@brief �A������
		
		Uint32 m_DeadTime;///@brief ���S����
		
		Uint32 m_BombDamage;///@brief �����_���[�W
		
		eEnemyState m_eState;///<@brief �L�����̏��
		eMovePat m_eMovePat;///<@brief �ړ��p�^�[��
		eShotPat m_eShotPat;///<@brief �V���b�g�p�^�[��
		eEnemyType m_eEnemyType;///<@brief �G�̃^�C�v
		
		Sint32 m_RollAngle;///<@brief ��]�p�x
		
		Math::Vector2D m_vTargetPos;///<@brief �^�[�Q�b�g�̈ʒu
		
		bool m_IsSwordDamage;///<@brief �ߋ����U���Ń_���[�W��^���邩
		
		Sint32 m_DeadCount;///<@brief ���S�J�E���g

		bool m_IsSlash;///<@brief �X���b�V�����
		bool m_IsSlashEnd;///<@brief

	public:
		
		/**
		* @brief �R���X�g���N�^
		* @param pName �t�@�C����
		* @param pDataName �f�[�^��
		* @param vPos �ݒ肷��ʒu
		*/
		CEnemy( const char *pName, const char *pDataName, Math::Vector2D vPos );
		
		/**
		* @brief �f�X�g���N�^
		*/
		~CEnemy(void);
		
		/**
		* @brief �ړ�����
		*/
		virtual void Move();
		
		/**
		* @brief �V���b�g����
		*/
		virtual void Shoot();
		
		/**
		* @brief �ړ��␳
		*/
		void MoveAdjust();
		
		/**
		* @brief �p�����[�^�[�̓ǂݍ���
		* @param pFileName �t�@�C����
		*/
		void LoadParameter( const char *pFileName );
		
		/**
		* @brief �����������̏���
		* @param spObj ���肷��I�u�W�F�N�g
		*/
		virtual void HitExec( sp<CGameObject> spObj );
		
		/**
		* @brief ��Ԗ��̏���
		*/
		virtual void StateExec();
		
		/**
		* @brief �A�j���[�V�����̐ݒ�
		*/
		virtual void SetAnimation();
		
		
		
	//�ړ��p�^�[��
	public:
	
		/**
		* @brief �ړ��p�^�[���̏���
		*/
		void MovePatExec();
	
		/**
		* @brief ���i
		*/
		void MovePatStraight();
		
		/**
		* @brief ��]
		*/
		void MovePatRoll();
		
		/**
		* @brief �J�[�u
		*/
		void MovePatCurve();
		
		/**
		* @brief ���@�_��
		*/
		void MovePatAiming();
		
	//�e�̃p�^�[��
	public:
	
		/**
		* @brief �e���˃p�^�[���̏���
		*/
		void ShotPatExec();
		
		/**
		* @brief ���i�e
		*/
		void ShotPatStraight();
		
		/**
		* @brief ���@�_���e
		*/
		void ShotPatAimShoot();
		
		/**
		* @brief �U���e
		*/
		void ShotPatMissile();
		
	public:
	
		/**
		* @brief �L�����N�^�[��Ԃ̐ݒ�
		* @param eState �ݒ肷��L�����N�^�[���
		*/
		void SetState( eEnemyState eState )
		{
			m_eState = eState;
		}
		
		void SetLife( int Life )
		{
			m_Life = Life;
		}
		
		void SubLife( int Life )
		{
			m_Life -= Life;
		}
		
	public:
	
		bool GetBlowFlag() const
		{
			return m_IsBlowed;
		}
	
	
		
		
};
