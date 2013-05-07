//*============================================================================
//EnemyCurve.h
//*============================================================================
/**
* 敵(カーブ)クラス
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "enemy.h"

//=============================================================================
//class
//=============================================================================
class CEnemyCurve :	public CEnemy
{
	private:
	
		Sint32 m_RollAngle;///<@brief 回転角度
		bool m_IsShoot;///<@brief ショット判定フラグ
		Uint32 m_ShotNum;///<@brief ショット数
		Uint32 m_StreamCount;///<@brief 連撃間隔
	
	public:
		
		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		* @param pDataName データ名
		* @param vPos 設定する位置
		*/
		CEnemyCurve( const char *pName, const char *pDataName, Math::Vector2D vPos );
		
		/**
		* @brief デストラクタ
		*/
		~CEnemyCurve(void);
		
		/**
		* @brief 移動処理
		*/
		void Move();
		
		/**
		* @brief ショット処理
		*/
		void Shoot();
		
		/**
		* @brief 移動補正
		*/
		void MoveAdjust();
		
	public:
	
		/**
		* @brief キャラクター状態の設定
		* @param eState 設定するキャラクター状態
		*/
		void SetState( eEnemyState eState )
		{
			m_eState = eState;
		}
	
};
