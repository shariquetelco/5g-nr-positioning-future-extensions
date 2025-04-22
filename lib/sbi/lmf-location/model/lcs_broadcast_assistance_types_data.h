/*
 * lcs_broadcast_assistance_types_data.h
 *
 *
 */

#ifndef _lcs_broadcast_assistance_types_data_H_
#define _lcs_broadcast_assistance_types_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct lcs_broadcast_assistance_types_data_s
        lcs_broadcast_assistance_types_data_t;
typedef struct lcs_broadcast_assistance_types_data_s {
	binary_t *location_assistance_type;
} lcs_broadcast_assistance_types_data_t;

lcs_broadcast_assistance_types_data_t *
lcs_broadcast_assistance_types_data_create(binary_t *location_assistance_type);
void lcs_broadcast_assistance_types_data_free(
	lcs_broadcast_assistance_types_data_t *lcs_broadcast_assistance_types_data);
lcs_broadcast_assistance_types_data_t *
lcs_broadcast_assistance_types_data_parseFromJSON(
	cJSON *lcs_broadcast_assistance_types_dataJSON);
cJSON *lcs_broadcast_assistance_types_data_convertToJSON(
	lcs_broadcast_assistance_types_data_t *lcs_broadcast_assistance_types_data);
lcs_broadcast_assistance_types_data_t *lcs_broadcast_assistance_types_data_copy(
	lcs_broadcast_assistance_types_data_t	*dst,
	lcs_broadcast_assistance_types_data_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _lcs_broadcast_assistance_types_data_H_ */
