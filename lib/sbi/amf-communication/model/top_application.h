/*
 * top_application.h
 *
 * Top application that contributes the most to the traffic.
 */

#ifndef _top_application_H_
#define _top_application_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "flow_info.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct top_application_s top_application_t;
typedef struct top_application_s {
	char *app_id;
	struct flow_info_s *ip_traffic_filter;
	bool is_ratio;
	int ratio;
} top_application_t;

top_application_t *top_application_create(char *app_id,
                                          flow_info_t *ip_traffic_filter,
                                          bool is_ratio, int ratio);
void top_application_free(top_application_t *top_application);
top_application_t *top_application_parseFromJSON(cJSON *top_applicationJSON);
cJSON *top_application_convertToJSON(top_application_t *top_application);
top_application_t *top_application_copy(top_application_t	*dst,
                                        top_application_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _top_application_H_ */
