# loc_context_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**amf_id** | **char \*** | String uniquely identifying a NF instance. The format of the NF Instance ID shall be a  Universally Unique Identifier (UUID) version 4, as described in IETF RFC 4122.   | 
**location_qo_s** | [**location_qo_s_t**](location_qo_s.md) \* |  | [optional] 
**supported_gad_shapes** | [**list_t**](supported_gad_shapes.md) \* |  | [optional] 
**supi** | **char \*** | String identifying a Supi that shall contain either an IMSI, a network specific identifier, a Global Cable Identifier (GCI) or a Global Line Identifier (GLI) as specified in clause  2.2A of 3GPP TS 23.003. It shall be formatted as follows  - for an IMSI \&quot;imsi-&lt;imsi&gt;\&quot;, where &lt;imsi&gt; shall be formatted according to clause 2.2    of 3GPP TS 23.003 that describes an IMSI.  - for a network specific identifier \&quot;nai-&lt;nai&gt;, where &lt;nai&gt; shall be formatted    according to clause 28.7.2 of 3GPP TS 23.003 that describes an NAI.  - for a GCI \&quot;gci-&lt;gci&gt;\&quot;, where &lt;gci&gt; shall be formatted according to clause 28.15.2    of 3GPP TS 23.003.  - for a GLI \&quot;gli-&lt;gli&gt;\&quot;, where &lt;gli&gt; shall be formatted according to clause 28.16.2 of    3GPP TS 23.003.To enable that the value is used as part of an URI, the string shall    only contain characters allowed according to the \&quot;lower-with-hyphen\&quot; naming convention    defined in 3GPP TS 29.501.  | [optional] 
**gpsi** | **char \*** | String identifying a Gpsi shall contain either an External Id or an MSISDN.  It shall be formatted as follows -External Identifier&#x3D; \&quot;extid-&#39;extid&#39;, where &#39;extid&#39;  shall be formatted according to clause 19.7.2 of 3GPP TS 23.003 that describes an  External Identifier.   | [optional] 
**ldr_type** | **ldr_type_t \*** |  | 
**hgmlc_call_back_uri** | **char \*** | String providing an URI formatted according to RFC 3986. | 
**ldr_reference** | **char \*** | LDR Reference. | 
**periodic_event_info** | [**periodic_event_info_t**](periodic_event_info.md) \* |  | [optional] 
**area_event_info** | [**area_event_info_t**](area_event_info.md) \* |  | [optional] 
**motion_event_info** | [**motion_event_info_t**](motion_event_info.md) \* |  | [optional] 
**event_report_message** | [**event_report_message_t**](event_report_message.md) \* |  | 
**event_reporting_status** | [**event_reporting_status_t**](event_reporting_status.md) \* |  | [optional] 
**ue_location_info** | [**ue_location_info_t**](ue_location_info.md) \* |  | [optional] 
**c_io_t5_gs_optimisation** | **int** |  | [optional] [default to false]
**ecgi** | [**ecgi_t**](ecgi.md) \* |  | [optional] 
**ncgi** | [**ncgi_t**](ncgi.md) \* |  | [optional] 
**guami** | [**guami_t**](guami.md) \* |  | [optional] 
**supported_features** | **char \*** | A string used to indicate the features supported by an API that is used as defined in clause  6.6 in 3GPP TS 29.500. The string shall contain a bitmask indicating supported features in  hexadecimal representation Each character in the string shall take a value of \&quot;0\&quot; to \&quot;9\&quot;,  \&quot;a\&quot; to \&quot;f\&quot; or \&quot;A\&quot; to \&quot;F\&quot; and shall represent the support of 4 features as described in  table 5.2.2-3. The most significant character representing the highest-numbered features shall  appear first in the string, and the character representing features 1 to 4 shall appear last  in the string. The list of features and their numbering (starting with 1) are defined  separately for each API. If the string contains a lower number of characters than there are  defined features for an API, all features that would be represented by characters that are not  present in the string are not supported.  | [optional] 
**ue_positioning_cap** | **char \*** | Positioning capabilities supported by the UE. A string encoding the \&quot;ProvideCapabilities-r9-IEs\&quot; IE as specified in clause 6.3 of 3GPP TS 37.355 (start from octet 1). | [optional] 
**scheduled_loc_time** | **char \*** | string with format &#39;date-time&#39; as defined in OpenAPI. | [optional] 
**indoor_outdoor_ind** | **indoor_outdoor_ind_t \*** |  | [optional] 
**los_nlos_measure_ind** | **los_nlos_measure_ind_t \*** |  | [optional] 
**up_cum_evt_rpt_criteria** | [**up_cum_evt_rpt_criteria_t**](up_cum_evt_rpt_criteria.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


