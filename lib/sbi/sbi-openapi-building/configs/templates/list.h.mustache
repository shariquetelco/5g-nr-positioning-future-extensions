#ifndef SBI_LIST_H
#define SBI_LIST_H

#include "../external/cJSON.h"
#include <stdbool.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct list_s list_t;

typedef struct lnode_s lnode_t;

struct lnode_s {
    lnode_t *next;
    lnode_t *prev;
    void *data;
};

typedef struct list_s {
    lnode_t *first;
    lnode_t *last;

    long count;
} list_t;

#define list_for_each(list, element) for(element = (list != NULL) ? (list)->first : NULL; element != NULL; element = element->next)
#define list_ForEach(element, list) for(element = (list != NULL) ? (list)->first : NULL; element != NULL; element = element->next)

/*NK: compatibility with older syntax generation*/
#define list_freeList list_free
#define list_addElement list_add
#define list_createList list_create

list_t *list_create(void);
void list_free(list_t *listToFree);
void list_clear(list_t *list);

void list_add(list_t *list, void *dataToAddInList);
void list_insert_prev(
    list_t *list, lnode_t *lnode, void *dataToAddInList);
lnode_t *list_find(list_t *list, long indexOfElement);
void list_remove(
    list_t *list, lnode_t *elementToRemove);

void list_iterate_forward(list_t *list,
        void (*operationToPerform)(lnode_t*, void*),
        void *additionalDataNeededForCallbackFunction);
void list_iterate_backward(list_t *list,
        void (*operationToPerform)(lnode_t*, void*),
        void *additionalDataNeededForCallbackFunction);

void lnode_print(lnode_t *listEntry, void *additionalData);
void lnode_free(lnode_t *listEntry, void *additionalData);

char *findStrInStrList(list_t *strList, const char *str);
void clear_and_free_string_list(list_t *list);

#ifdef __cplusplus
}
#endif

#endif // SBI_LIST_H
