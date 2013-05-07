//*============================================================================
//ResourceManager.h
//*============================================================================
//[history]
//	08/10/01�@�쐬
//[author]
//	Taka
//[ref]
//	SeleneSample�R�[�h
//=============================================================================
#pragma once

//=============================================================================
//include
//=============================================================================
#include "Common/Application.h"
#include "FileData.h"
#include "SoundObject.h"

#include <map>
#include <vector>
#include <list>

//=============================================================================
//define
//=============================================================================
//#define RELEASE_TEST


//=============================================================================
//const
//=============================================================================
const int QUE_MAX = 2;

//=============================================================================
//class
//=============================================================================
//[Desc]
//	���\�[�X�Ǘ��N���X
//============================================================================
class CResourceManager
{
	public:
	
		//�I�u�W�F�N�g�^�C�v
		enum eObjType
		{
			OBJ_2D,//2D�`��I�u�W�F�N�g
			OBJ_3D, //3D�`��I�u�W�F�N�g
			OBJ_SND,//�T�E���h�I�u�W�F�N�g
		};
	
	private:
		
		CFileData *m_pQueTop[QUE_MAX];
		Sint32 m_Page;
		
		eObjType m_eObjType;//�I�u�W�F�N�g�^�C�v
		
		bool m_IsLoadEnd;//���[�h�I���t���O
		
		//�`��}�b�v
		map< string, sp<CGameObject> > m_mapDraw;
		
		//�q�b�g���Ă���I�u�W�F�N�g�̒ǉ�
		list< sp<CGameObject> > m_liHitObj;
		
		//�`��}�b�v�̃C�e���[�^
		map< string, sp<CGameObject> >::iterator m_itDraw;
		
	private:
	
		/*�������\�b�h*/
		typedef void (CResourceManager::*CreateFunc)( CFileData *pFile );
	
		//�N��
		virtual void Run();
		
		//���[�h�p�X���b�h
		static void LoadProc( void *pData );
	
	public:	
	
		//�R���X�g���N�^
		CResourceManager( );
		
		//�f�X�g���N�^
		virtual ~CResourceManager();
		
		/*���\�[�X�̒ǉ�*/
		virtual void Push( CFileData *pFile );
		
		/**
		 * ���\�[�X�̒ǉ�
		 * @param pObj �ǉ�����I�u�W�F�N�g
		 */
		void Push( CGameObject *pObj );
		
		//�I�u�W�F�N�g�̎擾
		sp<CGameObject> FindObject( const char *pName );
		
		//�T�E���h�I�u�W�F�N�g�̎擾
		CSoundObject *FindSoundObject( const char *pName );
		
		//�I�u�W�F�N�g�̍폜
		void RemoveObject( const char *pDataName );
		
		//�T�E���h�I�u�W�F�N�g�̍폜
		void RemoveSoundObject( const char *pDataName );
		
		//���ׂẴI�u�W�F�N�g�̍폜
		void RemoveAll();
		
		//�S���\�[�X�̃����_�����O
		void RenderingAll();
		


		//�X�V
		void Update();
		
		//�S���\�[�X�̏���
		void ExecAll();
		
		/**
		* @brief �S���\�[�X�̓����蔻�菈��
		*/
		void HitCheckAll();
		
		/*���[�h��*/
		virtual Bool IsLoading();
		
	private:
	
		//���X�g�֒ǉ�
		void AppendList( string strDataName, sp<CGameObject> spGameObj );
		
		/*�^�C�v�̔���*/
		void CheckType( CFileData *pFile );
		
	//Set�n
	public:
	
		/**
		* @brief �`��}�b�v�̃Z�b�g
		* @param mapDraw �ݒ肷��`��}�b�v
		*/
		void SetDrawMap( map< string, sp<CGameObject> > mapDraw )
		{
			m_mapDraw.clear();
			m_IsLoadEnd = false;
			m_mapDraw = mapDraw;

		}
		
	//Get�n
	public:

		/**
		 * �`��}�b�v�̎擾
		 * @return �`��}�b�v
		 */
		map< string, sp<CGameObject> > GetDrawMap() const
		{
			return m_mapDraw;
		}
		
		list< sp<CGameObject> > GetHitObjList() const
		{
			return m_liHitObj;
		}
		
};

