//*============================================================================
//SoundFactory.h
//*============================================================================
//[author]
//	Taka
//=============================================================================
#pragma once

//=============================================================================
//include
//=============================================================================
#include "SoundObject.h"

//=============================================================================
//variable
//=============================================================================
class CFileData;

//=============================================================================
//class
//=============================================================================
//[Desc]
//	�T�E���h�t�@�N�g���[�N���X
//=============================================================================
class CSoundFactory
{
	public:

		//�R���X�g���N�^
		CSoundFactory(void){};
		
		//�f�X�g���N�^
		~CSoundFactory(void){};
		
		//�T�E���h�̎擾
		static CSoundObject *GetSound( CFileData *pFile );
};