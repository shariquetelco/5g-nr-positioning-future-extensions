# nnwdaf_events_subscription_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**event_subscriptions** | [**list_t**](event_subscription.md) \* | Subscribed events | 
**evt_req** | [**reporting_information_t**](reporting_information.md) \* |  | [optional] 
**notification_uri** | **char \*** | String providing an URI formatted according to RFC 3986. | [optional] 
**notif_corr_id** | **char \*** | Notification correlation identifier. | [optional] 
**supported_features** | **char \*** | A string used to indicate the features supported by an API that is used as defined in clause  6.6 in 3GPP TS 29.500. The string shall contain a bitmask indicating supported features in  hexadecimal representation Each character in the string shall take a value of \&quot;0\&quot; to \&quot;9\&quot;,  \&quot;a\&quot; to \&quot;f\&quot; or \&quot;A\&quot; to \&quot;F\&quot; and shall represent the support of 4 features as described in  table 5.2.2-3. The most significant character representing the highest-numbered features shall  appear first in the string, and the character representing features 1 to 4 shall appear last  in the string. The list of features and their numbering (starting with 1) are defined  separately for each API. If the string contains a lower number of characters than there are  defined features for an API, all features that would be represented by characters that are not  present in the string are not supported.  | [optional] 
**event_notifications** | [**list_t**](event_notification.md) \* |  | [optional] 
**fail_event_reports** | [**list_t**](failure_event_info.md) \* |  | [optional] 
**prev_sub** | [**prev_sub_info_t**](prev_sub_info.md) \* |  | [optional] 
**cons_nf_info** | [**consumer_nf_information_t**](consumer_nf_information.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


