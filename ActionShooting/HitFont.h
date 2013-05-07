//*============================================================================
//HitFont.h
//*============================================================================
//[history]
//	2009/10/10�@�쐬
//[author]
//	Taka
//============================================================================
#pragma once

//=============================================================================
//include
//=============================================================================
#include "FontSprite.h"

//=============================================================================
//class
//=============================================================================
//[Desc]
//	�t�H���g�X�v���C�g�`��p�I�u�W�F�N�g
//=============================================================================
class CHitFont :	public CFontSprite
{
	private:

		bool m_IsMaxHit;

	public:

		/**
		 * @brief �R���X�g���N�^
		 * @param pName �t�@�C����
		 * @param pDataName�@�f�[�^�t�@�C����
		 */
		CHitFont( const char *pName, const char *pDataName );

		/**
		 * @brief �f�X�g���N�^
		 */
		virtual ~CHitFont(void);

		/**
		 * @brief ������
		 */
		void Init();

		/**
		 * @brief ����
		 */
		void Exec();

//		/**
//		 * @brief �p�����[�^�[�̓ǂݍ���
//		 * @param pFileName �t�@�C����
//		 */
		void LoadParameter( const char *pFileName );

	public:

		/**
		 * @brief �`��
		 */
		void Draw();

};