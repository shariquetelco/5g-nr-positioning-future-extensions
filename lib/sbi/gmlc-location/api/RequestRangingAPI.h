#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/input_ranging_data.h"
#include "../model/problem_details.h"
#include "../model/ranging_datas.h"
#include "../model/redirect_response.h"


// Request Ranging information between UEs
//
ranging_datas_t *RequestRangingAPI_requestRanging(
	apiClient_t		*apiClient,
	input_ranging_data_t	*input_ranging_data);
