//*============================================================================
//Gauge.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "Gauge.h"
#include "joypad.h"
#include "ResourceManager.h"
#include "Bullet.h"
#include "FileLoader.h"

//=============================================================================
//variable
//=============================================================================
float CGauge::m_fGaugeVal = 0;
float CGauge::m_fAddGaugeVal = 0;

//============================================================================
//�R���X�g���N�^
//============================================================================
//[input]
//	pName:�t�@�C����
//	pDataName:�f�[�^�t�@�C����
//===========================================================================
CGauge::CGauge( const char *pName, const char *pDataName )
:CSprite( pName, pDataName ),
 m_FontAnim( 0 ),
 m_IsMaxCharge( false )

{
	//�p�����[�^�[�̓ǂݍ���
	LoadParameter( pDataName );
	
	m_vCenterPos.Set( m_fSize.x / 2, m_fSize.y / 2 );

	Init();
}

//============================================================================
//�f�X�g���N�^
//============================================================================
CGauge::~CGauge(void)
{
}

//============================================================================
//����
//============================================================================
void CGauge::Exec()
{
	const float GAUGE_MAX = 100.0f;
	
	//	�ő�␳
	if( m_fGaugeVal >= GAUGE_MAX )
	{
		if( !m_IsMaxCharge )
		{
			CCommonObject::GetResMgr()->Push( new CFileData("player_ring.png", "GRingFront",
															"EFFECT_MC", "effectcharge.csv", this->GetPos() ) );

			CCommonObject::GetResMgr()->Push( new CFileData("player_ring_2.png", "GRingBack",
																	"EFFECT_MC", "effectcharge2.csv", this->GetPos() ) );

															
			m_IsMaxCharge = true;
		}

		m_fGaugeVal = GAUGE_MAX;
	}

	//	�ŏ��␳
	if( m_fGaugeVal < 0 )
	{
		m_IsMaxCharge = false;
		m_fGaugeVal = 0;
	}


	
	m_DstRect.Set( m_vPos.x, m_vPos.y, m_fSize.x, m_fSize.y );
	
	
	
	m_pSpr->Begin();



	
	for( int i = 0;i < m_DivNum.y - 5;++i )
	{
//		�σQ�[�W�̂Ƃ�
		if( i == 1 || i == 2 )
		{
			if( m_fAddGaugeVal > 0 )
			{
				if( m_fGaugeVal >= GAUGE_MAX )
				{
					m_SrcRect.Set( m_Anim.x * m_fSize.x, 2 * m_fSize.y, m_fSize.x, m_fSize.y );
				}

				else
				{
					m_SrcRect.Set( m_Anim.x * m_fSize.x, m_fSize.y, m_fSize.x, m_fSize.y );
				}
			}

			else
			{
				m_SrcRect.Set( m_Anim.x * m_fSize.x, 2 * m_fSize.y, m_fSize.x, m_fSize.y );
			}

			float SizeX = ( m_fGaugeVal / GAUGE_MAX ) * m_fSize.x;

			Math::Rect2DF Dst( m_vPos.x + 4, m_vPos.y, SizeX, m_fSize.y );

			m_pSpr->DrawSquare( Dst, m_SrcRect, CColor( 255, 255, 255) );
		}


		else
		{
			float fTemp = toF(i);

			m_SrcRect.Set( m_Anim.x * m_fSize.x, fTemp * m_fSize.y, m_fSize.x, m_fSize.y );


			m_pSpr->DrawSquare( m_DstRect, m_SrcRect, CColor( 255, 255, 255) );
		}
	}
	
//	�����̓_��
	if( m_fGaugeVal >= GAUGE_MAX )
	{
		const int ANIM_NUM = 5;

		int Anim[ANIM_NUM] =
		{
		  2,
		  2,
		  5,
		  6,
		  15,
		};

		/*�A�j���[�V�����J�E���^�̑���*/
		if( ++m_AnimCount > Anim[m_FontAnim] )
		{
			m_AnimCount = 0;
			m_FontAnim += m_AnimSpeed;
		}

		if( m_FontAnim >= ANIM_NUM )
		{
			m_FontAnim = 0;
		}

		m_SrcRect.Set( m_Anim.x * m_fSize.x, ( m_FontAnim + 4 ) * m_fSize.y, m_fSize.x, m_fSize.y );

		m_pSpr->DrawSquare( m_DstRect, m_SrcRect, CColor( 255, 255, 255) );



	}


	Peripheral::IKeyboard *pKey = CCommonObject::GetAppli()->GetCore()->GetKeyboard();



	#if defined( DEBUG ) | (_DEBUG )
	
	if( pKey->GetKeyData( SELENE_VK_PAUSE ) )
	{
		m_fGaugeVal = 0;
	}

	if( pKey->GetKeyData( SELENE_VK_DELETE ) )
	{
		m_fGaugeVal = 100;
	}

	
	

	#endif
	
    m_pSpr->End();
	


	

	
	
}

//============================================================================
//�����蔻��
//============================================================================
//[input]
//	spObj:���肷��I�u�W�F�N�g
//[return]
//	�������Ă��邩
//===========================================================================
bool CGauge::HitCheck( sp<CGameObject> spObj )
{
	return false;
}

//============================================================================
//�p�����[�^�[�̓ǂݍ���
//============================================================================
//[input]
//	pFileName:�t�@�C����
//===========================================================================
void CGauge::LoadParameter( const char *pFileName )
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
	
	//----------------------------------------------
	//�Q�[�W�l�̐ݒ�
	//----------------------------------------------
	SetParameter( m_fGaugeVal, vecStr.at( 9 ) );
	
	
}
