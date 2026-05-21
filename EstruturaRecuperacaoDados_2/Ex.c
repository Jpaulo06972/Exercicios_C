#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// --------------------------------------------- //
//               Criação dos STRUCT
// --------------------------------------------- //
typedef struct Book{
    char name[50];
    int codigo;
    float preco;
    Book* nextNo;
} Book;

typedef struct List{
    Book* inicio;
    int tamanho;
} List;

// --------------------------------------------- //
//             Função de Criar NO
// --------------------------------------------- //
Book* createNewNo(char newName,int newCodigo, float newPreco){

    Book* newNo = (Book*)malloc(sizeof(Book));
    strcpy(newNo->name, newName);
    newNo->codigo = newCodigo;
    newNo->preco = newPreco;
    newNo->nextNo = NULL;
    return newNo;
}

// --------------------------------------------- //
//            Função de Criar Lista
// --------------------------------------------- //
List* criarLista(){
    List* lista = (List*)malloc(sizeof(List));
    if(lista){
        lista->inicio = NULL;
        lista->tamanho = 0;
    }
    return lista;
}

// --------------------------------------------- //
//      Função Inserir no Inicio da Lista
// --------------------------------------------- //
void insertFront(List* lista){
    char newName[50];
    int newCodigo;
    float newPreco;

    printf("Digite o Nome: ");
    scanf(" %[^\n]", newName);
    printf("Digite o Codigo: ");
    scanf(" %d", &newCodigo);
    printf("Digite o Preco: ");
    scanf(" %f", &newPreco);

    Book* newBook = createNewNo(newName, newCodigo, newPreco);

    if(newBook){
        newBook->nextNo = lista->inicio;
        lista->inicio = newBook;
        lista->tamanho ++;
    }

} 

// --------------------------------------------- //
//            Função de Criar o Menu
// --------------------------------------------- //
void menu(){


    int opcao = 0;

    do
    {
        // Pede para usuario escolher a opção..
        printf("================================================================\n");
        printf("                              MENU                              \n");
        printf("1 - Cadastrar Livro. .                                          \n");
        printf("2 - Excluir Livro.                                              \n");
        printf("3 - Exibir Livros.                                              \n");
        printf("4 - Consultar Livro.          .                                 \n");
        printf("5 - Sair.                                                       \n");
        printf("================================================================\n");
        printf("Digite a opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            printf("================================================================\n");
            printf("                     1 - Cadastrar Livro.                     \n");
            printf("================================================================\n");
            break;
        }

        case 2:
        {
            printf("================================================================\n");
            printf("                      2 - Excluir Livro.                      \n");
            printf("================================================================\n");
            break;
        }

        case 3:
        {
            printf("================================================================\n");
            printf("                      3 - Exibir Livros.                      \n");
            printf("================================================================\n");
            break;
        }

        case 4:
        {
            printf("================================================================\n");
            printf("               4 - Consultar Livro pelo Codigo.                 \n");
            printf("================================================================\n");
            // Chamada da nova função
            break;
        }
        case 5:
            printf("Saindo...\n");
            break;        

        default:
            printf("Valor Invalido Digite Novamente\n\n");
            break;
        }

    } while (opcao != 5);


    return;

}

int main(){
    menu();
    return 0;
}