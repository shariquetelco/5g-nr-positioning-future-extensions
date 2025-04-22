# smf_selection_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**unsupp_dnn** | **int** |  | [optional] 
**candidates** | **list_t*** | Contains the list of DNNs per S-NSSAI that are candidates for replacement. The snssai attribute within the CandidateForReplacement data type is the key of the map.  | [optional] 
**snssai** | [**snssai_t**](snssai.md) \* |  | [optional] 
**mapping_snssai** | [**snssai_t**](snssai.md) \* |  | [optional] 
**dnn** | **char \*** | String representing a Data Network as defined in clause 9A of 3GPP TS 23.003;  it shall contain either a DNN Network Identifier, or a full DNN with both the Network  Identifier and Operator Identifier, as specified in 3GPP TS 23.003 clause 9.1.1 and 9.1.2. It shall be coded as string in which the labels are separated by dots  (e.g. \&quot;Label1.Label2.Label3\&quot;).  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


