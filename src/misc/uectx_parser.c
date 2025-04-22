#include "uectx_parser.h"

/*
 * getUECTXfromFile - parse target file line by line to extract UE context
 *
 * @path: pat of the target file
 * @list: pointer to the created UE context list
 * @num: pointer to the number of parsed elements
 */
void
getUECTXfromFile(char *path, ue_entry_t **list, size_t *num)
{
	int i, j;
	FILE *fp;
    char * line = 0, *tmp = 0;
    size_t len = 0;
    ue_entry_t *entry = 0;

	/*Check passed input parameter*/
	if(!list || !path || !num || (fp = fopen(path, "r")) == NULL)
	{
		return;
	}

	/*Count entries*/
	for(i = 0; i <= MAX_ENTRY; i++)
	{
		/*Read line from file*/
		if(getline(&line, &len, fp) < 0)
		{
			break;
		}

		free(line);
		len = 0;
		line = 0;

		/*First line (CSV header) can be skipped*/
		if(!i)
		{
			continue;
		}

		*(num) = *(num) + 1;
	}

	/*Reset file pointer to beginning of the file*/
	rewind(fp);

	/*Allocate memory for @list entries*/
	if((*list = calloc(*num, sizeof(ue_entry_t))) == NULL)
	{
		*num = 0;
		return;
	}

	for(i = 0; i <= *num; i++)
	{
		/*Read line from file*/
		if(getline(&line, &len, fp) < 0)
		{
			goto err;
		}

		if(!i)
		{
			free(line);
			len = 0;
			line = 0;
			continue;
		}

		/*Tokenize line*/
		for(j = 0, tmp = strtok(line, ","); tmp != NULL; tmp = strtok(NULL, ","), j++)
		{
			tmp[strlen(tmp)] = 0; //erase '\n' character
			switch (j)
			{
				/*SUPI*/
				case 0:
					list[0][i-1].supi = strdup(tmp);
					break;

				case 1:
					list[0][i-1].lcsid = strdup(tmp);
					break;

				case 2:
					list[0][i-1].ngap_amf = atoi(tmp);
					break;

				case 3:
					list[0][i-1].ngap_ran = atoi(tmp);
					break;
				default:
					goto end;
			}
		}

end:
		free(line);
		line = 0;
		len = 0;
	}

	return;

err:
	for(j = 0; j < i; j++)
	{
		if(list[0][j].supi)
		{
			free(list[0][j].supi);
		}

		if(list[0][j].lcsid)
		{
			free(list[0][j].lcsid);
		}
	}
	free(*list);
	*num = 0;

	return;
}

void
freeUECTXList(ue_entry_t *list, size_t num)
{
	int i;

	if(!num || !list)
	{
		return;
	}

	for(i = 0; i < num; i++)
	{
		if(list[i].supi)
		{
			free(list[i].supi);
		}

		if(list[i].lcsid)
		{
			free(list[i].lcsid);
		}
	}

	free(list);
}
