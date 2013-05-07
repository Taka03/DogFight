//*============================================================================
//BackGraphic.h
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
class CBackGraphic :	public CSprite
{
	private:
	
		Sint32 m_ScrSpeed;///<@brief スクロールスピード
		static int m_Count;
	
	public:
		
		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		* @param pDataName データ名
		*/
		CBackGraphic( const char *pName, const char *pDataName );
		
		/**
		* @brief デストラクタ
		*/
		~CBackGraphic(void);
		
		void Rendering();
		
		/**
		* @brief 処理
		*/
		void Exec();
		
		/**
		* @brief 画面スクロール
		*/
		void Scroll();
		
		
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
		
		
};
