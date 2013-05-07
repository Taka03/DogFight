//*============================================================================
//common.h
//*============================================================================
/**
 * 共通ヘッダー
 */
#pragma once

//=============================================================================
//lib
//=============================================================================
#if 0//defined ( DEBUG ) | (_DEBUG )

	#pragma comment( lib, "Selene_D.lib" )
#else
	#pragma comment( lib, "Selene.lib" )
#endif

//=============================================================================
//include
//=============================================================================
#include "Selene.h"
#include <string>
#include <crtdbg.h>
#include <assert.h>
#include "dixsmartptr.h"
#include <sstream>

//=============================================================================
//namespace
//=============================================================================
using namespace Selene;
using namespace std;
using namespace Dix;

//=============================================================================
//class
//=============================================================================
class CGameObject;

//=============================================================================
//const
//=============================================================================
const int FRAME_RATE = 60;//フレームレート
const int SCREEN_WIDTH = 800;//スクリーンの幅
const int SCREEN_HEIGHT = 600;//スクリーンの高さ

//=============================================================================
//struct
//=============================================================================

//typedef pair< string, const sp<CGameObject> > str_pair;
//
//struct str_pair_less
//{
//  bool operator()(const str_pair& x, const str_pair& y) const 
//  {
//    return x.first < y.first;
//  }
//};
//
//struct str_pair_equal
//{
//  bool operator()(const str_pair& x, const str_pair& y) const 
//  {
//    return x.first == y.first;
//  }
//};


/**
 * @brief パラメーターの設定
 * @param value 設定先の値
 * @param strSource 設定元の値
 * @return 成功したらtrue。無効な値が設定された場合はfalse。
 */
template< class T >
void SetParameter( T &value, string strSource )
{
	istringstream iss( strSource );

	iss >> value;

}

