//*============================================================================
//EffectFire.h
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
class CEffectFire :	public CEffect
{
	private:

		int m_ExistCount;///<@brief 存在カウンター
		CGameObject *m_pTargetObj;

	public:

		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		* @param pDataName データ名
		* @param vPos 設定する位置
		*/
		CEffectFire( const char *pName, const char *pDataName, Math::Vector2D vPos );

		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		* @param pDataName データ名
		* @param vPos 設定する位置
		*/
		CEffectFire( const char *pName, const char *pDataName, CGameObject *pObj );


		/**
		* @brief デストラクタ
		*/
		~CEffectFire(void);

		/**
		* @brief 処理
		*/
		void Exec();

		/**
		* @brief 状態毎の処理
		*/
//		virtual void StateExec();


	//Set系
	public:



	//Get系
	public:


};
