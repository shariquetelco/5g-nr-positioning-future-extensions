# suggested_pfd_info_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**pfd_id** | **char \*** | Identifier of the PFD (i.e. new PFD ID assigned by NWDAF or existing PFD ID retrieved from UDR which was generated by NWDAF).  | 
**ip3_tuple_list** | **list_t \*** | Represents a 3-tuple with protocol, server ip and server port for UL/DL application traffic. The content of the string has the same encoding as the IPFilterRule AVP value as defined in IETF RFC 6733.  | [optional] 
**urls** | **list_t \*** | Represents the significant parts of the URL to be matched, e.g. host name. | [optional] 
**domain_names** | **list_t \*** | Represents Domain name matching criteria. | [optional] 
**dn_protocol** | [**domain_name_protocol_t**](domain_name_protocol.md) \* |  | [optional] 
**pfd_confidence** | **int** | Unsigned Integer, i.e. only value 0 and integers above 0 are permissible. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


