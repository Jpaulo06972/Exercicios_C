#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct Expressao{
    char guarda;
    struct Expressao* next;
} Expressao;

typedef struct Pilha{
    Expressao* top;
} Pilha;

Expressao* create_no(char value){
    Expressao* new_no = (Expressao*) malloc(sizeof(Expressao));
    new_no->guarda = value;
    new_no->next = NULL;
    return new_no;
}

Pilha* push(Pilha* p, char value){
    Expressao* new_no = create_no(value);
    new_no->next = p->top;
    p->top = new_no;
    return p;
}

Pilha* pop(Pilha* p){

    if (p->top == NULL) return p;

    Expressao* temp = p->top;
    p->top = p->top->next;
    free(temp);
    return p;
}

void free_pilha(Pilha* p){
    Expressao* current = p->top;

    while (current != NULL){
        Expressao* temp = current;
        current = current->next;
        free(temp);
    }

    free(p);
}

void print_pilha(Pilha* p){
    Expressao* current = p->top;
    printf("Pilha: ");
    while (current != NULL){
        printf("%c", current->guarda);
        current = current->next;
    }
    printf("NULL\n");
}

bool compara(char abertura, char fecha){
    if (abertura == '(' && fecha == ')') return true;
    if (abertura == '{' && fecha == '}') return true;
    if (abertura == '[' && fecha == ']') return true;
    return false;
}

int imprime(bool balanceada){
    if (balanceada) {
        printf("\nA expressao esta balanceada.\n");
        return 1;
    } else {
        printf("\nA expressao NAO esta balanceada.\n");
        return 0;
    }
}

int verifica(Pilha* p){

    char exp[100];
    int i;
    bool balancea = true;

    printf("Digite a expressao:");
    scanf(" %[^\n]", exp);

    for (i = 0; exp[i] != '\0'; i++) {
        char caracter = exp[i];

        if (caracter == '(' || caracter == '{' || caracter == '['){
            p = push(p, caracter);

        }

        else if (caracter == ')' || caracter == '}' || caracter == ']'){

            if (p->top == NULL){
                balancea = false;
                break;
            }

            if (compara(p->top->guarda, caracter)){
                p = pop(p);
            } else {
                balancea = false;
                break;
            }
        }
    }

    if (p->top != NULL) {
        balancea = false;
    }

    int result = imprime(balancea);

    return result;
}

void menu(){

    int opcao;

    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->top = NULL;

    do
    {
        printf("\n========================================\n");
        printf("                    MENU                  \n");
        printf("1 - Executar Verificacao.                 \n");
        printf("2 - Sair.                                 \n");
        printf("========================================  \n");
        printf("Digite a opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:

            verifica(p);
            break;
        case 2:
            printf("\nSaindo...\n");

            free_pilha(p);
            break;

        default:
            printf("\nValor Invalido. Digite Novamente.\n\n");
            break;
        }
    } while (opcao != 2);
}

int main(){
    menu();
    return 0;
}
