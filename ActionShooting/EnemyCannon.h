//*============================================================================
//EnemyCannon.h
//*============================================================================
/**
* 敵(砲台)クラス
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "enemy.h"

//=============================================================================
//class
//=============================================================================
class CEnemyCannon :	public CEnemy
{
	private:
	
		//sp<CGameObject> m_spTargetObj;
		CGameObject *m_pTargetObj;
	
	public:
		
		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		* @param pDataName データ名
		* @param vPos 設定する位置
		*/
		CEnemyCannon( const char *pName, const char *pDataName, Math::Vector2D vPos );
		
		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		* @param pDataName データ名
		* @param vPos 設定する位置
		*/
		CEnemyCannon( const char *pName, const char *pDataName, CGameObject *pObj );
		
		
		/**
		* @brief デストラクタ
		*/
		~CEnemyCannon(void);
		
		/**
		* @brief 移動処理
		*/
		void Move();
		
		void MoveAdjust(){};
		
		/**
		* @brief ショット処理
		*/
		//void Shoot();
		
		
};
