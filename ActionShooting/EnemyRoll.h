//*============================================================================
//EnemyRoll.h
//*============================================================================
/**
* 敵(回転する)クラス
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "enemy.h"

//=============================================================================
//class
//=============================================================================
class CEnemyRoll :	public CEnemy
{
	private:
	
		Sint32 m_Scroll;///<@brief スクロール
		Sint32 m_ScrollY;
	
	public:
		
		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		* @param pDataName データ名
		* @param vPos 設定する位置
		*/
		CEnemyRoll( const char *pName, const char *pDataName, Math::Vector2D vPos );
		
		/**
		* @brief デストラクタ
		*/
		~CEnemyRoll(void);
		
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
