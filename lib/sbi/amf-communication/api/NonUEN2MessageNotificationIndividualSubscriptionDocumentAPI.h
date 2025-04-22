#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/problem_details.h"
#include "../model/redirect_response.h"


// Namf_Communication Non UE N2 Info UnSubscribe service Operation
//
void
NonUEN2MessageNotificationIndividualSubscriptionDocumentAPI_nonUeN2InfoUnSubscribe(
	apiClient_t	*apiClient,
	char		*n2NotifySubscriptionId);
