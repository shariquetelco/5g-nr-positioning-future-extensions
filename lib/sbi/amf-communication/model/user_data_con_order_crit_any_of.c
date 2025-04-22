#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "user_data_con_order_crit_any_of.h"

char *user_data_con_order_crit_any_of_ToString(
	user_data_con_order_crit_any_of_e user_data_con_order_crit_any_of) {
	const char *user_data_con_order_crit_any_ofArray[] =
	{ "NULL", "APPLICABLE_TIME_WINDOW", "NETWORK_STATUS_INDICATION" };
	size_t sizeofArray = sizeof(user_data_con_order_crit_any_ofArray) /
	                     sizeof(user_data_con_order_crit_any_ofArray[0]);
	if(user_data_con_order_crit_any_of < sizeofArray) {
		return (char *) user_data_con_order_crit_any_ofArray[
			user_data_con_order_crit_any_of];
	} else {
		return (char *) "Unknown";
	}
}

user_data_con_order_crit_any_of_e user_data_con_order_crit_any_of_FromString(
	char *user_data_con_order_crit_any_of) {
	int stringToReturn = 0;
	const char *user_data_con_order_crit_any_ofArray[] =
	{ "NULL", "APPLICABLE_TIME_WINDOW", "NETWORK_STATUS_INDICATION" };
	size_t sizeofArray = sizeof(user_data_con_order_crit_any_ofArray) /
	                     sizeof(user_data_con_order_crit_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(user_data_con_order_crit_any_of,
		          user_data_con_order_crit_any_ofArray[stringToReturn])
		   == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
