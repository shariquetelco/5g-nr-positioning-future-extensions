#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sess_inact_timer_for_ue_comm.h"

sess_inact_timer_for_ue_comm_t *sess_inact_timer_for_ue_comm_create(
	int n4_sess_id, int sess_inactive_timer) {
	sess_inact_timer_for_ue_comm_t *sess_inact_timer_for_ue_comm_local_var =
		malloc(sizeof(sess_inact_timer_for_ue_comm_t));

	sess_inact_timer_for_ue_comm_local_var->n4_sess_id = n4_sess_id;
	sess_inact_timer_for_ue_comm_local_var->sess_inactive_timer =
		sess_inactive_timer;

	return sess_inact_timer_for_ue_comm_local_var;
}

void sess_inact_timer_for_ue_comm_free(
	sess_inact_timer_for_ue_comm_t *sess_inact_timer_for_ue_comm) {
	lnode_t *node = NULL;

	if(NULL == sess_inact_timer_for_ue_comm) {
		return;
	}
	free(sess_inact_timer_for_ue_comm);
}

cJSON *sess_inact_timer_for_ue_comm_convertToJSON(
	sess_inact_timer_for_ue_comm_t *sess_inact_timer_for_ue_comm) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(sess_inact_timer_for_ue_comm == NULL) {
		printf(
			"sess_inact_timer_for_ue_comm_convertToJSON() failed [SessInactTimerForUeComm]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "n4SessId",
	                           sess_inact_timer_for_ue_comm->n4_sess_id) ==
	   NULL)
	{
		printf(
			"sess_inact_timer_for_ue_comm_convertToJSON() failed [n4_sess_id]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "sessInactiveTimer",
	                           sess_inact_timer_for_ue_comm->
	                           sess_inactive_timer) == NULL)
	{
		printf(
			"sess_inact_timer_for_ue_comm_convertToJSON() failed [sess_inactive_timer]");
		goto end;
	}

end:
	return item;
}

sess_inact_timer_for_ue_comm_t *sess_inact_timer_for_ue_comm_parseFromJSON(
	cJSON *sess_inact_timer_for_ue_commJSON) {
	sess_inact_timer_for_ue_comm_t *sess_inact_timer_for_ue_comm_local_var =
		NULL;
	lnode_t *node = NULL;
	cJSON *n4_sess_id = NULL;
	cJSON *sess_inactive_timer = NULL;
	n4_sess_id = cJSON_GetObjectItemCaseSensitive(
		sess_inact_timer_for_ue_commJSON, "n4SessId");
	if(!n4_sess_id) {
		printf(
			"sess_inact_timer_for_ue_comm_parseFromJSON() failed [n4_sess_id]");
		goto end;
	}
	if(!cJSON_IsNumber(n4_sess_id)) {
		printf(
			"sess_inact_timer_for_ue_comm_parseFromJSON() failed [n4_sess_id]");
		goto end;
	}

	sess_inactive_timer = cJSON_GetObjectItemCaseSensitive(
		sess_inact_timer_for_ue_commJSON, "sessInactiveTimer");
	if(!sess_inactive_timer) {
		printf(
			"sess_inact_timer_for_ue_comm_parseFromJSON() failed [sess_inactive_timer]");
		goto end;
	}
	if(!cJSON_IsNumber(sess_inactive_timer)) {
		printf(
			"sess_inact_timer_for_ue_comm_parseFromJSON() failed [sess_inactive_timer]");
		goto end;
	}

	sess_inact_timer_for_ue_comm_local_var =
		sess_inact_timer_for_ue_comm_create(

			n4_sess_id->valuedouble,

			sess_inactive_timer->valuedouble
			);

	return sess_inact_timer_for_ue_comm_local_var;
end:
	return NULL;
}

sess_inact_timer_for_ue_comm_t *sess_inact_timer_for_ue_comm_copy(
	sess_inact_timer_for_ue_comm_t	*dst,
	sess_inact_timer_for_ue_comm_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = sess_inact_timer_for_ue_comm_convertToJSON(src);
	if(!item) {
		printf("sess_inact_timer_for_ue_comm_convertToJSON() failed");
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

	sess_inact_timer_for_ue_comm_free(dst);
	dst = sess_inact_timer_for_ue_comm_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
