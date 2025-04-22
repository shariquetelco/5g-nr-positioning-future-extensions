# input_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**gpsi** | **char \*** | String identifying a Gpsi shall contain either an External Id or an MSISDN.  It shall be formatted as follows -External Identifier&#x3D; \&quot;extid-&#39;extid&#39;, where &#39;extid&#39;  shall be formatted according to clause 19.7.2 of 3GPP TS 23.003 that describes an  External Identifier.   | [optional] 
**supi** | **char \*** | String identifying a Supi that shall contain either an IMSI, a network specific identifier, a Global Cable Identifier (GCI) or a Global Line Identifier (GLI) as specified in clause  2.2A of 3GPP TS 23.003. It shall be formatted as follows  - for an IMSI \&quot;imsi-&lt;imsi&gt;\&quot;, where &lt;imsi&gt; shall be formatted according to clause 2.2    of 3GPP TS 23.003 that describes an IMSI.  - for a network specific identifier \&quot;nai-&lt;nai&gt;, where &lt;nai&gt; shall be formatted    according to clause 28.7.2 of 3GPP TS 23.003 that describes an NAI.  - for a GCI \&quot;gci-&lt;gci&gt;\&quot;, where &lt;gci&gt; shall be formatted according to clause 28.15.2    of 3GPP TS 23.003.  - for a GLI \&quot;gli-&lt;gli&gt;\&quot;, where &lt;gli&gt; shall be formatted according to clause 28.16.2 of    3GPP TS 23.003.To enable that the value is used as part of an URI, the string shall    only contain characters allowed according to the \&quot;lower-with-hyphen\&quot; naming convention    defined in 3GPP TS 29.501.  | [optional] 
**app_layer_id** | **char \*** | String identifying an UE with application layer ID. The format of the application  layer ID parameter is same as the Application layer ID defined in clause 11.3.4 of  3GPP TS 24.554.  | [optional] 
**ext_group_id** | **char \*** | String identifying External Group Identifier that identifies a group made up of one or more  subscriptions associated to a group of IMSIs, as specified in clause 19.7.3 of 3GPP TS 23.003.   | [optional] 
**int_group_id** | **char \*** | String identifying a group of devices network internal globally unique ID which identifies a set of IMSIs, as specified in clause 19.9 of 3GPP TS 23.003.   | [optional] 
**external_client_type** | **external_client_type_t \*** |  | 
**location_qo_s** | [**location_qo_s_t**](location_qo_s.md) \* |  | [optional] 
**supported_gad_shapes** | [**list_t**](supported_gad_shapes.md) \* |  | [optional] 
**service_identity** | **char \*** | Contains the service identity | [optional] 
**service_coverage** | **list_t \*** |  | [optional] 
**ldr_type** | **ldr_type_t \*** |  | [optional] 
**periodic_event_info** | [**periodic_event_info_t**](periodic_event_info.md) \* |  | [optional] 
**area_event_info** | [**area_event_info_ext_t**](area_event_info_ext.md) \* |  | [optional] 
**motion_event_info** | [**motion_event_info_t**](motion_event_info.md) \* |  | [optional] 
**ldr_reference** | **char \*** | LDR Reference. | [optional] 
**hgmlc_call_back_uri** | **char \*** | String providing an URI formatted according to RFC 3986. | [optional] 
**event_notification_uri** | **char \*** | String providing an URI formatted according to RFC 3986. | [optional] 
**external_client_identification** | **char \*** | Contains the external client identification | [optional] 
**af_id** | **char \*** |  | [optional] 
**ue_privacy_requirements** | [**ue_privacy_requirements_t**](ue_privacy_requirements.md) \* |  | [optional] 
**lcs_service_type** | **int** | LCS service type. | [optional] 
**velocity_requested** | **velocity_requested_t \*** |  | [optional] 
**priority** | **lcs_priority_t \*** |  | [optional] 
**location_type_requested** | **location_type_requested_t \*** |  | [optional] 
**maximum_age_of_location_estimate** | **int** | Indicates value of the age of the location estimate. | [optional] 
**amf_id** | **char \*** | String identifying the AMF ID composed of AMF Region ID (8 bits), AMF Set ID (10 bits) and AMF  Pointer (6 bits) as specified in clause 2.10.1 of 3GPP TS 23.003. It is encoded as a string of  6 hexadecimal characters (i.e., 24 bits).   | [optional] 
**code_word** | **char \*** | Contains the codeword | [optional] 
**scheduled_loc_time** | **char \*** | string with format &#39;date-time&#39; as defined in OpenAPI. | [optional] 
**reliable_loc_req** | **int** |  | [optional] [default to false]
**serving_lmf_id** | **char \*** | LMF identification. | [optional] 
**lp_hap_type** | [**lp_hap_type_t**](lp_hap_type.md) \* |  | [optional] 
**evt_rpt_expected_area** | [**geographic_area_t**](geographic_area.md) \* |  | [optional] 
**reporting_ind** | [**input_data_reporting_ind_t**](input_data_reporting_ind.md) \* |  | [optional] 
**integrity_requirements** | [**integrity_requirements_t**](integrity_requirements.md) \* |  | [optional] 
**up_loc_rep_info_af** | [**up_loc_rep_info_af_t**](up_loc_rep_info_af.md) \* |  | [optional] 
**requested_ranging_sl_result** | [**list_t**](ranging_sl_result.md) \* |  | [optional] 
**related_ues** | [**list_t**](related_ue.md) \* |  | [optional] 
**mapped_qo_s_eps** | [**mapped_location_qo_s_eps_t**](mapped_location_qo_s_eps.md) \* |  | [optional] 
**coordinate_id** | **int** |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


