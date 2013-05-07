//*============================================================================
//EffectSlash.h
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
class CEffectSlash :	public CEffect
{
	private:

		int m_ExistCount;///<@brief 存在カウンター
		CGameObject *m_pTargetObj;
		Math::Vector2D m_vEffPos;

	public:

		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		* @param pDataName データ名
		* @param vPos 設定する位置
		*/
		CEffectSlash( const char *pName, const char *pDataName, Math::Vector2D vPos );

		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		* @param pDataName データ名
		* @param vPos 設定する位置
		*/
		CEffectSlash( const char *pName, const char *pDataName, CGameObject *pObj );


		/**
		* @brief デストラクタ
		*/
		~CEffectSlash(void);

		/**
		* @brief 処理
		*/
		void Exec();

		/**
		 * @brief アニメーションの設定
		 */
		void SetAnimation();

		/**
		* @brief 状態毎の処理
		*/
//		virtual void StateExec();


	//Set系
	public:



	//Get系
	public:


};
