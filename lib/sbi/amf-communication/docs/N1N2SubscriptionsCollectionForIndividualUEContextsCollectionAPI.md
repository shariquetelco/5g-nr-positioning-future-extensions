# N1N2SubscriptionsCollectionForIndividualUEContextsCollectionAPI

All URIs are relative to *https://example.com/namf-comm/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**N1N2SubscriptionsCollectionForIndividualUEContextsCollectionAPI_n1N2MessageSubscribe**](N1N2SubscriptionsCollectionForIndividualUEContextsCollectionAPI.md#N1N2SubscriptionsCollectionForIndividualUEContextsCollectionAPI_n1N2MessageSubscribe) | **POST** /ue-contexts/{ueContextId}/n1-n2-messages/subscriptions | Namf_Communication N1N2 Message Subscribe (UE Specific) service Operation


# **N1N2SubscriptionsCollectionForIndividualUEContextsCollectionAPI_n1N2MessageSubscribe**
```c
// Namf_Communication N1N2 Message Subscribe (UE Specific) service Operation
//
ue_n1_n2_info_subscription_created_data_t* N1N2SubscriptionsCollectionForIndividualUEContextsCollectionAPI_n1N2MessageSubscribe(apiClient_t *apiClient, char * ueContextId, ue_n1_n2_info_subscription_create_data_t * ue_n1_n2_info_subscription_create_data);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**ueContextId** | **char \*** | UE Context Identifier | 
**ue_n1_n2_info_subscription_create_data** | **[ue_n1_n2_info_subscription_create_data_t](ue_n1_n2_info_subscription_create_data.md) \*** |  | 

### Return type

[ue_n1_n2_info_subscription_created_data_t](ue_n1_n2_info_subscription_created_data.md) *


### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

