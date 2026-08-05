// Inclui a biblioteca padrão para funções de entrada e saída
#include <stdio.h>

// Inclui a interface do Core para gerenciar a pilha
#include "core/pilha_core.h"
// Inclui a interface de usuário para rodar o menu interativo
#include "ui/interface.h"

// --------------------------------------------- //
//         Ponto de Entrada do Programa (main)   //
// --------------------------------------------- //
int main() {

    // Aloca dinamicamente e inicializa a estrutura da pilha
    Stack* myStack = createStack();

    // Valida se a pilha foi criada com sucesso na memória
    if (myStack != NULL) {

        // Inicia o fluxo principal passando o controle para a interface do menu
        runMenu(myStack);

        // Ao fechar o menu, garante a desalocação completa de todos os nós e da pilha
        destroyStack(myStack);

    } else {
        // Exibe mensagem de erro caso ocorra falha crítica de memória na inicialização
        printf("Erro Critico: Falha ao inicializar a pilha por falta de memoria.\n");
    }

    // Retorna 0 para indicar encerramento com sucesso para o sistema operacional
    return 0;
}