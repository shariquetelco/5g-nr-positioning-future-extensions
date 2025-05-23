#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "n2_sm_information.h"

n2_sm_information_t *n2_sm_information_create(int pdu_session_id,
                                              n2_info_content_t *n2_info_content, snssai_t *s_nssai, snssai_t *home_plmn_snssai, snssai_t *iwk_snssai, bool is_subject_to_ho,
                                              int subject_to_ho) {
	n2_sm_information_t *n2_sm_information_local_var =
		malloc(sizeof(n2_sm_information_t));

	n2_sm_information_local_var->pdu_session_id = pdu_session_id;
	n2_sm_information_local_var->n2_info_content = n2_info_content;
	n2_sm_information_local_var->s_nssai = s_nssai;
	n2_sm_information_local_var->home_plmn_snssai = home_plmn_snssai;
	n2_sm_information_local_var->iwk_snssai = iwk_snssai;
	n2_sm_information_local_var->is_subject_to_ho = is_subject_to_ho;
	n2_sm_information_local_var->subject_to_ho = subject_to_ho;

	return n2_sm_information_local_var;
}

void n2_sm_information_free(n2_sm_information_t *n2_sm_information) {
	lnode_t *node = NULL;

	if(NULL == n2_sm_information) {
		return;
	}
	if(n2_sm_information->n2_info_content) {
		n2_info_content_free(n2_sm_information->n2_info_content);
		n2_sm_information->n2_info_content = NULL;
	}
	if(n2_sm_information->s_nssai) {
		snssai_free(n2_sm_information->s_nssai);
		n2_sm_information->s_nssai = NULL;
	}
	if(n2_sm_information->home_plmn_snssai) {
		snssai_free(n2_sm_information->home_plmn_snssai);
		n2_sm_information->home_plmn_snssai = NULL;
	}
	if(n2_sm_information->iwk_snssai) {
		snssai_free(n2_sm_information->iwk_snssai);
		n2_sm_information->iwk_snssai = NULL;
	}
	free(n2_sm_information);
}

cJSON *n2_sm_information_convertToJSON(n2_sm_information_t *n2_sm_information) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(n2_sm_information == NULL) {
		printf(
			"n2_sm_information_convertToJSON() failed [N2SmInformation]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "pduSessionId",
	                           n2_sm_information->pdu_session_id) == NULL)
	{
		printf(
			"n2_sm_information_convertToJSON() failed [pdu_session_id]");
		goto end;
	}

	if(n2_sm_information->n2_info_content) {
		cJSON *n2_info_content_local_JSON =
			n2_info_content_convertToJSON(
				n2_sm_information->n2_info_content);
		if(n2_info_content_local_JSON == NULL) {
			printf(
				"n2_sm_information_convertToJSON() failed [n2_info_content]");
			goto end;
		}
		cJSON_AddItemToObject(item, "n2InfoContent",
		                      n2_info_content_local_JSON);
		if(item->child == NULL) {
			printf(
				"n2_sm_information_convertToJSON() failed [n2_info_content]");
			goto end;
		}
	}

	if(n2_sm_information->s_nssai) {
		cJSON *s_nssai_local_JSON = snssai_convertToJSON(
			n2_sm_information->s_nssai);
		if(s_nssai_local_JSON == NULL) {
			printf(
				"n2_sm_information_convertToJSON() failed [s_nssai]");
			goto end;
		}
		cJSON_AddItemToObject(item, "sNssai", s_nssai_local_JSON);
		if(item->child == NULL) {
			printf(
				"n2_sm_information_convertToJSON() failed [s_nssai]");
			goto end;
		}
	}

	if(n2_sm_information->home_plmn_snssai) {
		cJSON *home_plmn_snssai_local_JSON = snssai_convertToJSON(
			n2_sm_information->home_plmn_snssai);
		if(home_plmn_snssai_local_JSON == NULL) {
			printf(
				"n2_sm_information_convertToJSON() failed [home_plmn_snssai]");
			goto end;
		}
		cJSON_AddItemToObject(item, "homePlmnSnssai",
		                      home_plmn_snssai_local_JSON);
		if(item->child == NULL) {
			printf(
				"n2_sm_information_convertToJSON() failed [home_plmn_snssai]");
			goto end;
		}
	}

	if(n2_sm_information->iwk_snssai) {
		cJSON *iwk_snssai_local_JSON = snssai_convertToJSON(
			n2_sm_information->iwk_snssai);
		if(iwk_snssai_local_JSON == NULL) {
			printf(
				"n2_sm_information_convertToJSON() failed [iwk_snssai]");
			goto end;
		}
		cJSON_AddItemToObject(item, "iwkSnssai", iwk_snssai_local_JSON);
		if(item->child == NULL) {
			printf(
				"n2_sm_information_convertToJSON() failed [iwk_snssai]");
			goto end;
		}
	}

	if(n2_sm_information->is_subject_to_ho) {
		if(cJSON_AddBoolToObject(item, "subjectToHo",
		                         n2_sm_information->subject_to_ho) ==
		   NULL)
		{
			printf(
				"n2_sm_information_convertToJSON() failed [subject_to_ho]");
			goto end;
		}
	}

end:
	return item;
}

n2_sm_information_t *n2_sm_information_parseFromJSON(
	cJSON *n2_sm_informationJSON) {
	n2_sm_information_t *n2_sm_information_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *pdu_session_id = NULL;
	cJSON *n2_info_content = NULL;
	n2_info_content_t *n2_info_content_local_nonprim = NULL;
	cJSON *s_nssai = NULL;
	snssai_t *s_nssai_local_nonprim = NULL;
	cJSON *home_plmn_snssai = NULL;
	snssai_t *home_plmn_snssai_local_nonprim = NULL;
	cJSON *iwk_snssai = NULL;
	snssai_t *iwk_snssai_local_nonprim = NULL;
	cJSON *subject_to_ho = NULL;
	pdu_session_id = cJSON_GetObjectItemCaseSensitive(n2_sm_informationJSON,
	                                                  "pduSessionId");
	if(!pdu_session_id) {
		printf(
			"n2_sm_information_parseFromJSON() failed [pdu_session_id]");
		goto end;
	}
	if(!cJSON_IsNumber(pdu_session_id)) {
		printf(
			"n2_sm_information_parseFromJSON() failed [pdu_session_id]");
		goto end;
	}

	n2_info_content = cJSON_GetObjectItemCaseSensitive(
		n2_sm_informationJSON, "n2InfoContent");
	if(n2_info_content) {
		n2_info_content_local_nonprim = n2_info_content_parseFromJSON(
			n2_info_content);
		if(!n2_info_content_local_nonprim) {
			printf(
				"n2_info_content_parseFromJSON failed [n2_info_content]");
			goto end;
		}
	}

	s_nssai = cJSON_GetObjectItemCaseSensitive(n2_sm_informationJSON,
	                                           "sNssai");
	if(s_nssai) {
		s_nssai_local_nonprim = snssai_parseFromJSON(s_nssai);
		if(!s_nssai_local_nonprim) {
			printf("snssai_parseFromJSON failed [s_nssai]");
			goto end;
		}
	}

	home_plmn_snssai = cJSON_GetObjectItemCaseSensitive(
		n2_sm_informationJSON, "homePlmnSnssai");
	if(home_plmn_snssai) {
		home_plmn_snssai_local_nonprim = snssai_parseFromJSON(
			home_plmn_snssai);
		if(!home_plmn_snssai_local_nonprim) {
			printf("snssai_parseFromJSON failed [home_plmn_snssai]");
			goto end;
		}
	}

	iwk_snssai = cJSON_GetObjectItemCaseSensitive(n2_sm_informationJSON,
	                                              "iwkSnssai");
	if(iwk_snssai) {
		iwk_snssai_local_nonprim = snssai_parseFromJSON(iwk_snssai);
		if(!iwk_snssai_local_nonprim) {
			printf("snssai_parseFromJSON failed [iwk_snssai]");
			goto end;
		}
	}

	subject_to_ho = cJSON_GetObjectItemCaseSensitive(n2_sm_informationJSON,
	                                                 "subjectToHo");
	if(subject_to_ho) {
		if(!cJSON_IsBool(subject_to_ho)) {
			printf(
				"n2_sm_information_parseFromJSON() failed [subject_to_ho]");
			goto end;
		}
	}

	n2_sm_information_local_var = n2_sm_information_create(

		pdu_session_id->valuedouble,
		n2_info_content ? n2_info_content_local_nonprim : NULL,
		s_nssai ? s_nssai_local_nonprim : NULL,
		home_plmn_snssai ? home_plmn_snssai_local_nonprim : NULL,
		iwk_snssai ? iwk_snssai_local_nonprim : NULL,
		subject_to_ho ? true : false,
		subject_to_ho ? subject_to_ho->valueint : 0
		);

	return n2_sm_information_local_var;
end:
	if(n2_info_content_local_nonprim) {
		n2_info_content_free(n2_info_content_local_nonprim);
		n2_info_content_local_nonprim = NULL;
	}
	if(s_nssai_local_nonprim) {
		snssai_free(s_nssai_local_nonprim);
		s_nssai_local_nonprim = NULL;
	}
	if(home_plmn_snssai_local_nonprim) {
		snssai_free(home_plmn_snssai_local_nonprim);
		home_plmn_snssai_local_nonprim = NULL;
	}
	if(iwk_snssai_local_nonprim) {
		snssai_free(iwk_snssai_local_nonprim);
		iwk_snssai_local_nonprim = NULL;
	}
	return NULL;
}

n2_sm_information_t *n2_sm_information_copy(n2_sm_information_t *dst,
                                            n2_sm_information_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = n2_sm_information_convertToJSON(src);
	if(!item) {
		printf("n2_sm_information_convertToJSON() failed");
		return NULL;
	}

	content = cJSON_Print(item);
	cJSON_Delete(item);

	if(!content) {
		printf("cJSON_Print() failed");
		return NULL;
	}

	item = cJSON_Parse(content);
	free(content);
	if(!item) {
		printf("cJSON_Parse() failed");
		return NULL;
	}

	n2_sm_information_free(dst);
	dst = n2_sm_information_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
