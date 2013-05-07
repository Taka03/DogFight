//*============================================================================
//SceneGameOver.h
//*============================================================================
/**
* ゲームオーバークラス
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "SceneBase.h"

//=============================================================================
//class
//=============================================================================
class CSceneGameOver :public CSceneBase
{
	private:

	
	
	public:
	
		/**
		* @brief コンストラクタ
		* @param pDataName データファイル名
		*/
		CSceneGameOver( const char *pDataName );
		
		/**
		* @brief デストラクタ
		*/
		virtual ~CSceneGameOver(void);
		
		/**
		* @brief 初期化
		*/
		virtual void Init();
		
		/**
		* @brief 待機中
		*/
		virtual void Idle();
		
		/**
		 * @brief 名前入力
		 */
		//virtual void InputName();



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
