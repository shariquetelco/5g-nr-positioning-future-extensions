# dispersion_collection_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**ue_loc** | [**user_location_t**](user_location.md) \* |  | [optional] 
**snssai** | [**snssai_t**](snssai.md) \* |  | [optional] 
**supis** | **list_t \*** |  | [optional] 
**gpsis** | **list_t \*** |  | [optional] 
**app_volumes** | [**list_t**](application_volume.md) \* |  | [optional] 
**disper_amount** | **int** | Unsigned Integer, i.e. only value 0 and integers above 0 are permissible. | [optional] 
**disper_class** | [**dispersion_class_t**](dispersion_class.md) \* |  | [optional] 
**usage_rank** | **int** | Integer where the allowed values correspond to 1, 2, 3 only. | [optional] 
**percentile_rank** | **int** | Unsigned integer indicating Sampling Ratio (see clauses 4.15.1 of 3GPP TS 23.502), expressed in percent.   | [optional] 
**ue_ratio** | **int** | Unsigned integer indicating Sampling Ratio (see clauses 4.15.1 of 3GPP TS 23.502), expressed in percent.   | [optional] 
**confidence** | **int** | Unsigned Integer, i.e. only value 0 and integers above 0 are permissible. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


