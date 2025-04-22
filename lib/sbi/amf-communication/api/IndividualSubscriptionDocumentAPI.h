#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/problem_details.h"
#include "../model/redirect_response.h"
#include "../model/subscription_data.h"


// Namf_Communication AMF Status Change Subscribe Modify service Operation
//
subscription_data_t *
IndividualSubscriptionDocumentAPI_aMFStatusChangeSubscribeModfy(
	apiClient_t *apiClient, char *subscriptionId,
	subscription_data_t *subscription_data);


// Namf_Communication AMF Status Change UnSubscribe service Operation
//
void IndividualSubscriptionDocumentAPI_aMFStatusChangeUnSubscribe(
	apiClient_t *apiClient, char *subscriptionId);
