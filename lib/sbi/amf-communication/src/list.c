#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/list.h"
static lnode_t *listEntry_create(void *data)
{
    lnode_t *created = NULL;

    created = malloc(sizeof(lnode_t));

    if (created == NULL) {
        return NULL;
    }
    created->data = data;

    return created;
}

void lnode_free(lnode_t *listEntry, void *additionalData)
{
    free(listEntry);
}

void lnode_print(lnode_t *listEntry, void *additionalData)
{
    printf("%i\n", *((int *) (listEntry->data)));
}

list_t *list_create(void)
{
    list_t *createdList = malloc(sizeof(list_t));

    if (createdList == NULL) {
        return NULL;
    }
    createdList->first = NULL;
    createdList->last = NULL;
    createdList->count = 0;

    return createdList;
}

void list_iterate_forward(list_t *list,
        void (*operationToPerform)(
            lnode_t *, void *callbackFunctionUsedData),
        void *additionalDataNeededForCallbackFunction)
{
    lnode_t *current = list->first;
    lnode_t *next;

    if (current == NULL) {
        return;
    }

    next = current->next;

    operationToPerform(current, additionalDataNeededForCallbackFunction);
    current = next;

    while (current != NULL) {
        next = current->next;
        operationToPerform(current, additionalDataNeededForCallbackFunction);
        current = next;
    }
}

void list_iterate_backward(list_t *list,
         void (*operationToPerform)(
             lnode_t *, void *callbackFunctionUsedData),
         void *additionalDataNeededForCallbackFunction)
{
    lnode_t *current = list->last;
    lnode_t *next = current->prev;

    if (current == NULL) {
        return;
    }

    operationToPerform(current, additionalDataNeededForCallbackFunction);
    current = next;

    while (current != NULL) {
        next = current->prev;
        operationToPerform(current, additionalDataNeededForCallbackFunction);
        current = next;
    }
}

void list_free(list_t *list)
{
    if (list){
        list_iterate_forward(list, lnode_free, NULL);
        free(list);
    }
}

void list_clear(list_t *list)
{
    if (list) {
        list_iterate_forward(list, lnode_free, NULL);
        list->first = NULL;
        list->last = NULL;
        list->count = 0;
    }
}

void list_add(list_t *list, void *dataToAddInList)
{
    lnode_t *newListEntry = listEntry_create(dataToAddInList);
    if (newListEntry == NULL) {
        return;
    }
    if (list->first == NULL) {
        list->first = newListEntry;
        list->last = newListEntry;

        newListEntry->prev = NULL;
        newListEntry->next = NULL;

        list->count++;

        return;
    }

    list->last->next = newListEntry;
    newListEntry->prev = list->last;
    newListEntry->next = NULL;
    list->last = newListEntry;

    list->count++;
}

void list_insert_prev(list_t *list, lnode_t *lnode,
                              void *dataToAddInList)
{
    lnode_t *newListEntry = listEntry_create(dataToAddInList);
    if (newListEntry == NULL) {
        return;
    } else if (lnode->prev == NULL) {
        list->first = newListEntry;
        lnode->prev = newListEntry;
        newListEntry->prev = NULL;
        newListEntry->next = lnode;
    } else {
        lnode->prev->next = newListEntry;
        newListEntry->prev = lnode->prev;
        newListEntry->next = lnode;
        lnode->prev = newListEntry;
    }
    list->count++;
}

void list_remove(list_t *list, lnode_t *elementToRemove)
{
    lnode_t *elementBeforeElementToRemove = elementToRemove->prev;
    lnode_t *elementAfterElementToRemove = elementToRemove->next;

    if (elementBeforeElementToRemove != NULL) {
        elementBeforeElementToRemove->next = elementAfterElementToRemove;
    } else {
        list->first = elementAfterElementToRemove;
    }

    if (elementAfterElementToRemove != NULL) {
        elementAfterElementToRemove->prev = elementBeforeElementToRemove;
    } else {
        list->last = elementBeforeElementToRemove;
    }

    lnode_free(elementToRemove, NULL);

    list->count--;
}

lnode_t *list_find(list_t *list, long indexOfElement)
{
    lnode_t *current;
	int i;

    if ((list->count / 2) > indexOfElement) {
        current = list->first;

        for(i = 0; i < indexOfElement; i++) {
            current = current->next;
        }

        return current;
    } else {
        current = list->last;

        for(i = 1; i < (list->count - indexOfElement); i++) {
            current = current->prev;
        }

        return current;
    }
}

char *findStrInStrList(list_t *strList, const char *str)
{
    lnode_t *listEntry = NULL;

    if (!strList || !str) {
        return NULL;
    }

    list_for_each(strList, listEntry) {
        if (strstr((char*)listEntry->data, str) != NULL) {
            return (char*)listEntry->data;
        }
    }

    return NULL;
}

void clear_and_free_string_list(list_t *list)
{
    lnode_t *listEntry = NULL;

    if (!list) {
        return;
    }

    list_for_each(list, listEntry) {
        char *list_item = listEntry->data;
        free(list_item);
        list_item = NULL;
    }
    list_free(list);
}
