//*============================================================================
//SceneGameMain.h
//*============================================================================
/**
* ゲームシーンクラス
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "SceneBase.h"
#include "EnemyPattern.h"

#include <set>

//=============================================================================
//const
//=============================================================================
const int SCORELIST_MAX = 10;

//=============================================================================
//class
//=============================================================================
class CSceneGameMain :public CSceneBase
{
	public:
	
		struct tagTime
		{
			Sint32 m_Minute;//分
			Sint32 m_Second;//秒
			
			tagTime()
			{
				m_Minute = 0;
				m_Second = 0;
			}
		};///@brief 時間
		
	private:
	
		static Uint32 m_HitCount;///<@brief ヒット数
		static Uint32 m_MaxHitCount;///@brief 最大ヒット数
		static Uint32 m_HitTime;///<@brief ヒット時間
		static Uint32 m_GameScore;///<@brief スコア
		static bool m_IsPause;///@brief ポーズ中判定フラグ
		Uint32 m_InitHighScore;///@brief 初期最高スコア
		static Uint32 m_HighScore;///<@brief 最高スコア
		
		int m_SceneCounter;//シーンカウンター
		
		int m_GameCounter;///<@brief ゲームカウンター
		static tagTime m_Time;///<@brief 時間
		static bool m_IsGameEnd;///<@brief ゲーム終了判定フラグ
		static bool m_IsUpdateScore;///@brief ハイスコアを更新したか
		
		Sint32 m_CurPat;///@brief 現在の敵パターン
		
		map< Sint32, sp<CEnemyPattern> > m_mapEnemyPat;///<@brief 敵のパターン
		vector< CEnemyPattern::tagPattern > m_vecPat;

		static multiset<int> m_setScore;///<@brief ランキングスコア	用

		int m_arScore[SCORELIST_MAX];///<@brief ランキングスコア用配列

		bool m_IsRetry;
		//list< sp<CEnemyPattern> > m_liEnemyPat;
		
		//CEnemyPattern m_EnemyPat;///<@brief 敵のパターン
		
		static string m_strScore;///<@brief スコアの文字列
		static string m_strMaxHitNum;///<@brief スコアの最大ヒット数
		static bool m_IsGameClear;///<@brief ゲームクリアフラグ
	
	public:
	
		/**
		* @brief コンストラクタ
		* @param pDataName データファイル名
		*/
		CSceneGameMain( const char *pDataName );
		
		/**
		* @brief デストラクタ
		*/
		virtual ~CSceneGameMain(void);
		
		/**
		* @brief 初期化
		*/
		virtual void Init();
		
		/**
		* @brief 待機中
		*/
		virtual void Idle();
		
		///**
		//* @brief 更新
		//* @return 現在のシーンの状態
		//*/
		//virtual eSceneState Update();
		//
		/**
		* @brief 終了
		*/
		virtual void End();
		
		/**
		 * @brief デモ
		 */
		void Demo();
		
		/**
		 * @brief メイン
		 */
		void Main();

		/**
		* @brief ハイスコアの読み込み
		*/
		void LoadHiScore();
		
		
		/**
		* @brief ハイスコアのセーブ
		*/
		void SaveHiScore();
		
		
		/**
		* @brief ヒット数の描画
		*/
		void DrawHitCount();
		
		/**
		* @brief スコアの描画
		*/
		void DrawScore();
		
		/**
		* @brief ハイスコアの描画
		*/
		void DrawHiScore();
		
		/**
		* @brief スコアの描画
		*/
		void DrawTime();
		
		/**
		* @brief 敵パターンの読み込み
		*/
		void LoadPattern( );
		
		//ポーズ中の処理
		void Pause();
		
		/**
		 * @brief リトライ
		 */
		void Retry();

		
		
	//Set系
	public:
	
		/**
		* @brief ヒットカウントの設定
		* @param count 設定するカウント
		*/
		static void SetHitCount( int count )
		{
			m_HitCount = count;
		}
		
		/**
		* @brief ヒット数の増加
		*/
		static void AddHitCount()
		{
			++m_HitCount;
		}
		
		/**
		* @brief ヒット時間の設定
		* @param count 設定するヒット時間
		*/
		static void SetHitTime( int time )
		{
			m_HitTime = time;
		}
	
		/**
		* @brief ヒット時間の増加
		*/
		static void AddHitTime()
		{
			++m_HitTime;
		}
		
		/**
		* @brief スコアの増加
		* @param Score 加算するスコア
		*/
		static void AddScore( const Uint32 Score )
		{
			m_GameScore += Score;
		}
		
		/**
		* @brief ゲーム終了フラグのセット
		* @param flag セットするフラグ
		*/
		static void SetGameEndFlag( bool flag )
		{
			m_IsGameEnd = flag;
		}
		
		/**
		* @brief ポーズフラグのセット
		* @param flag セットするフラグ
		*/
		static void SetPauseFlag( bool flag )
		{
			m_IsPause = flag;
		}
		
	//Get系
	public:
	
		/**
		* @brief ヒット時間の取得
		* @return ヒット時間
		*/
		static Uint32 GetHitTime()
		{
			return m_HitTime;
		}
		
		/**
		* @brief ヒット数の取得
		* @return ヒット数
		*/
		static Uint32 GetHitCount()
		{
			return m_HitCount;
		}
		
		static Uint32 GetMaxHitCount()
		{
			return m_MaxHitCount;
		}

		/**
		* @brief ポーズフラグの取得
		* @return ポーズフラグ
		*/
		static bool GetPauseFlag() 
		{
			return m_IsPause;
		}
		
		static string GetStrScore()
		{
			return m_strScore;
		}
		
		static string GetStrMaxHit()
		{
			return m_strMaxHitNum;
		}
		
		static bool GetUpdateScore()
		{
			return m_IsUpdateScore;
		}
		
		static int GetGameScore()
		{
			return m_GameScore;
		}

		static int GetHighScore()
		{
			return m_HighScore;
		}
	
		/**
		 * @brief ランキングスコアの取得
		 * @return ランキングスコア
		 */
		static multiset<int> GetSetScore()
		{
			return m_setScore;
		}


		/**
		 * @brief ゲーム時間の取得
		 * @return ゲーム時間
		 */
		static tagTime GetTime()
		{
			return m_Time;
		}

		/**
		 *
		 * @return
		 */
		static bool GetGameClearFlag()
		{
			return m_IsGameClear;
		}

				
		
		
		
		
};
