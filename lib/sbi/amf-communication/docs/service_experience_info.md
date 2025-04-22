# service_experience_info_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**svc_exprc** | [**svc_experience_t**](svc_experience.md) \* |  | 
**svc_exprc_variance** | **float** | string with format &#39;float&#39; as defined in OpenAPI. | [optional] 
**supis** | **list_t \*** |  | [optional] 
**snssai** | [**snssai_t**](snssai.md) \* |  | [optional] 
**app_id** | **char \*** | String providing an application identifier. | [optional] 
**srv_expc_type** | [**service_experience_type_t**](service_experience_type.md) \* |  | [optional] 
**ue_locs** | [**list_t**](location_info.md) \* |  | [optional] 
**upf_info** | [**upf_information_t**](upf_information.md) \* |  | [optional] 
**dnai** | **char \*** | DNAI (Data network access identifier), see clause 5.6.7 of 3GPP TS 23.501. | [optional] 
**app_server_inst** | [**addr_fqdn_t**](addr_fqdn.md) \* |  | [optional] 
**confidence** | **int** | Unsigned Integer, i.e. only value 0 and integers above 0 are permissible. | [optional] 
**dnn** | **char \*** | String representing a Data Network as defined in clause 9A of 3GPP TS 23.003;  it shall contain either a DNN Network Identifier, or a full DNN with both the Network  Identifier and Operator Identifier, as specified in 3GPP TS 23.003 clause 9.1.1 and 9.1.2. It shall be coded as string in which the labels are separated by dots  (e.g. \&quot;Label1.Label2.Label3\&quot;).  | [optional] 
**network_area** | [**network_area_info_t**](network_area_info.md) \* |  | [optional] 
**nsi_id** | **char \*** | Contains the Identifier of the selected Network Slice instance | [optional] 
**ratio** | **int** | Unsigned integer indicating Sampling Ratio (see clauses 4.15.1 of 3GPP TS 23.502), expressed in percent.   | [optional] 
**rat_freq** | [**rat_freq_information_t**](rat_freq_information.md) \* |  | [optional] 
**pdu_ses_info** | [**pdu_session_info_1_t**](pdu_session_info_1.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


