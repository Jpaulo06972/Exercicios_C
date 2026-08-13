#ifndef INTERFACE_H
#define INTERFACE_H

#include "../core/pilha_core.h"

#include "../core/error.h"

void handleStatus(StackStatus status);

int readPositiveInt(const char* prompt);

void displayStack(const Stack* stack);

void runMenu(Stack* stack);

#endif
