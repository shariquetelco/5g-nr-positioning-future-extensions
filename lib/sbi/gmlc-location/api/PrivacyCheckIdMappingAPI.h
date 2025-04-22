#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/privacy_check_id_mapping_req_data.h"
#include "../model/privacy_check_id_mapping_resp_data.h"
#include "../model/problem_details.h"
#include "../model/redirect_response.h"


// Privacy Check Id Mapping for Ranging SL Positioing Service
//
privacy_check_id_mapping_resp_data_t *
PrivacyCheckIdMappingAPI_privacyCheckIdMapping(
	apiClient_t				*apiClient,
	privacy_check_id_mapping_req_data_t	*privacy_check_id_mapping_req_data);
