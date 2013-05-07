//*============================================================================
//DrawObject.h
//*============================================================================
//[history]
//	08/03/03 修正開始
//[author]
//	Taka
//============================================================================
#pragma once

//=============================================================================
//include
//=============================================================================
#include "gameobject.h"

//=============================================================================
//class
//=============================================================================
//[Desc]
//	描画用オブジェクト
//=============================================================================
class CDrawObject :public CGameObject
{
	protected:
		
		
	public:
	
		//コンストラクタ
		CDrawObject( const char *pName );
		
		//デストラクタ
		virtual ~CDrawObject(void){};
		
		//初期化
		virtual void Init();
		
		//処理
		virtual void Exec(){}
		
		//ファイル読み込み
		virtual bool Load(){ return true; }
		
		//パラメータの読み込み
		virtual void LoadParameter( const char *pFileName ){}
		
		//レンダリング
		virtual void Rendering() = 0;
		
		/**
		* @brief 当たり判定
		* @param spObj 判定するオブジェクト
		* @retval true 当たっている
		* @retval false 当たっていない
		*/
		virtual bool HitCheck( sp<CDrawObject> spObj ){ return false; };
		
		
	public:
		
		
		
		
};
