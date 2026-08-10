// Trava de inclusão do cabeçalho da interface
#ifndef INTERFACE_H
#define INTERFACE_H

// Inclui o cabeçalho do core para reconhecer as structs da árvore
#include "../core/arvore_core.h"
// Inclui o cabeçalho de erros para formatar o status visualmente
#include "../core/error.h"

// --------------------------------------------- //
//          Protótipos do Módulo de UI           //
// --------------------------------------------- //

// Traduz o enum TreeStatus em mensagem claras exibida no terminal
void handleStatus(TreeStatus status);

// Lê e valida um número inteiro positivo digitado pelo usuário, tratando entradas inválidas
int readPositiveInt(const char* prompt);

// Busca um elemento desejado na árvore e retorna o nó encontrado (ou NULL)
TreeNode* findABB(Tree* tree, int value);

// Conta a quantidade de nós na árvore
int countNode(TreeNode* root);

// Imprime todos os elementos da árvore em ordem
void dislpay(TreeNode* root);

// Acha o menor elemento da árvore
TreeNode* findSmallABB(Tree* tree);

// Executa o menu interativo no terminal
void runMenu(Tree* tree);

#endif // INTERFACE_H