//*============================================================================
//ReadyTex.h
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
class CReadyTex :	public CSprite
{
	private:

		int m_ExistCount;///!< @brief ���݃J�E���^�[


	public:

		/**
		* @brief �R���X�g���N�^
		* @param pName �t�@�C����
		* @param pDataName �f�[�^��
		*/
		CReadyTex( const char *pName, const char *pDataName );

		/**
		* @brief �f�X�g���N�^
		*/
		~CReadyTex(void);

		/**
		* @brief ����
		*/
		void Exec();

		/**
		* @brief �����蔻��
		* @param spObj ���肷��I�u�W�F�N�g
		* @retval true �������Ă���
		* @retval false �������Ă��Ȃ�
		*/
		virtual bool HitCheck( sp<CGameObject> spObj );


	public:






};
