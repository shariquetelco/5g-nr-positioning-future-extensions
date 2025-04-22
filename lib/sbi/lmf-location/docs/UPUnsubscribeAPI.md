# UPUnsubscribeAPI

All URIs are relative to *https://example.com/nlmf-loc/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**UPUnsubscribeAPI_deleteSubscription**](UPUnsubscribeAPI.md#UPUnsubscribeAPI_deleteSubscription) | **DELETE** /up-subscriptions/{subscriptionId} | Deletes a subscription


# **UPUnsubscribeAPI_deleteSubscription**
```c
// Deletes a subscription
//
void UPUnsubscribeAPI_deleteSubscription(apiClient_t *apiClient, char * subscriptionId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**subscriptionId** | **char \*** | Unique subscription Id | 

### Return type

void

### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

