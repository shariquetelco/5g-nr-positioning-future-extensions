# flow_info_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**flow_id** | **int** | Indicates the IP flow identifier. | 
**flow_descriptions** | **list_t \*** | Indicates the packet filters of the IP flow. Refer to clause 5.3.8 of 3GPP TS 29.214 for encoding. It shall contain UL and/or DL IP flow description.  | [optional] 
**tos_tc** | **char \*** | 2-octet string, where each octet is encoded in hexadecimal representation. The first octet contains the IPv4 Type-of-Service or the IPv6 Traffic-Class field and the second octet contains the ToS/Traffic Class mask field.  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


