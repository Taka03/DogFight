//*============================================================================
//PauseFont.h
//*============================================================================
//[history]
//	2009/10/10　作成
//[author]
//	Taka
//============================================================================
#pragma once


//=============================================================================
//define
//=============================================================================
#define USE_SPRITE 1


//=============================================================================
//include
//=============================================================================

#ifdef USE_SPRITE
#include "Sprite.h"

#else
#include "FontSprite.h"

#endif


//=============================================================================
//const
//=============================================================================
const int MENU_MAX = 2;

//=============================================================================
//class
//=============================================================================
//[Desc]
//	フォントスプライト描画用オブジェクト
//=============================================================================
class CPauseFont :

#ifdef USE_SPRITE
	public CSprite
#else
	public CFontSprite
#endif

{
	private:

		Sint32 m_Cursor;///<@brief カーソル位置
		


	public:

		/**
		 * @brief コンストラクタ
		 * @param pName ファイル名
		 * @param pDataName　データファイル名
		 */
		CPauseFont( const char *pName, const char *pDataName );

		/**
		 * @brief デストラクタ
		 */
		virtual ~CPauseFont(void);

		/**
		 * @brief 初期化
		 */
		void Init();

		/**
		 * @brief 処理
		 */
		void Exec();

		/**
		 * @brief レンダリング
		 */
		void Rendering();

//		/**
//		 * @brief パラメーターの読み込み
//		 * @param pFileName ファイル名
//		 */
//		void LoadParameter( const char *pFileName );

	public:

		/**
		 * @brief 描画
		 */
		void Draw();

	public:

		/**
		 * @brief カーソル位置の設定
		 * @param Cursor 設定するカーソル位置
		 */
		void SetCursor( const Sint32 Cursor )
		{
			m_Cursor = Cursor;
		}

	public:


		/**
		 * @brief カーソル位置の取得
		 * @return カーソル位置
		 */
		Sint32 GetCursor()
		{
			return m_Cursor;
		}

};
