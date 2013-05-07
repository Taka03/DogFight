//*============================================================================
//Effect.h
//*============================================================================
/**
* エフェクトクラス
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "character.h"

//=============================================================================
//class
//=============================================================================
class CEffect :	public CCharacter
{
	protected:
	
		enum eEffectState
		{
			STATE_NONE,//何もない状態
			STATE_DIED,//死んだ状態
		};///<@brief エフェクトの状態
		
		eEffectState m_eState;///<@brief エフェクトの状態
		
	public:
		
		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		* @param pDataName データ名
		* @param vPos 設定する位置
		*/
		CEffect( const char *pName, const char *pDataName, Math::Vector2D vPos );
		
		/**
		* @brief デストラクタ
		*/
		~CEffect(void);
		
		/**
		* @brief 移動
		*/
		void Move();
		
		/**
		* @brief 処理
		*/
		//void Exec();
		
		virtual bool HitCheck( sp<CGameObject> spObj );
		
		/**
		* @brief 当たった時の処理
		* @param spObj 判定するオブジェクト
		*/
		virtual void HitExec( sp<CGameObject> spObj );
		
		/**
		* @brief 状態毎の処理
		*/
		virtual void StateExec();
		
		
};
