//*============================================================================
//FontSprite.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "FontSprite.h"
#include "CommonObject.h"
#include "Common/Application.h"
#include "FileLoader.h"


//============================================================================
//コンストラクタ
//============================================================================
//[input]
//	pName:データ名
//	pDataName:データ名
//===========================================================================
CFontSprite::CFontSprite( const char *pName, const char *pDataName ) 
:m_pFontSpr(NULL),
 m_IsFlash( false ),
 m_FlashCount( 0 ),
 m_Counter( 0 ),
  CGameObject( pName, pDataName )
{
	m_vecText.clear();
	
	m_FontColor = CColor( 255, 255, 255 );
	
	m_HitRect.Set( 0.0f, 0.0f, 0.0f, 0.0f );
	
	m_RefCount = 0;
	
	m_StrCount = 1;
	
	m_IsTextEnd = false;
	
	Load();
	
	LoadParameter( pDataName );
	
	Init();
	
	m_fScale.x = 2.0f;
	m_fScale.y = 2.0f;

}

//============================================================================
//デストラクタ
//============================================================================
CFontSprite::~CFontSprite(void)
{
	SAFE_RELEASE( m_pFontSpr );
}

//============================================================================
//初期化
//============================================================================
void CFontSprite::Init()
{
	m_vPos = m_vInitPos;
}

//============================================================================
//ファイル読み込み
//============================================================================
bool CFontSprite::Load(  )
{
	Renderer::IRender *pRender = CCommonObject::GetAppli()->GetRenderer();
	File::IFileManager *pFileMgr = CCommonObject::GetAppli()->GetFileMgr();
	
	pFileMgr->SetCurrentPath("Font");
	
	printf("LOAD FONT[%s]", m_strFileName.c_str() );
	
	m_pFontSpr = pRender->CreateFontSprite2DFromFile( m_strFileName.c_str(), "tga", 1024 );
	
	if( m_pFontSpr->IsInvalid() )
	{
		return false;
	}
	
	printf( "                 : -> %s\n", m_pFontSpr->IsInvalid() ? "Failed" : "Succeeded" );
	
	return true;
}

//============================================================================
//パラメーターの読み込み
//============================================================================
//[input]
//	pFileName:ファイル名
//===========================================================================
void CFontSprite::LoadParameter( const char *pFileName )
{
	CFileLoader FileLoad( pFileName );
	
	//文字列の分割読み込み
	vector< string > vecStr = CFileLoader::SplitString( FileLoad.GetStrList().at( 0 ), "," );
	
	//----------------------------------------------------------------------------
	//位置の設定
	//----------------------------------------------------------------------------
	SetParameter( m_vInitPos.x, vecStr.at( 0 ) );
	
	SetParameter( m_vInitPos.y, vecStr.at( 1 ) );
	
	//----------------------------------------------------------------------------
	//文字の設定
	//----------------------------------------------------------------------------
	SetParameter( m_Str, vecStr.at( 2 ) );
	
	//----------------------------------------------------------------------------
	//点滅させるか
	//----------------------------------------------------------------------------
	SetParameter( m_IsFlash, vecStr.at( 3 ) );
	
	//----------------------------------------------------------------------------
	//点滅頻度
	//----------------------------------------------------------------------------
	SetParameter( m_FlashCount, vecStr.at( 4 ) );
	
	
}


//============================================================================
//処理
//============================================================================
void CFontSprite::Exec()
{
	if( m_pFontSpr != NULL )
	{
		/*描画開始*/
		m_pFontSpr->Begin(3);
		
		/*描画キューに追加*/
		//m_pFontSpr->DrawStringScale( m_Str.c_str(), Math::Point2DF( m_vPos.x, m_vPos.y), m_fScale, m_FontColor );
		m_pFontSpr->DrawString( m_Str.c_str(), Math::Point2DF( m_vPos.x, m_vPos.y ), m_FontColor );
		
		/*描画終了*/
		m_pFontSpr->End();
		
		
		
		
	}	
}

//============================================================================
//レンダリング
//============================================================================
void CFontSprite::Rendering()
{
	if( m_IsFlash )
	{
		if( ++m_Counter < m_FlashCount )
		{
			m_pFontSpr->Rendering();
		}
		
		else if( m_Counter > m_FlashCount * 2 )
		{
			m_Counter = 0;
		}
	}
	
	
	else
	{
		m_pFontSpr->Rendering();
	}
	
}


//============================================================================
//表示する文字の設定
//============================================================================
//[input]
//	str:設定する文字列
//===========================================================================
void CFontSprite::SetDrawString(std::string str)
{
	m_Str = str;
}

