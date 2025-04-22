# n3ga_location_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**n3gpp_tai** | [**tai_t**](tai.md) \* |  | [optional] 
**n3_iwf_id** | **char \*** | This IE shall contain the N3IWF identifier received over NGAP and shall be encoded as a  string of hexadecimal characters. Each character in the string shall take a value of \&quot;0\&quot;  to \&quot;9\&quot;, \&quot;a\&quot; to \&quot;f\&quot; or \&quot;A\&quot; to \&quot;F\&quot; and shall represent 4 bits. The most significant  character representing the 4 most significant bits of the N3IWF ID shall appear first in  the string, and the character representing the 4 least significant bit of the N3IWF ID  shall appear last in the string.   | [optional] 
**ue_ipv4_addr** | **char \*** | String identifying a IPv4 address formatted in the &#39;dotted decimal&#39; notation as defined in RFC 1166.  | [optional] 
**ue_ipv6_addr** | [**ipv6_addr_t**](ipv6_addr.md) \* |  | [optional] 
**port_number** | **int** | Unsigned Integer, i.e. only value 0 and integers above 0 are permissible. | [optional] 
**protocol** | [**transport_protocol_t**](transport_protocol.md) \* |  | [optional] 
**tnap_id** | [**tnap_id_t**](tnap_id.md) \* |  | [optional] 
**twap_id** | [**twap_id_t**](twap_id.md) \* |  | [optional] 
**hfc_node_id** | [**hfc_node_id_t**](hfc_node_id.md) \* |  | [optional] 
**gli** | **char \*** | string with format &#39;bytes&#39; as defined in OpenAPI | [optional] 
**w5gban_line_type** | [**line_type_t**](line_type.md) \* |  | [optional] 
**gci** | **char \*** | Global Cable Identifier uniquely identifying the connection between the 5G-CRG or FN-CRG to the 5GS. See clause 28.15.4 of 3GPP TS 23.003. This shall be encoded as a string per clause 28.15.4 of 3GPP TS 23.003, and compliant with the syntax specified  in clause 2.2  of IETF RFC 7542 for the username part of a NAI. The GCI value is specified in CableLabs WR-TR-5WWC-ARCH.  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


