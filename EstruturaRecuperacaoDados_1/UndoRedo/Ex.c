#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Definição das Estruturas ---

typedef struct Node {
    char* text;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

// --- Funções Auxiliares de Pilha ---

// Inicializa uma pilha vazia
void initStack(Stack* p) {
    p->top = NULL;
}

// Verifica se está vazia
int isEmpty(Stack* p) {
    return p->top == NULL;
}

// Empilha uma string (copiando o conteúdo)
void push(Stack* p, const char* text) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro de memoria!\n");
        return;
    }
    // Aloca memória para a string e copia
    newNode->text = strdup(text); 
    newNode->next = p->top;
    p->top = newNode;
}

// Desempilha e retorna a string (quem chamar deve liberar a memória)
char* pop(Stack* p) {
    if (isEmpty(p)) return NULL;
    
    Node* temp = p->top;
    char* text = temp->text;
    p->top = temp->next;
    
    free(temp); // Libera o nó, mas não a string (retornamos ela)
    return text;
}

// Esvazia completamente uma pilha (Regra importante do "Digitar")
void clearStack(Stack* p) {
    while (!isEmpty(p)) {
        char* text = pop(p);
        free(text); // Libera a string que estava armazenada
    }
}

// --- Funções de Impressão (Baseadas no PDF) ---

// Função recursiva para imprimir da base para o topo
void imprimirRec(Node* no) {
    if (no == NULL) return;
    
    imprimirRec(no->next); // Chama o próximo antes de imprimir (vai até o fundo)
    printf("%s ", no->text); // Imprime na volta
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

// --- Lógica Principal ---

int main() {
    Stack pilhaUndo, pilhaRedo;
    initStack(&pilhaUndo);
    initStack(&pilhaRedo);
    
    int opcao;
    char buffer[100]; // Buffer para ler a palavra digitada

    do {
        printf("\nMENU EDITOR:\n");
        printf("0 - Digitar nova palavra\n");
        printf("1 - Desfazer (Undo)\n");
        printf("2 - Refazer (Redo)\n");
        printf("3 - Imprimir a frase\n");
        printf("4 - Sair\n");
        printf("Qual opcao? ");
        scanf("%d", &opcao);
        
        // Limpar buffer do teclado após ler o número
        while (getchar() != '\n'); 

        switch (opcao) {
            case 0: // Digitar
                printf("Digite a palavra: ");
                scanf("%s", buffer); // Lê uma palavra simples
                
                push(&pilhaUndo, buffer);
                
                // REGRA DE OURO: Digitou novo? Zera o Redo!
                clearStack(&pilhaRedo); 
                printf("Palavra '%s' inserida. Pilha Redo esvaziada.\n", buffer);
                break;

            case 1: // Undo
                if (isEmpty(&pilhaUndo)) {
                    printf("Nada para desfazer!\n");
                } else {
                    char* removido = pop(&pilhaUndo);
                    push(&pilhaRedo, removido);
                    printf("Desfeito: '%s' movido para Redo.\n", removido);
                    // Não damos free no 'removido' aqui pois ele foi para a outra pilha
                    // Se usássemos strdup no push, teríamos que gerenciar isso, 
                    // mas o ponteiro foi transferido com segurança.
                }
                break;

            case 2: // Redo
                if (isEmpty(&pilhaRedo)) {
                    printf("Nada para refazer!\n");
                } else {
                    char* recuperado = pop(&pilhaRedo);
                    push(&pilhaUndo, recuperado);
                    printf("Refeito: '%s' movido de volta para Undo.\n", recuperado);
                }
                break;

            case 3: // Imprimir
                imprimirTexto(&pilhaUndo);
                break;

            case 4:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);

    // Limpeza final de memória
    clearStack(&pilhaUndo);
    clearStack(&pilhaRedo);

    return 0;
}