/*
 * tss_information.h
 *
 * Represents a Tss related N2 information data part
 */

#ifndef _tss_information_H_
#define _tss_information_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "n2_info_content.h"
#include "tss_rsp_per_ngran.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct tss_information_s tss_information_t;
typedef struct tss_information_s {
	char *nf_id;
	list_t *tss_container;
	list_t *tss_rsp_per_ngran_list;
} tss_information_t;

tss_information_t *tss_information_create(char *nf_id, list_t *tss_container,
                                          list_t *tss_rsp_per_ngran_list);
void tss_information_free(tss_information_t *tss_information);
tss_information_t *tss_information_parseFromJSON(cJSON *tss_informationJSON);
cJSON *tss_information_convertToJSON(tss_information_t *tss_information);
tss_information_t *tss_information_copy(tss_information_t	*dst,
                                        tss_information_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _tss_information_H_ */
