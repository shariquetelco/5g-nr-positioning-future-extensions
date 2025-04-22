# qos_requirement_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**_5qi** | **int** | Unsigned integer representing a 5G QoS Identifier (see clause 5.7.2.1 of 3GPP TS 23.501, within the range 0 to 255.  | [optional] 
**gfbr_ul** | **char \*** | String representing a bit rate; the prefixes follow the standard symbols from The International System of Units, and represent x1000 multipliers, with the exception that prefix \&quot;K\&quot; is used to represent the standard symbol \&quot;k\&quot;.  | [optional] 
**gfbr_dl** | **char \*** | String representing a bit rate; the prefixes follow the standard symbols from The International System of Units, and represent x1000 multipliers, with the exception that prefix \&quot;K\&quot; is used to represent the standard symbol \&quot;k\&quot;.  | [optional] 
**res_type** | [**qos_resource_type_t**](qos_resource_type.md) \* |  | [optional] 
**pdb** | **int** | Unsigned integer indicating Packet Delay Budget (see clauses 5.7.3.4 and 5.7.4 of 3GPP TS 23.501), expressed in milliseconds.  | [optional] 
**per** | **char \*** | String representing Packet Error Rate (see clause 5.7.3.5 and 5.7.4 of 3GPP TS 23.501, expressed as a \&quot;scalar x 10-k\&quot; where the scalar and the exponent k are each encoded as one decimal digit.  | [optional] 
**device_speed** | [**velocity_estimate_t**](velocity_estimate.md) \* |  | [optional] 
**device_type** | [**device_type_t**](device_type.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


