//*============================================================================
//SceneGameMain.h
//*============================================================================
/**
* �Q�[���V�[���N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "SceneBase.h"
#include "EnemyPattern.h"

#include <set>

//=============================================================================
//const
//=============================================================================
const int SCORELIST_MAX = 10;

//=============================================================================
//class
//=============================================================================
class CSceneGameMain :public CSceneBase
{
	public:
	
		struct tagTime
		{
			Sint32 m_Minute;//��
			Sint32 m_Second;//�b
			
			tagTime()
			{
				m_Minute = 0;
				m_Second = 0;
			}
		};///@brief ����
		
	private:
	
		static Uint32 m_HitCount;///<@brief �q�b�g��
		static Uint32 m_MaxHitCount;///@brief �ő�q�b�g��
		static Uint32 m_HitTime;///<@brief �q�b�g����
		static Uint32 m_GameScore;///<@brief �X�R�A
		static bool m_IsPause;///@brief �|�[�Y������t���O
		Uint32 m_InitHighScore;///@brief �����ō��X�R�A
		static Uint32 m_HighScore;///<@brief �ō��X�R�A
		
		int m_SceneCounter;//�V�[���J�E���^�[
		
		int m_GameCounter;///<@brief �Q�[���J�E���^�[
		static tagTime m_Time;///<@brief ����
		static bool m_IsGameEnd;///<@brief �Q�[���I������t���O
		static bool m_IsUpdateScore;///@brief �n�C�X�R�A���X�V������
		
		Sint32 m_CurPat;///@brief ���݂̓G�p�^�[��
		
		map< Sint32, sp<CEnemyPattern> > m_mapEnemyPat;///<@brief �G�̃p�^�[��
		vector< CEnemyPattern::tagPattern > m_vecPat;

		static multiset<int> m_setScore;///<@brief �����L���O�X�R�A	�p

		int m_arScore[SCORELIST_MAX];///<@brief �����L���O�X�R�A�p�z��

		bool m_IsRetry;
		//list< sp<CEnemyPattern> > m_liEnemyPat;
		
		//CEnemyPattern m_EnemyPat;///<@brief �G�̃p�^�[��
		
		static string m_strScore;///<@brief �X�R�A�̕�����
		static string m_strMaxHitNum;///<@brief �X�R�A�̍ő�q�b�g��
		static bool m_IsGameClear;///<@brief �Q�[���N���A�t���O
	
	public:
	
		/**
		* @brief �R���X�g���N�^
		* @param pDataName �f�[�^�t�@�C����
		*/
		CSceneGameMain( const char *pDataName );
		
		/**
		* @brief �f�X�g���N�^
		*/
		virtual ~CSceneGameMain(void);
		
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
		
		/**
		 * @brief �f��
		 */
		void Demo();
		
		/**
		 * @brief ���C��
		 */
		void Main();

		/**
		* @brief �n�C�X�R�A�̓ǂݍ���
		*/
		void LoadHiScore();
		
		
		/**
		* @brief �n�C�X�R�A�̃Z�[�u
		*/
		void SaveHiScore();
		
		
		/**
		* @brief �q�b�g���̕`��
		*/
		void DrawHitCount();
		
		/**
		* @brief �X�R�A�̕`��
		*/
		void DrawScore();
		
		/**
		* @brief �n�C�X�R�A�̕`��
		*/
		void DrawHiScore();
		
		/**
		* @brief �X�R�A�̕`��
		*/
		void DrawTime();
		
		/**
		* @brief �G�p�^�[���̓ǂݍ���
		*/
		void LoadPattern( );
		
		//�|�[�Y���̏���
		void Pause();
		
		/**
		 * @brief ���g���C
		 */
		void Retry();

		
		
	//Set�n
	public:
	
		/**
		* @brief �q�b�g�J�E���g�̐ݒ�
		* @param count �ݒ肷��J�E���g
		*/
		static void SetHitCount( int count )
		{
			m_HitCount = count;
		}
		
		/**
		* @brief �q�b�g���̑���
		*/
		static void AddHitCount()
		{
			++m_HitCount;
		}
		
		/**
		* @brief �q�b�g���Ԃ̐ݒ�
		* @param count �ݒ肷��q�b�g����
		*/
		static void SetHitTime( int time )
		{
			m_HitTime = time;
		}
	
		/**
		* @brief �q�b�g���Ԃ̑���
		*/
		static void AddHitTime()
		{
			++m_HitTime;
		}
		
		/**
		* @brief �X�R�A�̑���
		* @param Score ���Z����X�R�A
		*/
		static void AddScore( const Uint32 Score )
		{
			m_GameScore += Score;
		}
		
		/**
		* @brief �Q�[���I���t���O�̃Z�b�g
		* @param flag �Z�b�g����t���O
		*/
		static void SetGameEndFlag( bool flag )
		{
			m_IsGameEnd = flag;
		}
		
		/**
		* @brief �|�[�Y�t���O�̃Z�b�g
		* @param flag �Z�b�g����t���O
		*/
		static void SetPauseFlag( bool flag )
		{
			m_IsPause = flag;
		}
		
	//Get�n
	public:
	
		/**
		* @brief �q�b�g���Ԃ̎擾
		* @return �q�b�g����
		*/
		static Uint32 GetHitTime()
		{
			return m_HitTime;
		}
		
		/**
		* @brief �q�b�g���̎擾
		* @return �q�b�g��
		*/
		static Uint32 GetHitCount()
		{
			return m_HitCount;
		}
		
		static Uint32 GetMaxHitCount()
		{
			return m_MaxHitCount;
		}

		/**
		* @brief �|�[�Y�t���O�̎擾
		* @return �|�[�Y�t���O
		*/
		static bool GetPauseFlag() 
		{
			return m_IsPause;
		}
		
		static string GetStrScore()
		{
			return m_strScore;
		}
		
		static string GetStrMaxHit()
		{
			return m_strMaxHitNum;
		}
		
		static bool GetUpdateScore()
		{
			return m_IsUpdateScore;
		}
		
		static int GetGameScore()
		{
			return m_GameScore;
		}

		static int GetHighScore()
		{
			return m_HighScore;
		}
	
		/**
		 * @brief �����L���O�X�R�A�̎擾
		 * @return �����L���O�X�R�A
		 */
		static multiset<int> GetSetScore()
		{
			return m_setScore;
		}


		/**
		 * @brief �Q�[�����Ԃ̎擾
		 * @return �Q�[������
		 */
		static tagTime GetTime()
		{
			return m_Time;
		}

		/**
		 *
		 * @return
		 */
		static bool GetGameClearFlag()
		{
			return m_IsGameClear;
		}

				
		
		
		
		
};
