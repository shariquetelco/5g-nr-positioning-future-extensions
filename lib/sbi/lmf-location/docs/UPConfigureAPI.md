# UPConfigureAPI

All URIs are relative to *https://example.com/nlmf-loc/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**UPConfigureAPI_upConfig**](UPConfigureAPI.md#UPConfigureAPI_upConfig) | **POST** /configure-up | set up, modify or terminate a secure LCS-UP connection for a target UE


# **UPConfigureAPI_upConfig**
```c
// set up, modify or terminate a secure LCS-UP connection for a target UE
//
void UPConfigureAPI_upConfig(apiClient_t *apiClient, up_config_t * up_config);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**up_config** | **[up_config_t](up_config.md) \*** |  | 

### Return type

void

### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

