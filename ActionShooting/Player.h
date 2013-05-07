//*============================================================================
//Player.h
//*============================================================================
/**
* プレイヤークラス
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "character.h"
#include <vector>

//=============================================================================
//const
//=============================================================================
const int SHADOW_NUM = 4;


//=============================================================================
//class
//=============================================================================
class CPlayer :	public CCharacter
{
	private:
	
		enum ePlayerState
		{
			STATE_NONE,//何もない状態
			STATE_SHOOTING, //弾を撃っている状態
			STATE_INVINCIBLE, //無敵状態
			STATE_HYPERMODE,//ハイパーモード
			STATE_DIED,//死んだ状態
		};///<@brief キャラクターの状態
		
		enum ePlayerAnim
		{
			ANIM_STAND,
			ANIM_FRONT,
			ANIM_BACK,
			ANIM_SLASH1,
			ANIM_SLASH2,
			ANIM_SLASH3,	
		};///<@brief プレイヤーアニメーション
		
		
		Sint32 m_Stock;///<@brief 残りストック数
		Sint32 m_HitNum;///<@brief ヒット数
		
		Sint32 m_HitCount;///<@brief ヒットカウンター
		Sint32 m_InvTime;///<@brief 無敵時間
		
		Sint32 m_Time;///@brief 汎用カウンター
		
		Sint32 m_SwordTime;///@brief ソード時間

		Math::Point2DI m_AdjustSize;///@brief 補正サイズ
		
		vector<Uint32> m_vecAnimNum;///<@brief アニメーション数
		vector<Uint32> m_vecAnimTime;///<@brief アニメーション数
		
		Sint32 m_ShootCount;
		Sint32 m_Count;
		
		bool m_IsShoot;///<@brief 弾発射判定フラグ
		bool m_IsSlash;///<@brief 斬撃中か
		bool m_IsMove;

		bool m_IsNoSword;///<@brief ソードの入力を受け付けるか


		static bool m_IsHyperMode;///< @brief 覚醒モード中か
		static bool m_IsSlashEnd;
		
		//bool m_IsDemo;///<@brief デモ中か
		
		ePlayerState m_eState;///<@brief キャラの状態
		
		static float m_fGaugeAdd;///<@brief ゲージ増加値
		static float m_fGaugeAddShot;///<@brief ゲージ増加値(ショット)
		float m_fGaugeSub;///<@brief 覚醒モード時のゲージ減少値)
		
		Sint32 m_ShadowNum;///<@brief 残像数

		Math::Vector2D m_vShadowPos[SHADOW_NUM];
		CColor m_ShadowColor[SHADOW_NUM];

		vector<Math::Vector2D> m_vecShadowPos;///<@brief 残像位置

		vector<CColor> m_vecColor;///<@brief 残像色

		




	public:
		
		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		* @param pDataName データ名
		*/
		CPlayer( const char *pName, const char *pDataName );
		
		/**
		* @brief デストラクタ
		*/
		~CPlayer(void);
		
		/**
		 * @brief 初期化
		 */
		void Init(){};

		/**
		* @brief 処理
		*/
		void Exec();
		
		/**
		 * @brief 描画リクエスト
		 */
		virtual void DrawRequest();

		/**
		* @brief パラメーターの読み込み
		* @param pFileName ファイル名
		*/
		void LoadParameter( const char *pFileName );
		
		/**
		 * @brief レンダリング
		 */
		void Rendering();

		/**
		* @brief 移動処理
		*/
		void Move();
		
		/**
		* @brief ショット処理
		*/
		void Shoot();
		
		/**
		* @brief 近接攻撃処理
		*/
		void Attack();
		
		/**
		 * @brief ハイパーモードの処理
		 */
		void HyperModeExec();

		/**
		* @brief アニメーションの設定
		*/
		void SetAnimation();
		
		
		/**
		* @brief 移動補正
		*/
		void MoveAdjust();
		
		/**
		* @brief ストックの描画
		*/
		void DrawStock();
		
		/**
		* @brief 当たった時の処理
		* @param spObj 判定するオブジェクト
		*/
		virtual void HitExec( sp<CGameObject> spObj );
		
		/**
		* @brief 状態毎の処理
		*/
		virtual void StateExec();
		


	public:


		/**
		 * @brief デモフラグの設定
		 */
		//void SetDemoFlag( const bool flag )
		//{
		//	m_IsDemo = flag;
		//}

		/**
		 * 覚醒状態フラグの設定
		 * @param flag 覚醒フラグ
		 */
		void SetHyperFlag( const bool flag )
		{
			m_IsHyperMode = flag;
		}

	public:
	
		Sint32 GetStock() const
		{
			return m_Stock;
		}
		
		/**
		 * @brief ゲージ増加値の取得
		 * @return　ゲージ増加値
		 */
		static float GetGaugeAdd()
		{
			return m_fGaugeAdd;
		}

		/**
		 * @brief ゲージ増加値の取得
		 * @return　ゲージ増加値
		 */
		static float GetGaugeAddShot()
		{
			return m_fGaugeAddShot;
		}

		/**
		 * @brief ハイパーモードの取得
		 * @return　ハイパーモードか
		 */
		static bool GetHyperMode()
		{
			return m_IsHyperMode;
		}



};
