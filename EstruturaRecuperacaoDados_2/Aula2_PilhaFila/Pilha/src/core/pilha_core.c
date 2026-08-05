// Biblioteca padrão para alocação de memória dinâmica (malloc, free)
#include <stdlib.h>
// Biblioteca para manipulação de strings (se necessário)
#include <string.h>
// Biblioteca padrão de entrada e saída
#include <stdio.h>

// Inclui o cabeçalho com a estrutura da pilha e protótipos das funções
#include "pilha_core.h"
// Inclui as definições dos códigos de status de erro
#include "error.h"

// --------------------------------------------- //
//         Função para Criar um Novo Nó          //
// --------------------------------------------- //
// Aloca memória dinamicamente para um nó individual e atribui seu valor inicial.
StackNode* createNode(int value){

    // Aloca a memória na Heap com o tamanho exato da struct StackNode
    StackNode* newNode = (StackNode*) malloc (sizeof(StackNode));

    // Valida se o sistema conseguiu reservar a memória (se o malloc retorna NULL)
    // Retorna NULL para sinalizar falha de memória para quem chamou a função
    if (newNode == NULL) return NULL;

    // Armazena o valor informado dentro do nó recém-criado
    newNode->value = value;

    // Define o ponteiro do próximo nó como NULL, pois quando criado ele não aponta pra nada
    newNode->next = NULL;

    // Retorna o ponteiro do nó criado e pronto pra uso
    return newNode;
}

// --------------------------------------------- //
//      Função para Criar a Pilha Principal      //
// --------------------------------------------- //
// Instancia a estrutura descritora que gerencia os ponteiros e o tamanho da pilha.
Stack* createStack(){

    // Aloca o espaço de memória Heap para o descritor da pilha.
    Stack* stack = (Stack*) malloc (sizeof(Stack));

    // Verifica se a alocação da estrutura descritora falhou
    if (stack == NULL) return NULL;

    // Inicializa o ponteiro do início da pilha vazio
    stack->head = NULL;

    // Inicializa o tamanho da pilha com 0
    stack->size = 0;

    // Retorna a pilha recém-criada
    return stack;
}

// --------------------------------------------- //
//                 Função de Push                //
// --------------------------------------------- //
// Adiciona um novo elemento ao topo da pilha.
StackStatus push(Stack* stack, int value){

    // Valida se o ponteiro da pilha recebido é válido
    // Retorna código de erro informando que a pilha não existe na memória
    if (stack == NULL) return ERR_STACK_NULL;

    // Aloca a memória e cria o nó com valor desejado
    StackNode* newNode = createNode(value);

    // Valida se a criação do nó deu certo
    // Retorna código de erro por falta de memória RAM.
    if (newNode == NULL) return ERR_OUT_OF_MEMORY;

    // Aponta o novo nó criado para o nó atual do topo da pilha
    newNode->next = stack->head;

    // Atualiza o topo da pilha para o novo nó criado
    stack->head = newNode;

    // Atualiza o tamanho da pilha 
    stack->size++;

    // Retorna o status de sucesso após adicionar um novo elemento com sucesso
    return STATUS_SUCCESS;
}

// --------------------------------------------- //
//                  Função de Pop                //
// --------------------------------------------- //
// Remove o elemento do topo (cabeça) da pilha e desaloca sua memória.
StackStatus pop(Stack* stack){

    // Valida se o ponteiro da pilha é válido
    // Caso o ponteiro da pilha seja NULL ele retorna erro 
    if (stack == NULL) return ERR_STACK_NULL;

    // Impede a remoção caso a pilha esteja vazia
    if (stack->size == 0 || stack->head == NULL) return ERR_STACK_EMPTY;

    // Guarda temporariamente a referência do nó no topo que será removido 
    StackNode* toDelete = stack->head;

    // Atualiza o topo da pilha para o próximo nó da sequência
    stack->head = toDelete->next;

    // Libera a memória alocada do nó que foi removido
    free(toDelete);

    // Diminui o tamanho da pilha
    stack->size--;

    // Retorna status de sucesso
    return STATUS_SUCCESS;
}

// --------------------------------------------- //
//       Função para Destruir/Liberar a Pilha    //
// --------------------------------------------- //
// Percorre a pilha desalocando nó por nó e finaliza liberando a estrutura principal.
StackStatus destroyStack(Stack* stack){

    // Verifica se a pilha existe
    // Retorna erro se o ponteiro for NULL
    if (stack == NULL) return ERR_STACK_NULL;

    // Ponteiro auxiliar para percorrer a pilha a partir do topo
    StackNode* currentNode = stack->head;

    // Percorre toda a pilha liberando a memória até chegar no fim
    while (currentNode != NULL) {

        // Cria toDelete para liberar o nó
        StackNode* toDelete = currentNode;

        // Atualiza o início da pilha para o próximo elemento
        currentNode = currentNode->next;

        // Libera o nó
        free(toDelete);
    }

    // Apaga a estrutura descritora da pilha após todos os nós serem liberados
    free(stack);

    // Retorna status de sucesso
    return STATUS_SUCCESS;      
}