/*
 * nf_type.h
 *
 * NF types known to NRF
 */

#ifndef _nf_type_H_
#define _nf_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "nf_type_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct nf_type_s nf_type_t;
typedef struct nf_type_s {} nf_type_t;

nf_type_t *nf_type_create();
void nf_type_free(nf_type_t *nf_type);
nf_type_t *nf_type_parseFromJSON(cJSON *nf_typeJSON);
cJSON *nf_type_convertToJSON(nf_type_t *nf_type);
nf_type_t *nf_type_copy(nf_type_t *dst, nf_type_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _nf_type_H_ */
