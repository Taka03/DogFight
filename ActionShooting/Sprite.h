//*============================================================================
//Sprite.h
//*============================================================================
//[history]
//	08/03/19�@�쐬
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
//	�X�v���C�g�`��p�I�u�W�F�N�g
//=============================================================================
class CSprite :	public CGameObject
{
	protected:
	
		Renderer::ITexture *m_pTex;///<@brief �e�N�X�`���p�n���h��
		Renderer::Object::ISprite2D *m_pSpr;///<@brief �X�v���C�g�p�n���h��
	
		Math::Point2DI m_DivNum;///<@brief ������
		Math::Point2DI m_Anim;///<@brief �A�j��ID
		
		Sint32 m_AnimSpeed;///<@brief �A�j���[�V�������x
		
		Math::Point2DF m_fSize;///<@brief �摜�T�C�Y
		
		Sint32 m_AnimTime;///<@brief �A�j���[�V��������
		Sint32 m_AnimCount;///<@brief �A�j���[�V�����J�E���^
		
		Math::Rect2DF m_HitRect;///<@brief �����蔻��p��`
		
		Math::Rect2DF m_DstRect;///<@brief �`����`
		Math::Rect2DF m_SrcRect;///<@brief �`�挳��`
		
		bool m_IsAnim;///<@brief �A�j���[�V���������邩
		
		Math::Vector2D m_vCenterPos;///<@brief ���S�_
		
		Math::Rect2DF m_AdjHitRect;///@brief �␳����T�C�Y
		
		Uint32 m_AnimNum;///<@brief �A�j����
		
		bool m_IsAuto;///<@brief �����������邩
		
		bool m_IsReverse;///@brief �t�Đ����邩
		
		Uint8 m_Alpha;///@brief �A���t�@�l
		
		float m_fBlendRate;///@brief �A���t�@��

		CColor m_Color;///@brief �F
		
		
		

	public:
	
		CSprite( const char *pName, const char *pDataName );//�R���X�g���N�^

		/**
		 *
		 * @param vecStr
		 * @return
		 */
		CSprite( vector<string> vecStr );//�R���X�g���N�^
		virtual ~CSprite(void);//�f�X�g���N�^
		
		
		virtual void Init();
		
		virtual bool Load();//�t�@�C���ǂݍ���

		virtual void Exec();//����
		
		void Rendering();//�����_�����O
		
		virtual void DrawRequest();//�`�惊�N�G�X�g
		
		void LoadParameter( const char *pFileName );//�p�����[�^�[�̓ǂݍ���
		
		void LoadParameter( vector<string> vecStr );//�p�����[�^�[�̓ǂݍ���

		void DrawGrayScale( Renderer::IRender *pRender );//�O���[�X�P�[���`��
		
		/**
		* @brief �A�j���[�V�����̐ݒ�
		*/
		virtual void SetAnimation();
		
		/**
		* @brief �����蔻��
		* @param spObj ���肷��I�u�W�F�N�g
		* @retval true �������Ă���
		* @retval false �������Ă��Ȃ�
		*/
		virtual bool HitCheck( sp<CGameObject> spObj );
		
		/**
		* @brief �����������̏���
		* @param spObj ���肷��I�u�W�F�N�g
		*/
		virtual void HitExec( sp<CGameObject> spObj ){};
		
		
		
	private:
	
		void CreateSprite( Renderer::IRender *pRender, Uint32 Num );//�X�v���C�g�̐��� 
	
		
	/*Set�n*/
	public:
	
		
		//�������̐ݒ�	
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
		
		
		/*X�����������̐ݒ�*/
		void SetDivNumX( int x )
		{
			SetDivNum( Math::Point2DI( x, m_DivNum.y ) );
		}
		
		/*Y�����������̐ݒ�*/
		void SetDivNumY( int y )
		{
			SetDivNum(  Math::Point2DI( m_DivNum.x, y ) );
		}
		
		////�A�j���[�V����ID�̐ݒ�
		//void SetAnimID( Uint32 anim )
		//{
		//	m_AnimID = anim;
		//}
		
		/*�摜�T�C�Y�̐ݒ�*/
		void SetGraphSize( Math::Point2DF Size )
		{
			m_fSize = Size;
		}
		
		/*�A�j���[�V�����t���O�̐ݒ�*/
		void SetAnimFlag( bool flag )
		{
			m_IsAnim = flag;
		}
		
		/*�`����`�̐ݒ�*/
		void SetDstRect( Math::Rect2DF Dst )
		{
			m_DstRect = Dst;
		}
		
		/*�`�挳��`�̐ݒ�*/
		void SetSrcRect( Math::Rect2DF Src )
		{
			m_SrcRect = Src;
		}
		
	/*Get�n*/
	public:

		//�e�N�X�`���p�n���h���̎擾
		Selene::Renderer::ITexture *GetTexture() const
		{
			return m_pTex;
		}
		
		/*�摜�T�C�Y�̎擾*/
		Math::Point2DF GetSize() const
		{
			return m_fSize;
		}
		
		/*�����蔻���`�̎擾*/
		virtual Math::Rect2DF GetHitRect() const
		{
			return m_HitRect;
		}
		
		////�A�j��ID�̎擾
		//Uint32 GetAnimID() const
		//{
		//	return m_AnimID;
		//}
		
		
		
};
