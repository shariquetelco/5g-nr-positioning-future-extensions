#include "any_type.h"

bool IsInvalid(const any_type_t * const item)
{
    return item && cJSON_IsInvalid(item->json);
}
bool IsFalse(const any_type_t * const item)
{
    return item && cJSON_IsFalse(item->json);
}
bool IsTrue(const any_type_t * const item)
{
    return item && cJSON_IsTrue(item->json);
}
bool IsBool(const any_type_t * const item)
{
    return item && cJSON_IsBool(item->json);
}
bool IsNull(const any_type_t * const item)
{
    return item && cJSON_IsNull(item->json);
}
bool IsNumber(const any_type_t * const item)
{
    return item && cJSON_IsNumber(item->json);
}
bool IsString(const any_type_t * const item)
{
    return item && cJSON_IsString(item->json);
}
bool IsArray(const any_type_t * const item)
{
    return item && cJSON_IsArray(item->json);
}
bool IsObject(const any_type_t * const item)
{
    return item && cJSON_IsObject(item->json);
}
bool IsRaw(const any_type_t * const item)
{
    return item && cJSON_IsRaw(item->json);
}

static any_type_t *any_create(cJSON *json) {
    any_type_t *any_type = NULL;

    if (!json) {
        return NULL;
    }

    any_type = calloc(1, sizeof(*any_type));
    if (!any_type) {
        cJSON_Delete(json);
    }
    any_type->json = json;

    return any_type;
}

any_type_t *any_type_create(cJSON *json) {
    any_type_t *any_type_local_var =
        any_create(cJSON_Duplicate(json, true));

    return any_type_local_var;
}

any_type_t *any_type_parseFromJSON(cJSON *json) {
    return any_type_create(json);
}

cJSON *any_type_convertToJSON(any_type_t *any_type) {
    cJSON *item = NULL;

    if (any_type == NULL) {
        printf("any_type_convertToJSON() failed [AnyType]");
        return NULL;
    }

    item = cJSON_Duplicate(any_type->json, true);
    if (item == NULL) {
        printf("any_type_convertToJSON() failed [AnyType]");
        return NULL;
    }

    return item;
}

any_type_t *any_type_create_true(void)
{
    return any_type_create_bool(true);
}

any_type_t *any_type_create_false(void)
{
    return any_type_create_bool(false);
}

any_type_t *any_type_create_bool(bool boolean)
{
    return any_create(boolean ? cJSON_CreateTrue() : cJSON_CreateFalse());
}

any_type_t *any_type_create_number(double num)
{
    return any_create(cJSON_CreateNumber(num));
}


any_type_t *any_type_create_string(const char *string)
{
    return any_create(cJSON_CreateString(string));
}

void any_type_free(any_type_t *any_type)
{
    if (any_type) {
        cJSON_Delete(any_type->json);
        free(any_type);
    }
}
