/*
 * nf_load_level_information.h
 *
 * Represents load level information of a given NF instance.
 */

#ifndef _nf_load_level_information_H_
#define _nf_load_level_information_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "nf_status.h"
#include "nf_type.h"
#include "snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct nf_load_level_information_s nf_load_level_information_t;
typedef struct nf_load_level_information_s {
	struct nf_type_s *nf_type;
	char *nf_instance_id;
	char *nf_set_id;
	struct nf_status_s *nf_status;
	bool is_nf_cpu_usage;
	int nf_cpu_usage;
	bool is_nf_memory_usage;
	int nf_memory_usage;
	bool is_nf_storage_usage;
	int nf_storage_usage;
	bool is_nf_load_level_average;
	int nf_load_level_average;
	bool is_nf_load_levelpeak;
	int nf_load_levelpeak;
	bool is_nf_load_avg_in_aoi;
	int nf_load_avg_in_aoi;
	struct snssai_s *snssai;
	bool is_confidence;
	int confidence;
} nf_load_level_information_t;

nf_load_level_information_t *nf_load_level_information_create(
	nf_type_t *nf_type, char *nf_instance_id, char *nf_set_id,
	nf_status_t *nf_status, bool is_nf_cpu_usage, int nf_cpu_usage,
	bool is_nf_memory_usage, int nf_memory_usage, bool is_nf_storage_usage,
	int nf_storage_usage, bool is_nf_load_level_average,
	int nf_load_level_average, bool is_nf_load_levelpeak,
	int nf_load_levelpeak, bool is_nf_load_avg_in_aoi,
	int nf_load_avg_in_aoi, snssai_t *snssai, bool is_confidence,
	int confidence);
void nf_load_level_information_free(
	nf_load_level_information_t *nf_load_level_information);
nf_load_level_information_t *nf_load_level_information_parseFromJSON(
	cJSON *nf_load_level_informationJSON);
cJSON *nf_load_level_information_convertToJSON(
	nf_load_level_information_t *nf_load_level_information);
nf_load_level_information_t *nf_load_level_information_copy(
	nf_load_level_information_t *dst, nf_load_level_information_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _nf_load_level_information_H_ */
