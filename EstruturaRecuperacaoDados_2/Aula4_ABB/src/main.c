#include <stdio.h>
#include "core/arvore_core.h"      // Módulo Core: Definição de estruturas e inicialização da árvore
#include "ui/interface.h"          // Módulo UI: Interface interativa do usuário via terminal

// Ponto de entrada principal da aplicação
int main() {

    // Instancia a estrutura descritora da Árvore Binária de Busca na Heap
    Tree* myTree = createTree();

    // Valida se a alocação de memória para o descritor da árvore obteve sucesso
    if (myTree != NULL){
        // Transfere o fluxo de controle para a interface do usuário (camada UI)
        menu(myTree);
        
        // Ao encerrar o menu, garante a desalocação de todos os nós e do descritor (evita vazamentos de memória/memory leaks)
        freeTree(myTree);
    } else {
        // Exibe mensagem de erro no console caso ocorra falha crítica de memória na inicialização
        printf("Erro ao iniciar a arvore.\n");
    }

    return 0; // Finaliza o programa indicando encerramento sem erros para o SO
}
