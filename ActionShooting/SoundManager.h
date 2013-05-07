//*============================================================================
//SoundManager.h
//*============================================================================
/**
* サウンド管理クラス
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
//	サウンド管理用クラス
//=============================================================================
class CSoundManager
{
	private:
		
		map< string, sp<CSoundObject> > m_mapSound;///<@brief サウンドマップ
	
	public:
	
		/**
		* @brief コンストラクタ
		*/		
		CSoundManager(void);
		
		/**
		* @brief デストラクタ
		*/		
		~CSoundManager(void);
		
		/**
		* @brief サウンドリストへの追加
		* @param pDataName データ名
		* @param spSoundObj サウンドオブジェクト
		*/
		void AppendSoundList( const char *pDataName, sp<CSoundObject> spSoundObj );
		
		/**
		* @brief サウンドの再生
		* @param pDataName 再生するデータ名
		*/
		void Play( const char *pDataName );
		
		/**
		* @brief サウンドの停止
		* @param pDataName 停止するデータ名
		*/
		void Stop( const char *pDataName );
		
		/**
		* @brief サウンドのボリューム設定
		* @param pDataName 設定するデータ名
		* @param fVolume 設定する音量
		*/
		void SetVolume( const char *pDataName, float fVolume );
		
};
