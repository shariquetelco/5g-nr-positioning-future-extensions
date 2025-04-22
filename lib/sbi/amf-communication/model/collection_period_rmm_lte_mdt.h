/*
 * collection_period_rmm_lte_mdt.h
 *
 * The enumeration CollectionPeriodRmmLteMdt defines Collection period for RRM measurements LTE for MDT in the trace. See 3GPP TS 32.422 for further description of the values. It shall comply with the provisions defined in table 5.6.3.15-1.
 */

#ifndef _collection_period_rmm_lte_mdt_H_
#define _collection_period_rmm_lte_mdt_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "collection_period_rmm_lte_mdt_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct collection_period_rmm_lte_mdt_s collection_period_rmm_lte_mdt_t;
typedef struct collection_period_rmm_lte_mdt_s {}
collection_period_rmm_lte_mdt_t;

collection_period_rmm_lte_mdt_t *collection_period_rmm_lte_mdt_create();
void collection_period_rmm_lte_mdt_free(
	collection_period_rmm_lte_mdt_t *collection_period_rmm_lte_mdt);
collection_period_rmm_lte_mdt_t *collection_period_rmm_lte_mdt_parseFromJSON(
	cJSON *collection_period_rmm_lte_mdtJSON);
cJSON *collection_period_rmm_lte_mdt_convertToJSON(
	collection_period_rmm_lte_mdt_t *collection_period_rmm_lte_mdt);
collection_period_rmm_lte_mdt_t *collection_period_rmm_lte_mdt_copy(
	collection_period_rmm_lte_mdt_t *dst,
	collection_period_rmm_lte_mdt_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _collection_period_rmm_lte_mdt_H_ */
