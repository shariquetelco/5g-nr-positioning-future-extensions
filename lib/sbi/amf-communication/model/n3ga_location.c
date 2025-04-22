#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "n3ga_location.h"

n3ga_location_t *n3ga_location_create(tai_t *n3gpp_tai, char *n3_iwf_id,
                                      char *ue_ipv4_addr,
                                      ipv6_addr_t *ue_ipv6_addr,
                                      bool is_port_number, int port_number,
                                      transport_protocol_t *protocol,
                                      tnap_id_t *tnap_id, twap_id_t *twap_id,
                                      hfc_node_id_t *hfc_node_id, char *gli,
                                      line_type_t *w5gban_line_type,
                                      char *gci) {
	n3ga_location_t *n3ga_location_local_var = malloc(
		sizeof(n3ga_location_t));

	n3ga_location_local_var->n3gpp_tai = n3gpp_tai;
	n3ga_location_local_var->n3_iwf_id = n3_iwf_id;
	n3ga_location_local_var->ue_ipv4_addr = ue_ipv4_addr;
	n3ga_location_local_var->ue_ipv6_addr = ue_ipv6_addr;
	n3ga_location_local_var->is_port_number = is_port_number;
	n3ga_location_local_var->port_number = port_number;
	n3ga_location_local_var->protocol = protocol;
	n3ga_location_local_var->tnap_id = tnap_id;
	n3ga_location_local_var->twap_id = twap_id;
	n3ga_location_local_var->hfc_node_id = hfc_node_id;
	n3ga_location_local_var->gli = gli;
	n3ga_location_local_var->w5gban_line_type = w5gban_line_type;
	n3ga_location_local_var->gci = gci;

	return n3ga_location_local_var;
}

void n3ga_location_free(n3ga_location_t *n3ga_location) {
	lnode_t *node = NULL;

	if(NULL == n3ga_location) {
		return;
	}
	if(n3ga_location->n3gpp_tai) {
		tai_free(n3ga_location->n3gpp_tai);
		n3ga_location->n3gpp_tai = NULL;
	}
	if(n3ga_location->n3_iwf_id) {
		free(n3ga_location->n3_iwf_id);
		n3ga_location->n3_iwf_id = NULL;
	}
	if(n3ga_location->ue_ipv4_addr) {
		free(n3ga_location->ue_ipv4_addr);
		n3ga_location->ue_ipv4_addr = NULL;
	}
	if(n3ga_location->ue_ipv6_addr) {
		ipv6_addr_free(n3ga_location->ue_ipv6_addr);
		n3ga_location->ue_ipv6_addr = NULL;
	}
	if(n3ga_location->protocol) {
		transport_protocol_free(n3ga_location->protocol);
		n3ga_location->protocol = NULL;
	}
	if(n3ga_location->tnap_id) {
		tnap_id_free(n3ga_location->tnap_id);
		n3ga_location->tnap_id = NULL;
	}
	if(n3ga_location->twap_id) {
		twap_id_free(n3ga_location->twap_id);
		n3ga_location->twap_id = NULL;
	}
	if(n3ga_location->hfc_node_id) {
		hfc_node_id_free(n3ga_location->hfc_node_id);
		n3ga_location->hfc_node_id = NULL;
	}
	if(n3ga_location->gli) {
		free(n3ga_location->gli);
		n3ga_location->gli = NULL;
	}
	if(n3ga_location->w5gban_line_type) {
		line_type_free(n3ga_location->w5gban_line_type);
		n3ga_location->w5gban_line_type = NULL;
	}
	if(n3ga_location->gci) {
		free(n3ga_location->gci);
		n3ga_location->gci = NULL;
	}
	free(n3ga_location);
}

cJSON *n3ga_location_convertToJSON(n3ga_location_t *n3ga_location) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(n3ga_location == NULL) {
		printf("n3ga_location_convertToJSON() failed [N3gaLocation]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(n3ga_location->n3gpp_tai) {
		cJSON *n3gpp_tai_local_JSON = tai_convertToJSON(
			n3ga_location->n3gpp_tai);
		if(n3gpp_tai_local_JSON == NULL) {
			printf(
				"n3ga_location_convertToJSON() failed [n3gpp_tai]");
			goto end;
		}
		cJSON_AddItemToObject(item, "n3gppTai", n3gpp_tai_local_JSON);
		if(item->child == NULL) {
			printf(
				"n3ga_location_convertToJSON() failed [n3gpp_tai]");
			goto end;
		}
	}

	if(n3ga_location->n3_iwf_id) {
		if(cJSON_AddStringToObject(item, "n3IwfId",
		                           n3ga_location->n3_iwf_id) == NULL)
		{
			printf(
				"n3ga_location_convertToJSON() failed [n3_iwf_id]");
			goto end;
		}
	}

	if(n3ga_location->ue_ipv4_addr) {
		if(cJSON_AddStringToObject(item, "ueIpv4Addr",
		                           n3ga_location->ue_ipv4_addr) == NULL)
		{
			printf(
				"n3ga_location_convertToJSON() failed [ue_ipv4_addr]");
			goto end;
		}
	}

	if(n3ga_location->ue_ipv6_addr) {
		cJSON *ue_ipv6_addr_local_JSON = ipv6_addr_convertToJSON(
			n3ga_location->ue_ipv6_addr);
		if(ue_ipv6_addr_local_JSON == NULL) {
			printf(
				"n3ga_location_convertToJSON() failed [ue_ipv6_addr]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ueIpv6Addr",
		                      ue_ipv6_addr_local_JSON);
		if(item->child == NULL) {
			printf(
				"n3ga_location_convertToJSON() failed [ue_ipv6_addr]");
			goto end;
		}
	}

	if(n3ga_location->is_port_number) {
		if(cJSON_AddNumberToObject(item, "portNumber",
		                           n3ga_location->port_number) == NULL)
		{
			printf(
				"n3ga_location_convertToJSON() failed [port_number]");
			goto end;
		}
	}

	if(n3ga_location->protocol) {
		cJSON *protocol_local_JSON = transport_protocol_convertToJSON(
			n3ga_location->protocol);
		if(protocol_local_JSON == NULL) {
			printf("n3ga_location_convertToJSON() failed [protocol]");
			goto end;
		}
		cJSON_AddItemToObject(item, "protocol", protocol_local_JSON);
		if(item->child == NULL) {
			printf("n3ga_location_convertToJSON() failed [protocol]");
			goto end;
		}
	}

	if(n3ga_location->tnap_id) {
		cJSON *tnap_id_local_JSON = tnap_id_convertToJSON(
			n3ga_location->tnap_id);
		if(tnap_id_local_JSON == NULL) {
			printf("n3ga_location_convertToJSON() failed [tnap_id]");
			goto end;
		}
		cJSON_AddItemToObject(item, "tnapId", tnap_id_local_JSON);
		if(item->child == NULL) {
			printf("n3ga_location_convertToJSON() failed [tnap_id]");
			goto end;
		}
	}

	if(n3ga_location->twap_id) {
		cJSON *twap_id_local_JSON = twap_id_convertToJSON(
			n3ga_location->twap_id);
		if(twap_id_local_JSON == NULL) {
			printf("n3ga_location_convertToJSON() failed [twap_id]");
			goto end;
		}
		cJSON_AddItemToObject(item, "twapId", twap_id_local_JSON);
		if(item->child == NULL) {
			printf("n3ga_location_convertToJSON() failed [twap_id]");
			goto end;
		}
	}

	if(n3ga_location->hfc_node_id) {
		cJSON *hfc_node_id_local_JSON = hfc_node_id_convertToJSON(
			n3ga_location->hfc_node_id);
		if(hfc_node_id_local_JSON == NULL) {
			printf(
				"n3ga_location_convertToJSON() failed [hfc_node_id]");
			goto end;
		}
		cJSON_AddItemToObject(item, "hfcNodeId",
		                      hfc_node_id_local_JSON);
		if(item->child == NULL) {
			printf(
				"n3ga_location_convertToJSON() failed [hfc_node_id]");
			goto end;
		}
	}

	if(n3ga_location->gli) {
		if(cJSON_AddStringToObject(item, "gli",
		                           n3ga_location->gli) == NULL)
		{
			printf("n3ga_location_convertToJSON() failed [gli]");
			goto end;
		}
	}

	if(n3ga_location->w5gban_line_type) {
		cJSON *w5gban_line_type_local_JSON = line_type_convertToJSON(
			n3ga_location->w5gban_line_type);
		if(w5gban_line_type_local_JSON == NULL) {
			printf(
				"n3ga_location_convertToJSON() failed [w5gban_line_type]");
			goto end;
		}
		cJSON_AddItemToObject(item, "w5gbanLineType",
		                      w5gban_line_type_local_JSON);
		if(item->child == NULL) {
			printf(
				"n3ga_location_convertToJSON() failed [w5gban_line_type]");
			goto end;
		}
	}

	if(n3ga_location->gci) {
		if(cJSON_AddStringToObject(item, "gci",
		                           n3ga_location->gci) == NULL)
		{
			printf("n3ga_location_convertToJSON() failed [gci]");
			goto end;
		}
	}

end:
	return item;
}

n3ga_location_t *n3ga_location_parseFromJSON(cJSON *n3ga_locationJSON) {
	n3ga_location_t *n3ga_location_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *n3gpp_tai = NULL;
	tai_t *n3gpp_tai_local_nonprim = NULL;
	cJSON *n3_iwf_id = NULL;
	cJSON *ue_ipv4_addr = NULL;
	cJSON *ue_ipv6_addr = NULL;
	ipv6_addr_t *ue_ipv6_addr_local_nonprim = NULL;
	cJSON *port_number = NULL;
	cJSON *protocol = NULL;
	transport_protocol_t *protocol_local_nonprim = NULL;
	cJSON *tnap_id = NULL;
	tnap_id_t *tnap_id_local_nonprim = NULL;
	cJSON *twap_id = NULL;
	twap_id_t *twap_id_local_nonprim = NULL;
	cJSON *hfc_node_id = NULL;
	hfc_node_id_t *hfc_node_id_local_nonprim = NULL;
	cJSON *gli = NULL;
	cJSON *w5gban_line_type = NULL;
	line_type_t *w5gban_line_type_local_nonprim = NULL;
	cJSON *gci = NULL;
	n3gpp_tai = cJSON_GetObjectItemCaseSensitive(n3ga_locationJSON,
	                                             "n3gppTai");
	if(n3gpp_tai) {
		n3gpp_tai_local_nonprim = tai_parseFromJSON(n3gpp_tai);
		if(!n3gpp_tai_local_nonprim) {
			printf("tai_parseFromJSON failed [n3gpp_tai]");
			goto end;
		}
	}

	n3_iwf_id = cJSON_GetObjectItemCaseSensitive(n3ga_locationJSON,
	                                             "n3IwfId");
	if(n3_iwf_id) {
		if(!cJSON_IsString(n3_iwf_id) &&
		   !cJSON_IsNull(n3_iwf_id))
		{
			printf(
				"n3ga_location_parseFromJSON() failed [n3_iwf_id]");
			goto end;
		}
	}

	ue_ipv4_addr = cJSON_GetObjectItemCaseSensitive(n3ga_locationJSON,
	                                                "ueIpv4Addr");
	if(ue_ipv4_addr) {
		if(!cJSON_IsString(ue_ipv4_addr) &&
		   !cJSON_IsNull(ue_ipv4_addr))
		{
			printf(
				"n3ga_location_parseFromJSON() failed [ue_ipv4_addr]");
			goto end;
		}
	}

	ue_ipv6_addr = cJSON_GetObjectItemCaseSensitive(n3ga_locationJSON,
	                                                "ueIpv6Addr");
	if(ue_ipv6_addr) {
		ue_ipv6_addr_local_nonprim = ipv6_addr_parseFromJSON(
			ue_ipv6_addr);
		if(!ue_ipv6_addr_local_nonprim) {
			printf("ipv6_addr_parseFromJSON failed [ue_ipv6_addr]");
			goto end;
		}
	}

	port_number = cJSON_GetObjectItemCaseSensitive(n3ga_locationJSON,
	                                               "portNumber");
	if(port_number) {
		if(!cJSON_IsNumber(port_number)) {
			printf(
				"n3ga_location_parseFromJSON() failed [port_number]");
			goto end;
		}
	}

	protocol = cJSON_GetObjectItemCaseSensitive(n3ga_locationJSON,
	                                            "protocol");
	if(protocol) {
		protocol_local_nonprim = transport_protocol_parseFromJSON(
			protocol);
		if(!protocol_local_nonprim) {
			printf(
				"transport_protocol_parseFromJSON failed [protocol]");
			goto end;
		}
	}

	tnap_id = cJSON_GetObjectItemCaseSensitive(n3ga_locationJSON, "tnapId");
	if(tnap_id) {
		tnap_id_local_nonprim = tnap_id_parseFromJSON(tnap_id);
		if(!tnap_id_local_nonprim) {
			printf("tnap_id_parseFromJSON failed [tnap_id]");
			goto end;
		}
	}

	twap_id = cJSON_GetObjectItemCaseSensitive(n3ga_locationJSON, "twapId");
	if(twap_id) {
		twap_id_local_nonprim = twap_id_parseFromJSON(twap_id);
		if(!twap_id_local_nonprim) {
			printf("twap_id_parseFromJSON failed [twap_id]");
			goto end;
		}
	}

	hfc_node_id = cJSON_GetObjectItemCaseSensitive(n3ga_locationJSON,
	                                               "hfcNodeId");
	if(hfc_node_id) {
		hfc_node_id_local_nonprim = hfc_node_id_parseFromJSON(
			hfc_node_id);
		if(!hfc_node_id_local_nonprim) {
			printf("hfc_node_id_parseFromJSON failed [hfc_node_id]");
			goto end;
		}
	}

	gli = cJSON_GetObjectItemCaseSensitive(n3ga_locationJSON, "gli");
	if(gli) {
		if(!cJSON_IsString(gli) &&
		   !cJSON_IsNull(gli))
		{
			printf("n3ga_location_parseFromJSON() failed [gli]");
			goto end;
		}
	}

	w5gban_line_type = cJSON_GetObjectItemCaseSensitive(n3ga_locationJSON,
	                                                    "w5gbanLineType");
	if(w5gban_line_type) {
		w5gban_line_type_local_nonprim = line_type_parseFromJSON(
			w5gban_line_type);
		if(!w5gban_line_type_local_nonprim) {
			printf(
				"line_type_parseFromJSON failed [w5gban_line_type]");
			goto end;
		}
	}

	gci = cJSON_GetObjectItemCaseSensitive(n3ga_locationJSON, "gci");
	if(gci) {
		if(!cJSON_IsString(gci) &&
		   !cJSON_IsNull(gci))
		{
			printf("n3ga_location_parseFromJSON() failed [gci]");
			goto end;
		}
	}

	n3ga_location_local_var = n3ga_location_create(
		n3gpp_tai ? n3gpp_tai_local_nonprim : NULL,
		n3_iwf_id &&
		!cJSON_IsNull(n3_iwf_id) ? strdup(
			n3_iwf_id->valuestring) : NULL,
		ue_ipv4_addr &&
		!cJSON_IsNull(ue_ipv4_addr) ? strdup(
			ue_ipv4_addr->valuestring) : NULL,
		ue_ipv6_addr ? ue_ipv6_addr_local_nonprim : NULL,
		port_number ? true : false,
		port_number ? port_number->valuedouble : 0,
		protocol ? protocol_local_nonprim : NULL,
		tnap_id ? tnap_id_local_nonprim : NULL,
		twap_id ? twap_id_local_nonprim : NULL,
		hfc_node_id ? hfc_node_id_local_nonprim : NULL,
		gli &&
		!cJSON_IsNull(gli) ? strdup(gli->valuestring) : NULL,
		w5gban_line_type ? w5gban_line_type_local_nonprim : NULL,
		gci &&
		!cJSON_IsNull(gci) ? strdup(gci->valuestring) : NULL
		);

	return n3ga_location_local_var;
end:
	if(n3gpp_tai_local_nonprim) {
		tai_free(n3gpp_tai_local_nonprim);
		n3gpp_tai_local_nonprim = NULL;
	}
	if(ue_ipv6_addr_local_nonprim) {
		ipv6_addr_free(ue_ipv6_addr_local_nonprim);
		ue_ipv6_addr_local_nonprim = NULL;
	}
	if(protocol_local_nonprim) {
		transport_protocol_free(protocol_local_nonprim);
		protocol_local_nonprim = NULL;
	}
	if(tnap_id_local_nonprim) {
		tnap_id_free(tnap_id_local_nonprim);
		tnap_id_local_nonprim = NULL;
	}
	if(twap_id_local_nonprim) {
		twap_id_free(twap_id_local_nonprim);
		twap_id_local_nonprim = NULL;
	}
	if(hfc_node_id_local_nonprim) {
		hfc_node_id_free(hfc_node_id_local_nonprim);
		hfc_node_id_local_nonprim = NULL;
	}
	if(w5gban_line_type_local_nonprim) {
		line_type_free(w5gban_line_type_local_nonprim);
		w5gban_line_type_local_nonprim = NULL;
	}
	return NULL;
}

n3ga_location_t *n3ga_location_copy(n3ga_location_t	*dst,
                                    n3ga_location_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = n3ga_location_convertToJSON(src);
	if(!item) {
		printf("n3ga_location_convertToJSON() failed");
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

	n3ga_location_free(dst);
	dst = n3ga_location_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
