#ifndef PILHA_CORE_H
#define PILHA_CORE_H

#include "error.h"

typedef struct StackNode {
  int value;
  struct StackNode* next;
} StackNode;

typedef struct Stack {
  StackNode *head;
  int size;
} Stack;

StackNode *createNode(int value);

Stack *createStack();

StackStatus push(Stack *stack, int value);

StackStatus pop(Stack *stack);

StackStatus destroyStack(Stack *stack);

#endif
