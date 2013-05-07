//*============================================================================
//Effect.h
//*============================================================================
/**
* �G�t�F�N�g�N���X
*/
#pragma once

//=============================================================================
//include
//=============================================================================
#include "character.h"

//=============================================================================
//class
//=============================================================================
class CEffect :	public CCharacter
{
	protected:
	
		enum eEffectState
		{
			STATE_NONE,//�����Ȃ����
			STATE_DIED,//���񂾏��
		};///<@brief �G�t�F�N�g�̏��
		
		eEffectState m_eState;///<@brief �G�t�F�N�g�̏��
		
	public:
		
		/**
		* @brief �R���X�g���N�^
		* @param pName �t�@�C����
		* @param pDataName �f�[�^��
		* @param vPos �ݒ肷��ʒu
		*/
		CEffect( const char *pName, const char *pDataName, Math::Vector2D vPos );
		
		/**
		* @brief �f�X�g���N�^
		*/
		~CEffect(void);
		
		/**
		* @brief �ړ�
		*/
		void Move();
		
		/**
		* @brief ����
		*/
		//void Exec();
		
		virtual bool HitCheck( sp<CGameObject> spObj );
		
		/**
		* @brief �����������̏���
		* @param spObj ���肷��I�u�W�F�N�g
		*/
		virtual void HitExec( sp<CGameObject> spObj );
		
		/**
		* @brief ��Ԗ��̏���
		*/
		virtual void StateExec();
		
		
};
