#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "candidate_for_replacement.h"

candidate_for_replacement_t *candidate_for_replacement_create(snssai_t	*snssai,
                                                              bool	is_dnns_null,
                                                              list_t	*dnns) {
	candidate_for_replacement_t *candidate_for_replacement_local_var =
		malloc(sizeof(candidate_for_replacement_t));

	candidate_for_replacement_local_var->snssai = snssai;
	candidate_for_replacement_local_var->is_dnns_null = is_dnns_null;
	candidate_for_replacement_local_var->dnns = dnns;

	return candidate_for_replacement_local_var;
}

void candidate_for_replacement_free(
	candidate_for_replacement_t *candidate_for_replacement) {
	lnode_t *node = NULL;

	if(NULL == candidate_for_replacement) {
		return;
	}
	if(candidate_for_replacement->snssai) {
		snssai_free(candidate_for_replacement->snssai);
		candidate_for_replacement->snssai = NULL;
	}
	if(candidate_for_replacement->dnns) {
		list_for_each(candidate_for_replacement->dnns, node) {
			free(node->data);
		}
		list_free(candidate_for_replacement->dnns);
		candidate_for_replacement->dnns = NULL;
	}
	free(candidate_for_replacement);
}

cJSON *candidate_for_replacement_convertToJSON(
	candidate_for_replacement_t *candidate_for_replacement) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(candidate_for_replacement == NULL) {
		printf(
			"candidate_for_replacement_convertToJSON() failed [CandidateForReplacement]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!candidate_for_replacement->snssai) {
		printf(
			"candidate_for_replacement_convertToJSON() failed [snssai]");
		return NULL;
	}
	cJSON *snssai_local_JSON = snssai_convertToJSON(
		candidate_for_replacement->snssai);
	if(snssai_local_JSON == NULL) {
		printf(
			"candidate_for_replacement_convertToJSON() failed [snssai]");
		goto end;
	}
	cJSON_AddItemToObject(item, "snssai", snssai_local_JSON);
	if(item->child == NULL) {
		printf(
			"candidate_for_replacement_convertToJSON() failed [snssai]");
		goto end;
	}

	if(candidate_for_replacement->dnns) {
		cJSON *dnnsList = cJSON_AddArrayToObject(item, "dnns");
		if(dnnsList == NULL) {
			printf(
				"candidate_for_replacement_convertToJSON() failed [dnns]");
			goto end;
		}
		list_for_each(candidate_for_replacement->dnns, node) {
			if(cJSON_AddStringToObject(dnnsList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"candidate_for_replacement_convertToJSON() failed [dnns]");
				goto end;
			}
		}
	} else if(candidate_for_replacement->is_dnns_null) {
		if(cJSON_AddNullToObject(item, "dnns") == NULL) {
			printf(
				"candidate_for_replacement_convertToJSON() failed [dnns]");
			goto end;
		}
	}

end:
	return item;
}

candidate_for_replacement_t *candidate_for_replacement_parseFromJSON(
	cJSON *candidate_for_replacementJSON) {
	candidate_for_replacement_t *candidate_for_replacement_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *snssai = NULL;
	snssai_t *snssai_local_nonprim = NULL;
	cJSON *dnns = NULL;
	list_t *dnnsList = NULL;
	snssai = cJSON_GetObjectItemCaseSensitive(candidate_for_replacementJSON,
	                                          "snssai");
	if(!snssai) {
		printf(
			"candidate_for_replacement_parseFromJSON() failed [snssai]");
		goto end;
	}
	snssai_local_nonprim = snssai_parseFromJSON(snssai);
	if(!snssai_local_nonprim) {
		printf("snssai_parseFromJSON failed [snssai]");
		goto end;
	}

	dnns = cJSON_GetObjectItemCaseSensitive(candidate_for_replacementJSON,
	                                        "dnns");
	if(dnns) {
		if(!cJSON_IsNull(dnns)) {
			cJSON *dnns_local = NULL;
			if(!cJSON_IsArray(dnns)) {
				printf(
					"candidate_for_replacement_parseFromJSON() failed [dnns]");
				goto end;
			}

			dnnsList = list_create();

			cJSON_ArrayForEach(dnns_local, dnns) {
				double *localDouble = NULL;
				int *localInt = NULL;
				if(!cJSON_IsString(dnns_local)) {
					printf(
						"candidate_for_replacement_parseFromJSON() failed [dnns]");
					goto end;
				}
				list_add(dnnsList,
				         strdup(dnns_local->valuestring));
			}
		}
	}

	candidate_for_replacement_local_var = candidate_for_replacement_create(
		snssai_local_nonprim,
		dnns &&
		cJSON_IsNull(dnns) ? true : false,
		dnns ? dnnsList : NULL
		);

	return candidate_for_replacement_local_var;
end:
	if(snssai_local_nonprim) {
		snssai_free(snssai_local_nonprim);
		snssai_local_nonprim = NULL;
	}
	if(dnnsList) {
		list_for_each(dnnsList, node) {
			free(node->data);
		}
		list_free(dnnsList);
		dnnsList = NULL;
	}
	return NULL;
}

candidate_for_replacement_t *candidate_for_replacement_copy(
	candidate_for_replacement_t *dst, candidate_for_replacement_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = candidate_for_replacement_convertToJSON(src);
	if(!item) {
		printf("candidate_for_replacement_convertToJSON() failed");
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

	candidate_for_replacement_free(dst);
	dst = candidate_for_replacement_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
