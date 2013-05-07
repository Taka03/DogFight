//*============================================================================
//Application.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "Application.h"
#include "../Game.h"
#include "../CommonObject.h"
#include "../ResourceManager.h"
#include "../FileLoader.h"

//=============================================================================
//コンストラクタ
//=============================================================================
//[input]
//	Width:画面幅
//	Height:画面高さ
//=============================================================================
CApplication::CApplication( Uint32 Width, Uint32 Height ) 
 :m_ScreenWidth( Width ),
  m_ScreenHeight( Height ),
  m_pCore( NULL ),
  m_pGraphicCard( NULL ),
  m_pFileMgr( NULL ),
  m_pRender( NULL ),
  m_strAppName( "GameSystem" )
{
	
}



//=============================================================================
//デストラクタ
//=============================================================================
CApplication::~CApplication(void)
{
	SAFE_RELEASE( m_pRender );
	SAFE_RELEASE( m_pFileMgr );
	SAFE_RELEASE( m_pGraphicCard );
	SAFE_RELEASE( m_pCore );
	
}

//=============================================================================
//コアの生成
//=============================================================================
void CApplication::CreateCore()
{
	
	#if defined(DEBUG) | defined(_DEBUG)
	
		/*システムの初期化*/
		System::Initialize();
		
	#else
	
		System::Initialize( true, false );
		
	#endif
	
	/*コアの生成*/
	m_pCore = System::CreateCore();
	
}

//=============================================================================
//初期化
//=============================================================================
bool CApplication::Initialize( )
{
	//-----------------------------------------------------------------
	// タイトルバーに情報を表示
	//-----------------------------------------------------------------
	#if defined(DEBUG) | (_DEBUG) 
	
		m_pCore->EnableDrawTitleInformation( true );
		
	#endif

	//-----------------------------------------------------------------
	// ファイル登録
	//-----------------------------------------------------------------
	// ファイルマネージャーを生成
	m_pFileMgr = m_pCore->CreateFileManager();
	
	// コアに設定
	m_pCore->SetFileManager( m_pFileMgr );
	
	// ルートディレクトリを設定
	#if defined(DEBUG) | (_DEBUG)
		
		m_pFileMgr->SetRootPath( 0, "../data" );
		
	#else
	
		m_pFileMgr->SetRootPath( 0, "./data" );
	
	#endif

	//-----------------------------------------------------------------
	// グラフィックカードを取得
	//-----------------------------------------------------------------
	// グラフィックカードに関しての初期化を行います。
	// IGraphicCardインターフェイスからは接続された
	// グラフィックカードの能力を取得する事が可能です。
	// IGraphicCardインターフェイスは1つのICoreインターフェイスに対して1つしか存在しません。
	m_pGraphicCard = m_pCore->CreateGraphicCard( GRAPHIC_CARD_DEFAULT_NO );
	
	_ASSERT( m_pGraphicCard );
	
	if( m_pGraphicCard == NULL )
	{
		return false;
	}

	//-----------------------------------------------------------------
	// ウィンドウ作成
	//-----------------------------------------------------------------
	// ICoreインターフェイス内の情報に従ってアプリケーション
	// ウィンドウを生成します。
	// IGraphicCardからの情報を元に画面解像度などを変更する場合は、
	// ICore::Start()を呼び出す前に行ってください。

	m_pCore->Start( m_ScreenWidth, m_ScreenHeight, true );

	//-----------------------------------------------------------------
	// レンダラーを取得
	//-----------------------------------------------------------------
	// 作成したグラフィックカードから画面描画用のレンダラーを取得します。
	// Renderer::IRenderインターフェイスは1つのIGraphicCardインターフェイスに対して1つしか存在しません。
	m_pRender = m_pGraphicCard->CreateRender();
	
	_ASSERT( m_pRender );
	
	if( m_pRender == NULL ) 
	{
		return false;
	}
	
	//テクスチャフォーマットの設定
	SetTextureFormat();
	
	return true;

}

//=============================================================================
//起動
//=============================================================================
void CApplication::Run()
{
	//コアの生成
	CreateCore();
	
	//初期化処理
	CCommonObject::Initialize();
	
	CGame Game;
	
	/*初期化*/
	if( m_pCore->Initialize( m_strAppName.c_str() , FRAME_RATE_60 ) )
	{
		Initialize();
		
		m_pRender->SetDrawTextFont( "メイリオ", 50, 1 );
	
		while( GetCore()->Run() )
		{
			//ゲーム処理
			Game.Run();

		}
		
	}
	
	//終了処理
	CCommonObject::Finalize();
	

}

//=============================================================================
//テクスチャフォーマットの設定
//=============================================================================
void CApplication::SetTextureFormat()
{
	Renderer::CTextureConfig Config;
	
	// テクスチャフォーマット
	Config.SetColorKey( CColor(0,0,0, 255) );
	Config.SetFormat( FORMAT_TEXTURE_32BIT );
	Config.SetMipmapEnable( false );
	m_pRender->SetTextureConfig( Config );
}

//=============================================================================
//参照カウンタ増加
//=============================================================================
void CApplication::AddRef()
{
	m_pRender->AddRef();
	m_pGraphicCard->AddRef();
	m_pFileMgr->AddRef();
	m_pCore->AddRef();
}

//=============================================================================
//参照カウンタ増加
//=============================================================================
void CApplication::Release()
{
	m_pRender->Release();
	m_pGraphicCard->Release();
	m_pFileMgr->Release();
	m_pCore->Release();
}

	



