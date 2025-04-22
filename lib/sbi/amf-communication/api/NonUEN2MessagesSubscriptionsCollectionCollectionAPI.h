#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/non_ue_n2_info_subscription_create_data.h"
#include "../model/non_ue_n2_info_subscription_created_data.h"
#include "../model/problem_details.h"
#include "../model/redirect_response.h"


// Namf_Communication Non UE N2 Info Subscribe service Operation
//
non_ue_n2_info_subscription_created_data_t *
NonUEN2MessagesSubscriptionsCollectionCollectionAPI_nonUeN2InfoSubscribe(
	apiClient_t					*apiClient,
	non_ue_n2_info_subscription_create_data_t	*non_ue_n2_info_subscription_create_data);
