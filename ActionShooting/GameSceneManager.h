//*============================================================================
//GameSceneManager.h
//*============================================================================
/**
* ゲームシーン管理クラス
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "SceneBase.h"
#include <map>

//=============================================================================
//class
//=============================================================================
class CGameSceneManager
{
	private:
	
		sp<CSceneBase> m_spCurScene;///<@brief 現在のシーン
		sp<CSceneBase> m_spNextScene;///<@brief 次のシーン
		//eSceneState m_eSceneState;///<@brief シーンの状態
		
		bool m_IsDemo;///<@brief デモ中か
		
	public:
		
		/**
		* @brief コンストラクタ
		*/
		CGameSceneManager( );
		
		/**
		* @brief デストラクタ
		*/
		~CGameSceneManager();
		
		/**
		* @brief 更新
		*/
		void Update();
		
		
	public:
	
		/**
		* @brief 現在のシーンの設定
		* @param pScene シーン
		*/
		void SetCurrentScene( CSceneBase *pScene );
		
		/**
		* @brief 次のシーンの設定
		* @param pScene シーン
		*/
		void SetNextScene( CSceneBase *pScene );
		
		/**
		 *
		 * @brief デモフラグの設定
		 * @param IsDemo デモフラグ
		 */
		void SetDemoFlag( const bool IsDemo )
		{
			m_IsDemo = IsDemo;
		}
		
	public:

		/**
		 * デモフラグの取得
		 * @return デモフラグ
		 */
		bool GetDemoFlag() const
		{
			return m_IsDemo;
		}

};
