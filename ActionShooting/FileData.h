//*============================================================================
//FileData.h
//*============================================================================
/**
*�t�@�C���f�[�^�p�N���X
*/

#pragma once

//=============================================================================
//include
//=============================================================================
#include "Player.h"
#include "Bullet.h"
#include "enemy.h"
#include "EnemyBullet.h"
#include "AimShoot.h"
#include "BackGraphic.h"
#include "EffectSword.h"
#include "EffectBomb.h"
#include "EffectFlash.h"
#include "Missile.h"
#include "EnemyRoll.h"
#include "EnemyMiddle1.h"
#include "EnemyCannon.h"
#include "EnemyCurve.h"
#include "EnemySmall2.h"
#include "TimeFont.h"
#include "Gauge.h"
#include "EffectTrBomb.h"
#include "ReadyTex.h"
#include "EffectPhoton.h"
#include "PauseFont.h"
#include "MultiSprite.h"
#include "ScoreFont.h"
#include "HitFont.h"
//TODO:
#include "GameFont.h"
#include "PushStart.h"
#include "EffectMaxCharge.h"
#include "EffectFire.h"
#include "EffectShot.h"
#include "EffectBurst.h"
#include "EffectSlash.h"

//=============================================================================
//class
//=============================================================================
class CFileData
{
	friend class CResourceManager;
	
	private:

		CFileData *m_pNext;///<@brief ���̃f�[�^
		
		string m_strTypeName;///<@brief �^�C�v��
		
		string m_strFileName;///<@brief �t�@�C����
		string m_strDataName;///<@brief �f�[�^��
		
		string m_strDataFileName;///<@brief �f�[�^�t�@�C����
		
		Math::Vector2D m_vPos;///<@brief �ʒu
		
		string m_DrawStr;///@brief �\������
		
		CGameObject *m_pObj;///@brief �I�u�W�F�N�g
		
	public:

		/**
		* @brief �R���X�g���N�^
		*/
		CFileData(){}
		
		/**
		* @brief �R���X�g���N�^
		* @param pFileName�@�t�@�C����
		* @param pDataName �f�[�^��
		* @param pTypeName �^�C�v��
		* @param pDatFileName �f�[�^�t�@�C����
		*/
		CFileData( const char *pFileName, const char *pDataName,
				   const char *pTypeName, const char *pDatFileName );

		/**
		* @brief �R���X�g���N�^
		* @param pFileName�@�t�@�C����
		* @param pDataName �f�[�^��
		* @param pTypeName �^�C�v��
		* @param pDatFileName �f�[�^�t�@�C����
		* @param vPos �ݒ肷��ʒu
		*/
		CFileData( const char *pFileName, const char *pDataName,
				   const char *pTypeName, const char *pDatFileName, Math::Vector2D vPos );
				   
		/**
		* @brief �R���X�g���N�^
		* @param pFileName�@�t�@�C����
		* @param pDataName �f�[�^��
		* @param pTypeName �^�C�v��
		* @param pDatFileName �f�[�^�t�@�C����
		* @param pObj �ݒ肷��I�u�W�F�N�g
		*/
		CFileData( const char *pFileName, const char *pDataName,
				   const char *pTypeName, const char *pDatFileName, CGameObject *pObj);
				   
				   
		/**
		* @brief �R���X�g���N�^
		* @param pFileName�@�t�@�C����
		* @param pDataName �f�[�^��
		* @param pTypeName �^�C�v��
		* @param pDatFileName �f�[�^�t�@�C����
		* @param str �`�敶��
		*/
		CFileData( const char *pFileName, const char *pDataName,
				   const char *pTypeName, const char *pDatFileName, string str );
				   
		
		/**
		* @brief �f�X�g���N�^
		*/
		~CFileData(){}
		
	/*Set�n*/
	public:
	
		/**
		* @brief ������X�g�̐ݒ�
		* @param pData �t�@�C���|�C���^
		*/
		void SetNext( CFileData *pData )
		{
			m_pNext = pData;
		}
		
	/*Get�n*/
	public:

		/**
		* @brief �t�@�C�����̎擾
		* @return �t�@�C����
		*/
		string GetFileName() const
		{
			return m_strFileName;
		}
		
		/**
		* @brief �f�[�^���̎擾
		* @return �f�[�^��
		*/
		string GetDataName() const
		{
			return m_strDataName;
		}
		
		/**
		* @brief �^�C�v���̎擾
		* @return �^�C�v��
		*/
		string GetTypeName() const
		{
			return m_strTypeName;
		}
		
		/**
		* @brief �f�[�^�t�@�C�����̎擾
		* @return �f�[�^�t�@�C����
		*/
		string GetDataFileName() const
		{
			return m_strDataFileName;
		}
		
		/**
		* @brief �ʒu�̎擾
		* @return �ʒu
		*/
		Math::Vector2D GetPos() const
		{
			return m_vPos;
		}
		
		/**
		* @brief �`�敶���̎擾
		* @return �`�敶��
		*/
		string GetDrawStr() const
		{
			return m_DrawStr;
		}
		
		CGameObject *GetTargetObject() const
		{
			return m_pObj;
		}
		
		/**
		* @brief ������X�g�̎擾
		* @return ������X�g
		*/
		CFileData *GetNext( void ) const
		{
			return m_pNext;
		}

};
