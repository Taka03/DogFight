//*============================================================================
//EnemyPattern.h
//*============================================================================
/**
* 敵パターンクラス
*/

#pragma once

//=============================================================================
//include
//=============================================================================
#include "CommonObject.h"
#include <string>
#include <vector>

//=============================================================================
//namespace
//=============================================================================
using namespace std;

//=============================================================================
//class
//=============================================================================
class CEnemyPattern 

{
	
	public:
	
		enum eEnemyPat
		{
			PAT_STEP, //階段状
			PAT_ROLL, //回転
			PAT_CURVE, //カーブ
			PAT_STRAIGHT,//直進(上)
			PAT_AIMING,//自機狙い
			PAT_MIDDLE,//中型機
		};///@brief 敵のパターン
		
		struct tagPattern
		{
			Sint32 m_Time;//出現時間
			Math::Vector2D m_vPos;//出現位置
			Sint32 m_Pattern;//敵のパターン
			Sint32 m_Interval;//敵の出てくる間隔
			Sint32 m_EnemyNum;//出てくる敵の数
			
			tagPattern() 
			{
				m_Time = 0;
				m_vPos.x = 0;
				m_vPos.y = 0;
				m_Pattern = 0;
				m_Interval = 0;
				m_EnemyNum = 0;
				
			}
		};///@brief 敵パターン
	
	private:
	
		tagPattern m_EnemyPat;///@brief 敵のパターン
		Uint32 m_Counter;///@brief 汎用カウンター
		Uint32 m_EnemyCount;///@brief 敵カウンター
		Sint32 m_CurPat;///<@brief 現在のパターン
		bool m_IsRemoved;///@brief 消去判定フラグ
		
		static Uint32 m_SmallEnemyNum;//@brief 小型機数
		
		Sint32 m_Angle;///@brief 汎用角度
			
	public:
	
		/**
		* @brief コンストラクタ
		*/
		CEnemyPattern( tagPattern Pat);
		
		/**
		* @brief デストラクタ
		*/
		virtual ~CEnemyPattern(void);
		
		
		/**
		* @brief 生成処理
		*/
		void Exec();
		
		
		/**
		* @brief 階段状の移動
		*/
		void MoveStep();

		/**
		* @brief TODO:回転の移動
		*/
		void MoveRoll();
		
		/**
		* @brief カーブの移動
		*/
		void MoveCurve();
		
		/**
		* @brief 直進の移動
		*/
		void MoveStraight( );

		/**
		* @brief 自機狙いの移動
		*/
		void MoveAiming();
		
		/**
		* @brief 中型機の移動
		*/
		void MoveMiddleEnemy();
		
	//Set系
	public:
	
		void SetRemoveFlag( bool flag )
		{
			m_IsRemoved = flag;
		}
		
	//Get系
	public:
	
		bool GetRemoveFlag() const
		{
			return m_IsRemoved;
		}
		
		tagPattern GetPattern() const
		{
			return m_EnemyPat;
		}
	
};
