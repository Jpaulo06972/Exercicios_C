#include <stdlib.h>
#include <string.h>
#include <assert.h>   
#include "lista_core.h" 

// --------------------------------------------- //
//             Função de Criar Nó (Book)
// --------------------------------------------- //
// Responsável por alocar dinamicamente a memória para um novo nó da lista e atribuir seus dados iniciais.
Book* createNewNo(char* newName, int newCodigo, float newPreco){

    // Aloca a quantidade necessária de bytes na Heap para armazenar um registro Book
    Book* newNo = (Book*)malloc(sizeof(Book));

    // Validação de segurança: se o SO não possuir memória suficiente, malloc retorna NULL
    if (newNo == NULL) {
        return NULL;
    }

    // Copia a string informada respeitando o tamanho máximo do vetor (50 chars),
    // garantindo que não ocorra estouro de memória (buffer overflow)
    strncpy(newNo->name, newName, 49);
    // Garante explicitamente que a string seja finalizada com o caractere nulo '\0'
    newNo->name[49] = '\0';

    // Atribui o código identificador ao nó recém-criado
    newNo->codigo = newCodigo;

    // Atribui o valor do preço do livro ao nó
    newNo->preco = newPreco;

    // Como o novo nó ainda não está conectado a nenhum outro elemento,
    // o ponteiro para o próximo nó é explicitamente inicializado como NULL
    newNo->nextNo = NULL;

    // Retorna o ponteiro para o bloco de memória configurado com sucesso
    return newNo;
}

// --------------------------------------------- //
//            Função de Criar Lista
// --------------------------------------------- //
// Instancia a estrutura descritora principal que gerencia o estado global da lista encadeada.
List* criarLista(){

    // Aloca o cabeçalho descritor da lista dinamicamente
    List* lista = (List*)malloc(sizeof(List));

    // Verifica se a alocação foi bem-sucedida para prevenir dereferência de ponteiro nulo
    if (lista == NULL) {
        return NULL;
    }

    // Inicializa o ponteiro de início apontando para NULL, indicando uma lista vazia
    lista->inicio = NULL;

    // Zera o contador de tamanho interno para manter a consistência dos dados
    lista->tamanho = 0;

    // Retorna a estrutura descritora pronta para uso
    return lista;
}