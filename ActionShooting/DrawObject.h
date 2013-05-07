//*============================================================================
//DrawObject.h
//*============================================================================
//[history]
//	08/03/03 �C���J�n
//[author]
//	Taka
//============================================================================
#pragma once

//=============================================================================
//include
//=============================================================================
#include "gameobject.h"

//=============================================================================
//class
//=============================================================================
//[Desc]
//	�`��p�I�u�W�F�N�g
//=============================================================================
class CDrawObject :public CGameObject
{
	protected:
		
		
	public:
	
		//�R���X�g���N�^
		CDrawObject( const char *pName );
		
		//�f�X�g���N�^
		virtual ~CDrawObject(void){};
		
		//������
		virtual void Init();
		
		//����
		virtual void Exec(){}
		
		//�t�@�C���ǂݍ���
		virtual bool Load(){ return true; }
		
		//�p�����[�^�̓ǂݍ���
		virtual void LoadParameter( const char *pFileName ){}
		
		//�����_�����O
		virtual void Rendering() = 0;
		
		/**
		* @brief �����蔻��
		* @param spObj ���肷��I�u�W�F�N�g
		* @retval true �������Ă���
		* @retval false �������Ă��Ȃ�
		*/
		virtual bool HitCheck( sp<CDrawObject> spObj ){ return false; };
		
		
	public:
		
		
		
		
};
