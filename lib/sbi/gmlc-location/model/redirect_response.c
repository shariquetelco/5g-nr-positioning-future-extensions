#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "redirect_response.h"

redirect_response_t *redirect_response_create(char *cause, char *target_scp,
                                              char *target_sepp) {
	redirect_response_t *redirect_response_local_var =
		malloc(sizeof(redirect_response_t));

	redirect_response_local_var->cause = cause;
	redirect_response_local_var->target_scp = target_scp;
	redirect_response_local_var->target_sepp = target_sepp;

	return redirect_response_local_var;
}

void redirect_response_free(redirect_response_t *redirect_response) {
	lnode_t *node = NULL;

	if(NULL == redirect_response) {
		return;
	}
	if(redirect_response->cause) {
		free(redirect_response->cause);
		redirect_response->cause = NULL;
	}
	if(redirect_response->target_scp) {
		free(redirect_response->target_scp);
		redirect_response->target_scp = NULL;
	}
	if(redirect_response->target_sepp) {
		free(redirect_response->target_sepp);
		redirect_response->target_sepp = NULL;
	}
	free(redirect_response);
}

cJSON *redirect_response_convertToJSON(redirect_response_t *redirect_response) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(redirect_response == NULL) {
		printf(
			"redirect_response_convertToJSON() failed [RedirectResponse]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(redirect_response->cause) {
		if(cJSON_AddStringToObject(item, "cause",
		                           redirect_response->cause) == NULL)
		{
			printf(
				"redirect_response_convertToJSON() failed [cause]");
			goto end;
		}
	}

	if(redirect_response->target_scp) {
		if(cJSON_AddStringToObject(item, "targetScp",
		                           redirect_response->target_scp) ==
		   NULL)
		{
			printf(
				"redirect_response_convertToJSON() failed [target_scp]");
			goto end;
		}
	}

	if(redirect_response->target_sepp) {
		if(cJSON_AddStringToObject(item, "targetSepp",
		                           redirect_response->target_sepp) ==
		   NULL)
		{
			printf(
				"redirect_response_convertToJSON() failed [target_sepp]");
			goto end;
		}
	}

end:
	return item;
}

redirect_response_t *redirect_response_parseFromJSON(
	cJSON *redirect_responseJSON) {
	redirect_response_t *redirect_response_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *cause = NULL;
	cJSON *target_scp = NULL;
	cJSON *target_sepp = NULL;
	cause =
		cJSON_GetObjectItemCaseSensitive(redirect_responseJSON,
		                                 "cause");
	if(cause) {
		if(!cJSON_IsString(cause) &&
		   !cJSON_IsNull(cause))
		{
			printf(
				"redirect_response_parseFromJSON() failed [cause]");
			goto end;
		}
	}

	target_scp = cJSON_GetObjectItemCaseSensitive(redirect_responseJSON,
	                                              "targetScp");
	if(target_scp) {
		if(!cJSON_IsString(target_scp) &&
		   !cJSON_IsNull(target_scp))
		{
			printf(
				"redirect_response_parseFromJSON() failed [target_scp]");
			goto end;
		}
	}

	target_sepp = cJSON_GetObjectItemCaseSensitive(redirect_responseJSON,
	                                               "targetSepp");
	if(target_sepp) {
		if(!cJSON_IsString(target_sepp) &&
		   !cJSON_IsNull(target_sepp))
		{
			printf(
				"redirect_response_parseFromJSON() failed [target_sepp]");
			goto end;
		}
	}

	redirect_response_local_var = redirect_response_create(
		cause &&
		!cJSON_IsNull(cause) ? strdup(cause->valuestring) : NULL,
		target_scp &&
		!cJSON_IsNull(target_scp) ? strdup(
			target_scp->valuestring) : NULL,
		target_sepp &&
		!cJSON_IsNull(target_sepp) ? strdup(
			target_sepp->valuestring) : NULL
		);

	return redirect_response_local_var;
end:
	return NULL;
}

redirect_response_t *redirect_response_copy(redirect_response_t *dst,
                                            redirect_response_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = redirect_response_convertToJSON(src);
	if(!item) {
		printf("redirect_response_convertToJSON() failed");
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

	redirect_response_free(dst);
	dst = redirect_response_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
