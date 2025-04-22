#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "e2e_data_vol_trans_time_criterion_any_of.h"

char *e2e_data_vol_trans_time_criterion_any_of_ToString(
	e2e_data_vol_trans_time_criterion_any_of_e e2e_data_vol_trans_time_criterion_any_of)
{
	const char *e2e_data_vol_trans_time_criterion_any_ofArray[] =
	{ "NULL", "TIME_SLOT_START", "E2E_DATA_VOL_TRANS_TIME" };
	size_t sizeofArray =
		sizeof(e2e_data_vol_trans_time_criterion_any_ofArray) /
		sizeof(e2e_data_vol_trans_time_criterion_any_ofArray[0]);
	if(e2e_data_vol_trans_time_criterion_any_of < sizeofArray) {
		return (char *) e2e_data_vol_trans_time_criterion_any_ofArray[
			e2e_data_vol_trans_time_criterion_any_of];
	} else {
		return (char *) "Unknown";
	}
}

e2e_data_vol_trans_time_criterion_any_of_e
e2e_data_vol_trans_time_criterion_any_of_FromString(
	char *e2e_data_vol_trans_time_criterion_any_of) {
	int stringToReturn = 0;
	const char *e2e_data_vol_trans_time_criterion_any_ofArray[] =
	{ "NULL", "TIME_SLOT_START", "E2E_DATA_VOL_TRANS_TIME" };
	size_t sizeofArray =
		sizeof(e2e_data_vol_trans_time_criterion_any_ofArray) /
		sizeof(e2e_data_vol_trans_time_criterion_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(e2e_data_vol_trans_time_criterion_any_of,
		          e2e_data_vol_trans_time_criterion_any_ofArray[
				  stringToReturn])
		   == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
