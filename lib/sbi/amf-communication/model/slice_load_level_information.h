/*
 * slice_load_level_information.h
 *
 * Contains load level information applicable for one or several slices.
 */

#ifndef _slice_load_level_information_H_
#define _slice_load_level_information_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct slice_load_level_information_s slice_load_level_information_t;
typedef struct slice_load_level_information_s {
	int load_level_information;
	list_t *snssais;
} slice_load_level_information_t;

slice_load_level_information_t *slice_load_level_information_create(
	int load_level_information, list_t *snssais);
void slice_load_level_information_free(
	slice_load_level_information_t *slice_load_level_information);
slice_load_level_information_t *slice_load_level_information_parseFromJSON(
	cJSON *slice_load_level_informationJSON);
cJSON *slice_load_level_information_convertToJSON(
	slice_load_level_information_t *slice_load_level_information);
slice_load_level_information_t *slice_load_level_information_copy(
	slice_load_level_information_t	*dst,
	slice_load_level_information_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _slice_load_level_information_H_ */
