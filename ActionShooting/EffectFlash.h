//*============================================================================
//EffectFlash.h
//*============================================================================
/**
* エフェクト(点滅)クラス
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "Effect.h"

//=============================================================================
//class
//=============================================================================
class CEffectFlash :	public CEffect
{
	private:
	
		int m_ExistCount;///<@brief 存在カウンター
		
	public:
		
		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		* @param pDataName データ名
		* @param vPos 設定する位置
		*/
		CEffectFlash( const char *pName, const char *pDataName, Math::Vector2D vPos );
		
		/**
		* @brief デストラクタ
		*/
		~CEffectFlash(void);
		
		/**
		* @brief 処理
		*/
		void Exec();
		
		/**
		* @brief 当たった時の処理
		* @param spObj 判定するキャラ
		*/
		virtual void HitExec( sp<CGameObject> spObj );
		
		/**
		* @brief 状態毎の処理
		*/
//		virtual void StateExec();
		
	
	//Set系
	public:
		
		
		
	//Get系
	public:
	
		
};
