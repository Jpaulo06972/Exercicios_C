#include <stdlib.h>

#include <string.h>

#include <stdio.h>

#include "pilha_core.h"

#include "error.h"

StackNode* createNode(int value){

    StackNode* newNode = (StackNode*) malloc (sizeof(StackNode));

    if (newNode == NULL) return NULL;

    newNode->value = value;

    newNode->next = NULL;

    return newNode;
}

Stack* createStack(){

    Stack* stack = (Stack*) malloc (sizeof(Stack));

    if (stack == NULL) return NULL;

    stack->head = NULL;

    stack->size = 0;

    return stack;
}

StackStatus push(Stack* stack, int value){

    if (stack == NULL) return ERR_STACK_NULL;

    StackNode* newNode = createNode(value);

    if (newNode == NULL) return ERR_OUT_OF_MEMORY;

    newNode->next = stack->head;

    stack->head = newNode;

    stack->size++;

    return STATUS_SUCCESS;
}

StackStatus pop(Stack* stack){

    if (stack == NULL) return ERR_STACK_NULL;

    if (stack->size == 0 || stack->head == NULL) return ERR_STACK_EMPTY;

    StackNode* toDelete = stack->head;

    stack->head = toDelete->next;

    free(toDelete);

    stack->size--;

    return STATUS_SUCCESS;
}

StackStatus destroyStack(Stack* stack){

    if (stack == NULL) return ERR_STACK_NULL;

    StackNode* currentNode = stack->head;

    while (currentNode != NULL) {

        StackNode* toDelete = currentNode;

        currentNode = currentNode->next;

        free(toDelete);
    }

    free(stack);

    return STATUS_SUCCESS;
}
