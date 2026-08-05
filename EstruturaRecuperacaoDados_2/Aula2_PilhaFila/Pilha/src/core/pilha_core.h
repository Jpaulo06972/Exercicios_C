// Trava de segurança para impedir múltiplas inclusões deste cabeçalho
#ifndef PILHA_CORE_H
#define PILHA_CORE_H

// Importa a enumeração de status de erro/sucesso do sistema
#include "error.h"

// --------------------------------------------- //
//            Definições das Estruturas          //
// --------------------------------------------- //

// Estrutura que representa um nó individual dentro da pilha
typedef struct StackNode {
    int value;                 // Guarda o valor inteiro armazenado neste nó
    struct StackNode* next;    // Ponteiro para o próximo nó da pilha (NULL se for o último)
} StackNode;

// Estrutura principal (descritora) que gerencia o estado da pilha
typedef struct Stack {
    StackNode* head;           // Ponteiro para o primeiro nó (início/cabeça) da pilha
    int size;                  // Contador que mantém a quantidade atual de elementos na pilha
} Stack;

// --------------------------------------------- //
//          Protótipos das Funções do Core       //
// --------------------------------------------- //

// Aloca dinamicamente e inicializa um novo nó individual na memória heap
StackNode* createNode(int value);

// Aloca dinamicamente e inicializa a estrutura principal da pilha
Stack* createStack();

// Insere um novo elemento no início da pilha 
StackStatus push(Stack* stack, int value);

// Remove o elemento do início (topo) da pilha
StackStatus pop(Stack* stack);

// Desaloca todos os nós e libera a estrutura completa da pilha da memória
StackStatus destroyStack(Stack* stack);

#endif // PILHA_CORE_H