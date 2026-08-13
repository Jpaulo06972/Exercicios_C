#include <stdio.h>

#include <assert.h>

#include <string.h>

#include "../src/core/pilha_core.h"
#include "../src/core/error.h"

void test_createStack(){

    Stack* stack = createStack();

    assert(stack != NULL);

    assert(stack->head == NULL);

    assert(stack->size == 0);

    destroyStack(stack);

    printf("[PASSOU] - Teste de Criar Pilha\n");
}

void test_push(){

    Stack* stack = createStack();

    push(stack, 25);

    assert(stack->size == 1);

    assert(stack->head != NULL);
    assert(stack->head->value == 25);

    push(stack, 10);

    assert(stack->size == 2);

    assert(stack->head->value == 10);

    assert(stack->head->next != NULL);
    assert(stack->head->next->value == 25);

    push(stack, 34);

    assert(stack->size == 3);

    assert(stack->head->value == 34);

    assert(stack->head->next != NULL);
    assert(stack->head->next->value == 10);

    assert(stack->head->next->next != NULL);
    assert(stack->head->next->next->value == 25);

    destroyStack(stack);

    printf("[PASSOU] - Teste de Push\n");
}

void test_pop(){

    Stack* stack = createStack();

    push(stack, 25);
    push(stack, 40);

    assert(stack->size == 2);

    pop(stack);

    assert(stack->size == 1);

    assert(stack->head != NULL);
    assert(stack->head->value == 25);

    destroyStack(stack);

    printf("[PASSOU] - Teste de Pop\n");
}

void test_stackErrors_NullPointer(){

    assert(push(NULL, 10) == ERR_STACK_NULL);

    assert(pop(NULL) == ERR_STACK_NULL);

    assert(destroyStack(NULL) == ERR_STACK_NULL);

    printf("[PASSOU] - Teste de Erro: Ponteiro Nulo na Pilha\n");
}

void test_stackErrors_EmptyStack(){

    Stack* stack = createStack();

    assert(pop(stack) == ERR_STACK_EMPTY);

    push(stack, 100);
    assert(pop(stack) == STATUS_SUCCESS);

    assert(pop(stack) == ERR_STACK_EMPTY);

    destroyStack(stack);
    printf("[PASSOU] - Teste de Erro: Pilha Vazia (Underflow)\n");
}

int main(){

    printf("\n=== RODANDO SUÍTE DE TESTES UNITÁRIOS DA PILHA ===\n\n");

    test_createStack();
    test_push();
    test_pop();

    test_stackErrors_NullPointer();
    test_stackErrors_EmptyStack();

    printf("\n>>> TODOS OS TESTES PASSARAM COM SUCESSO! <<<\n\n");

    return 0;
}
