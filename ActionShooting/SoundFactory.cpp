//*============================================================================
//SoundFactory.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "SoundFactory.h"
#include "SoundEffect.h"
#include "BGM.h"
#include "FileData.h"

//============================================================================
//�T�E���h�̎擾
//============================================================================
//[input]
//	pFile:�t�@�C���f�[�^
//[return]
//	�擾�����T�E���h
//===========================================================================
CSoundObject *CSoundFactory::GetSound( CFileData *pFile )
{
	string strDataName = pFile->GetTypeName();
	
	//���ʉ��̏ꍇ
	if( strDataName == "SE" )
	{
		return new CSoundEffect( pFile->GetFileName().c_str() );
	}
	
	else if( strDataName == "BGM" )
	{
		return new CBGM( pFile->GetFileName().c_str() );
	}
	
	return NULL;
	
}

