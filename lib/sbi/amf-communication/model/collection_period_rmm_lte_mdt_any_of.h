/*
 * collection_period_rmm_lte_mdt_any_of.h
 *
 *
 */

#ifndef _collection_period_rmm_lte_mdt_any_of_H_
#define _collection_period_rmm_lte_mdt_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { collection_period_rmm_lte_mdt_any_of_NULL = 0,
	       collection_period_rmm_lte_mdt_any_of__1024,
	       collection_period_rmm_lte_mdt_any_of__1280,
	       collection_period_rmm_lte_mdt_any_of__2048,
	       collection_period_rmm_lte_mdt_any_of__2560,
	       collection_period_rmm_lte_mdt_any_of__5120,
	       collection_period_rmm_lte_mdt_any_of__10240,
	       collection_period_rmm_lte_mdt_any_of__60000 }
collection_period_rmm_lte_mdt_any_of_e;

char *collection_period_rmm_lte_mdt_any_of_ToString(
	collection_period_rmm_lte_mdt_any_of_e collection_period_rmm_lte_mdt_any_of);

collection_period_rmm_lte_mdt_any_of_e
collection_period_rmm_lte_mdt_any_of_FromString(
	char *collection_period_rmm_lte_mdt_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _collection_period_rmm_lte_mdt_any_of_H_ */
