//*============================================================================
//ResourceManager.h
//*============================================================================
//[history]
//	08/10/01　作成
//[author]
//	Taka
//[ref]
//	SeleneSampleコード
//=============================================================================
#pragma once

//=============================================================================
//include
//=============================================================================
#include "Common/Application.h"
#include "FileData.h"
#include "Sound.h"

#include <map>
#include <vector>

//=============================================================================
//const
//=============================================================================
const int QUE_MAX = 2;

//=============================================================================
//class
//=============================================================================
//[Desc]
//	リソース管理クラス
//============================================================================
class CResourceManager
{
	public:
	
		//オブジェクトタイプ
		enum eObjType
		{
			OBJ_2D,//2D描画オブジェクト
			OBJ_3D, //3D描画オブジェクト
			OBJ_SND,//サウンドオブジェクト
		};
	
	private:
		
		Thread::CThread m_Thread;
		Thread::CCriticalSection m_CS;
		Thread::CEvent m_Event;
		
		CFileData *m_pQueTop[QUE_MAX];
		Sint32 m_Page;
		
		eObjType m_eObjType;//オブジェクトタイプ
		
		//描画マップ
		map< string, sp<CGameObject> > m_mapDraw;
		
		//描画マップのイテレータ
		map< string, sp<CGameObject> >::iterator m_itDraw;
		
	private:
	
		/*生成メソッド*/
		typedef void (CResourceManager::*CreateFunc)( CFileData *pFile );
	
		//起動
		virtual void Run();
		
		//ロード用スレッド
		static void LoadProc( void *pData );
	
	public:	
	
		//コンストラクタ
		CResourceManager( );
		
		//デストラクタ
		virtual ~CResourceManager();
		
		/*リソースの追加*/
		virtual void Push( CFileData *pFile );
		
		//オブジェクトの取得
		sp<CGameObject> FindObject( const char *pName );
		
		//サウンドオブジェクトの取得
		CSoundObject *FindSoundObject( const char *pName );
		
		//オブジェクトの削除
		void RemoveObject( const char *pDataName );
		
		//サウンドオブジェクトの削除
		void RemoveSoundObject( const char *pDataName );
		
		//すべてのオブジェクトの削除
		void RemoveAll();
		
		//全リソースのレンダリング
		void RenderingAll();
		
		//更新
		void Update();
		
		//全リソースの処理
		void ExecAll();
		
		/**
		* @brief 全リソースの当たり判定処理
		*/
		void HitCheckAll();
		
		/*ロード中*/
		virtual Bool IsLoading();
		
	private:
	
		//リストへ追加
		void AppendList( string strDataName, sp<CGameObject> spGameObj );
		
		//サウンドリストへ追加
		void AppendSoundList( string strDataName, CSoundObject *pSndObj );
		
		/*タイプの判定*/
		void CheckType( CFileData *pFile );
		
	//Set系
	public:
	
		/**
		* @brief 描画マップのセット
		* @param mapDraw 設定する描画マップ
		*/
		void SetDrawMap( map< string, sp<CGameObject> > mapDraw )
		{
			m_mapDraw = mapDraw;
		}
		
	//Get系
	public:
	
		map< string, sp<CGameObject> > GetDrawMap() const
		{
			return m_mapDraw;
		}
		
};

