#include <stdio.h>
#include <string.h>		// for string manipulation
#include <unistd.h>
#include <pwd.h>
#include "config.h"

int get_Entries(char * db_fname)
{
	FILE *fp = fopen(db_fname, "rb");
	if (!fp)
	{
		fprintf(stderr, "Could not open %s for reading\n", db_fname);
		return -1;
	}
	
	if(fseek(fp, 0, SEEK_END))
	{
		fclose(fp);
		fprintf(stderr, "Error While Seeking to End of File\n");
		return -1;
	}
	
	int FileSize = ftell(fp);
	if (FileSize == 0)
		return 0;
	else
		return FileSize / sizeof(db_todo);
}

int main(int argc, char **argv)
{
	struct passwd *pw = getpwuid(getuid());
	const char *homedir = pw->pw_dir;

	char db_fname [STR_MAX];
	
	strcpy(db_fname, homedir);
	strcat(db_fname, DEFAULT_DB_FNAME);
	

	printf("%d", get_Entries(db_fname));
	return 0;
}
