//*============================================================================
//FileLoader.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "FileLoader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "Common/Application.h"
#include "CommonObject.h"

//=============================================================================
//�R���X�g���N�^
//=============================================================================
//[input]
//	pName:�t�@�C����
//=============================================================================
CFileLoader::CFileLoader( const char *pName )
{
	m_StrList.clear();
	
	Load( pName );
}

//=============================================================================
//�t�@�C���ǂݍ���
//=============================================================================
//[input]
//	strFilePath:�t�@�C���ǂݍ��ݐ�
//[return]
//	�t�@�C���ǂݍ��݂ɐ���������
//=============================================================================
bool CFileLoader::Load( string strFilePath )
{
	File::IFileManager *pFileMgr = CCommonObject::GetAppli()->GetFileMgr();
	
	pFileMgr->SetCurrentPath( "CSV" );
	
	File::IResourceFile *pResFile = pFileMgr->FileOpen( strFilePath.c_str() );
	
	if( pResFile->IsInvalid() )
	{
		printf("No File");
		return false;
	}

	//TOFIX:�P���Ƀp�X�ǂݍ��ނ���
	ifstream ifs( pResFile->GetNamePointer() );
	
	SAFE_RELEASE( pResFile );
	
	if( ifs.fail() )
	{
		return false;	
	}
	
	char Temp[256];
	
	ifs.getline( Temp, 256 );
	
	while( !ifs.eof() )
	{
		string line(Temp);
		
//		1�s�ڂ�"#"�̎��́A�R�����g�Ƃ��Ĉ���
		if( line.substr( 0, 1 ).compare("#") != 0 )
		{
			//�s�������łȂ��ꍇ
			if( line.length() > 0 )
			{
				m_StrList.push_back( line );
			}
		}
		
		ifs.getline( Temp, 256 );
	}
	
	ifs.close();
	
	return true;
}

//=============================================================================
//������̕���
//=============================================================================
//[input]
//	strSource:���ɂȂ镶����
//	strDelim:�������镶��
//=============================================================================
vector<string> CFileLoader::SplitString( std::string strSource, std::string strDelim )
{
	vector<string> strRet;
	
	/*�����������������Ƃ�����L��*/
	size_t Delim = strSource.find( strDelim );
	
	//����������������Ȃ��Ȃ�܂Ń��[�v
	while( Delim != -1 )
	{
		/*����*/
		string strVal = strSource.substr( 0, Delim );
		
		//�����s�łȂ������烊�X�g�ɒǉ�
		if( strVal.length() > 0 )
		{
			strRet.push_back( strVal );
		}
		
		/*���̕���������Ɉړ�*/
		strSource = strSource.substr( Delim + strDelim.size() );
		
		Delim = strSource.find( strDelim );
	}
	
	/*�Ō�̕����������*/
	if( strSource.length() > 0 )
	{
		strRet.push_back( strSource );
	}
	
	return strRet;
}

