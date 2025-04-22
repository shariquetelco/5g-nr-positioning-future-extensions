# N1N2IndividualSubscriptionDocumentAPI

All URIs are relative to *https://example.com/namf-comm/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**N1N2IndividualSubscriptionDocumentAPI_n1N2MessageUnSubscribe**](N1N2IndividualSubscriptionDocumentAPI.md#N1N2IndividualSubscriptionDocumentAPI_n1N2MessageUnSubscribe) | **DELETE** /ue-contexts/{ueContextId}/n1-n2-messages/subscriptions/{subscriptionId} | Namf_Communication N1N2 Message UnSubscribe (UE Specific) service Operation


# **N1N2IndividualSubscriptionDocumentAPI_n1N2MessageUnSubscribe**
```c
// Namf_Communication N1N2 Message UnSubscribe (UE Specific) service Operation
//
void N1N2IndividualSubscriptionDocumentAPI_n1N2MessageUnSubscribe(apiClient_t *apiClient, char * ueContextId, char * subscriptionId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**ueContextId** | **char \*** | UE Context Identifier | 
**subscriptionId** | **char \*** | Subscription Identifier | 

### Return type

void

### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

