//*============================================================================
//Factory2D.cpp
//*============================================================================
#include "Factory2D.h"
#include "FontSprite.h"
#include "FileData.h"
#include "ResourceManager.h"

//============================================================================
//�R���X�g���N�^
//============================================================================
CFactory2D::CFactory2D(void)
{
}

//============================================================================
//�f�X�g���N�^
//============================================================================
CFactory2D::~CFactory2D(void)
{
}

//============================================================================
//2D�I�u�W�F�N�g�̎擾
//============================================================================
//[input]
//	pFile:�t�@�C���f�[�^
//[return]
//	�擾����2D�I�u�W�F�N�g
//===========================================================================
CGameObject *CFactory2D::Get2DObject( CFileData *pFile )
{
	//TOFIX:�֐��|�C���^�g���Ă܂Ƃ߂��Ȃ���
	//�e���v���[�g�����Ă�����?
	//void (*pFunc)( const char *pName, const char *pDataName )[]
	//{
	//	CSprite
	//}
	
	
	//�X�v���C�g�̏ꍇ
	if( pFile->GetTypeName() == "SPRITE" )
	{
		return new CSprite( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str() );
	}
	
	else if( pFile->GetTypeName() == "READY" )
	{
		return new CReadyTex( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str() );
	}

	//�t�H���g�̏ꍇ
	else if( pFile->GetTypeName() == "FONT" )
	{
		return new CFontSprite( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str() );
	}
	
//	���ԃt�H���g�̏ꍇ
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

	//�L�����N�^�[�̏ꍇ
	else if( pFile->GetTypeName() == "CHARA" )
	{
		return new CCharacter( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str() );
	}
	
	//�v���C���[�̏ꍇ
	else if( pFile->GetTypeName() == "PLAYER" )
	{
		return new CPlayer( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str() );
	}
	
	//�e�̏ꍇ
	else if( pFile->GetTypeName() == "BULLET" )
	{
		return new CBullet( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(), pFile->GetPos() );
	}
	
	//�G�̒e�̏ꍇ
	else if( pFile->GetTypeName() == "EBULLET" )
	{
		return new CEnemyBullet( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(), pFile->GetPos() );
	}
	
	//���@�_���e�̏ꍇ
	else if( pFile->GetTypeName() == "AIMSHOOT" )
	{
		return new CAimShoot( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(), pFile->GetPos() );
	}
	
	else if( pFile->GetTypeName() == "MISSILE" )
	{
		return new CMissile( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(), pFile->GetPos() );
	}
	
	//�G�̏ꍇ
	else if( pFile->GetTypeName() == "ENEMY" )
	{
		return new CEnemy( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(), pFile->GetPos() );
	}
	
	//�G(���^�@2)�̏ꍇ
	else if( pFile->GetTypeName() == "ENE_SMALL_2" )
	{
		return new CEnemySmall2( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(), pFile->GetPos() );
	}
	
	//�G(��])�̏ꍇ
	else if( pFile->GetTypeName() == "ENE_ROLL" )
	{
		return new CEnemyRoll( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(), pFile->GetPos() );
	}
	
	//�G(�J�[�u)�̏ꍇ
	else if( pFile->GetTypeName() == "ENE_CURVE" )
	{
//		return new CEnemyCurve( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(), pFile->GetPos() );
	}
	
	//�G(���^1)�̏ꍇ
	else if( pFile->GetTypeName() == "ENE_MID_1" )
	{
		return new CEnemyMiddle1( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(), pFile->GetPos() );
	}
	
	//�G(�C��)�̏ꍇ
	else if( pFile->GetTypeName() == "ENE_CANNON" )
	{
		return new CEnemyCannon( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(), pFile->GetTargetObject() );
	}
	
	//�G�t�F�N�g�̏ꍇ
	else if( pFile->GetTypeName() == "EFFECT" )
	{
		return new CEffect( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(), pFile->GetPos() );
	}
	
	//�G�t�F�N�g(��)�̏ꍇ
	else if( pFile->GetTypeName() == "EFFECT_S" )
	{
		return new CEffectSword( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(), 
								 pFile->GetPos() );
	}
	
	//�G�t�F�N�g(����)�̏ꍇ
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


	//�G�t�F�N�g(�ő�`���[�W)�̏ꍇ
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


	//�G�t�F�N�g(�_��)�̏ꍇ
	else if( pFile->GetTypeName() == "EFFECT_F" )
	{
		return new CEffectFlash( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(),
							 	 pFile->GetPos() );
	}
	
	//�G�t�F�N�g(����)
	else if( pFile->GetTypeName() == "EFFECT_P" )
	{
		return new CEffectPhoton( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str(),
								 pFile->GetPos() );
	}

	
	//�w�i�̏ꍇ
	else if( pFile->GetTypeName() == "BG" )
	{
		return new CBackGraphic( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str() );
	}
	
	else if( pFile->GetTypeName() == "GAUGE" )
	{
		return new CGauge( pFile->GetFileName().c_str(), pFile->GetDataFileName().c_str() );
	}

	//���̑��̏ꍇ�͉����擾���Ȃ�
	return NULL;
	
}

