//*============================================================================
//Character.h
//*============================================================================
/**
* 弾クラス
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "character.h"

//=============================================================================
//class
//=============================================================================
class CBullet :	public CCharacter
{
	public:
	
		enum eBulletState
		{
			STATE_NONE,//何もない状態
			STATE_DIED,//死亡状態
		};///<@brief 弾の状態
	
	private:
	
		static int m_BulletNum;///<@brief 弾の数
		
	protected:
	
		eBulletState m_eState;///<@brief 弾の状態
		
	public:
		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		* @param pDataName データ名
		* @param vPos 設定する位置
		*/
		CBullet( const char *pName, const char *pDataName, Math::Vector2D vPos );
		
		/**
		* @brief デストラクタ
		*/
		virtual ~CBullet(void);
		
		/**
		* @brief 移動処理
		*/
		void Move();
		
		/**
		 * 処理
		 */
		//void Exec();

		/**
		* @brief 当たった時の処理
		* @param spObj 判定するオブジェクト
		*/
		virtual void HitExec( sp<CGameObject> spObj );
		
		/**
		* @brief 状態処理
		*/
		virtual void StateExec(){};
		
		/**
		* @brief 移動補正
		*/
		void MoveAdjust();
		
		/**
		* @brief 現在の弾の数の取得
		* @return 現在の弾の数
		*/
		static int GetBulletNum()
		{
			return m_BulletNum;
		}
};
