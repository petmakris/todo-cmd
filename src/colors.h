#ifndef	COLORS_H
#define COLORS_H

// DEBUG FUNCTIONS
#define _dumpvar(x, fmt) fprintf(stderr, "%s: %u: %s=" fmt "\n", __FILE__, __LINE__, #x, x)

// LINUX COLORS
#define __LINUX_COLOR_(a)	"\033[" #a "m"

#define RESET				__LINUX_COLOR_(0)
#define BOLD				__LINUX_COLOR_(1)
#define HALF_BRIGHT			__LINUX_COLOR_(2)
#define	UNDERLINE 			__LINUX_COLOR_(4)
#define	BLINK				__LINUX_COLOR_(5)
#define	REVERSE_VIDEO		__LINUX_COLOR_(7)
#define	NORMAL_INT			__LINUX_COLOR_(22)
#define	UNDERLINE_OFF		__LINUX_COLOR_(24)
#define	BLINK_OFF			__LINUX_COLOR_(25)
#define	REVERSE_VIDEO_OFF 	__LINUX_COLOR_(27)

const char * COLOR_AT[] = {
	RESET,
	BOLD,
	HALF_BRIGHT,
	UNDERLINE,
	BLINK,
	REVERSE_VIDEO,
	NORMAL_INT,
	UNDERLINE_OFF,
	BLINK_OFF,
	REVERSE_VIDEO_OFF
};

#define COLOR_AT_MAX	10

#define FG_RED			__LINUX_COLOR_(31)
#define	FG_GREEN		__LINUX_COLOR_(32)
#define	FG_BROWN		__LINUX_COLOR_(33)
#define	FG_BLUE			__LINUX_COLOR_(34)
#define	FG_MAGENTA		__LINUX_COLOR_(35)
#define	FG_CYAN			__LINUX_COLOR_(26)
#define	FG_WHITE		__LINUX_COLOR_(27)

const char * COLOR_FG[] = {
	FG_RED,
	FG_GREEN,
	FG_BROWN,
	FG_BLUE,
	FG_MAGENTA,
	FG_CYAN,
	FG_WHITE
};

#define	COLOR_FG_MAX 7

#define	BG_BLACK		__LINUX_COLOR_(40)
#define	BG_RED			__LINUX_COLOR_(41)
#define	BG_GREEN		__LINUX_COLOR_(42)
#define	BG_BROWN		__LINUX_COLOR_(43)
#define	BG_BLUE			__LINUX_COLOR_(44)
#define	BG_MAGENTA		__LINUX_COLOR_(45)
#define	BG_CYAN			__LINUX_COLOR_(46)
#define	BG_WHITE		__LINUX_COLOR_(47)
#define	BG_DEFAULT		__LINUX_COLOR_(49)

const char * COLOR_BG[] = {
	BG_BLACK,
	BG_RED,
	BG_GREEN,
	BG_BROWN,
	BG_BLUE,
	BG_MAGENTA,
	BG_CYAN,
	BG_WHITE,
	BG_DEFAULT
};

#define	COLOR_BG_MAX 8

#endif
