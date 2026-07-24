#include <stdio.h>
#include "core/lista_core.h"      // Módulo Core: Definição de estruturas e inicialização da lista
#include "core/lista_remove.h"   // Módulo Core: Funções de encerramento e liberação de memória
#include "ui/interface.h"          // Módulo UI: Interface interativa do usuário via terminal

// Ponto de entrada principal da aplicação
int main(){

    // Inicializa dinamicamente a estrutura de controle da lista de livros (camada Core)
    List* myList = createList();

    // Valida se a alocação de memória para o descritor da lista obteve sucesso
    if (myList != NULL){
        // Transfere o fluxo de controle para a interface do usuário (camada UI)
        menu(myList);
        
        // Ao encerrar o menu, garante a desalocação de todos os nós e do descritor (evita vazamentos de memória/memory leaks)
        freeList(myList);
    } else {
        // Exibe mensagem de erro no console caso ocorra falha crítica de memória na inicialização
        printf("Erro ao iniciar a lista.\n");
    }
    
    return 0; // Finaliza o programa indicando encerramento sem erros para o SO
}