#ifndef SBI_ANY_TYPE_H
#define SBI_ANY_TYPE_H

#include "../external/cJSON.h"

#ifdef __cplusplus
extern "C" {
#endif

#define Invalid (0)
#define False  (1 << 0)
#define True   (1 << 1)
#define NULL   (1 << 2)
#define Number (1 << 3)
#define String (1 << 4)
#define Array  (1 << 5)
#define Object (1 << 6)
#define Raw    (1 << 7) /* raw json */

#define IsReference 256
#define StringIsConst 512

typedef struct any_type_s any_type_t;
typedef struct any_type_s {
    cJSON *json;
} any_type_t;

bool IsInvalid(const any_type_t * const item);
bool IsFalse(const any_type_t * const item);
bool IsTrue(const any_type_t * const item);
bool IsBool(const any_type_t * const item);
bool IsNull(const any_type_t * const item);
bool IsNumber(const any_type_t * const item);
bool IsString(const any_type_t * const item);
bool IsArray(const any_type_t * const item);
bool IsObject(const any_type_t * const item);
bool IsRaw(const any_type_t * const item);

any_type_t *any_type_create(cJSON *json);
any_type_t *any_type_parseFromJSON(cJSON *json);
cJSON *any_type_convertToJSON(any_type_t *any_type);

any_type_t *any_type_create_true(void);
any_type_t *any_type_create_false(void);
any_type_t *any_type_create_bool(bool boolean);
any_type_t *any_type_create_number(double num);
any_type_t *any_type_create_string(const char *string);
void any_type_free(any_type_t *any_type);

#ifdef __cplusplus
}
#endif

#endif /* SBI_ANY_TYPE_H */
