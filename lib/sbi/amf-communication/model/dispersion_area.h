/*
 * dispersion_area.h
 *
 * Dispersion Area
 */

#ifndef _dispersion_area_H_
#define _dispersion_area_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ecgi.h"
#include "ncgi.h"
#include "tai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct dispersion_area_s dispersion_area_t;
typedef struct dispersion_area_s {
	list_t *tai_list;
	list_t *ncgi_list;
	list_t *ecgi_list;
	bool is_n3ga_ind;
	int n3ga_ind;
} dispersion_area_t;

dispersion_area_t *dispersion_area_create(list_t *tai_list, list_t *ncgi_list,
                                          list_t *ecgi_list, bool is_n3ga_ind,
                                          int n3ga_ind);
void dispersion_area_free(dispersion_area_t *dispersion_area);
dispersion_area_t *dispersion_area_parseFromJSON(cJSON *dispersion_areaJSON);
cJSON *dispersion_area_convertToJSON(dispersion_area_t *dispersion_area);
dispersion_area_t *dispersion_area_copy(dispersion_area_t	*dst,
                                        dispersion_area_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _dispersion_area_H_ */
