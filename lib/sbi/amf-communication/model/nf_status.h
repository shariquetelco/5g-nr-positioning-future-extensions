/*
 * nf_status.h
 *
 * Contains the percentage of time spent on various NF states.
 */

#ifndef _nf_status_H_
#define _nf_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct nf_status_s nf_status_t;
typedef struct nf_status_s {
	bool is_status_registered;
	int status_registered;
	bool is_status_unregistered;
	int status_unregistered;
	bool is_status_undiscoverable;
	int status_undiscoverable;
} nf_status_t;

nf_status_t *nf_status_create(bool is_status_registered, int status_registered,
                              bool is_status_unregistered,
                              int status_unregistered,
                              bool is_status_undiscoverable,
                              int status_undiscoverable);
void nf_status_free(nf_status_t *nf_status);
nf_status_t *nf_status_parseFromJSON(cJSON *nf_statusJSON);
cJSON *nf_status_convertToJSON(nf_status_t *nf_status);
nf_status_t *nf_status_copy(nf_status_t *dst, nf_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _nf_status_H_ */
