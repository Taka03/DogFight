//*============================================================================
//Application.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "FileData.h"

//=============================================================================
//�R���X�g���N�^
//=============================================================================
//[input]
//	pFileName:�t�@�C����
//	pDataName:�f�[�^��
//	pTypeName:�^�C�v��
//	pDatFileName:�f�[�^�t�@�C����
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
//�R���X�g���N�^
//=============================================================================
//[input]
//	pFileName:�t�@�C����
//	pDataName:�f�[�^��
//	pTypeName:�^�C�v��
//	pDatFileName:�f�[�^�t�@�C����
//	pObj:�ݒ肷��I�u�W�F�N�g
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
//�R���X�g���N�^
//=============================================================================
//[input]
//	pFileName:�t�@�C����
//	pDataName:�f�[�^��
//	pTypeName:�^�C�v��
//	pDatFileName:�f�[�^�t�@�C����
//	vPos:�ʒu
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
//�R���X�g���N�^
//=============================================================================
//[input]
//	pFileName:�t�@�C����
//	pDataName:�f�[�^��
//	pTypeName:�^�C�v��
//	pDatFileName:�f�[�^�t�@�C����
//	str:�`�敶��
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