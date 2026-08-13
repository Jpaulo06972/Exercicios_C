#include <stdlib.h>

#include <string.h>

#include <stdio.h>

#include "fila_core.h"

#include "error.h"

QueueNode* createNode(int value) {

    QueueNode* newNode = (QueueNode*) malloc(sizeof(QueueNode));

    if (newNode == NULL) {

        return NULL;
    }

    newNode->value = value;

    newNode->next = NULL;

    return newNode;
}

Queue* createQueue() {

    Queue* queue = (Queue*) malloc(sizeof(Queue));

    if (queue == NULL) {

        return NULL;
    }

    queue->head = NULL;

    queue->tail = NULL;

    queue->size = 0;

    return queue;
}

QueueStatus enqueue(Queue* queue, int value) {

    if (queue == NULL) {

        return ERR_QUEUE_NULL;
    }

    QueueNode* newNode = createNode(value);

    if (newNode == NULL) {

        return ERR_OUT_OF_MEMORY;
    }

    if (queue->head == NULL) {

        queue->head = newNode;

        queue->tail = newNode;

        queue->size++;

        return STATUS_SUCCESS;
    }

    queue->tail->next = newNode;

    queue->tail = newNode;

    queue->size++;

    return STATUS_SUCCESS;
}

QueueStatus dequeue(Queue* queue) {

    if (queue == NULL) {

        return ERR_QUEUE_NULL;
    }

    if (queue->head == NULL) {

        return ERR_QUEUE_EMPTY;
    }

    QueueNode* nodeToDelete = queue->head;

    if (nodeToDelete == queue->tail) {

        queue->head = NULL;

        queue->tail = NULL;
    } else {

        queue->head = queue->head->next;
    }

    free(nodeToDelete);

    queue->size--;

    return STATUS_SUCCESS;
}

QueueStatus destroyQueue(Queue* queue) {

    if (queue == NULL) {

        return ERR_QUEUE_NULL;
    }

    if (queue->head == NULL) {

        free(queue);

        return STATUS_SUCCESS;
    }

    QueueNode* currentNode = queue->head;

    QueueNode* nextNode = NULL;

    while (currentNode != NULL) {

        nextNode = currentNode->next;

        free(currentNode);

        currentNode = nextNode;
    }

    free(queue);

    return STATUS_SUCCESS;
}
