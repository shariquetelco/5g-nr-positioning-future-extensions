#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/n2_information_transfer_error.h"
#include "../model/n2_information_transfer_req_data.h"
#include "../model/n2_information_transfer_rsp_data.h"
#include "../model/non_ue_n2_message_transfer_200_response.h"
#include "../model/non_ue_n2_message_transfer_request.h"
#include "../model/problem_details.h"
#include "../model/redirect_response.h"


// Namf_Communication Non UE N2 Message Transfer service Operation
//
n2_information_transfer_rsp_data_t *
NonUEN2MessagesCollectionCollectionAPI_nonUeN2MessageTransfer(
	apiClient_t				*apiClient,
	n2_information_transfer_req_data_t	*n2_information_transfer_req_data);
