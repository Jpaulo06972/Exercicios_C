// Trava de segurança para impedir múltiplas inclusões deste cabeçalho
#ifndef ARVORE_CORE_H
#define ARVORE_CORE_H

// Importa a enumeração de status de erro/sucesso do sistema
#include "error.h"

// --------------------------------------------- //
//            Definições das Estruturas          //
// --------------------------------------------- //

// Estrutura que representa um nó individual dentro da árvore
typedef struct TreeNode {
    int value;              // Guarda o valor inteiro armazenado neste nó
    struct TreeNode* left;  // Ponteiro para o próximo nó a esquerda da árvore
    struct TreeNode* right; // Ponteiro para o próximo nó a direita da árvore
} TreeNode;

// Estrutura principal que gerencia o estado da árvore
typedef struct Tree {
    TreeNode* root;  // Ponteiro para o nó raiz (início) da árvore
} Tree;

// --------------------------------------------- //
//          Protótipos das Funções do Core       //
// --------------------------------------------- //

// Aloca dinamicamente e incializa um novo nó individualmente na memória heap
TreeNode* createNode(int value);

// Aloca dinamicamente e inicializa a estrutura principal descritora da árvore
Tree* createTree();

// Insere um novo elemento na árvore
TreeStatus insert(Tree* tree, int value);

// Insere um novo elemento na árvore com recursividade
TreeStatus insertRecursive(Tree* tree, int value);

// Remove um elemento na árvore 
TreeStatus removeTreeNode(Tree* tree, int value);

// Remove um elemento na árvore com recursividade
TreeStatus removeRecursive(Tree* tree, int value);

// Libera a árvore
void freeTree(Tree* tree);

#endif // ARVORE_CORE_H