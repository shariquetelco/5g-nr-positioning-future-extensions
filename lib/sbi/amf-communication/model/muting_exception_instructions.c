#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "muting_exception_instructions.h"

muting_exception_instructions_t *muting_exception_instructions_create(
	buffered_notifications_action_t *buffered_notifs,
	subscription_action_t		*subscription) {
	muting_exception_instructions_t *muting_exception_instructions_local_var
	        = malloc(sizeof(muting_exception_instructions_t));

	muting_exception_instructions_local_var->buffered_notifs =
		buffered_notifs;
	muting_exception_instructions_local_var->subscription = subscription;

	return muting_exception_instructions_local_var;
}

void muting_exception_instructions_free(
	muting_exception_instructions_t *muting_exception_instructions) {
	lnode_t *node = NULL;

	if(NULL == muting_exception_instructions) {
		return;
	}
	if(muting_exception_instructions->buffered_notifs) {
		buffered_notifications_action_free(
			muting_exception_instructions->buffered_notifs);
		muting_exception_instructions->buffered_notifs = NULL;
	}
	if(muting_exception_instructions->subscription) {
		subscription_action_free(
			muting_exception_instructions->subscription);
		muting_exception_instructions->subscription = NULL;
	}
	free(muting_exception_instructions);
}

cJSON *muting_exception_instructions_convertToJSON(
	muting_exception_instructions_t *muting_exception_instructions) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(muting_exception_instructions == NULL) {
		printf(
			"muting_exception_instructions_convertToJSON() failed [MutingExceptionInstructions]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(muting_exception_instructions->buffered_notifs) {
		cJSON *buffered_notifs_local_JSON =
			buffered_notifications_action_convertToJSON(
				muting_exception_instructions->buffered_notifs);
		if(buffered_notifs_local_JSON == NULL) {
			printf(
				"muting_exception_instructions_convertToJSON() failed [buffered_notifs]");
			goto end;
		}
		cJSON_AddItemToObject(item, "bufferedNotifs",
		                      buffered_notifs_local_JSON);
		if(item->child == NULL) {
			printf(
				"muting_exception_instructions_convertToJSON() failed [buffered_notifs]");
			goto end;
		}
	}

	if(muting_exception_instructions->subscription) {
		cJSON *subscription_local_JSON =
			subscription_action_convertToJSON(
				muting_exception_instructions->subscription);
		if(subscription_local_JSON == NULL) {
			printf(
				"muting_exception_instructions_convertToJSON() failed [subscription]");
			goto end;
		}
		cJSON_AddItemToObject(item, "subscription",
		                      subscription_local_JSON);
		if(item->child == NULL) {
			printf(
				"muting_exception_instructions_convertToJSON() failed [subscription]");
			goto end;
		}
	}

end:
	return item;
}

muting_exception_instructions_t *muting_exception_instructions_parseFromJSON(
	cJSON *muting_exception_instructionsJSON) {
	muting_exception_instructions_t *muting_exception_instructions_local_var
	        = NULL;
	lnode_t *node = NULL;
	cJSON *buffered_notifs = NULL;
	buffered_notifications_action_t *buffered_notifs_local_nonprim = NULL;
	cJSON *subscription = NULL;
	subscription_action_t *subscription_local_nonprim = NULL;
	buffered_notifs = cJSON_GetObjectItemCaseSensitive(
		muting_exception_instructionsJSON, "bufferedNotifs");
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
		muting_exception_instructionsJSON, "subscription");
	if(subscription) {
		subscription_local_nonprim = subscription_action_parseFromJSON(
			subscription);
		if(!subscription_local_nonprim) {
			printf(
				"subscription_action_parseFromJSON failed [subscription]");
			goto end;
		}
	}

	muting_exception_instructions_local_var =
		muting_exception_instructions_create(
			buffered_notifs ? buffered_notifs_local_nonprim : NULL,
			subscription ? subscription_local_nonprim : NULL
			);

	return muting_exception_instructions_local_var;
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

muting_exception_instructions_t *muting_exception_instructions_copy(
	muting_exception_instructions_t *dst,
	muting_exception_instructions_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = muting_exception_instructions_convertToJSON(src);
	if(!item) {
		printf("muting_exception_instructions_convertToJSON() failed");
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

	muting_exception_instructions_free(dst);
	dst = muting_exception_instructions_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
