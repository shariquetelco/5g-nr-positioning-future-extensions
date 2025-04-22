#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "loc_update_subs.h"

loc_update_subs_t *loc_update_subs_create(char *nf_instance_id, char *notif_uri,
                                          char *gpsi, char *supi) {
	loc_update_subs_t *loc_update_subs_local_var =
		malloc(sizeof(loc_update_subs_t));

	loc_update_subs_local_var->nf_instance_id = nf_instance_id;
	loc_update_subs_local_var->notif_uri = notif_uri;
	loc_update_subs_local_var->gpsi = gpsi;
	loc_update_subs_local_var->supi = supi;

	return loc_update_subs_local_var;
}

void loc_update_subs_free(loc_update_subs_t *loc_update_subs) {
	lnode_t *node = NULL;

	if(NULL == loc_update_subs) {
		return;
	}
	if(loc_update_subs->nf_instance_id) {
		free(loc_update_subs->nf_instance_id);
		loc_update_subs->nf_instance_id = NULL;
	}
	if(loc_update_subs->notif_uri) {
		free(loc_update_subs->notif_uri);
		loc_update_subs->notif_uri = NULL;
	}
	if(loc_update_subs->gpsi) {
		free(loc_update_subs->gpsi);
		loc_update_subs->gpsi = NULL;
	}
	if(loc_update_subs->supi) {
		free(loc_update_subs->supi);
		loc_update_subs->supi = NULL;
	}
	free(loc_update_subs);
}

cJSON *loc_update_subs_convertToJSON(loc_update_subs_t *loc_update_subs) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(loc_update_subs == NULL) {
		printf("loc_update_subs_convertToJSON() failed [LocUpdateSubs]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!loc_update_subs->nf_instance_id) {
		printf("loc_update_subs_convertToJSON() failed [nf_instance_id]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "nfInstanceId",
	                           loc_update_subs->nf_instance_id) == NULL)
	{
		printf("loc_update_subs_convertToJSON() failed [nf_instance_id]");
		goto end;
	}

	if(!loc_update_subs->notif_uri) {
		printf("loc_update_subs_convertToJSON() failed [notif_uri]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "notifURI",
	                           loc_update_subs->notif_uri) == NULL)
	{
		printf("loc_update_subs_convertToJSON() failed [notif_uri]");
		goto end;
	}

	if(loc_update_subs->gpsi) {
		if(cJSON_AddStringToObject(item, "gpsi",
		                           loc_update_subs->gpsi) == NULL)
		{
			printf("loc_update_subs_convertToJSON() failed [gpsi]");
			goto end;
		}
	}

	if(loc_update_subs->supi) {
		if(cJSON_AddStringToObject(item, "supi",
		                           loc_update_subs->supi) == NULL)
		{
			printf("loc_update_subs_convertToJSON() failed [supi]");
			goto end;
		}
	}

end:
	return item;
}

loc_update_subs_t *loc_update_subs_parseFromJSON(cJSON *loc_update_subsJSON) {
	loc_update_subs_t *loc_update_subs_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *nf_instance_id = NULL;
	cJSON *notif_uri = NULL;
	cJSON *gpsi = NULL;
	cJSON *supi = NULL;
	nf_instance_id = cJSON_GetObjectItemCaseSensitive(loc_update_subsJSON,
	                                                  "nfInstanceId");
	if(!nf_instance_id) {
		printf("loc_update_subs_parseFromJSON() failed [nf_instance_id]");
		goto end;
	}
	if(!cJSON_IsString(nf_instance_id)) {
		printf("loc_update_subs_parseFromJSON() failed [nf_instance_id]");
		goto end;
	}

	notif_uri = cJSON_GetObjectItemCaseSensitive(loc_update_subsJSON,
	                                             "notifURI");
	if(!notif_uri) {
		printf("loc_update_subs_parseFromJSON() failed [notif_uri]");
		goto end;
	}
	if(!cJSON_IsString(notif_uri)) {
		printf("loc_update_subs_parseFromJSON() failed [notif_uri]");
		goto end;
	}

	gpsi = cJSON_GetObjectItemCaseSensitive(loc_update_subsJSON, "gpsi");
	if(gpsi) {
		if(!cJSON_IsString(gpsi) &&
		   !cJSON_IsNull(gpsi))
		{
			printf("loc_update_subs_parseFromJSON() failed [gpsi]");
			goto end;
		}
	}

	supi = cJSON_GetObjectItemCaseSensitive(loc_update_subsJSON, "supi");
	if(supi) {
		if(!cJSON_IsString(supi) &&
		   !cJSON_IsNull(supi))
		{
			printf("loc_update_subs_parseFromJSON() failed [supi]");
			goto end;
		}
	}

	loc_update_subs_local_var = loc_update_subs_create(
		strdup(nf_instance_id->valuestring),
		strdup(notif_uri->valuestring),
		gpsi &&
		!cJSON_IsNull(gpsi) ? strdup(gpsi->valuestring) : NULL,
		supi &&
		!cJSON_IsNull(supi) ? strdup(supi->valuestring) : NULL
		);

	return loc_update_subs_local_var;
end:
	return NULL;
}

loc_update_subs_t *loc_update_subs_copy(loc_update_subs_t	*dst,
                                        loc_update_subs_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = loc_update_subs_convertToJSON(src);
	if(!item) {
		printf("loc_update_subs_convertToJSON() failed");
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

	loc_update_subs_free(dst);
	dst = loc_update_subs_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
