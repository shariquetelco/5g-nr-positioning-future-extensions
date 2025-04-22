/*
 * eps_iwk_pgw.h
 *
 * This datatype signifies the PGW FQDN, SMF instance ID and the PLMNId location.
 */

#ifndef _eps_iwk_pgw_H_
#define _eps_iwk_pgw_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "plmn_id.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct eps_iwk_pgw_s eps_iwk_pgw_t;
typedef struct eps_iwk_pgw_s {
	char *pgw_fqdn;
	char *smf_instance_id;
	struct plmn_id_s *plmn_id;
} eps_iwk_pgw_t;

eps_iwk_pgw_t *eps_iwk_pgw_create(char *pgw_fqdn, char *smf_instance_id,
                                  plmn_id_t *plmn_id);
void eps_iwk_pgw_free(eps_iwk_pgw_t *eps_iwk_pgw);
eps_iwk_pgw_t *eps_iwk_pgw_parseFromJSON(cJSON *eps_iwk_pgwJSON);
cJSON *eps_iwk_pgw_convertToJSON(eps_iwk_pgw_t *eps_iwk_pgw);
eps_iwk_pgw_t *eps_iwk_pgw_copy(eps_iwk_pgw_t *dst, eps_iwk_pgw_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _eps_iwk_pgw_H_ */
