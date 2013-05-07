//*============================================================================
//BGM.h
//*============================================================================
/**
* BGM�N���X�B
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "SoundObject.h"

//=============================================================================
//class
//=============================================================================
//[desc]
//	BGM�Đ��p�N���X
//=============================================================================
class CBGM :	public CSoundObject
{
	private:
	
		Sound::IStreamSound *m_pBGM;///<@brief BGM�Đ��p�f�o�C�X
	
	public:
	
		/**
		* @brief �R���X�g���N�^
		* @param pName �f�[�^��
		*/
		CBGM( const char *pName );
		
		/**
		* @brief �f�X�g���N�^
		*/
		virtual ~CBGM(void);
		
		/**
		* @brief ���̓ǂݍ���
		*/
		virtual bool Load();
		
		//�Đ�
		//void Play( Sound::SPlayBlock *pTbl, int count );
		
		/**
		* @brief ���̍Đ�
		*/
		void Play();
		
		/**
		* @brief ���̒�~
		*/
		void Stop();
		
		
		/**
		* @brief �t�F�[�h�A�E�g
		*/
		void FadeOut();
		
	/*Get�n*/
	public:

		/**
		* @brief BGM�f�o�C�X�̎擾
		* @return BGM�f�o�C�X
		*/
		Sound::IStreamSound *GetBGMDevice() const
		{
			return m_pBGM;
		}
		
};
