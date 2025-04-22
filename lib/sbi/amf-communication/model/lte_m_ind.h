/*
 * lte_m_ind.h
 *
 * LTE-M Indication.
 */

#ifndef _lte_m_ind_H_
#define _lte_m_ind_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct lte_m_ind_s lte_m_ind_t;
typedef struct lte_m_ind_s {
	int lte_cat_m_ind;
} lte_m_ind_t;

lte_m_ind_t *lte_m_ind_create(int lte_cat_m_ind);
void lte_m_ind_free(lte_m_ind_t *lte_m_ind);
lte_m_ind_t *lte_m_ind_parseFromJSON(cJSON *lte_m_indJSON);
cJSON *lte_m_ind_convertToJSON(lte_m_ind_t *lte_m_ind);
lte_m_ind_t *lte_m_ind_copy(lte_m_ind_t *dst, lte_m_ind_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _lte_m_ind_H_ */
