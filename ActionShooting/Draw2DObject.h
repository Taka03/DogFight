//*============================================================================
//Draw2DObject.h
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
#include "drawobject.h"

//=============================================================================
//class
//=============================================================================
//[Desc]
//	2D�`��p�I�u�W�F�N�g
//=============================================================================
class CDraw2DObject :	public CDrawObject
{
	protected:
	
	public:
	
		CDraw2DObject( const char *pName );//�R���X�g���N�^
		~CDraw2DObject(void);//�f�X�g���N�^
		
		virtual bool Load( ){ return true; }//�t�@�C���ǂݍ���
		
		void Init();//������
		void Exec(){}//����
		virtual void Rendering(){}//�����_�����O
		
		//�p�����[�^�[�̓ǂݍ���
		void LoadParameter( const char *pFileName ){};
		
		/**
		* @brief �����蔻��
		* @param spObj ���肷��I�u�W�F�N�g
		* @retval true �������Ă���
		* @retval false �������Ă��Ȃ�
		*/
		virtual bool HitCheck( sp<CDrawObject> spObj ){ return false; };
		
	public:
	
		
};
