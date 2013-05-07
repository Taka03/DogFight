//*============================================================================
//TimeFont.cpp
//*============================================================================

//=============================================================================
//include
//=============================================================================
#include "TimeFont.h"
#include "CommonObject.h"
#include "Common/Application.h"
#include "FileLoader.h"
#include "Selene.h"
#include "SceneGameMain.h"


//=============================================================================
//�R���X�g���N�^
//=============================================================================
//[input]
//	pName:�f�[�^��
//	pDataName:�f�[�^��
//===========================================================================
CTimeFont::CTimeFont( const char *pName, const char *pDataName )
:CFontSprite( pName, pDataName )

{
	m_fScale.x = 1;
	m_fScale.y = 1;
}

//============================================================================
//�f�X�g���N�^
//============================================================================
CTimeFont::~CTimeFont(void)
{

}

//============================================================================
//������
//============================================================================
void CTimeFont::Init()
{

}

//============================================================================
//����
//============================================================================
void CTimeFont::Exec()
{
	#if 0
		if( m_pFontSpr != NULL )
		{
		
			m_pFontSpr->Begin();

			Draw();

			m_pFontSpr->End();

		}
		
	#else


		CSceneGameMain::tagTime Time = CSceneGameMain::GetTime();

		stringstream ss("");
		stringstream ss2("");

		ss2 << Time.m_Second;

		if( ss2.str().size() < 2 )
		{
			ss2.str("");

			ss2 << "0" << Time.m_Second;
		}

		ss << Time.m_Minute << ":" << ss2.str();

		this->SetDrawString( ss.str() );

//		���Ԃ��߂��Ȃ�����A����
		if( Time.m_Minute == 0 && Time.m_Second < 10 )
		{
			m_FontColor = CColor( 255, 0, 0 );
		}

		else
		{
			m_FontColor = CColor( 255, 255, 255 );
		}
	
		
		CFontSprite::Exec();
		
	#endif


}

//=============================================================================
//�`��
//=============================================================================
void CTimeFont::Draw()
{
	//m_pFontSpr->DrawStringScale()

	//m_pFontSpr->draws

}




