//*============================================================================
//EffectPhoton.h
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
class CEffectPhoton :	public CEffect
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
		CEffectPhoton( const char *pName, const char *pDataName, Math::Vector2D vPos );

		/**
		* @brief デストラクタ
		*/
		~CEffectPhoton(void);


		/**
		 * @brief レンダリング
		 */
		void Rendering();

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
