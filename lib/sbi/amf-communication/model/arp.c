#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "arp.h"

arp_t *arp_create(bool is_priority_level_null, int priority_level,
                  preemption_capability_t *preempt_cap,
                  preemption_vulnerability_t *preempt_vuln) {
	arp_t *arp_local_var = malloc(sizeof(arp_t));

	arp_local_var->is_priority_level_null = is_priority_level_null;
	arp_local_var->priority_level = priority_level;
	arp_local_var->preempt_cap = preempt_cap;
	arp_local_var->preempt_vuln = preempt_vuln;

	return arp_local_var;
}

void arp_free(arp_t *arp) {
	lnode_t *node = NULL;

	if(NULL == arp) {
		return;
	}
	if(arp->preempt_cap) {
		preemption_capability_free(arp->preempt_cap);
		arp->preempt_cap = NULL;
	}
	if(arp->preempt_vuln) {
		preemption_vulnerability_free(arp->preempt_vuln);
		arp->preempt_vuln = NULL;
	}
	free(arp);
}

cJSON *arp_convertToJSON(arp_t *arp) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(arp == NULL) {
		printf("arp_convertToJSON() failed [Arp]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "priorityLevel",
	                           arp->priority_level) == NULL)
	{
		printf("arp_convertToJSON() failed [priority_level]");
		goto end;
	}

	if(!arp->preempt_cap) {
		printf("arp_convertToJSON() failed [preempt_cap]");
		return NULL;
	}
	cJSON *preempt_cap_local_JSON = preemption_capability_convertToJSON(
		arp->preempt_cap);
	if(preempt_cap_local_JSON == NULL) {
		printf("arp_convertToJSON() failed [preempt_cap]");
		goto end;
	}
	cJSON_AddItemToObject(item, "preemptCap", preempt_cap_local_JSON);
	if(item->child == NULL) {
		printf("arp_convertToJSON() failed [preempt_cap]");
		goto end;
	}

	if(!arp->preempt_vuln) {
		printf("arp_convertToJSON() failed [preempt_vuln]");
		return NULL;
	}
	cJSON *preempt_vuln_local_JSON = preemption_vulnerability_convertToJSON(
		arp->preempt_vuln);
	if(preempt_vuln_local_JSON == NULL) {
		printf("arp_convertToJSON() failed [preempt_vuln]");
		goto end;
	}
	cJSON_AddItemToObject(item, "preemptVuln", preempt_vuln_local_JSON);
	if(item->child == NULL) {
		printf("arp_convertToJSON() failed [preempt_vuln]");
		goto end;
	}

end:
	return item;
}

arp_t *arp_parseFromJSON(cJSON *arpJSON) {
	arp_t *arp_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *priority_level = NULL;
	cJSON *preempt_cap = NULL;
	preemption_capability_t *preempt_cap_local_nonprim = NULL;
	cJSON *preempt_vuln = NULL;
	preemption_vulnerability_t *preempt_vuln_local_nonprim = NULL;
	priority_level = cJSON_GetObjectItemCaseSensitive(arpJSON,
	                                                  "priorityLevel");
	if(!priority_level) {
		printf("arp_parseFromJSON() failed [priority_level]");
		goto end;
	}
	if(!cJSON_IsNumber(priority_level)) {
		printf("arp_parseFromJSON() failed [priority_level]");
		goto end;
	}

	preempt_cap = cJSON_GetObjectItemCaseSensitive(arpJSON, "preemptCap");
	if(!preempt_cap) {
		printf("arp_parseFromJSON() failed [preempt_cap]");
		goto end;
	}
	preempt_cap_local_nonprim = preemption_capability_parseFromJSON(
		preempt_cap);
	if(!preempt_cap_local_nonprim) {
		printf(
			"preemption_capability_parseFromJSON failed [preempt_cap]");
		goto end;
	}

	preempt_vuln = cJSON_GetObjectItemCaseSensitive(arpJSON, "preemptVuln");
	if(!preempt_vuln) {
		printf("arp_parseFromJSON() failed [preempt_vuln]");
		goto end;
	}
	preempt_vuln_local_nonprim = preemption_vulnerability_parseFromJSON(
		preempt_vuln);
	if(!preempt_vuln_local_nonprim) {
		printf(
			"preemption_vulnerability_parseFromJSON failed [preempt_vuln]");
		goto end;
	}

	arp_local_var = arp_create(
		priority_level &&
		cJSON_IsNull(priority_level) ? true : false,

		priority_level->valuedouble,
		preempt_cap_local_nonprim,
		preempt_vuln_local_nonprim
		);

	return arp_local_var;
end:
	if(preempt_cap_local_nonprim) {
		preemption_capability_free(preempt_cap_local_nonprim);
		preempt_cap_local_nonprim = NULL;
	}
	if(preempt_vuln_local_nonprim) {
		preemption_vulnerability_free(preempt_vuln_local_nonprim);
		preempt_vuln_local_nonprim = NULL;
	}
	return NULL;
}

arp_t *arp_copy(arp_t *dst, arp_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = arp_convertToJSON(src);
	if(!item) {
		printf("arp_convertToJSON() failed");
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

	arp_free(dst);
	dst = arp_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
