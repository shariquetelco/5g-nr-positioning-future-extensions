# ue_context_relocate_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**ue_context** | [**ue_context_t**](ue_context.md) \* |  | 
**target_id** | [**ng_ran_target_id_t**](ng_ran_target_id.md) \* |  | 
**source_to_target_data** | [**n2_info_content_t**](n2_info_content.md) \* |  | 
**forward_relocation_request** | [**ref_to_binary_data_t**](ref_to_binary_data.md) \* |  | 
**pdu_session_list** | [**list_t**](n2_sm_information.md) \* |  | [optional] 
**ue_radio_capability** | [**n2_info_content_t**](n2_info_content.md) \* |  | [optional] 
**ngap_cause** | [**ng_ap_cause_t**](ng_ap_cause.md) \* |  | [optional] 
**supported_features** | **char \*** | A string used to indicate the features supported by an API that is used as defined in clause  6.6 in 3GPP TS 29.500. The string shall contain a bitmask indicating supported features in  hexadecimal representation Each character in the string shall take a value of \&quot;0\&quot; to \&quot;9\&quot;,  \&quot;a\&quot; to \&quot;f\&quot; or \&quot;A\&quot; to \&quot;F\&quot; and shall represent the support of 4 features as described in  table 5.2.2-3. The most significant character representing the highest-numbered features shall  appear first in the string, and the character representing features 1 to 4 shall appear last  in the string. The list of features and their numbering (starting with 1) are defined  separately for each API. If the string contains a lower number of characters than there are  defined features for an API, all features that would be represented by characters that are not  present in the string are not supported.  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


