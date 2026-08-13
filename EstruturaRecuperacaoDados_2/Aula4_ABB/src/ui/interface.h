#ifndef INTERFACE_H
#define INTERFACE_H

#include "../core/arvore_core.h"

#include "../core/error.h"

void handleStatus(TreeStatus status);

int readPositiveInt(const char* prompt);

TreeNode* findABB(Tree* tree, int value);

int countNode(TreeNode* root);

void dislpay(TreeNode* root);

TreeNode* findSmallABB(Tree* tree);

void runMenu(Tree* tree);

#endif
