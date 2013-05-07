//*============================================================================
//PauseFont.h
//*============================================================================
//[history]
//	2009/10/10�@�쐬
//[author]
//	Taka
//============================================================================
#pragma once


//=============================================================================
//define
//=============================================================================
#define USE_SPRITE 1


//=============================================================================
//include
//=============================================================================

#ifdef USE_SPRITE
#include "Sprite.h"

#else
#include "FontSprite.h"

#endif


//=============================================================================
//const
//=============================================================================
const int MENU_MAX = 2;

//=============================================================================
//class
//=============================================================================
//[Desc]
//	�t�H���g�X�v���C�g�`��p�I�u�W�F�N�g
//=============================================================================
class CPauseFont :

#ifdef USE_SPRITE
	public CSprite
#else
	public CFontSprite
#endif

{
	private:

		Sint32 m_Cursor;///<@brief �J�[�\���ʒu
		


	public:

		/**
		 * @brief �R���X�g���N�^
		 * @param pName �t�@�C����
		 * @param pDataName�@�f�[�^�t�@�C����
		 */
		CPauseFont( const char *pName, const char *pDataName );

		/**
		 * @brief �f�X�g���N�^
		 */
		virtual ~CPauseFont(void);

		/**
		 * @brief ������
		 */
		void Init();

		/**
		 * @brief ����
		 */
		void Exec();

		/**
		 * @brief �����_�����O
		 */
		void Rendering();

//		/**
//		 * @brief �p�����[�^�[�̓ǂݍ���
//		 * @param pFileName �t�@�C����
//		 */
//		void LoadParameter( const char *pFileName );

	public:

		/**
		 * @brief �`��
		 */
		void Draw();

	public:

		/**
		 * @brief �J�[�\���ʒu�̐ݒ�
		 * @param Cursor �ݒ肷��J�[�\���ʒu
		 */
		void SetCursor( const Sint32 Cursor )
		{
			m_Cursor = Cursor;
		}

	public:


		/**
		 * @brief �J�[�\���ʒu�̎擾
		 * @return �J�[�\���ʒu
		 */
		Sint32 GetCursor()
		{
			return m_Cursor;
		}

};
