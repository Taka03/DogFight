//*============================================================================
//Character.h
//*============================================================================
/**
* キャラクタークラス
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "sprite.h"

//=============================================================================
//class
//=============================================================================
class CCharacter :	public CSprite
{
	protected:
	
		float m_fSpeed;///<@brief 移動スピード
		
	private:
	
		/**
		* @brief 移動補正
		*/
		virtual void MoveAdjust();
	
		
	public:
		
		/**
		* @brief コンストラクタ
		* @param pName ファイル名
		* @param pDataName データ名
		*/
		CCharacter( const char *pName, const char *pDataName );
		
		/**
		* @brief デストラクタ
		*/
		virtual ~CCharacter(void);
		
		/**
		* @brief 移動処理
		*/
		virtual void Move(){};
		
		/**
		* @brief 処理
		*/
		void Exec();
		
		/**
		* @brief パラメーターの読み込み
		* @param pFileName ファイル名
		*/
		void LoadParameter( const char *pFileName ){};
		
		/**
		* @brief アニメーションの設定
		*/
		virtual void SetAnimation();
		
		/**
		* @brief 当たった時の処理
		* @param spObj 判定するオブジェクト
		*/
		virtual void HitExec( sp<CGameObject> spObj ){};
		
		/**
		* @brief 状態毎の処理
		*/
		virtual void StateExec();
		
		
	//Set系
	public:
	
		/**
		* @brief キャラクター状態の設定
		* @param eState 設定するキャラクター状態
		*/
		//void SetState( eCharaState eState )
		//{
		//	m_eState = eState;
		//}
	
	//Get系
	public:
	
		
		
		///**
		//* @brief キャラクター状態の取得
		//* @return キャラクター状態
		//*/
		//eCharaState GetState() const
		//{
		//	return m_eState;
		//}
		
};
