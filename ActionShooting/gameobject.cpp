//*============================================================================
//gameobject.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "gameobject.h"
#include "selene.h"

//=============================================================================
//コンストラクタ
//=============================================================================
//[input]
//	pName:ファイル名
//	pDataName:データファイル名
//===========================================================================
CGameObject::CGameObject( const char *pName, const char *pDataName ) 
:m_strFileName( pName ),
 m_strDataName( pDataName ), 
 m_IsVisible( true ),
 m_IsStop( false ),
 m_IsRemoved( false ),
 m_IsHit( false ),
 m_vInitPos( 0, 0 ),
 m_InitAngle( 0 ),
 m_fInitScale( 1, 1 ),
 m_vPos( 0, 0 ),
 m_Angle( 0 ),
 m_fScale( 1, 1 ),
 m_spTargetObj( NULL ),
 m_IsRemEnd( false )
 
{
	
}

//=============================================================================
//コンストラクタ
//=============================================================================
//[input]
//	pName:ファイル名
//	pDataName:データファイル名
//===========================================================================
CGameObject::CGameObject( vector<string> vecStr )
:m_strFileName( "" ),
 m_strDataName( "" ),
 m_IsVisible( true ),
 m_IsStop( false ),
 m_IsRemoved( false ),
 m_IsHit( false ),
 m_vInitPos( 0, 0 ),
 m_InitAngle( 0 ),
 m_fInitScale( 1, 1 ),
 m_vPos( 0, 0 ),
 m_Angle( 0 ),
 m_fScale( 1, 1 ),
 m_spTargetObj( NULL ),
 m_IsRemEnd( false )

{

}


//=============================================================================
//デストラクタ
//=============================================================================
CGameObject::~CGameObject()
{
	
}


