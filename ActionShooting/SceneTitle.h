//*============================================================================
//SceneTitle.h
//*============================================================================
/**
* タイトルクラス
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "SceneBase.h"
#include "Sprite.h"

//=============================================================================
//class
//=============================================================================
class CSceneTitle :public CSceneBase
{
	private:

		CSprite *pSpr;

	protected:

		/**
		 * オブジェクトの追加
		 * @return オブジェクトの追加が終了したか
		 */
		virtual bool InitObject();

		/**
		* @brief 初期化
		*/
		virtual void Init();

		/**
		* @brief 待機中
		*/
		virtual void Idle();

		/**
		* @brief 終了
		*/
		virtual void End();
	
		
	
	public:
	
		/**
		* @brief コンストラクタ
		* @param pDataName データファイル名
		*/
		CSceneTitle( const char *pDataName );
		
		/**
		* @brief デストラクタ
		*/
		virtual ~CSceneTitle(void);
		
		
		
		///**
		//* @brief 更新
		//* @return 現在のシーンの状態
		//*/
		//virtual eSceneState Update();
		//
		
		

};
