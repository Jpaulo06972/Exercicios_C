#include <stdio.h>
#include <stdbool.h>
#include "interface.h"
#include "../core/lista_core.h"
#include "../core/lista_insert.h"
#include "../core/lista_remove.h"
#include "../core/error.h"

// --------------------------------------------- //
//        Tratamento e Exibição de Status
// --------------------------------------------- //
// Traduz os códigos de status de erro/sucesso retornados pela camada lógica (Core)
// em mensagens amigáveis exibidas no terminal para o usuário final.
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

// --------------------------------------------- //
//             Valida Número Inteiro
// --------------------------------------------- //
// Garante a leitura correta de um número inteiro positivo do stdin, exibindo mensagem personalizada.
// Trata o estouro/erro de tipo limpando o buffer do teclado (previne loops infinitos se o usuário digitar texto).
int validateInt(const char *message) {
    int num = 0;

    do {
        printf("%s", message);
        // scanf retorna 1 quando consegue converter a entrada para inteiro com sucesso
        if (scanf("%d", &num) == 1) {
            if (num <= 0) {
               printf("\nVALOR INVALIDO - Digite um valor maior que 0!\n");
            }
        } else {
            // Se a leitura falhar (ex: usuário digitou letras), consome os caracteres residuais do buffer até a quebra de linha
            while (getchar() != '\n');
            num = 0; // Força permanecer no laço do-while
            printf("\nVALOR INVALIDO - Digite apenas numeros!\n"); 
        }
    
    } while (num <= 0); // Repete a solicitação até obter um inteiro estritamente positivo
    
    return num;
}

// --------------------------------------------- //
//             Valida Número Real (Float)
// --------------------------------------------- //
// Garante a leitura sanitizada de um valor em ponto flutuante maior que zero, exibindo mensagem personalizada.
float validateFloat(const char *message) {
    float num = 0;

    do {
        printf("%s", message);
        // Verifica se a conversão para float foi bem-sucedida
        if (scanf("%f", &num) == 1) {
            if (num <= 0) {
               printf("\nVALOR INVALIDO - Digite um valor maior que 0!\n");
            }
        } else {
            // Esvazia o buffer de entrada para evitar travamentos decorrentes de entradas não numéricas
            while (getchar() != '\n');
            num = 0;
            printf("\nVALOR INVALIDO - Digite apenas numeros!\n"); 
        }
    
    } while (num <= 0);
    
    return num;
}

// --------------------------------------------- //
//                 Valida String
// --------------------------------------------- //
// Garante a leitura segura e sanitizada de uma string não vazia do stdin, exibindo mensagem personalizada.
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

// --------------------------------------------- //
//         Achar o Livro com Maior Preço
// --------------------------------------------- //
Book* findBiggerPrice(List* list){
    
    // Validação da lista instanciada
    if (list == NULL) return NULL;

    // Retorna erro caso a lista esteja totalmente vazia
    if (list->head == NULL) return NULL;

    // Ponteiro de varredura atual
    Book* current = list->head;

    // Cria o ponteiro do livro com maior preço
    Book* biggerPrice = current;

    while (current != NULL){

        if (biggerPrice->price < current->price){
            biggerPrice = current;
        }

        current = current->nextNode;
    }

    return biggerPrice;
}

// --------------------------------------------- //
//            Menu Principal Interativo
// --------------------------------------------- //
// Renderiza o menu de opções no console e faz a integração entre as entradas do usuário e as operações do Core.
void menu(List* list){
    int option = 0;

    // Buffer e variáveis temporárias para armazenar os dados digitados antes de criar o objeto Book
    char tempName[50];
    int tempCode;
    float tempPrice;
    Book* tempBook = NULL;
    Status opStatus; // Armazena a resposta de erro/sucesso retornada pela camada lógica

    do {
        // Exibição do cabeçalho visual do menu
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

                // Executa a inserção no início e direciona o código de retorno para formatação de UI
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

                // Executa a inserção no fim e repassa o retorno de status para a UI
                opStatus = insertBack(list, tempName, tempCode, tempPrice);
                handleStatus(opStatus);
                break;
            }

            case 3: {
                printf("================================================================\n");
                printf("             3 - Excluir Livro do Inicio da Lista.              \n");
                printf("================================================================\n");
                
                // Solicita a remoção da cabeça da lista e exibe o feedback correspondente
                opStatus = removeFront(list); 
                handleStatus(opStatus);
                break;
            }

            case 4: {
                printf("================================================================\n");
                printf("               4 - Excluir Livro do Fim da Lista.               \n");
                printf("================================================================\n");
                
                // Solicita a remoção da cauda da lista e exibe o feedback correspondente
                opStatus = removeBack(list);
                handleStatus(opStatus);
                break;
            }
            
            case 5: {
                printf("================================================================\n");
                printf("          5 - Excluir Livros Acima do Preço na Lista            \n");
                printf("================================================================\n");

                // Solicita o valor limite dos livros na lista
                tempPrice = validateFloat("Digite o preco limite: ");
                opStatus = removeOverPrice(list, tempPrice);
                handleStatus(opStatus);
                break;
            }

            case 6: {
                printf("================================================================\n");
                printf("          6 - Exibir Livro com Maior Preço da Lista             \n");
                printf("================================================================\n");
                
                // Chama função para verificar qual e o livro com maior preço na lista
                tempBook = findBiggerPrice(list);

                // Verifica se a lista não estava vazia antes de tentar imprimir
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
                
                // Solicita a remoção de livros com códigos duplicados e exibe o feedback correspondente
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

    } while (option != 8); // Mantém a execução até o usuário solicitar a opção de saída (6)
}
