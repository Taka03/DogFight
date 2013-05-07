//*============================================================================
//PushStart.h
//*============================================================================
/**
* Ready�e�N�X�`���N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "sprite.h"

//=============================================================================
//class
//=============================================================================
class CPushStart :	public CSprite
{
	private:

		Sint32 m_Counter;//@brief �ėp�J�E���^�[
		Sint32 m_FlashCount;//@brief �t���b�V���J�E���g
		
	public:

		/**
		* @brief �R���X�g���N�^
		* @param pName �t�@�C����
		* @param pDataName �f�[�^��
		*/
		CPushStart( const char *pName, const char *pDataName );

		/**
		* @brief �f�X�g���N�^
		*/
		~CPushStart(void);

		/**
		* @brief �����_�����O
		*/
		void Rendering();

		/**
		* @brief �����蔻��
		* @param spObj ���肷��I�u�W�F�N�g
		* @retval true �������Ă���
		* @retval false �������Ă��Ȃ�
		*/
		virtual bool HitCheck( sp<CGameObject> spObj );


	public:






};
