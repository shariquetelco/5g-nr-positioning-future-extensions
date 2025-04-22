#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "collection_period_rmm_nr_mdt_any_of.h"

char *collection_period_rmm_nr_mdt_any_of_ToString(
	collection_period_rmm_nr_mdt_any_of_e collection_period_rmm_nr_mdt_any_of)
{
	const char *collection_period_rmm_nr_mdt_any_ofArray[] =
	{ "NULL", "1024", "2048", "5120", "10240", "60000" };
	size_t sizeofArray = sizeof(collection_period_rmm_nr_mdt_any_ofArray) /
	                     sizeof(collection_period_rmm_nr_mdt_any_ofArray[0]);
	if(collection_period_rmm_nr_mdt_any_of < sizeofArray) {
		return (char *) collection_period_rmm_nr_mdt_any_ofArray[
			collection_period_rmm_nr_mdt_any_of];
	} else {
		return (char *) "Unknown";
	}
}

collection_period_rmm_nr_mdt_any_of_e
collection_period_rmm_nr_mdt_any_of_FromString(
	char *collection_period_rmm_nr_mdt_any_of) {
	int stringToReturn = 0;
	const char *collection_period_rmm_nr_mdt_any_ofArray[] =
	{ "NULL", "1024", "2048", "5120", "10240", "60000" };
	size_t sizeofArray = sizeof(collection_period_rmm_nr_mdt_any_ofArray) /
	                     sizeof(collection_period_rmm_nr_mdt_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(collection_period_rmm_nr_mdt_any_of,
		          collection_period_rmm_nr_mdt_any_ofArray[
				  stringToReturn]) ==
		   0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
