#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/cancel_loc_data.h"
#include "../model/problem_details.h"
#include "../model/redirect_response.h"


// request cancellation of periodic or triggered location
//
void CancelLocationAPI_cancelLocation(apiClient_t	*apiClient,
                                      cancel_loc_data_t *cancel_loc_data);
