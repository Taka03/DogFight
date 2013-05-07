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
#include "SoundObject.h"

#include <map>
#include <vector>
#include <list>

//=============================================================================
//define
//=============================================================================
//#define RELEASE_TEST


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
		
		CFileData *m_pQueTop[QUE_MAX];
		Sint32 m_Page;
		
		eObjType m_eObjType;//オブジェクトタイプ
		
		bool m_IsLoadEnd;//ロード終了フラグ
		
		//描画マップ
		map< string, sp<CGameObject> > m_mapDraw;
		
		//ヒットしているオブジェクトの追加
		list< sp<CGameObject> > m_liHitObj;
		
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
		
		/**
		 * リソースの追加
		 * @param pObj 追加するオブジェクト
		 */
		void Push( CGameObject *pObj );
		
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
			m_mapDraw.clear();
			m_IsLoadEnd = false;
			m_mapDraw = mapDraw;

		}
		
	//Get系
	public:

		/**
		 * 描画マップの取得
		 * @return 描画マップ
		 */
		map< string, sp<CGameObject> > GetDrawMap() const
		{
			return m_mapDraw;
		}
		
		list< sp<CGameObject> > GetHitObjList() const
		{
			return m_liHitObj;
		}
		
};

