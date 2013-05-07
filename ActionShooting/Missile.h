//*============================================================================
//Missile.h
//*============================================================================
/**
* 誘導弾クラス
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "Bullet.h"

//=============================================================================
//class
//=============================================================================
class CMissile :	public CBullet
{
	private:
	
		static int m_BulletNum;///<@brief 弾の数
		
		Math::Vector2D m_TargetPos;///<@brief ターゲットの位置
		
	public:
	
		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		* @param pDataName データ名
		* @param vPos 設定する位置
		*/
		CMissile( const char *pName, const char *pDataName, Math::Vector2D vPos );
		
		/**
		* @brief デストラクタ
		*/
		virtual ~CMissile(void);
		
		/**
		* @brief 移動処理
		*/
		void Move();
		
		/**
		* @brief 当たった時の処理
		* @param spObj 判定するオブジェクト
		*/
		virtual void HitExec( sp<CGameObject> spObj );
		
		///**
		//* @brief 移動補正
		//*/
		//void MoveAdjust();
		
		/**
		* @brief 現在の弾の数の取得
		* @return 現在の弾の数
		*/
		static int GetBulletNum()
		{
			return m_BulletNum;
		}
};
