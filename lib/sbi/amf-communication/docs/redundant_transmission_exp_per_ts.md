# redundant_transmission_exp_per_ts_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**ts_start** | **char \*** | string with format &#39;date-time&#39; as defined in OpenAPI. | 
**ts_duration** | **int** | indicating a time in seconds. | 
**obsv_red_trans_exp** | [**observed_redundant_trans_exp_t**](observed_redundant_trans_exp.md) \* |  | 
**red_trans_status** | **int** | Redundant Transmission Status. Set to \&quot;true\&quot; if redundant transmission was activated, otherwise set to \&quot;false\&quot;. Default value is \&quot;false\&quot; if omitted.  | [optional] 
**ue_ratio** | **int** | Unsigned integer indicating Sampling Ratio (see clauses 4.15.1 of 3GPP TS 23.502), expressed in percent.   | [optional] 
**confidence** | **int** | Unsigned Integer, i.e. only value 0 and integers above 0 are permissible. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


