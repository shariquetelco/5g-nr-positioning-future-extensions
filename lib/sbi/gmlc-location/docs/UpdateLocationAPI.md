# UpdateLocationAPI

All URIs are relative to *https://example.com/ngmlc-loc/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**UpdateLocationAPI_updateLocation**](UpdateLocationAPI.md#UpdateLocationAPI_updateLocation) | **POST** /location-update | update UE location information


# **UpdateLocationAPI_updateLocation**
```c
// update UE location information
//
void UpdateLocationAPI_updateLocation(apiClient_t *apiClient, loc_update_data_t * loc_update_data);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**loc_update_data** | **[loc_update_data_t](loc_update_data.md) \*** |  | 

### Return type

void

### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

