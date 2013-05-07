//*============================================================================
//enemy.h
//*============================================================================
/**
* 敵クラス
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "character.h"

//=============================================================================
//class
//=============================================================================
class CEnemy :	public CCharacter
{
	
	protected:
	
		enum eEnemyState
		{
			STATE_NONE,//何もない状態
			STATE_DAMAGE_SHOT,//ダメージを受けている状態(ショット)
			STATE_DAMAGE_SWORD_W,//ダメージを受けている状態(弱)
			STATE_DAMAGE_SWORD_S,//ダメージを受けている状態(強)
			STATE_DAMAGE_BOMB,////ダメージを受けている状態(ボム)
			STATE_DIED,//死んだ状態
		};///<@brief キャラクターの状態
		
		enum eMovePat
		{
			MOVE_STRAIGHT,//直進
			MOVE_ROLL, //回転
			MOVE_CURVE, //カーブ
			MOVE_AIMING, //自機狙い
		};///<@brief 移動パターン
		
		enum eShotPat
		{
			SHOT_NONE, //弾を撃たない
			SHOT_STRAIGHT,//直進弾
			SHOT_AIMSHOOT, //自機狙い弾
			SHOT_MISSILE, //誘導弾
		};///<@brief ショットパターン
		
		enum eEnemyType
		{
			TYPE_SMALL,
			TYPE_MIDDLE,
		};///<@brief 敵のタイプ
		
		
	protected:
	
		int m_ShootCount;///<@brief 弾を撃ち出すカウンター
		int m_Score;///<@brief スコア
		Sint32 m_Scroll;///<@brief スクロール
		Sint32 m_Life;///<@brief ライフ
		Sint32 m_StateTime;///<@brief 状態カウンター
		bool m_IsDamaged;///<@brief ダメージを受けているか
		bool m_IsBlowed;///@brief 吹き飛ばされているか
		bool m_IsDead;///@brief 死亡判定フラグ
		
		bool m_IsShoot;///<@brief ショット判定フラグ
		Uint32 m_ShotNum;///<@brief ショット数
		Uint32 m_MaxShot;///<@brief 最大ショット数
		Uint32 m_StreamCount;///<@brief 連撃カウンター
		Uint32 m_ShotTime;///<@brief 弾を出す時間
		
		Uint32 m_StreamTime;///<@brief 連撃時間
		
		Uint32 m_DeadTime;///@brief 死亡時間
		
		Uint32 m_BombDamage;///@brief 爆発ダメージ
		
		eEnemyState m_eState;///<@brief キャラの状態
		eMovePat m_eMovePat;///<@brief 移動パターン
		eShotPat m_eShotPat;///<@brief ショットパターン
		eEnemyType m_eEnemyType;///<@brief 敵のタイプ
		
		Sint32 m_RollAngle;///<@brief 回転角度
		
		Math::Vector2D m_vTargetPos;///<@brief ターゲットの位置
		
		bool m_IsSwordDamage;///<@brief 近距離攻撃でダメージを与えるか
		
		Sint32 m_DeadCount;///<@brief 死亡カウント

		bool m_IsSlash;///<@brief スラッシュ状態
		bool m_IsSlashEnd;///<@brief

	public:
		
		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		* @param pDataName データ名
		* @param vPos 設定する位置
		*/
		CEnemy( const char *pName, const char *pDataName, Math::Vector2D vPos );
		
		/**
		* @brief デストラクタ
		*/
		~CEnemy(void);
		
		/**
		* @brief 移動処理
		*/
		virtual void Move();
		
		/**
		* @brief ショット処理
		*/
		virtual void Shoot();
		
		/**
		* @brief 移動補正
		*/
		void MoveAdjust();
		
		/**
		* @brief パラメーターの読み込み
		* @param pFileName ファイル名
		*/
		void LoadParameter( const char *pFileName );
		
		/**
		* @brief 当たった時の処理
		* @param spObj 判定するオブジェクト
		*/
		virtual void HitExec( sp<CGameObject> spObj );
		
		/**
		* @brief 状態毎の処理
		*/
		virtual void StateExec();
		
		/**
		* @brief アニメーションの設定
		*/
		virtual void SetAnimation();
		
		
		
	//移動パターン
	public:
	
		/**
		* @brief 移動パターンの処理
		*/
		void MovePatExec();
	
		/**
		* @brief 直進
		*/
		void MovePatStraight();
		
		/**
		* @brief 回転
		*/
		void MovePatRoll();
		
		/**
		* @brief カーブ
		*/
		void MovePatCurve();
		
		/**
		* @brief 自機狙い
		*/
		void MovePatAiming();
		
	//弾のパターン
	public:
	
		/**
		* @brief 弾発射パターンの処理
		*/
		void ShotPatExec();
		
		/**
		* @brief 直進弾
		*/
		void ShotPatStraight();
		
		/**
		* @brief 自機狙い弾
		*/
		void ShotPatAimShoot();
		
		/**
		* @brief 誘導弾
		*/
		void ShotPatMissile();
		
	public:
	
		/**
		* @brief キャラクター状態の設定
		* @param eState 設定するキャラクター状態
		*/
		void SetState( eEnemyState eState )
		{
			m_eState = eState;
		}
		
		void SetLife( int Life )
		{
			m_Life = Life;
		}
		
		void SubLife( int Life )
		{
			m_Life -= Life;
		}
		
	public:
	
		bool GetBlowFlag() const
		{
			return m_IsBlowed;
		}
	
	
		
		
};
