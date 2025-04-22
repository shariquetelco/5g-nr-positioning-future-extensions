/*
 * gnss_positioning_method_and_usage.h
 *
 * Indicates the usage of a Global Navigation Satellite System (GNSS) positioning method.
 */

#ifndef _gnss_positioning_method_and_usage_H_
#define _gnss_positioning_method_and_usage_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "gnss_id.h"
#include "positioning_mode.h"
#include "usage.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct gnss_positioning_method_and_usage_s
        gnss_positioning_method_and_usage_t;
typedef struct gnss_positioning_method_and_usage_s {
	positioning_mode_e mode;
	gnss_id_e gnss;
	usage_e usage;
} gnss_positioning_method_and_usage_t;

gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage_create(
	positioning_mode_e mode, gnss_id_e gnss, usage_e usage);
void gnss_positioning_method_and_usage_free(
	gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage);
gnss_positioning_method_and_usage_t *
gnss_positioning_method_and_usage_parseFromJSON(
	cJSON *gnss_positioning_method_and_usageJSON);
cJSON *gnss_positioning_method_and_usage_convertToJSON(
	gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage);
gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage_copy(
	gnss_positioning_method_and_usage_t	*dst,
	gnss_positioning_method_and_usage_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _gnss_positioning_method_and_usage_H_ */
