/*
 * ue_area_indication.h
 *
 * Indicates area (country, area in a country or international area) where UE is located
 */

#ifndef _ue_area_indication_H_
#define _ue_area_indication_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_area_indication_s ue_area_indication_t;
typedef struct ue_area_indication_s {
	char *country;
	bool is_international_area_ind;
	int international_area_ind;
} ue_area_indication_t;

ue_area_indication_t *ue_area_indication_create(char	*country,
                                                bool	is_international_area_ind,
                                                int	international_area_ind);
void ue_area_indication_free(ue_area_indication_t *ue_area_indication);
ue_area_indication_t *ue_area_indication_parseFromJSON(
	cJSON *ue_area_indicationJSON);
cJSON *ue_area_indication_convertToJSON(
	ue_area_indication_t *ue_area_indication);
ue_area_indication_t *ue_area_indication_copy(ue_area_indication_t	*dst,
                                              ue_area_indication_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_area_indication_H_ */
