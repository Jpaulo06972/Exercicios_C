#ifndef LISTA_REMOVE_H
#define LISTA_REMOVE_H

#include "lista_core.h"
#include "error.h"

Status removeFront(List* list);

Status removeBack(List* list);

Status removeOverPrice(List* list, float limit);

Status removeDuplicateCode(List* list);

Status freeList(List* list);

#endif
