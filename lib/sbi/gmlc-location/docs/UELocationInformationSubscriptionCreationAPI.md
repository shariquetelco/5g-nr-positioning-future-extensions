# UELocationInformationSubscriptionCreationAPI

All URIs are relative to *https://example.com/ngmlc-loc/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**UELocationInformationSubscriptionCreationAPI_locationUpdateSubcribe**](UELocationInformationSubscriptionCreationAPI.md#UELocationInformationSubscriptionCreationAPI_locationUpdateSubcribe) | **POST** /loc-update-subs | subscribe to notifications of UE location information


# **UELocationInformationSubscriptionCreationAPI_locationUpdateSubcribe**
```c
// subscribe to notifications of UE location information
//
void UELocationInformationSubscriptionCreationAPI_locationUpdateSubcribe(apiClient_t *apiClient, loc_update_subs_t * loc_update_subs);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**loc_update_subs** | **[loc_update_subs_t](loc_update_subs.md) \*** |  | 

### Return type

void

### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

