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
//サウンドの取得
//============================================================================
//[input]
//	pFile:ファイルデータ
//[return]
//	取得したサウンド
//===========================================================================
CSoundObject *CSoundFactory::GetSound( CFileData *pFile )
{
	string strDataName = pFile->GetTypeName();
	
	//効果音の場合
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

