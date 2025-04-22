#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/loc_update_subs.h"
#include "../model/problem_details.h"
#include "../model/redirect_response.h"


// subscribe to notifications of UE location information
//
void UELocationInformationSubscriptionCreationAPI_locationUpdateSubcribe(
	apiClient_t *apiClient, loc_update_subs_t *loc_update_subs);
