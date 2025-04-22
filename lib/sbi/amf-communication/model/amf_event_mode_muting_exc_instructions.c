#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "amf_event_mode_muting_exc_instructions.h"

amf_event_mode_muting_exc_instructions_t *
amf_event_mode_muting_exc_instructions_create(
	buffered_notifications_action_t *buffered_notifs,
	subscription_action_t		*subscription) {
	amf_event_mode_muting_exc_instructions_t *
	        amf_event_mode_muting_exc_instructions_local_var =
		malloc(sizeof(amf_event_mode_muting_exc_instructions_t));

	amf_event_mode_muting_exc_instructions_local_var->buffered_notifs =
		buffered_notifs;
	amf_event_mode_muting_exc_instructions_local_var->subscription =
		subscription;

	return amf_event_mode_muting_exc_instructions_local_var;
}

void amf_event_mode_muting_exc_instructions_free(
	amf_event_mode_muting_exc_instructions_t *amf_event_mode_muting_exc_instructions)
{
	lnode_t *node = NULL;

	if(NULL == amf_event_mode_muting_exc_instructions) {
		return;
	}
	if(amf_event_mode_muting_exc_instructions->buffered_notifs) {
		buffered_notifications_action_free(
			amf_event_mode_muting_exc_instructions->buffered_notifs);
		amf_event_mode_muting_exc_instructions->buffered_notifs = NULL;
	}
	if(amf_event_mode_muting_exc_instructions->subscription) {
		subscription_action_free(
			amf_event_mode_muting_exc_instructions->subscription);
		amf_event_mode_muting_exc_instructions->subscription = NULL;
	}
	free(amf_event_mode_muting_exc_instructions);
}

cJSON *amf_event_mode_muting_exc_instructions_convertToJSON(
	amf_event_mode_muting_exc_instructions_t *amf_event_mode_muting_exc_instructions)
{
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(amf_event_mode_muting_exc_instructions == NULL) {
		printf(
			"amf_event_mode_muting_exc_instructions_convertToJSON() failed [AmfEventMode_mutingExcInstructions]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(amf_event_mode_muting_exc_instructions->buffered_notifs) {
		cJSON *buffered_notifs_local_JSON =
			buffered_notifications_action_convertToJSON(
				amf_event_mode_muting_exc_instructions->buffered_notifs);
		if(buffered_notifs_local_JSON == NULL) {
			printf(
				"amf_event_mode_muting_exc_instructions_convertToJSON() failed [buffered_notifs]");
			goto end;
		}
		cJSON_AddItemToObject(item, "bufferedNotifs",
		                      buffered_notifs_local_JSON);
		if(item->child == NULL) {
			printf(
				"amf_event_mode_muting_exc_instructions_convertToJSON() failed [buffered_notifs]");
			goto end;
		}
	}

	if(amf_event_mode_muting_exc_instructions->subscription) {
		cJSON *subscription_local_JSON =
			subscription_action_convertToJSON(
				amf_event_mode_muting_exc_instructions->subscription);
		if(subscription_local_JSON == NULL) {
			printf(
				"amf_event_mode_muting_exc_instructions_convertToJSON() failed [subscription]");
			goto end;
		}
		cJSON_AddItemToObject(item, "subscription",
		                      subscription_local_JSON);
		if(item->child == NULL) {
			printf(
				"amf_event_mode_muting_exc_instructions_convertToJSON() failed [subscription]");
			goto end;
		}
	}

end:
	return item;
}

amf_event_mode_muting_exc_instructions_t *
amf_event_mode_muting_exc_instructions_parseFromJSON(
	cJSON *amf_event_mode_muting_exc_instructionsJSON) {
	amf_event_mode_muting_exc_instructions_t *
	        amf_event_mode_muting_exc_instructions_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *buffered_notifs = NULL;
	buffered_notifications_action_t *buffered_notifs_local_nonprim = NULL;
	cJSON *subscription = NULL;
	subscription_action_t *subscription_local_nonprim = NULL;
	buffered_notifs = cJSON_GetObjectItemCaseSensitive(
		amf_event_mode_muting_exc_instructionsJSON, "bufferedNotifs");
	if(buffered_notifs) {
		buffered_notifs_local_nonprim =
			buffered_notifications_action_parseFromJSON(
				buffered_notifs);
		if(!buffered_notifs_local_nonprim) {
			printf(
				"buffered_notifications_action_parseFromJSON failed [buffered_notifs]");
			goto end;
		}
	}

	subscription = cJSON_GetObjectItemCaseSensitive(
		amf_event_mode_muting_exc_instructionsJSON, "subscription");
	if(subscription) {
		subscription_local_nonprim = subscription_action_parseFromJSON(
			subscription);
		if(!subscription_local_nonprim) {
			printf(
				"subscription_action_parseFromJSON failed [subscription]");
			goto end;
		}
	}

	amf_event_mode_muting_exc_instructions_local_var =
		amf_event_mode_muting_exc_instructions_create(
			buffered_notifs ? buffered_notifs_local_nonprim : NULL,
			subscription ? subscription_local_nonprim : NULL
			);

	return amf_event_mode_muting_exc_instructions_local_var;
end:
	if(buffered_notifs_local_nonprim) {
		buffered_notifications_action_free(buffered_notifs_local_nonprim);
		buffered_notifs_local_nonprim = NULL;
	}
	if(subscription_local_nonprim) {
		subscription_action_free(subscription_local_nonprim);
		subscription_local_nonprim = NULL;
	}
	return NULL;
}

amf_event_mode_muting_exc_instructions_t *
amf_event_mode_muting_exc_instructions_copy(
	amf_event_mode_muting_exc_instructions_t	*dst,
	amf_event_mode_muting_exc_instructions_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = amf_event_mode_muting_exc_instructions_convertToJSON(src);
	if(!item) {
		printf(
			"amf_event_mode_muting_exc_instructions_convertToJSON() failed");
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

	amf_event_mode_muting_exc_instructions_free(dst);
	dst = amf_event_mode_muting_exc_instructions_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
