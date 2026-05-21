#include <stdio.h> // Para funções de entrada/saída (printf, scanf).
#include <stdlib.h> // Para alocação de memória (malloc, free).
#include <string.h> // Para manipulação de strings (strcpy).
#include <stdbool.h> // Para usar o tipo 'bool' (true, false).
#include <ctype.h> // Para manipulação de caracteres (não usado aqui, mas estava no original).

// Estrutura para guarda os parentese da expressao
typedef struct Expressao{
    char guarda;
    
    struct Expressao* next;
} Expressao;

// Estrutura da pilha
typedef struct Pilha{
    Expressao* top;
} Pilha;

// Funcao para criar um novo no
Expressao* create_no(char value){
    Expressao*  new_no = (Expressao*) malloc(sizeof(Expressao));
    new_no->guarda = value;
    new_no->next = NULL;
    return new_no;
}

// Push - Insere um novo elemento na fila 
Pilha* push(Pilha* p, char value){
    Expressao* new_no = create_no(value); // Chama funcao para criacao do novo no
    new_no->next = p->top; // Aponta o next do novo no para o anterior
    p->top = new_no; // Faz o topo apontar para o novo no criado
    return p; // Retorna a pilha atualizada
}

// Pop - Remove o primeiro da fila 
Pilha* pop(Pilha* p){
    if (p->top == NULL) return p; // Ocorre quando a pilha está vazia
    Expressao* temp = p->top; // Associa o no temporario ao no que vai ser removido
    p->top = p->top->next; // Aponta o top para o proximo da pilha 
    free(temp); // Limpa a memoria temporaria
    return p; // Retorna a pilh atualizada
}

// Free - Limpa a pilha
void free_pilha(Pilha* p){
    Expressao* current = p->top; // Cria uma pilha temporaria 
    while (current != NULL){ // Enquanto a pilha nao estiver vazia 
        Expressao* temp = current; // Cria o temporaria dentro do while
        current = current->next; // Aponta para o próximo da pilha
        free(temp); // Limpa a memoria do temporario
    }
    free(p); // Limpa o topo   
}

// Mostra o elementos da pilha
void print_pilha(Pilha* p){
    Expressao* current = p->top;
    printf("Pilha: ");
    while (current != NULL){
        printf("%d", current->guarda);
        current = current->next;
    }
    printf("NULL\n");
}

// Cria fiuncao para comparar se a expressao esta balanceada 
bool compara(char abertura, char fecha){

    // Verifica se abertura corresponde com que fecha
    if (abertura == '(' && fecha == ')') return true;
    if (abertura == '{' && fecha == '}') return true;
    if (abertura == '[' && fecha == ']') return true;
    return false;
}

int imprime(bool balanceada){
    // Imprime o resultado e retorna
    if (balanceada) {
        printf("\nA expressao esta balanceada.\n");
        return 1;
    } else {
        printf("\nA expressao NAO esta balanceada.\n");
        return 0;
    }
}
// Funcao para verificar expressao
int verifica(Pilha* p){

    // Declara as variaveis
    char exp[100];
    int i;
    bool balancea = true;

    // Pede para usuario digitar a expressao
    printf("Digite a expressao:");
    scanf(" %[^\n]", exp);

    // Percorre a expressão
    for (i = 0; exp[i] != '\0'; i++) {
        char caracter = exp[i];

        // Adiciona o elemento na pilha caso seja abertura
        if (caracter == '(' || caracter == '{' || caracter == '['){
            // Chama funcao para adicionar na pilha
            p = push(p, caracter);

        } else if (caracter == ')' || caracter == '}' || caracter == ']'){

            // Verifica se a pilha nao está vazia
            if (p->top == NULL){
                balancea = false;
                break;
            }

            // Verifica se está a expressao está certo
            if (compara(p->top->guarda, caracter)){
                p = pop(p);
            } else {
                balancea = false;
                break;
            }
        }
    }

    // Verifica se a expressao está vazia
    if (p->top != NULL) {
        balancea = false;
    }

    // Chama funçao para imprimir a verificao da expressao
    int result = imprime(balancea);

    return result;
}

void menu(){
    
    // Declara funcao
    int opcao;
    
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->top = NULL;

    // Loop para rodar o menu
    do
    {
        printf("\n========================================\n");
        printf("                    MENU                  \n");
        printf("1 - Executar Verificacao.                 \n");
        printf("2 - Sai.                                  \n");
        printf("========================================  \n");
        printf("Digite a opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            // Chama funcao para verificar expressao
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
    // Chama funçao do menu 
    menu();

    // Retorna 0
    return 0;
}
