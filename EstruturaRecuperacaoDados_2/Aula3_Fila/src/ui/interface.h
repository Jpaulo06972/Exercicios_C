#ifndef INTERFACE_H
#define INTERFACE_H

#include "../core/fila_core.h"

#include "../core/error.h"

void handleStatus(QueueStatus status);

int readPositiveInt(const char* prompt);

void displayQueue(const Queue* queue);

void runMenu(Queue* queue);

#endif
