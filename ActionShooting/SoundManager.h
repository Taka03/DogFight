//*============================================================================
//SoundManager.h
//*============================================================================
/**
* �T�E���h�Ǘ��N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "SoundObject.h"
#include <map>
#include <string>

//=============================================================================
//class
//=============================================================================
//[desc]
//	�T�E���h�Ǘ��p�N���X
//=============================================================================
class CSoundManager
{
	private:
		
		map< string, sp<CSoundObject> > m_mapSound;///<@brief �T�E���h�}�b�v
	
	public:
	
		/**
		* @brief �R���X�g���N�^
		*/		
		CSoundManager(void);
		
		/**
		* @brief �f�X�g���N�^
		*/		
		~CSoundManager(void);
		
		/**
		* @brief �T�E���h���X�g�ւ̒ǉ�
		* @param pDataName �f�[�^��
		* @param spSoundObj �T�E���h�I�u�W�F�N�g
		*/
		void AppendSoundList( const char *pDataName, sp<CSoundObject> spSoundObj );
		
		/**
		* @brief �T�E���h�̍Đ�
		* @param pDataName �Đ�����f�[�^��
		*/
		void Play( const char *pDataName );
		
		/**
		* @brief �T�E���h�̒�~
		* @param pDataName ��~����f�[�^��
		*/
		void Stop( const char *pDataName );
		
		/**
		* @brief �T�E���h�̃{�����[���ݒ�
		* @param pDataName �ݒ肷��f�[�^��
		* @param fVolume �ݒ肷�鉹��
		*/
		void SetVolume( const char *pDataName, float fVolume );
		
};
