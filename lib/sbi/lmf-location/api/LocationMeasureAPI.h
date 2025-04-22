#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/loc_measurement_req.h"
#include "../model/loc_measurement_resp.h"
#include "../model/problem_details.h"
#include "../model/redirect_response.h"


// PRU location measurement
//
loc_measurement_resp_t *LocationMeasureAPI_locationMeasure(
	apiClient_t *apiClient, loc_measurement_req_t *loc_measurement_req);
