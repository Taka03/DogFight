//*============================================================================
//Draw3DObject.h
//*============================================================================
//[history]
//	08/03/03�@�C���J�n
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
//[desc]
//	3D�I�u�W�F�N�g�`��p�N���X
//=============================================================================
class CDraw3DObject :public CDrawObject
{
	public:
	
		//�I�u�W�F�N�g�^�C�v
		enum e3DObjectType
		{
			OBJ_PLAYER,
			OBJ_ENEMY,
			OBJ_FIELD,
			OBJ_OTHER,
		};

	
	protected:
	
		Math::Vector3D m_vPos; //���W
		Math::Vector3D m_vInitPos;//�ʒu�̃o�b�N�A�b�v�p
		Math::Point3DI m_Rot;//�p�x
		Math::Point3DI m_InitRot;//�p�x�̃o�b�N�A�b�v�p
		Math::Point3DF m_fScale;//�g�k
		Math::Point3DF m_fInitScale;//�g�k�̃o�b�N�A�b�v�p
	
		int m_ActorIndex;//�A�N�^�[�C���f�b�N�X
		
	public:
	
		CDraw3DObject( const char *pName, const char *pDataName );//�R���X�g���N�^
		virtual ~CDraw3DObject(void);//�f�X�g���N�^
		
		void Init();//������
		void Exec();//����
		virtual void MoveExec();//�ړ�����
		virtual void Rendering();//�����_�����O
		
		virtual bool Load( ){ return true; };//�t�@�C���ǂݍ���
		void LoadShader( Renderer::IRender *pRender, const char *pName );//�V�F�[�_�[�̓ǂݍ���
		
		//�p�����[�^�[�̓ǂݍ���
		void LoadParameter( const char *pDataName );
		
		virtual void CreateActor( int index,  Scene::ISceneManager *pSceneMgr );//�A�N�^�[�̐���
		
		virtual bool HitCheck( CDraw3DObject **ppChara );//�����蔻��
		virtual bool HitCheck( Selene::Collision::CLine3D &vRay );//�����蔻��
		virtual bool HitCheck( Selene::Collision::CLine3D &vRay, CDraw3DObject **ppHitObj );//�����蔻��
		virtual bool HitCheck( Selene::Collision::CLine3D &vRay, Renderer::SCollisionResult &Out );
		virtual bool HitCheck( Selene::Collision::CLine3D &vRay, Renderer::SCollisionResult &Out, CDraw3DObject **ppHitObj );
		
		virtual void SetActorIndex( int index );//�A�N�^�[�C���f�b�N�X�̐ݒ�
		
	/*Set�n*/
	public:
	
		//�ʒu�̐ݒ�
		void SetPosition( Math::Vector3D vPos )
		{
			m_vPos = vPos;
		}
		
		/*�����ʒu�̐ݒ�*/
		void SetInitPosition( Math::Vector3D vPos )
		{
			m_vInitPos = vPos;
		}
		
		/*X�ʒu�̐ݒ�*/
		void SetXPosition( float x )
		{
			m_vPos.x = x;
		}
		
		/*Y�ʒu�̐ݒ�*/
		void SetYPosition( float y )
		{
			m_vPos.y = y;
		}
		
		/*Z�ʒu�̐ݒ�*/
		void SetZPosition( float z )
		{
			m_vPos.z = z;
		}
		
		//��]�p�x�̐ݒ�
		void SetRotate( Math::Point3DI Rot )
		{
			m_Rot = Rot;
		}
		
		//X��]�p�x�̐ݒ�
		void SetXRotate( Sint32 x )
		{
			m_Rot.x = x;
		}
		
		//Y��]�p�x�̐ݒ�
		void SetYRotate( Sint32 y )
		{
			m_Rot.y = y;
		}

		//Z��]�p�x�̐ݒ�
		void SetZRotate( Sint32 z )
		{
			m_Rot.z = z;
		}
		
		//�g�k�̎擾
		void SetScale( Math::Point3DF fScale )
		{
			m_fScale = fScale;
		}
		
	/*Get�n*/
	public:
	
		//�ʒu�̎擾
		Math::Vector3D GetPosition() const
		{
			return m_vPos;
		}
		
		/*�������W�̎擾*/
		Math::Vector3D GetInitPos() const
		{
			return m_vInitPos;
		}
		
		//��]�p�x�̎擾
		Math::Point3DI GetRotate() const
		{
			return m_Rot;
		}
		
		//�g�k�̎擾
		Math::Point3DF GetScale() const
		{
			return m_fScale;
		}
		
		/*�A�N�^�[�C���f�b�N�X�̎擾*/
		int GetActorIndex() const
		{
			return m_ActorIndex;
		}
		
};
