/*
 * dispersion_collection.h
 *
 * Dispersion collection per UE location or per slice.
 */

#ifndef _dispersion_collection_H_
#define _dispersion_collection_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "application_volume.h"
#include "dispersion_class.h"
#include "snssai.h"
#include "user_location.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct dispersion_collection_s dispersion_collection_t;
typedef struct dispersion_collection_s {
	struct user_location_s *ue_loc;
	struct snssai_s *snssai;
	list_t *supis;
	list_t *gpsis;
	list_t *app_volumes;
	bool is_disper_amount;
	int disper_amount;
	struct dispersion_class_s *disper_class;
	bool is_usage_rank;
	int usage_rank;
	bool is_percentile_rank;
	int percentile_rank;
	bool is_ue_ratio;
	int ue_ratio;
	bool is_confidence;
	int confidence;
} dispersion_collection_t;

dispersion_collection_t *dispersion_collection_create(user_location_t *ue_loc,
                                                      snssai_t *snssai,
                                                      list_t *supis,
                                                      list_t *gpsis,
                                                      list_t *app_volumes,
                                                      bool is_disper_amount,
                                                      int disper_amount,
                                                      dispersion_class_t *disper_class, bool is_usage_rank, int usage_rank, bool is_percentile_rank, int percentile_rank, bool is_ue_ratio, int ue_ratio, bool is_confidence, int confidence);
void dispersion_collection_free(dispersion_collection_t *dispersion_collection);
dispersion_collection_t *dispersion_collection_parseFromJSON(
	cJSON *dispersion_collectionJSON);
cJSON *dispersion_collection_convertToJSON(
	dispersion_collection_t *dispersion_collection);
dispersion_collection_t *dispersion_collection_copy(
	dispersion_collection_t *dst, dispersion_collection_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _dispersion_collection_H_ */
