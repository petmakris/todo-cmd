#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "list.h"
#include "menu.h"

/* colorized for linux
#define MENU_OPTION		"\033[22;32m(\033[01;37m%1c\033[22;32m) %s\033[22;37m\n"
#define MENU_INPUT		"\033[01;33m%s\033[22;37m"
#define MENU_INVALID	"\033[22;31m%s\033[22;37m\n"
*/
#define MENU_OPTION		"(%1c) %s\n"
#define MENU_INPUT		"%s"
#define MENU_INVALID	"%s\n"
#define MENU_RETURN		"\n:result is %d\n"

MenuItem * NewMenuItem(char choice, bool terminal, char *msg, MenuFunction f)
{
	MenuItem *menuitem = malloc(sizeof(MenuItem));
	if (!menuitem)
	{
		fprintf(stderr, "::NewMenuItem()\n");
		return 0;
	}
	menuitem->choice = choice;
	menuitem->terminal = terminal;
	strcpy(menuitem->msg, msg);
	menuitem->menufunc = f;
	return menuitem;
}

void InsertMenuItem(ctList **Menu, char choice, bool terminal, MenuFunction f, char *msg)
{
	if (!isalnum(choice)) 
	{
		fprintf(stderr, "::Menu choice character should be alphanumeric\n");
		return;
	}
	ctList * listnode = NewNode(sizeof(MenuItem));
	MenuItem * menuitem = NewMenuItem(choice, terminal, msg, f);
	
	if (!listnode || !menuitem)
	{
		fprintf(stderr, "::Could not allocate memory in InsertMenuItem()\n");
		return;
	}

	listnode->data = (void *) menuitem;
	
	PushLast(Menu, listnode);
}

MenuItem *GetMenuItem(ctList* Menu, int i)
{
	return (MenuItem *) GetNodeByOrder(Menu, i)->data;
}

void MenuPrintFunction(ctList *item)
{
	MenuItem *t = (MenuItem *) item->data;
	printf(MENU_OPTION, t->choice, t->msg);
}

int ApplicationRun(ctList* *Menu)
{
	bool terminal = false;
	while (!terminal)
	{
		printf("\n");
		PrintList(*Menu, MenuPrintFunction);

		printf(MENU_INPUT, "Input: ");

		char inbuf[255];
		scanf("%s", inbuf);

		bool found = false;		
		int i;
		for (i=1; i<=Length(*Menu); i++)
		{
			// config 
			char ch0 = GetMenuItem(*Menu, i)->choice;
			char ch1 = ch0;
			
			if (isalpha(ch0)) ch1 = toupper(ch0);
			
			if (inbuf[0] == ch0 || inbuf[0] == ch1)
			{
				found = true;
				MenuItem *menuitem = GetMenuItem(*Menu, i);

				printf(MENU_RETURN, menuitem->menufunc());
				if (menuitem->terminal)
				{
					printf(MENU_INVALID, "Exiting Application");
					ClearList(Menu);
					return EXIT_SUCCESS;
				}
			}
		}
		if (!found) printf(MENU_INVALID, "Invalid Selection");
	}
	return EXIT_SUCCESS;
}

