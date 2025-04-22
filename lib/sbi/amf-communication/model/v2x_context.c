#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2x_context.h"

v2x_context_t *v2x_context_create(nr_v2x_auth_t		*nr_v2x_services_auth,
                                  lte_v2x_auth_t	*lte_v2x_services_auth,
                                  char			*nr_ue_sidelink_ambr,
                                  char			*lte_ue_sidelink_ambr,
                                  pc5_qo_s_para_t	*pc5_qo_s_para) {
	v2x_context_t *v2x_context_local_var = malloc(sizeof(v2x_context_t));

	v2x_context_local_var->nr_v2x_services_auth = nr_v2x_services_auth;
	v2x_context_local_var->lte_v2x_services_auth = lte_v2x_services_auth;
	v2x_context_local_var->nr_ue_sidelink_ambr = nr_ue_sidelink_ambr;
	v2x_context_local_var->lte_ue_sidelink_ambr = lte_ue_sidelink_ambr;
	v2x_context_local_var->pc5_qo_s_para = pc5_qo_s_para;

	return v2x_context_local_var;
}

void v2x_context_free(v2x_context_t *v2x_context) {
	lnode_t *node = NULL;

	if(NULL == v2x_context) {
		return;
	}
	if(v2x_context->nr_v2x_services_auth) {
		nr_v2x_auth_free(v2x_context->nr_v2x_services_auth);
		v2x_context->nr_v2x_services_auth = NULL;
	}
	if(v2x_context->lte_v2x_services_auth) {
		lte_v2x_auth_free(v2x_context->lte_v2x_services_auth);
		v2x_context->lte_v2x_services_auth = NULL;
	}
	if(v2x_context->nr_ue_sidelink_ambr) {
		free(v2x_context->nr_ue_sidelink_ambr);
		v2x_context->nr_ue_sidelink_ambr = NULL;
	}
	if(v2x_context->lte_ue_sidelink_ambr) {
		free(v2x_context->lte_ue_sidelink_ambr);
		v2x_context->lte_ue_sidelink_ambr = NULL;
	}
	if(v2x_context->pc5_qo_s_para) {
		pc5_qo_s_para_free(v2x_context->pc5_qo_s_para);
		v2x_context->pc5_qo_s_para = NULL;
	}
	free(v2x_context);
}

cJSON *v2x_context_convertToJSON(v2x_context_t *v2x_context) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(v2x_context == NULL) {
		printf("v2x_context_convertToJSON() failed [V2xContext]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(v2x_context->nr_v2x_services_auth) {
		cJSON *nr_v2x_services_auth_local_JSON =
			nr_v2x_auth_convertToJSON(
				v2x_context->nr_v2x_services_auth);
		if(nr_v2x_services_auth_local_JSON == NULL) {
			printf(
				"v2x_context_convertToJSON() failed [nr_v2x_services_auth]");
			goto end;
		}
		cJSON_AddItemToObject(item, "nrV2xServicesAuth",
		                      nr_v2x_services_auth_local_JSON);
		if(item->child == NULL) {
			printf(
				"v2x_context_convertToJSON() failed [nr_v2x_services_auth]");
			goto end;
		}
	}

	if(v2x_context->lte_v2x_services_auth) {
		cJSON *lte_v2x_services_auth_local_JSON =
			lte_v2x_auth_convertToJSON(
				v2x_context->lte_v2x_services_auth);
		if(lte_v2x_services_auth_local_JSON == NULL) {
			printf(
				"v2x_context_convertToJSON() failed [lte_v2x_services_auth]");
			goto end;
		}
		cJSON_AddItemToObject(item, "lteV2xServicesAuth",
		                      lte_v2x_services_auth_local_JSON);
		if(item->child == NULL) {
			printf(
				"v2x_context_convertToJSON() failed [lte_v2x_services_auth]");
			goto end;
		}
	}

	if(v2x_context->nr_ue_sidelink_ambr) {
		if(cJSON_AddStringToObject(item, "nrUeSidelinkAmbr",
		                           v2x_context->nr_ue_sidelink_ambr) ==
		   NULL)
		{
			printf(
				"v2x_context_convertToJSON() failed [nr_ue_sidelink_ambr]");
			goto end;
		}
	}

	if(v2x_context->lte_ue_sidelink_ambr) {
		if(cJSON_AddStringToObject(item, "lteUeSidelinkAmbr",
		                           v2x_context->lte_ue_sidelink_ambr) ==
		   NULL)
		{
			printf(
				"v2x_context_convertToJSON() failed [lte_ue_sidelink_ambr]");
			goto end;
		}
	}

	if(v2x_context->pc5_qo_s_para) {
		cJSON *pc5_qo_s_para_local_JSON = pc5_qo_s_para_convertToJSON(
			v2x_context->pc5_qo_s_para);
		if(pc5_qo_s_para_local_JSON == NULL) {
			printf(
				"v2x_context_convertToJSON() failed [pc5_qo_s_para]");
			goto end;
		}
		cJSON_AddItemToObject(item, "pc5QoSPara",
		                      pc5_qo_s_para_local_JSON);
		if(item->child == NULL) {
			printf(
				"v2x_context_convertToJSON() failed [pc5_qo_s_para]");
			goto end;
		}
	}

end:
	return item;
}

v2x_context_t *v2x_context_parseFromJSON(cJSON *v2x_contextJSON) {
	v2x_context_t *v2x_context_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *nr_v2x_services_auth = NULL;
	nr_v2x_auth_t *nr_v2x_services_auth_local_nonprim = NULL;
	cJSON *lte_v2x_services_auth = NULL;
	lte_v2x_auth_t *lte_v2x_services_auth_local_nonprim = NULL;
	cJSON *nr_ue_sidelink_ambr = NULL;
	cJSON *lte_ue_sidelink_ambr = NULL;
	cJSON *pc5_qo_s_para = NULL;
	pc5_qo_s_para_t *pc5_qo_s_para_local_nonprim = NULL;
	nr_v2x_services_auth = cJSON_GetObjectItemCaseSensitive(v2x_contextJSON,
	                                                        "nrV2xServicesAuth");
	if(nr_v2x_services_auth) {
		nr_v2x_services_auth_local_nonprim = nr_v2x_auth_parseFromJSON(
			nr_v2x_services_auth);
		if(!nr_v2x_services_auth_local_nonprim) {
			printf(
				"nr_v2x_auth_parseFromJSON failed [nr_v2x_services_auth]");
			goto end;
		}
	}

	lte_v2x_services_auth = cJSON_GetObjectItemCaseSensitive(
		v2x_contextJSON, "lteV2xServicesAuth");
	if(lte_v2x_services_auth) {
		lte_v2x_services_auth_local_nonprim =
			lte_v2x_auth_parseFromJSON(lte_v2x_services_auth);
		if(!lte_v2x_services_auth_local_nonprim) {
			printf(
				"lte_v2x_auth_parseFromJSON failed [lte_v2x_services_auth]");
			goto end;
		}
	}

	nr_ue_sidelink_ambr = cJSON_GetObjectItemCaseSensitive(v2x_contextJSON,
	                                                       "nrUeSidelinkAmbr");
	if(nr_ue_sidelink_ambr) {
		if(!cJSON_IsString(nr_ue_sidelink_ambr) &&
		   !cJSON_IsNull(nr_ue_sidelink_ambr))
		{
			printf(
				"v2x_context_parseFromJSON() failed [nr_ue_sidelink_ambr]");
			goto end;
		}
	}

	lte_ue_sidelink_ambr = cJSON_GetObjectItemCaseSensitive(v2x_contextJSON,
	                                                        "lteUeSidelinkAmbr");
	if(lte_ue_sidelink_ambr) {
		if(!cJSON_IsString(lte_ue_sidelink_ambr) &&
		   !cJSON_IsNull(lte_ue_sidelink_ambr))
		{
			printf(
				"v2x_context_parseFromJSON() failed [lte_ue_sidelink_ambr]");
			goto end;
		}
	}

	pc5_qo_s_para = cJSON_GetObjectItemCaseSensitive(v2x_contextJSON,
	                                                 "pc5QoSPara");
	if(pc5_qo_s_para) {
		pc5_qo_s_para_local_nonprim = pc5_qo_s_para_parseFromJSON(
			pc5_qo_s_para);
		if(!pc5_qo_s_para_local_nonprim) {
			printf(
				"pc5_qo_s_para_parseFromJSON failed [pc5_qo_s_para]");
			goto end;
		}
	}

	v2x_context_local_var = v2x_context_create(
		nr_v2x_services_auth ? nr_v2x_services_auth_local_nonprim : NULL,
		lte_v2x_services_auth ? lte_v2x_services_auth_local_nonprim : NULL,
		nr_ue_sidelink_ambr &&
		!cJSON_IsNull(nr_ue_sidelink_ambr) ? strdup(nr_ue_sidelink_ambr
		                                            ->valuestring) : NULL,
		lte_ue_sidelink_ambr &&
		!cJSON_IsNull(lte_ue_sidelink_ambr) ? strdup(
			lte_ue_sidelink_ambr->valuestring) : NULL,
		pc5_qo_s_para ? pc5_qo_s_para_local_nonprim : NULL
		);

	return v2x_context_local_var;
end:
	if(nr_v2x_services_auth_local_nonprim) {
		nr_v2x_auth_free(nr_v2x_services_auth_local_nonprim);
		nr_v2x_services_auth_local_nonprim = NULL;
	}
	if(lte_v2x_services_auth_local_nonprim) {
		lte_v2x_auth_free(lte_v2x_services_auth_local_nonprim);
		lte_v2x_services_auth_local_nonprim = NULL;
	}
	if(pc5_qo_s_para_local_nonprim) {
		pc5_qo_s_para_free(pc5_qo_s_para_local_nonprim);
		pc5_qo_s_para_local_nonprim = NULL;
	}
	return NULL;
}

v2x_context_t *v2x_context_copy(v2x_context_t *dst, v2x_context_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = v2x_context_convertToJSON(src);
	if(!item) {
		printf("v2x_context_convertToJSON() failed");
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

	v2x_context_free(dst);
	dst = v2x_context_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
