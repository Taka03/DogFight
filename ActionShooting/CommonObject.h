//*============================================================================
//CommonObject.h
//*============================================================================
/**
* 共通オブジェクトクラス
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "common.h"

//=============================================================================
//variable
//=============================================================================
class CGameSceneManager;
class CSoundManager;
class CResourceManager;
class CApplication;
class CJoyPad;

//=============================================================================
//class
//=============================================================================
//[Desc]
//	共通オブジェクト用クラス
//=============================================================================
class CCommonObject
{
	public:
	
		/**
		* @brief コンストラクタ
		*/
		CCommonObject(void);
		
		/**
		* @brief デストラクタ
		*/
		~CCommonObject(void);
		
	private:
	
		static CApplication *m_pApp;///<@brief アプリケーションクラス
		static CResourceManager *m_pResMgr;///<@brief リソース管理クラス
		static CSoundManager *m_pSndMgr;///<@brief サウンド管理クラス
		static CGameSceneManager *m_pGameSceneMgr;///<@brief ゲームシーン管理クラス
		static CJoyPad *m_pJoyPad;///<@brief ジョイパッドクラス
		
	public:
	
		/**
		* @brief 初期化処理
		*/
		static void Initialize();
		
		/**
		* @brief 終了処理
		*/
		static void Finalize();
	
	public:
	
		/*サウンド管理クラスの取得*/
		static CSoundManager *GetSoundMgr(); 
		
		/**
		* @brief リソース管理クラスの取得
		* @return リソース管理クラス
		*/		
		static CResourceManager *GetResMgr();
		
		/**
		* @brief アプリケーションクラスの取得
		* @return アプリケーションクラス
		*/		
		static CApplication *GetAppli();
		
		////マウスクラスの取得
		//static CMouse *GetMouse();
		
		/**
		* @brief ジョイパッドクラスの取得
		* @return ジョイパッドクラス
		*/		
		static CJoyPad *GetJoyPad();
		
		/**
		* @brief ゲームシーンマネージャの取得
		* @return ゲームシーンマネージャ
		*/		
		static CGameSceneManager *GetGameSceneMgr();
};
