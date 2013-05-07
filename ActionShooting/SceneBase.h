//*============================================================================
//SceneBase.h
//*============================================================================
/**
* シーン基本クラス
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "common.h"
#include <vector>
#include <map>

//=============================================================================
//variable
//=============================================================================
//class CGameObject;

//=============================================================================
//class
//=============================================================================
class CSceneBase
{
	public:
	
		enum eSceneState
		{
			SCENE_STANDBY,
			SCENE_FADEIN,
			SCENE_FADEOUT,
			SCENE_FINISH,
		};///<@brief シーン状態
		
	
	protected:
	
		map< string, sp<CGameObject> > m_mapResource;///<@brief リソースマップ

		void (CSceneBase::*m_pStateFunc)(void);///<@brief シーンの状態変化
		
		eSceneState m_eSceneState;///<@brief シーンの状態
		
		string m_ResName;///<@brief リソース名

	protected:
	
		/**
		* @brief リソースファイルの読み込み
		* @param pDataName データファイル名
		* @return ロードが完了したか
		*/
		bool LoadResourceFile( const char *pDataName );
		
		/**
		 * オブジェクトの追加
		 * @return オブジェクトの追加が終了したか
		 */
		virtual bool InitObject(){ return false; };


	public:

		/**
		* @brief コンストラクタ
		* @param pDataName データファイル名
		*/
		CSceneBase( const char *pDataName );

		/**
		* @brief デストラクタ
		*/
		virtual ~CSceneBase(void);

		/**
		* @brief 初期化
		*/
		virtual void Init() = 0;

		/**
		* @brief 待機中
		*/
		virtual void Idle() = 0;

		/**
		* @brief 終了
		*/
		virtual void End() = 0;

		
		
		/**
		* @brief 更新
		* @return 現在のシーンの状態
		*/
		eSceneState Update();
		
		
	public:
	
		/*状態のセット*/
		void SetState( void ( CSceneBase::*pState_Func )(void) )
		{
			m_pStateFunc = pState_Func;
		}
	
		
};
