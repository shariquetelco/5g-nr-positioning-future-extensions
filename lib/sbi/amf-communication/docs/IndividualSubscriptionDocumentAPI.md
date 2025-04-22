# IndividualSubscriptionDocumentAPI

All URIs are relative to *https://example.com/namf-comm/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**IndividualSubscriptionDocumentAPI_aMFStatusChangeSubscribeModfy**](IndividualSubscriptionDocumentAPI.md#IndividualSubscriptionDocumentAPI_aMFStatusChangeSubscribeModfy) | **PUT** /subscriptions/{subscriptionId} | Namf_Communication AMF Status Change Subscribe Modify service Operation
[**IndividualSubscriptionDocumentAPI_aMFStatusChangeUnSubscribe**](IndividualSubscriptionDocumentAPI.md#IndividualSubscriptionDocumentAPI_aMFStatusChangeUnSubscribe) | **DELETE** /subscriptions/{subscriptionId} | Namf_Communication AMF Status Change UnSubscribe service Operation


# **IndividualSubscriptionDocumentAPI_aMFStatusChangeSubscribeModfy**
```c
// Namf_Communication AMF Status Change Subscribe Modify service Operation
//
subscription_data_t* IndividualSubscriptionDocumentAPI_aMFStatusChangeSubscribeModfy(apiClient_t *apiClient, char * subscriptionId, subscription_data_t * subscription_data);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**subscriptionId** | **char \*** | AMF Status Change Subscription Identifier | 
**subscription_data** | **[subscription_data_t](subscription_data.md) \*** |  | 

### Return type

[subscription_data_t](subscription_data.md) *


### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **IndividualSubscriptionDocumentAPI_aMFStatusChangeUnSubscribe**
```c
// Namf_Communication AMF Status Change UnSubscribe service Operation
//
void IndividualSubscriptionDocumentAPI_aMFStatusChangeUnSubscribe(apiClient_t *apiClient, char * subscriptionId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**subscriptionId** | **char \*** | AMF Status Change Subscription Identifier | 

### Return type

void

### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

