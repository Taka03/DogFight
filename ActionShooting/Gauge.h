//*============================================================================
//Gauge.h
//*============================================================================
/**
* �w�i�N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "sprite.h"

//=============================================================================
//class
//=============================================================================
class CGauge :	public CSprite
{
	private:
	
		static float m_fGaugeVal;///<@brief �Q�[�W�l
		Sint32 m_FontAnim;///@brief �����̃A�j���[�V����
		static float m_fAddGaugeVal;///<@brief �Q�[�W�����l
		bool m_IsMaxCharge;///<@brief �ő�܂Ń`���[�W������

	
	public:
		
		/**
		* @brief �R���X�g���N�^
		* @param pName �t�@�C����
		* @param pDataName �f�[�^��
		*/
		CGauge( const char *pName, const char *pDataName );
		
		/**
		* @brief �f�X�g���N�^
		*/
		~CGauge(void);
		
		/**
		* @brief ����
		*/
		void Exec();
		

		/**
		* @brief �p�����[�^�[�̓ǂݍ���
		* @param pFileName �t�@�C����
		*/
		void LoadParameter( const char *pFileName );
		
		/**
		* @brief �����蔻��
		* @param spObj ���肷��I�u�W�F�N�g
		* @retval true �������Ă���
		* @retval false �������Ă��Ȃ�
		*/
		virtual bool HitCheck( sp<CGameObject> spObj );
		

	public:

		/**
		 * @brief �Q�[�W�̑���
		 * @param fVal �����l
		 */
		static void AddGauge( float fVal )
		{
			m_fAddGaugeVal = fVal;
			m_fGaugeVal += m_fAddGaugeVal;

		}

		/**
		 * @brief �Q�[�W�l�̎擾
		 * @return�@�Q�[�W�l
		 */
		static float GetGaugeVal( )
		{
			return m_fGaugeVal;
		}

	public:

		
		
		
};
