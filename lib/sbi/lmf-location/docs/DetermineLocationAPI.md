# DetermineLocationAPI

All URIs are relative to *https://example.com/nlmf-loc/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**DetermineLocationAPI_determineLocation**](DetermineLocationAPI.md#DetermineLocationAPI_determineLocation) | **POST** /determine-location | Determine Location of an UE


# **DetermineLocationAPI_determineLocation**
```c
// Determine Location of an UE
//
location_data_ext_t* DetermineLocationAPI_determineLocation(apiClient_t *apiClient, input_data_t * input_data);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**input_data** | **[input_data_t](input_data.md) \*** |  | 

### Return type

[location_data_ext_t](location_data_ext.md) *


### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: application/json, multipart/related
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

