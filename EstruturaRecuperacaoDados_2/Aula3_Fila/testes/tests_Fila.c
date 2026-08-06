// Inclui a biblioteca de entrada e saída
#include <stdio.h>
// Inclui a biblioteca de asserções para validação automatizada dos testes
#include <assert.h>
// Inclui a biblioteca de strings (caso necessário)
#include <string.h>

// Importa a interface do Core da Fila para executar os testes unitários
#include "../src/core/fila_core.h"

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
// Executor da Suíte de Testes Unitários
// -------------------------------------------------------------
int main() {
    // Cabeçalho da execução da suíte de testes
    printf("\n=== RODANDO SUÍTE DE TESTES UNITÁRIOS ===\n\n");
    
    // Executa o caso de teste 1
    test_createQueue();
    // Executa o caso de teste 2
    test_enqueue();
    // Executa o caso de teste 3
    test_dequeue();

    // Imprime a mensagem de sucesso total da suíte de testes
    printf("\n>>> TODOS OS TESTES PASSARAM COM SUCESSO! <<<\n\n");

    // Retorna 0 indicando sucesso da suíte
    return 0;
}
