//*============================================================================
//common.h
//*============================================================================
/**
 * ���ʃw�b�_�[
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
const int FRAME_RATE = 60;//�t���[�����[�g
const int SCREEN_WIDTH = 800;//�X�N���[���̕�
const int SCREEN_HEIGHT = 600;//�X�N���[���̍���

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
 * @brief �p�����[�^�[�̐ݒ�
 * @param value �ݒ��̒l
 * @param strSource �ݒ茳�̒l
 * @return ����������true�B�����Ȓl���ݒ肳�ꂽ�ꍇ��false�B
 */
template< class T >
void SetParameter( T &value, string strSource )
{
	istringstream iss( strSource );

	iss >> value;

}

