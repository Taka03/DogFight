//*============================================================================
//BGM.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "BGM.h"
#include "CommonObject.h"
#include "Common/Application.h"

//=============================================================================
//コンストラクタ
//=============================================================================
//[input]
//	pName:データ名
//=============================================================================
CBGM::CBGM( const char *pName ) 
 :m_pBGM(NULL),
  CSoundObject( pName )
{
	Load();
}


//=============================================================================
//デストラクタ
//=============================================================================
CBGM::~CBGM(void)
{
	SAFE_RELEASE( m_pBGM );
}

//=============================================================================
//サウンドの読み込み
//=============================================================================
bool CBGM::Load( )
{
	ICore *pCore = CCommonObject::GetAppli()->GetCore();
	File::IFileManager *pFileMgr = CCommonObject::GetAppli()->GetFileMgr();
	
	pFileMgr->SetCurrentPath("BGM");
	
	printf("LOAD BGM[%s]", m_strFileName.c_str() );

	m_pBGM = pCore->CreateStreamSoundFromFile( m_strFileName.c_str(), false, "OggVorbis" );
	
	_ASSERT( m_pBGM );
	
	if( m_pBGM == NULL )
	{
		return false;
	}
	
	printf( "                 : -> %s\n", m_pBGM->IsInvalid() ? "Failed" : "Succeeded" );
		
	return true;
	
}

//=============================================================================
//サウンドの再生
//=============================================================================
//[input]
//	pTbl:再生テーブル
//	count:テーブル数
//=============================================================================
//void CBGM::Play( Sound::SPlayBlock *pTbl, int count )
//{
//	m_pBGM->Play( pTbl, count );
//}

//=============================================================================
//サウンドの再生
//=============================================================================
void CBGM::Play()
{
	m_pBGM->Play( -1 );
}

//=============================================================================
//サウンドの停止
//=============================================================================
void CBGM::Stop()
{
	m_pBGM->Stop();
}


//=============================================================================
//フェードアウト
//=============================================================================
void CBGM::FadeOut()
{
	static int count = 0;
	
	while( count <= 60 )
	{
	
		float fVolume = Interpolation::Flat( 100.0f, 0.0f, 60, count );
		
		m_pBGM->SetVolume( fVolume );
		
		count++;
		

	}
	
	if( count >= 60 )
	{
		count = 0;
	}

	
}

