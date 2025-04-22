/*
 * n1_n2_message_transfer_cause.h
 *
 *
 */

#ifndef _n1_n2_message_transfer_cause_H_
#define _n1_n2_message_transfer_cause_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { n1_n2_message_transfer_cause_NULL = 0,
	       n1_n2_message_transfer_cause_ATTEMPTING_TO_REACH_UE,
	       n1_n2_message_transfer_cause_N1_N2_TRANSFER_INITIATED,
	       n1_n2_message_transfer_cause_WAITING_FOR_ASYNCHRONOUS_TRANSFER,
	       n1_n2_message_transfer_cause_UE_NOT_RESPONDING,
	       n1_n2_message_transfer_cause_N1_MSG_NOT_TRANSFERRED,
	       n1_n2_message_transfer_cause_N2_MSG_NOT_TRANSFERRED,
	       n1_n2_message_transfer_cause_UE_NOT_REACHABLE_FOR_SESSION,
	       n1_n2_message_transfer_cause_TEMPORARY_REJECT_REGISTRATION_ONGOING,
	       n1_n2_message_transfer_cause_TEMPORARY_REJECT_HANDOVER_ONGOING,
	       n1_n2_message_transfer_cause_REJECTION_DUE_TO_PAGING_RESTRICTION,
	       n1_n2_message_transfer_cause_AN_NOT_RESPONDING,
	       n1_n2_message_transfer_cause_FAILURE_CAUSE_UNSPECIFIED }
n1_n2_message_transfer_cause_e;

char *n1_n2_message_transfer_cause_ToString(
	n1_n2_message_transfer_cause_e n1_n2_message_transfer_cause);

n1_n2_message_transfer_cause_e n1_n2_message_transfer_cause_FromString(
	char *n1_n2_message_transfer_cause);

#ifdef __cplusplus
}
#endif

#endif /* _n1_n2_message_transfer_cause_H_ */
