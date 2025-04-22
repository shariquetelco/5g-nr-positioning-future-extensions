# RequestLocationAPI

All URIs are relative to *https://example.com/ngmlc-loc/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**RequestLocationAPI_requestLocation**](RequestLocationAPI.md#RequestLocationAPI_requestLocation) | **POST** /provide-location | Request Location of an UE


# **RequestLocationAPI_requestLocation**
```c
// Request Location of an UE
//
location_data_ext_t* RequestLocationAPI_requestLocation(apiClient_t *apiClient, input_data_t * input_data);
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

 - **Content-Type**: application/json
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

