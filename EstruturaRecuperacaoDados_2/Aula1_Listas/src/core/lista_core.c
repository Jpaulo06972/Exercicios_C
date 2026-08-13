#include <stdlib.h>
#include <string.h>
#include "lista_core.h"

Book* createNewNode(const char* newName, int newCode, float newPrice){

    Book* newNode = (Book*)malloc(sizeof(Book));

    if (newNode == NULL) {
        return NULL;
    }

    strncpy(newNode->name, newName, 49);

    newNode->name[49] = '\0';

    newNode->code = newCode;

    newNode->price = newPrice;

    newNode->nextNode = NULL;

    return newNode;
}

List* createList(){

    List* list = (List*)malloc(sizeof(List));

    if (list == NULL) {
        return NULL;
    }

    list->head = NULL;

    list->size = 0;

    return list;
}
