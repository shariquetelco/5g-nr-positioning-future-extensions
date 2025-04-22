# traffic_characterization_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**dnn** | **char \*** | String representing a Data Network as defined in clause 9A of 3GPP TS 23.003;  it shall contain either a DNN Network Identifier, or a full DNN with both the Network  Identifier and Operator Identifier, as specified in 3GPP TS 23.003 clause 9.1.1 and 9.1.2. It shall be coded as string in which the labels are separated by dots  (e.g. \&quot;Label1.Label2.Label3\&quot;).  | [optional] 
**snssai** | [**snssai_t**](snssai.md) \* |  | [optional] 
**app_id** | **char \*** | String providing an application identifier. | [optional] 
**f_descs** | [**list_t**](ip_eth_flow_description.md) \* |  | [optional] 
**ul_vol** | **long** | Unsigned integer identifying a volume in units of bytes. | [optional] 
**ul_vol_variance** | **float** | string with format &#39;float&#39; as defined in OpenAPI. | [optional] 
**dl_vol** | **long** | Unsigned integer identifying a volume in units of bytes. | [optional] 
**dl_vol_variance** | **float** | string with format &#39;float&#39; as defined in OpenAPI. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


