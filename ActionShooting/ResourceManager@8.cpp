//*============================================================================
//ResourceManager.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "ResourceManager.h"
#include "Factory2D.h"
#include "PathStrAnalizer.h"
#include "SoundManager.h"
#include "SoundFactory.h"
#include "dixsmartptr.h"
//#include "MouseSprite.h"

//============================================================================
//コンストラクタ
//============================================================================
CResourceManager::CResourceManager( ) 
: m_Page(0)
{
	for( int i = 0;i < QUE_MAX;++i )
	{
		m_pQueTop[i] = NULL;
	}
	
	m_mapDraw.clear();
	
	/*スレッドの作成*/
	m_Thread.Create( LoadProc, (void*)this );
	
	printf("BOOT ResourceManager\n");
}	

//============================================================================
//デストラクタ
//============================================================================
CResourceManager::~CResourceManager()
{
	printf("ABORT ResourceManager\n");
	
	/*終了*/
	m_Event.Set();
	
	/*スレッドの終了待ち*/
	while( !m_Thread.WaitForExit() )
	{
		Sleep( 100 );
	}
	
	//描画リストの消去
	RemoveAll();
	
	printf("EXIT ResourceManager\n");
	
}

//============================================================================
//オブジェクトの取得
//============================================================================
//[input]
//	pName:データ名
//[return]
//	取得したオブジェクト
//===========================================================================
sp<CGameObject> CResourceManager::FindObject( const char *pName )
{
	//ロックを掛ける
	Thread::CAutoLock Lock( m_CS );

	return m_mapDraw[pName];
}

//============================================================================
//オブジェクトのリスト追加
//============================================================================
//[input]
//	pDataName:データ名
//	spGameObj:ゲームオブジェクト
//===========================================================================
void CResourceManager::AppendList( string strDataName, sp<CGameObject> spGameObj )
{
	m_CS.Enter();
	
	//パラメーターの読み込み
	//pGameObj->LoadParameter( pGameObj->GetDataName() );
	
	//マップに追加
	m_mapDraw.insert( make_pair( strDataName, spGameObj ) );
	
	m_CS.Leave();
}


//============================================================================
//オブジェクトの消去
//============================================================================
//[input]
//	pDataName:データ名
//============================================================================
void CResourceManager::RemoveObject( const char *pDataName )
{
	m_CS.Enter();
	
	while( m_itDraw != m_mapDraw.end() )
	{
		if( m_itDraw->first.compare( pDataName ) == 0 )
		{
			printf("REMOVE OBJECT[%s]", pDataName );
			
			sp<CGameObject> spTemp( m_itDraw->second );
			spTemp->SetRemoveFlag( true );
			
			break;
			
		}
		
		else
		{
			m_itDraw++;
		}
	}
	
	m_CS.Leave();
	
}

//============================================================================
//すべてのオブジェクトの消去
//============================================================================
void CResourceManager::RemoveAll()
{
	m_mapDraw.clear();
}

//============================================================================
//オブジェクトの追加
//============================================================================
//[input]
//	pFile:追加するデータ
//===========================================================================
void CResourceManager::Push( CFileData *pFile )
{
	/*終了処理発生した?*/
	if( m_Event.IsSignal() )
	{
		return;
	}
	
	//オートロック
	Thread::CAutoLock Lock( m_CS );
	
	/*先頭*/
	if( m_pQueTop[m_Page] == NULL )
	{
		m_pQueTop[m_Page] = pFile;
	}
	
	/*リストの追加*/
	else
	{
		CFileData *pData = m_pQueTop[m_Page];
		
		while( pData->GetNext() != NULL )
		{
			pData = pData->GetNext();
		}
		
		pData->SetNext( pFile );
	}
	
	pFile->SetNext( NULL );
	
	printf("CResourceManager :PUSH [%s]\n", pFile->GetDataName().c_str() );
	
}

//============================================================================
//読み込み中かどうか判定
//============================================================================
//[return]
//	読み込み中かどうか(true:読み込み中)
//===========================================================================
Bool CResourceManager::IsLoading()
{
	//オートロック
	Thread::CAutoLock Lock( m_CS );
	
	if( m_pQueTop[0] != NULL )
	{
		return true;
	}
	
	if( m_pQueTop[1] != NULL )
	{
		return true;
	}
	
	return false;
}


//============================================================================
//起動
//============================================================================
void CResourceManager::Run()
{
	for(;;)
	{
		CFileData *pFile = NULL;
		Sint32 ActivePage = -1;
		
		/*終了チェック*/
		if( m_Event.IsSignal() )
		{
			break;
		}
		
		/*今回取得するリストを取得*/
		m_CS.Enter();
		
		/*これから処理するページ*/
		ActivePage = m_Page;
		
		/*ページ切り替え*/
		m_Page = 1 - m_Page;
		
		/*先頭を取得*/
		pFile = m_pQueTop[ActivePage];
		
		m_CS.Leave();
		
		if( pFile == NULL )
		{
			::Sleep( 250 );
			
			continue;
		}
		
		while( pFile != NULL )
		{
			/*リソースタイプを判別*/
			CheckType( pFile );
			
			/*次を取得*/
			CFileData *pNext = pFile->GetNext();
			
			/*現在のものを削除*/
			delete pFile;
			
			pFile = pNext;
			
		}
		
		/*リスト初期化*/
		m_pQueTop[ActivePage] = NULL;
		
	}
	
	//----------------------------------------------------------------------------
	//キューの中身をクリア
	//----------------------------------------------------------------------------
	for( Sint32 i = 0;i < QUE_MAX;++i )
	{
		CFileData *pFile = m_pQueTop[i];
		
		while( pFile != NULL )
		{
			CFileData *pNext = pFile->GetNext();
			delete pFile ;
			pFile = pNext;
		}
		
		m_pQueTop[i] = NULL;
	}

	
}

//============================================================================
//タイプの判別
//============================================================================
//[input]
//	pFile:判定するデータ
//===========================================================================
void CResourceManager::CheckType( CFileData *pFile )
{
	
	
	TCHAR *pName =  (TCHAR *)( pFile->GetFileName().c_str() );
	
	Dix::PathStrAnalizer PSA( pName );
	
	//拡張子を取得
	string strExtName = PSA.getExtName();
	
	//音関係の場合
	if( strExtName == "wav" || strExtName == "ogg" )
	{
		//音の取得
		CSoundObject *pSoundObj = CSoundFactory::GetSound( pFile );
		
		sp<CSoundObject> spSndObj( pSoundObj );
		
		//サウンドリストに追加
		CCommonObject::GetSoundMgr()->AppendSoundList( pFile->GetDataName().c_str(), spSndObj );
		
	}
	
	//その他オブジェクトの場合
	else
	{
		//2Dオブジェクトの取得
		CGameObject *pObj = CFactory2D::Get2DObject( pFile );
		
		sp<CGameObject> spObj;
		
		spObj.SetPtr( pObj );
		
		//リソースの登録
		AppendList( pFile->GetDataName(), spObj );
		
	}
	
}

//============================================================================
//全リソースのレンダリング
//============================================================================
void CResourceManager::RenderingAll()
{
	//ロックを掛ける
	Thread::CAutoLock Lock( m_CS );
	
	map< string, sp<CGameObject> >::iterator it = m_mapDraw.begin();
	
	while( it != m_mapDraw.end() )
	{
		sp<CGameObject> spGameObj( it->second );
		
		//表示フラグが立っていたらレンダリング
		if( spGameObj->GetVisibleFlag() )
		{	
			spGameObj->Rendering();
		}
		
		it++;
		
	}
}

//============================================================================
//全リソースの処理
//============================================================================
void CResourceManager::ExecAll()
{
	//ロックを掛ける
	Thread::CAutoLock Lock( m_CS );
	
	//map< string, CGameObject *>::iterator it = m_mapDraw.begin();
	//
	//for( it = m_mapDraw.begin(); it != m_mapDraw.end();it++ )
	//{
	//	CDrawObject *pDrawObj = dynamic_cast<CDrawObject *>( it->second );
	//	
	//	pDrawObj->Exec();
	//}
}

//============================================================================
//更新
//============================================================================
void CResourceManager::Update()
{
	//ロックを掛ける
	Thread::CAutoLock Lock( m_CS );
	
	m_itDraw = m_mapDraw.begin();
	
	
	while( m_itDraw != m_mapDraw.end() )
	{
		
		
		sp<CGameObject> spGameObj( m_itDraw->second );
		
		spGameObj->Exec();
		
		if( spGameObj->GetRemoveFlag() )
		{
			m_mapDraw.erase( m_itDraw++ );
			
		}
		
		else
		{
			++m_itDraw;
		}
		
	}
	

}


//============================================================================
//全リソースの当たり判定
//============================================================================
void CResourceManager::HitCheckAll()
{
	//while( m_itDraw != m_mapDraw.end() )
	//{
	//	
	//	//sp<CGameObject> spGameObj( m_itDraw->second );

	//	//spDrawObj->HitCheck( spDrawObj2 );

	//	m_itDraw++;
	//	
	//}
	
}


//============================================================================
//ロード用スレッド
//============================================================================
//[input]
//	pData:実行データ
//===========================================================================
void CResourceManager::LoadProc( void *pData )
{
	//使用するCPU番号
	System::SetThreadCPUNo( 1 );
	
	//起動
	( (CResourceManager*)pData)->Run();

}



					
									


