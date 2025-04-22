#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "prose_context.h"

prose_context_t *prose_context_create(ue_auth_t *direct_discovery,
                                      ue_auth_t *direct_comm,
                                      ue_auth_t *l2_relay, ue_auth_t *l3_relay,
                                      ue_auth_t *l2_remote,
                                      ue_auth_t *l3_remote,
                                      ue_auth_t *l2_ue_relay,
                                      ue_auth_t *l3_ue_relay, ue_auth_t *l2_end,
                                      ue_auth_t *l3_end,
                                      ue_auth_t *multi_path_comm,
                                      char *nr_ue_pc5_ambr,
                                      pc5_qo_s_para_t *pc5_qo_s_para) {
	prose_context_t *prose_context_local_var = malloc(
		sizeof(prose_context_t));

	prose_context_local_var->direct_discovery = direct_discovery;
	prose_context_local_var->direct_comm = direct_comm;
	prose_context_local_var->l2_relay = l2_relay;
	prose_context_local_var->l3_relay = l3_relay;
	prose_context_local_var->l2_remote = l2_remote;
	prose_context_local_var->l3_remote = l3_remote;
	prose_context_local_var->l2_ue_relay = l2_ue_relay;
	prose_context_local_var->l3_ue_relay = l3_ue_relay;
	prose_context_local_var->l2_end = l2_end;
	prose_context_local_var->l3_end = l3_end;
	prose_context_local_var->multi_path_comm = multi_path_comm;
	prose_context_local_var->nr_ue_pc5_ambr = nr_ue_pc5_ambr;
	prose_context_local_var->pc5_qo_s_para = pc5_qo_s_para;

	return prose_context_local_var;
}

void prose_context_free(prose_context_t *prose_context) {
	lnode_t *node = NULL;

	if(NULL == prose_context) {
		return;
	}
	if(prose_context->direct_discovery) {
		ue_auth_free(prose_context->direct_discovery);
		prose_context->direct_discovery = NULL;
	}
	if(prose_context->direct_comm) {
		ue_auth_free(prose_context->direct_comm);
		prose_context->direct_comm = NULL;
	}
	if(prose_context->l2_relay) {
		ue_auth_free(prose_context->l2_relay);
		prose_context->l2_relay = NULL;
	}
	if(prose_context->l3_relay) {
		ue_auth_free(prose_context->l3_relay);
		prose_context->l3_relay = NULL;
	}
	if(prose_context->l2_remote) {
		ue_auth_free(prose_context->l2_remote);
		prose_context->l2_remote = NULL;
	}
	if(prose_context->l3_remote) {
		ue_auth_free(prose_context->l3_remote);
		prose_context->l3_remote = NULL;
	}
	if(prose_context->l2_ue_relay) {
		ue_auth_free(prose_context->l2_ue_relay);
		prose_context->l2_ue_relay = NULL;
	}
	if(prose_context->l3_ue_relay) {
		ue_auth_free(prose_context->l3_ue_relay);
		prose_context->l3_ue_relay = NULL;
	}
	if(prose_context->l2_end) {
		ue_auth_free(prose_context->l2_end);
		prose_context->l2_end = NULL;
	}
	if(prose_context->l3_end) {
		ue_auth_free(prose_context->l3_end);
		prose_context->l3_end = NULL;
	}
	if(prose_context->multi_path_comm) {
		ue_auth_free(prose_context->multi_path_comm);
		prose_context->multi_path_comm = NULL;
	}
	if(prose_context->nr_ue_pc5_ambr) {
		free(prose_context->nr_ue_pc5_ambr);
		prose_context->nr_ue_pc5_ambr = NULL;
	}
	if(prose_context->pc5_qo_s_para) {
		pc5_qo_s_para_free(prose_context->pc5_qo_s_para);
		prose_context->pc5_qo_s_para = NULL;
	}
	free(prose_context);
}

cJSON *prose_context_convertToJSON(prose_context_t *prose_context) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(prose_context == NULL) {
		printf("prose_context_convertToJSON() failed [ProseContext]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(prose_context->direct_discovery) {
		cJSON *direct_discovery_local_JSON = ue_auth_convertToJSON(
			prose_context->direct_discovery);
		if(direct_discovery_local_JSON == NULL) {
			printf(
				"prose_context_convertToJSON() failed [direct_discovery]");
			goto end;
		}
		cJSON_AddItemToObject(item, "directDiscovery",
		                      direct_discovery_local_JSON);
		if(item->child == NULL) {
			printf(
				"prose_context_convertToJSON() failed [direct_discovery]");
			goto end;
		}
	}

	if(prose_context->direct_comm) {
		cJSON *direct_comm_local_JSON = ue_auth_convertToJSON(
			prose_context->direct_comm);
		if(direct_comm_local_JSON == NULL) {
			printf(
				"prose_context_convertToJSON() failed [direct_comm]");
			goto end;
		}
		cJSON_AddItemToObject(item, "directComm",
		                      direct_comm_local_JSON);
		if(item->child == NULL) {
			printf(
				"prose_context_convertToJSON() failed [direct_comm]");
			goto end;
		}
	}

	if(prose_context->l2_relay) {
		cJSON *l2_relay_local_JSON = ue_auth_convertToJSON(
			prose_context->l2_relay);
		if(l2_relay_local_JSON == NULL) {
			printf("prose_context_convertToJSON() failed [l2_relay]");
			goto end;
		}
		cJSON_AddItemToObject(item, "l2Relay", l2_relay_local_JSON);
		if(item->child == NULL) {
			printf("prose_context_convertToJSON() failed [l2_relay]");
			goto end;
		}
	}

	if(prose_context->l3_relay) {
		cJSON *l3_relay_local_JSON = ue_auth_convertToJSON(
			prose_context->l3_relay);
		if(l3_relay_local_JSON == NULL) {
			printf("prose_context_convertToJSON() failed [l3_relay]");
			goto end;
		}
		cJSON_AddItemToObject(item, "l3Relay", l3_relay_local_JSON);
		if(item->child == NULL) {
			printf("prose_context_convertToJSON() failed [l3_relay]");
			goto end;
		}
	}

	if(prose_context->l2_remote) {
		cJSON *l2_remote_local_JSON = ue_auth_convertToJSON(
			prose_context->l2_remote);
		if(l2_remote_local_JSON == NULL) {
			printf(
				"prose_context_convertToJSON() failed [l2_remote]");
			goto end;
		}
		cJSON_AddItemToObject(item, "l2Remote", l2_remote_local_JSON);
		if(item->child == NULL) {
			printf(
				"prose_context_convertToJSON() failed [l2_remote]");
			goto end;
		}
	}

	if(prose_context->l3_remote) {
		cJSON *l3_remote_local_JSON = ue_auth_convertToJSON(
			prose_context->l3_remote);
		if(l3_remote_local_JSON == NULL) {
			printf(
				"prose_context_convertToJSON() failed [l3_remote]");
			goto end;
		}
		cJSON_AddItemToObject(item, "l3Remote", l3_remote_local_JSON);
		if(item->child == NULL) {
			printf(
				"prose_context_convertToJSON() failed [l3_remote]");
			goto end;
		}
	}

	if(prose_context->l2_ue_relay) {
		cJSON *l2_ue_relay_local_JSON = ue_auth_convertToJSON(
			prose_context->l2_ue_relay);
		if(l2_ue_relay_local_JSON == NULL) {
			printf(
				"prose_context_convertToJSON() failed [l2_ue_relay]");
			goto end;
		}
		cJSON_AddItemToObject(item, "l2UeRelay",
		                      l2_ue_relay_local_JSON);
		if(item->child == NULL) {
			printf(
				"prose_context_convertToJSON() failed [l2_ue_relay]");
			goto end;
		}
	}

	if(prose_context->l3_ue_relay) {
		cJSON *l3_ue_relay_local_JSON = ue_auth_convertToJSON(
			prose_context->l3_ue_relay);
		if(l3_ue_relay_local_JSON == NULL) {
			printf(
				"prose_context_convertToJSON() failed [l3_ue_relay]");
			goto end;
		}
		cJSON_AddItemToObject(item, "l3UeRelay",
		                      l3_ue_relay_local_JSON);
		if(item->child == NULL) {
			printf(
				"prose_context_convertToJSON() failed [l3_ue_relay]");
			goto end;
		}
	}

	if(prose_context->l2_end) {
		cJSON *l2_end_local_JSON = ue_auth_convertToJSON(
			prose_context->l2_end);
		if(l2_end_local_JSON == NULL) {
			printf("prose_context_convertToJSON() failed [l2_end]");
			goto end;
		}
		cJSON_AddItemToObject(item, "l2End", l2_end_local_JSON);
		if(item->child == NULL) {
			printf("prose_context_convertToJSON() failed [l2_end]");
			goto end;
		}
	}

	if(prose_context->l3_end) {
		cJSON *l3_end_local_JSON = ue_auth_convertToJSON(
			prose_context->l3_end);
		if(l3_end_local_JSON == NULL) {
			printf("prose_context_convertToJSON() failed [l3_end]");
			goto end;
		}
		cJSON_AddItemToObject(item, "l3End", l3_end_local_JSON);
		if(item->child == NULL) {
			printf("prose_context_convertToJSON() failed [l3_end]");
			goto end;
		}
	}

	if(prose_context->multi_path_comm) {
		cJSON *multi_path_comm_local_JSON = ue_auth_convertToJSON(
			prose_context->multi_path_comm);
		if(multi_path_comm_local_JSON == NULL) {
			printf(
				"prose_context_convertToJSON() failed [multi_path_comm]");
			goto end;
		}
		cJSON_AddItemToObject(item, "multiPathComm",
		                      multi_path_comm_local_JSON);
		if(item->child == NULL) {
			printf(
				"prose_context_convertToJSON() failed [multi_path_comm]");
			goto end;
		}
	}

	if(prose_context->nr_ue_pc5_ambr) {
		if(cJSON_AddStringToObject(item, "nrUePc5Ambr",
		                           prose_context->nr_ue_pc5_ambr) ==
		   NULL)
		{
			printf(
				"prose_context_convertToJSON() failed [nr_ue_pc5_ambr]");
			goto end;
		}
	}

	if(prose_context->pc5_qo_s_para) {
		cJSON *pc5_qo_s_para_local_JSON = pc5_qo_s_para_convertToJSON(
			prose_context->pc5_qo_s_para);
		if(pc5_qo_s_para_local_JSON == NULL) {
			printf(
				"prose_context_convertToJSON() failed [pc5_qo_s_para]");
			goto end;
		}
		cJSON_AddItemToObject(item, "pc5QoSPara",
		                      pc5_qo_s_para_local_JSON);
		if(item->child == NULL) {
			printf(
				"prose_context_convertToJSON() failed [pc5_qo_s_para]");
			goto end;
		}
	}

end:
	return item;
}

prose_context_t *prose_context_parseFromJSON(cJSON *prose_contextJSON) {
	prose_context_t *prose_context_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *direct_discovery = NULL;
	ue_auth_t *direct_discovery_local_nonprim = NULL;
	cJSON *direct_comm = NULL;
	ue_auth_t *direct_comm_local_nonprim = NULL;
	cJSON *l2_relay = NULL;
	ue_auth_t *l2_relay_local_nonprim = NULL;
	cJSON *l3_relay = NULL;
	ue_auth_t *l3_relay_local_nonprim = NULL;
	cJSON *l2_remote = NULL;
	ue_auth_t *l2_remote_local_nonprim = NULL;
	cJSON *l3_remote = NULL;
	ue_auth_t *l3_remote_local_nonprim = NULL;
	cJSON *l2_ue_relay = NULL;
	ue_auth_t *l2_ue_relay_local_nonprim = NULL;
	cJSON *l3_ue_relay = NULL;
	ue_auth_t *l3_ue_relay_local_nonprim = NULL;
	cJSON *l2_end = NULL;
	ue_auth_t *l2_end_local_nonprim = NULL;
	cJSON *l3_end = NULL;
	ue_auth_t *l3_end_local_nonprim = NULL;
	cJSON *multi_path_comm = NULL;
	ue_auth_t *multi_path_comm_local_nonprim = NULL;
	cJSON *nr_ue_pc5_ambr = NULL;
	cJSON *pc5_qo_s_para = NULL;
	pc5_qo_s_para_t *pc5_qo_s_para_local_nonprim = NULL;
	direct_discovery = cJSON_GetObjectItemCaseSensitive(prose_contextJSON,
	                                                    "directDiscovery");
	if(direct_discovery) {
		direct_discovery_local_nonprim = ue_auth_parseFromJSON(
			direct_discovery);
		if(!direct_discovery_local_nonprim) {
			printf("ue_auth_parseFromJSON failed [direct_discovery]");
			goto end;
		}
	}

	direct_comm = cJSON_GetObjectItemCaseSensitive(prose_contextJSON,
	                                               "directComm");
	if(direct_comm) {
		direct_comm_local_nonprim = ue_auth_parseFromJSON(direct_comm);
		if(!direct_comm_local_nonprim) {
			printf("ue_auth_parseFromJSON failed [direct_comm]");
			goto end;
		}
	}

	l2_relay =
		cJSON_GetObjectItemCaseSensitive(prose_contextJSON, "l2Relay");
	if(l2_relay) {
		l2_relay_local_nonprim = ue_auth_parseFromJSON(l2_relay);
		if(!l2_relay_local_nonprim) {
			printf("ue_auth_parseFromJSON failed [l2_relay]");
			goto end;
		}
	}

	l3_relay =
		cJSON_GetObjectItemCaseSensitive(prose_contextJSON, "l3Relay");
	if(l3_relay) {
		l3_relay_local_nonprim = ue_auth_parseFromJSON(l3_relay);
		if(!l3_relay_local_nonprim) {
			printf("ue_auth_parseFromJSON failed [l3_relay]");
			goto end;
		}
	}

	l2_remote = cJSON_GetObjectItemCaseSensitive(prose_contextJSON,
	                                             "l2Remote");
	if(l2_remote) {
		l2_remote_local_nonprim = ue_auth_parseFromJSON(l2_remote);
		if(!l2_remote_local_nonprim) {
			printf("ue_auth_parseFromJSON failed [l2_remote]");
			goto end;
		}
	}

	l3_remote = cJSON_GetObjectItemCaseSensitive(prose_contextJSON,
	                                             "l3Remote");
	if(l3_remote) {
		l3_remote_local_nonprim = ue_auth_parseFromJSON(l3_remote);
		if(!l3_remote_local_nonprim) {
			printf("ue_auth_parseFromJSON failed [l3_remote]");
			goto end;
		}
	}

	l2_ue_relay = cJSON_GetObjectItemCaseSensitive(prose_contextJSON,
	                                               "l2UeRelay");
	if(l2_ue_relay) {
		l2_ue_relay_local_nonprim = ue_auth_parseFromJSON(l2_ue_relay);
		if(!l2_ue_relay_local_nonprim) {
			printf("ue_auth_parseFromJSON failed [l2_ue_relay]");
			goto end;
		}
	}

	l3_ue_relay = cJSON_GetObjectItemCaseSensitive(prose_contextJSON,
	                                               "l3UeRelay");
	if(l3_ue_relay) {
		l3_ue_relay_local_nonprim = ue_auth_parseFromJSON(l3_ue_relay);
		if(!l3_ue_relay_local_nonprim) {
			printf("ue_auth_parseFromJSON failed [l3_ue_relay]");
			goto end;
		}
	}

	l2_end = cJSON_GetObjectItemCaseSensitive(prose_contextJSON, "l2End");
	if(l2_end) {
		l2_end_local_nonprim = ue_auth_parseFromJSON(l2_end);
		if(!l2_end_local_nonprim) {
			printf("ue_auth_parseFromJSON failed [l2_end]");
			goto end;
		}
	}

	l3_end = cJSON_GetObjectItemCaseSensitive(prose_contextJSON, "l3End");
	if(l3_end) {
		l3_end_local_nonprim = ue_auth_parseFromJSON(l3_end);
		if(!l3_end_local_nonprim) {
			printf("ue_auth_parseFromJSON failed [l3_end]");
			goto end;
		}
	}

	multi_path_comm = cJSON_GetObjectItemCaseSensitive(prose_contextJSON,
	                                                   "multiPathComm");
	if(multi_path_comm) {
		multi_path_comm_local_nonprim = ue_auth_parseFromJSON(
			multi_path_comm);
		if(!multi_path_comm_local_nonprim) {
			printf("ue_auth_parseFromJSON failed [multi_path_comm]");
			goto end;
		}
	}

	nr_ue_pc5_ambr = cJSON_GetObjectItemCaseSensitive(prose_contextJSON,
	                                                  "nrUePc5Ambr");
	if(nr_ue_pc5_ambr) {
		if(!cJSON_IsString(nr_ue_pc5_ambr) &&
		   !cJSON_IsNull(nr_ue_pc5_ambr))
		{
			printf(
				"prose_context_parseFromJSON() failed [nr_ue_pc5_ambr]");
			goto end;
		}
	}

	pc5_qo_s_para = cJSON_GetObjectItemCaseSensitive(prose_contextJSON,
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

	prose_context_local_var = prose_context_create(
		direct_discovery ? direct_discovery_local_nonprim : NULL,
		direct_comm ? direct_comm_local_nonprim : NULL,
		l2_relay ? l2_relay_local_nonprim : NULL,
		l3_relay ? l3_relay_local_nonprim : NULL,
		l2_remote ? l2_remote_local_nonprim : NULL,
		l3_remote ? l3_remote_local_nonprim : NULL,
		l2_ue_relay ? l2_ue_relay_local_nonprim : NULL,
		l3_ue_relay ? l3_ue_relay_local_nonprim : NULL,
		l2_end ? l2_end_local_nonprim : NULL,
		l3_end ? l3_end_local_nonprim : NULL,
		multi_path_comm ? multi_path_comm_local_nonprim : NULL,
		nr_ue_pc5_ambr &&
		!cJSON_IsNull(nr_ue_pc5_ambr) ? strdup(nr_ue_pc5_ambr->
		                                       valuestring) : NULL,
		pc5_qo_s_para ? pc5_qo_s_para_local_nonprim : NULL
		);

	return prose_context_local_var;
end:
	if(direct_discovery_local_nonprim) {
		ue_auth_free(direct_discovery_local_nonprim);
		direct_discovery_local_nonprim = NULL;
	}
	if(direct_comm_local_nonprim) {
		ue_auth_free(direct_comm_local_nonprim);
		direct_comm_local_nonprim = NULL;
	}
	if(l2_relay_local_nonprim) {
		ue_auth_free(l2_relay_local_nonprim);
		l2_relay_local_nonprim = NULL;
	}
	if(l3_relay_local_nonprim) {
		ue_auth_free(l3_relay_local_nonprim);
		l3_relay_local_nonprim = NULL;
	}
	if(l2_remote_local_nonprim) {
		ue_auth_free(l2_remote_local_nonprim);
		l2_remote_local_nonprim = NULL;
	}
	if(l3_remote_local_nonprim) {
		ue_auth_free(l3_remote_local_nonprim);
		l3_remote_local_nonprim = NULL;
	}
	if(l2_ue_relay_local_nonprim) {
		ue_auth_free(l2_ue_relay_local_nonprim);
		l2_ue_relay_local_nonprim = NULL;
	}
	if(l3_ue_relay_local_nonprim) {
		ue_auth_free(l3_ue_relay_local_nonprim);
		l3_ue_relay_local_nonprim = NULL;
	}
	if(l2_end_local_nonprim) {
		ue_auth_free(l2_end_local_nonprim);
		l2_end_local_nonprim = NULL;
	}
	if(l3_end_local_nonprim) {
		ue_auth_free(l3_end_local_nonprim);
		l3_end_local_nonprim = NULL;
	}
	if(multi_path_comm_local_nonprim) {
		ue_auth_free(multi_path_comm_local_nonprim);
		multi_path_comm_local_nonprim = NULL;
	}
	if(pc5_qo_s_para_local_nonprim) {
		pc5_qo_s_para_free(pc5_qo_s_para_local_nonprim);
		pc5_qo_s_para_local_nonprim = NULL;
	}
	return NULL;
}

prose_context_t *prose_context_copy(prose_context_t	*dst,
                                    prose_context_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = prose_context_convertToJSON(src);
	if(!item) {
		printf("prose_context_convertToJSON() failed");
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

	prose_context_free(dst);
	dst = prose_context_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
