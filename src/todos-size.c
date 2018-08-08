#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include "config.h"


#include "colors.h"

#define CLR1	RESET BOLD FG_GREEN BG_DEFAULT
#define	CLR2	RESET BOLD FG_WHITE BG_DEFAULT

int getEntries(char * db_fname) {

	FILE *fp = fopen(db_fname, "rb");
	if (!fp) {
		fprintf(stderr, "Could not open [%s] for reading\n", db_fname);
		return -1;
	}
	if(fseek(fp, 0, SEEK_END)) {
		fclose(fp);
		fprintf(stderr, "Error while seeking EOF\n");
		return -1;
	}
	int fileSize = ftell(fp);
	if (fileSize == 0)
		return 0;
	else
		return fileSize / sizeof(Todo);
}

int main(int argc, char **argv) {
	struct passwd *pw = getpwuid(getuid());
	const char *homedir = pw->pw_dir;

	char db_fname [STR_MAX];
	
	strcpy(db_fname, homedir);
	strcat(db_fname, DEFAULT_DB_FNAME);

	int v = getEntries(db_fname);

	if (v!=0) {
		printf("%s[%s%d%s]%s", 
					CLR1, 
					CLR2, 
					getEntries(db_fname), 
					CLR1,
					RESET);
	}
	return 0;
}
