#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/problem_details.h"
#include "../model/redirect_response.h"
#include "../model/ue_n1_n2_info_subscription_create_data.h"
#include "../model/ue_n1_n2_info_subscription_created_data.h"


// Namf_Communication N1N2 Message Subscribe (UE Specific) service Operation
//
ue_n1_n2_info_subscription_created_data_t *
N1N2SubscriptionsCollectionForIndividualUEContextsCollectionAPI_n1N2MessageSubscribe(
	apiClient_t *apiClient, char *ueContextId,
	ue_n1_n2_info_subscription_create_data_t *ue_n1_n2_info_subscription_create_data);
