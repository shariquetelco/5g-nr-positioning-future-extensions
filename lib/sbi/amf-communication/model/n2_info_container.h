/*
 * n2_info_container.h
 *
 * N2 information container
 */

#ifndef _n2_info_container_H_
#define _n2_info_container_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "a2x_information.h"
#include "n2_information_class.h"
#include "n2_ran_information.h"
#include "n2_sm_information.h"
#include "nrppa_information.h"
#include "pro_se_information.h"
#include "pws_information.h"
#include "rslp_information.h"
#include "tss_information.h"
#include "v2x_information.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct n2_info_container_s n2_info_container_t;
typedef struct n2_info_container_s {
	n2_information_class_e n2_information_class;
	struct n2_sm_information_s *sm_info;
	struct n2_ran_information_s *ran_info;
	struct nrppa_information_s *nrppa_info;
	struct pws_information_s *pws_info;
	struct v2x_information_s *v2x_info;
	struct pro_se_information_s *prose_info;
	struct tss_information_s *tss_info;
	struct rslp_information_s *rslp_info;
	struct a2x_information_s *a2x_info;
} n2_info_container_t;

n2_info_container_t *n2_info_container_create(
	n2_information_class_e n2_information_class,
	n2_sm_information_t *sm_info, n2_ran_information_t *ran_info,
	nrppa_information_t *nrppa_info, pws_information_t *pws_info,
	v2x_information_t *v2x_info, pro_se_information_t *prose_info,
	tss_information_t *tss_info, rslp_information_t *rslp_info,
	a2x_information_t *a2x_info);
void n2_info_container_free(n2_info_container_t *n2_info_container);
n2_info_container_t *n2_info_container_parseFromJSON(
	cJSON *n2_info_containerJSON);
cJSON *n2_info_container_convertToJSON(n2_info_container_t *n2_info_container);
n2_info_container_t *n2_info_container_copy(n2_info_container_t *dst,
                                            n2_info_container_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _n2_info_container_H_ */
