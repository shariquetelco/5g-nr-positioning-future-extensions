# assign_ebi_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**pdu_session_id** | **int** | Unsigned integer identifying a PDU session, within the range 0 to 255, as specified in  clause 11.2.3.1b, bits 1 to 8, of 3GPP TS 24.007. If the PDU Session ID is allocated by the  Core Network for UEs not supporting N1 mode, reserved range 64 to 95 is used. PDU Session ID  within the reserved range is only visible in the Core Network.   | 
**arp_list** | [**list_t**](arp.md) \* |  | [optional] 
**released_ebi_list** | **list_t \*** |  | [optional] 
**old_guami** | [**guami_t**](guami.md) \* |  | [optional] 
**modified_ebi_list** | [**list_t**](ebi_arp_mapping.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


