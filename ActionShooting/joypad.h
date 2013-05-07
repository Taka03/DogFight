//*============================================================================
//joypad.h
//*============================================================================
/**
* ジョイパッドクラス
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "common.h"

//=============================================================================
//class
//=============================================================================
//[desc]
//	ジョイパッド用クラス
//=============================================================================
class CJoyPad 
{
	public:
	
	private:
	
		static Peripheral::IInputController *m_pController;//コントローラー用デバイス
		Peripheral::IJoystick		 *m_pJoystick;//ジョイスティック用デバイス
		
	public:
	
		/**
		* @brief コンストラクタ
		*/
		CJoyPad();
		
		/**
		* @brief デストラクタ
		*/
		virtual ~CJoyPad();
		
	public:
	
		/**
		* @brief デバイスの作成
		* @param pCore コアデバイス
		*/
		void CreateDevice( ICore *pCore );
		
		/**
		* @brief 初期化
		*/
		void Initialize();	
		
		/**
		* @brief 更新
		*/
		void Update();
		
		/**
		* @brief 参照カウンタ増加
		*/
		void AddRef();
		
	/*Get系*/
	public:
	
		/**
		* @brief コントローラー用デバイスの取得
		* @return コントローラー用デバイス
		*/		
		Peripheral::IInputController *GetController() const
		{
			return m_pController;
		}
		
		/**
		* @brief ジョイスティック用デバイスの取得
		* @return ジョイスティック用デバイス
		*/		
		Peripheral::IJoystick *GetJoyStick() const
		{
			return m_pJoystick;
		}

};
