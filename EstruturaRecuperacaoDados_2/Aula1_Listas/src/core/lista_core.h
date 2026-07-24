// Proteção contra inclusões repetidas do cabeçalho
#ifndef LISTA_CORE_H
#define LISTA_CORE_H

// --------------------------------------------- //
//               Definição de Estruturas
// --------------------------------------------- //

// Estrutura que representa cada elemento individual da lista encadeada (um livro).
// Funciona como um nó que armazena os dados do objeto e o ponteiro para o próximo item da sequência.
typedef struct Book{
    char name[50];         // Armazena o título do livro com um limite fixo para evitar estouro de buffer
    int code;              // Código identificador único do livro
    float price;           // Valor monetário do livro
    struct Book* nextNode; // Ponteiro autoreferenciado para encadear com o próximo nó (NULL caso seja o último)
} Book;

// Estrutura descritora/cabeçalho da lista encadeada.
// Encapsula o controle da estrutura, mantendo a referência do primeiro nó e o contador de elementos.
typedef struct List{
    Book* head;            // Ponteiro para o primeiro elemento da lista, permitindo percorrê-la do começo ao fim
    int size;              // Mantém a contagem atualizada de elementos para consulta em tempo constante O(1)
} List;

// --------------------------------------------- //
//          Protótipos do Módulo Core
// --------------------------------------------- //

// Aloca e inicializa os dados de um novo nó (Book) na memória heap
Book* createNewNode(const char* newName, int newCode, float newPrice);

// Aloca e inicializa a estrutura de controle da lista
List* createList();

#endif // LISTA_CORE_H
