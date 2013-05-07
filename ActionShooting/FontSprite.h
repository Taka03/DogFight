//*============================================================================
//FontSprite.h
//*============================================================================
//[history]
//	08/03/16 作成
//[author]
//	Taka
//============================================================================
#pragma once

//=============================================================================
//include
//=============================================================================
#include "gameobject.h"
#include <vector>
#include <string>

using namespace std;

//=============================================================================
//class
//=============================================================================
//[Desc]
//	フォントスプライト描画用オブジェクト
//=============================================================================
class CFontSprite :	public CGameObject
{
	protected:
		
		
		Renderer::Object::IFontSprite2D *m_pFontSpr;//フォントスプライト用ハンドル
		string m_Str;//表示する文字
		vector<string> m_vecText;//複数テキスト
		
		CColor m_FontColor;//フォント色
		
		Uint32 m_StrCount;//文字カウンタ
		Uint32 m_RefCount;//文字の参照カウンタ
		
		bool m_IsTextEnd;//テキスト終了フラグ
		
		bool m_IsFlash;///@brief 点滅させるか
		
		Sint32 m_Counter;//@brief 汎用カウンター
		Sint32 m_FlashCount;//@brief フラッシュカウント
		
		// 当たり判定領域
		Math::Rect2DF m_HitRect;
		
	public:
	
		CFontSprite( const char *pName, const char *pDataName );//コンストラクタ
	
		virtual ~CFontSprite(void);//デストラクタ
		
		void Init();//初期化
		void Exec();//処理
		void Rendering();//レンダリング
		
		bool Load( );//読み込み
		
		//パラメーターの読み込み
		void LoadParameter( const char *pFileName );
		
		virtual bool HitCheck( sp<CGameObject> spObj ){ return false; }
		
		/**
		* @brief 当たった時の処理
		* @param spObj 判定するオブジェクト
		*/
		virtual void HitExec( sp<CGameObject> spObj ){};
		
		
	public:
	
		void SetDrawString( string str );//描画する文字の設定
		
		/*複数文字列の描画設定*/
		void SetVecTextChat( vector<string> vecStr )
		{
			m_vecText = vecStr;
		}
		
		/*文字参照カウンタの増加*/
		void SetRefCount( Uint32 count) 
		{
			m_RefCount = count;
		}
		
		/*テキスト終了フラグの設定*/
		void SetTextEndFlag( bool flag )
		{
			m_IsTextEnd = flag;
		}
		
		/*文字カウンタの設定*/
		void SetStrCount( Uint32 count )
		{
			m_StrCount = count;
		}
		
		/*フォント色の設定*/
		void SetFontColor( CColor color )
		{
			m_FontColor = color;
		}
		
	public:
	
		//フォントスプライト用ハンドルの取得
		Renderer::Object::IFontSprite2D *GetFontSprite() const
		{
			return m_pFontSpr;
		}
		
		/*表示する文字の取得*/
		string GetDrawString() const
		{
			return m_Str;
		}
		
		/*複数テキストの取得*/
		vector<string> GetVecString() const
		{
			return m_vecText;
		}
		
		/*テキスト終了フラグの取得*/
		bool GetTextEndFlag() const
		{
			return m_IsTextEnd;
		}
		
		/*文字カウンタの取得*/
		Uint32 GetStrCount() const
		{
			return m_StrCount;
		}
		
		// 当たり判定領域の取得
		Math::Rect2DF GetHitRect(void) const
		{
			return m_HitRect;
		}
		
};
