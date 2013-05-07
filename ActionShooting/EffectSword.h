//*============================================================================
//EffectSword.h
//*============================================================================
/**
* エフェクト(剣)クラス
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "Effect.h"

//=============================================================================
//class
//=============================================================================
class CEffectSword :	public CEffect
{
	private:
	
		int m_ExistCount;
		
		static Uint32 m_HitCount;///<@brief ヒット数
	
	public:
		
		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		* @param pDataName データ名
		* @param vPos 設定する位置
		*/
		CEffectSword( const char *pName, const char *pDataName, Math::Vector2D vPos );
		
		/**
		* @brief デストラクタ
		*/
		~CEffectSword(void);
		
		/**
		* @brief 処理
		*/
		void Exec();
		
		/**
		* @brief 当たった時の処理
		* @param spObj 判定するオブジェクト
		*/
		virtual void HitExec( sp<CGameObject> spObj );
		
		/**
		* @brief 状態毎の処理
		*/
//		virtual void StateExec();
		
	
	//Set系
	public:
		
		/**
		* @brief ヒットカウントの設定
		* @param count 設定するヒットカウント
		*/
		static void SetHitCount( const Uint32 count )
		{
			m_HitCount = count;
		}
		
		/**
		* @brief ヒットカウントの増加
		*/
		static void AddHitCount( )
		{
			++m_HitCount;
		}
		
	//Get系
	public:
	
		
};
