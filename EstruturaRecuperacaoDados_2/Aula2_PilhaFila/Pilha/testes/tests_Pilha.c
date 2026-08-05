// Inclui a biblioteca de entrada e saída
#include <stdio.h>
// Inclui a biblioteca de asserções para validação automatizada dos testes
#include <assert.h>
// Inclui a biblioteca de strings (caso necessário)
#include <string.h>

// Importa a interface do Core da Pilha para executar os testes unitários
#include "../src/core/pilha_core.h"

// -------------------------------------------------------------
// Teste 1: Validação de Inicialização da Pilha
// -------------------------------------------------------------
// Garante que a função de criação aloque a pilha zerada e com ponteiros em NULL.
void test_createStack(){

    // Instancia uma nova pilha através do Core
    Stack* stack = createStack();

    // Valida se o ponteiro retornado é diferente de NULL
    assert(stack != NULL);

    // Valida se a cabeça (topo) da pilha inicia como NULL
    assert(stack->head == NULL);

    // Valida se a contagem inicial de elementos é igual a 0
    assert(stack->size == 0);

    // Desaloca a memória utilizada durante o teste unitário
    destroyStack(stack);

    // Imprime mensagem de confirmação do teste
    printf("[PASSOU] - Teste de Criar Pilha\n");
}

// -------------------------------------------------------------
// Teste 2: Validação de Push 
// -------------------------------------------------------------
// Testa a inserção de múltiplos elementos no topo da pilha.
void test_push(){

    // Instancia uma nova pilha através do Core
    Stack* stack = createStack();

    // Insere o valor 25 -> Pilha: [25]
    push(stack, 25);
    // Valida se o tamanho foi alterado para 1
    assert(stack->size == 1);
    // Valida se o valor no topo da pilha é 25
    assert(stack->head != NULL);
    assert(stack->head->value == 25);
    
    // Insere o valor 10 -> Pilha: [10 -> 25]
    push(stack, 10);
    // Valida se o tamanho foi alterado para 2
    assert(stack->size == 2);
    // Valida se o valor no topo da pilha é 10
    assert(stack->head->value == 10);
    // Valida se o próximo valor da pilha é 25
    assert(stack->head->next != NULL);
    assert(stack->head->next->value == 25);
    
    // Insere o valor 34 -> Pilha: [34 -> 10 -> 25]
    push(stack, 34);
    // Valida se o tamanho foi alterado para 3
    assert(stack->size == 3);
    // Valida se o valor no topo da pilha é 34
    assert(stack->head->value == 34);
    // Valida se o segundo elemento é 10
    assert(stack->head->next != NULL);
    assert(stack->head->next->value == 10);
    // Valida se o terceiro elemento é 25
    assert(stack->head->next->next != NULL);
    assert(stack->head->next->next->value == 25);

    // Libera a memória da pilha de teste
    destroyStack(stack);

    // Imprime mensagem de confirmação do teste
    printf("[PASSOU] - Teste de Push\n");
}

// -------------------------------------------------------------
// Teste 3: Validação de Pop 
// -------------------------------------------------------------
// Garante que ao remover a cabeça/topo da pilha, o próximo nó se torna a nova cabeça.
void test_pop(){

    // Instancia uma nova pilha através do Core
    Stack* stack = createStack();

    // Insere 2 elementos na pilha: [40 -> 25]
    push(stack, 25);
    push(stack, 40);

    // Valida se o tamanho inicial é 2
    assert(stack->size == 2);

    // Remove o primeiro elemento do topo da pilha (40)
    pop(stack);

    // Valida se o tamanho reduziu para 1
    assert(stack->size == 1);

    // Valida se o valor 25 foi promovido ao novo topo da pilha
    assert(stack->head != NULL);
    assert(stack->head->value == 25);

    // Libera a memória da pilha de teste
    destroyStack(stack);

    // Imprime a mensagem de confirmação do teste
    printf("[PASSOU] - Teste de Pop\n");
}

// -------------------------------------------------------------
// Ponto de Entrada dos Testes (main)
// -------------------------------------------------------------
int main(){
    // Cabeçalho da execução da suíte de testes
    printf("\n=== RODANDO SUÍTE DE TESTES UNITÁRIOS ===\n\n");
    
    // Executa o caso de teste 1
    test_createStack();
    // Executa o caso de teste 2
    test_push();
    // Executa o caso de teste 3
    test_pop();

    // Imprime a mensagem de sucesso total da suíte de testes
    printf("\n>>> TODOS OS TESTES PASSARAM COM SUCESSO! <<<\n\n");

    // Retorna 0 indicando sucesso da suíte
    return 0;
}