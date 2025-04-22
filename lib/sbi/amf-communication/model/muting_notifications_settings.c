#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "muting_notifications_settings.h"

muting_notifications_settings_t *muting_notifications_settings_create(
	bool is_max_no_of_notif, int max_no_of_notif,
	bool is_duration_buffered_notif, int duration_buffered_notif) {
	muting_notifications_settings_t *muting_notifications_settings_local_var
	        = malloc(sizeof(muting_notifications_settings_t));

	muting_notifications_settings_local_var->is_max_no_of_notif =
		is_max_no_of_notif;
	muting_notifications_settings_local_var->max_no_of_notif =
		max_no_of_notif;
	muting_notifications_settings_local_var->is_duration_buffered_notif =
		is_duration_buffered_notif;
	muting_notifications_settings_local_var->duration_buffered_notif =
		duration_buffered_notif;

	return muting_notifications_settings_local_var;
}

void muting_notifications_settings_free(
	muting_notifications_settings_t *muting_notifications_settings) {
	lnode_t *node = NULL;

	if(NULL == muting_notifications_settings) {
		return;
	}
	free(muting_notifications_settings);
}

cJSON *muting_notifications_settings_convertToJSON(
	muting_notifications_settings_t *muting_notifications_settings) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(muting_notifications_settings == NULL) {
		printf(
			"muting_notifications_settings_convertToJSON() failed [MutingNotificationsSettings]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(muting_notifications_settings->is_max_no_of_notif) {
		if(cJSON_AddNumberToObject(item, "maxNoOfNotif",
		                           muting_notifications_settings->
		                           max_no_of_notif) == NULL)
		{
			printf(
				"muting_notifications_settings_convertToJSON() failed [max_no_of_notif]");
			goto end;
		}
	}

	if(muting_notifications_settings->is_duration_buffered_notif) {
		if(cJSON_AddNumberToObject(item, "durationBufferedNotif",
		                           muting_notifications_settings->
		                           duration_buffered_notif) ==
		   NULL)
		{
			printf(
				"muting_notifications_settings_convertToJSON() failed [duration_buffered_notif]");
			goto end;
		}
	}

end:
	return item;
}

muting_notifications_settings_t *muting_notifications_settings_parseFromJSON(
	cJSON *muting_notifications_settingsJSON) {
	muting_notifications_settings_t *muting_notifications_settings_local_var
	        = NULL;
	lnode_t *node = NULL;
	cJSON *max_no_of_notif = NULL;
	cJSON *duration_buffered_notif = NULL;
	max_no_of_notif = cJSON_GetObjectItemCaseSensitive(
		muting_notifications_settingsJSON, "maxNoOfNotif");
	if(max_no_of_notif) {
		if(!cJSON_IsNumber(max_no_of_notif)) {
			printf(
				"muting_notifications_settings_parseFromJSON() failed [max_no_of_notif]");
			goto end;
		}
	}

	duration_buffered_notif = cJSON_GetObjectItemCaseSensitive(
		muting_notifications_settingsJSON, "durationBufferedNotif");
	if(duration_buffered_notif) {
		if(!cJSON_IsNumber(duration_buffered_notif)) {
			printf(
				"muting_notifications_settings_parseFromJSON() failed [duration_buffered_notif]");
			goto end;
		}
	}

	muting_notifications_settings_local_var =
		muting_notifications_settings_create(
			max_no_of_notif ? true : false,
			max_no_of_notif ? max_no_of_notif->valuedouble : 0,
			duration_buffered_notif ? true : false,
			duration_buffered_notif ? duration_buffered_notif->valuedouble : 0
			);

	return muting_notifications_settings_local_var;
end:
	return NULL;
}

muting_notifications_settings_t *muting_notifications_settings_copy(
	muting_notifications_settings_t *dst,
	muting_notifications_settings_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = muting_notifications_settings_convertToJSON(src);
	if(!item) {
		printf("muting_notifications_settings_convertToJSON() failed");
		return NULL;
	}

	content = cJSON_Print(item);
	cJSON_Delete(item);

	if(!content) {
		printf("cJSON_Print() failed");
		return NULL;
	}

	item = cJSON_Parse(content);
	free(content);
	if(!item) {
		printf("cJSON_Parse() failed");
		return NULL;
	}

	muting_notifications_settings_free(dst);
	dst = muting_notifications_settings_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
