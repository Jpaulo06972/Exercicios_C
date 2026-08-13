#ifndef INTERFACE_H
#define INTERFACE_H

#include "../core/lista_core.h"
#include "../core/error.h"

void handleStatus(Status st);

int validateInt(const char *message);

float validateFloat(const char *message);

void validateString(const char *message, char *buffer, int size);

Book* findBiggerPrice(List* list);

void menu(List* list);

#endif
