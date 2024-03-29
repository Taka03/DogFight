//*============================================================================
//SoundObject.h
//*============================================================================
/**
* サウンドオブジェクト
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "common.h"

//=============================================================================
//class
//=============================================================================
class CSoundObject
{
	protected:
	
		string m_strFileName;///<@brief ファイル名
	
	public:
	
		/**
		* @brief コンストラクタ
		* @param pName データ名
		*/
		CSoundObject( const char *pName );
		
		/**
		* @brief デストラクタ
		*/
		virtual ~CSoundObject(void);
		
		
	public:
	
		/**
		* @brief 音の再生
		*/
		virtual void Play() = 0;
		
		/**
		* @brief 音の停止
		*/
		virtual void Stop() = 0;
		
		/**
		* @brief 音の読み込み
		*/
		virtual bool Load( ) = 0;
		
		
	
};
