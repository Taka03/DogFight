//*============================================================================
//BackGraphic.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "BackGraphic.h"
#include "joypad.h"
#include "ResourceManager.h"
#include "Bullet.h"
#include "FileLoader.h"


int CBackGraphic::m_Count = 0;



//============================================================================
//�R���X�g���N�^
//============================================================================
//[input]
//	pName:�t�@�C����
//	pDataName:�f�[�^�t�@�C����
//===========================================================================
CBackGraphic::CBackGraphic( const char *pName, const char *pDataName )
:CSprite( pName, pDataName ),
 m_ScrSpeed( 0 )
{
	m_Count++;
	
	//�p�����[�^�[�̓ǂݍ���
	LoadParameter( pDataName );
	
	Init();
}

//============================================================================
//�f�X�g���N�^
//============================================================================
CBackGraphic::~CBackGraphic(void)
{
}

void CBackGraphic::Rendering()
{
	
	
	//Renderer::IRender *pRender = CCommonObject::GetAppli()->GetRenderer();
	
	//pRender->DrawTextLayer( 0, Math::Point2DI( 0, 200 + m_Count * 10 ), CColor( 255, 0, 0 ), "Visible:%d", m_IsVisible );
		
	
	m_pSpr->Rendering();
	
	
}
//============================================================================
//����
//============================================================================
void CBackGraphic::Exec()
{
	Scroll();
	
	m_DstRect.Set( m_vPos.x, m_vPos.y, m_fSize.x, m_fSize.y );
	
	m_SrcRect.Set( 0, 0, m_fSize.x, m_fSize.y );
	
	CSprite::DrawRequest();
	
}

//============================================================================
//�����蔻��
//============================================================================
//[input]
//	spObj:���肷��I�u�W�F�N�g
//[return]
//	�������Ă��邩
//===========================================================================
bool CBackGraphic::HitCheck( sp<CGameObject> spObj )
{
	return false;
}


//============================================================================
//�X�N���[������
//============================================================================
void CBackGraphic::Scroll()
{
	//if( m_DstRect.x <= + SCREEN_WIDTH * 2 )
	//{
	//	m_Scroll = 0;
	//	m_vPos.x = m_vInitPos.x + SCREEN_WIDTH * 2;
	//}
	
	
	m_vPos.x -= m_ScrSpeed;
	
	if( m_vPos.x <= -toF(SCREEN_WIDTH * 2) )
	{
		m_vPos.x = SCREEN_WIDTH * 2;
	}
	

}

//============================================================================
//�p�����[�^�[�̓ǂݍ���
//============================================================================
//[input]
//	pFileName:�t�@�C����
//===========================================================================
void CBackGraphic::LoadParameter( const char *pFileName )
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
	//�X�N���[���X�s�[�h�̐ݒ�
	//----------------------------------------------
	SetParameter( m_ScrSpeed, vecStr.at( 9 ) );
	
	
}


