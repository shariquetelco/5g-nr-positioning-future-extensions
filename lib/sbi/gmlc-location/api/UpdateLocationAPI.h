#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/loc_update_data.h"
#include "../model/problem_details.h"
#include "../model/redirect_response.h"


// update UE location information
//
void UpdateLocationAPI_updateLocation(apiClient_t	*apiClient,
                                      loc_update_data_t *loc_update_data);
