/*
 * upf_information.h
 *
 * Represents the ID/address/FQDN of the UPF.
 */

#ifndef _upf_information_H_
#define _upf_information_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "addr_fqdn.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct upf_information_s upf_information_t;
typedef struct upf_information_s {
	char *upf_id;
	struct addr_fqdn_s *upf_addr;
} upf_information_t;

upf_information_t *upf_information_create(char *upf_id, addr_fqdn_t *upf_addr);
void upf_information_free(upf_information_t *upf_information);
upf_information_t *upf_information_parseFromJSON(cJSON *upf_informationJSON);
cJSON *upf_information_convertToJSON(upf_information_t *upf_information);
upf_information_t *upf_information_copy(upf_information_t	*dst,
                                        upf_information_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _upf_information_H_ */
