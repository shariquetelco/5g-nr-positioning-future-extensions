#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/cipher_request_data.h"
#include "../model/cipher_response_data.h"
#include "../model/problem_details.h"
#include "../model/redirect_response.h"


// Request ciphering key data
//
cipher_response_data_t *RequestCipheringKeyDataAPI_cipheringKeyData(
	apiClient_t *apiClient, cipher_request_data_t *cipher_request_data);
