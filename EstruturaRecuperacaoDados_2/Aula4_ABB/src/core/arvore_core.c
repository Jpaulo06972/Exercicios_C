#include <stdlib.h>

#include <string.h>

#include <stdio.h>

#include "arvore_core.h"

#include "error.h"

TreeNode* createNode(int value){

    TreeNode* newNode = (TreeNode*) malloc (sizeof(TreeNode));

    if (newNode == NULL) return NULL;

    newNode->value = value;

    newNode->left  = NULL;

    newNode->right = NULL;

    return newNode;
}

Tree* createTree(){

    Tree* tree = (Tree*) malloc (sizeof(Tree));

    if (tree == NULL) return NULL;

    tree->root = NULL;

    return tree;
}

TreeStatus insert(Tree* tree, int value){

    if (tree == NULL) return ERR_TREE_NULL;

    TreeNode* newNode = createNode(value);

    if (newNode == NULL) return ERR_OUT_OF_MEMORY;

    if (tree->root == NULL){

        tree->root = newNode;

        return STATUS_SUCCESS;
    }

    TreeNode* current = tree->root;

    TreeNode* father  = NULL;

    while(current != NULL){

        father = current;

        if (current->value == value) {

            free(newNode);

            return ERR_INVALID_INPUT;
        }

        if (newNode->value < current->value){

            current = current->left;
        } else {

            current = current->right;
        }
    }

    if (newNode->value > father->value) {

        father->right = newNode;
    } else {

        father->left = newNode;
    }

    return STATUS_SUCCESS;
}

static TreeStatus insertNodeRecursive(TreeNode* root, TreeNode* newNode){

    if (newNode->value < root->value){

        if (root->left == NULL) {

            root->left = newNode;

            return STATUS_SUCCESS;
        }

        return insertNodeRecursive(root->left, newNode);

    } else if (newNode->value == root->value){

        free(newNode);

        return ERR_INVALID_INPUT;

    } else {

        if (root->right == NULL) {

            root->right = newNode;

            return STATUS_SUCCESS;
        }

        return insertNodeRecursive(root->right, newNode);
    }
}

TreeStatus insertRecursive(Tree* tree, int value){

    if (tree == NULL) return ERR_TREE_NULL;

    TreeNode* newNode = createNode(value);

    if (newNode == NULL) return ERR_OUT_OF_MEMORY;

    if (tree->root == NULL){

        tree->root = newNode;

        return STATUS_SUCCESS;
    }

    return insertNodeRecursive(tree->root, newNode);
}

TreeStatus removeTreeNode(Tree* tree, int value){

    if (tree == NULL) return ERR_TREE_NULL;

    TreeNode* current = tree->root;
    TreeNode* father  = NULL;

    while (current != NULL && current->value != value){

        father = current;

        if (value < current->value){
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (current == NULL) return ERR_INVALID_INPUT;

    if (current->left == NULL || current->right == NULL){

        TreeNode* aux = (current->left != NULL) ? current->left : current->right;

        if (father == NULL){

            tree->root = aux;

        } else if (father->left == current){

            father->left = aux;

        } else {

            father->right = aux;
        }

        free(current);

        return STATUS_SUCCESS;

    } else {

        TreeNode* successor = current->right;
        TreeNode* successorFather = current;

        while(successor->left != NULL){

            successorFather = successor;

            successor = successor->left;
        }

        if (successorFather != current){

            successorFather->left = successor->right;

            successor->right = current->right;
        }

        successor->left = current->left;

        if (father == NULL){

            tree->root = successor;
        } else if(father->left == current){

            father->left = successor;
        } else {

            father->right = successor;
        }

        free(current);

        return STATUS_SUCCESS;
    }
}

static TreeStatus removeNodeRecursive(Tree* tree, TreeNode* root, TreeNode* father, int value){

    if (root == NULL) {

        return ERR_INVALID_INPUT;
    }

    if (value < root->value) {

        return removeNodeRecursive(tree, root->left, root, value);

    } else if (value > root->value){

        return removeNodeRecursive(tree, root->right, root, value);
    }

    if (root->left == NULL || root->right == NULL){

        TreeNode* aux = (root->left != NULL) ? root->left : root->right;

        if (father == NULL){

            tree->root = aux;

        } else if (father->left == root){

            father->left = aux;

        } else {

            father->right = aux;
        }

        free(root);

        return STATUS_SUCCESS;

    } else {

        TreeNode* successor = root->right;
        TreeNode* successorFather = root;

        while(successor->left != NULL){

            successorFather = successor;

            successor = successor->left;
        }

        if (successorFather != root){

            successorFather->left = successor->right;

            successor->right = root->right;
        }

        successor->left = root->left;

        if (father == NULL){

            tree->root = successor;
        } else if(father->left == root){

            father->left = successor;
        } else {

            father->right = successor;
        }

        free(root);

        return STATUS_SUCCESS;
    }
}

TreeStatus removeRecursive(Tree* tree, int value){

    if (tree == NULL) return ERR_TREE_NULL;

    if (tree->root == NULL) return ERR_INVALID_INPUT;

    return removeNodeRecursive(tree, tree->root, NULL, value);
}

static void freeTreeNode(TreeNode* root){

    if (root != NULL) {

        freeTreeNode(root->left);

        freeTreeNode(root->right);

        free(root);
    }
}

void freeTree(Tree* tree){

    if (tree == NULL) return;

    if (tree->root != NULL){

        freeTreeNode(tree->root);
    }

    free(tree);
}
