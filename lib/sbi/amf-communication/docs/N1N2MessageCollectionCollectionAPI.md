# N1N2MessageCollectionCollectionAPI

All URIs are relative to *https://example.com/namf-comm/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**N1N2MessageCollectionCollectionAPI_n1N2MessageTransfer**](N1N2MessageCollectionCollectionAPI.md#N1N2MessageCollectionCollectionAPI_n1N2MessageTransfer) | **POST** /ue-contexts/{ueContextId}/n1-n2-messages | Namf_Communication N1N2 Message Transfer (UE Specific) service Operation


# **N1N2MessageCollectionCollectionAPI_n1N2MessageTransfer**
```c
// Namf_Communication N1N2 Message Transfer (UE Specific) service Operation
//
n1_n2_message_transfer_rsp_data_t* N1N2MessageCollectionCollectionAPI_n1N2MessageTransfer(apiClient_t *apiClient, char * ueContextId, n1_n2_message_transfer_req_data_t * n1_n2_message_transfer_req_data);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**ueContextId** | **char \*** | UE Context Identifier | 
**n1_n2_message_transfer_req_data** | **[n1_n2_message_transfer_req_data_t](n1_n2_message_transfer_req_data.md) \*** |  | 

### Return type

[n1_n2_message_transfer_rsp_data_t](n1_n2_message_transfer_rsp_data.md) *


### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: application/json, multipart/related
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

