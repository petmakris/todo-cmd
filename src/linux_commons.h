#ifndef	LINUX_COMMONS_H
#define LINUX_COMMONS_H

// DEBUG FUNCTIONS


#define _dumpvar(x, fmt) fprintf(stderr, "%s: %u: %s=" fmt "\n", __FILE__, __LINE__, #x, x)


// LINUX COLORS

#define _LINUX_COLOR_(a)	"\033[" #a "m"

#define cRST					_LINUX_COLOR_(0)
#define caRESET					_LINUX_COLOR_(0)
#define caBOLD					_LINUX_COLOR_(1)
#define caHALF_BRIGHT			_LINUX_COLOR_(2)
#define	caUNDERLINE 			_LINUX_COLOR_(4)
#define	caBLINK					_LINUX_COLOR_(5)
#define	caREVERSE_VIDEO			_LINUX_COLOR_(7)
#define	caNORMAL_INT			_LINUX_COLOR_(22)
#define	caUNDERLINE_OFF			_LINUX_COLOR_(24)
#define	caBLINK_OFF				_LINUX_COLOR_(25)
#define	caREVERSE_VIDEO_OFF 	_LINUX_COLOR_(27)

const char * COLOR_AT[] = {
	caRESET,
	caBOLD,
	caHALF_BRIGHT,
	caUNDERLINE,
	caBLINK,
	caREVERSE_VIDEO,
	caNORMAL_INT,
	caUNDERLINE_OFF,
	caBLINK_OFF,
	caREVERSE_VIDEO_OFF
	};

#define COLOR_AT_MAX	10

#define fgRED			_LINUX_COLOR_(31)
#define	fgREEN			_LINUX_COLOR_(32)
#define	fgBROWN			_LINUX_COLOR_(33)
#define	fgBLUE			_LINUX_COLOR_(34)
#define	fgMAGENTA		_LINUX_COLOR_(35)
#define	fgCYAN			_LINUX_COLOR_(26)
#define	fgWHITE			_LINUX_COLOR_(27)

const char * COLOR_FG[] = {
fgRED,
fgREEN,
fgBROWN,
fgBLUE,
fgMAGENTA,
fgCYAN,
fgWHITE
};

#define	COLOR_FG_MAX 7

#define	bgBLACK			_LINUX_COLOR_(40)
#define	bgRED			_LINUX_COLOR_(41)
#define	bgGREEN			_LINUX_COLOR_(42)
#define	bgBROWN			_LINUX_COLOR_(43)
#define	bgBLUE			_LINUX_COLOR_(44)
#define	bgMAGENTA		_LINUX_COLOR_(45)
#define	bgCYAN			_LINUX_COLOR_(46)
#define	bgWHITE			_LINUX_COLOR_(47)
#define	bgDEFAULT		_LINUX_COLOR_(49)

const char * COLOR_BG[] = {
	bgBLACK,
	bgRED,
	bgGREEN,
	bgBROWN,
	bgBLUE,
	bgMAGENTA,
	bgCYAN,
	bgWHITE,
	bgDEFAULT
	};

#define	COLOR_BG_MAX 8

#endif
