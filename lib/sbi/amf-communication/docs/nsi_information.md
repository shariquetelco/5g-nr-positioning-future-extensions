# nsi_information_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**nrf_id** | **char \*** | String providing an URI formatted according to RFC 3986. | 
**nsi_id** | **char \*** | Contains the Identifier of the selected Network Slice instance | [optional] 
**nrf_nf_mgt_uri** | **char \*** | String providing an URI formatted according to RFC 3986. | [optional] 
**nrf_access_token_uri** | **char \*** | String providing an URI formatted according to RFC 3986. | [optional] 
**nrf_oauth2_required** | **list_t*** | Map indicating whether the NRF requires Oauth2-based authorization for accessing its services. The key of the map shall be the name of an NRF service, e.g. \&quot;nnrf-nfm\&quot; or \&quot;nnrf-disc\&quot;  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


