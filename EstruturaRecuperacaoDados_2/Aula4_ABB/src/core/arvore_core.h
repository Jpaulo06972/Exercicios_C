#ifndef ARVORE_CORE_H
#define ARVORE_CORE_H

#include "error.h"

typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct Tree {
    TreeNode* root;
} Tree;

TreeNode* createNode(int value);

Tree* createTree();

TreeStatus insert(Tree* tree, int value);

TreeStatus insertRecursive(Tree* tree, int value);

TreeStatus removeTreeNode(Tree* tree, int value);

TreeStatus removeRecursive(Tree* tree, int value);

void freeTree(Tree* tree);

#endif
