# UPSubscribeAPI

All URIs are relative to *https://example.com/nlmf-loc/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**UPSubscribeAPI_upSubscriptions**](UPSubscribeAPI.md#UPSubscribeAPI_upSubscriptions) | **POST** /up-subscriptions | subscribe about status of a secure LCS-UP connection for a target UE


# **UPSubscribeAPI_upSubscriptions**
```c
// subscribe about status of a secure LCS-UP connection for a target UE
//
up_subscription_t* UPSubscribeAPI_upSubscriptions(apiClient_t *apiClient, up_subscription_t * up_subscription);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**up_subscription** | **[up_subscription_t](up_subscription.md) \*** |  | 

### Return type

[up_subscription_t](up_subscription.md) *


### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

