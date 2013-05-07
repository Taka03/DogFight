//*============================================================================
//CSceneGameDemo.h
//*============================================================================
/**
* ゲームデモクラス
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "SceneBase.h"

//=============================================================================
//class
//=============================================================================
class CSceneGameDemo :public CSceneBase
{
	private:

		int m_SceneCounter;///<@brief シーンカウンター
		int m_SceneTime;///<@brief シーン移行時間

	public:

		/**
		* @brief コンストラクタ
		* @param pDataName データファイル名
		*/
		CSceneGameDemo( const char *pDataName );

		/**
		* @brief デストラクタ
		*/
		virtual ~CSceneGameDemo(void);

		/**
		* @brief 初期化
		*/
		virtual void Init();

		/**
		* @brief 待機中
		*/
		virtual void Idle();

		///**
		//* @brief 更新
		//* @return 現在のシーンの状態
		//*/
		//virtual eSceneState Update();
		//
		/**
		* @brief 終了
		*/
		virtual void End();


};
