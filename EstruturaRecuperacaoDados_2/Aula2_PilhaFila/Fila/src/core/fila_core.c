// Biblioteca padrão para alocação de memória dinâmica (malloc, free)
#include <stdlib.h>
// Biblioteca para manipulação de strings (se necessário)
#include <string.h>
// Biblioteca padrão de entrada e saída
#include <stdio.h>

// Inclui o cabeçalho com a estrutura da fila e protótipos das funções
#include "fila_core.h"
// Inclui as definições dos códigos de status de erro
#include "error.h"

// --------------------------------------------- //
//         Função para Criar um Novo Nó          //
// --------------------------------------------- //
// Aloca memória dinamicamente para um nó individual e atribui seu valor inicial.
QueueNode* createNode(int value) {

    // Aloca a memória na Heap com o tamanho exato da struct QueueNode
    QueueNode* newNode = (QueueNode*) malloc(sizeof(QueueNode));

    // Valida se o sistema conseguiu reservar a memória (se malloc retornar NULL)
    if (newNode == NULL) {
        // Retorna NULL para sinalizar falha de memória para quem chamou a função
        return NULL;
    }

    // Armazena o valor informado dentro do nó recém-criado
    newNode->value = value;

    // Define o ponteiro do próximo como NULL, pois o nó acabou de nascer solto
    newNode->next = NULL;

    // Retorna o ponteiro do nó criado e pronto para uso
    return newNode;
}

// --------------------------------------------- //
//       Função para Criar a Fila Principal      //
// --------------------------------------------- //
// Instancia a estrutura descritora que gerencia os ponteiros e o tamanho da fila.
Queue* createQueue() {

    // Aloca o espaço na memória Heap para o descritor da fila
    Queue* queue = (Queue*) malloc(sizeof(Queue));

    // Verifica se a alocação da estrutura descritora falhou
    if (queue == NULL) {
        // Retorna NULL indicando erro de memória ao inicializar
        return NULL;
    }

    // Inicializa o ponteiro de início (head) apontando para NULL (fila vazia)
    queue->head = NULL;

    // Inicializa o ponteiro de fim (tail) apontando para NULL (fila vazia)
    queue->tail = NULL;

    // Começa o contador de elementos da fila em 0
    queue->size = 0;

    // Retorna o ponteiro da fila criada e inicializada
    return queue;
}

// --------------------------------------------- //
//          Função de Enfileirar (Enqueue)       //
// --------------------------------------------- //
// Adiciona um novo elemento ao final (cauda) da fila.
QueueStatus enqueue(Queue* queue, int value) {

    // Valida se o ponteiro da fila recebido é válido
    if (queue == NULL) {
        // Retorna código de erro informando que a fila não existe na memória
        return ERR_QUEUE_NULL;
    }

    // Aloca a memória e cria o nó com o valor desejado
    QueueNode* newNode = createNode(value);

    // Valida se a criação do nó deu certo
    if (newNode == NULL) {
        // Retorna código de erro por falta de memória RAM
        return ERR_OUT_OF_MEMORY;
    }

    // Se a fila estiver vazia (head é NULL), o novo nó será o primeiro e único elemento
    if (queue->head == NULL) {
        // O início da fila passa a ser o novo nó
        queue->head = newNode;

        // O fim da fila também passa a ser o novo nó
        queue->tail = newNode;

        // Incrementa a contagem de elementos da fila
        queue->size++;

        // Retorna status de sucesso
        return STATUS_SUCCESS;
    }

    // Se a fila já tiver elementos, faz o último nó atual apontar para o novo nó
    queue->tail->next = newNode;

    // Atualiza o ponteiro de fim da fila para ser o novo nó recém-chegado
    queue->tail = newNode;

    // Incrementa a contagem de elementos na estrutura da fila
    queue->size++;

    // Retorna status de sucesso na operação
    return STATUS_SUCCESS;
}

// --------------------------------------------- //
//         Função de Desenfileirar (Dequeue)     //
// --------------------------------------------- //
// Remove o primeiro elemento do início (cabeça) da fila e desaloca sua memória.
QueueStatus dequeue(Queue* queue) {

    // Valida se o ponteiro da fila é válido
    if (queue == NULL) {
        // Retorna erro se a fila for nula
        return ERR_QUEUE_NULL;
    }

    // Impede a remoção caso a fila esteja vazia
    if (queue->head == NULL) {
        // Retorna erro informando que não há itens para remover
        return ERR_QUEUE_EMPTY;
    }

    // Guarda temporariamente a referência do nó que será excluído
    QueueNode* nodeToDelete = queue->head;

    // Se o elemento a ser removido for o único item da fila (head igual a tail)
    if (nodeToDelete == queue->tail) {
        // Reseta o ponteiro de início para NULL
        queue->head = NULL;

        // Reseta o ponteiro de fim para NULL
        queue->tail = NULL;
    } else {
        // Se houver mais elementos, avança o início para o próximo nó da sequência
        queue->head = queue->head->next;
    }

    // Libera a memória alocada do nó que foi removido
    free(nodeToDelete);

    // Diminui a contagem do tamanho da fila
    queue->size--;

    // Retorna status de sucesso
    return STATUS_SUCCESS;
}

// --------------------------------------------- //
//        Função para Destruir/Liberar a Fila    //
// --------------------------------------------- //
// Percorre a fila desalocando nó por nó e finaliza liberando a estrutura principal.
QueueStatus destroyQueue(Queue* queue) {

    // Verifica se a fila passada existe
    if (queue == NULL) {
        // Retorna erro se o ponteiro for nulo
        return ERR_QUEUE_NULL;
    }

    // Se a fila já estiver vazia, apenas libera o descritor principal
    if (queue->head == NULL) {
        // Libera a estrutura da fila
        free(queue);

        // Retorna sucesso
        return STATUS_SUCCESS;
    }

    // Ponteiro auxiliar para percorrer a lista a partir da cabeça
    QueueNode* currentNode = queue->head;

    // Ponteiro temporário para não perder a referência do próximo nó
    QueueNode* nextNode = NULL;

    // Laço que percorre nó por nó liberando a memória até chegar ao final
    while (currentNode != NULL) {

        // Salva o endereço do próximo elemento antes de apagar o atual
        nextNode = currentNode->next;

        // Libera a memória do nó atual
        free(currentNode);

        // Avança o ponteiro auxiliar para o próximo nó
        currentNode = nextNode;
    }

    // Apaga a estrutura descritora da fila após todos os nós serem liberados
    free(queue);

    // Retorna status de sucesso
    return STATUS_SUCCESS;
}