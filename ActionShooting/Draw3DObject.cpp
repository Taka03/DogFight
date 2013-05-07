//*===========================================================================
//Draw3DObject.cpp
//*===========================================================================

//============================================================================
//include
//============================================================================
#include "Draw3DObject.h"
#include "FileLoader.h"

//============================================================================
//コンストラクタ
//============================================================================
//[input]
//	pName:ファイル名
//	pDataName:データ名
//===========================================================================
CDraw3DObject::CDraw3DObject( const char *pName, const char *pDataName ) 
: CDrawObject( pName ),
  m_vPos( 0, 0, 0 ),
  m_vInitPos( m_vPos ),
  m_Rot( 0, 0, 0 ),
  m_InitRot( m_Rot ),
  m_fScale( 1.0f, 1.0f, 1.0f ),
  m_fInitScale( m_fScale ),
  m_ActorIndex( SCREEN_MAIN )
{
	
	LoadParameter( pDataName );
}

//=============================================================================
//デストラクタ
//=============================================================================
CDraw3DObject::~CDraw3DObject(void)
{
}

//=============================================================================
//初期化
//=============================================================================
void CDraw3DObject::Init()
{
	m_vPos = m_vInitPos;
	m_Rot = m_InitRot;
	m_fScale = m_fInitScale;
}


//=============================================================================
//処理
//=============================================================================
void CDraw3DObject::Exec()
{
}

//=============================================================================
//移動処理
//=============================================================================
void CDraw3DObject::MoveExec()
{
}



//=============================================================================
//レンダリング
//=============================================================================
void CDraw3DObject::Rendering( )
{
	
}

//=============================================================================
//パラメーターの読み込み
//=============================================================================
//[input]
//	pDataName:データファイル名
//[return]
//	ファイル読み込みに成功したか
//=============================================================================
void CDraw3DObject::LoadParameter( const char *pDataName )
{
	//TOFIX:できればファイルひとつひとつじゃなくて、そのファイルひとつですべて読み込めるように
	//HOWTO:インデックス作って、SplitStringのat数字で切り分けるとか
	CFileLoader FileLoad( pDataName );
	
	//文字列の分割読み込み
	vector< string > vecStr = CFileLoader::SplitString( FileLoad.GetStrList().at( 0 ), "," );
	
	//ファイル名の取得
	SetParameter( m_strFileName, vecStr.at( 0 ) );
	
	//----------------------------------------------------------------------------
	//位置の設定
	//----------------------------------------------------------------------------
	SetParameter( m_vInitPos.x, vecStr.at( 1 ) );
	
	SetParameter( m_vInitPos.y, vecStr.at( 2 ) );
	
	SetParameter( m_vInitPos.z, vecStr.at( 3 ) );
	
	//----------------------------------------------------------------------------
	//角度の設定
	//----------------------------------------------------------------------------
	SetParameter( m_InitRot.x, vecStr.at( 4 ) );
	
	SetParameter( m_InitRot.y, vecStr.at( 5 ) );
	
	SetParameter( m_InitRot.z, vecStr.at( 6 ) );
	
	//----------------------------------------------------------------------------
	//拡縮の設定
	//----------------------------------------------------------------------------
	SetParameter( m_fInitScale.x, vecStr.at( 7 ) );
	
	SetParameter( m_fInitScale.y, vecStr.at( 8 ) );
	
	SetParameter( m_fInitScale.z, vecStr.at( 9 ) );
}


//=============================================================================
//アクターの生成
//=============================================================================
//[input]
//	pSceneMgr:シーン管理用デバイス
//=============================================================================
void CDraw3DObject::CreateActor( int index, Scene::ISceneManager *pSceneMgr )
{
}


//=============================================================================
//当たり判定のチェック
//=============================================================================
//[input/output]
//	ppChara:判定するキャラ
//[return]
//	当たったかどうか
//=============================================================================
bool CDraw3DObject::HitCheck( CDraw3DObject **ppChara )
{
	//list<ListData>::iterator i;
	//
	//for( i = m_ObjectList.begin();i != m_ObjectList.end();++i )
	//{
	//	CDraw3DObject *obj = dynamic_cast<CDraw3DObject *>( i->gameobj );
	//	
	//	if( obj->GetObjectType() == OBJ_ENEMY && this->HitCheck( &obj ) )
	//	{
	//		*ppChara = obj;
	//		return true;
	//	}
	//		
	//}
	
	return false;
}

//=============================================================================
//当たり判定のチェック
//=============================================================================
//[input]
//	vRay:判定用のレイ
//[return]
//	当たったかどうか
//=============================================================================
bool CDraw3DObject::HitCheck( Collision::CLine3D &vRay )
{
	//list<ListData>::iterator i;
	//
	//for( i = m_ObjectList.begin();i != m_ObjectList.end();++i )
	//{
	//	CDraw3DObject *pChara = dynamic_cast<CDraw3DObject *>( i->gameobj );
	//	
	//	if( pChara->HitCheck( vRay ) )
	//	{
	//		return true;
	//	}
	//}
	
	return false;
}

//=============================================================================
//当たり判定のチェック
//=============================================================================
//[input]
//	vRay:判定用のレイ
//	ppHitObj:当たったオブジェクトの取得
//[output]
//	obj:衝突したオブジェクト	
//[return]
//	当たったかどうか
//=============================================================================
bool CDraw3DObject::HitCheck( Selene::Collision::CLine3D &vRay, CDraw3DObject **ppHitObj )
{
	//list<ListData>::iterator i;
	//
	//for( i = m_ObjectList.begin();i != m_ObjectList.end();++i )
	//{
	//	CDraw3DObject *pChara = dynamic_cast<CDraw3DObject *>( i->gameobj );
	//	
	//	if( pChara->HitCheck( vRay ) )
	//	{
	//		*ppHitObj = pChara;
	//		return true;
	//	}
	//}
	
	return false;
}


//=============================================================================
//当たり判定のチェック
//=============================================================================
//[input]
//	vRay:判定用のレイ
//	Out:衝突判定の結果
//[return]
//	当たったかどうか
//=============================================================================
bool CDraw3DObject::HitCheck( Collision::CLine3D &vRay, Renderer::SCollisionResult &Out )
{
	//list<ListData>::iterator i;
	//
	//for( i = m_ObjectList.begin();i != m_ObjectList.end();++i )
	//{
	//	CDraw3DObject *pChara = dynamic_cast<CDraw3DObject *>( i->gameobj );
	//	
	//	if( pChara->HitCheck( vRay, Out ) )
	//	{
	//		return true;
	//	}
	//}
	
	return false;
}

//=============================================================================
//当たり判定のチェック
//=============================================================================
//[input]
//	vRay:判定用のレイ
//	Out:衝突判定の結果
//[output]
//	ppHitObj:当たったオブジェクト
//[return]
//	当たったかどうか
//=============================================================================
bool CDraw3DObject::HitCheck( Collision::CLine3D &vRay, Renderer::SCollisionResult &Out, CDraw3DObject **ppHitObj )
{
	//list<ListData>::iterator i;
	//
	//for( i = m_ObjectList.begin();i != m_ObjectList.end();++i )
	//{
	//	CDraw3DObject *pChara = dynamic_cast<CDraw3DObject *>( i->gameobj );
	//	
	//	if( pChara->HitCheck( vRay, Out ) )
	//	{
	//		*ppHitObj = pChara;
	//		
	//		return true;
	//	}
	//}
	
	return false;
}

//=============================================================================
//アクターインデックスのセット
//=============================================================================
//[input]
//	index:設定するインデックス
//=============================================================================
void CDraw3DObject::SetActorIndex( int index )
{
	m_ActorIndex = index;
	//list<ListData>::iterator i;
	//
	//for( i = m_ObjectList.begin();i != m_ObjectList.end();++i )
	//{
	//	CDraw3DObject *pChara = dynamic_cast<CDraw3DObject *>( i->gameobj );
	//	
	//	pChara->SetActorIndex( index );		
	//}
}
