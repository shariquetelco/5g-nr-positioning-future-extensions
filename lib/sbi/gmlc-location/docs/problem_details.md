# problem_details_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | String providing an URI formatted according to RFC 3986. | [optional] 
**title** | **char \*** |  | [optional] 
**status** | **int** |  | [optional] 
**detail** | **char \*** | A human-readable explanation specific to this occurrence of the problem. | [optional] 
**instance** | **char \*** | String providing an URI formatted according to RFC 3986. | [optional] 
**cause** | **char \*** | A machine-readable application error cause specific to this occurrence of the problem.  This IE should be present and provide application-related error information, if available.  | [optional] 
**invalid_params** | [**list_t**](invalid_param.md) \* |  | [optional] 
**supported_features** | **char \*** | A string used to indicate the features supported by an API that is used as defined in clause  6.6 in 3GPP TS 29.500. The string shall contain a bitmask indicating supported features in  hexadecimal representation Each character in the string shall take a value of \&quot;0\&quot; to \&quot;9\&quot;,  \&quot;a\&quot; to \&quot;f\&quot; or \&quot;A\&quot; to \&quot;F\&quot; and shall represent the support of 4 features as described in  table 5.2.2-3. The most significant character representing the highest-numbered features shall  appear first in the string, and the character representing features 1 to 4 shall appear last  in the string. The list of features and their numbering (starting with 1) are defined  separately for each API. If the string contains a lower number of characters than there are  defined features for an API, all features that would be represented by characters that are not  present in the string are not supported.  | [optional] 
**access_token_error** | [**access_token_err_t**](access_token_err.md) \* |  | [optional] 
**access_token_request** | [**access_token_req_t**](access_token_req.md) \* |  | [optional] 
**nrf_id** | **char \*** | Fully Qualified Domain Name | [optional] 
**supported_api_versions** | **list_t \*** |  | [optional] 
**no_profile_match_info** | [**no_profile_match_info_t**](no_profile_match_info.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


