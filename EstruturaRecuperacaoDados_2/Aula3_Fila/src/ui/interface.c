#include <stdio.h>

#include <stdbool.h>

#include "../core/fila_core.h"

#include "interface.h"

void handleStatus(QueueStatus status) {

    switch (status) {

    case STATUS_SUCCESS:

        printf("\n[SUCESSO] Operacao realizada com sucesso!\n\n");

        break;

    case ERR_QUEUE_NULL:

        printf("\n[ERRO] A fila nao foi inicializada (ponteiro NULL)!\n\n");

        break;

    case ERR_OUT_OF_MEMORY:

        printf("\n[ERRO] Memoria RAM insuficiente para realizar a operacao!\n\n");

        break;

    case ERR_QUEUE_EMPTY:

        printf("\n[ERRO] A fila esta vazia! Nao ha itens para operar.\n\n");

        break;

    case ERR_INVALID_INPUT:

        printf("\n[ERRO] Valor ou parametro informado e invalido!\n\n");

        break;

    default:

        break;
    }
}

int readPositiveInt(const char* prompt) {

    int inputVal = 0;

    do {

        printf("%s", prompt);

        if (scanf("%d", &inputVal) == 1) {

            if (inputVal <= 0) {

                printf("\n[VALOR INVALIDO] Por favor, digite um valor maior que 0!\n");
            }
        } else {

            while (getchar() != '\n' && getchar() != EOF);

            inputVal = 0;
        }

    } while (inputVal <= 0);

    return inputVal;
}

void displayQueue(const Queue* queue) {

    if (queue == NULL) {

        printf("[ERRO] - A fila informada nao existe!\n");

        return;
    }

    if (queue->head == NULL) {

        printf("\n[INFO] A fila esta vazia!\n\n");

        return;
    }

    const QueueNode* currentNode = queue->head;

    printf("\nElementos da Fila: ");

    while (currentNode != NULL) {

        printf("%d -> ", currentNode->value);

        currentNode = currentNode->next;
    }

    printf("NULL\n\n");
}

void runMenu(Queue* queue) {

    int option = 0;

    int inputVal;

    QueueStatus status;

    do {

        printf("================================================================\n");
        printf("                              MENU                              \n");
        printf("1 - Enfileirar (Adicionar valor ao final da fila)               \n");
        printf("2 - Desenfileirar (Remover o primeiro valor da fila)            \n");
        printf("3 - Exibir os elementos da fila                                 \n");
        printf("4 - Sair do programa                                            \n");
        printf("================================================================\n");

        option = readPositiveInt("Digite a sua opcao: ");

        switch (option) {

            case 1: {

                printf("================================================================\n");
                printf("                1 - Enfileirar Novo Elemento                    \n");
                printf("================================================================\n");

                inputVal = readPositiveInt("Digite o valor para inserir: ");

                status = enqueue(queue, inputVal);

                handleStatus(status);

                break;
            }

            case 2: {

                printf("================================================================\n");
                printf("              2 - Desenfileirar Primeiro Elemento               \n");
                printf("================================================================\n");

                status = dequeue(queue);

                handleStatus(status);

                break;
            }

            case 3: {

                printf("================================================================\n");
                printf("              3 - Exibir Conteudo da Fila                       \n");
                printf("================================================================\n");

                displayQueue(queue);

                break;
            }

            case 4: {

                printf("\nSaindo do programa... Ate logo!\n\n");

                break;
            }

            default:

                printf("\nOpcao invalida! Digite um numero valido do menu.\n\n");

                break;
        }

    } while (option != 4);
}
