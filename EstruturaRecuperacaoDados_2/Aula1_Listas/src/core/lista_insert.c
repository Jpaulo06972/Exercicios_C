#include <stdlib.h>
#include <assert.h>
#include "lista_core.h"
#include "lista_insert.h"
#include "error.h"

Status insertFront(List* list, const char* newName, int newCode, float newPrice) {

    if (list == NULL) return ERR_LIST_NULL;

    Book* newBook = createNewNode(newName, newCode, newPrice);

    if (newBook == NULL) return ERR_NO_MEMORY;

    newBook->nextNode = list->head;

    list->head = newBook;

    list->size++;

    return STATUS_OK;
}

Status insertBack(List* list, const char* newName, int newCode, float newPrice) {

    if (list == NULL) return ERR_LIST_NULL;

    Book* newBook = createNewNode(newName, newCode, newPrice);
    if (newBook == NULL) return ERR_NO_MEMORY;

    if (list->head == NULL) {
        list->head = newBook;
        list->size++;
        return STATUS_OK;
    }

    Book* current = list->head;

    while (current->nextNode != NULL) {
        current = current->nextNode;
    }

    current->nextNode = newBook;

    list->size++;

    return STATUS_OK;
}
