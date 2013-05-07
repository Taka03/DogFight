//*============================================================================
//Application.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "FileData.h"

//=============================================================================
//コンストラクタ
//=============================================================================
//[input]
//	pFileName:ファイル名
//	pDataName:データ名
//	pTypeName:タイプ名
//	pDatFileName:データファイル名
//=============================================================================
CFileData::CFileData( const char *pFileName, const char *pDataName, 
					  const char *pTypeName, const char *pDatFileName ) 
:m_strFileName( pFileName ),
 m_strDataName( pDataName ),
 m_pNext( NULL ),
 m_strTypeName( pTypeName ),
 m_strDataFileName( pDatFileName )

{

}

//=============================================================================
//コンストラクタ
//=============================================================================
//[input]
//	pFileName:ファイル名
//	pDataName:データ名
//	pTypeName:タイプ名
//	pDatFileName:データファイル名
//	pObj:設定するオブジェクト
//=============================================================================
CFileData::CFileData( const char *pFileName, const char *pDataName, 
					  const char *pTypeName, const char *pDatFileName, CGameObject *pObj ) 
:m_strFileName( pFileName ),
 m_strDataName( pDataName ),
 m_pNext( NULL ),
 m_strTypeName( pTypeName ),
 m_strDataFileName( pDatFileName ),
 m_pObj( pObj )
{

}

//=============================================================================
//コンストラクタ
//=============================================================================
//[input]
//	pFileName:ファイル名
//	pDataName:データ名
//	pTypeName:タイプ名
//	pDatFileName:データファイル名
//	vPos:位置
//=============================================================================
CFileData::CFileData( const char *pFileName, const char *pDataName, 
					  const char *pTypeName, const char *pDatFileName, Math::Vector2D vPos ) 
:m_strFileName( pFileName ),
 m_strDataName( pDataName ),
 m_pNext( NULL ),
 m_strTypeName( pTypeName ),
 m_strDataFileName( pDatFileName ),
 m_vPos( vPos )

{

}




//=============================================================================
//コンストラクタ
//=============================================================================
//[input]
//	pFileName:ファイル名
//	pDataName:データ名
//	pTypeName:タイプ名
//	pDatFileName:データファイル名
//	str:描画文字
//=============================================================================
CFileData::CFileData( const char *pFileName, const char *pDataName, 
					  const char *pTypeName, const char *pDatFileName, string str ) 
:m_strFileName( pFileName ),
 m_strDataName( pDataName ),
 m_pNext( NULL ),
 m_strTypeName( pTypeName ),
 m_strDataFileName( pDatFileName ),
 m_DrawStr( str )

{

}