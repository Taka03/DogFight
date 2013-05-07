//*============================================================================
//gameobject.h
//*============================================================================
/**
* ゲームオブジェクトクラス
*/

#pragma once

//=============================================================================
//include
//=============================================================================
#include "CommonObject.h"
#include <string>

//=============================================================================
//variable
//=============================================================================
class CGameObject;

//=============================================================================
//namespace
//=============================================================================
using namespace std;

//=============================================================================
//class
//=============================================================================
//[desc]
//	ゲームオブジェクト用クラス
//=============================================================================
class CGameObject 
{
	public:
	
		//オブジェクトタイプ
		enum eObjectType
		{
			TYPE_PLAYER,//プレイヤー
			TYPE_ENEMY,//敵
			TYPE_BULLET,//プレイヤーの弾
			TYPE_EBULLET,//敵の弾
			TYPE_MISSILE,//ミサイル
			TYPE_SWORD_WEAK,//剣エフェクト(弱)
			TYPE_SWORD_STRONG,//剣エフェクト(強)
			TYPE_BOMB,//ボム
		};
	
	protected:
	
		string m_strFileName;///<@brief ファイル名
		
		string m_strDataName;///<@brief データ
		
		bool m_IsStop;///<@brief 静止判定フラグ
		bool m_IsVisible;///<@brief 表示判定フラグ
		bool m_IsRemoved;///<@brief 削除判定フラグ
		
		eObjectType m_eType;///<@brief オブジェクトタイプ
		
	public:
	
		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		*/
		CGameObject( const char *pName );
		
		/**
		* @brief デストラクタ
		*/
		virtual ~CGameObject();
		
		/**
		* @brief 初期化
		*/
		virtual void Init() = 0;
		
		
		/**
		* @brief 処理
		*/
		virtual void Exec() = 0;
		
		/**
		* @brief レンダリング処理
		*/
		virtual void Rendering() = 0;
		
		/**
		* @brief 当たり判定処理
		* @param spObj 判定するオブジェクト
		*/
		virtual bool HitCheck( sp<CGameObject> spObj ) = 0;
		
		
		/**
		* @brief 当たった時の処理
		* @param spObj 判定するオブジェクト
		*/
		virtual void HitExec( sp<CGameObject> spObj ) = 0;
		
		
		/**
		* @brief ファイル読み込み
		*/
		virtual bool Load() = 0;
		
		/**
		* @brief パラメーター読み込み
		*/
		virtual void LoadParameter( const char *pDataName ){};
		
	/*Set系*/
	public:
	
		//データ名の設定
		void SetDataName( string strDataName )
		{
			m_strDataName = strDataName;
		}
		
		/**
		* @brief 表示フラグの設定
		* @param IsVisible 設定する表示フラグ
		*/
		void SetVisibleFlag( bool IsVisible )
		{
			m_IsVisible = IsVisible;
		}
		
		/**
		* @brief 静止フラグの設定
		* @param IsStop 設定する静止フラグ
		*/
		void SetStopFlag( bool IsStop )
		{
			m_IsStop = IsStop;
		}
		
		/**
		* @brief 削除フラグの取得
		* @param IsRemoved 判定する削除フラグ
		*/
		void SetRemoveFlag( bool IsRemoved )
		{
			m_IsRemoved = IsRemoved;
		}
		
		/**
		* @brief キャラクター状態の設定
		* @param eState 設定するキャラクター状態
		*/
		//void SetState( eCharaState eState )
		//{
		//	m_eState = eState;
		//}
		
		
		
	/*Get系*/
	public:
	
		/**
		* @brief ファイル名の取得
		* @return ファイル名
		*/
		string GetFileName() const
		{
			return m_strFileName;
		}
		
		/**
		* @brief データ名の取得
		* @return データ名
		*/
		string GetDataName() const
		{
			return m_strDataName;
		}
		
		/**
		* @brief 表示フラグの取得
		* @return 表示フラグ
		*/
		bool GetVisibleFlag() const
		{
			return m_IsVisible;
		}
		
		/**
		* @brief 静止フラグの取得
		* @return 静止フラグ
		*/
		bool GetStopFlag() const
		{
			return m_IsStop;
		}
		
		/**
		* @brief 削除フラグの取得
		* @return 削除フラグ
		*/
		bool GetRemoveFlag() const
		{
			return m_IsRemoved;
		}
		
		/**
		* @brief オブジェクトタイプの取得
		* @return オブジェクトタイプ
		*/
		eObjectType GetType() const
		{
			return m_eType;
		}
		
		/**
		* @brief 当たり判定領域の取得
		* @return 当たり判定領域
		*/
		virtual Math::Rect2DF GetHitRect() const
		{ 
			return Math::Rect2DF( 0, 0, 0, 0 ); 
		};
		
		
};
