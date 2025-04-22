# abnormal_behaviour_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**supis** | **list_t \*** |  | [optional] 
**excep** | [**exception_t**](exception.md) \* |  | 
**dnn** | **char \*** | String representing a Data Network as defined in clause 9A of 3GPP TS 23.003;  it shall contain either a DNN Network Identifier, or a full DNN with both the Network  Identifier and Operator Identifier, as specified in 3GPP TS 23.003 clause 9.1.1 and 9.1.2. It shall be coded as string in which the labels are separated by dots  (e.g. \&quot;Label1.Label2.Label3\&quot;).  | [optional] 
**snssai** | [**snssai_t**](snssai.md) \* |  | [optional] 
**ratio** | **int** | Unsigned integer indicating Sampling Ratio (see clauses 4.15.1 of 3GPP TS 23.502), expressed in percent.   | [optional] 
**confidence** | **int** | Unsigned Integer, i.e. only value 0 and integers above 0 are permissible. | [optional] 
**addt_meas_info** | [**additional_measurement_t**](additional_measurement.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


