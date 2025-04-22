# NonUEN2MessageNotificationIndividualSubscriptionDocumentAPI

All URIs are relative to *https://example.com/namf-comm/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**NonUEN2MessageNotificationIndividualSubscriptionDocumentAPI_nonUeN2InfoUnSubscribe**](NonUEN2MessageNotificationIndividualSubscriptionDocumentAPI.md#NonUEN2MessageNotificationIndividualSubscriptionDocumentAPI_nonUeN2InfoUnSubscribe) | **DELETE** /non-ue-n2-messages/subscriptions/{n2NotifySubscriptionId} | Namf_Communication Non UE N2 Info UnSubscribe service Operation


# **NonUEN2MessageNotificationIndividualSubscriptionDocumentAPI_nonUeN2InfoUnSubscribe**
```c
// Namf_Communication Non UE N2 Info UnSubscribe service Operation
//
void NonUEN2MessageNotificationIndividualSubscriptionDocumentAPI_nonUeN2InfoUnSubscribe(apiClient_t *apiClient, char * n2NotifySubscriptionId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**n2NotifySubscriptionId** | **char \*** | N2 info Subscription Identifier | 

### Return type

void

### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

