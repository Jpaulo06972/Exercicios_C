#include <stdlib.h>
#include <assert.h>
#include "lista_core.h"
#include "lista_insert.h"
#include "error.h"

// --------------------------------------------- //
//      Função Inserir no Início da Lista
// --------------------------------------------- //
// Insere um novo elemento na primeira posição da lista encadeada.
// Operação realizada em tempo constante O(1), pois não necessita percorrer a estrutura.
Status insertFront(List* list, char* newName, int newCode, float newPrice) {

    // Verifica se o ponteiro da estrutura da lista é válido para evitar falhas de segmentação
    if (list == NULL) return ERR_LIST_NULL;

    // Cria e aloca dinamicamente o novo nó com os dados informados
    Book* newBook = createNewNode(newName, newCode, newPrice);

    // Valida se a alocação de memória para o novo livro obteve sucesso
    if (newBook == NULL) return ERR_NO_MEMORY;

    // Atualiza o ponteiro do novo nó para apontar para o antigo primeiro nó da lista
    newBook->nextNode = list->head;

    // Redireciona o ponteiro de início do descritor para que o novo nó seja a nova cabeça da lista
    list->head = newBook;

    // Incrementa a contagem total de elementos cadastrados na lista
    list->size++;

    // Retorna código informando que a inserção ocorreu com sucesso
    return STATUS_OK;
} 

// --------------------------------------------- //
//      Função Inserir no Fim da Lista
// --------------------------------------------- //
// Insere um novo elemento no final da lista encadeada.
// Como não há ponteiro direto para o fim, requer navegação O(N) até o último nó.
Status insertBack(List* list, char* newName, int newCode, float newPrice) {
    
    // Confirma a existência do objeto lista recebido por parâmetro
    if (list == NULL) return ERR_LIST_NULL;

    // Aloca a memória e inicializa a struct do novo livro
    Book* newBook = createNewNode(newName, newCode, newPrice);
    if (newBook == NULL) return ERR_NO_MEMORY;

    // Caso de borda 1: Se a lista estiver vazia, o novo nó torna-se o primeiro elemento
    if (list->head == NULL) {
        list->head = newBook;
        list->size++;
        return STATUS_OK;
    }
    
    // Caso de borda 2: Se já existirem elementos, cria um ponteiro auxiliar para percorrer a lista
    Book* current = list->head;

    // Navega pela lista até que current alcance o nó cujo próximo ponteiro seja NULL (último nó atual)
    while (current->nextNode != NULL) {
        current = current->nextNode;
    }

    // Faz o encadeamento: o antigo último nó passa a apontar para o nó recém-criado
    current->nextNode = newBook;

    // Atualiza o tamanho global armazenado no descritor
    list->size++;

    return STATUS_OK;
}