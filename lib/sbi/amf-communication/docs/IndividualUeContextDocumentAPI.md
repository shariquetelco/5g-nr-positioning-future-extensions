# IndividualUeContextDocumentAPI

All URIs are relative to *https://example.com/namf-comm/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**IndividualUeContextDocumentAPI_cancelRelocateUEContext**](IndividualUeContextDocumentAPI.md#IndividualUeContextDocumentAPI_cancelRelocateUEContext) | **POST** /ue-contexts/{ueContextId}/cancel-relocate | Namf_Communication CancelRelocateUEContext service Operation
[**IndividualUeContextDocumentAPI_createUEContext**](IndividualUeContextDocumentAPI.md#IndividualUeContextDocumentAPI_createUEContext) | **PUT** /ue-contexts/{ueContextId} | Namf_Communication CreateUEContext service Operation
[**IndividualUeContextDocumentAPI_eBIAssignment**](IndividualUeContextDocumentAPI.md#IndividualUeContextDocumentAPI_eBIAssignment) | **POST** /ue-contexts/{ueContextId}/assign-ebi | Namf_Communication EBI Assignment service Operation
[**IndividualUeContextDocumentAPI_registrationStatusUpdate**](IndividualUeContextDocumentAPI.md#IndividualUeContextDocumentAPI_registrationStatusUpdate) | **POST** /ue-contexts/{ueContextId}/transfer-update | Namf_Communication RegistrationStatusUpdate service Operation
[**IndividualUeContextDocumentAPI_releaseUEContext**](IndividualUeContextDocumentAPI.md#IndividualUeContextDocumentAPI_releaseUEContext) | **POST** /ue-contexts/{ueContextId}/release | Namf_Communication ReleaseUEContext service Operation
[**IndividualUeContextDocumentAPI_relocateUEContext**](IndividualUeContextDocumentAPI.md#IndividualUeContextDocumentAPI_relocateUEContext) | **POST** /ue-contexts/{ueContextId}/relocate | Namf_Communication RelocateUEContext service Operation
[**IndividualUeContextDocumentAPI_uEContextTransfer**](IndividualUeContextDocumentAPI.md#IndividualUeContextDocumentAPI_uEContextTransfer) | **POST** /ue-contexts/{ueContextId}/transfer | Namf_Communication UEContextTransfer service Operation


# **IndividualUeContextDocumentAPI_cancelRelocateUEContext**
```c
// Namf_Communication CancelRelocateUEContext service Operation
//
void IndividualUeContextDocumentAPI_cancelRelocateUEContext(apiClient_t *apiClient, char * ueContextId, ue_context_cancel_relocate_data_t * jsonData, binary_t* binaryDataGtpcMessage);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**ueContextId** | **char \*** | UE Context Identifier | 
**jsonData** | **[ue_context_cancel_relocate_data_t](ue_context_cancel_relocate_data.md) \*** |  | [optional] 
**binaryDataGtpcMessage** | **binary_t*** |  | [optional] 

### Return type

void

### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: multipart/related
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **IndividualUeContextDocumentAPI_createUEContext**
```c
// Namf_Communication CreateUEContext service Operation
//
ue_context_created_data_t* IndividualUeContextDocumentAPI_createUEContext(apiClient_t *apiClient, char * ueContextId, ue_context_create_data_t * jsonData, binary_t* binaryDataN2Information, binary_t* binaryDataN2InformationExt1, binary_t* binaryDataN2InformationExt2, binary_t* binaryDataN2InformationExt3, binary_t* binaryDataN2InformationExt4, binary_t* binaryDataN2InformationExt5, binary_t* binaryDataN2InformationExt6, binary_t* binaryDataN2InformationExt7, binary_t* binaryDataN2InformationExt8, binary_t* binaryDataN2InformationExt9, binary_t* binaryDataN2InformationExt10, binary_t* binaryDataN2InformationExt11, binary_t* binaryDataN2InformationExt12, binary_t* binaryDataN2InformationExt13, binary_t* binaryDataN2InformationExt14, binary_t* binaryDataN2InformationExt15, binary_t* binaryDataN2InformationExt16, binary_t* binaryDataN2InformationExt17);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**ueContextId** | **char \*** | UE Context Identifier | 
**jsonData** | **[ue_context_create_data_t](ue_context_create_data.md) \*** |  | [optional] 
**binaryDataN2Information** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt1** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt2** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt3** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt4** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt5** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt6** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt7** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt8** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt9** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt10** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt11** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt12** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt13** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt14** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt15** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt16** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt17** | **binary_t*** |  | [optional] 

### Return type

[ue_context_created_data_t](ue_context_created_data.md) *


### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: multipart/related
 - **Accept**: application/json, multipart/related, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **IndividualUeContextDocumentAPI_eBIAssignment**
```c
// Namf_Communication EBI Assignment service Operation
//
assigned_ebi_data_t* IndividualUeContextDocumentAPI_eBIAssignment(apiClient_t *apiClient, char * ueContextId, assign_ebi_data_t * assign_ebi_data);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**ueContextId** | **char \*** | UE Context Identifier | 
**assign_ebi_data** | **[assign_ebi_data_t](assign_ebi_data.md) \*** |  | 

### Return type

[assigned_ebi_data_t](assigned_ebi_data.md) *


### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **IndividualUeContextDocumentAPI_registrationStatusUpdate**
```c
// Namf_Communication RegistrationStatusUpdate service Operation
//
ue_reg_status_update_rsp_data_t* IndividualUeContextDocumentAPI_registrationStatusUpdate(apiClient_t *apiClient, char * ueContextId, ue_reg_status_update_req_data_t * ue_reg_status_update_req_data);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**ueContextId** | **char \*** | UE Context Identifier | 
**ue_reg_status_update_req_data** | **[ue_reg_status_update_req_data_t](ue_reg_status_update_req_data.md) \*** |  | 

### Return type

[ue_reg_status_update_rsp_data_t](ue_reg_status_update_rsp_data.md) *


### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **IndividualUeContextDocumentAPI_releaseUEContext**
```c
// Namf_Communication ReleaseUEContext service Operation
//
void IndividualUeContextDocumentAPI_releaseUEContext(apiClient_t *apiClient, char * ueContextId, ue_context_release_t * ue_context_release);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**ueContextId** | **char \*** | UE Context Identifier | 
**ue_context_release** | **[ue_context_release_t](ue_context_release.md) \*** |  | 

### Return type

void

### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **IndividualUeContextDocumentAPI_relocateUEContext**
```c
// Namf_Communication RelocateUEContext service Operation
//
ue_context_relocated_data_t* IndividualUeContextDocumentAPI_relocateUEContext(apiClient_t *apiClient, char * ueContextId, ue_context_relocate_data_t * jsonData, binary_t* binaryDataForwardRelocationRequest, binary_t* binaryDataN2Information, binary_t* binaryDataN2InformationExt1, binary_t* binaryDataN2InformationExt2, binary_t* binaryDataN2InformationExt3, binary_t* binaryDataN2InformationExt4, binary_t* binaryDataN2InformationExt5, binary_t* binaryDataN2InformationExt6, binary_t* binaryDataN2InformationExt7, binary_t* binaryDataN2InformationExt8, binary_t* binaryDataN2InformationExt9, binary_t* binaryDataN2InformationExt10, binary_t* binaryDataN2InformationExt11, binary_t* binaryDataN2InformationExt12, binary_t* binaryDataN2InformationExt13, binary_t* binaryDataN2InformationExt14, binary_t* binaryDataN2InformationExt15, binary_t* binaryDataN2InformationExt16);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**ueContextId** | **char \*** | UE Context Identifier | 
**jsonData** | **[ue_context_relocate_data_t](ue_context_relocate_data.md) \*** |  | [optional] 
**binaryDataForwardRelocationRequest** | **binary_t*** |  | [optional] 
**binaryDataN2Information** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt1** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt2** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt3** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt4** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt5** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt6** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt7** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt8** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt9** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt10** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt11** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt12** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt13** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt14** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt15** | **binary_t*** |  | [optional] 
**binaryDataN2InformationExt16** | **binary_t*** |  | [optional] 

### Return type

[ue_context_relocated_data_t](ue_context_relocated_data.md) *


### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: multipart/related
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **IndividualUeContextDocumentAPI_uEContextTransfer**
```c
// Namf_Communication UEContextTransfer service Operation
//
ue_context_transfer_rsp_data_t* IndividualUeContextDocumentAPI_uEContextTransfer(apiClient_t *apiClient, char * ueContextId, ue_context_transfer_req_data_t * ue_context_transfer_req_data);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**ueContextId** | **char \*** | UE Context Identifier | 
**ue_context_transfer_req_data** | **[ue_context_transfer_req_data_t](ue_context_transfer_req_data.md) \*** |  | 

### Return type

[ue_context_transfer_rsp_data_t](ue_context_transfer_rsp_data.md) *


### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: application/json, multipart/related
 - **Accept**: application/json, multipart/related, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

