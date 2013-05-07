//*============================================================================
//BackGraphic.h
//*============================================================================
/**
* �w�i�N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "sprite.h"

//=============================================================================
//class
//=============================================================================
class CBackGraphic :	public CSprite
{
	private:
	
		Sint32 m_ScrSpeed;///<@brief �X�N���[���X�s�[�h
		static int m_Count;
	
	public:
		
		/**
		* @brief �R���X�g���N�^
		* @param pName �t�@�C����
		* @param pDataName �f�[�^��
		*/
		CBackGraphic( const char *pName, const char *pDataName );
		
		/**
		* @brief �f�X�g���N�^
		*/
		~CBackGraphic(void);
		
		void Rendering();
		
		/**
		* @brief ����
		*/
		void Exec();
		
		/**
		* @brief ��ʃX�N���[��
		*/
		void Scroll();
		
		
		/**
		* @brief �p�����[�^�[�̓ǂݍ���
		* @param pFileName �t�@�C����
		*/
		void LoadParameter( const char *pFileName );
		
		/**
		* @brief �����蔻��
		* @param spObj ���肷��I�u�W�F�N�g
		* @retval true �������Ă���
		* @retval false �������Ă��Ȃ�
		*/
		virtual bool HitCheck( sp<CGameObject> spObj );
		
		
};
