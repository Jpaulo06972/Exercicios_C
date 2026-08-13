#ifndef LISTA_INSERT_H
#define LISTA_INSERT_H

#include "lista_core.h"
#include "error.h"

Status insertFront(List* list, const char* newName, int newCode, float newPrice);

Status insertBack(List* list, const char* newName, int newCode, float newPrice);

#endif
