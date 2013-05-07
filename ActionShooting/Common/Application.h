//*============================================================================
//Application.h
//*============================================================================
//[history]
//	08/03/05　作成
//[author]
//	Taka
//============================================================================
#pragma once

//=============================================================================
//include
//=============================================================================
#include "../common.h"

//=============================================================================
//class
//=============================================================================
//[desc]
//	アプリケーション用クラス
//=============================================================================
class CApplication
{
	private:
	
		ICore	*m_pCore;//コアデバイス
		IGraphicCard	*m_pGraphicCard;//グラフィックカードデバイス
		File::IFileManager	*m_pFileMgr;//ファイル管理デバイス
		Renderer::IRender	*m_pRender;//レンダラー用デバイス
		
	private:
	
		const Uint32 m_ScreenWidth;//画面幅
		const Uint32 m_ScreenHeight;//画面高さ
		const std::string m_strAppName;//アプリケーション名
		
	public:

		CApplication( Uint32 Width, Uint32 Height );//コンストラクタ
		~CApplication(void);//デストラクタ
		
	public:
	
		void CreateCore();//コアの生成
		bool Initialize( );//初期化
		void SetTextureFormat();//テクスチャフォーマットの設定
		
		void Run();//起動
		
		void AddRef();//参照カウンタの増加
		void Release();//参照カウンタの減少
		
	/*Get系*/
	public:
	
		/*コアデバイスの取得*/
		ICore	*GetCore() const
		{
			return m_pCore;
		}
		
		/*ファイル管理デバイスの取得*/
		File::IFileManager	*GetFileMgr() const
		{
			return m_pFileMgr;
		}
		
		/*レンダラー用デバイスの取得*/
		Renderer::IRender	*GetRenderer() const
		{
			return m_pRender;
		}
		
		
};

