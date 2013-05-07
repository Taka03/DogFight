//*============================================================================
//FileData.h
//*============================================================================
/**
*ファイルデータ用クラス
*/

#pragma once

//=============================================================================
//include
//=============================================================================
#include "Player.h"
#include "Bullet.h"
#include "enemy.h"
#include "EnemyBullet.h"
#include "AimShoot.h"
#include "BackGraphic.h"
#include "EffectSword.h"
#include "EffectBomb.h"
#include "EffectFlash.h"
#include "Missile.h"
#include "EnemyRoll.h"
#include "EnemyMiddle1.h"
#include "EnemyCannon.h"
#include "EnemyCurve.h"
#include "EnemySmall2.h"
#include "TimeFont.h"
#include "Gauge.h"
#include "EffectTrBomb.h"
#include "ReadyTex.h"
#include "EffectPhoton.h"
#include "PauseFont.h"
#include "MultiSprite.h"
#include "ScoreFont.h"
#include "HitFont.h"
//TODO:
#include "GameFont.h"
#include "PushStart.h"
#include "EffectMaxCharge.h"
#include "EffectFire.h"
#include "EffectShot.h"
#include "EffectBurst.h"
#include "EffectSlash.h"

//=============================================================================
//class
//=============================================================================
class CFileData
{
	friend class CResourceManager;
	
	private:

		CFileData *m_pNext;///<@brief 次のデータ
		
		string m_strTypeName;///<@brief タイプ名
		
		string m_strFileName;///<@brief ファイル名
		string m_strDataName;///<@brief データ名
		
		string m_strDataFileName;///<@brief データファイル名
		
		Math::Vector2D m_vPos;///<@brief 位置
		
		string m_DrawStr;///@brief 表示文字
		
		CGameObject *m_pObj;///@brief オブジェクト
		
	public:

		/**
		* @brief コンストラクタ
		*/
		CFileData(){}
		
		/**
		* @brief コンストラクタ
		* @param pFileName　ファイル名
		* @param pDataName データ名
		* @param pTypeName タイプ名
		* @param pDatFileName データファイル名
		*/
		CFileData( const char *pFileName, const char *pDataName,
				   const char *pTypeName, const char *pDatFileName );

		/**
		* @brief コンストラクタ
		* @param pFileName　ファイル名
		* @param pDataName データ名
		* @param pTypeName タイプ名
		* @param pDatFileName データファイル名
		* @param vPos 設定する位置
		*/
		CFileData( const char *pFileName, const char *pDataName,
				   const char *pTypeName, const char *pDatFileName, Math::Vector2D vPos );
				   
		/**
		* @brief コンストラクタ
		* @param pFileName　ファイル名
		* @param pDataName データ名
		* @param pTypeName タイプ名
		* @param pDatFileName データファイル名
		* @param pObj 設定するオブジェクト
		*/
		CFileData( const char *pFileName, const char *pDataName,
				   const char *pTypeName, const char *pDatFileName, CGameObject *pObj);
				   
				   
		/**
		* @brief コンストラクタ
		* @param pFileName　ファイル名
		* @param pDataName データ名
		* @param pTypeName タイプ名
		* @param pDatFileName データファイル名
		* @param str 描画文字
		*/
		CFileData( const char *pFileName, const char *pDataName,
				   const char *pTypeName, const char *pDatFileName, string str );
				   
		
		/**
		* @brief デストラクタ
		*/
		~CFileData(){}
		
	/*Set系*/
	public:
	
		/**
		* @brief 後方リストの設定
		* @param pData ファイルポインタ
		*/
		void SetNext( CFileData *pData )
		{
			m_pNext = pData;
		}
		
	/*Get系*/
	public:

		/**
		* @brief ファイル名の取得
		* @return ファイル名
		*/
		string GetFileName() const
		{
			return m_strFileName;
		}
		
		/**
		* @brief データ名の取得
		* @return データ名
		*/
		string GetDataName() const
		{
			return m_strDataName;
		}
		
		/**
		* @brief タイプ名の取得
		* @return タイプ名
		*/
		string GetTypeName() const
		{
			return m_strTypeName;
		}
		
		/**
		* @brief データファイル名の取得
		* @return データファイル名
		*/
		string GetDataFileName() const
		{
			return m_strDataFileName;
		}
		
		/**
		* @brief 位置の取得
		* @return 位置
		*/
		Math::Vector2D GetPos() const
		{
			return m_vPos;
		}
		
		/**
		* @brief 描画文字の取得
		* @return 描画文字
		*/
		string GetDrawStr() const
		{
			return m_DrawStr;
		}
		
		CGameObject *GetTargetObject() const
		{
			return m_pObj;
		}
		
		/**
		* @brief 後方リストの取得
		* @return 後方リスト
		*/
		CFileData *GetNext( void ) const
		{
			return m_pNext;
		}

};
