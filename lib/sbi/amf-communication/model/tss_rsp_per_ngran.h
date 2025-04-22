/*
 * tss_rsp_per_ngran.h
 *
 * Represents a TSS related N2 information data part
 */

#ifndef _tss_rsp_per_ngran_H_
#define _tss_rsp_per_ngran_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "global_ran_node_id.h"
#include "n2_info_content.h"
#include "ngran_failure_info.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct tss_rsp_per_ngran_s tss_rsp_per_ngran_t;
typedef struct tss_rsp_per_ngran_s {
	struct global_ran_node_id_s *ngran_id;
	ngran_failure_info_e ngran_failure_info;
	struct n2_info_content_s *tss_container;
} tss_rsp_per_ngran_t;

tss_rsp_per_ngran_t *tss_rsp_per_ngran_create(global_ran_node_id_t *ngran_id,
                                              ngran_failure_info_e ngran_failure_info, n2_info_content_t *tss_container);
void tss_rsp_per_ngran_free(tss_rsp_per_ngran_t *tss_rsp_per_ngran);
tss_rsp_per_ngran_t *tss_rsp_per_ngran_parseFromJSON(
	cJSON *tss_rsp_per_ngranJSON);
cJSON *tss_rsp_per_ngran_convertToJSON(tss_rsp_per_ngran_t *tss_rsp_per_ngran);
tss_rsp_per_ngran_t *tss_rsp_per_ngran_copy(tss_rsp_per_ngran_t *dst,
                                            tss_rsp_per_ngran_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _tss_rsp_per_ngran_H_ */
