#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <pwd.h>

#include "list.h"
#include "colors.h"
#include "config.h"

#define CLR1	RESET BOLD 	FG_RED 	 BG_DEFAULT
#define	CLR2	RESET 		FG_BLUE	 BG_DEFAULT
#define	CLR3	RESET BOLD 	FG_WHITE BG_DEFAULT

List * sdb = 0;

void dbInsert(char *s) {
	Todo * newtd = (Todo *) malloc(sizeof(Todo));
	strcpy(newtd->msg, s);
	
	// setup void pointer
	List  * node = newNode(sizeof(Todo));
	node->data = (void *) newtd;

	// push student last into list
	pushLast(&sdb, node);
}

Todo * get_db_todo(int i) {
	return (Todo *) getNodeByOrder(sdb, i)->data;
}

void dbPrint() {
	int i, L = length(sdb);
	for (i=1; i<=L; i++) {
		printf("%s %2d %s -> %s %s %s\n", CLR1, i, CLR2, CLR3, get_db_todo(i)->msg, RESET);
	}
}

void dbWriteFile(char * db_fname) {
	int i, L = length(sdb);

	FILE *fp = fopen(db_fname, "wb");
	if (!fp) {
		fprintf(stderr, "Could not open [%s]\n", db_fname);
		return ;
	}	

	for (i=1; i<=L; i++) {
		Todo * item = get_db_todo(i);
		fwrite(item, 1, sizeof(Todo), fp);
	}
	fclose(fp);
}

void dbReadFile(char * db_fname)
{
	FILE *fp = fopen(db_fname, "rb");
	if (!fp) {
		return ;
	}
	
	if(fseek(fp, 0, SEEK_END)) {
		fclose(fp);
		fprintf(stderr, "Error reading todos\n");
		exit(1);
	}
	
	int fileSize = ftell(fp);
	int entries = fileSize / sizeof(Todo);
	rewind(fp);
	
	if (fileSize >= sizeof(Todo))
	{
		int i = 0;
		Todo n;
		for (i=1; i<=entries; i++)
		{
			fread(&n, 1, sizeof(Todo), fp);
			dbInsert(n.msg);
		}
	}
}

int help() {
	fprintf(stderr, "[https://github.com/petmakris/todo-cmd]\n");
	return 0;
}

int quit() {
	return 0;
}

int main(int argc, char **argv)
{
	struct passwd *pw = getpwuid(getuid());
	const char *homedir = pw->pw_dir;

	char dbfname [STR_MAX];
	
	strcpy(dbfname, homedir);
	strcat(dbfname, DEFAULT_DB_FNAME);
	
	extern char *optarg;
	char * optarg_insert = 0;
	char * optarg_remove = 0;
	bool bl_size = 0;
	bool bl_clear = 0;
	bool bl_remove = 0;
	bool bl_insert = 0;

	char c;
	while ((c = getopt (argc, argv, "n:r:sc")) != -1)
		switch (c) {
			case 'n': optarg_insert = optarg; bl_insert ++; break;
			case 'r': optarg_remove = optarg; bl_remove ++; break;
			case 's': bl_size ++; break;
			case 'c': bl_clear ++; break;
			default: return help()-1;
		}

	if (bl_insert && bl_remove) {
		return help()-1;
	}

	dbReadFile(dbfname);

	if (bl_size) {
		printf("%d", length(sdb));
		return 0;
	}

	if (bl_clear) {
		clearList(&sdb);
		dbWriteFile(dbfname);
		return 0;	
	}

	if (bl_insert)
	{
		dbInsert(optarg_insert);		
		dbWriteFile(dbfname);
		return 0;
	}
	
	if (bl_remove)
	{
		int i = atoi(optarg_remove);
		if (listValidOrder(sdb, i))
			deleteByOrder(&sdb, i);
		else
			fprintf(stderr, "Out of range\n");
		dbWriteFile(dbfname);
		return 0;
	}

	dbPrint();
	clearList(&sdb);

	return 0;
}

