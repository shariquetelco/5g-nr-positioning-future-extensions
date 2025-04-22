#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/problem_details.h"
#include "../model/redirect_response.h"


// Deletes a subscription
//
void UPUnsubscribeAPI_deleteSubscription(apiClient_t	*apiClient,
                                         char		*subscriptionId);
