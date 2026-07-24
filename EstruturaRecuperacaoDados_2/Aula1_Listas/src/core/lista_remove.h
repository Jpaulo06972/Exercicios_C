// Guard contra inclusões duplicadas
#ifndef LISTA_REMOVE_H
#define LISTA_REMOVE_H

#include "lista_core.h" // Importa as estruturas descritoras List e Book
#include "error.h"      // Importa a enumeração de Status para retornos de validação

// --------------------------------------------- //
//      Protótipos das Funções de Remoção
// --------------------------------------------- //

// Remove o primeiro elemento da lista e desaloca sua memória em tempo O(1)
Status removeFront(List* list);

// Remove o último elemento da lista encadeada e desaloca sua memória em tempo O(N)
Status removeBack(List* list);

// Filtra a lista removendo todos os elementos que possuem preço estritamente superior ao valor limite
Status removeOverPrice(List* list, float limit);

// Filtra a lista removendo todos os livros com código de identificação duplicado
Status removeDuplicateCode(List* list);

// Percorre toda a estrutura liberando a memória de cada nó e, por fim, a memória da lista descritora
Status freeList(List* list);

#endif // LISTA_REMOVE_H