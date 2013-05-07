//*============================================================================
//Application.h
//*============================================================================
//[history]
//	08/03/05�@�쐬
//[author]
//	Taka
//============================================================================
#pragma once

//=============================================================================
//include
//=============================================================================
#include "../common.h"

//=============================================================================
//class
//=============================================================================
//[desc]
//	�A�v���P�[�V�����p�N���X
//=============================================================================
class CApplication
{
	private:
	
		ICore	*m_pCore;//�R�A�f�o�C�X
		IGraphicCard	*m_pGraphicCard;//�O���t�B�b�N�J�[�h�f�o�C�X
		File::IFileManager	*m_pFileMgr;//�t�@�C���Ǘ��f�o�C�X
		Renderer::IRender	*m_pRender;//�����_���[�p�f�o�C�X
		
	private:
	
		const Uint32 m_ScreenWidth;//��ʕ�
		const Uint32 m_ScreenHeight;//��ʍ���
		const std::string m_strAppName;//�A�v���P�[�V������
		
	public:

		CApplication( Uint32 Width, Uint32 Height );//�R���X�g���N�^
		~CApplication(void);//�f�X�g���N�^
		
	public:
	
		void CreateCore();//�R�A�̐���
		bool Initialize( );//������
		void SetTextureFormat();//�e�N�X�`���t�H�[�}�b�g�̐ݒ�
		
		void Run();//�N��
		
		void AddRef();//�Q�ƃJ�E���^�̑���
		void Release();//�Q�ƃJ�E���^�̌���
		
	/*Get�n*/
	public:
	
		/*�R�A�f�o�C�X�̎擾*/
		ICore	*GetCore() const
		{
			return m_pCore;
		}
		
		/*�t�@�C���Ǘ��f�o�C�X�̎擾*/
		File::IFileManager	*GetFileMgr() const
		{
			return m_pFileMgr;
		}
		
		/*�����_���[�p�f�o�C�X�̎擾*/
		Renderer::IRender	*GetRenderer() const
		{
			return m_pRender;
		}
		
		
};

