//*============================================================================
//EffectShot.h
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
class CEffectShot :	public CEffect
{
	private:

		int m_ExistCount;///<@brief 存在カウンター
		int m_ShotCount;

	public:

		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		* @param pDataName データ名
		* @param vPos 設定する位置
		*/
		CEffectShot( const char *pName, const char *pDataName, Math::Vector2D vPos );

		/**
		* @brief デストラクタ
		*/
		~CEffectShot(void);

		/**
		* @brief 処理
		*/
		void Exec();

		/**
		 *
		 */
		virtual void SetAnimation();

		/**
		* @brief 状態毎の処理
		*/
//		virtual void StateExec();


	//Set系
	public:



	//Get系
	public:


};
