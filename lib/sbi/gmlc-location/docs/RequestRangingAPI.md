# RequestRangingAPI

All URIs are relative to *https://example.com/ngmlc-loc/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**RequestRangingAPI_requestRanging**](RequestRangingAPI.md#RequestRangingAPI_requestRanging) | **POST** /provide-ranging | Request Ranging information between UEs


# **RequestRangingAPI_requestRanging**
```c
// Request Ranging information between UEs
//
ranging_datas_t* RequestRangingAPI_requestRanging(apiClient_t *apiClient, input_ranging_data_t * input_ranging_data);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**input_ranging_data** | **[input_ranging_data_t](input_ranging_data.md) \*** |  | 

### Return type

[ranging_datas_t](ranging_datas.md) *


### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

