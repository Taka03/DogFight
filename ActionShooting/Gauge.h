//*============================================================================
//Gauge.h
//*============================================================================
/**
* 背景クラス
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "sprite.h"

//=============================================================================
//class
//=============================================================================
class CGauge :	public CSprite
{
	private:
	
		static float m_fGaugeVal;///<@brief ゲージ値
		Sint32 m_FontAnim;///@brief 文字のアニメーション
		static float m_fAddGaugeVal;///<@brief ゲージ増加値
		bool m_IsMaxCharge;///<@brief 最大までチャージしたか

	
	public:
		
		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		* @param pDataName データ名
		*/
		CGauge( const char *pName, const char *pDataName );
		
		/**
		* @brief デストラクタ
		*/
		~CGauge(void);
		
		/**
		* @brief 処理
		*/
		void Exec();
		

		/**
		* @brief パラメーターの読み込み
		* @param pFileName ファイル名
		*/
		void LoadParameter( const char *pFileName );
		
		/**
		* @brief 当たり判定
		* @param spObj 判定するオブジェクト
		* @retval true 当たっている
		* @retval false 当たっていない
		*/
		virtual bool HitCheck( sp<CGameObject> spObj );
		

	public:

		/**
		 * @brief ゲージの増加
		 * @param fVal 増加値
		 */
		static void AddGauge( float fVal )
		{
			m_fAddGaugeVal = fVal;
			m_fGaugeVal += m_fAddGaugeVal;

		}

		/**
		 * @brief ゲージ値の取得
		 * @return　ゲージ値
		 */
		static float GetGaugeVal( )
		{
			return m_fGaugeVal;
		}

	public:

		
		
		
};
