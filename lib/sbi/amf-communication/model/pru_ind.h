/*
 * pru_ind.h
 *
 * Indicates whether the UE can act as a PRU or the type of PRU.
 */

#ifndef _pru_ind_H_
#define _pru_ind_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "pru_ind_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct pru_ind_s pru_ind_t;
typedef struct pru_ind_s {} pru_ind_t;

pru_ind_t *pru_ind_create();
void pru_ind_free(pru_ind_t *pru_ind);
pru_ind_t *pru_ind_parseFromJSON(cJSON *pru_indJSON);
cJSON *pru_ind_convertToJSON(pru_ind_t *pru_ind);
pru_ind_t *pru_ind_copy(pru_ind_t *dst, pru_ind_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _pru_ind_H_ */
