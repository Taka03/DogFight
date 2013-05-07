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
#include "Sound.h"

#include <map>
#include <vector>

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
		
		Thread::CThread m_Thread;
		Thread::CCriticalSection m_CS;
		Thread::CEvent m_Event;
		
		CFileData *m_pQueTop[QUE_MAX];
		Sint32 m_Page;
		
		eObjType m_eObjType;//�I�u�W�F�N�g�^�C�v
		
		//�`��}�b�v
		map< string, sp<CGameObject> > m_mapDraw;
		
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
		
		//�T�E���h���X�g�֒ǉ�
		void AppendSoundList( string strDataName, CSoundObject *pSndObj );
		
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
			m_mapDraw = mapDraw;
		}
		
	//Get�n
	public:
	
		map< string, sp<CGameObject> > GetDrawMap() const
		{
			return m_mapDraw;
		}
		
};

