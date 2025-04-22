#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "trace_data.h"

trace_data_t *trace_data_create(char *trace_ref, trace_depth_t *trace_depth,
                                char *ne_type_list, char *event_list,
                                char *collection_entity_ipv4_addr,
                                ipv6_addr_t *collection_entity_ipv6_addr,
                                char *trace_reporting_consumer_uri,
                                char *interface_list) {
	trace_data_t *trace_data_local_var = malloc(sizeof(trace_data_t));

	trace_data_local_var->trace_ref = trace_ref;
	trace_data_local_var->trace_depth = trace_depth;
	trace_data_local_var->ne_type_list = ne_type_list;
	trace_data_local_var->event_list = event_list;
	trace_data_local_var->collection_entity_ipv4_addr =
		collection_entity_ipv4_addr;
	trace_data_local_var->collection_entity_ipv6_addr =
		collection_entity_ipv6_addr;
	trace_data_local_var->trace_reporting_consumer_uri =
		trace_reporting_consumer_uri;
	trace_data_local_var->interface_list = interface_list;

	return trace_data_local_var;
}

void trace_data_free(trace_data_t *trace_data) {
	lnode_t *node = NULL;

	if(NULL == trace_data) {
		return;
	}
	if(trace_data->trace_ref) {
		free(trace_data->trace_ref);
		trace_data->trace_ref = NULL;
	}
	if(trace_data->trace_depth) {
		trace_depth_free(trace_data->trace_depth);
		trace_data->trace_depth = NULL;
	}
	if(trace_data->ne_type_list) {
		free(trace_data->ne_type_list);
		trace_data->ne_type_list = NULL;
	}
	if(trace_data->event_list) {
		free(trace_data->event_list);
		trace_data->event_list = NULL;
	}
	if(trace_data->collection_entity_ipv4_addr) {
		free(trace_data->collection_entity_ipv4_addr);
		trace_data->collection_entity_ipv4_addr = NULL;
	}
	if(trace_data->collection_entity_ipv6_addr) {
		ipv6_addr_free(trace_data->collection_entity_ipv6_addr);
		trace_data->collection_entity_ipv6_addr = NULL;
	}
	if(trace_data->trace_reporting_consumer_uri) {
		free(trace_data->trace_reporting_consumer_uri);
		trace_data->trace_reporting_consumer_uri = NULL;
	}
	if(trace_data->interface_list) {
		free(trace_data->interface_list);
		trace_data->interface_list = NULL;
	}
	free(trace_data);
}

cJSON *trace_data_convertToJSON(trace_data_t *trace_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(trace_data == NULL) {
		printf("trace_data_convertToJSON() failed [TraceData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!trace_data->trace_ref) {
		printf("trace_data_convertToJSON() failed [trace_ref]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "traceRef",
	                           trace_data->trace_ref) == NULL)
	{
		printf("trace_data_convertToJSON() failed [trace_ref]");
		goto end;
	}

	if(!trace_data->trace_depth) {
		printf("trace_data_convertToJSON() failed [trace_depth]");
		return NULL;
	}
	cJSON *trace_depth_local_JSON = trace_depth_convertToJSON(
		trace_data->trace_depth);
	if(trace_depth_local_JSON == NULL) {
		printf("trace_data_convertToJSON() failed [trace_depth]");
		goto end;
	}
	cJSON_AddItemToObject(item, "traceDepth", trace_depth_local_JSON);
	if(item->child == NULL) {
		printf("trace_data_convertToJSON() failed [trace_depth]");
		goto end;
	}

	if(!trace_data->ne_type_list) {
		printf("trace_data_convertToJSON() failed [ne_type_list]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "neTypeList",
	                           trace_data->ne_type_list) == NULL)
	{
		printf("trace_data_convertToJSON() failed [ne_type_list]");
		goto end;
	}

	if(!trace_data->event_list) {
		printf("trace_data_convertToJSON() failed [event_list]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "eventList",
	                           trace_data->event_list) == NULL)
	{
		printf("trace_data_convertToJSON() failed [event_list]");
		goto end;
	}

	if(trace_data->collection_entity_ipv4_addr) {
		if(cJSON_AddStringToObject(item, "collectionEntityIpv4Addr",
		                           trace_data->
		                           collection_entity_ipv4_addr) == NULL)
		{
			printf(
				"trace_data_convertToJSON() failed [collection_entity_ipv4_addr]");
			goto end;
		}
	}

	if(trace_data->collection_entity_ipv6_addr) {
		cJSON *collection_entity_ipv6_addr_local_JSON =
			ipv6_addr_convertToJSON(
				trace_data->collection_entity_ipv6_addr);
		if(collection_entity_ipv6_addr_local_JSON == NULL) {
			printf(
				"trace_data_convertToJSON() failed [collection_entity_ipv6_addr]");
			goto end;
		}
		cJSON_AddItemToObject(item, "collectionEntityIpv6Addr",
		                      collection_entity_ipv6_addr_local_JSON);
		if(item->child == NULL) {
			printf(
				"trace_data_convertToJSON() failed [collection_entity_ipv6_addr]");
			goto end;
		}
	}

	if(trace_data->trace_reporting_consumer_uri) {
		if(cJSON_AddStringToObject(item, "traceReportingConsumerUri",
		                           trace_data->
		                           trace_reporting_consumer_uri) ==
		   NULL)
		{
			printf(
				"trace_data_convertToJSON() failed [trace_reporting_consumer_uri]");
			goto end;
		}
	}

	if(trace_data->interface_list) {
		if(cJSON_AddStringToObject(item, "interfaceList",
		                           trace_data->interface_list) == NULL)
		{
			printf(
				"trace_data_convertToJSON() failed [interface_list]");
			goto end;
		}
	}

end:
	return item;
}

trace_data_t *trace_data_parseFromJSON(cJSON *trace_dataJSON) {
	trace_data_t *trace_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *trace_ref = NULL;
	cJSON *trace_depth = NULL;
	trace_depth_t *trace_depth_local_nonprim = NULL;
	cJSON *ne_type_list = NULL;
	cJSON *event_list = NULL;
	cJSON *collection_entity_ipv4_addr = NULL;
	cJSON *collection_entity_ipv6_addr = NULL;
	ipv6_addr_t *collection_entity_ipv6_addr_local_nonprim = NULL;
	cJSON *trace_reporting_consumer_uri = NULL;
	cJSON *interface_list = NULL;
	trace_ref =
		cJSON_GetObjectItemCaseSensitive(trace_dataJSON, "traceRef");
	if(!trace_ref) {
		printf("trace_data_parseFromJSON() failed [trace_ref]");
		goto end;
	}
	if(!cJSON_IsString(trace_ref)) {
		printf("trace_data_parseFromJSON() failed [trace_ref]");
		goto end;
	}

	trace_depth = cJSON_GetObjectItemCaseSensitive(trace_dataJSON,
	                                               "traceDepth");
	if(!trace_depth) {
		printf("trace_data_parseFromJSON() failed [trace_depth]");
		goto end;
	}
	trace_depth_local_nonprim = trace_depth_parseFromJSON(trace_depth);
	if(!trace_depth_local_nonprim) {
		printf("trace_depth_parseFromJSON failed [trace_depth]");
		goto end;
	}

	ne_type_list = cJSON_GetObjectItemCaseSensitive(trace_dataJSON,
	                                                "neTypeList");
	if(!ne_type_list) {
		printf("trace_data_parseFromJSON() failed [ne_type_list]");
		goto end;
	}
	if(!cJSON_IsString(ne_type_list)) {
		printf("trace_data_parseFromJSON() failed [ne_type_list]");
		goto end;
	}

	event_list = cJSON_GetObjectItemCaseSensitive(trace_dataJSON,
	                                              "eventList");
	if(!event_list) {
		printf("trace_data_parseFromJSON() failed [event_list]");
		goto end;
	}
	if(!cJSON_IsString(event_list)) {
		printf("trace_data_parseFromJSON() failed [event_list]");
		goto end;
	}

	collection_entity_ipv4_addr = cJSON_GetObjectItemCaseSensitive(
		trace_dataJSON, "collectionEntityIpv4Addr");
	if(collection_entity_ipv4_addr) {
		if(!cJSON_IsString(collection_entity_ipv4_addr) &&
		   !cJSON_IsNull(collection_entity_ipv4_addr))
		{
			printf(
				"trace_data_parseFromJSON() failed [collection_entity_ipv4_addr]");
			goto end;
		}
	}

	collection_entity_ipv6_addr = cJSON_GetObjectItemCaseSensitive(
		trace_dataJSON, "collectionEntityIpv6Addr");
	if(collection_entity_ipv6_addr) {
		collection_entity_ipv6_addr_local_nonprim =
			ipv6_addr_parseFromJSON(collection_entity_ipv6_addr);
		if(!collection_entity_ipv6_addr_local_nonprim) {
			printf(
				"ipv6_addr_parseFromJSON failed [collection_entity_ipv6_addr]");
			goto end;
		}
	}

	trace_reporting_consumer_uri = cJSON_GetObjectItemCaseSensitive(
		trace_dataJSON, "traceReportingConsumerUri");
	if(trace_reporting_consumer_uri) {
		if(!cJSON_IsString(trace_reporting_consumer_uri) &&
		   !cJSON_IsNull(trace_reporting_consumer_uri))
		{
			printf(
				"trace_data_parseFromJSON() failed [trace_reporting_consumer_uri]");
			goto end;
		}
	}

	interface_list = cJSON_GetObjectItemCaseSensitive(trace_dataJSON,
	                                                  "interfaceList");
	if(interface_list) {
		if(!cJSON_IsString(interface_list) &&
		   !cJSON_IsNull(interface_list))
		{
			printf(
				"trace_data_parseFromJSON() failed [interface_list]");
			goto end;
		}
	}

	trace_data_local_var = trace_data_create(
		strdup(trace_ref->valuestring),
		trace_depth_local_nonprim,
		strdup(ne_type_list->valuestring),
		strdup(event_list->valuestring),
		collection_entity_ipv4_addr &&
		!cJSON_IsNull(collection_entity_ipv4_addr) ? strdup(
			collection_entity_ipv4_addr->valuestring) : NULL,
		collection_entity_ipv6_addr ? collection_entity_ipv6_addr_local_nonprim : NULL,
		trace_reporting_consumer_uri &&
		!cJSON_IsNull(trace_reporting_consumer_uri) ? strdup(
			trace_reporting_consumer_uri->valuestring) : NULL,
		interface_list &&
		!cJSON_IsNull(interface_list) ? strdup(interface_list->
		                                       valuestring) : NULL
		);

	return trace_data_local_var;
end:
	if(trace_depth_local_nonprim) {
		trace_depth_free(trace_depth_local_nonprim);
		trace_depth_local_nonprim = NULL;
	}
	if(collection_entity_ipv6_addr_local_nonprim) {
		ipv6_addr_free(collection_entity_ipv6_addr_local_nonprim);
		collection_entity_ipv6_addr_local_nonprim = NULL;
	}
	return NULL;
}

trace_data_t *trace_data_copy(trace_data_t *dst, trace_data_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = trace_data_convertToJSON(src);
	if(!item) {
		printf("trace_data_convertToJSON() failed");
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

	trace_data_free(dst);
	dst = trace_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
