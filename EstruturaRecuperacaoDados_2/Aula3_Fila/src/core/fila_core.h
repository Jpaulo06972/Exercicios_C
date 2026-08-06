// Trava de segurança para impedir múltiplas inclusões deste cabeçalho
#ifndef FILA_CORE_H
#define FILA_CORE_H

// Importa a enumeração de status de erro/sucesso do sistema
#include "error.h"

// --------------------------------------------- //
//            Definições das Estruturas          //
// --------------------------------------------- //

// Estrutura que representa um nó individual dentro da fila
typedef struct QueueNode {
    int value;                 // Guarda o valor inteiro armazenado neste nó
    struct QueueNode* next;    // Ponteiro para o próximo nó da fila (NULL se for o último)
} QueueNode;

// Estrutura principal (descritora) que gerencia o estado da fila
typedef struct Queue {
    QueueNode* head;           // Ponteiro para o primeiro nó (início/cabeça) da fila
    QueueNode* tail;           // Ponteiro para o último nó (fim/cauda) da fila
    int size;                  // Contador que mantém a quantidade atual de elementos na fila
} Queue;

// --------------------------------------------- //
//          Protótipos das Funções do Core       //
// --------------------------------------------- //

// Aloca dinamicamente e inicializa um novo nó individual na memória heap
QueueNode* createNode(int value);

// Aloca dinamicamente e inicializa a estrutura principal descritora da fila
Queue* createQueue();

// Insere um novo elemento no final da fila (operação de Enqueue)
QueueStatus enqueue(Queue* queue, int value);

// Remove o primeiro elemento do início da fila (operação de Dequeue)
QueueStatus dequeue(Queue* queue);

// Desaloca todos os nós e libera a estrutura completa da fila da memória
QueueStatus destroyQueue(Queue* queue);

#endif // FILA_CORE_H