#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "../src/core/arvore_core.h"
#include "../src/ui/interface.h"
#include "../src/core/error.h"

void test_createTree() {
    Tree* tree = createTree();
    assert(tree != NULL);
    assert(tree->root == NULL);

    freeTree(tree);
    printf("[PASSOU] - Teste Criar Arvore\n");
}

void test_insert() {
    Tree* tree = createTree();

    assert(insert(tree, 50) == STATUS_SUCCESS);
    assert(tree->root != NULL);
    assert(tree->root->value == 50);

    assert(insert(tree, 30) == STATUS_SUCCESS);
    assert(insert(tree, 70) == STATUS_SUCCESS);
    assert(insert(tree, 20) == STATUS_SUCCESS);
    assert(insert(tree, 40) == STATUS_SUCCESS);

    assert(tree->root->left->value == 30);
    assert(tree->root->right->value == 70);
    assert(tree->root->left->left->value == 20);
    assert(tree->root->left->right->value == 40);

    freeTree(tree);
    printf("[PASSOU] - Teste Insert Iterativo\n");
}

void test_insertRecursive() {
    Tree* tree = createTree();

    assert(insertRecursive(tree, 50) == STATUS_SUCCESS);
    assert(insertRecursive(tree, 30) == STATUS_SUCCESS);
    assert(insertRecursive(tree, 70) == STATUS_SUCCESS);
    assert(insertRecursive(tree, 20) == STATUS_SUCCESS);

    assert(tree->root->value == 50);
    assert(tree->root->left->value == 30);
    assert(tree->root->right->value == 70);
    assert(tree->root->left->left->value == 20);

    freeTree(tree);
    printf("[PASSOU] - Teste Insert Recursivo\n");
}

void test_removeTreeNode() {
    Tree* tree = createTree();

    insert(tree, 50);
    insert(tree, 30);
    insert(tree, 70);
    insert(tree, 20);
    insert(tree, 40);

    assert(removeTreeNode(tree, 20) == STATUS_SUCCESS);
    assert(findABB(tree, 20) == NULL);

    assert(removeTreeNode(tree, 30) == STATUS_SUCCESS);
    assert(findABB(tree, 30) == NULL);

    assert(removeTreeNode(tree, 50) == STATUS_SUCCESS);
    assert(findABB(tree, 50) == NULL);

    freeTree(tree);
    printf("[PASSOU] - Teste Remove Iterativo\n");
}

void test_removeRecursive() {
    Tree* tree = createTree();

    insert(tree, 50);
    insert(tree, 30);
    insert(tree, 70);
    insert(tree, 20);
    insert(tree, 40);

    assert(removeRecursive(tree, 20) == STATUS_SUCCESS);
    assert(findABB(tree, 20) == NULL);

    assert(removeRecursive(tree, 30) == STATUS_SUCCESS);
    assert(findABB(tree, 30) == NULL);

    assert(removeRecursive(tree, 50) == STATUS_SUCCESS);
    assert(findABB(tree, 50) == NULL);

    freeTree(tree);
    printf("[PASSOU] - Teste Remove Recursivo\n");
}

void test_findABB() {
    Tree* tree = createTree();

    insert(tree, 50);
    insert(tree, 30);
    insert(tree, 70);

    TreeNode* n50 = findABB(tree, 50);
    assert(n50 != NULL && n50->value == 50);

    TreeNode* n30 = findABB(tree, 30);
    assert(n30 != NULL && n30->value == 30);

    assert(findABB(tree, 999) == NULL);

    freeTree(tree);
    printf("[PASSOU] - Teste Find ABB\n");
}

void test_findSmallABB() {
    Tree* tree = createTree();

    insert(tree, 50);
    insert(tree, 30);
    insert(tree, 70);
    insert(tree, 15);

    TreeNode* small = findSmallABB(tree);
    assert(small != NULL && small->value == 15);

    freeTree(tree);
    printf("[PASSOU] - Teste Find Small ABB\n");
}

void test_countNode() {
    Tree* tree = createTree();
    assert(countNode(tree->root) == 0);

    insert(tree, 50);
    insert(tree, 30);
    insert(tree, 70);
    assert(countNode(tree->root) == 3);

    freeTree(tree);
    printf("[PASSOU] - Teste Count Node\n");
}

void test_treeErrors_NullPointer() {
    assert(insert(NULL, 10) == ERR_TREE_NULL);
    assert(insertRecursive(NULL, 10) == ERR_TREE_NULL);
    assert(removeTreeNode(NULL, 10) == ERR_TREE_NULL);
    assert(removeRecursive(NULL, 10) == ERR_TREE_NULL);
    assert(findABB(NULL, 10) == NULL);
    assert(findSmallABB(NULL) == NULL);

    printf("[PASSOU] - Teste de Erro: Ponteiro Nulo na Arvore\n");
}

void test_treeErrors_EmptyTree() {
    Tree* tree = createTree();

    assert(findABB(tree, 10) == NULL);
    assert(findSmallABB(tree) == NULL);
    assert(countNode(tree->root) == 0);
    assert(removeTreeNode(tree, 10) == ERR_INVALID_INPUT);
    assert(removeRecursive(tree, 10) == ERR_INVALID_INPUT);

    freeTree(tree);
    printf("[PASSOU] - Teste de Erro: Arvore Vazia\n");
}

void test_treeErrors_DuplicateValue() {
    Tree* tree = createTree();

    assert(insert(tree, 50) == STATUS_SUCCESS);
    assert(insert(tree, 50) == ERR_INVALID_INPUT);

    assert(insertRecursive(tree, 30) == STATUS_SUCCESS);
    assert(insertRecursive(tree, 30) == ERR_INVALID_INPUT);

    freeTree(tree);
    printf("[PASSOU] - Teste de Erro: Insercao Duplicada na Arvore\n");
}

void test_treeErrors_NonExistentNode() {
    Tree* tree = createTree();

    insert(tree, 50);
    insert(tree, 30);

    assert(removeTreeNode(tree, 999) == ERR_INVALID_INPUT);
    assert(removeRecursive(tree, 999) == ERR_INVALID_INPUT);

    freeTree(tree);
    printf("[PASSOU] - Teste de Erro: No Inexistente na Arvore\n");
}

int main() {
    printf("\n=== RODANDO SUÍTE DE TESTES UNITÁRIOS DA ÁRVORE ===\n\n");

    test_createTree();
    test_insert();
    test_insertRecursive();
    test_removeTreeNode();
    test_removeRecursive();
    test_findABB();
    test_findSmallABB();
    test_countNode();

    test_treeErrors_NullPointer();
    test_treeErrors_EmptyTree();
    test_treeErrors_DuplicateValue();
    test_treeErrors_NonExistentNode();

    printf("\n>>> TODOS OS TESTES PASSARAM COM SUCESSO! <<<\n\n");
    return 0;
}
