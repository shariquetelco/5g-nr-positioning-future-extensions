#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "user_location.h"

user_location_t *user_location_create(eutra_location_t	*eutra_location,
                                      nr_location_t	*nr_location,
                                      n3ga_location_t	*n3ga_location,
                                      utra_location_t	*utra_location,
                                      gera_location_t	*gera_location) {
	user_location_t *user_location_local_var = malloc(
		sizeof(user_location_t));

	user_location_local_var->eutra_location = eutra_location;
	user_location_local_var->nr_location = nr_location;
	user_location_local_var->n3ga_location = n3ga_location;
	user_location_local_var->utra_location = utra_location;
	user_location_local_var->gera_location = gera_location;

	return user_location_local_var;
}

void user_location_free(user_location_t *user_location) {
	lnode_t *node = NULL;

	if(NULL == user_location) {
		return;
	}
	if(user_location->eutra_location) {
		eutra_location_free(user_location->eutra_location);
		user_location->eutra_location = NULL;
	}
	if(user_location->nr_location) {
		nr_location_free(user_location->nr_location);
		user_location->nr_location = NULL;
	}
	if(user_location->n3ga_location) {
		n3ga_location_free(user_location->n3ga_location);
		user_location->n3ga_location = NULL;
	}
	if(user_location->utra_location) {
		utra_location_free(user_location->utra_location);
		user_location->utra_location = NULL;
	}
	if(user_location->gera_location) {
		gera_location_free(user_location->gera_location);
		user_location->gera_location = NULL;
	}
	free(user_location);
}

cJSON *user_location_convertToJSON(user_location_t *user_location) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(user_location == NULL) {
		printf("user_location_convertToJSON() failed [UserLocation]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(user_location->eutra_location) {
		cJSON *eutra_location_local_JSON = eutra_location_convertToJSON(
			user_location->eutra_location);
		if(eutra_location_local_JSON == NULL) {
			printf(
				"user_location_convertToJSON() failed [eutra_location]");
			goto end;
		}
		cJSON_AddItemToObject(item, "eutraLocation",
		                      eutra_location_local_JSON);
		if(item->child == NULL) {
			printf(
				"user_location_convertToJSON() failed [eutra_location]");
			goto end;
		}
	}

	if(user_location->nr_location) {
		cJSON *nr_location_local_JSON = nr_location_convertToJSON(
			user_location->nr_location);
		if(nr_location_local_JSON == NULL) {
			printf(
				"user_location_convertToJSON() failed [nr_location]");
			goto end;
		}
		cJSON_AddItemToObject(item, "nrLocation",
		                      nr_location_local_JSON);
		if(item->child == NULL) {
			printf(
				"user_location_convertToJSON() failed [nr_location]");
			goto end;
		}
	}

	if(user_location->n3ga_location) {
		cJSON *n3ga_location_local_JSON = n3ga_location_convertToJSON(
			user_location->n3ga_location);
		if(n3ga_location_local_JSON == NULL) {
			printf(
				"user_location_convertToJSON() failed [n3ga_location]");
			goto end;
		}
		cJSON_AddItemToObject(item, "n3gaLocation",
		                      n3ga_location_local_JSON);
		if(item->child == NULL) {
			printf(
				"user_location_convertToJSON() failed [n3ga_location]");
			goto end;
		}
	}

	if(user_location->utra_location) {
		cJSON *utra_location_local_JSON = utra_location_convertToJSON(
			user_location->utra_location);
		if(utra_location_local_JSON == NULL) {
			printf(
				"user_location_convertToJSON() failed [utra_location]");
			goto end;
		}
		cJSON_AddItemToObject(item, "utraLocation",
		                      utra_location_local_JSON);
		if(item->child == NULL) {
			printf(
				"user_location_convertToJSON() failed [utra_location]");
			goto end;
		}
	}

	if(user_location->gera_location) {
		cJSON *gera_location_local_JSON = gera_location_convertToJSON(
			user_location->gera_location);
		if(gera_location_local_JSON == NULL) {
			printf(
				"user_location_convertToJSON() failed [gera_location]");
			goto end;
		}
		cJSON_AddItemToObject(item, "geraLocation",
		                      gera_location_local_JSON);
		if(item->child == NULL) {
			printf(
				"user_location_convertToJSON() failed [gera_location]");
			goto end;
		}
	}

end:
	return item;
}

user_location_t *user_location_parseFromJSON(cJSON *user_locationJSON) {
	user_location_t *user_location_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *eutra_location = NULL;
	eutra_location_t *eutra_location_local_nonprim = NULL;
	cJSON *nr_location = NULL;
	nr_location_t *nr_location_local_nonprim = NULL;
	cJSON *n3ga_location = NULL;
	n3ga_location_t *n3ga_location_local_nonprim = NULL;
	cJSON *utra_location = NULL;
	utra_location_t *utra_location_local_nonprim = NULL;
	cJSON *gera_location = NULL;
	gera_location_t *gera_location_local_nonprim = NULL;
	eutra_location = cJSON_GetObjectItemCaseSensitive(user_locationJSON,
	                                                  "eutraLocation");
	if(eutra_location) {
		eutra_location_local_nonprim = eutra_location_parseFromJSON(
			eutra_location);
		if(!eutra_location_local_nonprim) {
			printf(
				"eutra_location_parseFromJSON failed [eutra_location]");
			goto end;
		}
	}

	nr_location = cJSON_GetObjectItemCaseSensitive(user_locationJSON,
	                                               "nrLocation");
	if(nr_location) {
		nr_location_local_nonprim = nr_location_parseFromJSON(
			nr_location);
		if(!nr_location_local_nonprim) {
			printf("nr_location_parseFromJSON failed [nr_location]");
			goto end;
		}
	}

	n3ga_location = cJSON_GetObjectItemCaseSensitive(user_locationJSON,
	                                                 "n3gaLocation");
	if(n3ga_location) {
		n3ga_location_local_nonprim = n3ga_location_parseFromJSON(
			n3ga_location);
		if(!n3ga_location_local_nonprim) {
			printf(
				"n3ga_location_parseFromJSON failed [n3ga_location]");
			goto end;
		}
	}

	utra_location = cJSON_GetObjectItemCaseSensitive(user_locationJSON,
	                                                 "utraLocation");
	if(utra_location) {
		utra_location_local_nonprim = utra_location_parseFromJSON(
			utra_location);
		if(!utra_location_local_nonprim) {
			printf(
				"utra_location_parseFromJSON failed [utra_location]");
			goto end;
		}
	}

	gera_location = cJSON_GetObjectItemCaseSensitive(user_locationJSON,
	                                                 "geraLocation");
	if(gera_location) {
		gera_location_local_nonprim = gera_location_parseFromJSON(
			gera_location);
		if(!gera_location_local_nonprim) {
			printf(
				"gera_location_parseFromJSON failed [gera_location]");
			goto end;
		}
	}

	user_location_local_var = user_location_create(
		eutra_location ? eutra_location_local_nonprim : NULL,
		nr_location ? nr_location_local_nonprim : NULL,
		n3ga_location ? n3ga_location_local_nonprim : NULL,
		utra_location ? utra_location_local_nonprim : NULL,
		gera_location ? gera_location_local_nonprim : NULL
		);

	return user_location_local_var;
end:
	if(eutra_location_local_nonprim) {
		eutra_location_free(eutra_location_local_nonprim);
		eutra_location_local_nonprim = NULL;
	}
	if(nr_location_local_nonprim) {
		nr_location_free(nr_location_local_nonprim);
		nr_location_local_nonprim = NULL;
	}
	if(n3ga_location_local_nonprim) {
		n3ga_location_free(n3ga_location_local_nonprim);
		n3ga_location_local_nonprim = NULL;
	}
	if(utra_location_local_nonprim) {
		utra_location_free(utra_location_local_nonprim);
		utra_location_local_nonprim = NULL;
	}
	if(gera_location_local_nonprim) {
		gera_location_free(gera_location_local_nonprim);
		gera_location_local_nonprim = NULL;
	}
	return NULL;
}

user_location_t *user_location_copy(user_location_t	*dst,
                                    user_location_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = user_location_convertToJSON(src);
	if(!item) {
		printf("user_location_convertToJSON() failed");
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

	user_location_free(dst);
	dst = user_location_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
