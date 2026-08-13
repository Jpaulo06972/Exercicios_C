#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* text;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void initStack(Stack* p) {
    p->top = NULL;
}

int isEmpty(Stack* p) {
    return p->top == NULL;
}

void push(Stack* p, const char* text) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro de memoria!\n");
        return;
    }

    newNode->text = strdup(text);
    newNode->next = p->top;
    p->top = newNode;
}

char* pop(Stack* p) {
    if (isEmpty(p)) return NULL;

    Node* temp = p->top;
    char* text = temp->text;
    p->top = temp->next;

    free(temp);
    return text;
}

void clearStack(Stack* p) {
    while (!isEmpty(p)) {
        char* text = pop(p);
        free(text);
    }
}

void imprimirRec(Node* no) {
    if (no == NULL) return;

    imprimirRec(no->next);

    printf("%s ", no->text);
}

void imprimirTexto(Stack* p) {
    printf("\n--- TEXTO ATUAL ---\n> ");
    if (isEmpty(p)) {
        printf("(vazio)");
    } else {
        imprimirRec(p->top);
    }
    printf("\n-------------------\n");
}

int main() {

    Stack pilhaUndo, pilhaRedo;
    initStack(&pilhaUndo);
    initStack(&pilhaRedo);

    int opcao;
    char buffer[100];

    do {
        printf("\nMENU EDITOR:\n");
        printf("0 - Digitar nova palavra\n");
        printf("1 - Desfazer (Undo)\n");
        printf("2 - Refazer (Redo)\n");
        printf("3 - Imprimir a frase\n");
        printf("4 - Sair\n");
        printf("Qual opcao? ");
        scanf("%d", &opcao);

        while (getchar() != '\n');

        switch (opcao) {
            case 0:
                printf("Digite a palavra: ");
                scanf("%s", buffer);

                push(&pilhaUndo, buffer);

                clearStack(&pilhaRedo);
                printf("Palavra '%s' inserida. Pilha Redo esvaziada.\n", buffer);
                break;

            case 1:
                if (isEmpty(&pilhaUndo)) {
                    printf("Nada para desfazer!\n");
                } else {

                    char* removido = pop(&pilhaUndo);

                    push(&pilhaRedo, removido);
                    free(removido);

                    printf("Desfeito com sucesso.\n");
                }
                break;

            case 2:
                if (isEmpty(&pilhaRedo)) {
                    printf("Nada para refazer!\n");
                } else {

                    char* recuperado = pop(&pilhaRedo);
                    push(&pilhaUndo, recuperado);
                    free(recuperado);

                    printf("Refeito com sucesso.\n");
                }
                break;

            case 3:
                imprimirTexto(&pilhaUndo);
                break;

            case 4:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);

    clearStack(&pilhaUndo);
    clearStack(&pilhaRedo);

    return 0;
}
