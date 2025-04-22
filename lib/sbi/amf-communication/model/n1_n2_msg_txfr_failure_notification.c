#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "n1_n2_msg_txfr_failure_notification.h"

n1_n2_msg_txfr_failure_notification_t *
n1_n2_msg_txfr_failure_notification_create(
	n1_n2_message_transfer_cause_e	cause,
	char				*n1n2_msg_data_uri,
	bool				is_retry_after,
	int				retry_after)
{
	n1_n2_msg_txfr_failure_notification_t *
	        n1_n2_msg_txfr_failure_notification_local_var =
		malloc(sizeof(n1_n2_msg_txfr_failure_notification_t));

	n1_n2_msg_txfr_failure_notification_local_var->cause = cause;
	n1_n2_msg_txfr_failure_notification_local_var->n1n2_msg_data_uri =
		n1n2_msg_data_uri;
	n1_n2_msg_txfr_failure_notification_local_var->is_retry_after =
		is_retry_after;
	n1_n2_msg_txfr_failure_notification_local_var->retry_after =
		retry_after;

	return n1_n2_msg_txfr_failure_notification_local_var;
}

void n1_n2_msg_txfr_failure_notification_free(
	n1_n2_msg_txfr_failure_notification_t *n1_n2_msg_txfr_failure_notification)
{
	lnode_t *node = NULL;

	if(NULL == n1_n2_msg_txfr_failure_notification) {
		return;
	}
	if(n1_n2_msg_txfr_failure_notification->n1n2_msg_data_uri) {
		free(n1_n2_msg_txfr_failure_notification->n1n2_msg_data_uri);
		n1_n2_msg_txfr_failure_notification->n1n2_msg_data_uri = NULL;
	}
	free(n1_n2_msg_txfr_failure_notification);
}

cJSON *n1_n2_msg_txfr_failure_notification_convertToJSON(
	n1_n2_msg_txfr_failure_notification_t *n1_n2_msg_txfr_failure_notification)
{
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(n1_n2_msg_txfr_failure_notification == NULL) {
		printf(
			"n1_n2_msg_txfr_failure_notification_convertToJSON() failed [N1N2MsgTxfrFailureNotification]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(n1_n2_msg_txfr_failure_notification->cause ==
	   n1_n2_message_transfer_cause_NULL)
	{
		printf(
			"n1_n2_msg_txfr_failure_notification_convertToJSON() failed [cause]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "cause",
	                           n1_n2_message_transfer_cause_ToString(
					   n1_n2_msg_txfr_failure_notification->
					   cause)) == NULL)
	{
		printf(
			"n1_n2_msg_txfr_failure_notification_convertToJSON() failed [cause]");
		goto end;
	}

	if(!n1_n2_msg_txfr_failure_notification->n1n2_msg_data_uri) {
		printf(
			"n1_n2_msg_txfr_failure_notification_convertToJSON() failed [n1n2_msg_data_uri]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "n1n2MsgDataUri",
	                           n1_n2_msg_txfr_failure_notification->
	                           n1n2_msg_data_uri) == NULL)
	{
		printf(
			"n1_n2_msg_txfr_failure_notification_convertToJSON() failed [n1n2_msg_data_uri]");
		goto end;
	}

	if(n1_n2_msg_txfr_failure_notification->is_retry_after) {
		if(cJSON_AddNumberToObject(item, "retryAfter",
		                           n1_n2_msg_txfr_failure_notification->
		                           retry_after) == NULL)
		{
			printf(
				"n1_n2_msg_txfr_failure_notification_convertToJSON() failed [retry_after]");
			goto end;
		}
	}

end:
	return item;
}

n1_n2_msg_txfr_failure_notification_t *
n1_n2_msg_txfr_failure_notification_parseFromJSON(
	cJSON *n1_n2_msg_txfr_failure_notificationJSON) {
	n1_n2_msg_txfr_failure_notification_t *
	        n1_n2_msg_txfr_failure_notification_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *cause = NULL;
	n1_n2_message_transfer_cause_e causeVariable = 0;
	cJSON *n1n2_msg_data_uri = NULL;
	cJSON *retry_after = NULL;
	cause = cJSON_GetObjectItemCaseSensitive(
		n1_n2_msg_txfr_failure_notificationJSON, "cause");
	if(!cause) {
		printf(
			"n1_n2_msg_txfr_failure_notification_parseFromJSON() failed [cause]");
		goto end;
	}
	if(!cJSON_IsString(cause)) {
		printf(
			"n1_n2_msg_txfr_failure_notification_parseFromJSON() failed [cause]");
		goto end;
	}
	causeVariable = n1_n2_message_transfer_cause_FromString(
		cause->valuestring);

	n1n2_msg_data_uri = cJSON_GetObjectItemCaseSensitive(
		n1_n2_msg_txfr_failure_notificationJSON, "n1n2MsgDataUri");
	if(!n1n2_msg_data_uri) {
		printf(
			"n1_n2_msg_txfr_failure_notification_parseFromJSON() failed [n1n2_msg_data_uri]");
		goto end;
	}
	if(!cJSON_IsString(n1n2_msg_data_uri)) {
		printf(
			"n1_n2_msg_txfr_failure_notification_parseFromJSON() failed [n1n2_msg_data_uri]");
		goto end;
	}

	retry_after = cJSON_GetObjectItemCaseSensitive(
		n1_n2_msg_txfr_failure_notificationJSON, "retryAfter");
	if(retry_after) {
		if(!cJSON_IsNumber(retry_after)) {
			printf(
				"n1_n2_msg_txfr_failure_notification_parseFromJSON() failed [retry_after]");
			goto end;
		}
	}

	n1_n2_msg_txfr_failure_notification_local_var =
		n1_n2_msg_txfr_failure_notification_create(
			causeVariable,
			strdup(n1n2_msg_data_uri->valuestring),
			retry_after ? true : false,
			retry_after ? retry_after->valuedouble : 0
			);

	return n1_n2_msg_txfr_failure_notification_local_var;
end:
	return NULL;
}

n1_n2_msg_txfr_failure_notification_t *n1_n2_msg_txfr_failure_notification_copy(
	n1_n2_msg_txfr_failure_notification_t	*dst,
	n1_n2_msg_txfr_failure_notification_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = n1_n2_msg_txfr_failure_notification_convertToJSON(src);
	if(!item) {
		printf(
			"n1_n2_msg_txfr_failure_notification_convertToJSON() failed");
		return NULL;
	}

	content = cJSON_Print(item);
	cJSON_Delete(item);

	if(!content) {
		printf("cJSON_Print() failed");
		return NULL;
	}

	item = cJSON_Parse(content);
	free(content);
	if(!item) {
		printf("cJSON_Parse() failed");
		return NULL;
	}

	n1_n2_msg_txfr_failure_notification_free(dst);
	dst = n1_n2_msg_txfr_failure_notification_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
