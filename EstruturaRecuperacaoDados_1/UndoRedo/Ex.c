#include <stdio.h>  // Entrada e saída padrão.
#include <stdlib.h> // Alocação e liberação de memória (malloc, free).
#include <string.h> // Manipulação de strings (strdup, strcmp).

// --- Definição das Estruturas da Pilha ---

// Estrutura que representa o nó da pilha, armazenando a palavra digitada.
typedef struct Node {
    char* text;         // Ponteiro para a string da palavra alocada dinamicamente na heap.
    struct Node* next;  // Ponteiro para a palavra anterior (nó abaixo na pilha).
} Node;

// Estrutura descritora da Pilha.
typedef struct {
    Node* top;          // Aponta para a palavra no topo da pilha.
} Stack;

// --- Funções Auxiliares de Gerenciamento da Pilha ---

// Inicializa a pilha com topo nulo (pilha vazia).
void initStack(Stack* p) {
    p->top = NULL;
}

// Verifica se a pilha está vazia.
int isEmpty(Stack* p) {
    return p->top == NULL;
}

// Empilha uma nova string copiando o conteúdo (Operação PUSH).
void push(Stack* p, const char* text) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro de memoria!\n");
        return;
    }
    // Duplica dinamicamente a string recebida (aloca o espaço exato e copia os caracteres).
    newNode->text = strdup(text); 
    newNode->next = p->top;
    p->top = newNode;
}

// Desempilha e retorna o ponteiro da string armazenada (Operação POP).
// Importante: a responsabilidade de liberar a memória da string 'text' fica a cargo de quem chamou a função.
char* pop(Stack* p) {
    if (isEmpty(p)) return NULL;
    
    Node* temp = p->top;
    char* text = temp->text;
    p->top = temp->next;
    
    // Libera a estrutura do nó, mas preserva a memória da string retornando seu ponteiro.
    free(temp); 
    return text;
}

// Esvazia completamente a pilha liberando tanto a memória dos nós quanto das strings (crucial na regra de novo texto).
void clearStack(Stack* p) {
    while (!isEmpty(p)) {
        char* text = pop(p);
        free(text); // Desaloca a string alocada por strdup.
    }
}

// --- Funções de Impressão Recursiva ---

// Função recursiva para imprimir as palavras na ordem cronológica em que foram digitadas (da base até o topo).
void imprimirRec(Node* no) {
    if (no == NULL) return; // Caso base: chegou ao fundo da pilha (nó nulo).
    
    // Passo recursivo: avança até a base da pilha antes de imprimir.
    imprimirRec(no->next); 
    
    // Na volta da recursão, imprime a palavra seguida por espaço.
    printf("%s ", no->text); 
}

// Exibe a frase reconstruída a partir da pilha de Undo.
void imprimirTexto(Stack* p) {
    printf("\n--- TEXTO ATUAL ---\n> ");
    if (isEmpty(p)) {
        printf("(vazio)");
    } else {
        imprimirRec(p->top);
    }
    printf("\n-------------------\n");
}

// --- Lógica Principal do Editor de Texto Undo/Redo ---

int main() {
    // Declara e inicializa as duas pilhas: Undo (ações efetuadas) e Redo (ações desfeitas).
    Stack pilhaUndo, pilhaRedo;
    initStack(&pilhaUndo);
    initStack(&pilhaRedo);
    
    int opcao;
    char buffer[100]; // Buffer temporário para armazenar a entrada digitada pelo usuário.

    do {
        printf("\nMENU EDITOR:\n");
        printf("0 - Digitar nova palavra\n");
        printf("1 - Desfazer (Undo)\n");
        printf("2 - Refazer (Redo)\n");
        printf("3 - Imprimir a frase\n");
        printf("4 - Sair\n");
        printf("Qual opcao? ");
        scanf("%d", &opcao);
        
        // Limpa o buffer de entrada do teclado consumindo o caractere de nova linha '\n'.
        while (getchar() != '\n'); 

        switch (opcao) {
            case 0: // Digitar nova palavra
                printf("Digite a palavra: ");
                scanf("%s", buffer); // Lê uma palavra do teclado.
                
                // Adiciona a nova palavra à pilha de desfazer (Undo).
                push(&pilhaUndo, buffer);
                
                // REGRA DE OURO: ao digitar uma nova palavra, o histórico de refazer (Redo) deve ser limpo.
                clearStack(&pilhaRedo); 
                printf("Palavra '%s' inserida. Pilha Redo esvaziada.\n", buffer);
                break;

            case 1: // Undo (Desfazer)
                if (isEmpty(&pilhaUndo)) {
                    printf("Nada para desfazer!\n");
                } else {
                    // Desempilha a última palavra da pilha Undo e move-a diretamente para a pilha Redo.
                    char* removido = pop(&pilhaUndo);
                    
                    // Aloca o novo nó no Redo reaproveitando a string ou duplicando via push.
                    push(&pilhaRedo, removido);
                    free(removido); // Libera o ponteiro retornado pelo pop já que push alocou nova cópia.
                    
                    printf("Desfeito com sucesso.\n");
                }
                break;

            case 2: // Redo (Refazer)
                if (isEmpty(&pilhaRedo)) {
                    printf("Nada para refazer!\n");
                } else {
                    // Desempilha da pilha Redo e move de volta para a pilha Undo.
                    char* recuperado = pop(&pilhaRedo);
                    push(&pilhaUndo, recuperado);
                    free(recuperado); // Libera o ponteiro intermediário.
                    
                    printf("Refeito com sucesso.\n");
                }
                break;

            case 3: // Imprimir texto atual
                imprimirTexto(&pilhaUndo);
                break;

            case 4: // Sair do programa
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);

    // Desaloca a memória residual de ambas as pilhas antes de finalizar a execução.
    clearStack(&pilhaUndo);
    clearStack(&pilhaRedo);

    return 0;
}