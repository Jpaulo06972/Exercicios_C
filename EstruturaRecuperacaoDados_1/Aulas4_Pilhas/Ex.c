#include <stdio.h>  // Entrada e saída padrão (printf, scanf).
#include <stdlib.h> // Gerenciamento dinâmico de memória (malloc, free).
#include <string.h> // Manipulação de cadeias de caracteres (strcpy).
#include <stdbool.h>// Tipo booleano (bool, true, false).
#include <ctype.h>  // Funções de verificação de caracteres.

// Estrutura que representa o nó (elemento) da pilha, contendo as informações do livro.
typedef struct Livro{
    char titulo[50];       // Título do livro.
    int anoPublicacao;     // Ano de publicação do livro.
    long isbn;             // Código identificador único ISBN.
    struct Livro* next;    // Ponteiro para o livro empilhado imediatamente abaixo deste.
} Livro;

// Estrutura descritora da Pilha (guarda a referência para o elemento no TOPO).
// Pilhas seguem o comportamento LIFO (Last In, First Out) - o último a entrar é o primeiro a sair.
typedef struct Pilha{
    Livro* topo; // Ponteiro para o nó que está no topo da pilha.
} Pilha;

// Aloca dinamicamente na memória Heap um novo nó do tipo Livro.
Livro* criaNoLivro(char newTitulo[50], int newAno, long newIsbn){
    Livro* novoNo = (Livro*) malloc (sizeof(Livro));
    strcpy(novoNo->titulo, newTitulo);
    novoNo->anoPublicacao = newAno;
    novoNo->isbn = newIsbn;
    novoNo->next = NULL; // Como o nó é isolado na criação, seu próximo é iniciado como NULL.
    return novoNo;
}

// Operação PUSH: Empilha um novo elemento no TOPO da pilha.
// Complexidade O(1) - inserção constante no topo.
Pilha* empilhar(Pilha* P, char newTitulo[50], int newAno, long newIsbn){
    Livro* novoLivro = criaNoLivro(newTitulo, newAno, newIsbn);
    
    // O novo livro passa a apontar para o livro que era o antigo topo.
    novoLivro->next = P->topo;
    
    // O ponteiro de topo da estrutura da pilha é atualizado para o novo livro.
    P->topo = novoLivro;
    
    return P;
}

// Operação POP: Desempilha (remove) o elemento que está no TOPO da pilha.
// Complexidade O(1) - remoção constante do topo.
Pilha* desempilhar(Pilha* P){
    // Tratamento de pilha vazia (underflow): se não há topo, não é possível remover nada.
    if(P->topo == NULL) {
        printf("\nA pilha esta vazia. Nao e possivel desempilhar.\n");
        return P; 
    }
    
    // Guarda o ponteiro do topo atual temporariamente para poder liberá-lo.
    Livro* temp = P->topo; 
    
    // O topo da pilha avança para o elemento de baixo (next).
    P->topo = P->topo->next; 
    
    printf("\nLivro '%s' (ISBN: %ld) removido do topo.\n", temp->titulo, temp->isbn);
    
    // Desaloca a memória do nó removido.
    free(temp); 
    
    return P;
}

// Função utilitária que verifica se a pilha contém elementos.
int pilhaEstaVazia(Pilha* P){
    // A pilha é considerada vazia se o topo for nulo.
    return (P->topo == NULL); 
}

// Percorre e exibe todos os elementos da pilha a partir do topo até a base.
void imprimePilha(Pilha* P){
    Livro* current = P->topo; // Inicia a navegação a partir do topo da pilha.
    printf("\n========= PILHA DE LIVROS ATUAL =========\n");
    
    if (pilhaEstaVazia(P)) {
        printf("A pilha esta vazia.\n");
    }
    
    // Itera descendo nó a nó pela pilha.
    while(current != NULL){
        printf("Titulo: %s\n", current->titulo);
        printf("Ano: %d\n", current->anoPublicacao);
        printf("ISBN: %ld\n\n", current->isbn);
        current = current->next; // Move para o livro imediatamente abaixo.
    }
    printf("===========================================\n");
}

// Libera toda a memória ocupada pelos nós empilhados e pela própria estrutura descritora da pilha.
void limpaPilha(Pilha* P){
    Livro* current = P->topo;
    
    // Percorre cada elemento desempilhando e destruindo os nós.
    while (current != NULL){
        Livro* temp = current;
        current = current->next;
        free(temp);
    }
    // Libera a estrutura de controle da pilha.
    free(P); 
}

// Interface interativa do usuário via menu.
void menu(){
    // Aloca a estrutura principal da Pilha na Heap.
    Pilha* minhaPilha = (Pilha*) malloc(sizeof(Pilha));
    minhaPilha->topo = NULL; // Inicializa a pilha como vazia.

    int opcao = 0;

    do
    {
        // Exibição do menu
        printf("\n================================================================\n");
        printf("                MENU - PILHA DE LIVROS                  \n");
        printf("1 - Empilhar Livro (Push).                                  \n");
        printf("2 - Desempilhar Livro (Pop).                                \n");
        printf("3 - Mostrar Pilha Completa.                                 \n");
        printf("4 - Verificar se a pilha esta vazia.                        \n");
        printf("5 - Sair.                                                   \n");
        printf("================================================================\n");
        printf("Digite a opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1: // PUSH
            {
                printf("================================================================\n");
                printf("                     1 - Empilhar Livro.                        \n");
                printf("================================================================\n");
                char titulo[50];
                int ano;
                long isbn;
                
                printf("Digite o Titulo: ");
                scanf(" %[^\n]", titulo);
                printf("Digite o Ano de Publicacao: ");
                scanf(" %d", &ano);
                printf("Digite o ISBN (apenas numeros): ");
                scanf(" %ld", &isbn);
                
                // Insere o novo livro no topo da pilha.
                minhaPilha = empilhar(minhaPilha, titulo, ano, isbn);
                
                printf("\nLivro '%s' adicionado ao topo da pilha.\n", titulo);
                break;
            }

            case 2: // POP
            {
                printf("================================================================\n");
                printf("                   2 - Desempilhar Livro.                       \n");
                printf("================================================================\n");
                
                // Remove o livro do topo da pilha.
                minhaPilha = desempilhar(minhaPilha);
                break;
            }

            case 3: // Impressão
            {
                printf("================================================================\n");
                printf("                  3 - Mostrar Pilha Completa.                   \n");
                printf("================================================================\n");
                
                // Exibe a pilha do topo até a base.
                imprimePilha(minhaPilha);
                break;
            }

            case 4: // Verificação
            {
                printf("================================================================\n");
                printf("                4 - Verificar se a pilha esta vazia.            \n");
                printf("================================================================\n");
                
                if (pilhaEstaVazia(minhaPilha)) {
                    printf("\nA pilha ESTA VAZIA.\n");
                } else {
                    printf("\nA pilha NAO ESTA VAZIA.\n");
                }
                break;
            }
            case 5: // Encerramento
                printf("\nSaindo e limpando a memoria da pilha...\n");
                break;                

            default:
                printf("\nValor Invalido. Digite Novamente.\n\n");
                break;
        }

    } while (opcao != 5);
    
    // Libera os recursos alocados ao sair do sistema.
    limpaPilha(minhaPilha);
}

// Ponto de entrada do executável.
int main(){
    menu();
    return 0;
}