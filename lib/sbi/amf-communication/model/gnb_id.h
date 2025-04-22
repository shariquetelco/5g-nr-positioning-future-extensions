/*
 * gnb_id.h
 *
 * Provides the G-NB identifier.
 */

#ifndef _gnb_id_H_
#define _gnb_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct gnb_id_s gnb_id_t;
typedef struct gnb_id_s {
	int bit_length;
	char *g_nb_value;
} gnb_id_t;

gnb_id_t *gnb_id_create(int bit_length, char *g_nb_value);
void gnb_id_free(gnb_id_t *gnb_id);
gnb_id_t *gnb_id_parseFromJSON(cJSON *gnb_idJSON);
cJSON *gnb_id_convertToJSON(gnb_id_t *gnb_id);
gnb_id_t *gnb_id_copy(gnb_id_t *dst, gnb_id_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _gnb_id_H_ */
