# pws_information_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**message_identifier** | **int** | Integer where the allowed values correspond to the value range of an unsigned 16-bit integer.  | 
**serial_number** | **int** | Integer where the allowed values correspond to the value range of an unsigned 16-bit integer.  | 
**pws_container** | [**n2_info_content_t**](n2_info_content.md) \* |  | 
**bc_empty_area_list** | [**list_t**](global_ran_node_id.md) \* |  | [optional] 
**send_ran_response** | **int** |  | [optional] [default to false]
**omc_id** | **char \*** | Represents the OMC Identifier | [optional] 
**nf_id** | **char \*** | String uniquely identifying a NF instance. The format of the NF Instance ID shall be a  Universally Unique Identifier (UUID) version 4, as described in IETF RFC 4122.   | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


