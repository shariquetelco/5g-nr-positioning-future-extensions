#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/n1_n2_message_transfer_error.h"
#include "../model/n1_n2_message_transfer_req_data.h"
#include "../model/n1_n2_message_transfer_rsp_data.h"
#include "../model/problem_details.h"
#include "../model/redirect_response.h"


// Namf_Communication N1N2 Message Transfer (UE Specific) service Operation
//
n1_n2_message_transfer_rsp_data_t *
N1N2MessageCollectionCollectionAPI_n1N2MessageTransfer(
	apiClient_t				*apiClient,
	char					*ueContextId,
	n1_n2_message_transfer_req_data_t	*n1_n2_message_transfer_req_data);
