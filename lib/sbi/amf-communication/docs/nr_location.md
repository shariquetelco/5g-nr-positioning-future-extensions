# nr_location_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**tai** | [**tai_t**](tai.md) \* |  | 
**ncgi** | [**ncgi_t**](ncgi.md) \* |  | 
**ignore_ncgi** | **int** |  | [optional] [default to false]
**age_of_location_information** | **int** | The value represents the elapsed time in minutes since the last network contact of the mobile station. Value \&quot;0\&quot; indicates that the location information was obtained after a successful paging procedure for Active Location Retrieval when the UE is in idle mode or after a successful  NG-RAN location reporting procedure with the eNB when the UE is in connected mode. Any other value than \&quot;0\&quot; indicates that the location information is the last known one. See 3GPP TS 29.002 clause 17.7.8.  | [optional] 
**ue_location_timestamp** | **char \*** | string with format &#39;date-time&#39; as defined in OpenAPI. | [optional] 
**geographical_information** | **char \*** | Refer to geographical Information. See 3GPP TS 23.032 clause 7.3.2. Only the description of an ellipsoid point with uncertainty circle is allowed to be used.  | [optional] 
**geodetic_information** | **char \*** | Refers to Calling Geodetic Location. See ITU-T Recommendation Q.763 (1999) [24] clause 3.88.2. Only the description of an ellipsoid point with uncertainty circle is allowed to be used.  | [optional] 
**global_gnb_id** | [**global_ran_node_id_t**](global_ran_node_id.md) \* |  | [optional] 
**ntn_tai_info** | [**ntn_tai_info_t**](ntn_tai_info.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


