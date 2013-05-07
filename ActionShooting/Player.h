//*============================================================================
//Player.h
//*============================================================================
/**
* �v���C���[�N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "character.h"
#include <vector>

//=============================================================================
//const
//=============================================================================
const int SHADOW_NUM = 4;


//=============================================================================
//class
//=============================================================================
class CPlayer :	public CCharacter
{
	private:
	
		enum ePlayerState
		{
			STATE_NONE,//�����Ȃ����
			STATE_SHOOTING, //�e�������Ă�����
			STATE_INVINCIBLE, //���G���
			STATE_HYPERMODE,//�n�C�p�[���[�h
			STATE_DIED,//���񂾏��
		};///<@brief �L�����N�^�[�̏��
		
		enum ePlayerAnim
		{
			ANIM_STAND,
			ANIM_FRONT,
			ANIM_BACK,
			ANIM_SLASH1,
			ANIM_SLASH2,
			ANIM_SLASH3,	
		};///<@brief �v���C���[�A�j���[�V����
		
		
		Sint32 m_Stock;///<@brief �c��X�g�b�N��
		Sint32 m_HitNum;///<@brief �q�b�g��
		
		Sint32 m_HitCount;///<@brief �q�b�g�J�E���^�[
		Sint32 m_InvTime;///<@brief ���G����
		
		Sint32 m_Time;///@brief �ėp�J�E���^�[
		
		Sint32 m_SwordTime;///@brief �\�[�h����

		Math::Point2DI m_AdjustSize;///@brief �␳�T�C�Y
		
		vector<Uint32> m_vecAnimNum;///<@brief �A�j���[�V������
		vector<Uint32> m_vecAnimTime;///<@brief �A�j���[�V������
		
		Sint32 m_ShootCount;
		Sint32 m_Count;
		
		bool m_IsShoot;///<@brief �e���˔���t���O
		bool m_IsSlash;///<@brief �a������
		bool m_IsMove;

		bool m_IsNoSword;///<@brief �\�[�h�̓��͂��󂯕t���邩


		static bool m_IsHyperMode;///< @brief �o�����[�h����
		static bool m_IsSlashEnd;
		
		//bool m_IsDemo;///<@brief �f������
		
		ePlayerState m_eState;///<@brief �L�����̏��
		
		static float m_fGaugeAdd;///<@brief �Q�[�W�����l
		static float m_fGaugeAddShot;///<@brief �Q�[�W�����l(�V���b�g)
		float m_fGaugeSub;///<@brief �o�����[�h���̃Q�[�W�����l)
		
		Sint32 m_ShadowNum;///<@brief �c����

		Math::Vector2D m_vShadowPos[SHADOW_NUM];
		CColor m_ShadowColor[SHADOW_NUM];

		vector<Math::Vector2D> m_vecShadowPos;///<@brief �c���ʒu

		vector<CColor> m_vecColor;///<@brief �c���F

		




	public:
		
		/**
		* @brief �R���X�g���N�^
		* @param pName �t�@�C����
		* @param pDataName �f�[�^��
		*/
		CPlayer( const char *pName, const char *pDataName );
		
		/**
		* @brief �f�X�g���N�^
		*/
		~CPlayer(void);
		
		/**
		 * @brief ������
		 */
		void Init(){};

		/**
		* @brief ����
		*/
		void Exec();
		
		/**
		 * @brief �`�惊�N�G�X�g
		 */
		virtual void DrawRequest();

		/**
		* @brief �p�����[�^�[�̓ǂݍ���
		* @param pFileName �t�@�C����
		*/
		void LoadParameter( const char *pFileName );
		
		/**
		 * @brief �����_�����O
		 */
		void Rendering();

		/**
		* @brief �ړ�����
		*/
		void Move();
		
		/**
		* @brief �V���b�g����
		*/
		void Shoot();
		
		/**
		* @brief �ߐڍU������
		*/
		void Attack();
		
		/**
		 * @brief �n�C�p�[���[�h�̏���
		 */
		void HyperModeExec();

		/**
		* @brief �A�j���[�V�����̐ݒ�
		*/
		void SetAnimation();
		
		
		/**
		* @brief �ړ��␳
		*/
		void MoveAdjust();
		
		/**
		* @brief �X�g�b�N�̕`��
		*/
		void DrawStock();
		
		/**
		* @brief �����������̏���
		* @param spObj ���肷��I�u�W�F�N�g
		*/
		virtual void HitExec( sp<CGameObject> spObj );
		
		/**
		* @brief ��Ԗ��̏���
		*/
		virtual void StateExec();
		


	public:


		/**
		 * @brief �f���t���O�̐ݒ�
		 */
		//void SetDemoFlag( const bool flag )
		//{
		//	m_IsDemo = flag;
		//}

		/**
		 * �o����ԃt���O�̐ݒ�
		 * @param flag �o���t���O
		 */
		void SetHyperFlag( const bool flag )
		{
			m_IsHyperMode = flag;
		}

	public:
	
		Sint32 GetStock() const
		{
			return m_Stock;
		}
		
		/**
		 * @brief �Q�[�W�����l�̎擾
		 * @return�@�Q�[�W�����l
		 */
		static float GetGaugeAdd()
		{
			return m_fGaugeAdd;
		}

		/**
		 * @brief �Q�[�W�����l�̎擾
		 * @return�@�Q�[�W�����l
		 */
		static float GetGaugeAddShot()
		{
			return m_fGaugeAddShot;
		}

		/**
		 * @brief �n�C�p�[���[�h�̎擾
		 * @return�@�n�C�p�[���[�h��
		 */
		static bool GetHyperMode()
		{
			return m_IsHyperMode;
		}



};
