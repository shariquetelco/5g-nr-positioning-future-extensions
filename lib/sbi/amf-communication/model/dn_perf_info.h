/*
 * dn_perf_info.h
 *
 * Represents DN performance information.
 */

#ifndef _dn_perf_info_H_
#define _dn_perf_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "dn_perf.h"
#include "snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct dn_perf_info_s dn_perf_info_t;
typedef struct dn_perf_info_s {
	char *app_id;
	char *dnn;
	struct snssai_s *snssai;
	list_t *dn_perf;
	bool is_confidence;
	int confidence;
} dn_perf_info_t;

dn_perf_info_t *dn_perf_info_create(char *app_id, char *dnn, snssai_t *snssai,
                                    list_t *dn_perf, bool is_confidence,
                                    int confidence);
void dn_perf_info_free(dn_perf_info_t *dn_perf_info);
dn_perf_info_t *dn_perf_info_parseFromJSON(cJSON *dn_perf_infoJSON);
cJSON *dn_perf_info_convertToJSON(dn_perf_info_t *dn_perf_info);
dn_perf_info_t *dn_perf_info_copy(dn_perf_info_t *dst, dn_perf_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _dn_perf_info_H_ */
