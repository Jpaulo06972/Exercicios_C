#ifndef FILA_CORE_H
#define FILA_CORE_H

#include "error.h"

typedef struct QueueNode {
    int value;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* head;
    QueueNode* tail;
    int size;
} Queue;

QueueNode* createNode(int value);

Queue* createQueue();

QueueStatus enqueue(Queue* queue, int value);

QueueStatus dequeue(Queue* queue);

QueueStatus destroyQueue(Queue* queue);

#endif
