//*============================================================================
//BGM.h
//*============================================================================
/**
* BGMクラス。
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
//	BGM再生用クラス
//=============================================================================
class CBGM :	public CSoundObject
{
	private:
	
		Sound::IStreamSound *m_pBGM;///<@brief BGM再生用デバイス
	
	public:
	
		/**
		* @brief コンストラクタ
		* @param pName データ名
		*/
		CBGM( const char *pName );
		
		/**
		* @brief デストラクタ
		*/
		virtual ~CBGM(void);
		
		/**
		* @brief 音の読み込み
		*/
		virtual bool Load();
		
		//再生
		//void Play( Sound::SPlayBlock *pTbl, int count );
		
		/**
		* @brief 音の再生
		*/
		void Play();
		
		/**
		* @brief 音の停止
		*/
		void Stop();
		
		
		/**
		* @brief フェードアウト
		*/
		void FadeOut();
		
	/*Get系*/
	public:

		/**
		* @brief BGMデバイスの取得
		* @return BGMデバイス
		*/
		Sound::IStreamSound *GetBGMDevice() const
		{
			return m_pBGM;
		}
		
};
