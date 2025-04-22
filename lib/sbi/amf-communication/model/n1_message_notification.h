/*
 * n1_message_notification.h
 *
 * Data within a N1 message notification request
 */

#ifndef _n1_message_notification_H_
#define _n1_message_notification_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ecgi.h"
#include "guami.h"
#include "n1_message_container.h"
#include "ncgi.h"
#include "pru_ind.h"
#include "registration_context_container.h"
#include "tai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct n1_message_notification_s n1_message_notification_t;
typedef struct n1_message_notification_s {
	char *n1_notify_subscription_id;
	struct n1_message_container_s *n1_message_container;
	char *lcs_correlation_id;
	struct registration_context_container_s *registration_ctxt_container;
	char *new_lmf_identification;
	struct guami_s *guami;
	bool is_c_io_t5_gs_optimisation;
	int c_io_t5_gs_optimisation;
	struct ecgi_s *ecgi;
	struct ncgi_s *ncgi;
	struct tai_s *tai;
	char *supi;
	struct pru_ind_s *pru_ind;
} n1_message_notification_t;

n1_message_notification_t *n1_message_notification_create(
	char *n1_notify_subscription_id,
	n1_message_container_t *n1_message_container, char *lcs_correlation_id,
	registration_context_container_t *registration_ctxt_container,
	char *new_lmf_identification, guami_t *guami,
	bool is_c_io_t5_gs_optimisation, int c_io_t5_gs_optimisation,
	ecgi_t *ecgi, ncgi_t *ncgi, tai_t *tai, char *supi, pru_ind_t *pru_ind);
void n1_message_notification_free(
	n1_message_notification_t *n1_message_notification);
n1_message_notification_t *n1_message_notification_parseFromJSON(
	cJSON *n1_message_notificationJSON);
cJSON *n1_message_notification_convertToJSON(
	n1_message_notification_t *n1_message_notification);
n1_message_notification_t *n1_message_notification_copy(
	n1_message_notification_t *dst, n1_message_notification_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _n1_message_notification_H_ */
