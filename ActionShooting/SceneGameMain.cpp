//*============================================================================
//SceneGameMain.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "SceneGameMain.h"
#include "CommonObject.h"
#include "ResourceManager.h"
#include "FileLoader.h"
#include "SoundManager.h"
#include "SceneGameOver.h"
#include "GameSceneManager.h"
#include <fstream>
#include "joypad.h"
#include "SceneTitle.h"
#include "CSceneGameDemo.h"
#include "PauseFont.h"

//=============================================================================
//variable
//=============================================================================
Uint32 CSceneGameMain::m_HitTime = 0;
Uint32 CSceneGameMain::m_HitCount = 0;
Uint32 CSceneGameMain::m_MaxHitCount = 0;
Uint32 CSceneGameMain::m_GameScore = 0;
Uint32 CSceneGameMain::m_HighScore = 0;
bool CSceneGameMain::m_IsGameEnd = false;
bool CSceneGameMain::m_IsPause = false;
bool CSceneGameMain::m_IsUpdateScore = false;
string CSceneGameMain::m_strScore;
string CSceneGameMain::m_strMaxHitNum;
multiset<int> CSceneGameMain::m_setScore;
CSceneGameMain::tagTime CSceneGameMain::m_Time;
bool CSceneGameMain::m_IsGameClear = false;




//============================================================================
//コンストラクタ
//============================================================================
//[input]
//	pDataName:データファイル名
//============================================================================
CSceneGameMain::CSceneGameMain( const char *pDataName )
:CSceneBase( pDataName ),
 m_GameCounter( 0 ),
 m_CurPat( 0 ),
 m_InitHighScore( 0 ),
 m_SceneCounter( 0 ),
 m_IsRetry( false )
{
	//CCommonObject::GetResMgr()->SetDrawMap( m_mapResource );
	
	
	m_Time.m_Minute = 2;
	m_Time.m_Second = 0;
	

	m_mapEnemyPat.clear();

	m_vecPat.clear();
	m_setScore.clear();
	
	CCommonObject::GetGameSceneMgr()->SetDemoFlag( false );
	
	
	//LoadResourceFile( pDataName );
	
//	配列の初期化
	memset( m_arScore, 0, SCORELIST_MAX );

	
	
	
	LoadPattern();
}

//============================================================================
//デストラクタ
//============================================================================
CSceneGameMain::~CSceneGameMain(void)
{
	m_mapResource.clear();
	m_mapEnemyPat.clear();
	m_vecPat.clear();
	
	printf("GameMainEnd\n");
	
}

//=============================================================================
//敵パターンの読み込み
//=============================================================================
void CSceneGameMain::LoadPattern()
{
	CFileLoader FileLoad( "stage1.csv" );
	
	for( Uint32 i = 0;i < FileLoad.GetStrList().size();++i )
	{
		vector< string > vecStr = CFileLoader::SplitString( FileLoad.GetStrList().at( i ), "," );
		
		CEnemyPattern::tagPattern pat;
		
		//出現時間の設定
		SetParameter( pat.m_Time, vecStr.at( 0 ) );
		
		//出現位置の設定
		SetParameter( pat.m_vPos.x, vecStr.at( 1 ) );
		
		SetParameter( pat.m_vPos.y, vecStr.at( 2 ) );
		
		//パターンの設定
		SetParameter( pat.m_Pattern, vecStr.at( 3 ) );
		
		//敵の間隔の設定
		SetParameter( pat.m_Interval, vecStr.at( 4 ) );
		
		//敵の出現数の設定
		SetParameter( pat.m_EnemyNum, vecStr.at( 5 ) );
		
		//m_liEnemyPat.push_back( spPat );
		
		m_vecPat.push_back( pat );
		
		//m_vecEnemyPat.push_back(  );
	}
}


//============================================================================
//初期化
//============================================================================
void CSceneGameMain::Init()
{
	//ハイスコアの読み込み
	LoadHiScore();
	
	m_Time.m_Minute = 2;
	m_Time.m_Second = 0;
	m_GameCounter = 0;
	m_SceneCounter = 0;
	m_HitCount = 0;
	m_HitTime = 0;
	m_GameScore	= 0;
	m_IsGameEnd = false;
	m_IsPause = false;
	m_IsUpdateScore	= false;
	m_IsGameClear = false;


	if( !CCommonObject::GetResMgr()->IsLoading() )
	{
		
		//CCommonObject::GetResMgr()->FindObject("PlaHitFont")->SetVisibleFlag( false );
		//次のシーンに移動
		SetState( &CSceneBase::Idle );
	}
		
}

//============================================================================
//待機中
//============================================================================
void CSceneGameMain::Idle()
{

	//if( !m_IsPause )
	//{	
	//	++m_GameCounter;
	//}
	//
	//CEnemyPattern::tagPattern pat = m_vecPat.at( m_CurPat );
	//
	Renderer::IRender *pRender = CCommonObject::GetAppli()->GetRenderer();
	
	//画面のクリア
	pRender->Clear( );
		
	//描画開始
	pRender->Begin();	
	
	//描画タイプの設定
	//pRender->SetDrawType( DRAW_TYPE_ADD );
	
	
#if 0
#if defined ( DEBUG) | (_DEBUG )

	Peripheral::IKeyboard *pKeyboard = CCommonObject::GetAppli()->GetCore()->GetKeyboard();
	


	if( pKeyboard->GetKeyData( SELENE_VK_1 ) )
	{
		pRender->SetDrawType( DRAW_TYPE_SUB );
	}

	if( pKeyboard->GetKeyData( SELENE_VK_2 ) )
	{
		pRender->SetDrawType( DRAW_TYPE_ADD );
	}

	if( pKeyboard->GetKeyData( SELENE_VK_3 ) )
	{
		pRender->SetDrawType( DRAW_TYPE_ADD_NOALPHA );
	}

	if( pKeyboard->GetKeyData( SELENE_VK_4 ) )
	{
		pRender->SetDrawType( DRAW_TYPE_SUB_NOALPHA );
	}

	if( pKeyboard->GetKeyData( SELENE_VK_5 ) )
	{
		pRender->SetDrawType( DRAW_TYPE_MULTIPLE );
	}

	if( pKeyboard->GetKeyData( SELENE_VK_6 ) )
	{
		pRender->SetDrawType( DRAW_TYPE_BLEND );
	}


#endif

	if( CPlayer::GetHyperMode() )
	{
		pRender->SetDrawType( DRAW_TYPE_BLEND );
	}

	else
	{
		//描画タイプの設定
		pRender->SetDrawType( DRAW_TYPE_NORMAL );
	}

	//全リソースのレンダリング
	CCommonObject::GetResMgr()->RenderingAll();

	if( m_IsPause )
	{
	//	pRender->SetDrawType( DRAW_TYPE)
	}
#endif

	//描画終了
	pRender->End();	
	
	////ゲームカウンターが一定時間になったときに敵を表示
	//if( m_GameCounter == 60 * pat.m_Time )
	//{
	//	CEnemyPattern *pPat = new CEnemyPattern( pat );
	//	
	//	sp<CEnemyPattern> spPat( pPat );
	//	
	//	m_mapEnemyPat.insert( make_pair( m_CurPat, spPat ) );
	//	
	//	++m_CurPat;
	//	
	//}
	//
	//if( m_CurPat > m_vecPat.size() - 1 )
	//{
	//	m_CurPat = m_vecPat.size() - 1;
	//}

	
	////ヒット数の描画
	//DrawHitCount();
	//
	////ハイスコアの描画
	//DrawHiScore();
	//
	////スコアの描画
	//DrawScore();
	//
	////時間の描画
	//DrawTime();
	//
	////ハイスコアを更新したら、書き換える
	//if( m_GameScore > m_HighScore )
	//{
	//	m_HighScore = m_GameScore;
	//}
	//
	//if( m_IsGameEnd )
	//{
	//	//ゲームオーバー画面に移行
	//	CCommonObject::GetGameSceneMgr()->SetNextScene( new CSceneGameOver( "settinggameover.csv" ) );
	//	
	//	if( m_GameScore >= m_InitHighScore )
	//	{
	//		m_IsUpdateScore = true;
	//	}
	//	
	//	//ハイスコアのセーブ
	//	SaveHiScore();
	//	
	//
	//	SetState( &CSceneBase::End );
	//}
	//
	//
	//
	//Pause();
	//
	//if( m_IsRetry )
	//{
	//	CCommonObject::GetGameSceneMgr()->SetDemoFlag( true );
	//	
	//	
	//	//CCommonObject::GetGameSceneMgr()->SetNextScene( new CSceneGameOver("settinggameover.csv") );		
	//	CCommonObject::GetGameSceneMgr()->SetNextScene( new CSceneGameDemo("settingdemo.csv") );
	//		
	//	//	CCommonObject::GetResMgr()->SetDrawMap( m_mapResource );		
	//		
	//	SetState( &CSceneBase::End );		
	//}	
	
	
	//map< Sint32, sp<CEnemyPattern> >::iterator it = m_mapEnemyPat.begin();
	//
	//while( it != m_mapEnemyPat.end() )
	//{
	//	sp<CEnemyPattern> spPat( it->second );
	//	
	//	spPat->Exec();
	//	
	//	if( spPat->GetRemoveFlag() )
	//	{
	//		m_mapEnemyPat.erase( it++ );
	//		
	//	}
	//	
	//	else
	//	{
	//		++it;
	//	}
	//	
	//	//if( spPat
	//}
	




	#if defined ( DEBUG ) | ( _DEBUG )
	
		//if( pKeyboard->GetKeyData( SELENE_VK_F10 ) )
		//{
		//	Retry();
		//	//SetState( &CSceneBase::End );


		//}

//		ランキング用スコアの表示



	
	#endif
	
	#if defined ( RELEASE_TEST )
	
		//::Peripheral::IKeyboard *pKeyboard = CCommonObject::GetAppli()->GetCore()->GetKeyboard();
		//
		////次のパターンに移動
		//if( pKeyboard->GetKeyData( SELENE_VK_1 ) )
		//{
		//	m_GameCounter = pat.m_Time;	
		//}
		//
		////時間を止める
		//if( pKeyboard->GetKeyData( SELENE_VK_2 ) )
		//{
		//	IsStop = !IsStop;
		//}
	
	#endif


	
}

//============================================================================
//終了処理
//============================================================================
void CSceneGameMain::End()
{

	SetState( &CSceneBase::Init );
	

}

//============================================================================
//デモ
//============================================================================
void CSceneGameMain::Demo()
{

}
//============================================================================
//ポーズ中の処理
//============================================================================
void CSceneGameMain::Pause()
{

	::Peripheral::IInputController *pCtrl = CCommonObject::GetJoyPad()->GetController();	
	
	//TOFIX:ダウンキャストを避ける
	sp<CGameObject> spObj = CCommonObject::GetResMgr()->FindObject("Z_PauseFont");

	sp<CPauseFont> spPauFont;

	spPauFont.DownCast( spObj );
	
	static Sint32 Cursor = 0;	

	if( pCtrl->GetState( BUTTON_STATE_PUSH, BUTTON_03 ) )
	{
		Cursor = 0;
		
		m_IsPause = !m_IsPause;
						
		
	}
	
	if( m_IsPause )
	{	
		
		//pRender->DrawTextLayer( 1, Math::Point2DI( 300, 200 ), CColor( 255, 255, 255 ), "PAUSE" );
		
		
		
		pCtrl->CursorRepeatUpDown( 0, Cursor, MENU_MAX );
	
		if( pCtrl->GetState( BUTTON_STATE_PUSH, BUTTON_01 ) )
		{
			if( Cursor == 0 )
			{
				m_IsPause = false;
			}
			
			else if( Cursor == 1 )
			{
				Cursor = 0;			
				
				m_IsPause = false;
				
				m_IsRetry = true;
				
				
				
				SetState( &CSceneBase::End );
			}
			
#if 0

			else if( Cursor == 2 )
			{
				CCommonObject::GetGameSceneMgr()->SetNextScene( new CSceneTitle("settingtitle.csv") );			
				
				Cursor = 0;
				
				SetState( &CSceneBase::End );
				
				
				
			}
#endif
			
		}
		
	
		spPauFont->SetCursor( Cursor );
	
			
		
	
		
		
	}
	
	spPauFont->SetVisibleFlag( m_IsPause );		
}

//============================================================================
//リトライ
//============================================================================
void CSceneGameMain::Retry()
{
	CCommonObject::GetGameSceneMgr()->SetDemoFlag( false );
	
	if( m_IsRetry )
	{

		CCommonObject::GetGameSceneMgr()->SetNextScene( new CSceneTitle("settingtitle.csv") );

		m_IsRetry = false;
	}


	SetState( &CSceneBase::End );	

	//CCommonObject::GetGameSceneMgr()->SetNextScene( new CSceneGameDemo("settingdemo.csv") );
	
	
		

}


//============================================================================
//ハイスコアの読み込み
//============================================================================
void CSceneGameMain::LoadHiScore()
{
	ifstream ifs("score.dat");
	
	//読み込みに失敗したらファイルを生成
	if( ifs.fail() )
	{
		
		ofstream ofs("score.dat");

//			初期値入力
		for( int i = 0;i < SCORELIST_MAX;++i )
		{
			ofs << "0" << endl;
		}

		//再読込み
		ifs.open("score.dat");
	
		
	}
	
//	ランキング用の配列に格納(この時点でソート済みのはず)
	for( int i = 0;i < SCORELIST_MAX;++i )
	{
		string str;

		ifs >> str;


		stringstream ss(str);

		int Score = 0;

		ss >> Score;

		m_arScore[i] = Score;

	}
	
	//	最高スコアを設定
	m_HighScore = m_arScore[SCORELIST_MAX - 1];


	//初期最高スコアを設定
	m_InitHighScore = m_HighScore;
	
}

//============================================================================
//ハイスコアの書き込み
//============================================================================
void CSceneGameMain::SaveHiScore()
{
	ofstream ofs("score.dat");
	
	//ハイスコアの設定
	//既にソートされているから、最初の要素だけを比べればOK
	if( m_GameScore >= m_arScore[0] )
	{
		m_arScore[0] = m_GameScore;

	}


	//ソートするために、multisetに代入
	for( int i = 0;i < SCORELIST_MAX;++i )
	{
		m_setScore.insert( m_arScore[i] );

	}

	multiset<int>::iterator it = m_setScore.begin();

//	ランキングスコアの書き込み
	while( it != m_setScore.end() )
	{
		ofs << *it << endl;

		++it;
	}


	

}



//============================================================================
//ヒット数の描画
//============================================================================
void CSceneGameMain::DrawHitCount()
{
	sp<CGameObject> spObj = CCommonObject::GetResMgr()->FindObject("PlaHitNumFont");
	
	stringstream ss("");
	
	ss << GetHitCount();
	
	//ss << 999;
	
	
	
	if( GetHitCount() >= 999 )
	{
		m_HitCount = 999;
	}
	
	CCommonObject::GetResMgr()->FindObject("PlaHitFont")->SetVisibleFlag( spObj->GetVisibleFlag() );
		
	
	const int HIT_TIME = 60 * 2;
	
	//ヒット数を表示させる時間
	if( ++m_HitTime > HIT_TIME )
	{
		if( GetHitCount() > m_MaxHitCount )
		{	
			m_MaxHitCount = GetHitCount();
			
		}
		
		m_HitTime = 0;
		SetHitCount( 0 );
	}	

}

//============================================================================
//スコアの描画
//============================================================================
void CSceneGameMain::DrawScore()
{
	stringstream ss2("");
	
	ss2 << m_GameScore;
	
	const int MAX_SCORE = 99999;
	
	if( m_GameScore >= MAX_SCORE )
	{
		m_GameScore = MAX_SCORE;
	}
	
	
	
	m_strScore = ss2.str();
	
	//CCommonObject::GetResMgr()->FindObject("ScoreFont")->SetDrawString( ss2.str() );
}

//============================================================================
//ハイスコアの描画
//============================================================================
void CSceneGameMain::DrawHiScore()
{


	
	const int MAX_SCORE = 99999;
	
	if( m_HighScore > MAX_SCORE )
	{
		m_HighScore = MAX_SCORE;
	}
	

}


//============================================================================
//時間の描画
//============================================================================
void CSceneGameMain::DrawTime()
{
	if( !m_IsPause )
	{
		if( m_GameCounter % 60 == 0 )
		{
			m_Time.m_Second--;
		}
		
		if( m_Time.m_Second < 0 )
		{
			m_Time.m_Second = 59;
			m_Time.m_Minute--;
		}
		
		if( m_Time.m_Minute < 0 )
		{
			m_Time.m_Minute = 0;
			m_Time.m_Second = 0;
			m_IsGameEnd = true;
			m_IsGameClear = true;
		}
	}
	
	
	
	
}





