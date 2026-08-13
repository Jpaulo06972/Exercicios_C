#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct Livro{
    char titulo[50];
    int anoPublicacao;
    long isbn;
    struct Livro* next;
} Livro;

typedef struct Pilha{
    Livro* topo;
} Pilha;

Livro* criaNoLivro(char newTitulo[50], int newAno, long newIsbn){
    Livro* novoNo = (Livro*) malloc (sizeof(Livro));
    strcpy(novoNo->titulo, newTitulo);
    novoNo->anoPublicacao = newAno;
    novoNo->isbn = newIsbn;
    novoNo->next = NULL;
    return novoNo;
}

Pilha* empilhar(Pilha* P, char newTitulo[50], int newAno, long newIsbn){
    Livro* novoLivro = criaNoLivro(newTitulo, newAno, newIsbn);

    novoLivro->next = P->topo;

    P->topo = novoLivro;

    return P;
}

Pilha* desempilhar(Pilha* P){

    if(P->topo == NULL) {
        printf("\nA pilha esta vazia. Nao e possivel desempilhar.\n");
        return P;
    }

    Livro* temp = P->topo;

    P->topo = P->topo->next;

    printf("\nLivro '%s' (ISBN: %ld) removido do topo.\n", temp->titulo, temp->isbn);

    free(temp);

    return P;
}

int pilhaEstaVazia(Pilha* P){

    return (P->topo == NULL);
}

void imprimePilha(Pilha* P){
    Livro* current = P->topo;
    printf("\n========= PILHA DE LIVROS ATUAL =========\n");

    if (pilhaEstaVazia(P)) {
        printf("A pilha esta vazia.\n");
    }

    while(current != NULL){
        printf("Titulo: %s\n", current->titulo);
        printf("Ano: %d\n", current->anoPublicacao);
        printf("ISBN: %ld\n\n", current->isbn);
        current = current->next;
    }
    printf("===========================================\n");
}

void limpaPilha(Pilha* P){
    Livro* current = P->topo;

    while (current != NULL){
        Livro* temp = current;
        current = current->next;
        free(temp);
    }

    free(P);
}

void menu(){

    Pilha* minhaPilha = (Pilha*) malloc(sizeof(Pilha));
    minhaPilha->topo = NULL;

    int opcao = 0;

    do
    {

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
            case 1:
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

                minhaPilha = empilhar(minhaPilha, titulo, ano, isbn);

                printf("\nLivro '%s' adicionado ao topo da pilha.\n", titulo);
                break;
            }

            case 2:
            {
                printf("================================================================\n");
                printf("                   2 - Desempilhar Livro.                       \n");
                printf("================================================================\n");

                minhaPilha = desempilhar(minhaPilha);
                break;
            }

            case 3:
            {
                printf("================================================================\n");
                printf("                  3 - Mostrar Pilha Completa.                   \n");
                printf("================================================================\n");

                imprimePilha(minhaPilha);
                break;
            }

            case 4:
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
            case 5:
                printf("\nSaindo e limpando a memoria da pilha...\n");
                break;

            default:
                printf("\nValor Invalido. Digite Novamente.\n\n");
                break;
        }

    } while (opcao != 5);

    limpaPilha(minhaPilha);
}

int main(){
    menu();
    return 0;
}
