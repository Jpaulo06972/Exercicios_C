#include <stdio.h>

#include <stdbool.h>

#include "../core/pilha_core.h"

#include "interface.h"

void handleStatus(StackStatus status){

    switch (status) {

        case STATUS_SUCCESS:

            printf("\n[SUCESSO] Operacao realizada com sucesso!\n\n");
            break;

        case ERR_STACK_NULL:

            printf("\n[ERRO] A pilha nao foi inicializada (ponteiro NULL)!\n\n");

            break;

        case ERR_OUT_OF_MEMORY:

            printf("\n[ERRO] Memoria RAM insuficiente para realizar a operacao!\n\n");

            break;

        case ERR_STACK_EMPTY:

            printf("\n[ERRO] A pilha esta vazia! Nao ha itens para operar.\n\n");

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

void displayStack(const Stack* stack){

    if (stack == NULL){

        printf("[ERRO] - A pilha informada nao existe!");

        return;
    }

    if (stack->head == NULL){

        printf("\n[INFO] A pilha esta vazia!\n\n");

        return;
    }

    const StackNode* currentNode = stack->head;

    printf("\nElementos da pilha (Topo -> Base): ");

    while (currentNode != NULL){

        printf("%d -> ", currentNode->value);

        currentNode = currentNode->next;
    }

    printf("NULL\n\n");
}

void runMenu(Stack* stack){

    int option = 0;

    int inputVal;

    StackStatus status;

    do{

        printf("================================================================\n");
        printf("                              MENU                              \n");
        printf("1 - Push (Adicionar valor ao topo da pilha)                     \n");
        printf("2 - Pop (Remover o valor do topo da pilha)                      \n");
        printf("3 - Exibir os elementos da pilha                                \n");
        printf("4 - Sair do programa                                            \n");
        printf("================================================================\n");

        option = readPositiveInt("Digite a sua opcao: ");

        switch (option) {

            case 1: {

                printf("================================================================\n");
                printf("                 1 - Adicionar Novo Elemento                    \n");
                printf("================================================================\n");

                inputVal = readPositiveInt("Digite o valor para inserir: ");

                status = push(stack, inputVal);

                handleStatus(status);

                break;
            }

            case 2: {

                printf("================================================================\n");
                printf("                2 - Remover o Elemento do Topo                  \n");
                printf("================================================================\n");

                status = pop(stack);

                handleStatus(status);

                break;
            }

            case 3: {

                printf("================================================================\n");
                printf("                3 - Exibir Conteudo da Pilha                    \n");
                printf("================================================================\n");

                displayStack(stack);

                break;
            }

            case 4: {

                printf("\nSaindo do programa... Ate logo!\n\n");

                break;
            }

            default: {

                printf("\nOpcao invalida! Digite um numero valido do menu.\n\n");

                break;
            }
        }

    } while (option != 4);
}
