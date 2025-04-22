# NonUEN2MessagesCollectionCollectionAPI

All URIs are relative to *https://example.com/namf-comm/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**NonUEN2MessagesCollectionCollectionAPI_nonUeN2MessageTransfer**](NonUEN2MessagesCollectionCollectionAPI.md#NonUEN2MessagesCollectionCollectionAPI_nonUeN2MessageTransfer) | **POST** /non-ue-n2-messages/transfer | Namf_Communication Non UE N2 Message Transfer service Operation


# **NonUEN2MessagesCollectionCollectionAPI_nonUeN2MessageTransfer**
```c
// Namf_Communication Non UE N2 Message Transfer service Operation
//
n2_information_transfer_rsp_data_t* NonUEN2MessagesCollectionCollectionAPI_nonUeN2MessageTransfer(apiClient_t *apiClient, n2_information_transfer_req_data_t * n2_information_transfer_req_data);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**n2_information_transfer_req_data** | **[n2_information_transfer_req_data_t](n2_information_transfer_req_data.md) \*** |  | 

### Return type

[n2_information_transfer_rsp_data_t](n2_information_transfer_rsp_data.md) *


### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: application/json, multipart/related
 - **Accept**: application/json, multipart/related, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

