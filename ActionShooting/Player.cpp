//*============================================================================
//Player.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "Player.h"
#include "joypad.h"
#include "ResourceManager.h"
#include "Bullet.h"
#include "FileLoader.h"
#include "Common/Application.h"
#include "EffectSword.h"
#include "GameSceneManager.h"
#include "SceneGameMain.h"
#include "SoundManager.h"
#include "Gauge.h"

//=============================================================================
//variable
//=============================================================================
float CPlayer::m_fGaugeAdd = 0.0f;
float CPlayer::m_fGaugeAddShot = 0.0f;
bool CPlayer::m_IsHyperMode = false;
bool CPlayer::m_IsSlashEnd = false;

//============================================================================
//�R���X�g���N�^
//============================================================================
//[input]
//	pName:�t�@�C����
//	pDataName:�f�[�^�t�@�C����
//===========================================================================
CPlayer::CPlayer( const char *pName, const char *pDataName )
:CCharacter( pName, pDataName ),
 m_HitNum( 0 ),
 m_HitCount( 0 ),
 m_AdjustSize( 20, 0 ),
 m_IsMove( false ),
 m_IsShoot( false ),
 m_IsSlash( false ),
 m_InvTime( 0 ),
 m_Time( 0 ),
 m_eState( STATE_NONE ),
 m_ShootCount( -1 ),
 m_fGaugeSub( 0 ),
 m_SwordTime( 0 ),
 m_IsNoSword( false ),
 m_ShadowNum( 4 ),
 m_Count( 0 )

{
	m_eState = STATE_NONE;

	bool IsDemo = CCommonObject::GetGameSceneMgr()->GetDemoFlag();

	m_vecShadowPos.clear();

	//m_vecShadowPos.resize( m_ShadowNum );

	m_vecColor.clear();

	//m_vecColor.resize( m_ShadowNum );

	memset( m_vShadowPos, 0, SHADOW_NUM );
	//memset(m_ShadowColor, -1, SHADOW_NUM );


	m_eType = CCharacter::TYPE_PLAYER;
	
	LoadParameter( pDataName );

	CFileLoader FileLoad("game.csv");

	vector< string > vecStr = CFileLoader::SplitString( FileLoad.GetStrList().at( 0 ), "," );

	//�c�@���̐ݒ�
	SetParameter( m_Stock, vecStr.at( 0 ) );

	SetParameter( m_fGaugeAdd, vecStr.at( 1 ) );

	SetParameter( m_fGaugeAddShot, vecStr.at( 2 ) );

	SetParameter( m_fGaugeSub, vecStr.at( 3 ) );
	
	SetParameter( m_fSpeed, vecStr.at( 4 ) );






	
}

//============================================================================
//�f�X�g���N�^
//============================================================================
CPlayer::~CPlayer(void)
{
	m_IsHyperMode = false;
}

//============================================================================
//�����_�����O
//============================================================================
void CPlayer::Rendering()
{
	Renderer::IRender *pRender = CCommonObject::GetAppli()->GetRenderer();
	
	//pRender->DrawTextLayer( 0, Math::Point2DI( 0, 200 ), CColor( 255, 0, 0 ), "State:%d", m_eState );
	
	pRender->SetDrawType( DRAW_TYPE_BLEND );

	m_pSpr->Rendering();

	pRender->SetDrawType( DRAW_TYPE_NORMAL );


}

//============================================================================
//����
//============================================================================
void CPlayer::Exec()
{
	bool IsDemo = CCommonObject::GetGameSceneMgr()->GetDemoFlag();

	
	

	//�A�^�b�N����
	//if( !m_IsShoot )
	//{
		Attack();
	//}

	//�V���b�g����
	Shoot();
	
	
	
	

		

//	�o�����
	if( m_IsHyperMode )
	{
//		�Q�[�W�����������Ă���
		CGauge::AddGauge( m_fGaugeSub );

		if( CGauge::GetGaugeVal() < 0 )
		{
			m_IsHyperMode = false;
		}




	}

	//�Q�[���I�[�o�[����
	if( m_Stock <= 0 )
	{
		m_Stock = 0;
		m_eState = STATE_NONE;
		this->SetRemoveFlag( true );
		CSceneGameMain::SetGameEndFlag( true );
	}
	
	
	//�X�g�b�N�̕`��
	if( !IsDemo )
	{	
		DrawStock();
	}
	
	//static int count = 0;

	//count += DEG_TO_ANGLE(1);

	//m_Color.r = Abs( Math::Sin( count ) * 255.0f );

	Renderer::IRender *pRender = CCommonObject::GetAppli()->GetRenderer();

	CCharacter::Exec();
	
	//pRender->DrawTextureTile( m_DstRect, CColor( 255, 255, 255, 255), m_SrcRect, m_pTex, m_Angle, Math::Point2DF( 0, 0 ) );

	//pRender->DrawBlur( m_DstRect, CColor( 255, 255, 255, 255), m_SrcRect, m_pTex, m_Angle, Math::Point2DF( 0, 0 ) );



	
}

//============================================================================
//�`�惊�N�G�X�g
//============================================================================
void CPlayer::DrawRequest()
{
	/*�����蔻��̈�̃Z�b�g*/
	m_HitRect.Set( m_vPos.x + m_AdjHitRect.x, m_vPos.y + m_AdjHitRect.y,
				   m_fSize.x * m_fScale.x - m_AdjHitRect.w,
				   m_fSize.y * m_fScale.y - m_AdjHitRect.h );

	/*�`��J�n*/
	m_pSpr->Begin();

/*��]�t���`��*/
	m_pSpr->DrawSquareRotateC( m_DstRect, m_SrcRect,
	Math::Vector3D( m_vPos.x + m_vCenterPos.x, m_vPos.y + m_vCenterPos.y, 0 ), m_Color, m_Angle );
	
	if( m_IsMove && GetHyperMode() )
	{
		for( int i = 0;i < m_ShadowNum;++i )
		{
			/*�`���*/
			m_DstRect.Set( m_vShadowPos[i].x, m_vShadowPos[i].y, m_fSize.x * m_fScale.x, m_fSize.y * m_fScale.y );

			m_pSpr->DrawSquareRotateC( m_DstRect, m_SrcRect,
			Math::Vector3D( m_vPos.x + m_vCenterPos.x, m_vPos.y + m_vCenterPos.y, 0 ), m_ShadowColor[i], m_Angle );


		}
	}
	
		

	/*�`��I��*/
	m_pSpr->End();
}

//============================================================================
//�X�g�b�N�̕`��
//============================================================================
void CPlayer::DrawStock()
{
	stringstream ss("");
	
	ss << "X " << m_Stock;
	
	sp<CGameObject> spObj = CCommonObject::GetResMgr()->FindObject("PlaStockFont");
	
	if( spObj != NULL )
	{
		sp<CFontSprite> spFont;
		
		spFont.DownCast( spObj );	
		spFont->SetDrawString( ss.str() );
	}

}


//============================================================================
//�p�����[�^�[�̓ǂݍ���
//============================================================================
//[input]
//	pFileName:�t�@�C����
//===========================================================================
void CPlayer::LoadParameter( const char *pFileName )
{
	CFileLoader FileLoad( pFileName );
	
	vector< string > vecStr = CFileLoader::SplitString( FileLoad.GetStrList().at( 0 ), "," );
	
	//----------------------------------------------
	//�ʒu�̐ݒ�
	//----------------------------------------------
	SetParameter( m_vInitPos.x, vecStr.at( 0 ) );
	
	SetParameter( m_vInitPos.y, vecStr.at( 1 ) );
	
	//----------------------------------------------
	//�p�x�̐ݒ�
	//----------------------------------------------
	SetParameter( m_InitAngle, vecStr.at( 2 ) );
	
	//----------------------------------------------
	//�g�k���̐ݒ�
	//----------------------------------------------
	SetParameter( m_fInitScale.x, vecStr.at( 3 ) );
	
	SetParameter( m_fInitScale.y, vecStr.at( 4 ) );
	
	//----------------------------------------------
	//�������̐ݒ�
	//----------------------------------------------
	SetParameter( m_DivNum.x, vecStr.at( 5 ) );
	
	SetParameter( m_DivNum.y, vecStr.at( 6 ) );
	
	//----------------------------------------------
	//�A�j���[�V�����̐ݒ�
	//----------------------------------------------
	SetParameter( m_IsAnim, vecStr.at( 7 ) );
	
	SetParameter( m_AnimTime, vecStr.at( 8 ) );
	
	SetParameter( m_AnimNum, vecStr.at( 9 ) );
	
	//----------------------------------------------
	//���G���Ԃ̐ݒ�
	//----------------------------------------------
	SetParameter( m_InvTime, vecStr.at( 10 ) );
	
	//----------------------------------------------
	//�����蔻��␳�T�C�Y�̐ݒ�
	//----------------------------------------------
	SetParameter( m_AdjHitRect.x, vecStr.at( 11 ) );
	
	SetParameter( m_AdjHitRect.y, vecStr.at( 12 ) );
	
	SetParameter( m_AdjHitRect.w, vecStr.at( 13 ) );

	SetParameter( m_AdjHitRect.h, vecStr.at( 14 ) );
	
	for( Uint32 i = 1;i < m_AnimNum + 1;++i )
	{
		vecStr = CFileLoader::SplitString( FileLoad.GetStrList().at( i ), "," );
		
		int Anim = 0;
		
		SetParameter( Anim, vecStr.at( 1 ) );
		
		m_vecAnimNum.push_back( Anim );		
		
		//for( int j = 0;j < Anim;++j )
		//{
			int AnimTime = 0;
		
			SetParameter( AnimTime, vecStr.at( 2 ) );
			
			m_vecAnimTime.push_back( AnimTime );
		//}
	}
	
}

//============================================================================
//�ړ�
//============================================================================
void CPlayer::Move()
{
	Peripheral::IInputController *pCtrl = CCommonObject::GetJoyPad()->GetController();
	
	static int count = 0;
	static int Num = 0;
	
	//���Ɉړ�
	if( pCtrl->GetState( BUTTON_STATE_HOLD, BUTTON_AXIS1_LEFT ) )
	{
		m_vPos.x -= m_fSpeed;
		m_Anim.y = ANIM_BACK;	
		m_IsMove = true;		
		
	
	}
	
	else if( pCtrl->GetState( BUTTON_STATE_PULL, BUTTON_AXIS1_LEFT ) )
	{
		if( !m_IsSlash )
		{
			m_Anim.y = ANIM_STAND;
		}
		
		m_IsMove = false;
	}
	
	//�E�Ɉړ�
	if( pCtrl->GetState( BUTTON_STATE_HOLD, BUTTON_AXIS1_RIGHT ) )
	{
		m_vPos.x += m_fSpeed;
			
		m_Anim.y = ANIM_FRONT;	
		
		m_IsMove = true;
		
		

	}
	
	else if( pCtrl->GetState( BUTTON_STATE_PULL, BUTTON_AXIS1_RIGHT ) )
	{
		if( !m_IsSlash )
		{
			m_Anim.y = ANIM_STAND;
		}
		
		m_IsMove = false;
	}
	
	//��Ɉړ�
	if( pCtrl->GetState( BUTTON_STATE_HOLD, BUTTON_AXIS1_UP ) )
	{
		m_vPos.y -= m_fSpeed;
		m_IsMove = true;
		
	
	}
	
	else if( pCtrl->GetState( BUTTON_STATE_PULL, BUTTON_AXIS1_UP ) )
	{
		if( !m_IsSlash )
		{
			m_Anim.y = ANIM_STAND;
		}
		
		
		m_IsMove = false;
	}
	
	//���Ɉړ�
	if( pCtrl->GetState( BUTTON_STATE_HOLD, BUTTON_AXIS1_DOWN ) )
	{
		m_vPos.y += m_fSpeed;
		m_IsMove = true;
		
		
	}
	
	else if( pCtrl->GetState( BUTTON_STATE_PULL, BUTTON_AXIS1_DOWN ) )
	{
		if( !m_IsSlash )
		{
			m_Anim.y = ANIM_STAND;
		}
		
		
		m_IsMove = false;
	}
	
	//�o����ԂɃ`�F���W
	if( CGauge::GetGaugeVal() >= 100 && pCtrl->GetState( BUTTON_STATE_PUSH, BUTTON_04 ) )
	{
		m_IsHyperMode = true;

		//���G�t�F�N�g�̒ǉ�
		CCommonObject::GetResMgr()->Push( new CFileData("player_mode.png", "Photon",
																	"EFFECT_P", "effectphoton.csv", m_vPos ) );


	//	m_eState = STATE_HYPERMODE;

	}

	if( m_IsMove )
	{
		if( ++count > 2 )
		{
			count = 0;
			m_vShadowPos[Num] = m_vPos;
			m_ShadowColor[Num] = CColor( 0, 0, 0, 128 );
			Num++;
		}
	}

	else
	{
		for( int i = 0;i < SHADOW_NUM;++i )
		{
			m_vShadowPos[i] = m_vPos;
		}
	}

	if( Num >= SHADOW_NUM )
	{
		Num = 0;
	}

	
	
}

//============================================================================
//�V���b�g����
//============================================================================
void CPlayer::Shoot()
{
	Peripheral::IInputController *pCtrl = CCommonObject::GetJoyPad()->GetController();
	

	static int count = 0;
	
	
	string str("");
	
	if( pCtrl->GetState( BUTTON_STATE_PUSH, BUTTON_01 ) )
	{
		m_IsShoot = true;
		m_ShootCount = 0;
		
	}	

	else if( pCtrl->GetState( BUTTON_STATE_PULL, BUTTON_01 ) )
	{
		m_ShootCount = -1;
		
		m_IsShoot = false;
		
	}
	
	
	if(pCtrl->GetState( BUTTON_STATE_HOLD, BUTTON_01 ) )
	{
		stringstream ss("");

		ss << "PlEff_Shot" << count;

		CCommonObject::GetResMgr()->Push( new CFileData( "player_flash.png", ss.str().c_str(),
															 "EFFECT_SH", "effectshot.csv",
															  this ) );

		m_IsShoot = true;
		
		
		//�e���o���Ԋu��ݒ�
		if( m_ShootCount++ > 10 )
		{
			
			m_ShootCount = 0;
		}
		
		//�V���b�g���̍Đ�
		CCommonObject::GetSoundMgr()->Play("Shot");
		

	}
	
	if( m_ShootCount == 0 )
	{
		int Array[5] =
		{
			42,
			45,
			48,
			45,
			42,
		};
		
		
		
		for( int i = 0;i < 5;++i )
		{
		
			stringstream ss(" ");
			
			ss << "PlBullet" << count;
			
			str = ss.str();
			
			Math::Vector2D vPos( toF( Array[i] ), toF( 10 * i ) );
			
			CCommonObject::GetResMgr()->Push( new CFileData("jiki_tama.png", str.c_str(), 
															"BULLET", "bullet.csv", m_vPos + vPos ) );
			count++;		
		}
														
	}
	

}

//============================================================================
//�ߐڍU������
//============================================================================
void CPlayer::Attack()
{
	//�U������
	Peripheral::IInputController *pCtrl = CCommonObject::GetJoyPad()->GetController();
	
	const int SLASH_NUM = 2;
	


	Math::Vector2D vPos[SLASH_NUM] =
	{
		Math::Vector2D( 10, -32 ),
		Math::Vector2D( 10, -28 ),
	};
	
	if( pCtrl->GetState( BUTTON_STATE_PUSH, BUTTON_02 ) && !m_IsNoSword )
	{

		
			m_Time = 0;

			stringstream ss(" ");

			ss << "PlEffectSword" << m_HitCount;

			m_Anim.x = 0;

			Sint32 Hit = m_HitCount % SLASH_NUM;


			if( Hit == 1 )
			{
				m_IsNoSword = true;
			}


			m_Anim.y = ANIM_SLASH1 +  Hit ;

//			m_Anim.y = ANIM_SLASH1;
			//�\�[�h�G�t�F�N�g�̒ǉ�
			CCommonObject::GetResMgr()->Push( new CFileData( "slash.png", ss.str().c_str(),
												"EFFECT_S", "effectsword.csv", m_vPos + vPos[Hit] )  );

			m_HitCount++;

			//�a�鉹�̍Đ�
			CCommonObject::GetSoundMgr()->Play("Slash");

			m_IsSlash = true;




	}
	


	if( pCtrl->GetState( BUTTON_STATE_PULL, BUTTON_02 ) )
	{
		
	}
	
	if( ++m_Time > 60 )
	{
		CEffectSword::SetHitCount( 0 );
		m_HitCount = 0;
	}
	
	if( m_IsNoSword )
	{
		const int SWORD_STOP_TIME = 15;

		if( ++m_SwordTime > SWORD_STOP_TIME )
		{
			m_IsNoSword = false;
			m_SwordTime = 0;
		}
	}

	
	
}


//============================================================================
//�ړ��␳
//============================================================================
void CPlayer::MoveAdjust()
{
	//���[
	if( m_vPos.x < -m_AdjustSize.x )
	{
		m_vPos.x = -m_AdjustSize.x;
	}
	
	//�E�[
	else if( m_vPos.x > SCREEN_WIDTH - m_fSize.x + m_AdjustSize.x )
	{
		m_vPos.x = SCREEN_WIDTH - m_fSize.x + m_AdjustSize.x;
	}
	
	//��[
	else if( m_vPos.y < 0 )
	{
		m_vPos.y = 0;
	}
	
	//���[
	else if( m_vPos.y > SCREEN_HEIGHT - m_fSize.y )
	{
		m_vPos.y = SCREEN_HEIGHT - m_fSize.y;
	}
}

//============================================================================
//�ړ��␳
//============================================================================
void CPlayer::SetAnimation()
{
	if( m_Anim.y < ANIM_SLASH1 )
	{
		/*�A�j���[�V�����J�E���^�̑���*/
		if( ++m_AnimCount > m_vecAnimNum.at( m_Anim.y ) )
		{
			m_AnimCount = 0;
			++ m_Anim.x ;
		}
		
		if( m_Anim.x >= m_DivNum.x )
		{
			m_Anim.x = 0;
			m_IsSlash = false;
			
		}
			
	}
	
	else
	{
		/*�A�j���[�V�����J�E���^�̑���*/
		if( ++m_AnimCount > m_vecAnimTime.at( m_Anim.y ) )
		{
			m_AnimCount = 0;
			++ m_Anim.x ;
		}
		
		if( m_Anim.x >= m_vecAnimNum.at( m_Anim.y ) )
		{
			m_IsSlash = false;
			m_Anim.y = ANIM_STAND;
		}
		
	}

}


//============================================================================
//�����蔻�菈��
//============================================================================
//[input]
//	spObj:���肷��I�u�W�F�N�g
//============================================================================
void CPlayer::HitExec( sp<CGameObject> spObj )
{
	static bool IsCheat = false;//���G���[�h�t���O
	
	if( m_eState == STATE_NONE && spObj != NULL )
	{
		//�G�ɓ��������ꍇ
		if( spObj->GetType() == CGameObject::TYPE_ENEMY )
		{
			if( !IsCheat )
			{	
				m_eState = STATE_DIED;
			}
		
		}	
		
		//�G�̒e�ɓ��������ꍇ
		else if( spObj->GetType() == CGameObject::TYPE_EBULLET )
		{
			spObj->SetRemoveFlag( true );
			
			if( !IsCheat )
			{	
				m_eState = STATE_DIED;
			}
		}
		
		else if( spObj->GetType() == CGameObject::TYPE_MISSILE )
		{
			spObj->SetRemoveFlag( true );
			
			if( !IsCheat )
			{	
				m_eState = STATE_DIED;
			}
		}
	}
	
	#if defined( RELEASE_TEST )
	
		::Peripheral::IKeyboard *pKeyboard = CCommonObject::GetAppli()->GetCore()->GetKeyboard();
		
		if( pKeyboard->GetKeyData( SELENE_VK_3 ) )
		{
			IsCheat = !IsCheat;
		}
		
	#endif
	
	#if defined (RELEASE_TEST )
		
		static bool IsShowHitArea = false;
		
		static int count = 0;
		
		++count;
		
		Renderer::IRender *pRender = CCommonObject::GetAppli()->GetRenderer();
		
		if( IsShowHitArea )
		{	
			pRender->FillRect( m_HitRect, CColor( 255, 255, 255, 128 ) );
		}
		
		//::Peripheral::IKeyboard *pKeyboard = CCommonObject::GetAppli()->GetCore()->GetKeyboard();
		
		if( pKeyboard->GetKeyData( SELENE_VK_2 ) )
		{
			count = 0;
			
		}
		
			if( count == 0 )
			{
				IsShowHitArea = !IsShowHitArea;
			}
		
		
	
	#endif
	
	
}

//============================================================================
//��Ԗ��̏���
//============================================================================
void CPlayer::StateExec()
{
	switch( m_eState )
	{
		//�����Ȃ����
		case STATE_NONE:
		{
			break;
		}
		
		//���G��Ԃ̎�
		case STATE_INVINCIBLE:
		{
			
			
			this->SetStopFlag( false );
			
			if( ++m_Count % 10 == 0 )
			{
				this->SetVisibleFlag( !this->GetVisibleFlag() );
			}
			
			if( m_Count > 60 * m_InvTime )
			{	
				m_Count = 0;
				this->SetVisibleFlag( true );
				
				m_eState = STATE_NONE;
			}
			
			break;
		}
		
		//���񂾏��
		case STATE_DIED:
		{
			//�c�@�����炷
			m_Stock--;
			
			this->SetVisibleFlag( false );
			
			
			CCommonObject::GetResMgr()->Push( new CFileData("bomb.png", "PLDeadBomb", 
															"EFFECT_B", "effectbomb.csv", m_vPos ) );
															
			this->SetStopFlag( true );		
			
			this->SetPosition( Math::Vector2D( 0, m_vPos.y ) );
													
			
			//�S�̍U��
			CCommonObject::GetResMgr()->Push( new CFileData( "flash.png", "PLFlash", "EFFECT_F", "effectflash.csv", Math::Vector2D( 0, 0 ) ) );
			
			//CCommonObject::GetAppli()->GetRenderer()->SetDrawType( DRAW_TYPE_BLEND );
			
			//�������̍Đ�
			CCommonObject::GetSoundMgr()->Play("BombPlayer");

			
			m_eState = STATE_INVINCIBLE;
			break;
		}
		
//TODO:		�o�����
		case STATE_HYPERMODE:
		{
//

			break;
		}

	}
	
	m_DivNum.x = m_vecAnimNum.at( m_Anim.y );
	
				   
}

