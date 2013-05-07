//*============================================================================
//EnemyMiddle1.h
//*============================================================================
/**
* 敵(中型機1)クラス
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "enemy.h"

//=============================================================================
//class
//=============================================================================
class CEnemyMiddle1 :	public CEnemy
{
	private:
	
		static Uint32 m_ExistNum;///<@brief 出現敵数
		
		Uint32 m_ID;///<@brief 識別番号
		
		//CEnemyCannon
		
	public:
		
		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		* @param pDataName データ名
		* @param vPos 設定する位置
		*/
		CEnemyMiddle1( const char *pName, const char *pDataName, Math::Vector2D vPos );
		
		/**
		* @brief デストラクタ
		*/
		~CEnemyMiddle1(void);
		
		/**
		* @brief 移動補正
		*/
		void MoveAdjust();
		
		/**
		* @brief 状態処理
		*/
		//void StateExec();
		
		
	public:
	
		/**
		* @brief 出現敵数の取得
		* @return 出現敵数
		*/
		static int GetExistNum()
		{
			return m_ExistNum;
		}
		
		
};
