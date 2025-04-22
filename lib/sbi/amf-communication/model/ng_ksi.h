/*
 * ng_ksi.h
 *
 * Represents the ngKSI
 */

#ifndef _ng_ksi_H_
#define _ng_ksi_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "sc_type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ng_ksi_s ng_ksi_t;
typedef struct ng_ksi_s {
	sc_type_e tsc;
	int ksi;
} ng_ksi_t;

ng_ksi_t *ng_ksi_create(sc_type_e tsc, int ksi);
void ng_ksi_free(ng_ksi_t *ng_ksi);
ng_ksi_t *ng_ksi_parseFromJSON(cJSON *ng_ksiJSON);
cJSON *ng_ksi_convertToJSON(ng_ksi_t *ng_ksi);
ng_ksi_t *ng_ksi_copy(ng_ksi_t *dst, ng_ksi_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ng_ksi_H_ */
