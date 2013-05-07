// PathStrAnalizer.cpp
//
//  �p�X�������̓N���X������
//�@ver 1.00
//
//  ����� : IKD (2007. 9. 17)
//  HP     : http://marupeke296.com/
//

#pragma warning ( disable : 4996 )

#include "PathStrAnalizer.h"
#include <memory.h>

using namespace Dix;

const TCHAR PathStrAnalizer::nullStr_g = 0;

PathStrAnalizer::PathStrAnalizer( TCHAR* pathName ) :
directoryNum_( 0 ),
driveName_( 0 ),
pathValidate_( false )
{
	memset( directoryList_, 0, sizeof( directoryList_ ) );
	memset( pathName_, 0, sizeof( pathName_ ) );
	memset( fileName_, 0, sizeof( fileName_ ) );
	memset( extName_, 0, sizeof( extName_ ) );
	memset( fullFileName_, 0, sizeof( fullFileName_ ) );

	// �f�B���N�g���p�[�T�[�ɂ�����
	if ( pathName && _tcslen( pathName ) )
		pathValidate_ = startDirectoryParser( pathName );
}

PathStrAnalizer::~PathStrAnalizer() {
	size_t i;
	for ( i = 0; i < MAXDIRECTORYLISTNUM; i++ ) {
		safeDeleteDirectory( directoryList_[i] );
	}
}


// �t�@�C���p�X�o�^
bool PathStrAnalizer::regist( const TCHAR *pathName ) {
	pathValidate_ = startDirectoryParser( pathName );
	return pathValidate_;
}


// �o�^���ꂽ�p�X�͑Ó����H
bool PathStrAnalizer::validatePathName() {
	return pathValidate_;
}


// �f�B���N�g���p�[�X�J�n
bool PathStrAnalizer::startDirectoryParser( const TCHAR* pathName ) {
	size_t sz = _tcslen( pathName );
	if( sz == 0 || sz > FULLPATHLENGTH-1 )
		return false;
	size_t prepos = 0;		// �p�[�X�|�W�V����

	// -- �h���C�u���`�F�b�N -- //
	TCHAR driveName[DRIVELENGTH];
	bool isDrive = checkDriveName	( pathName, sz, 0, driveName );
	if( isDrive )
		prepos += DRIVELENGTH - 1;

	// -- �f�B���N�g���`�F�b�N -- //
	TCHAR *directList[MAXDIRECTORYLISTNUM];
	memset( directList, 0, sizeof( TCHAR* ) * MAXDIRECTORYLISTNUM );
	size_t curListNum = 0;
	if ( isDrive ) {
		// �h���C�u�����f�B���N�g���̐擪�ɓo�^
		directList[0] = new TCHAR[ DRIVELENGTH ];
		memset( directList[0], 0, sizeof( TCHAR ) * DRIVELENGTH );
		_tcsncpy( directList[ 0 ], driveName, DRIVELENGTH-2 );	// �f���~�^�͏���
		curListNum++;
	}
	size_t num = 0;
	while( prepos < sz ) {
		size_t yenDelim = findFirstOf( pathName+prepos, sz - prepos, L'\\' );
		size_t slashDelim = findFirstOf( pathName+prepos, sz - prepos,  L'/' );
		num = yenDelim < slashDelim ? yenDelim : slashDelim;
		if ( num != CANNOT_FIND_CHAR ) {
			// �f�B���N�g��������
			if ( num == 0 || !checkFileName( pathName+prepos, num ) ) {
				// �s���ȃf�B���N�g��������������
				size_t i;
				for ( i = 0; i < curListNum ; i++ ) {
					safeDeleteDirectory( directList[ i ] );
				}
				return false;
			}
			directList[ curListNum ] = new TCHAR[ num+1 ];
			memset( directList[ curListNum ], 0, sizeof( TCHAR ) * ( num + 1 ) );
			_tcsncpy( directList[ curListNum ], pathName+prepos, num );
			prepos += num + 1;	// �f���~�^��΂�
			curListNum++;
		}
		else {
			// �t�@�C�����Ƃ��ēo�^
			if ( !setFullFileName( pathName + prepos ) ) {
				size_t i;
				for ( i = 0; i < curListNum ; i++ ) {
					safeDeleteDirectory( directList[ curListNum ] );
				}
				return false;  // �t�@�C�����Ƃ��ĔF�߂��Ȃ�����
			}
			break;
		}
	}

	// �h���C�u����o�^
	if( isDrive ) {
		driveName_ = driveName[0];
	}
	else {
		driveName_ = L'0';
	}

	// �f�B���N�g�����X�g��o�^
	size_t i;
	for ( i = 0; i < curListNum; i++ ) {
		if ( directoryList_[i] )
			safeDeleteDirectory( directoryList_[i] );
		directoryList_[i] = directList[i];
	}
	directoryNum_ = curListNum;

	// �t���p�X�����쐬
	updateFullName();

	return true;
}


// �t���p�X���𐶐��o�^
void PathStrAnalizer::createFullPath( const TCHAR delim ) {
	memset( pathName_, 0, FULLPATHLENGTH );
	size_t fullPos = 0;
	size_t i;
	for ( i = 0; i < directoryNum_; i++ ) {
		size_t Dir_sz = _tcslen( directoryList_[i] );
		_tcsncpy( pathName_ + fullPos, directoryList_[i], Dir_sz );
		pathName_[ fullPos + Dir_sz ] = delim;
		fullPos += Dir_sz + 1;
	}
	_tcsncpy( pathName_ + fullPos, fileName_, _tcslen( fileName_ ) );
	if ( _tcslen( extName_ ) ) {
		*(pathName_ + fullPos + 1) = L'.';
		_tcsncpy( pathName_ + fullPos + 1, extName_, _tcslen( extName_ ) );
	}
}

// �h���C�u�����`�F�b�N
bool PathStrAnalizer::checkDriveName( const TCHAR* pathName, size_t length, size_t pos, TCHAR outDriveName[] ) {
	if( length < 4 ) {
		// ��΃p�X�ł͂Ȃ�
		return false;
	}
	memset( outDriveName, 0, sizeof( TCHAR ) * DRIVELENGTH ); 

	// �h���C�u�`�F�b�N
	TCHAR A = L'A', Z = L'Z', Co = L':';
	TCHAR a = L'a', z = L'z';
	TCHAR name = pathName[0];
	if( ( a <= name && name <= z )
		|| (A <= name && name <= Z ) ) {
		if ( pathName[1] == Co && checkDriveDelim( pathName[2] ) ) {
			// �h���C�u�����o����
			_tcsncpy( outDriveName, pathName, DRIVELENGTH-1 );
			return true;
		}
	}
	return false;
}

// �h���C�u�f���~�^�`�F�b�N
bool PathStrAnalizer::checkDriveDelim( TCHAR delim ) {
	if ( delim == '\\' || delim == '/' )
		return true;
	return false;
}

// ����������
size_t PathStrAnalizer::findFirstOf( const TCHAR *str, size_t sz, const TCHAR c ) {
	size_t i;
	for ( i = 0; i < sz; i++ ) {
		if ( str[i] == c ) {
			return i;
		}
	}
	return CANNOT_FIND_CHAR;
}

// �I��������
size_t PathStrAnalizer::findLastOf( const TCHAR *str, size_t sz, const TCHAR c ) {
	size_t i;
	for ( i = sz-1; i != -1; i-- ) {
		if ( str[i] == c ) {
			return i;
		}
	}
	return CANNOT_FIND_CHAR;
}

// �q�b�g���Ȃ��������I�[���猟��
size_t PathStrAnalizer::findLastNotOf( const TCHAR *str, size_t sz, const TCHAR c ) {
	size_t i;
	for ( i = sz-1; i != -1; i-- ) {
		if ( str[i] != c ) {
			return i;
		}
	}
	return CANNOT_FIND_CHAR;
}


// �h���C�u����o�^
bool PathStrAnalizer::setDriveName( TCHAR driveName ) {
	// ���΃p�X�ł���΃h���C�u���ύX�����Ȃ�
	if ( !isAbsolutePath() )
		return false;

	// �h���C�u�`�F�b�N
	TCHAR A = L'A', Z = L'Z';
	TCHAR a = L'a', z = L'z';
	if( ( a <= driveName && driveName <= z )
		|| (A <= driveName && driveName <= Z ) )
	{
		if ( driveName_ != driveName ) {
			driveName_ = driveName;
			updateFullName();
		}
		return true;
	}
	return false;
}

// �t�@�C�������`�F�b�N
bool PathStrAnalizer::checkFileName( const TCHAR *fileName ) {
	// �t�@�C�����Ƃ��Ĉ����Ȃ��������܂܂�Ă��Ȃ������`�F�b�N
	size_t sz = _tcslen( fileName ), i;
	if( sz > MAXFILELENGTH )
		return false;

	for ( i = 0; i < sz; i++ ) {
		TCHAR c = fileName[i];
		if ( c == L'\\' || c == L'/' || c == L'?'
			|| c == L':' || c == L'*' || c == L'"'
			|| c == L'|' || c == L'<' || c == L'>' || c == '\'' )
		{
			return false;	// �t�@�C�����Ɏg���Ȃ������������Ă���
		}
	}
	return true;
}


// �t�@�C�������`�F�b�N
bool PathStrAnalizer::checkFileName( const TCHAR *fileName, size_t size ) {
	TCHAR tmp[MAXFILELENGTH];
	memset( tmp, 0, sizeof( TCHAR ) * MAXFILELENGTH );
	_tcsncpy( tmp, fileName, size );
	return checkFileName( tmp );
}


// �t���t�@�C������o�^
bool PathStrAnalizer::setFullFileName( const TCHAR* fileName ) {
	if ( !checkFileName( fileName ) )
		return false;
	size_t sz = _tcslen( fileName );
	// �I�[��[.]���`�F�b�N
	size_t pos = sz;
	if ( fileName[sz-1] == L'.' ) {
		pos = findLastNotOf( fileName, sz, L'.' );
	}

	// �g���q�`�F�b�N
	memset( extName_, 0, sizeof( extName_ ) );
	size_t extpos = findLastOf( fileName, pos, L'.' );
	if ( extpos != CANNOT_FIND_CHAR ) {
		setExtName( fileName+extpos+1 );
		setFileName( fileName, extpos );
	}
	else {
		setFileName( fileName, pos );
	}

	updateFullName();

	return true;
}

// �t�@�C������o�^
bool PathStrAnalizer::setFileName( const TCHAR* fileName ) {
	if ( !checkFileName( fileName ) )
		return false;
	size_t sz = _tcslen( fileName );
	memset( fileName_, 0, sizeof( fileName_ ) );

	// �I�[��[.]������Ώ����ēo�^
	if ( fileName[sz-1] == L'.' ) {
		size_t pos = findLastNotOf( fileName, sz, L'.' );
		_tcsncpy( fileName_, fileName, pos+1 );
	}
	else {
		_tcsncpy( fileName_, fileName, sz );
	}

	updateFullName();
	return true;
}

// �t�@�C������o�^
bool PathStrAnalizer::setFileName( const TCHAR* fileName, size_t size ) {
	size_t sz = _tcslen( fileName );
	TCHAR tmpFileName[MAXFILELENGTH];
	memset( tmpFileName, 0, sizeof( TCHAR ) * MAXFILELENGTH );
	_tcsncpy( tmpFileName, fileName, ( sz < size )? sz : size );
	setFileName( tmpFileName );
	return true;
}

// �g���q����o�^
bool PathStrAnalizer::setExtName( const TCHAR* extName ) {
	size_t sz = _tcslen( extName );
	if( sz > MAXEXTLENGHT )
		return false;  // �g���q���I�[�o�[

	if ( !checkFileName( extName ) )
		return false;

	memset( extName_, 0, sizeof( extName_ ) );
	// �I�[��[.]������Ώ����ēo�^
	if ( extName[sz-1] == L'.' ) {
		size_t pos = findLastNotOf( extName, sz, L'.' );
		_tcsncpy( extName_, extName, pos+1 );
	}
	else {
		_tcsncpy( extName_, extName, sz );
	}
	updateFullName();
	return true;
}


// �t���p�X�����擾
const TCHAR* PathStrAnalizer::getFullPathName() const {
	return pathName_;
}

// �t���t�@�C�������擾
const TCHAR* PathStrAnalizer::getFullFileName() const {
	return fullFileName_;
}

// �t�@�C�������擾
const TCHAR* PathStrAnalizer::getFileName() const {
	return fileName_;
}

// �g���q�����擾
const TCHAR* PathStrAnalizer::getExtName() const {
	return extName_;
}

// �f�B���N�g�������擾
const TCHAR* PathStrAnalizer::getDirectoryName( size_t level ) const {
	if ( level >= directoryNum_ )
		return &nullStr_g;
	return directoryList_[level];
}

// �f�B���N�g�������擾
size_t PathStrAnalizer::getDirectoryNum() const {
	return directoryNum_;
}

// �t���p�X�n���A�b�v�f�[�g
void PathStrAnalizer::updateFullName() {
	size_t i;
	// ��΃p�X�ł���΃h���C�u����ύX����
	if ( isAbsolutePath() && directoryList_[0] )
		directoryList_[0][0] = driveName_;

	memset( pathName_, 0, sizeof(TCHAR) * FULLPATHLENGTH );
	for ( i = 0; i < directoryNum_; i++ ) {
		_tcsncat( pathName_, directoryList_[i], _tcslen(directoryList_[i]) );
		_tcsncat( pathName_, _T("/"), 1 );
	}

	memset( fullFileName_, 0, sizeof(TCHAR) * MAXFILELENGTH );
	_tcsncat( fullFileName_, fileName_, _tcslen(fileName_) );
	if ( isExt() ) {
		_tcsncat( fullFileName_, _T("."), 1 );
		_tcsncat( fullFileName_, extName_, _tcslen(extName_) );
	}
	_tcsncat( pathName_, fullFileName_, _tcslen(fullFileName_) );
}

// �g���q�����邩�`�F�b�N
bool PathStrAnalizer::isExt() {
	if ( _tcslen( extName_ ) )
		return true;
	return false;
}


// ��΃p�X���H
bool PathStrAnalizer::isAbsolutePath() {
	return ( driveName_ != L'0' );
}

// �f�B���N�g����}��
bool PathStrAnalizer::insert( size_t level, const TCHAR* directoryName ) {
	size_t num = getDirectoryNum();
	if ( isAbsolutePath() ) {
		// ��΃p�X�̏ꍇ
		// �E ���[�g�ւ̑}��
		// �E �ŉ��wnum���1��(num+1�̈ʒu)�ȉ����w��
		// �̏ꍇ�̓G���[
		if ( level == 0 || level >= num+1 ) {
			return false;
		}
	}
	else {
		// ���΃p�X�̏ꍇ
		// �E �f�B���N�g���������ă��[�g�K�w���w�肵���ꍇ�͗L��
		// �E �f�B���N�g���������Ԃł͍ŉ��w���2���inum + 1�j���w�肵����G���[
		if ( num == 0 ) {
			if ( level != 0 )
				return false;
		}
		else {
			if ( level >= num + 1 ) {
				return false;
			}
		}
	}

	// �}���ӏ��̌����ړ�
	memmove( directoryList_ + level + 1, directoryList_ + level, sizeof( TCHAR* ) * ( num - level + 1 ) );
	directoryList_[level] = new TCHAR[ _tcslen( directoryName ) + 1 ];
	_tcscpy( directoryList_[level], directoryName );
	directoryList_[level][_tcslen( directoryName )] = L'\0';	// �I�[�i�������ǉ�
	directoryNum_++;

	updateFullName();

	return true;
}

// �f�B���N�g����ݒ�
bool PathStrAnalizer::setDirectoryName( size_t level, const TCHAR* directoryName ) {
	size_t num = getDirectoryNum();
	if ( num <= level )
		return false;
	if ( level == 0 && isAbsolutePath() )
		return false;

	// �ύX
	safeDeleteDirectory( directoryList_[level] );
	directoryList_[level] = new TCHAR[ _tcslen( directoryName ) + 1 ];
	_tcscpy( directoryList_[level], directoryName );
	directoryList_[level][_tcslen( directoryName )] = L'\0';	// �I�[�i�������ǉ�

	updateFullName();

	return true;
}

// �f�B���N�g�����폜
bool PathStrAnalizer::deleteDirectory( size_t level ) {
	size_t num = getDirectoryNum();
	// ��΃p�X�̏ꍇ��num=1�ł͏������������̂ŃG���[
	// �܂��h���C�u�͏����Ȃ�
	if ( isAbsolutePath() ) {
		if ( num <= 1 || level >= num || level == 0 )
			return false;
	}
	else {
		// ���΃p�X�̏ꍇ�͏�����f�B���N�g���������ƃG���[
		if ( level >= num )
			return false;
	}

	// �폜
	safeDeleteDirectory( directoryList_[level] );
	memmove( directoryList_ + level, directoryList_ + level + 1, sizeof( TCHAR* ) * ( num - level ) );
	directoryList_[directoryNum_ - 1] = PATHSTRANALIZER_SKIP_PTR;
	directoryNum_--;

	updateFullName();

	return true;
}

// �f�B���N�g���Z�[�t�f���[�g
void PathStrAnalizer::safeDeleteDirectory( TCHAR* deleteDirectory ) {
	if( deleteDirectory && deleteDirectory != PATHSTRANALIZER_SKIP_PTR )
		delete[] deleteDirectory;
}