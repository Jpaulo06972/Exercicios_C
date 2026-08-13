#include <stdio.h>
#include <stdbool.h>
#include "interface.h"
#include "../core/lista_core.h"
#include "../core/lista_insert.h"
#include "../core/lista_remove.h"
#include "../core/error.h"

void handleStatus(Status st) {
    switch (st) {
        case STATUS_OK:
            printf("\n[SUCESSO] Operacao realizada com sucesso!\n\n");
            break;
        case ERR_LIST_NULL:
            printf("\n[ERRO] A lista enviada nao foi inicializada (ponteiro NULL)!\n\n");
            break;
        case ERR_NO_MEMORY:
            printf("\n[ERRO] Memoria RAM insuficiente para realizar a operacao!\n\n");
            break;
        case ERR_EMPTY_LIST:
            printf("\n[AVISO] A lista esta vazia! Nao ha itens para operar.\n\n");
            break;
        case ERR_INVALID_PARAM:
            printf("\n[ERRO] Parametro informado e invalido!\n\n");
            break;
        default:
            printf("\n[ERRO] Ocorreu um erro desconhecido!\n\n");
            break;
    }
}

int validateInt(const char *message) {
    int num = 0;

    do {
        printf("%s", message);

        if (scanf("%d", &num) == 1) {
            if (num <= 0) {
               printf("\nVALOR INVALIDO - Digite um valor maior que 0!\n");
            }
        } else {

            while (getchar() != '\n');
            num = 0;
            printf("\nVALOR INVALIDO - Digite apenas numeros!\n");
        }

    } while (num <= 0);

    return num;
}

float validateFloat(const char *message) {
    float num = 0;

    do {
        printf("%s", message);

        if (scanf("%f", &num) == 1) {
            if (num <= 0) {
               printf("\nVALOR INVALIDO - Digite um valor maior que 0!\n");
            }
        } else {

            while (getchar() != '\n');
            num = 0;
            printf("\nVALOR INVALIDO - Digite apenas numeros!\n");
        }

    } while (num <= 0);

    return num;
}

void validateString(const char *message, char *buffer, int size) {
    char format[20];
    snprintf(format, sizeof(format), " %%%d[^\n]", size - 1);

    do {
        printf("%s", message);
        if (scanf(format, buffer) == 1) {
            break;
        } else {
            while (getchar() != '\n');
            printf("\nVALOR INVALIDO - Digite um texto valido!\n");
        }
    } while (1);
}

Book* findBiggerPrice(List* list){

    if (list == NULL) return NULL;

    if (list->head == NULL) return NULL;

    Book* current = list->head;

    Book* biggerPrice = current;

    while (current != NULL){

        if (biggerPrice->price < current->price){
            biggerPrice = current;
        }

        current = current->nextNode;
    }

    return biggerPrice;
}

void menu(List* list){
    int option = 0;

    char tempName[50];
    int tempCode;
    float tempPrice;
    Book* tempBook = NULL;
    Status opStatus;

    do {

        printf("================================================================\n");
        printf("                              MENU                              \n");
        printf("1 - Cadastrar Livro no Inicio da Lista.                         \n");
        printf("2 - Cadastrar Livro no Fim da Lista.                            \n");
        printf("3 - Excluir Livro do Inicio da Lista.                           \n");
        printf("4 - Excluir Livro do Fim da Lista.                              \n");
        printf("5 - Excluir Livros Acima do Preço na Lista.                     \n");
        printf("6 - Exibir Livro com Maior Preço da Lista.                      \n");
        printf("7 - Excluir Livros com Codigos Duplicados na Lista.             \n");
        printf("8 - Sair.                                                       \n");
        printf("================================================================\n");
        option = validateInt("Digite sua opcao: ");

        switch (option) {
            case 1: {
                printf("================================================================\n");
                printf("               1 - Cadastrar Livro Inicio da Lista              \n");
                printf("================================================================\n");

                validateString("Digite o nome do livro: ", tempName, sizeof(tempName));
                tempCode = validateInt("A seguir digite o codigo: ");
                tempPrice = validateFloat("A seguir digite o preco: ");

                opStatus = insertFront(list, tempName, tempCode, tempPrice);
                handleStatus(opStatus);
                break;
            }

            case 2: {
                printf("================================================================\n");
                printf("               2 - Cadastrar Livro Fim da Lista                 \n");
                printf("================================================================\n");

                validateString("Digite o nome do livro: ", tempName, sizeof(tempName));
                tempCode = validateInt("A seguir digite o codigo: ");
                tempPrice = validateFloat("A seguir digite o preco: ");

                opStatus = insertBack(list, tempName, tempCode, tempPrice);
                handleStatus(opStatus);
                break;
            }

            case 3: {
                printf("================================================================\n");
                printf("             3 - Excluir Livro do Inicio da Lista.              \n");
                printf("================================================================\n");

                opStatus = removeFront(list);
                handleStatus(opStatus);
                break;
            }

            case 4: {
                printf("================================================================\n");
                printf("               4 - Excluir Livro do Fim da Lista.               \n");
                printf("================================================================\n");

                opStatus = removeBack(list);
                handleStatus(opStatus);
                break;
            }

            case 5: {
                printf("================================================================\n");
                printf("          5 - Excluir Livros Acima do Preço na Lista            \n");
                printf("================================================================\n");

                tempPrice = validateFloat("Digite o preco limite: ");
                opStatus = removeOverPrice(list, tempPrice);
                handleStatus(opStatus);
                break;
            }

            case 6: {
                printf("================================================================\n");
                printf("          6 - Exibir Livro com Maior Preço da Lista             \n");
                printf("================================================================\n");

                tempBook = findBiggerPrice(list);

                if (tempBook != NULL) {
                    printf("\n--- Livro com Maior Preco ---\n");
                    printf("Titulo: %s\n", tempBook->name);
                    printf("Codigo: %d\n", tempBook->code);
                    printf("Preco: R$ %.2f\n", tempBook->price);
                } else {
                    printf("A lista de livros esta vazia.\n");
                }
                break;
            }

            case 7: {
                printf("================================================================\n");
                printf("      7 - Excluir Livros com Codigos Duplicados na Lista.       \n");
                printf("================================================================\n");

                opStatus = removeDuplicateCode(list);
                handleStatus(opStatus);
                break;
            }

            case 8: {
                printf("\nSaindo do programa...\n\n");
                break;
            }

            default: {
                printf("\nOpção Invalida! Digite Novamente.\n\n");
                break;
            }
        }

    } while (option != 8);
}
