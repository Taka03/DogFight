//*============================================================================
//SoundEffect.h
//*============================================================================
/**
* ���ʉ��N���X
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
//	���ʉ��Đ��p�N���X
//=============================================================================
class CSoundEffect :	public CSoundObject
{
	private:
	
		Sound::ISound *m_pSE;///<@brief ���ʉ��Đ��p�f�o�C�X

	
	public:
	
		/**
		* @brief �R���X�g���N�^
		* @param pName �f�[�^��
		*/
		CSoundEffect( const char *pName );
		
		/**
		* @brief �f�X�g���N�^
		*/
		virtual ~CSoundEffect(void);
		
		/**
		* @brief ���̍Đ�
		*/
		virtual void Play();
		
		/**
		* @brief ���̒�~
		*/
		virtual void Stop();
		
		/**
		* @brief ���̓ǂݍ���
		*/
		virtual bool Load( );
		
	/*Get�n*/
	public:

		/**
		* @brief ���ʉ��Đ��p�f�o�C�X�̎擾
		* @return ���ʉ��Đ��p�f�o�C�X
		*/
		Sound::ISound *GetSEDevice() const
		{
			return m_pSE;
		}
		
};
