#ifndef _UECTX_PARSER_H_
#define _UECTX_PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define MAX_ENTRY 256

typedef struct entry_ue
{
	char *supi;
	char *lcsid;
	long ngap_amf;
	long ngap_ran;
} ue_entry_t;

void getUECTXfromFile(char *path, ue_entry_t **list, size_t *num);
void freeUECTXList(ue_entry_t *list, size_t num);

#endif
