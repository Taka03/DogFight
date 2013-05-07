//*============================================================================
//EnemyPattern.h
//*============================================================================
/**
* �G�p�^�[���N���X
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
class CEnemyPattern 

{
	
	public:
	
		enum eEnemyPat
		{
			PAT_STEP, //�K�i��
			PAT_ROLL, //��]
			PAT_CURVE, //�J�[�u
			PAT_STRAIGHT,//���i(��)
			PAT_AIMING,//���@�_��
			PAT_MIDDLE,//���^�@
		};///@brief �G�̃p�^�[��
		
		struct tagPattern
		{
			Sint32 m_Time;//�o������
			Math::Vector2D m_vPos;//�o���ʒu
			Sint32 m_Pattern;//�G�̃p�^�[��
			Sint32 m_Interval;//�G�̏o�Ă���Ԋu
			Sint32 m_EnemyNum;//�o�Ă���G�̐�
			
			tagPattern() 
			{
				m_Time = 0;
				m_vPos.x = 0;
				m_vPos.y = 0;
				m_Pattern = 0;
				m_Interval = 0;
				m_EnemyNum = 0;
				
			}
		};///@brief �G�p�^�[��
	
	private:
	
		tagPattern m_EnemyPat;///@brief �G�̃p�^�[��
		Uint32 m_Counter;///@brief �ėp�J�E���^�[
		Uint32 m_EnemyCount;///@brief �G�J�E���^�[
		Sint32 m_CurPat;///<@brief ���݂̃p�^�[��
		bool m_IsRemoved;///@brief ��������t���O
		
		static Uint32 m_SmallEnemyNum;//@brief ���^�@��
		
		Sint32 m_Angle;///@brief �ėp�p�x
			
	public:
	
		/**
		* @brief �R���X�g���N�^
		*/
		CEnemyPattern( tagPattern Pat);
		
		/**
		* @brief �f�X�g���N�^
		*/
		virtual ~CEnemyPattern(void);
		
		
		/**
		* @brief ��������
		*/
		void Exec();
		
		
		/**
		* @brief �K�i��̈ړ�
		*/
		void MoveStep();

		/**
		* @brief TODO:��]�̈ړ�
		*/
		void MoveRoll();
		
		/**
		* @brief �J�[�u�̈ړ�
		*/
		void MoveCurve();
		
		/**
		* @brief ���i�̈ړ�
		*/
		void MoveStraight( );

		/**
		* @brief ���@�_���̈ړ�
		*/
		void MoveAiming();
		
		/**
		* @brief ���^�@�̈ړ�
		*/
		void MoveMiddleEnemy();
		
	//Set�n
	public:
	
		void SetRemoveFlag( bool flag )
		{
			m_IsRemoved = flag;
		}
		
	//Get�n
	public:
	
		bool GetRemoveFlag() const
		{
			return m_IsRemoved;
		}
		
		tagPattern GetPattern() const
		{
			return m_EnemyPat;
		}
	
};
