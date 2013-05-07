//*============================================================================
//SceneBase.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "SceneBase.h"
#include "gameobject.h"
#include "ResourceManager.h"
#include "FileLoader.h"

//============================================================================
//コンストラクタ
//============================================================================
//[input]
//	pDataName:データファイル名
//============================================================================
CSceneBase::CSceneBase( const char *pDataName ) 
:m_eSceneState( SCENE_STANDBY ),
 m_ResName( pDataName )
{
	SetState( &CSceneBase::Init );
}

//============================================================================
//デストラクタ
//============================================================================
CSceneBase::~CSceneBase(void)
{
//	TODO:シーンと同時に削除するフラグが立っていたら、そのオブジェクトを削除
	map< string, sp<CGameObject> > mapDraw = CCommonObject::GetResMgr()->GetDrawMap();

	map< string, sp<CGameObject> >::iterator it = mapDraw.begin();

	while( it != mapDraw.end() )
	{
		sp<CGameObject> spObj = it->second;

		if( spObj != NULL && spObj->GetRemEndFlag() )
		{
			spObj->SetRemoveFlag( true );
		}

		it++;
	}




	//m_mapResource.clear();
}


//============================================================================
//リソースファイルの読み込み
//============================================================================
//[input]
//	pDataName:データファイル名
//============================================================================
bool CSceneBase::LoadResourceFile( const char *pDataName )
{
	
	bool IsLoadEnd = false;

	CFileLoader FileLoad( pDataName );
	
	int Size = FileLoad.GetStrList().size();
	
	for( int i = 0;i < Size; ++i )
	{
		vector< string > vecStr = CFileLoader::SplitString( FileLoad.GetStrList().at( i ), "," );
		
		string strFileName = vecStr.at( 0 );
		
		string strDataName = vecStr.at( 1 );
		
		string strTypeName = vecStr.at( 2 );
		
		string strDataFileName = vecStr.at( 3 ); 
		
		//リソースの追加
		CCommonObject::GetResMgr()->Push( new CFileData( strFileName.c_str(), strDataName.c_str(),
														 strTypeName.c_str(), strDataFileName.c_str() ) );
		
	}
	
	
	
	IsLoadEnd = true;

	return IsLoadEnd;

	
}


//============================================================================
//更新
//============================================================================
CSceneBase::eSceneState CSceneBase::Update()
{
	( this->*m_pStateFunc )( );

	
	return m_eSceneState;
}

