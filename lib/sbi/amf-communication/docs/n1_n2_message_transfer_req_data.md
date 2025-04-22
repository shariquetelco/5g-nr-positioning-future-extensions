# n1_n2_message_transfer_req_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**n1_message_container** | [**n1_message_container_t**](n1_message_container.md) \* |  | [optional] 
**n2_info_container** | [**n2_info_container_t**](n2_info_container.md) \* |  | [optional] 
**mt_data** | [**ref_to_binary_data_t**](ref_to_binary_data.md) \* |  | [optional] 
**skip_ind** | **int** |  | [optional] [default to false]
**last_msg_indication** | **int** |  | [optional] 
**pdu_session_id** | **int** | Unsigned integer identifying a PDU session, within the range 0 to 255, as specified in  clause 11.2.3.1b, bits 1 to 8, of 3GPP TS 24.007. If the PDU Session ID is allocated by the  Core Network for UEs not supporting N1 mode, reserved range 64 to 95 is used. PDU Session ID  within the reserved range is only visible in the Core Network.   | [optional] 
**lcs_correlation_id** | **char \*** | LCS Correlation ID. | [optional] 
**ppi** | **int** | Paging Policy Indicator | [optional] 
**arp** | [**arp_t**](arp.md) \* |  | [optional] 
**_5qi** | **int** | Unsigned integer representing a 5G QoS Identifier (see clause 5.7.2.1 of 3GPP TS 23.501, within the range 0 to 255.  | [optional] 
**n1n2_failure_txf_notif_uri** | **char \*** | String providing an URI formatted according to RFC 3986. | [optional] 
**smf_reallocation_ind** | **int** |  | [optional] [default to false]
**area_of_validity** | [**area_of_validity_t**](area_of_validity.md) \* |  | [optional] 
**supported_features** | **char \*** | A string used to indicate the features supported by an API that is used as defined in clause  6.6 in 3GPP TS 29.500. The string shall contain a bitmask indicating supported features in  hexadecimal representation Each character in the string shall take a value of \&quot;0\&quot; to \&quot;9\&quot;,  \&quot;a\&quot; to \&quot;f\&quot; or \&quot;A\&quot; to \&quot;F\&quot; and shall represent the support of 4 features as described in  table 5.2.2-3. The most significant character representing the highest-numbered features shall  appear first in the string, and the character representing features 1 to 4 shall appear last  in the string. The list of features and their numbering (starting with 1) are defined  separately for each API. If the string contains a lower number of characters than there are  defined features for an API, all features that would be represented by characters that are not  present in the string are not supported.  | [optional] 
**old_guami** | [**guami_t**](guami.md) \* |  | [optional] 
**ma_accepted_ind** | **int** |  | [optional] [default to false]
**ext_buf_support** | **int** |  | [optional] [default to false]
**target_access** | **access_type_t \*** |  | [optional] 
**nf_id** | **char \*** | String uniquely identifying a NF instance. The format of the NF Instance ID shall be a  Universally Unique Identifier (UUID) version 4, as described in IETF RFC 4122.   | [optional] 
**pru_ind** | **int** |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


