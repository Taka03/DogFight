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
//コンストラクタ
//=============================================================================
//[input]
//	pName:ファイル名
//=============================================================================
CFileLoader::CFileLoader( const char *pName )
{
	m_StrList.clear();
	
	Load( pName );
}

//=============================================================================
//ファイル読み込み
//=============================================================================
//[input]
//	strFilePath:ファイル読み込み先
//[return]
//	ファイル読み込みに成功したか
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

	//TOFIX:単純にパス読み込むだけ
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
		
//		1行目が"#"の時は、コメントとして扱う
		if( line.substr( 0, 1 ).compare("#") != 0 )
		{
			//行が無効でない場合
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
//文字列の分割
//=============================================================================
//[input]
//	strSource:元になる文字列
//	strDelim:分割する文字
//=============================================================================
vector<string> CFileLoader::SplitString( std::string strSource, std::string strDelim )
{
	vector<string> strRet;
	
	/*分割文字を見つけたところを記憶*/
	size_t Delim = strSource.find( strDelim );
	
	//分割文字が見つからなくなるまでループ
	while( Delim != -1 )
	{
		/*分割*/
		string strVal = strSource.substr( 0, Delim );
		
		//無効行でなかったらリストに追加
		if( strVal.length() > 0 )
		{
			strRet.push_back( strVal );
		}
		
		/*次の分割文字列に移動*/
		strSource = strSource.substr( Delim + strDelim.size() );
		
		Delim = strSource.find( strDelim );
	}
	
	/*最後の文字列を入れる*/
	if( strSource.length() > 0 )
	{
		strRet.push_back( strSource );
	}
	
	return strRet;
}

