# CancelLocationAPI

All URIs are relative to *https://example.com/nlmf-loc/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**CancelLocationAPI_cancelLocation**](CancelLocationAPI.md#CancelLocationAPI_cancelLocation) | **POST** /cancel-location | request cancellation of periodic or triggered location


# **CancelLocationAPI_cancelLocation**
```c
// request cancellation of periodic or triggered location
//
void CancelLocationAPI_cancelLocation(apiClient_t *apiClient, cancel_loc_data_t * cancel_loc_data);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**cancel_loc_data** | **[cancel_loc_data_t](cancel_loc_data.md) \*** |  | 

### Return type

void

### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

