//*============================================================================
//FontSprite.h
//*============================================================================
//[history]
//	08/03/16 �쐬
//[author]
//	Taka
//============================================================================
#pragma once

//=============================================================================
//include
//=============================================================================
#include "gameobject.h"
#include <vector>
#include <string>

using namespace std;

//=============================================================================
//class
//=============================================================================
//[Desc]
//	�t�H���g�X�v���C�g�`��p�I�u�W�F�N�g
//=============================================================================
class CFontSprite :	public CGameObject
{
	protected:
		
		
		Renderer::Object::IFontSprite2D *m_pFontSpr;//�t�H���g�X�v���C�g�p�n���h��
		string m_Str;//�\�����镶��
		vector<string> m_vecText;//�����e�L�X�g
		
		CColor m_FontColor;//�t�H���g�F
		
		Uint32 m_StrCount;//�����J�E���^
		Uint32 m_RefCount;//�����̎Q�ƃJ�E���^
		
		bool m_IsTextEnd;//�e�L�X�g�I���t���O
		
		bool m_IsFlash;///@brief �_�ł����邩
		
		Sint32 m_Counter;//@brief �ėp�J�E���^�[
		Sint32 m_FlashCount;//@brief �t���b�V���J�E���g
		
		// �����蔻��̈�
		Math::Rect2DF m_HitRect;
		
	public:
	
		CFontSprite( const char *pName, const char *pDataName );//�R���X�g���N�^
	
		virtual ~CFontSprite(void);//�f�X�g���N�^
		
		void Init();//������
		void Exec();//����
		void Rendering();//�����_�����O
		
		bool Load( );//�ǂݍ���
		
		//�p�����[�^�[�̓ǂݍ���
		void LoadParameter( const char *pFileName );
		
		virtual bool HitCheck( sp<CGameObject> spObj ){ return false; }
		
		/**
		* @brief �����������̏���
		* @param spObj ���肷��I�u�W�F�N�g
		*/
		virtual void HitExec( sp<CGameObject> spObj ){};
		
		
	public:
	
		void SetDrawString( string str );//�`�悷�镶���̐ݒ�
		
		/*����������̕`��ݒ�*/
		void SetVecTextChat( vector<string> vecStr )
		{
			m_vecText = vecStr;
		}
		
		/*�����Q�ƃJ�E���^�̑���*/
		void SetRefCount( Uint32 count) 
		{
			m_RefCount = count;
		}
		
		/*�e�L�X�g�I���t���O�̐ݒ�*/
		void SetTextEndFlag( bool flag )
		{
			m_IsTextEnd = flag;
		}
		
		/*�����J�E���^�̐ݒ�*/
		void SetStrCount( Uint32 count )
		{
			m_StrCount = count;
		}
		
		/*�t�H���g�F�̐ݒ�*/
		void SetFontColor( CColor color )
		{
			m_FontColor = color;
		}
		
	public:
	
		//�t�H���g�X�v���C�g�p�n���h���̎擾
		Renderer::Object::IFontSprite2D *GetFontSprite() const
		{
			return m_pFontSpr;
		}
		
		/*�\�����镶���̎擾*/
		string GetDrawString() const
		{
			return m_Str;
		}
		
		/*�����e�L�X�g�̎擾*/
		vector<string> GetVecString() const
		{
			return m_vecText;
		}
		
		/*�e�L�X�g�I���t���O�̎擾*/
		bool GetTextEndFlag() const
		{
			return m_IsTextEnd;
		}
		
		/*�����J�E���^�̎擾*/
		Uint32 GetStrCount() const
		{
			return m_StrCount;
		}
		
		// �����蔻��̈�̎擾
		Math::Rect2DF GetHitRect(void) const
		{
			return m_HitRect;
		}
		
};
