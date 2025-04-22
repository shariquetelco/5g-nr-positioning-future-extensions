#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/assign_ebi_data.h"
#include "../model/assign_ebi_error.h"
#include "../model/assigned_ebi_data.h"
#include "../model/create_ue_context_201_response.h"
#include "../model/create_ue_context_403_response.h"
#include "../model/problem_details.h"
#include "../model/redirect_response.h"
#include "../model/ue_context_cancel_relocate_data.h"
#include "../model/ue_context_create_data.h"
#include "../model/ue_context_create_error.h"
#include "../model/ue_context_created_data.h"
#include "../model/ue_context_release.h"
#include "../model/ue_context_relocate_data.h"
#include "../model/ue_context_relocated_data.h"
#include "../model/ue_context_transfer_200_response.h"
#include "../model/ue_context_transfer_req_data.h"
#include "../model/ue_context_transfer_request.h"
#include "../model/ue_context_transfer_rsp_data.h"
#include "../model/ue_reg_status_update_req_data.h"
#include "../model/ue_reg_status_update_rsp_data.h"


// Namf_Communication CancelRelocateUEContext service Operation
//
void IndividualUeContextDocumentAPI_cancelRelocateUEContext(
	apiClient_t *apiClient, char *ueContextId,
	ue_context_cancel_relocate_data_t *jsonData,
	binary_t *binaryDataGtpcMessage);


// Namf_Communication CreateUEContext service Operation
//
ue_context_created_data_t *IndividualUeContextDocumentAPI_createUEContext(
	apiClient_t *apiClient, char *ueContextId,
	ue_context_create_data_t *jsonData, binary_t *binaryDataN2Information,
	binary_t *binaryDataN2InformationExt1,
	binary_t *binaryDataN2InformationExt2,
	binary_t *binaryDataN2InformationExt3,
	binary_t *binaryDataN2InformationExt4,
	binary_t *binaryDataN2InformationExt5,
	binary_t *binaryDataN2InformationExt6,
	binary_t *binaryDataN2InformationExt7,
	binary_t *binaryDataN2InformationExt8,
	binary_t *binaryDataN2InformationExt9,
	binary_t *binaryDataN2InformationExt10,
	binary_t *binaryDataN2InformationExt11,
	binary_t *binaryDataN2InformationExt12,
	binary_t *binaryDataN2InformationExt13,
	binary_t *binaryDataN2InformationExt14,
	binary_t *binaryDataN2InformationExt15,
	binary_t *binaryDataN2InformationExt16,
	binary_t *binaryDataN2InformationExt17);


// Namf_Communication EBI Assignment service Operation
//
assigned_ebi_data_t *IndividualUeContextDocumentAPI_eBIAssignment(
	apiClient_t *apiClient, char *ueContextId,
	assign_ebi_data_t *assign_ebi_data);


// Namf_Communication RegistrationStatusUpdate service Operation
//
ue_reg_status_update_rsp_data_t *
IndividualUeContextDocumentAPI_registrationStatusUpdate(
	apiClient_t			*apiClient,
	char				*ueContextId,
	ue_reg_status_update_req_data_t *ue_reg_status_update_req_data);


// Namf_Communication ReleaseUEContext service Operation
//
void IndividualUeContextDocumentAPI_releaseUEContext(
	apiClient_t		*apiClient,
	char			*ueContextId,
	ue_context_release_t	*ue_context_release);


// Namf_Communication RelocateUEContext service Operation
//
ue_context_relocated_data_t *IndividualUeContextDocumentAPI_relocateUEContext(
	apiClient_t *apiClient, char *ueContextId,
	ue_context_relocate_data_t *jsonData,
	binary_t *binaryDataForwardRelocationRequest,
	binary_t *binaryDataN2Information,
	binary_t *binaryDataN2InformationExt1,
	binary_t *binaryDataN2InformationExt2,
	binary_t *binaryDataN2InformationExt3,
	binary_t *binaryDataN2InformationExt4,
	binary_t *binaryDataN2InformationExt5,
	binary_t *binaryDataN2InformationExt6,
	binary_t *binaryDataN2InformationExt7,
	binary_t *binaryDataN2InformationExt8,
	binary_t *binaryDataN2InformationExt9,
	binary_t *binaryDataN2InformationExt10,
	binary_t *binaryDataN2InformationExt11,
	binary_t *binaryDataN2InformationExt12,
	binary_t *binaryDataN2InformationExt13,
	binary_t *binaryDataN2InformationExt14,
	binary_t *binaryDataN2InformationExt15,
	binary_t *binaryDataN2InformationExt16);


// Namf_Communication UEContextTransfer service Operation
//
ue_context_transfer_rsp_data_t *IndividualUeContextDocumentAPI_uEContextTransfer(
	apiClient_t *apiClient, char *ueContextId,
	ue_context_transfer_req_data_t *ue_context_transfer_req_data);
