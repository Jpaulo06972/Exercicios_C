#include <stdlib.h>
#include <assert.h>
#include "lista_core.h"
#include "lista_remove.h"
#include "error.h"

Status removeFront(List* list){

    if (list == NULL) return ERR_LIST_NULL;

    if (list->head == NULL) return ERR_EMPTY_LIST;

    Book *toDelete = list->head;

    list->head = toDelete->nextNode;

    free(toDelete);

    list->size--;

    return STATUS_OK;
}

Status removeBack(List* list){

    if (list == NULL) return ERR_LIST_NULL;

    if (list->head == NULL) return ERR_EMPTY_LIST;

    if (list->head->nextNode == NULL)
    {
        free(list->head);
        list->head = NULL;
        list->size--;
        return STATUS_OK;
    }

    Book *current = list->head;

    while (current->nextNode->nextNode != NULL)
    {
        current = current->nextNode;
    }

    free(current->nextNode);

    current->nextNode = NULL;

    list->size--;

    return STATUS_OK;
}

Status removeOverPrice(List* list, float limit){

    if (list == NULL) return ERR_LIST_NULL;

    if (list->head == NULL) return ERR_EMPTY_LIST;

    Book *current = list->head;

    Book *prev = NULL;

    while (current != NULL)
    {

        if (current->price > limit)
        {

            Book *aux = current;

            if (prev == NULL)
            {
                list->head = current->nextNode;
                current = list->head;
            }

            else
            {
                prev->nextNode = current->nextNode;
                current = current->nextNode;
            }

            free(aux);
            list->size--;
        }
        else
        {

            prev = current;
            current = current->nextNode;
        }
    }

    return STATUS_OK;
}

Status freeList(List *list)
{

    if (list == NULL) return ERR_LIST_NULL;

    if (list->head == NULL)
    {
        free(list);
        return STATUS_OK;
    }

    Book *current = list->head;
    Book *nextNode = NULL;

    while (current != NULL)
    {

        nextNode = current->nextNode;
        free(current);

        current = nextNode;
    }

    free(list);
    return STATUS_OK;
}

Status removeDuplicateCode(List *list)
{

    if (list == NULL)
        return ERR_LIST_NULL;

    if (list->head == NULL)
        return ERR_EMPTY_LIST;

    Book *current = list->head;

    while (current != NULL)
    {

        Book *previous = current;

        Book *compare = current->nextNode;

        while (compare != NULL)
        {

            if (current->code == compare->code)
            {

                Book *toDelete = compare;

                compare = compare->nextNode;

                previous->nextNode = toDelete->nextNode;

                free(toDelete);

                list->size--;
            }
            else
            {

                previous = compare;

                compare = compare->nextNode;
            }
        }

        current = current->nextNode;
    }

    return STATUS_OK;
}
