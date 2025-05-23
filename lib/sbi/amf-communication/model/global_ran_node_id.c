#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "global_ran_node_id.h"

global_ran_node_id_t *global_ran_node_id_create(plmn_id_t *plmn_id,
                                                char *n3_iwf_id,
                                                gnb_id_t *g_nb_id,
                                                char *nge_nb_id, char *wagf_id,
                                                char *tngf_id, char *nid,
                                                char *e_nb_id) {
	global_ran_node_id_t *global_ran_node_id_local_var =
		malloc(sizeof(global_ran_node_id_t));

	global_ran_node_id_local_var->plmn_id = plmn_id;
	global_ran_node_id_local_var->n3_iwf_id = n3_iwf_id;
	global_ran_node_id_local_var->g_nb_id = g_nb_id;
	global_ran_node_id_local_var->nge_nb_id = nge_nb_id;
	global_ran_node_id_local_var->wagf_id = wagf_id;
	global_ran_node_id_local_var->tngf_id = tngf_id;
	global_ran_node_id_local_var->nid = nid;
	global_ran_node_id_local_var->e_nb_id = e_nb_id;

	return global_ran_node_id_local_var;
}

void global_ran_node_id_free(global_ran_node_id_t *global_ran_node_id) {
	lnode_t *node = NULL;

	if(NULL == global_ran_node_id) {
		return;
	}
	if(global_ran_node_id->plmn_id) {
		plmn_id_free(global_ran_node_id->plmn_id);
		global_ran_node_id->plmn_id = NULL;
	}
	if(global_ran_node_id->n3_iwf_id) {
		free(global_ran_node_id->n3_iwf_id);
		global_ran_node_id->n3_iwf_id = NULL;
	}
	if(global_ran_node_id->g_nb_id) {
		gnb_id_free(global_ran_node_id->g_nb_id);
		global_ran_node_id->g_nb_id = NULL;
	}
	if(global_ran_node_id->nge_nb_id) {
		free(global_ran_node_id->nge_nb_id);
		global_ran_node_id->nge_nb_id = NULL;
	}
	if(global_ran_node_id->wagf_id) {
		free(global_ran_node_id->wagf_id);
		global_ran_node_id->wagf_id = NULL;
	}
	if(global_ran_node_id->tngf_id) {
		free(global_ran_node_id->tngf_id);
		global_ran_node_id->tngf_id = NULL;
	}
	if(global_ran_node_id->nid) {
		free(global_ran_node_id->nid);
		global_ran_node_id->nid = NULL;
	}
	if(global_ran_node_id->e_nb_id) {
		free(global_ran_node_id->e_nb_id);
		global_ran_node_id->e_nb_id = NULL;
	}
	free(global_ran_node_id);
}

cJSON *global_ran_node_id_convertToJSON(
	global_ran_node_id_t *global_ran_node_id) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(global_ran_node_id == NULL) {
		printf(
			"global_ran_node_id_convertToJSON() failed [GlobalRanNodeId]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!global_ran_node_id->plmn_id) {
		printf("global_ran_node_id_convertToJSON() failed [plmn_id]");
		return NULL;
	}
	cJSON *plmn_id_local_JSON = plmn_id_convertToJSON(
		global_ran_node_id->plmn_id);
	if(plmn_id_local_JSON == NULL) {
		printf("global_ran_node_id_convertToJSON() failed [plmn_id]");
		goto end;
	}
	cJSON_AddItemToObject(item, "plmnId", plmn_id_local_JSON);
	if(item->child == NULL) {
		printf("global_ran_node_id_convertToJSON() failed [plmn_id]");
		goto end;
	}

	if(global_ran_node_id->n3_iwf_id) {
		if(cJSON_AddStringToObject(item, "n3IwfId",
		                           global_ran_node_id->n3_iwf_id) ==
		   NULL)
		{
			printf(
				"global_ran_node_id_convertToJSON() failed [n3_iwf_id]");
			goto end;
		}
	}

	if(global_ran_node_id->g_nb_id) {
		cJSON *g_nb_id_local_JSON = gnb_id_convertToJSON(
			global_ran_node_id->g_nb_id);
		if(g_nb_id_local_JSON == NULL) {
			printf(
				"global_ran_node_id_convertToJSON() failed [g_nb_id]");
			goto end;
		}
		cJSON_AddItemToObject(item, "gNbId", g_nb_id_local_JSON);
		if(item->child == NULL) {
			printf(
				"global_ran_node_id_convertToJSON() failed [g_nb_id]");
			goto end;
		}
	}

	if(global_ran_node_id->nge_nb_id) {
		if(cJSON_AddStringToObject(item, "ngeNbId",
		                           global_ran_node_id->nge_nb_id) ==
		   NULL)
		{
			printf(
				"global_ran_node_id_convertToJSON() failed [nge_nb_id]");
			goto end;
		}
	}

	if(global_ran_node_id->wagf_id) {
		if(cJSON_AddStringToObject(item, "wagfId",
		                           global_ran_node_id->wagf_id) == NULL)
		{
			printf(
				"global_ran_node_id_convertToJSON() failed [wagf_id]");
			goto end;
		}
	}

	if(global_ran_node_id->tngf_id) {
		if(cJSON_AddStringToObject(item, "tngfId",
		                           global_ran_node_id->tngf_id) == NULL)
		{
			printf(
				"global_ran_node_id_convertToJSON() failed [tngf_id]");
			goto end;
		}
	}

	if(global_ran_node_id->nid) {
		if(cJSON_AddStringToObject(item, "nid",
		                           global_ran_node_id->nid) == NULL)
		{
			printf("global_ran_node_id_convertToJSON() failed [nid]");
			goto end;
		}
	}

	if(global_ran_node_id->e_nb_id) {
		if(cJSON_AddStringToObject(item, "eNbId",
		                           global_ran_node_id->e_nb_id) == NULL)
		{
			printf(
				"global_ran_node_id_convertToJSON() failed [e_nb_id]");
			goto end;
		}
	}

end:
	return item;
}

global_ran_node_id_t *global_ran_node_id_parseFromJSON(
	cJSON *global_ran_node_idJSON) {
	global_ran_node_id_t *global_ran_node_id_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *plmn_id = NULL;
	plmn_id_t *plmn_id_local_nonprim = NULL;
	cJSON *n3_iwf_id = NULL;
	cJSON *g_nb_id = NULL;
	gnb_id_t *g_nb_id_local_nonprim = NULL;
	cJSON *nge_nb_id = NULL;
	cJSON *wagf_id = NULL;
	cJSON *tngf_id = NULL;
	cJSON *nid = NULL;
	cJSON *e_nb_id = NULL;
	plmn_id = cJSON_GetObjectItemCaseSensitive(global_ran_node_idJSON,
	                                           "plmnId");
	if(!plmn_id) {
		printf("global_ran_node_id_parseFromJSON() failed [plmn_id]");
		goto end;
	}
	plmn_id_local_nonprim = plmn_id_parseFromJSON(plmn_id);
	if(!plmn_id_local_nonprim) {
		printf("plmn_id_parseFromJSON failed [plmn_id]");
		goto end;
	}

	n3_iwf_id = cJSON_GetObjectItemCaseSensitive(global_ran_node_idJSON,
	                                             "n3IwfId");
	if(n3_iwf_id) {
		if(!cJSON_IsString(n3_iwf_id) &&
		   !cJSON_IsNull(n3_iwf_id))
		{
			printf(
				"global_ran_node_id_parseFromJSON() failed [n3_iwf_id]");
			goto end;
		}
	}

	g_nb_id = cJSON_GetObjectItemCaseSensitive(global_ran_node_idJSON,
	                                           "gNbId");
	if(g_nb_id) {
		g_nb_id_local_nonprim = gnb_id_parseFromJSON(g_nb_id);
		if(!g_nb_id_local_nonprim) {
			printf("gnb_id_parseFromJSON failed [g_nb_id]");
			goto end;
		}
	}

	nge_nb_id = cJSON_GetObjectItemCaseSensitive(global_ran_node_idJSON,
	                                             "ngeNbId");
	if(nge_nb_id) {
		if(!cJSON_IsString(nge_nb_id) &&
		   !cJSON_IsNull(nge_nb_id))
		{
			printf(
				"global_ran_node_id_parseFromJSON() failed [nge_nb_id]");
			goto end;
		}
	}

	wagf_id = cJSON_GetObjectItemCaseSensitive(global_ran_node_idJSON,
	                                           "wagfId");
	if(wagf_id) {
		if(!cJSON_IsString(wagf_id) &&
		   !cJSON_IsNull(wagf_id))
		{
			printf(
				"global_ran_node_id_parseFromJSON() failed [wagf_id]");
			goto end;
		}
	}

	tngf_id = cJSON_GetObjectItemCaseSensitive(global_ran_node_idJSON,
	                                           "tngfId");
	if(tngf_id) {
		if(!cJSON_IsString(tngf_id) &&
		   !cJSON_IsNull(tngf_id))
		{
			printf(
				"global_ran_node_id_parseFromJSON() failed [tngf_id]");
			goto end;
		}
	}

	nid = cJSON_GetObjectItemCaseSensitive(global_ran_node_idJSON, "nid");
	if(nid) {
		if(!cJSON_IsString(nid) &&
		   !cJSON_IsNull(nid))
		{
			printf("global_ran_node_id_parseFromJSON() failed [nid]");
			goto end;
		}
	}

	e_nb_id = cJSON_GetObjectItemCaseSensitive(global_ran_node_idJSON,
	                                           "eNbId");
	if(e_nb_id) {
		if(!cJSON_IsString(e_nb_id) &&
		   !cJSON_IsNull(e_nb_id))
		{
			printf(
				"global_ran_node_id_parseFromJSON() failed [e_nb_id]");
			goto end;
		}
	}

	global_ran_node_id_local_var = global_ran_node_id_create(
		plmn_id_local_nonprim,
		n3_iwf_id &&
		!cJSON_IsNull(n3_iwf_id) ? strdup(
			n3_iwf_id->valuestring) : NULL,
		g_nb_id ? g_nb_id_local_nonprim : NULL,
		nge_nb_id &&
		!cJSON_IsNull(nge_nb_id) ? strdup(
			nge_nb_id->valuestring) : NULL,
		wagf_id &&
		!cJSON_IsNull(wagf_id) ? strdup(wagf_id->valuestring) : NULL,
		tngf_id &&
		!cJSON_IsNull(tngf_id) ? strdup(tngf_id->valuestring) : NULL,
		nid &&
		!cJSON_IsNull(nid) ? strdup(nid->valuestring) : NULL,
		e_nb_id &&
		!cJSON_IsNull(e_nb_id) ? strdup(e_nb_id->valuestring) : NULL
		);

	return global_ran_node_id_local_var;
end:
	if(plmn_id_local_nonprim) {
		plmn_id_free(plmn_id_local_nonprim);
		plmn_id_local_nonprim = NULL;
	}
	if(g_nb_id_local_nonprim) {
		gnb_id_free(g_nb_id_local_nonprim);
		g_nb_id_local_nonprim = NULL;
	}
	return NULL;
}

global_ran_node_id_t *global_ran_node_id_copy(global_ran_node_id_t	*dst,
                                              global_ran_node_id_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = global_ran_node_id_convertToJSON(src);
	if(!item) {
		printf("global_ran_node_id_convertToJSON() failed");
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

	global_ran_node_id_free(dst);
	dst = global_ran_node_id_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
