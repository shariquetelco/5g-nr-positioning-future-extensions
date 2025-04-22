# LocationMeasureAPI

All URIs are relative to *https://example.com/nlmf-loc/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**LocationMeasureAPI_locationMeasure**](LocationMeasureAPI.md#LocationMeasureAPI_locationMeasure) | **POST** /measure-location | PRU location measurement


# **LocationMeasureAPI_locationMeasure**
```c
// PRU location measurement
//
loc_measurement_resp_t* LocationMeasureAPI_locationMeasure(apiClient_t *apiClient, loc_measurement_req_t * loc_measurement_req);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**loc_measurement_req** | **[loc_measurement_req_t](loc_measurement_req.md) \*** |  | 

### Return type

[loc_measurement_resp_t](loc_measurement_resp.md) *


### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

