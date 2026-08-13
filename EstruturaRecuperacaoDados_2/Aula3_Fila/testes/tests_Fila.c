#include <stdio.h>

#include <assert.h>

#include <string.h>

#include "../src/core/fila_core.h"
#include "../src/core/error.h"

void test_createQueue() {

    Queue* queue = createQueue();

    assert(queue != NULL);

    assert(queue->head == NULL);

    assert(queue->tail == NULL);

    assert(queue->size == 0);

    destroyQueue(queue);

    printf("[PASSOU] - Teste de Criar Fila\n");
}

void test_enqueue() {

    Queue* queue = createQueue();

    enqueue(queue, 25);

    assert(queue->size == 1);

    assert(queue->head->value == 25);

    enqueue(queue, 10);

    assert(queue->size == 2);

    assert(queue->head->value == 25);

    assert(queue->head->next->value == 10);

    enqueue(queue, 34);

    assert(queue->size == 3);

    assert(queue->head->value == 25);

    assert(queue->head->next->value == 10);

    assert(queue->tail->value == 34);

    destroyQueue(queue);

    printf("[PASSOU] - Teste de Enfileirar (Enqueue)\n");
}

void test_dequeue() {

    Queue* queue = createQueue();

    enqueue(queue, 25);
    enqueue(queue, 40);

    assert(queue->size == 2);

    dequeue(queue);

    assert(queue->size == 1);

    assert(queue->head->value == 40);

    destroyQueue(queue);

    printf("[PASSOU] - Teste de Desenfileirar (Dequeue)\n");
}

void test_queueErrors_NullPointer(){

    assert(enqueue(NULL, 10) == ERR_QUEUE_NULL);

    assert(dequeue(NULL) == ERR_QUEUE_NULL);

    assert(destroyQueue(NULL) == ERR_QUEUE_NULL);

    printf("[PASSOU] - Teste de Erro: Ponteiro Nulo na Fila\n");
}

void test_queueErrors_EmptyQueue(){

    Queue* queue = createQueue();

    assert(dequeue(queue) == ERR_QUEUE_EMPTY);

    enqueue(queue, 100);
    assert(dequeue(queue) == STATUS_SUCCESS);

    assert(dequeue(queue) == ERR_QUEUE_EMPTY);

    destroyQueue(queue);
    printf("[PASSOU] - Teste de Erro: Fila Vazia (Underflow)\n");
}

int main() {

    printf("\n=== RODANDO SUÍTE DE TESTES UNITÁRIOS DA FILA ===\n\n");

    test_createQueue();
    test_enqueue();
    test_dequeue();

    test_queueErrors_NullPointer();
    test_queueErrors_EmptyQueue();

    printf("\n>>> TODOS OS TESTES PASSARAM COM SUCESSO! <<<\n\n");

    return 0;
}
