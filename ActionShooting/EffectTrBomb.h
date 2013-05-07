//*============================================================================
//EffectTrBomb.h
//*============================================================================
/**
* エフェクト(誘爆)クラス
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "EffectBomb.h"

//=============================================================================
//class
//=============================================================================
class CEffectTrBomb :	public CEffectBomb
{
	private:

	public:

		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		* @param pDataName データ名
		* @param vPos 設定する位置
		*/
		CEffectTrBomb( const char *pName, const char *pDataName, Math::Vector2D vPos );

		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		* @param pDataName データ名
		* @param vPos 設定する位置
		*/
		CEffectTrBomb( const char *pName, const char *pDataName, CGameObject *pObj );


		/**
		* @brief デストラクタ
		*/
		~CEffectTrBomb(void);


		/**
		* @brief 状態毎の処理
		*/
//		virtual void StateExec();


	//Set系
	public:



	//Get系
	public:


};
