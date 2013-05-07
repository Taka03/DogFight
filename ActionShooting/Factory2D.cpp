//*============================================================================
//Factory2D.cpp
//*============================================================================
#include "Factory2D.h"
#include "FontSprite.h"
#include "FileData.h"
#include "ResourceManager.h"

//============================================================================
//コンストラクタ
//============================================================================
CFactory2D::CFactory2D(void)
{
}

//============================================================================
//デストラクタ
//============================================================================
CFactory2D::~CFactory2D(void)
{
}

//============================================================================
//2Dオブジェクトの取得
//============================================================================
//[input]
//	pFile:ファイルデータ
//[return]
//	取得した2Dオブジェクト
//===========================================================================
CGameObject *CFactory2D::Get2DObject( CFileData *pFile )
{
	//TOFIX:関数ポインタ使ってまとめられないか
	//テンプレートつかっていける?
	//void (*pFunc)( const char *pName, const char *pDataName )[]
	//{
	//	CSprite
	//}
	
	
	//スプライトの場合
	if( pFile->GetTypeName() == "SPRITE" )
	{
		return new CSprite( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str() );
	}
	
	else if( pFile->GetTypeName() == "READY" )
	{
		return new CReadyTex( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str() );
	}

	//フォントの場合
	else if( pFile->GetTypeName() == "FONT" )
	{
		return new CFontSprite( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str() );
	}
	
//	時間フォントの場合
	else if( pFile->GetTypeName() == "TIMEFONT" )
	{
		return new CTimeFont( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str() );
	}
	
	else if( pFile->GetTypeName() == "PAUSEFONT" )
	{
		return new CPauseFont( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str() );
	}

	else if( pFile->GetTypeName() == "SCOREFONT" )
	{
		return new CScoreFont( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str() );
	}

	else if( pFile->GetTypeName() == "HITFONT" )
	{
		return new CHitFont( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str() );
	}


	else if( pFile->GetTypeName() == "MULTISPR" )
	{
		return new CMultiSprite( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str() );
	}

//	TODO:
	else if( pFile->GetTypeName() == "GAMESPR" )
	{
		return new CGameFont( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str() );
	}

	else if( pFile->GetTypeName() == "START" )
	{
		return new CPushStart( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str() );
	}

	//キャラクターの場合
	else if( pFile->GetTypeName() == "CHARA" )
	{
		return new CCharacter( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str() );
	}
	
	//プレイヤーの場合
	else if( pFile->GetTypeName() == "PLAYER" )
	{
		return new CPlayer( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str() );
	}
	
	//弾の場合
	else if( pFile->GetTypeName() == "BULLET" )
	{
		return new CBullet( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(), pFile->GetPos() );
	}
	
	//敵の弾の場合
	else if( pFile->GetTypeName() == "EBULLET" )
	{
		return new CEnemyBullet( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(), pFile->GetPos() );
	}
	
	//自機狙い弾の場合
	else if( pFile->GetTypeName() == "AIMSHOOT" )
	{
		return new CAimShoot( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(), pFile->GetPos() );
	}
	
	else if( pFile->GetTypeName() == "MISSILE" )
	{
		return new CMissile( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(), pFile->GetPos() );
	}
	
	//敵の場合
	else if( pFile->GetTypeName() == "ENEMY" )
	{
		return new CEnemy( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(), pFile->GetPos() );
	}
	
	//敵(小型機2)の場合
	else if( pFile->GetTypeName() == "ENE_SMALL_2" )
	{
		return new CEnemySmall2( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(), pFile->GetPos() );
	}
	
	//敵(回転)の場合
	else if( pFile->GetTypeName() == "ENE_ROLL" )
	{
		return new CEnemyRoll( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(), pFile->GetPos() );
	}
	
	//敵(カーブ)の場合
	else if( pFile->GetTypeName() == "ENE_CURVE" )
	{
//		return new CEnemyCurve( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(), pFile->GetPos() );
	}
	
	//敵(中型1)の場合
	else if( pFile->GetTypeName() == "ENE_MID_1" )
	{
		return new CEnemyMiddle1( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(), pFile->GetPos() );
	}
	
	//敵(砲台)の場合
	else if( pFile->GetTypeName() == "ENE_CANNON" )
	{
		return new CEnemyCannon( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(), pFile->GetTargetObject() );
	}
	
	//エフェクトの場合
	else if( pFile->GetTypeName() == "EFFECT" )
	{
		return new CEffect( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(), pFile->GetPos() );
	}
	
	//エフェクト(剣)の場合
	else if( pFile->GetTypeName() == "EFFECT_S" )
	{
		return new CEffectSword( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(), 
								 pFile->GetPos() );
	}
	
	//エフェクト(爆発)の場合
	else if( pFile->GetTypeName() == "EFFECT_B" )
	{
		return new CEffectBomb( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(), 
								pFile->GetPos() );
	}
	
	else if( pFile->GetTypeName() == "EFFECT_TB" )
	{
		return new CEffectTrBomb( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(),
									pFile->GetPos() );
	}


	//エフェクト(最大チャージ)の場合
	else if( pFile->GetTypeName() == "EFFECT_MC" )
	{
		return new CEffectMaxCharge( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(),
									pFile->GetPos() );
	}

	else if( pFile->GetTypeName() == "EFFECT_FR" )
	{
		return new CEffectFire( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(),
				pFile->GetTargetObject() );
	}


	else if( pFile->GetTypeName() == "EFFECT_SH" )
	{
		return new CEffectShot( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(),
									pFile->GetPos() );
	}


	else if( pFile->GetTypeName() == "EFFECT_BT" )
	{
		return new CEffectBurst( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(),
									pFile->GetPos() );
	}


	else if( pFile->GetTypeName() == "EFFECT_SL" )
	{
		return new CEffectSlash( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(),
								  pFile->GetPos() );
	}


	//エフェクト(点滅)の場合
	else if( pFile->GetTypeName() == "EFFECT_F" )
	{
		return new CEffectFlash( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(),
							 	 pFile->GetPos() );
	}
	
	//エフェクト(光球)
	else if( pFile->GetTypeName() == "EFFECT_P" )
	{
		return new CEffectPhoton( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(),
								 pFile->GetPos() );
	}

	
	//背景の場合
	else if( pFile->GetTypeName() == "BG" )
	{
		return new CBackGraphic( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str() );
	}
	
	else if( pFile->GetTypeName() == "GAUGE" )
	{
		return new CGauge( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str() );
	}

	//その他の場合は何も取得しない
	return NULL;
	
}

