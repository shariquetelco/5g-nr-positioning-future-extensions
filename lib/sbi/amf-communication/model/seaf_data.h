/*
 * seaf_data.h
 *
 * Represents SEAF data derived from data received from AUSF
 */

#ifndef _seaf_data_H_
#define _seaf_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "key_amf.h"
#include "ng_ksi.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct seaf_data_s seaf_data_t;
typedef struct seaf_data_s {
	struct ng_ksi_s *ng_ksi;
	struct key_amf_s *key_amf;
	char *nh;
	bool is_ncc;
	int ncc;
	bool is_key_amf_change_ind;
	int key_amf_change_ind;
	bool is_key_amf_h_derivation_ind;
	int key_amf_h_derivation_ind;
} seaf_data_t;

seaf_data_t *seaf_data_create(ng_ksi_t *ng_ksi, key_amf_t *key_amf, char *nh,
                              bool is_ncc, int ncc, bool is_key_amf_change_ind,
                              int key_amf_change_ind,
                              bool is_key_amf_h_derivation_ind,
                              int key_amf_h_derivation_ind);
void seaf_data_free(seaf_data_t *seaf_data);
seaf_data_t *seaf_data_parseFromJSON(cJSON *seaf_dataJSON);
cJSON *seaf_data_convertToJSON(seaf_data_t *seaf_data);
seaf_data_t *seaf_data_copy(seaf_data_t *dst, seaf_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _seaf_data_H_ */
