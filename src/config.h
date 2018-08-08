#ifndef CONFIG_H
#define CONFIG_H

#define STR_MAX		1024
#define DEFAULT_DB_FNAME "/.consoletodo.db"

typedef struct
{
	char  msg[STR_MAX];
} Todo;

#endif

