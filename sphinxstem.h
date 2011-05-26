//
// $Id: sphinxstem.h 2665 2011-02-11 22:43:13Z shodan $
//

//
// Copyright (c) 2001-2011, Andrew Aksyonoff
// Copyright (c) 2008-2011, Sphinx Technologies Inc
// All rights reserved
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License. You should have
// received a copy of the GPL license along with this program; if you
// did not, you can find it at http://www.gnu.org/
//

#ifndef _sphinxstem_
#define _sphinxstem_

// #include "sphinx.h"
#if _WIN32

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define strcasecmp			strcmpi
#define strncasecmp			_strnicmp
#define snprintf			_snprintf
#define strtoll				_strtoi64
#define strtoull			_strtoui64

#else

#if USE_ODBC
// UnixODBC compatible DWORD
#if defined(__alpha) || defined(__sparcv9) || defined(__LP64__) || (defined(__HOS_AIX__) && defined(_LP64))
typedef unsigned int		DWORD;
#else
typedef unsigned long		DWORD;
#endif
#else
// default DWORD
typedef unsigned int		DWORD;
#endif // USE_ODBC

typedef unsigned short		WORD;
typedef unsigned char		BYTE;

#endif // _WIN32

/// initialize English stemmar
void	stem_en_init ();

/// initialize Russian stemmar
void	stem_ru_init ();

/// stem lowercase English word
void	stem_en ( BYTE * pWord, int iLen );

/// stem lowercase Russian word in Windows-1251 encoding
void	stem_ru_cp1251 ( BYTE * pWord );

/// stem lowercase Russian word in UTF-8 encoding
void	stem_ru_utf8 ( WORD * pWord );

/// initialize Czech stemmer
void	stem_cz_init ();

/// stem lowercase Czech word
void	stem_cz ( BYTE * pWord );

/// calculate soundex in-place if the word is lowercase English letters only;
/// do nothing if it's not
void	stem_soundex ( BYTE * pWord );

/// double metaphone stemmer
void	stem_dmetaphone ( BYTE * pWord, bool bUTF8 );

#endif // _sphinxstem_

//
// $Id: sphinxstem.h 2665 2011-02-11 22:43:13Z shodan $
//
