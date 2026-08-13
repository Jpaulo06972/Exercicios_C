#include <stdio.h>

#include <stdbool.h>

#include "../core/arvore_core.h"

#include "interface.h"

void handleStatus(TreeStatus status){

    switch (status) {

        case STATUS_SUCCESS:

            printf("\n[SUCESSO] Operacao realizada com sucesso!\n\n");
            break;

        case ERR_TREE_NULL:

            printf("\n[ERRO] A arvore nao foi inicializada (ponteiro NULL)!\n\n");

            break;

        case ERR_OUT_OF_MEMORY:

            printf("\n[ERRO] Memoria RAM insuficiente para realizar a operacao!\n\n");

            break;

        case ERR_TREE_EMPTY:

            printf("\n[ERRO] A arvore esta vazia! Nao ha itens para operar.\n\n");

            break;

        case ERR_INVALID_INPUT:

            printf("\n[ERRO] Valor ou parametro informado eh invalido!\n\n");

            break;

        default:

            break;
    }
}

int readPositiveInt(const char* prompt){

    int inputVal = 0;

    do {

        printf("%s", prompt);

        if(scanf("%d", &inputVal) == 1){

            if (inputVal <= 0){

                printf("\n[VALOR INVALIDO] Por favor, digite um valor maior que 0!\n");
            }
        } else {

            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            inputVal = 0;
        }
    } while (inputVal <= 0);

    return inputVal;
}

TreeNode* findABB(Tree* tree, int value){

    if (tree == NULL) return NULL;

    TreeNode* current = tree->root;

    while (current != NULL) {

        if (current->value == value) return current;

        if (value > current->value){
            current = current->right;
        } else {
            current = current->left;
        }
    }

    return NULL;
}

int countNode(TreeNode* root){

    if (root != NULL){

        return (countNode(root->left) + countNode(root->right) + 1);
    }

    return 0;
}

void dislpay(TreeNode* root){

    if (root != NULL){

        dislpay(root->left);

        printf("%d -> ", root->value);

        dislpay(root->right);
    }
}

TreeNode* findSmallABB(Tree* tree){

    if (tree == NULL || tree->root == NULL) return NULL;

    TreeNode* current = tree->root;

    while (current->left != NULL) {

        current = current->left;
    }

    return current;
}

void runMenu(Tree* tree){

    int option = 0;

    int inputVal;

    TreeStatus status;

    do{

        printf("================================================================\n");
        printf("                              MENU                              \n");
        printf("1 - Inserir um Novo Valor na Árvore.                            \n");
        printf("2 - Inserir um Novo Valor na Árvore com Recursividade.          \n");
        printf("3 - Remover um Valor da Árvore.                                 \n");
        printf("4 - Remover um Valor da Árvore com Recursividade.               \n");
        printf("5 - Buscar um Valor na Árvore.                                  \n");
        printf("6 - Imprimir Todos os Elementos em Ordem.                       \n");
        printf("7 - Contar a Quantidade de Nós na Árvore.                       \n");
        printf("8 - Buscar o Menor Valor da Árvore.                             \n");
        printf("9 - Sair.                                                       \n");
        printf("================================================================\n");

        option = readPositiveInt("Digite a sua opcao: ");

        switch (option) {

            case 1: {

                printf("================================================================\n");
                printf("             1 - Inserir um Novo Valor na Árvore.               \n");
                printf("================================================================\n");

                inputVal = readPositiveInt("Digite o valor para inserir: ");

                status = insert(tree, inputVal);

                handleStatus(status);

                break;
            }

            case 2: {

                printf("================================================================\n");
                printf("     2 - Inserir um Novo Valor na Árvore com Recursividade.     \n");
                printf("================================================================\n");

                inputVal = readPositiveInt("Digite o valor para inserir: ");

                status = insertRecursive(tree, inputVal);

                handleStatus(status);

                break;
            }

            case 3: {

                printf("================================================================\n");
                printf("                 3 - Remover um Valor da Árvore.                \n");
                printf("================================================================\n");

                inputVal = readPositiveInt("Digite o valor para remover: ");

                status = removeTreeNode(tree, inputVal);

                handleStatus(status);

                break;
            }

            case 4: {

                printf("================================================================\n");
                printf("         4 - Remover um Valor da Árvore com Recursividade.      \n");
                printf("================================================================\n");

                inputVal = readPositiveInt("Digite o valor para remover: ");

                status = removeRecursive(tree, inputVal);

                handleStatus(status);

                break;
            }

            case 5: {

                printf("================================================================\n");
                printf("                  5 - Buscar um Valor na Árvore.                \n");
                printf("================================================================\n");

                inputVal = readPositiveInt("Digite o valor para buscar: ");

                TreeNode* foundNode = findABB(tree, inputVal);

                if (foundNode != NULL) {
                    printf("\n[SUCESSO] O valor %d foi ENCONTRADO na arvore!\n\n", foundNode->value);
                } else {
                    printf("\n[NAO ENCONTRADO] O valor %d NAO existe na arvore.\n\n", inputVal);
                }

                break;
            }

            case 6: {

                printf("================================================================\n");
                printf("             6 - Imprimir Todos os Elementos em Ordem.          \n");
                printf("================================================================\n");

                if (tree == NULL || tree->root == NULL) {
                    printf("\n[ARVORE VAZIA] Nao ha elementos para exibir.\n\n");
                } else {
                    printf("\nElementos da Arvore (Em Ordem): ");

                    dislpay(tree->root);
                    printf("NULL\n\n");
                }

                break;
            }

            case 7: {

                printf("================================================================\n");
                printf("             7 - Contar a Quantidade de Nós na Árvore.          \n");
                printf("================================================================\n");

                int totalNodes = countNode(tree == NULL ? NULL : tree->root);

                printf("\nA arvore possui um total de %d no(s).\n\n", totalNodes);

                break;
            }

            case 8: {

                printf("================================================================\n");
                printf("               8 - Buscar o Menor Valor da Árvore.              \n");
                printf("================================================================\n");

                TreeNode* smallNode = findSmallABB(tree);

                if (smallNode != NULL) {
                    printf("\n[SUCESSO] O menor valor na arvore eh: %d\n\n", smallNode->value);
                } else {
                    printf("\n[ARVORE VAZIA] A arvore nao possui elementos.\n\n");
                }

                break;
            }

            case 9: {

                printf("\nSaindo do programa... Ate logo!\n\n");

                break;
            }

            default: {

                printf("\nOpcao invalida! Digite um numero entre 1 e 9.\n\n");

                break;
            }
        }

    } while (option != 9);
}
