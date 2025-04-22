/*
 * twap_id.h
 *
 * Contain the TWAP Identifier as defined in clause 4.2.8.5.3 of 3GPP TS 23.501 or the WLAN location information as defined in clause 4.5.7.2.8 of 3GPP TS 23.402.
 */

#ifndef _twap_id_H_
#define _twap_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct twap_id_s twap_id_t;
typedef struct twap_id_s {
	char *ss_id;
	char *bss_id;
	char *civic_address;
} twap_id_t;

twap_id_t *twap_id_create(char *ss_id, char *bss_id, char *civic_address);
void twap_id_free(twap_id_t *twap_id);
twap_id_t *twap_id_parseFromJSON(cJSON *twap_idJSON);
cJSON *twap_id_convertToJSON(twap_id_t *twap_id);
twap_id_t *twap_id_copy(twap_id_t *dst, twap_id_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _twap_id_H_ */
