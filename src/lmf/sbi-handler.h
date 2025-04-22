#ifndef _SBI_LMF_HANDLER_
#define _SBI_LMF_HANDLER_

#include "lmfd.h"

/*
 * Forward declaration
 *
 * implemented in: lmf-callbacks.c
 */
int send_response(nghttp2_session *session, int32_t stream_id, nghttp2_nv *nva, size_t nvlen, nghttp2_data_provider2 *data_prd);
int error_response(nghttp2_session *session, http2_stream_data *stream_data, int err, char *cause);

/*
 * Callback function to send JSON data
 */
nghttp2_ssize json_read_callback(nghttp2_session *session, int32_t stream_id, uint8_t *buf, size_t length, uint32_t *data_flags, nghttp2_data_source *source, void *user_data);

/*
 * SBI handler functions
 *
 * Working principle: parsing and interpretation of request payload data, generation and sending of HTTP response
 * ... in error cases: return -1 if an INTERNAL SERVER ERROR occurs (e.g. not enough memory available), 0 otherwise (because sending response is realized in SBI handler itself!)
 */
int nlmf_loc_determineLocation(nghttp2_session *session, http2_stream_data *stream_data);
int namf_comm_N2InfoNotify(nghttp2_session *session, http2_stream_data *stream_data);

#endif
