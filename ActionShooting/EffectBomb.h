//*============================================================================
//EffectBomb.h
//*============================================================================
/**
* エフェクト(爆発)クラス
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "Effect.h"

//=============================================================================
//class
//=============================================================================
class CEffectBomb :	public CEffect
{
	private:
	
		int m_ExistCount;///<@brief 存在カウンター
		CGameObject *m_pEnemyObj;///@brief 敵オブジェクト(消去用)
		
	public:
		
		static Uint32 m_Cnt;

	
	public:
		
		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		* @param pDataName データ名
		* @param vPos 設定する位置
		*/
		CEffectBomb( const char *pName, const char *pDataName, Math::Vector2D vPos );
		
		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		* @param pDataName データ名
		* @param vPos 設定する位置
		*/
		CEffectBomb( const char *pName, const char *pDataName, CGameObject *pObj );
		
		
		/**
		* @brief デストラクタ
		*/
		~CEffectBomb(void);
		
		/**
		* @brief 処理
		*/
		void Exec();
		
		/**
		* @brief 当たった時の処理
		* @param spObj 判定するキャラ
		*/
		virtual void HitExec( sp<CGameObject> spObj);
		
		/**
		* @brief 状態毎の処理
		*/
//		virtual void StateExec();
		
	
	//Set系
	public:
		
		
		
	//Get系
	public:
	
		
};
