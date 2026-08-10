// Inclui a biblioteca de entrada e saída
#include <stdio.h>
// Inclui a biblioteca de asserções para validação automatizada dos testes
#include <assert.h>
// Inclui a biblioteca de strings (caso necessário)
#include <string.h>

// Importa a interface do Core da Fila para executar os testes unitários
#include "../src/core/fila_core.h"
#include "../src/core/error.h"

// -------------------------------------------------------------
// Teste 1: Validação de Inicialização da Fila
// -------------------------------------------------------------
// Garante que a função de criação aloque a fila zerada e com ponteiros em NULL.
void test_createQueue() {

    // Instancia uma nova fila através do Core
    Queue* queue = createQueue();

    // Valida se o ponteiro retornado é diferente de NULL
    assert(queue != NULL);

    // Valida se a cabeça da fila inicia como NULL
    assert(queue->head == NULL);

    // Valida se a cauda da fila inicia como NULL
    assert(queue->tail == NULL);

    // Valida se a contagem inicial de elementos é igual a 0
    assert(queue->size == 0);

    // Desaloca a memória utilizada durante o teste unitário
    destroyQueue(queue);

    // Imprime mensagem de confirmação do teste
    printf("[PASSOU] - Teste de Criar Fila\n");
} 

// -------------------------------------------------------------
// Teste 2: Validação de Enfileiramento (Enqueue)
// -------------------------------------------------------------
// Testa a inserção de múltiplos elementos no final da fila.
void test_enqueue() {

    // Instancia uma nova fila através do Core
    Queue* queue = createQueue();

    // Insere o valor 25 -> Fila: [25]
    enqueue(queue, 25);
    // Valida se o tamanho subiu para 1
    assert(queue->size == 1);
    // Valida se o valor na cabeça da fila é 25
    assert(queue->head->value == 25);

    // Insere o valor 10 -> Fila: [25 -> 10]
    enqueue(queue, 10);
    // Valida se o tamanho subiu para 2
    assert(queue->size == 2);
    // Valida se a cabeça continua sendo 25
    assert(queue->head->value == 25);
    // Valida se o próximo nó contém o valor 10
    assert(queue->head->next->value == 10);

    // Insere o valor 34 -> Fila: [25 -> 10 -> 34]
    enqueue(queue, 34);
    // Valida se o tamanho subiu para 3
    assert(queue->size == 3);
    // Valida se a cabeça continua sendo 25
    assert(queue->head->value == 25);
    // Valida se o segundo elemento é 10
    assert(queue->head->next->value == 10);
    // Valida se a cauda (fim) da fila contém o valor 34
    assert(queue->tail->value == 34);

    // Libera a memória da fila de teste
    destroyQueue(queue);

    // Imprime mensagem de confirmação do teste
    printf("[PASSOU] - Teste de Enfileirar (Enqueue)\n");
}

// -------------------------------------------------------------
// Teste 3: Validação de Desenfileiramento (Dequeue)
// -------------------------------------------------------------
// Garante que ao remover a cabeça da fila, o próximo nó se torna a nova cabeça.
void test_dequeue() {

    // Instancia uma nova fila através do Core
    Queue* queue = createQueue(); 

    // Insere 2 elementos na fila: [25 -> 40]
    enqueue(queue, 25);
    enqueue(queue, 40);
    // Valida se o tamanho inicial é 2
    assert(queue->size == 2);

    // Remove o primeiro elemento da fila (25)
    dequeue(queue);

    // Valida se o tamanho reduziu para 1
    assert(queue->size == 1);
    // Valida se o valor 40 foi promovido a nova cabeça da fila
    assert(queue->head->value == 40);

    // Libera a memória da fila de teste
    destroyQueue(queue);

    // Imprime mensagem de confirmação do teste
    printf("[PASSOU] - Teste de Desenfileirar (Dequeue)\n");
}

// -------------------------------------------------------------
// Teste 4 (Erro): Validação de Operações com Ponteiro Nulo (ERR_QUEUE_NULL)
// -------------------------------------------------------------
// Testa a robustez ao tentar operar com uma fila nula (NULL).
void test_queueErrors_NullPointer(){

    // Testa enqueue em ponteiro NULL
    assert(enqueue(NULL, 10) == ERR_QUEUE_NULL);

    // Testa dequeue em ponteiro NULL
    assert(dequeue(NULL) == ERR_QUEUE_NULL);

    // Testa destroyQueue em ponteiro NULL
    assert(destroyQueue(NULL) == ERR_QUEUE_NULL);

    printf("[PASSOU] - Teste de Erro: Ponteiro Nulo na Fila\n");
}

// -------------------------------------------------------------
// Teste 5 (Erro): Validação de Operação em Fila Vazia (ERR_QUEUE_EMPTY)
// -------------------------------------------------------------
// Testa a tentativa de desenfileiramento (dequeue) em uma fila vazia.
void test_queueErrors_EmptyQueue(){

    Queue* queue = createQueue();

    // Tenta fazer dequeue em uma fila vazia
    assert(dequeue(queue) == ERR_QUEUE_EMPTY);

    // Adiciona e remove um elemento para desocupar a fila
    enqueue(queue, 100);
    assert(dequeue(queue) == STATUS_SUCCESS);

    // Tenta fazer dequeue novamente na fila desocupada
    assert(dequeue(queue) == ERR_QUEUE_EMPTY);

    destroyQueue(queue);
    printf("[PASSOU] - Teste de Erro: Fila Vazia (Underflow)\n");
}

// -------------------------------------------------------------
// Executor da Suíte de Testes Unitários
// -------------------------------------------------------------
int main() {
    // Cabeçalho da execução da suíte de testes
    printf("\n=== RODANDO SUÍTE DE TESTES UNITÁRIOS DA FILA ===\n\n");
    
    // Executa os testes de uso normal
    test_createQueue();
    test_enqueue();
    test_dequeue();

    // Executa os testes de cenários de erro / exceção
    test_queueErrors_NullPointer();
    test_queueErrors_EmptyQueue();

    // Imprime a mensagem de sucesso total da suíte de testes
    printf("\n>>> TODOS OS TESTES PASSARAM COM SUCESSO! <<<\n\n");

    // Retorna 0 indicando sucesso da suíte
    return 0;
}
