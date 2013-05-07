//*============================================================================
//SceneTutorial.h
//*============================================================================
/**
* チュートリアルクラス
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "SceneBase.h"

//=============================================================================
//class
//=============================================================================
class CSceneTutorial :public CSceneBase
{
	private:

			Sint32 m_PushCount;


	public:

		/**
		* @brief コンストラクタ
		* @param pDataName データファイル名
		*/
		CSceneTutorial( const char *pDataName );

		/**
		* @brief デストラクタ
		*/
		virtual ~CSceneTutorial(void);

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
