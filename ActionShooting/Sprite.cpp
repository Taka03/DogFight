//*============================================================================
//Sprite.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "Sprite.h"
#include "CommonObject.h"
#include "Common/Application.h"
#include "FileLoader.h"
#include "ResourceManager.h"
#include <map>

//============================================================================
//コンストラクタ
//============================================================================
//[input]
//	pName:ファイル名
//	pDataName:データファイル名
//===========================================================================
CSprite::CSprite( const char *pName, const char *pDataName )  
:m_pTex(NULL),
 m_pSpr(NULL),
 m_vCenterPos( 8, 8 ),
 m_DivNum( 1, 1 ),
 m_AnimTime( 5 ),
 m_AnimCount( 0 ),
 m_Anim( 0, 0 ),
 m_AnimNum( 0 ),
 m_fSize( 0, 0 ),
 m_HitRect( 0, 0, 0, 0 ),
 m_DstRect( 0, 0, 0, 0 ),
 m_SrcRect( 0, 0, 0, 0 ),
 m_IsAnim( false ),
 m_IsAuto( true ),
 m_IsReverse( true ),
 m_AnimSpeed( 1 ),
 m_Color( 255, 255, 255 ),
 m_AdjHitRect( 0, 0, 0, 0 ),
 CGameObject( pName, pDataName )
{
	_ASSERT( m_DivNum.x > 0 );
	_ASSERT( m_DivNum.y > 0 );
	
	//パラメーターの読み込み
	this->LoadParameter( pDataName );
	
	//読み込み
	Load();
	
	//初期化
	Init();
	
}

//============================================================================
//コンストラクタ
//============================================================================
//[input]
//	LineNo:行数
//===========================================================================
CSprite::CSprite( vector<string> vecStr )
:m_pTex(NULL),
 m_pSpr(NULL),
 m_vCenterPos( 8, 8 ),
 m_DivNum( 1, 1 ),
 m_AnimTime( 5 ),
 m_AnimCount( 0 ),
 m_Anim( 0, 0 ),
 m_AnimNum( 0 ),
 m_fSize( 0, 0 ),
 m_HitRect( 0, 0, 0, 0 ),
 m_DstRect( 0, 0, 0, 0 ),
 m_SrcRect( 0, 0, 0, 0 ),
 m_IsAnim( false ),
 m_IsAuto( true ),
 m_IsReverse( true ),
 m_AnimSpeed( 1 ),
 m_fBlendRate( 0 ),
 m_Color( 255, 255, 255 ),
 m_AdjHitRect( 0, 0, 0, 0 ),
 CGameObject( vecStr )
{
	_ASSERT( m_DivNum.x > 0 );
	_ASSERT( m_DivNum.y > 0 );

	if( m_DivNum.x < 0 )
	{
		m_DivNum.x = 1;
	}

	if( m_DivNum.y < 0 )
	{
		m_DivNum.y = 1;
	}

	//パラメーターの読み込み
	this->LoadParameter( vecStr );

	//読み込み
	Load();

	//初期化
	Init();

}

//============================================================================
//デストラクタ
//============================================================================
CSprite::~CSprite(void)
{
	SAFE_RELEASE( m_pSpr );
	SAFE_RELEASE( m_pTex );
}

//============================================================================
//初期化
//============================================================================
void CSprite::Init()
{
	m_vPos = m_vInitPos;
	
	m_Angle = m_InitAngle;
	
	m_fScale = m_fInitScale;
	
}

//============================================================================
//ファイル読み込み
//============================================================================
//[return]
//	ファイル読み込みに成功したか
//===========================================================================
bool CSprite::Load( )
{
	Renderer::IRender *pRender = CCommonObject::GetAppli()->GetRenderer();
	File::IFileManager *pFileMgr = CCommonObject::GetAppli()->GetFileMgr();
	
	pFileMgr->SetCurrentPath("Texture");
	
	const char *pFileName = m_strFileName.c_str();
	
	printf("LOAD TEXTURE[%s]", pFileName );
	
	//テクスチャファイルの生成(同一ファイルがあったら複製)
	m_pTex = pRender->CreateTextureFromFile( pFileName );

	_ASSERT( m_pTex );
	
	//読み込みに失敗?
	if( m_pTex->IsInvalid() )
	{
		return false;
	}
	
	printf( "                 : -> %s\n", m_pTex->IsInvalid() ? "Failed" : "Succeeded" );
	
	/*サイズの設定*/
	m_fSize.x = toF( m_pTex->GetOriginalSize().x / m_DivNum.x );
	m_fSize.y = toF( m_pTex->GetOriginalSize().y / m_DivNum.y );
	
	m_SrcRect.Set( 0, 0, m_fSize.x, m_fSize.y ),
	
	/*スプライトの生成*/
	CreateSprite( pRender, 500 );
	
	return true;
	
}

//============================================================================
//パラメーターの読み込み
//============================================================================
//[input]
//	pFileName:ファイル名
//===========================================================================
void CSprite::LoadParameter( const char *pFileName )
{
	CFileLoader FileLoad( pFileName );
	
	vector< string > vecStr = CFileLoader::SplitString( FileLoad.GetStrList().at( 0 ), "," );
	
	//----------------------------------------------
	//位置の設定
	//----------------------------------------------
	SetParameter( m_vInitPos.x, vecStr.at( 0 ) );
	
	SetParameter( m_vInitPos.y, vecStr.at( 1 ) );
	
	//----------------------------------------------
	//角度の設定
	//----------------------------------------------
	SetParameter( m_InitAngle, vecStr.at( 2 ) );
	
	//----------------------------------------------
	//不透明度の設定
	//----------------------------------------------
	SetParameter( m_Alpha, vecStr.at( 3 ) );


	//----------------------------------------------
	//拡縮率の設定
	//----------------------------------------------
	SetParameter( m_fInitScale.x, vecStr.at( 4 ) );
	
	SetParameter( m_fInitScale.y, vecStr.at( 5 ) );
	
	//----------------------------------------------
	//分割数の設定
	//----------------------------------------------
	SetParameter( m_DivNum.x, vecStr.at( 6 ) );
	
	SetParameter( m_DivNum.y, vecStr.at( 7 ) );
	
	//----------------------------------------------
	//アニメーションの設定
	//----------------------------------------------
	SetParameter( m_IsAnim, vecStr.at( 8 ) );
	
	SetParameter( m_AnimTime, vecStr.at( 9 ) );
	
}

//============================================================================
//パラメーターの読み込み
//============================================================================
//[input]
//	vecStr:
//===========================================================================
void CSprite::LoadParameter( vector<string> vecStr )
{
	//----------------------------------------------
	//ファイル名の設定
	//----------------------------------------------
	SetParameter( m_strFileName, vecStr.at( 0 ) );

	//----------------------------------------------
	//データファイル名の設定
	//----------------------------------------------
	SetParameter( m_strDataName, vecStr.at( 1 ) );

	//----------------------------------------------
	//位置の設定
	//----------------------------------------------
	SetParameter( m_vInitPos.x, vecStr.at( 2 ) );

	SetParameter( m_vInitPos.y, vecStr.at( 3 ) );

	//----------------------------------------------
	//角度の設定
	//----------------------------------------------
	SetParameter( m_InitAngle, vecStr.at( 4 ) );

	//----------------------------------------------
	//不透明度の設定
	//----------------------------------------------
	SetParameter( m_Alpha, vecStr.at( 5 ) );

	//----------------------------------------------
	//拡縮率の設定
	//----------------------------------------------
	SetParameter( m_fInitScale.x, vecStr.at( 6 ) );

	SetParameter( m_fInitScale.y, vecStr.at( 7 ) );

	//----------------------------------------------
	//分割数の設定
	//----------------------------------------------
	SetParameter( m_DivNum.x, vecStr.at( 8 ) );

	SetParameter( m_DivNum.y, vecStr.at( 9 ) );

	//----------------------------------------------
	//アニメーションの設定
	//----------------------------------------------
	//SetParameter( m_IsAnim, vecStr.at( 8 ) );

	//SetParameter( m_AnimTime, vecStr.at( 9 ) );

}

//============================================================================
//スプライトの生成
//============================================================================
//[input]
//	pRender:レンダラー用デバイス
//	Num:スプライト数
//===========================================================================
void CSprite::CreateSprite( Renderer::IRender *pRender, Uint32 Num )
{
	m_pSpr = pRender->CreateSprite2D( Num, m_pTex ); 
	
	_ASSERT( m_pSpr );
		
}

//============================================================================
//処理
//============================================================================
void CSprite::Exec()
{
	/*アニメーションの設定*/
	SetAnimation();
	
	/*描画先*/
	m_DstRect.Set( m_vPos.x, m_vPos.y, m_fSize.x * m_fScale.x, m_fSize.y * m_fScale.y );
	
	/*描画元*/
	m_SrcRect.Set( m_Anim.x * m_fSize.x, m_Anim.y * m_fSize.y, m_fSize.x, m_fSize.y );
	
	//描画リクエスト
	DrawRequest();
	
	map< string, sp<CGameObject> > mapDraw;
	
	mapDraw.clear();
	
	mapDraw = CCommonObject::GetResMgr()->GetDrawMap();

	map< string, sp<CGameObject> >::iterator it = mapDraw.begin();




#if defined( DEBUG ) | ( _DEBUG )

	Peripheral::IKeyboard *pKey = CCommonObject::GetAppli()->GetCore()->GetKeyboard();


	static bool IsHit = true;

	if( pKey->GetKeyData( SELENE_VK_Q ) )
	{
		IsHit = !IsHit;
	}



#endif

#if defined( DEBUG ) | ( _DEBUG )

	if( IsHit )
#endif
	{

		while( it != mapDraw.end() )
		{
			sp<CGameObject> spObj( it->second );
			
			bool IsThis = ( this->GetPos().x > 0 && this->GetPos().x < SCREEN_WIDTH - this->GetSize().x && this->GetPos().y > 0 
							&& this->GetPos().y < SCREEN_HEIGHT - this->GetSize().y );
			
				if( this->HitCheck( spObj ) )
				{
					this->HitExec( spObj );
				}
			

			it++;
		}
	}



	
}



//============================================================================
//描画リクエスト
//============================================================================
void CSprite::DrawRequest()
{
	/*当たり判定領域のセット*/
	m_HitRect.Set( m_vPos.x + m_AdjHitRect.x, m_vPos.y + m_AdjHitRect.y, 
				   m_fSize.x * m_fScale.x - m_AdjHitRect.w, 
				   m_fSize.y * m_fScale.y - m_AdjHitRect.h );
	
	/*描画開始*/
	m_pSpr->Begin();
	
	m_Color.a = m_Alpha;	
	

	
	
	/*回転付き描画*/
	m_pSpr->DrawSquareRotateC( m_DstRect, m_SrcRect, 
	Math::Vector3D( m_vPos.x + m_vCenterPos.x, m_vPos.y + m_vCenterPos.y, 0 ), m_Color, m_Angle );
	
	/*描画終了*/
	m_pSpr->End();
}

//============================================================================
//レンダリング
//============================================================================
void CSprite::Rendering( )
{
	m_pSpr->Rendering();
}

//============================================================================
//グレースケール描画
//============================================================================
//[input]
//	pRender:レンダラー用デバイス
//===========================================================================
void CSprite::DrawGrayScale( Renderer::IRender *pRender )
{
	if( m_pTex != NULL )
	{
		Math::Rect2DF Dst( m_vPos.x, m_vPos.y, m_fSize.x, m_fSize.y );
		
		Math::Rect2DF Src( 0, 0, m_fSize.x, m_fSize.y );
		
		pRender->DrawGrayscale( Dst, CColor( 255, 254, 255 ), Src, m_pTex );
		
		
	}
}

//============================================================================
//アニメーションの設定
//============================================================================
void CSprite::SetAnimation()
{
	if( m_IsAnim )
	{
		/*アニメーションカウンタの増加*/
		if( ++m_AnimCount > m_AnimTime )
		{
			m_AnimCount = 0;
			m_Anim.x += m_AnimSpeed;
		}
		 
		if( m_Anim.x >= m_DivNum.x )
		{
			m_Anim.x = 0;
		}
		
	}
	
}

//============================================================================
//当たり判定
//============================================================================
//[input]
//	spObj:判定オブジェクト
//[return]
// 当たっているかどうか
//============================================================================
bool CSprite::HitCheck( sp<CGameObject> spObj )
{
	if( spObj != NULL && this != NULL )
	{
		if( spObj->GetVisibleFlag() && this->GetVisibleFlag() )
		{
			if( Collision::Rect_Rect( this->GetHitRect(), spObj->GetHitRect() )  )
			{
				return true;
			}
			
			

			else
			{
				return false;
			}
		}
	}
	
	return false;
}
