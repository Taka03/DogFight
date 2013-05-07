//*============================================================================
//EffectMaxCharge.h
//*============================================================================
/**
* エフェクト(最大チャージ)クラス
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "Effect.h"

//=============================================================================
//class
//=============================================================================
class CEffectMaxCharge :	public CEffect
{
	private:

		int m_ExistCount;///<@brief 存在カウンター
		Math::Vector2D m_vAdjPos;///<@brief
		bool m_IsAdd;///<@brief 加算するか
		bool m_IsBlend;
		Sint32 m_Alpha;///<@brief アルファ値

	public:

		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		* @param pDataName データ名
		* @param vPos 設定する位置
		*/
		CEffectMaxCharge( const char *pName, const char *pDataName, Math::Vector2D vPos );

		/**
		* @brief デストラクタ
		*/
		~CEffectMaxCharge(void);


		/**
		 * @brief レンダリング
		 */
		void Rendering();

		/**
		 * @brief アニメーションの設定
		 */
		virtual void SetAnimation();

		/**
		 * @brief パラメーターの読み込み
		 * @param pFileName ファイル名
		 */
		virtual void LoadParameter( const char *pFileName );



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
