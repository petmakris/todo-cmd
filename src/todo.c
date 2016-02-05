#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>	// std boolean variables
#include <string.h>		// for string manipulation
#include <ctype.h>		// for isalpha, isdigit etc
#include <unistd.h>

#include "menu.h" 		// includes a custom menu system
#include "list.h"		// include a double list 
#include "linux_commons.h"

#include <pwd.h>

#include "config.h"

ctList * sdb = 0;

void db_Insert(char *s)
{
	db_todo * newtd = (db_todo *) malloc(sizeof(db_todo));
	strcpy(newtd->msg, s);
	
	// setup void pointer
	ctList  * node = NewNode(sizeof(db_todo));
	node->data = (void *) newtd;
	// push student last into list
	PushLast(&sdb, node);
}

db_todo * get_db_todo(int i)
{
	return (db_todo *) GetNodeByOrder(sdb, i)->data;
}

#define CLR1	cRST caBOLD fgRED bgDEFAULT
#define	CLR2	cRST fgBLUE bgDEFAULT
#define	CLR3	cRST caBOLD fgWHITE bgDEFAULT

void db_Print()
{
	int i, L = Length(sdb);
	for (i=1; i<=L; i++)
		printf("%s %2d %s -> %s %s %s\n", CLR1, i, CLR2, CLR3, get_db_todo(i)->msg, cRST);
}

void db_Write_File(char * db_fname)
{
	int i, L = Length(sdb);

	FILE *fp = fopen(db_fname, "wb");
	if (!fp)
	{
		fprintf(stderr, "Could not open %s for writing\n", db_fname);
		return ;
	}	
	

	for (i=1; i<=L; i++)
	{
		db_todo * item = get_db_todo(i);
		fwrite(item, 1, sizeof(db_todo), fp);
		
	}
	fclose(fp);
}

void db_Read_File(char * db_fname)
{
	FILE *fp = fopen(db_fname, "rb");
	if (!fp)
	{
		return ;
	}
	
	if(fseek(fp, 0, SEEK_END))
	{
		fclose(fp);
		fprintf(stderr, "Error While Seeking to End of File\n");
		exit(1);
	}
	
	int FileSize = ftell(fp);
	int Entries = FileSize / sizeof(db_todo);
	rewind(fp);
	
	if (FileSize >= sizeof(db_todo))
	{
		int i = 0;
		db_todo n;
		for (i=1; i<=Entries; i++)
		{
			fread(&n, 1, sizeof(db_todo), fp);
			db_Insert(n.msg);
		}
	}
}

int Help()
{
	fprintf(stderr, "Console todo application\n");
	return 0;
}

int Quit()
{
	return 0;
}

int main(int argc, char **argv)
{



	struct passwd *pw = getpwuid(getuid());
	const char *homedir = pw->pw_dir;

	char db_fname [STR_MAX];
	
	strcpy(db_fname, homedir);
	strcat(db_fname, DEFAULT_DB_FNAME);
	
	extern char *optarg;
	char * optarg_insert = 0;
	char * optarg_remove = 0;
	bool bl_size = 0;
	bool bl_clear = 0;
	bool bl_remove = 0;
	bool bl_insert = 0;

	char c;
	while ((c = getopt (argc, argv, "n:r:sc")) != -1)
		switch (c)
		{
			case 'n': optarg_insert = optarg; bl_insert ++; break;
			case 'r': optarg_remove = optarg; bl_remove ++; break;
			case 's': bl_size ++; break;
			case 'c': bl_clear ++; break;
			default: return Help()-1;
		}

	if (bl_insert && bl_remove)
		return Help()-1;

	db_Read_File(db_fname);

	if (bl_size)
	{
		printf("%d", Length(sdb));
		return 0;
	}

	if (bl_clear)
	{
		ClearList(&sdb);
		db_Write_File(db_fname);
		return 0;	
	}

	if (bl_insert)
	{
		db_Insert(optarg_insert);		
		db_Write_File(db_fname);
		return 0;
	}
	
	if (bl_remove)
	{
		int i = atoi(optarg_remove);
		if (ListValidOrder(sdb, i))
			DeleteByOrder(&sdb, i);
		else
			fprintf(stderr, "Out of range\n");
		db_Write_File(db_fname);
		return 0;
	}

	db_Print(sdb);
	ClearList(&sdb);

	return 0;
}

