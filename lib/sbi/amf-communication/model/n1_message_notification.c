#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "n1_message_notification.h"

n1_message_notification_t *n1_message_notification_create(
	char *n1_notify_subscription_id,
	n1_message_container_t *n1_message_container, char *lcs_correlation_id,
	registration_context_container_t *registration_ctxt_container,
	char *new_lmf_identification, guami_t *guami,
	bool is_c_io_t5_gs_optimisation, int c_io_t5_gs_optimisation,
	ecgi_t *ecgi, ncgi_t *ncgi, tai_t *tai, char *supi,
	pru_ind_t *pru_ind) {
	n1_message_notification_t *n1_message_notification_local_var = malloc(
		sizeof(n1_message_notification_t));

	n1_message_notification_local_var->n1_notify_subscription_id =
		n1_notify_subscription_id;
	n1_message_notification_local_var->n1_message_container =
		n1_message_container;
	n1_message_notification_local_var->lcs_correlation_id =
		lcs_correlation_id;
	n1_message_notification_local_var->registration_ctxt_container =
		registration_ctxt_container;
	n1_message_notification_local_var->new_lmf_identification =
		new_lmf_identification;
	n1_message_notification_local_var->guami = guami;
	n1_message_notification_local_var->is_c_io_t5_gs_optimisation =
		is_c_io_t5_gs_optimisation;
	n1_message_notification_local_var->c_io_t5_gs_optimisation =
		c_io_t5_gs_optimisation;
	n1_message_notification_local_var->ecgi = ecgi;
	n1_message_notification_local_var->ncgi = ncgi;
	n1_message_notification_local_var->tai = tai;
	n1_message_notification_local_var->supi = supi;
	n1_message_notification_local_var->pru_ind = pru_ind;

	return n1_message_notification_local_var;
}

void n1_message_notification_free(
	n1_message_notification_t *n1_message_notification) {
	lnode_t *node = NULL;

	if(NULL == n1_message_notification) {
		return;
	}
	if(n1_message_notification->n1_notify_subscription_id) {
		free(n1_message_notification->n1_notify_subscription_id);
		n1_message_notification->n1_notify_subscription_id = NULL;
	}
	if(n1_message_notification->n1_message_container) {
		n1_message_container_free(
			n1_message_notification->n1_message_container);
		n1_message_notification->n1_message_container = NULL;
	}
	if(n1_message_notification->lcs_correlation_id) {
		free(n1_message_notification->lcs_correlation_id);
		n1_message_notification->lcs_correlation_id = NULL;
	}
	if(n1_message_notification->registration_ctxt_container) {
		registration_context_container_free(
			n1_message_notification->registration_ctxt_container);
		n1_message_notification->registration_ctxt_container = NULL;
	}
	if(n1_message_notification->new_lmf_identification) {
		free(n1_message_notification->new_lmf_identification);
		n1_message_notification->new_lmf_identification = NULL;
	}
	if(n1_message_notification->guami) {
		guami_free(n1_message_notification->guami);
		n1_message_notification->guami = NULL;
	}
	if(n1_message_notification->ecgi) {
		ecgi_free(n1_message_notification->ecgi);
		n1_message_notification->ecgi = NULL;
	}
	if(n1_message_notification->ncgi) {
		ncgi_free(n1_message_notification->ncgi);
		n1_message_notification->ncgi = NULL;
	}
	if(n1_message_notification->tai) {
		tai_free(n1_message_notification->tai);
		n1_message_notification->tai = NULL;
	}
	if(n1_message_notification->supi) {
		free(n1_message_notification->supi);
		n1_message_notification->supi = NULL;
	}
	if(n1_message_notification->pru_ind) {
		pru_ind_free(n1_message_notification->pru_ind);
		n1_message_notification->pru_ind = NULL;
	}
	free(n1_message_notification);
}

cJSON *n1_message_notification_convertToJSON(
	n1_message_notification_t *n1_message_notification) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(n1_message_notification == NULL) {
		printf(
			"n1_message_notification_convertToJSON() failed [N1MessageNotification]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(n1_message_notification->n1_notify_subscription_id) {
		if(cJSON_AddStringToObject(item, "n1NotifySubscriptionId",
		                           n1_message_notification->
		                           n1_notify_subscription_id) == NULL)
		{
			printf(
				"n1_message_notification_convertToJSON() failed [n1_notify_subscription_id]");
			goto end;
		}
	}

	if(!n1_message_notification->n1_message_container) {
		printf(
			"n1_message_notification_convertToJSON() failed [n1_message_container]");
		return NULL;
	}
	cJSON *n1_message_container_local_JSON =
		n1_message_container_convertToJSON(
			n1_message_notification->n1_message_container);
	if(n1_message_container_local_JSON == NULL) {
		printf(
			"n1_message_notification_convertToJSON() failed [n1_message_container]");
		goto end;
	}
	cJSON_AddItemToObject(item, "n1MessageContainer",
	                      n1_message_container_local_JSON);
	if(item->child == NULL) {
		printf(
			"n1_message_notification_convertToJSON() failed [n1_message_container]");
		goto end;
	}

	if(n1_message_notification->lcs_correlation_id) {
		if(cJSON_AddStringToObject(item, "lcsCorrelationId",
		                           n1_message_notification->
		                           lcs_correlation_id) == NULL)
		{
			printf(
				"n1_message_notification_convertToJSON() failed [lcs_correlation_id]");
			goto end;
		}
	}

	if(n1_message_notification->registration_ctxt_container) {
		cJSON *registration_ctxt_container_local_JSON =
			registration_context_container_convertToJSON(
				n1_message_notification->registration_ctxt_container);
		if(registration_ctxt_container_local_JSON == NULL) {
			printf(
				"n1_message_notification_convertToJSON() failed [registration_ctxt_container]");
			goto end;
		}
		cJSON_AddItemToObject(item, "registrationCtxtContainer",
		                      registration_ctxt_container_local_JSON);
		if(item->child == NULL) {
			printf(
				"n1_message_notification_convertToJSON() failed [registration_ctxt_container]");
			goto end;
		}
	}

	if(n1_message_notification->new_lmf_identification) {
		if(cJSON_AddStringToObject(item, "newLmfIdentification",
		                           n1_message_notification->
		                           new_lmf_identification) == NULL)
		{
			printf(
				"n1_message_notification_convertToJSON() failed [new_lmf_identification]");
			goto end;
		}
	}

	if(n1_message_notification->guami) {
		cJSON *guami_local_JSON = guami_convertToJSON(
			n1_message_notification->guami);
		if(guami_local_JSON == NULL) {
			printf(
				"n1_message_notification_convertToJSON() failed [guami]");
			goto end;
		}
		cJSON_AddItemToObject(item, "guami", guami_local_JSON);
		if(item->child == NULL) {
			printf(
				"n1_message_notification_convertToJSON() failed [guami]");
			goto end;
		}
	}

	if(n1_message_notification->is_c_io_t5_gs_optimisation) {
		if(cJSON_AddBoolToObject(item, "cIoT5GSOptimisation",
		                         n1_message_notification->
		                         c_io_t5_gs_optimisation) == NULL)
		{
			printf(
				"n1_message_notification_convertToJSON() failed [c_io_t5_gs_optimisation]");
			goto end;
		}
	}

	if(n1_message_notification->ecgi) {
		cJSON *ecgi_local_JSON = ecgi_convertToJSON(
			n1_message_notification->ecgi);
		if(ecgi_local_JSON == NULL) {
			printf(
				"n1_message_notification_convertToJSON() failed [ecgi]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ecgi", ecgi_local_JSON);
		if(item->child == NULL) {
			printf(
				"n1_message_notification_convertToJSON() failed [ecgi]");
			goto end;
		}
	}

	if(n1_message_notification->ncgi) {
		cJSON *ncgi_local_JSON = ncgi_convertToJSON(
			n1_message_notification->ncgi);
		if(ncgi_local_JSON == NULL) {
			printf(
				"n1_message_notification_convertToJSON() failed [ncgi]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ncgi", ncgi_local_JSON);
		if(item->child == NULL) {
			printf(
				"n1_message_notification_convertToJSON() failed [ncgi]");
			goto end;
		}
	}

	if(n1_message_notification->tai) {
		cJSON *tai_local_JSON = tai_convertToJSON(
			n1_message_notification->tai);
		if(tai_local_JSON == NULL) {
			printf(
				"n1_message_notification_convertToJSON() failed [tai]");
			goto end;
		}
		cJSON_AddItemToObject(item, "tai", tai_local_JSON);
		if(item->child == NULL) {
			printf(
				"n1_message_notification_convertToJSON() failed [tai]");
			goto end;
		}
	}

	if(n1_message_notification->supi) {
		if(cJSON_AddStringToObject(item, "supi",
		                           n1_message_notification->supi) ==
		   NULL)
		{
			printf(
				"n1_message_notification_convertToJSON() failed [supi]");
			goto end;
		}
	}

	if(n1_message_notification->pru_ind) {
		cJSON *pru_ind_local_JSON = pru_ind_convertToJSON(
			n1_message_notification->pru_ind);
		if(pru_ind_local_JSON == NULL) {
			printf(
				"n1_message_notification_convertToJSON() failed [pru_ind]");
			goto end;
		}
		cJSON_AddItemToObject(item, "pruInd", pru_ind_local_JSON);
		if(item->child == NULL) {
			printf(
				"n1_message_notification_convertToJSON() failed [pru_ind]");
			goto end;
		}
	}

end:
	return item;
}

n1_message_notification_t *n1_message_notification_parseFromJSON(
	cJSON *n1_message_notificationJSON) {
	n1_message_notification_t *n1_message_notification_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *n1_notify_subscription_id = NULL;
	cJSON *n1_message_container = NULL;
	n1_message_container_t *n1_message_container_local_nonprim = NULL;
	cJSON *lcs_correlation_id = NULL;
	cJSON *registration_ctxt_container = NULL;
	registration_context_container_t *
	        registration_ctxt_container_local_nonprim = NULL;
	cJSON *new_lmf_identification = NULL;
	cJSON *guami = NULL;
	guami_t *guami_local_nonprim = NULL;
	cJSON *c_io_t5_gs_optimisation = NULL;
	cJSON *ecgi = NULL;
	ecgi_t *ecgi_local_nonprim = NULL;
	cJSON *ncgi = NULL;
	ncgi_t *ncgi_local_nonprim = NULL;
	cJSON *tai = NULL;
	tai_t *tai_local_nonprim = NULL;
	cJSON *supi = NULL;
	cJSON *pru_ind = NULL;
	pru_ind_t *pru_ind_local_nonprim = NULL;
	n1_notify_subscription_id = cJSON_GetObjectItemCaseSensitive(
		n1_message_notificationJSON, "n1NotifySubscriptionId");
	if(n1_notify_subscription_id) {
		if(!cJSON_IsString(n1_notify_subscription_id) &&
		   !cJSON_IsNull(n1_notify_subscription_id))
		{
			printf(
				"n1_message_notification_parseFromJSON() failed [n1_notify_subscription_id]");
			goto end;
		}
	}

	n1_message_container = cJSON_GetObjectItemCaseSensitive(
		n1_message_notificationJSON, "n1MessageContainer");
	if(!n1_message_container) {
		printf(
			"n1_message_notification_parseFromJSON() failed [n1_message_container]");
		goto end;
	}
	n1_message_container_local_nonprim = n1_message_container_parseFromJSON(
		n1_message_container);
	if(!n1_message_container_local_nonprim) {
		printf(
			"n1_message_container_parseFromJSON failed [n1_message_container]");
		goto end;
	}

	lcs_correlation_id = cJSON_GetObjectItemCaseSensitive(
		n1_message_notificationJSON, "lcsCorrelationId");
	if(lcs_correlation_id) {
		if(!cJSON_IsString(lcs_correlation_id) &&
		   !cJSON_IsNull(lcs_correlation_id))
		{
			printf(
				"n1_message_notification_parseFromJSON() failed [lcs_correlation_id]");
			goto end;
		}
	}

	registration_ctxt_container = cJSON_GetObjectItemCaseSensitive(
		n1_message_notificationJSON, "registrationCtxtContainer");
	if(registration_ctxt_container) {
		registration_ctxt_container_local_nonprim =
			registration_context_container_parseFromJSON(
				registration_ctxt_container);
		if(!registration_ctxt_container_local_nonprim) {
			printf(
				"registration_context_container_parseFromJSON failed [registration_ctxt_container]");
			goto end;
		}
	}

	new_lmf_identification = cJSON_GetObjectItemCaseSensitive(
		n1_message_notificationJSON, "newLmfIdentification");
	if(new_lmf_identification) {
		if(!cJSON_IsString(new_lmf_identification) &&
		   !cJSON_IsNull(new_lmf_identification))
		{
			printf(
				"n1_message_notification_parseFromJSON() failed [new_lmf_identification]");
			goto end;
		}
	}

	guami = cJSON_GetObjectItemCaseSensitive(n1_message_notificationJSON,
	                                         "guami");
	if(guami) {
		guami_local_nonprim = guami_parseFromJSON(guami);
		if(!guami_local_nonprim) {
			printf("guami_parseFromJSON failed [guami]");
			goto end;
		}
	}

	c_io_t5_gs_optimisation = cJSON_GetObjectItemCaseSensitive(
		n1_message_notificationJSON, "cIoT5GSOptimisation");
	if(c_io_t5_gs_optimisation) {
		if(!cJSON_IsBool(c_io_t5_gs_optimisation)) {
			printf(
				"n1_message_notification_parseFromJSON() failed [c_io_t5_gs_optimisation]");
			goto end;
		}
	}

	ecgi = cJSON_GetObjectItemCaseSensitive(n1_message_notificationJSON,
	                                        "ecgi");
	if(ecgi) {
		ecgi_local_nonprim = ecgi_parseFromJSON(ecgi);
		if(!ecgi_local_nonprim) {
			printf("ecgi_parseFromJSON failed [ecgi]");
			goto end;
		}
	}

	ncgi = cJSON_GetObjectItemCaseSensitive(n1_message_notificationJSON,
	                                        "ncgi");
	if(ncgi) {
		ncgi_local_nonprim = ncgi_parseFromJSON(ncgi);
		if(!ncgi_local_nonprim) {
			printf("ncgi_parseFromJSON failed [ncgi]");
			goto end;
		}
	}

	tai = cJSON_GetObjectItemCaseSensitive(n1_message_notificationJSON,
	                                       "tai");
	if(tai) {
		tai_local_nonprim = tai_parseFromJSON(tai);
		if(!tai_local_nonprim) {
			printf("tai_parseFromJSON failed [tai]");
			goto end;
		}
	}

	supi = cJSON_GetObjectItemCaseSensitive(n1_message_notificationJSON,
	                                        "supi");
	if(supi) {
		if(!cJSON_IsString(supi) &&
		   !cJSON_IsNull(supi))
		{
			printf(
				"n1_message_notification_parseFromJSON() failed [supi]");
			goto end;
		}
	}

	pru_ind = cJSON_GetObjectItemCaseSensitive(n1_message_notificationJSON,
	                                           "pruInd");
	if(pru_ind) {
		pru_ind_local_nonprim = pru_ind_parseFromJSON(pru_ind);
		if(!pru_ind_local_nonprim) {
			printf("pru_ind_parseFromJSON failed [pru_ind]");
			goto end;
		}
	}

	n1_message_notification_local_var = n1_message_notification_create(
		n1_notify_subscription_id &&
		!cJSON_IsNull(n1_notify_subscription_id) ? strdup(
			n1_notify_subscription_id->valuestring) : NULL,
		n1_message_container_local_nonprim,
		lcs_correlation_id &&
		!cJSON_IsNull(lcs_correlation_id) ? strdup(lcs_correlation_id->
		                                           valuestring) : NULL,
		registration_ctxt_container ? registration_ctxt_container_local_nonprim : NULL,
		new_lmf_identification &&
		!cJSON_IsNull(new_lmf_identification) ? strdup(
			new_lmf_identification->valuestring) : NULL,
		guami ? guami_local_nonprim : NULL,
		c_io_t5_gs_optimisation ? true : false,
		c_io_t5_gs_optimisation ? c_io_t5_gs_optimisation->valueint : 0,
		ecgi ? ecgi_local_nonprim : NULL,
		ncgi ? ncgi_local_nonprim : NULL,
		tai ? tai_local_nonprim : NULL,
		supi &&
		!cJSON_IsNull(supi) ? strdup(supi->valuestring) : NULL,
		pru_ind ? pru_ind_local_nonprim : NULL
		);

	return n1_message_notification_local_var;
end:
	if(n1_message_container_local_nonprim) {
		n1_message_container_free(n1_message_container_local_nonprim);
		n1_message_container_local_nonprim = NULL;
	}
	if(registration_ctxt_container_local_nonprim) {
		registration_context_container_free(
			registration_ctxt_container_local_nonprim);
		registration_ctxt_container_local_nonprim = NULL;
	}
	if(guami_local_nonprim) {
		guami_free(guami_local_nonprim);
		guami_local_nonprim = NULL;
	}
	if(ecgi_local_nonprim) {
		ecgi_free(ecgi_local_nonprim);
		ecgi_local_nonprim = NULL;
	}
	if(ncgi_local_nonprim) {
		ncgi_free(ncgi_local_nonprim);
		ncgi_local_nonprim = NULL;
	}
	if(tai_local_nonprim) {
		tai_free(tai_local_nonprim);
		tai_local_nonprim = NULL;
	}
	if(pru_ind_local_nonprim) {
		pru_ind_free(pru_ind_local_nonprim);
		pru_ind_local_nonprim = NULL;
	}
	return NULL;
}

n1_message_notification_t *n1_message_notification_copy(
	n1_message_notification_t *dst, n1_message_notification_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = n1_message_notification_convertToJSON(src);
	if(!item) {
		printf("n1_message_notification_convertToJSON() failed");
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

	n1_message_notification_free(dst);
	dst = n1_message_notification_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
