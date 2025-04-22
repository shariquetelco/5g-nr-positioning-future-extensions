# n1_message_notification_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**n1_notify_subscription_id** | **char \*** |  | [optional] 
**n1_message_container** | [**n1_message_container_t**](n1_message_container.md) \* |  | 
**lcs_correlation_id** | **char \*** | LCS Correlation ID. | [optional] 
**registration_ctxt_container** | [**registration_context_container_t**](registration_context_container.md) \* |  | [optional] 
**new_lmf_identification** | **char \*** | LMF identification. | [optional] 
**guami** | [**guami_t**](guami.md) \* |  | [optional] 
**c_io_t5_gs_optimisation** | **int** |  | [optional] [default to false]
**ecgi** | [**ecgi_t**](ecgi.md) \* |  | [optional] 
**ncgi** | [**ncgi_t**](ncgi.md) \* |  | [optional] 
**tai** | [**tai_t**](tai.md) \* |  | [optional] 
**supi** | **char \*** | String identifying a Supi that shall contain either an IMSI, a network specific identifier, a Global Cable Identifier (GCI) or a Global Line Identifier (GLI) as specified in clause  2.2A of 3GPP TS 23.003. It shall be formatted as follows  - for an IMSI \&quot;imsi-&lt;imsi&gt;\&quot;, where &lt;imsi&gt; shall be formatted according to clause 2.2    of 3GPP TS 23.003 that describes an IMSI.  - for a network specific identifier \&quot;nai-&lt;nai&gt;, where &lt;nai&gt; shall be formatted    according to clause 28.7.2 of 3GPP TS 23.003 that describes an NAI.  - for a GCI \&quot;gci-&lt;gci&gt;\&quot;, where &lt;gci&gt; shall be formatted according to clause 28.15.2    of 3GPP TS 23.003.  - for a GLI \&quot;gli-&lt;gli&gt;\&quot;, where &lt;gli&gt; shall be formatted according to clause 28.16.2 of    3GPP TS 23.003.To enable that the value is used as part of an URI, the string shall    only contain characters allowed according to the \&quot;lower-with-hyphen\&quot; naming convention    defined in 3GPP TS 29.501.  | [optional] 
**pru_ind** | [**pru_ind_t**](pru_ind.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


