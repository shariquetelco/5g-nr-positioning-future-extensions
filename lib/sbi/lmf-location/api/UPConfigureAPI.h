#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/problem_details.h"
#include "../model/redirect_response.h"
#include "../model/up_config.h"


// set up, modify or terminate a secure LCS-UP connection for a target UE
//
void UPConfigureAPI_upConfig(apiClient_t *apiClient, up_config_t *up_config);
