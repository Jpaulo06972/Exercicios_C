#include <stdlib.h>
#include <string.h>
#include <assert.h>   
#include "lista_core.h" 

// --------------------------------------------- //
//             Função de Criar Nó (Book)
// --------------------------------------------- //
// Responsável por alocar dinamicamente a memória para um novo nó da lista e atribuir seus dados iniciais.
Book* createNewNode(char* newName, int newCode, float newPrice){

    // Aloca a quantidade necessária de bytes na Heap para armazenar um registro Book
    Book* newNode = (Book*)malloc(sizeof(Book));

    // Validação de segurança: se o SO não possuir memória suficiente, malloc retorna NULL
    if (newNode == NULL) {
        return NULL;
    }

    // Copia a string informada respeitando o tamanho máximo do vetor (50 chars),
    // garantindo que não ocorra estouro de memória (buffer overflow)
    strncpy(newNode->name, newName, 49);
    // Garante explicitamente que a string seja finalizada com o caractere nulo '\0'
    newNode->name[49] = '\0';

    // Atribui o código identificador ao nó recém-criado
    newNode->code = newCode;

    // Atribui o valor do preço do livro ao nó
    newNode->price = newPrice;

    // Como o novo nó ainda não está conectado a nenhum outro elemento,
    // o ponteiro para o próximo nó é explicitamente inicializado como NULL
    newNode->nextNode = NULL;

    // Retorna o ponteiro para o bloco de memória configurado com sucesso
    return newNode;
}

// --------------------------------------------- //
//            Função de Criar Lista
// --------------------------------------------- //
// Instancia a estrutura descritora principal que gerencia o estado global da lista encadeada.
List* createList(){

    // Aloca o cabeçalho descritor da lista dinamicamente
    List* list = (List*)malloc(sizeof(List));

    // Verifica se a alocação foi bem-sucedida para prevenir dereferência de ponteiro nulo
    if (list == NULL) {
        return NULL;
    }

    // Inicializa o ponteiro de início apontando para NULL, indicando uma lista vazia
    list->head = NULL;

    // Zera o contador de tamanho interno para manter a consistência dos dados
    list->size = 0;

    // Retorna a estrutura descritora pronta para uso
    return list;
}