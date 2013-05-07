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
#include <vector>

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
			TYPE_BLOWENEMY,//吹き飛ばされている敵
			TYPE_BULLET,//プレイヤーの弾
			TYPE_EBULLET,//敵の弾
			TYPE_MISSILE,//ミサイル
			TYPE_SWORD_WEAK,//剣エフェクト(弱)
			TYPE_SWORD_STRONG,//剣エフェクト(強)
			TYPE_BOMB,//ボム
			TYPE_CHAINBOMB,//誘爆ボム
		};
	
	protected:
	
		Math::Vector2D m_vPos;///<@brief 位置
		Sint32 m_Angle;///<@brief 回転角度
		Math::Point2DF m_fScale;///<@brief 拡縮率
		
		Math::Vector2D m_vInitPos;///<@brief 初期位置
		Sint32 m_InitAngle;///<@brief 初期角度
		Math::Point2DF m_fInitScale;///<@brief 初期拡縮率
	
		string m_strFileName;///<@brief ファイル名
		
		string m_strDataName;///<@brief データ名
		
		bool m_IsStop;///<@brief 静止判定フラグ
		bool m_IsVisible;///<@brief 表示判定フラグ
		bool m_IsRemoved;///<@brief 削除判定フラグ
		
		bool m_IsRemEnd;///<@brief シーン終了と同時に削除するか

		bool m_IsHit;///<@brief 当たり判定フラグ
		
		eObjectType m_eType;///<@brief オブジェクトタイプ
		
		sp<CGameObject> m_spTargetObj;///@brief ターゲットオブジェクト
		
	public:
	
		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		* @param pDataName データファイル名
		*/
		CGameObject( const char *pName, const char *pDataName );
		
		/**
		 * @brief コンストラクタ
		 * @param vecStr
		 * @return
		 */
		CGameObject( vector<string> vecStr );

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
		void SetDataName( const string strDataName )
		{
			m_strDataName = strDataName;
		}
		
		/**
		* @brief 表示フラグの設定
		* @param IsVisible 設定する表示フラグ
		*/
		void SetVisibleFlag( const bool IsVisible )
		{
			m_IsVisible = IsVisible;
		}
		
		/**
		* @brief 静止フラグの設定
		* @param IsStop 設定する静止フラグ
		*/
		void SetStopFlag( const bool IsStop )
		{
			m_IsStop = IsStop;
		}
		
		/**
		* @brief 削除フラグの設定
		* @param IsRemoved 判定する削除フラグ
		*/
		void SetRemoveFlag( const bool IsRemoved )
		{
			m_IsRemoved = IsRemoved;
		}
		
		/**
		 * @brief シーンと同時に削除するかフラグの設定
		 * @param IsEnd　シーンと同時に削除するかフラグ
		 */
		void SetRemEndFlag( const bool IsEnd )
		{
			m_IsRemEnd = IsEnd;
		}

		/**
		* @brief 位置の設定
		* @param vPos 設定する位置
		*/
		void SetPosition( const Math::Vector2D vPos )
		{
			m_vPos = vPos;
		}
	
		/**
		* @brief 回転角度の設定
		* @param Angle 設定する角度
		*/
		void SetAngle( const Sint32 Angle )
		{
			m_Angle = Angle;
		}
		
		//描画する文字の設定		
		virtual void SetDrawString( string str ){};
		
		void SetHitFlag( bool flag )
		{
			m_IsHit = flag;
		}
		
		void SetTargetObj( sp<CGameObject> spObj )
		{
			m_spTargetObj = spObj;
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
		* @brief 位置の取得
		* @return 位置
		*/
		Math::Vector2D GetPos() const
		{
			return m_vPos;
		}
		
		/**
		* @brief 回転角度の取得
		* @return 回転角度
		*/
		Sint32 GetAngle() const
		{
			return m_Angle;
		}
		
		/**
		* @brief 拡縮の取得
		* @return 拡縮
		*/
		Math::Point2DF GetScale() const
		{
			return m_fScale;
		}
		
		/**
		* @brief 初期位置の取得
		* @return 初期位置
		*/
		Math::Vector2D GetInitPos() const
		{
			return m_vInitPos;
		}
	
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
		 * @brief シーンと同時に削除するかフラグの取得
		 * @return シーンと同時に削除するかフラグ
		 */
		bool GetRemEndFlag() const
		{
			return m_IsRemEnd;
		}

		/**
		* @brief 当たり判定フラグの取得
		* @return 当たり判定フラグ
		*/
		bool GetHitFlag() const
		{
			return m_IsHit;
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
		
		sp<CGameObject> GetTargetObj() const
		{
			return m_spTargetObj;
		}
		
		virtual bool GetBlowFlag() const
		{
			return false;
		}
		
		virtual void SubLife( int Life )
		{
			
		}
		
		
};
