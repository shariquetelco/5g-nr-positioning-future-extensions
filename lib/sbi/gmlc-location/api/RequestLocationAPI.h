#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/input_data.h"
#include "../model/location_data_ext.h"
#include "../model/problem_details.h"
#include "../model/redirect_response.h"


// Request Location of an UE
//
location_data_ext_t *RequestLocationAPI_requestLocation(
	apiClient_t	*apiClient,
	input_data_t	*input_data);
