#include <stdio.h>  // Entrada e saída padrão (printf, scanf).
#include <stdlib.h> // Alocação dinâmica de memória (malloc, free).
#include <string.h> // Manipulação de strings.
#include <stdbool.h>// Tipo booleano (bool, true, false).
#include <ctype.h>  // Manipulação de caracteres.

// Estrutura do nó da pilha para armazenar caracteres de abertura ('(', '{', '[').
typedef struct Expressao{
    char guarda;            // Caractere do símbolo de abertura armazenado.
    struct Expressao* next; // Ponteiro para o próximo nó abaixo na pilha.
} Expressao;

// Estrutura descritora da Pilha.
typedef struct Pilha{
    Expressao* top; // Ponteiro para o topo da pilha.
} Pilha;

// Aloca dinamicamente e inicializa um nó da pilha com o caractere informado.
Expressao* create_no(char value){
    Expressao* new_no = (Expressao*) malloc(sizeof(Expressao));
    new_no->guarda = value;
    new_no->next = NULL;
    return new_no;
}

// Operação PUSH: Insere um novo símbolo de abertura no TOPO da pilha.
Pilha* push(Pilha* p, char value){
    Expressao* new_no = create_no(value); // Cria o nó alocado dinamicamente.
    new_no->next = p->top;                // O novo nó aponta para o antigo topo.
    p->top = new_no;                      // Atualiza o topo da pilha para o novo nó.
    return p;                             // Retorna a pilha modificada.
}

// Operação POP: Desempilha (remove) o símbolo do TOPO da pilha.
Pilha* pop(Pilha* p){
    // Tratamento de segurança para evitar erro ao desempilhar pilha vazia.
    if (p->top == NULL) return p; 
    
    Expressao* temp = p->top; // Guarda a referência do topo atual.
    p->top = p->top->next;    // Avança o topo para o elemento de baixo.
    free(temp);               // Libera a memória do antigo topo.
    return p;                 // Retorna a pilha atualizada.
}

// Libera toda a memória alocada para os nós da pilha.
void free_pilha(Pilha* p){
    Expressao* current = p->top;
    
    // Itera desempilhando e desalocando cada nó da pilha.
    while (current != NULL){ 
        Expressao* temp = current;
        current = current->next;
        free(temp);
    }
    // Desaloca a própria estrutura descritora da pilha.
    free(p);
}

// Função utilitária para imprimir o conteúdo visual atual da pilha.
void print_pilha(Pilha* p){
    Expressao* current = p->top;
    printf("Pilha: ");
    while (current != NULL){
        printf("%c", current->guarda); // Imprime o caractere empilhado.
        current = current->next;
    }
    printf("NULL\n");
}

// Verifica se um caractere de abertura e um de fechamento formam um par válido e compatível.
bool compara(char abertura, char fecha){
    if (abertura == '(' && fecha == ')') return true;
    if (abertura == '{' && fecha == '}') return true;
    if (abertura == '[' && fecha == ']') return true;
    return false; // Retorna false se os pares de delimitadores forem incompatíveis.
}

// Exibe a mensagem referente ao status de balanceamento da expressão e retorna flag indicativo.
int imprime(bool balanceada){
    if (balanceada) {
        printf("\nA expressao esta balanceada.\n");
        return 1;
    } else {
        printf("\nA expressao NAO esta balanceada.\n");
        return 0;
    }
}

// Realiza a leitura e a verificação do balanceamento dos parênteses/chaves/colchetes da expressão.
int verifica(Pilha* p){

    char exp[100];
    int i;
    bool balancea = true; // Flag inicializada assumindo que a expressão está balanceada.

    // Solicita a expressão matemática ao usuário.
    printf("Digite a expressao:");
    scanf(" %[^\n]", exp);

    // Percorre caractere por caractere a string da expressão até o fim ('\0').
    for (i = 0; exp[i] != '\0'; i++) {
        char caracter = exp[i];

        // Se for caractere de abertura, empilha para conferência posterior.
        if (caracter == '(' || caracter == '{' || caracter == '['){
            p = push(p, caracter);

        } 
        // Se for caractere de fechamento, valida com o topo da pilha.
        else if (caracter == ')' || caracter == '}' || caracter == ']'){

            // Se encontrou um fechamento mas a pilha está vazia, falta o correspondente de abertura.
            if (p->top == NULL){
                balancea = false;
                break;
            }

            // Confere se o fechamento atual combina com o tipo do caractere que está no topo.
            if (compara(p->top->guarda, caracter)){
                p = pop(p); // Par correto: desempilha o elemento de abertura correspondente.
            } else {
                balancea = false; // Par incorreto (ex: '(]'): marca como desbalanceada e cancela o laço.
                break;
            }
        }
    }

    // Ao término da string, se a pilha ainda possuir elementos, há aberturas não fechadas.
    if (p->top != NULL) {
        balancea = false;
    }

    // Exibe o resultado e retorna a indicação de sucesso/falha.
    int result = imprime(balancea);

    return result;
}

// Menu principal interativo do programa.
void menu(){
    
    int opcao;
    
    // Aloca e inicializa a pilha encadeada.
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->top = NULL;

    // Loop do menu de opções.
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
            // Executa o teste de verificação da expressão.
            verifica(p);
            break;
        case 2:
            printf("\nSaindo...\n");
            // Libera a pilha da memória antes de sair.
            free_pilha(p);
            break;  
        
        default:
            printf("\nValor Invalido. Digite Novamente.\n\n");
            break;
        }
    } while (opcao != 2);
}

// Ponto de entrada do executável C.
int main(){
    menu(); // Inicia o menu interativo.
    return 0;
}
