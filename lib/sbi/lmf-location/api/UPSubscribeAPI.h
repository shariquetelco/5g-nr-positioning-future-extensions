#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/problem_details.h"
#include "../model/redirect_response.h"
#include "../model/up_subscription.h"


// subscribe about status of a secure LCS-UP connection for a target UE
//
up_subscription_t *UPSubscribeAPI_upSubscriptions(
	apiClient_t		*apiClient,
	up_subscription_t	*up_subscription);
