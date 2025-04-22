/*
 * comb_gci_and_hfc_n_ids.h
 *
 *
 */

#ifndef _comb_gci_and_hfc_n_ids_H_
#define _comb_gci_and_hfc_n_ids_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct comb_gci_and_hfc_n_ids_s comb_gci_and_hfc_n_ids_t;
typedef struct comb_gci_and_hfc_n_ids_s {
	char *global_cable_id;
	char *hfc_nid;
} comb_gci_and_hfc_n_ids_t;

comb_gci_and_hfc_n_ids_t *comb_gci_and_hfc_n_ids_create(
	char	*global_cable_id,
	char	*hfc_nid);
void comb_gci_and_hfc_n_ids_free(
	comb_gci_and_hfc_n_ids_t *comb_gci_and_hfc_n_ids);
comb_gci_and_hfc_n_ids_t *comb_gci_and_hfc_n_ids_parseFromJSON(
	cJSON *comb_gci_and_hfc_n_idsJSON);
cJSON *comb_gci_and_hfc_n_ids_convertToJSON(
	comb_gci_and_hfc_n_ids_t *comb_gci_and_hfc_n_ids);
comb_gci_and_hfc_n_ids_t *comb_gci_and_hfc_n_ids_copy(
	comb_gci_and_hfc_n_ids_t *dst, comb_gci_and_hfc_n_ids_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _comb_gci_and_hfc_n_ids_H_ */
