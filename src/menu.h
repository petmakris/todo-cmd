#ifndef __MENU_H__
#define __MENU_H__

#include <stdbool.h>
#include "list.h"

typedef int (*MenuFunction)(void);

typedef struct
{
	bool terminal;
	char choice;
	char msg[255];
	MenuFunction menufunc;
} MenuItem;

void InsertMenuItem(ctList **Menu, char choice, bool terminal, MenuFunction f, char *msg);
int ApplicationRun(ctList **Menu);

#endif

