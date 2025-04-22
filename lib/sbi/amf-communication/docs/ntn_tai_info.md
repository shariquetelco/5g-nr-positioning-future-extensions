# ntn_tai_info_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**plmn_id** | [**plmn_id_nid_t**](plmn_id_nid.md) \* |  | 
**tac_list** | **list_t \*** |  | 
**derived_tac** | **char \*** | 2 or 3-octet string identifying a tracking area code as specified in clause 9.3.3.10  of 3GPP TS 38.413, in hexadecimal representation. Each character in the string shall  take a value of \&quot;0\&quot; to \&quot;9\&quot;, \&quot;a\&quot; to \&quot;f\&quot; or \&quot;A\&quot; to \&quot;F\&quot; and shall represent 4 bits. The most significant character representing the 4 most significant bits of the TAC shall  appear first in the string, and the character representing the 4 least significant bit  of the TAC shall appear last in the string.   | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


