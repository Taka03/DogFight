//*============================================================================
//Sprite.h
//*============================================================================
//[history]
//	08/03/19　作成
//[author]
//	Taka
//============================================================================
#pragma once

//=============================================================================
//include
//=============================================================================
#include "common.h"
#include "gameobject.h"

//=============================================================================
//class
//=============================================================================
//[Desc]
//	スプライト描画用オブジェクト
//=============================================================================
class CSprite :	public CGameObject
{
	protected:
	
		Renderer::ITexture *m_pTex;///<@brief テクスチャ用ハンドル
		Renderer::Object::ISprite2D *m_pSpr;///<@brief スプライト用ハンドル
	
		Math::Point2DI m_DivNum;///<@brief 分割数
		Math::Point2DI m_Anim;///<@brief アニメID
		
		Sint32 m_AnimSpeed;///<@brief アニメーション速度
		
		Math::Point2DF m_fSize;///<@brief 画像サイズ
		
		Sint32 m_AnimTime;///<@brief アニメーション時間
		Sint32 m_AnimCount;///<@brief アニメーションカウンタ
		
		Math::Rect2DF m_HitRect;///<@brief 当たり判定用矩形
		
		Math::Rect2DF m_DstRect;///<@brief 描画先矩形
		Math::Rect2DF m_SrcRect;///<@brief 描画元矩形
		
		bool m_IsAnim;///<@brief アニメーションさせるか
		
		Math::Vector2D m_vCenterPos;///<@brief 中心点
		
		Math::Rect2DF m_AdjHitRect;///@brief 補正判定サイズ
		
		Uint32 m_AnimNum;///<@brief アニメ数
		
		bool m_IsAuto;///<@brief 自動分割するか
		
		bool m_IsReverse;///@brief 逆再生するか
		
		Uint8 m_Alpha;///@brief アルファ値
		
		float m_fBlendRate;///@brief アルファ率

		CColor m_Color;///@brief 色
		
		
		

	public:
	
		CSprite( const char *pName, const char *pDataName );//コンストラクタ

		/**
		 *
		 * @param vecStr
		 * @return
		 */
		CSprite( vector<string> vecStr );//コンストラクタ
		virtual ~CSprite(void);//デストラクタ
		
		
		virtual void Init();
		
		virtual bool Load();//ファイル読み込み

		virtual void Exec();//処理
		
		void Rendering();//レンダリング
		
		virtual void DrawRequest();//描画リクエスト
		
		void LoadParameter( const char *pFileName );//パラメーターの読み込み
		
		void LoadParameter( vector<string> vecStr );//パラメーターの読み込み

		void DrawGrayScale( Renderer::IRender *pRender );//グレースケール描画
		
		/**
		* @brief アニメーションの設定
		*/
		virtual void SetAnimation();
		
		/**
		* @brief 当たり判定
		* @param spObj 判定するオブジェクト
		* @retval true 当たっている
		* @retval false 当たっていない
		*/
		virtual bool HitCheck( sp<CGameObject> spObj );
		
		/**
		* @brief 当たった時の処理
		* @param spObj 判定するオブジェクト
		*/
		virtual void HitExec( sp<CGameObject> spObj ){};
		
		
		
	private:
	
		void CreateSprite( Renderer::IRender *pRender, Uint32 Num );//スプライトの生成 
	
		
	/*Set系*/
	public:
	
		
		//分割数の設定	
		void SetDivNum( Math::Point2DI divnum )
		{
			m_DivNum = divnum;
			
			_ASSERT( m_DivNum.x > 0 );
			_ASSERT( m_DivNum.y > 0 );
			
			divnum.x = 1;
			divnum.y = 1;
			
			m_fSize.x = toF( m_pTex->GetOriginalSize().x / divnum.x );
			m_fSize.y = toF( m_pTex->GetOriginalSize().y / divnum.y );
			
		}
		
		
		/*X方向分割数の設定*/
		void SetDivNumX( int x )
		{
			SetDivNum( Math::Point2DI( x, m_DivNum.y ) );
		}
		
		/*Y方向分割数の設定*/
		void SetDivNumY( int y )
		{
			SetDivNum(  Math::Point2DI( m_DivNum.x, y ) );
		}
		
		////アニメーションIDの設定
		//void SetAnimID( Uint32 anim )
		//{
		//	m_AnimID = anim;
		//}
		
		/*画像サイズの設定*/
		void SetGraphSize( Math::Point2DF Size )
		{
			m_fSize = Size;
		}
		
		/*アニメーションフラグの設定*/
		void SetAnimFlag( bool flag )
		{
			m_IsAnim = flag;
		}
		
		/*描画先矩形の設定*/
		void SetDstRect( Math::Rect2DF Dst )
		{
			m_DstRect = Dst;
		}
		
		/*描画元矩形の設定*/
		void SetSrcRect( Math::Rect2DF Src )
		{
			m_SrcRect = Src;
		}
		
	/*Get系*/
	public:

		//テクスチャ用ハンドルの取得
		Selene::Renderer::ITexture *GetTexture() const
		{
			return m_pTex;
		}
		
		/*画像サイズの取得*/
		Math::Point2DF GetSize() const
		{
			return m_fSize;
		}
		
		/*当たり判定矩形の取得*/
		virtual Math::Rect2DF GetHitRect() const
		{
			return m_HitRect;
		}
		
		////アニメIDの取得
		//Uint32 GetAnimID() const
		//{
		//	return m_AnimID;
		//}
		
		
		
};
