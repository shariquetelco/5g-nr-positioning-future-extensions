# LocationContextTransferAPI

All URIs are relative to *https://example.com/nlmf-loc/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**LocationContextTransferAPI_locationContextTransfer**](LocationContextTransferAPI.md#LocationContextTransferAPI_locationContextTransfer) | **POST** /location-context-transfer | transfer context information for periodic or triggered location


# **LocationContextTransferAPI_locationContextTransfer**
```c
// transfer context information for periodic or triggered location
//
void LocationContextTransferAPI_locationContextTransfer(apiClient_t *apiClient, loc_context_data_t * loc_context_data);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**loc_context_data** | **[loc_context_data_t](loc_context_data.md) \*** |  | 

### Return type

void

### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

