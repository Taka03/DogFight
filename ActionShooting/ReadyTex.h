//*============================================================================
//ReadyTex.h
//*============================================================================
/**
* Readyテクスチャクラス
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "sprite.h"

//=============================================================================
//class
//=============================================================================
class CReadyTex :	public CSprite
{
	private:

		int m_ExistCount;///!< @brief 存在カウンター


	public:

		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		* @param pDataName データ名
		*/
		CReadyTex( const char *pName, const char *pDataName );

		/**
		* @brief デストラクタ
		*/
		~CReadyTex(void);

		/**
		* @brief 処理
		*/
		void Exec();

		/**
		* @brief 当たり判定
		* @param spObj 判定するオブジェクト
		* @retval true 当たっている
		* @retval false 当たっていない
		*/
		virtual bool HitCheck( sp<CGameObject> spObj );


	public:






};
