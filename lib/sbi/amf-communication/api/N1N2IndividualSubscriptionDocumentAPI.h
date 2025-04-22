#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/problem_details.h"
#include "../model/redirect_response.h"


// Namf_Communication N1N2 Message UnSubscribe (UE Specific) service Operation
//
void N1N2IndividualSubscriptionDocumentAPI_n1N2MessageUnSubscribe(
	apiClient_t *apiClient, char *ueContextId, char *subscriptionId);
