# NonUEN2MessagesSubscriptionsCollectionCollectionAPI

All URIs are relative to *https://example.com/namf-comm/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**NonUEN2MessagesSubscriptionsCollectionCollectionAPI_nonUeN2InfoSubscribe**](NonUEN2MessagesSubscriptionsCollectionCollectionAPI.md#NonUEN2MessagesSubscriptionsCollectionCollectionAPI_nonUeN2InfoSubscribe) | **POST** /non-ue-n2-messages/subscriptions | Namf_Communication Non UE N2 Info Subscribe service Operation


# **NonUEN2MessagesSubscriptionsCollectionCollectionAPI_nonUeN2InfoSubscribe**
```c
// Namf_Communication Non UE N2 Info Subscribe service Operation
//
non_ue_n2_info_subscription_created_data_t* NonUEN2MessagesSubscriptionsCollectionCollectionAPI_nonUeN2InfoSubscribe(apiClient_t *apiClient, non_ue_n2_info_subscription_create_data_t * non_ue_n2_info_subscription_create_data);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**non_ue_n2_info_subscription_create_data** | **[non_ue_n2_info_subscription_create_data_t](non_ue_n2_info_subscription_create_data.md) \*** |  | 

### Return type

[non_ue_n2_info_subscription_created_data_t](non_ue_n2_info_subscription_created_data.md) *


### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

