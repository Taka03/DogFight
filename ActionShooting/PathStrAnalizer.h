#ifndef IKD_PATHSTRANALIZER_H
#define IKD_PATHSTRANALIZER_H
// PathStrAnalizer.h
//
//  �p�X�������̓N���X
//�@ver 1.00
//
//  ����� : IKD (2007. 9. 17)
//  HP     : http://marupeke296.com/
//

#include <tchar.h>
#include <windows.h>

#define DRIVELENGTH 4
#define FULLPATHLENGTH 512
#define MAXFILELENGTH 256
#define MAXEXTLENGHT 20
#define MAXDIRECTORYLISTNUM 128
#define CANNOT_FIND_CHAR 0xffffffff
#define PATHSTRANALIZER_SKIP_PTR ((TCHAR*)(LONG_PTR)0xffffffff)

namespace Dix {
	class PathStrAnalizer {
	public:
		PathStrAnalizer( TCHAR* pathName = 0 );
		~PathStrAnalizer();

	private:
		// �f�B���N�g���p�[�T�[���s
		bool startDirectoryParser( const TCHAR* pathName );
		// �h���C�u���`�F�b�N
		bool checkDriveName( const TCHAR* pathName, size_t length, size_t pos,  TCHAR outDraiveName[DRIVELENGTH] );
		// �h���C�u�f���~�^�`�F�b�N
		bool checkDriveDelim( TCHAR delim );
		// ����������
		size_t findFirstOf( const TCHAR *str, size_t sz, const TCHAR c );
		// �I��������
		size_t findLastOf( const TCHAR *str, size_t sz, const TCHAR c );
		// �q�b�g���Ȃ��������I�[���猟��
		size_t findLastNotOf( const TCHAR *str, size_t sz, const TCHAR c );
		// �t�@�C�������`�F�b�N
		bool checkFileName( const TCHAR *fileName );
		// �t�@�C�������`�F�b�N
		bool checkFileName( const TCHAR *fileName, size_t size );
		// �t���p�X���𐶐��o�^
		void createFullPath( const TCHAR delim = L'/' );
		// �t���p�X�n���A�b�v�f�[�g
		void updateFullName();
		// �g���q�����邩�`�F�b�N
		bool isExt();
		// �f�B���N�g���Z�[�t�f���[�g
		void safeDeleteDirectory( TCHAR* deleteDirectory );

	public:
		// �f�B���N�g�����폜
		bool deleteDirectory( size_t level );
		// �f�B���N�g�������擾
		const TCHAR* getDirectoryName( size_t level ) const;
		// �f�B���N�g�������擾
		size_t getDirectoryNum() const;
		// �g���q�����擾
		const TCHAR* getExtName() const;
		// �t�@�C�������擾
		const TCHAR* getFileName() const;
		// �t���t�@�C�������擾
		const TCHAR* getFullFileName() const;
		// �t���p�X�����擾
		const TCHAR* getFullPathName() const;
		// �f�B���N�g����}��
		bool insert( size_t level, const TCHAR* directoryName );
		// ��΃p�X���H
		bool isAbsolutePath();
		// �t�@�C���p�X�o�^
		bool regist( const TCHAR *pathName );
		// �f�B���N�g����ݒ�
		bool setDirectoryName( size_t level, const TCHAR* directoryName );
		// �h���C�u����o�^
		bool setDriveName( TCHAR driveName );
		// �g���q����o�^
		bool setExtName( const TCHAR* extName );
		// �t�@�C������o�^
		bool setFileName( const TCHAR* fileName );
		bool setFileName( const TCHAR* fileName, size_t size );
		// �t���t�@�C������o�^
		bool setFullFileName( const TCHAR* fileName );
		// �o�^���ꂽ�p�X�͑Ó����H
		bool validatePathName();

	private:
		bool pathValidate_;
		static const TCHAR nullStr_g;
		size_t directoryNum_;
		TCHAR *directoryList_[MAXDIRECTORYLISTNUM];
		TCHAR pathName_[FULLPATHLENGTH];
		TCHAR driveName_;
		TCHAR fullFileName_[MAXFILELENGTH];
		TCHAR fileName_[MAXFILELENGTH];
		TCHAR extName_[MAXEXTLENGHT];
	};
}

#endif