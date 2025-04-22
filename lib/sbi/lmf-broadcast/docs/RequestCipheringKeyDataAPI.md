# RequestCipheringKeyDataAPI

All URIs are relative to *https://example.com/nlmf-broadcast/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**RequestCipheringKeyDataAPI_cipheringKeyData**](RequestCipheringKeyDataAPI.md#RequestCipheringKeyDataAPI_cipheringKeyData) | **POST** /cipher-key-data | Request ciphering key data


# **RequestCipheringKeyDataAPI_cipheringKeyData**
```c
// Request ciphering key data
//
cipher_response_data_t* RequestCipheringKeyDataAPI_cipheringKeyData(apiClient_t *apiClient, cipher_request_data_t * cipher_request_data);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**cipher_request_data** | **[cipher_request_data_t](cipher_request_data.md) \*** |  | 

### Return type

[cipher_response_data_t](cipher_response_data.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

