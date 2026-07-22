// Guard contra inclusões repetidas
#ifndef LISTA_INSERT_H
#define LISTA_INSERT_H

#include "lista_core.h" // Importa as estruturas descritoras List e Book
#include "error.h"      // Importa a enumeração Status para padronizar os retornos de erro/sucesso

// --------------------------------------------- //
//       Protótipos de Inserção na Lista
// --------------------------------------------- //

// Insere um novo elemento no início da lista encadeada (complexidade O(1)).
// Retorna STATUS_OK se for bem-sucedido ou o código de erro apropriado.
Status insertFront(List* lista, char* newName, int newCodigo, float newPreco);

// Insere um novo elemento no final da lista encadeada (complexidade O(N)).
// Retorna STATUS_OK se for bem-sucedido ou o código de erro apropriado.
Status insertBack(List* lista, char* newName, int newCodigo, float newPreco);

#endif // LISTA_INSERT_H