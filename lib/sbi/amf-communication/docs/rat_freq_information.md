# rat_freq_information_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**all_freq** | **int** | Set to \&quot;true\&quot; to indicate to handle all the frequencies the NWDAF received, otherwise set to \&quot;false\&quot; or omit. The \&quot;allFreq\&quot; attribute and the \&quot;freq\&quot; attribute are mutually exclusive.  | [optional] 
**all_rat** | **int** | Set to \&quot;true\&quot; to indicate to handle all the RAT Types the NWDAF received, otherwise set to \&quot;false\&quot; or omit. The \&quot;allRat\&quot; attribute and the \&quot;ratType\&quot; attribute are mutually exclusive.  | [optional] 
**freq** | **int** | Integer value indicating the ARFCN applicable for a downlink, uplink or bi-directional (TDD) NR global frequency raster, as definition of \&quot;ARFCN-ValueNR\&quot; IE in clause 6.3.2 of 3GPP TS 38.331.  | [optional] 
**rat_type** | [**rat_type_t**](rat_type.md) \* |  | [optional] 
**svc_exp_threshold** | [**threshold_level_t**](threshold_level.md) \* |  | [optional] 
**matching_dir** | [**matching_direction_t**](matching_direction.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


