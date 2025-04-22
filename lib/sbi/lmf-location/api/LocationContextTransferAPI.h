#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/loc_context_data.h"
#include "../model/problem_details.h"
#include "../model/redirect_response.h"


// transfer context information for periodic or triggered location
//
void LocationContextTransferAPI_locationContextTransfer(
	apiClient_t		*apiClient,
	loc_context_data_t	*loc_context_data);
