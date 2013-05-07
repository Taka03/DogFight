//*============================================================================
//PushStart.h
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
class CPushStart :	public CSprite
{
	private:

		Sint32 m_Counter;//@brief 汎用カウンター
		Sint32 m_FlashCount;//@brief フラッシュカウント
		
	public:

		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		* @param pDataName データ名
		*/
		CPushStart( const char *pName, const char *pDataName );

		/**
		* @brief デストラクタ
		*/
		~CPushStart(void);

		/**
		* @brief レンダリング
		*/
		void Rendering();

		/**
		* @brief 当たり判定
		* @param spObj 判定するオブジェクト
		* @retval true 当たっている
		* @retval false 当たっていない
		*/
		virtual bool HitCheck( sp<CGameObject> spObj );


	public:






};
