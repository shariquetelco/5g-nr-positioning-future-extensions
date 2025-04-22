# PrivacyCheckIdMappingAPI

All URIs are relative to *https://example.com/ngmlc-loc/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**PrivacyCheckIdMappingAPI_privacyCheckIdMapping**](PrivacyCheckIdMappingAPI.md#PrivacyCheckIdMappingAPI_privacyCheckIdMapping) | **POST** /perform-privacy-check-id-mapping | Privacy Check Id Mapping for Ranging SL Positioing Service


# **PrivacyCheckIdMappingAPI_privacyCheckIdMapping**
```c
// Privacy Check Id Mapping for Ranging SL Positioing Service
//
privacy_check_id_mapping_resp_data_t* PrivacyCheckIdMappingAPI_privacyCheckIdMapping(apiClient_t *apiClient, privacy_check_id_mapping_req_data_t * privacy_check_id_mapping_req_data);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**privacy_check_id_mapping_req_data** | **[privacy_check_id_mapping_req_data_t](privacy_check_id_mapping_req_data.md) \*** |  | 

### Return type

[privacy_check_id_mapping_resp_data_t](privacy_check_id_mapping_resp_data.md) *


### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

