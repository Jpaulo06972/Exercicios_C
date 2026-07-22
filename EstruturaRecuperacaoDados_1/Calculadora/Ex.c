#include <stdio.h>  // Entrada e saída padrão.
#include <stdlib.h> // Gerenciamento dinâmico de memória e função atof.
#include <string.h> // Manipulação e medição de tamanho de strings.
#include <ctype.h>  // Funções isdigit e isspace para parsing da expressão.
#include <stdbool.h>// Suporte a dados booleanos nativos (bool, true, false).

// -----------------------------------------------------------
// Estruturas da pilha encadeada de caracteres (utilizada para validar delimitadores e converter expressões)
typedef struct NodePilha {
    char data;               // Armazena o caractere (delimitador ou operador).
    struct NodePilha* next;  // Aponta para o nó abaixo na pilha.
} NodePilha;

typedef struct {
    NodePilha* top;          // Ponteiro para o topo da pilha de caracteres.
} Pilha;

// -----------------------------------------------------------
// Funções básicas de manipulação da pilha de caracteres
void inicializarPilha(Pilha* p) {
    p->top = NULL; // Define a pilha como vazia.
}

int pilhaVazia(Pilha* p) {
    return (p->top == NULL); // Retorna 1 se estiver vazia, 0 caso contrário.
}

void empilhar(Pilha* p, char valor) {
    // Aloca um novo nó da pilha de caracteres e o insere no topo (operacao Push).
    NodePilha* novo = (NodePilha*) malloc(sizeof(NodePilha));
    novo->data = valor;
    novo->next = p->top;
    p->top = novo;
}

char desempilhar(Pilha* p) {
    // Remove o elemento do topo da pilha e retorna seu caractere armazenado (operacao Pop).
    if (pilhaVazia(p))
        return '\0';

    NodePilha* temp = p->top;
    char valor = temp->data;
    p->top = temp->next;
    free(temp); // Libera o nó desempilhado da memória.
    return valor;
}

char topo(Pilha* p) {
    // Consulta o caractere que está no topo da pilha sem removê-lo (operação Peek).
    if (pilhaVazia(p))
        return '\0';
    return p->top->data;
}

// -----------------------------------------------------------
// Valida a consistência e o balanceamento dos delimitadores '()', '[]' e '{}' na expressão infixa.
bool verificarExpressao(char exp[]) {
    Pilha pilha;
    inicializarPilha(&pilha);

    // Percorre cada caractere da string contendo a expressão matemática.
    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        // Se for um delimitador de abertura, empilha para conferência posterior.
        if (c == '(' || c == '[' || c == '{') {
            empilhar(&pilha, c);
        }
        // Se for um delimitador de fechamento, verifica a correspondência com o topo.
        else if (c == ')' || c == ']' || c == '}') {
            // Se encontrar fechamento mas a pilha estiver vazia, há desbalanceamento.
            if (pilhaVazia(&pilha))
                return false;

            char topoChar = desempilhar(&pilha);

            // Verifica se o par de abertura/fechamento é do mesmo tipo.
            if ((c == ')' && topoChar != '(') ||
                (c == ']' && topoChar != '[') ||
                (c == '}' && topoChar != '{'))
                return false; // Tipos incompatíveis (ex: '(]').
        }
    }

    // Se ao final sobrou algum delimitador não fechado na pilha, a expressão é inválida.
    if (!pilhaVazia(&pilha))
        return false;
    else
        return true;
}

// -----------------------------------------------------------
// Estruturas da Árvore de Expressão e Pilha de Nós da Árvore
typedef struct Node {
    char data;             // Simbolo do operador (+, -, *, /) ou '#' para valores numéricos.
    double value;          // Valor numérico real (quando o nó for uma folha).
    struct Node* left;     // Ponteiro para a subárvore esquerda (operando esquerdo).
    struct Node* right;    // Ponteiro para a subárvore direita (operando direito).
} Node;

// Pilha sequencial para armazenar ponteiros de nós da árvore durante a construção da árvore de sintaxe.
typedef struct {
    Node* itens[200];
    int topo;
} PilhaNode;

// -----------------------------------------------------------
// Operações para a pilha de ponteiros de nós da árvore
void inicializarPilhaNode(PilhaNode* p) {
    p->topo = -1; // -1 indica pilha de nós vazia.
}

int pilhaNodeVazia(PilhaNode* p) {
    return (p->topo == -1);
}

void empilharNode(PilhaNode* p, Node* n) {
    p->itens[++(p->topo)] = n; // Incrementa o topo e armazena o nó.
}

Node* desempilharNode(PilhaNode* p) {
    if (pilhaNodeVazia(p)) return NULL;
    return p->itens[(p->topo)--]; // Retorna o nó e decrementa o topo.
}

// -----------------------------------------------------------
// Retorna a ordem de precedência dos operadores matemáticos segundo as regras da aritmética.
int precedencia(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; // Para parênteses ou caracteres não operadores.
}

// -----------------------------------------------------------
// Converte a expressão da notação Infixa para Pós-fixa (Algoritmo Shunting Yard de Dijkstra).
// Trata números reais de múltiplos dígitos e pontos decimais.
void infixParaPosfix(char infixa[], char posfixa[]) {
    Pilha pilha;
    inicializarPilha(&pilha);
    int j = 0; // Índice de escrita da string pós-fixa resultado.

    for (int i = 0; infixa[i] != '\0'; i++) {
        char c = infixa[i];
        if (isspace(c)) continue; // Descarta espaços em branco.

        // Se o caractere for um dígito numérico:
        if (isdigit(c)) {
            // Agrupa sequencialmente todos os dígitos e eventuais pontos decimais do número completo.
            while (isdigit(infixa[i]) || infixa[i] == '.') {
                posfixa[j++] = infixa[i++];
            }
            posfixa[j++] = ' '; // Insere espaço como delimitador entre tokens.
            i--; // Ajusta o índice pois o laço for externo fará o incremento 'i++'.
        }
        else if (c == '(') {
            empilhar(&pilha, c);
        }
        else if (c == ')') {
            // Ao fechar parênteses, desempilha todos os operadores acumulados até encontrar o '(' correspondente.
            while (!pilhaVazia(&pilha) && topo(&pilha) != '(') {
                posfixa[j++] = desempilhar(&pilha);
                posfixa[j++] = ' ';
            }
            if (!pilhaVazia(&pilha))
                desempilhar(&pilha); // Descarta o parêntese de abertura '(' da pilha.
        }
        else { // Se for um operador (+, -, *, /):
            // Desempilha operadores com precedência maior ou igual antes de empilhar o operador atual.
            while (!pilhaVazia(&pilha) &&
                   precedencia(topo(&pilha)) >= precedencia(c)) {
                posfixa[j++] = desempilhar(&pilha);
                posfixa[j++] = ' ';
            }
            empilhar(&pilha, c);
        }
    }

    // Desempilha os operadores restantes após o término da leitura da expressão.
    while (!pilhaVazia(&pilha)) {
        posfixa[j++] = desempilhar(&pilha);
        posfixa[j++] = ' ';
    }

    posfixa[j] = '\0'; // Finaliza a string pós-fixa com o caractere nulo.
}

// -----------------------------------------------------------
// Aloca e inicializa um novo nó para a Árvore de Expressão.
Node* novoNo(char data, double value) {
    Node* n = (Node*) malloc(sizeof(Node));
    n->data = data;
    n->value = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// -----------------------------------------------------------
// Constrói a Árvore de Sintaxe Abstrata a partir da notação pós-fixa.
Node* construirArvore(char posfixa[]) {
    PilhaNode pilha;
    inicializarPilhaNode(&pilha);

    for (int i = 0; posfixa[i] != '\0'; i++) {
        char c = posfixa[i];
        if (isspace(c)) continue;

        // Se for número, lê a string numérica completa e cria nó folha.
        if (isdigit(c)) {
            char numStr[50];
            int k = 0;

            while (isdigit(posfixa[i]) || posfixa[i] == '.') {
                numStr[k++] = posfixa[i++];
            }
            numStr[k] = '\0';

            // Converte a substring numérica para o valor real double.
            double valor = atof(numStr);
            Node* n = novoNo('#', valor); // '#' sinaliza que o nó armazena um operando.
            empilharNode(&pilha, n);
        }
        else { // Se for um operador, cria nó interno e conecta as subárvores.
            Node* n = novoNo(c, 0.0);
            
            // O primeiro elemento desempilhado forma a subárvore direita (LIFO).
            Node* direita = desempilharNode(&pilha);
            // O segundo elemento desempilhado forma a subárvore esquerda.
            Node* esquerda = desempilharNode(&pilha);
            
            n->left = esquerda;
            n->right = direita;
            
            // Empilha o nó do operador com suas subárvores conectadas.
            empilharNode(&pilha, n);
        }
    }

    // A raiz principal da árvore completa é o último nó restante na pilha.
    return desempilharNode(&pilha);
}

// -----------------------------------------------------------
// Função integradora: valida a expressão, converte para pós-fixa e constrói a árvore sintática.
Node* montarArvoreExpressao(char expressao[]) {
    // 1. Valida o balanceamento de parênteses e delimitadores.
    if (!verificarExpressao(expressao)) {
        printf("Expressao invalida! Delimitadores incorretos.\n");
        return NULL;
    }

    // 2. Converte a expressão de infixa para pós-fixa.
    char posfixa[200];
    infixParaPosfix(expressao, posfixa);

    // 3. Monta a estrutura da árvore de expressão a partir da representação pós-fixa.
    Node* raiz = construirArvore(posfixa);
    return raiz;
}

// -----------------------------------------------------------
// Avalia recursivamente o resultado da Árvore de Expressão em percurso pós-ordem.
double evaluateExpression(Node* currentNode) {
    // Caso base 1: Nó nulo.
    if (currentNode == NULL) {
        return 0.0;
    }

    // Caso base 2: Nó folha (operando marcado com '#'). Retorna seu valor numérico.
    if (currentNode->data == '#') {
        return currentNode->value;
    }
    
    // Passo recursivo: avalia a subárvore esquerda e a subárvore direita.
    double esquerda = evaluateExpression(currentNode->left);
    double direita = evaluateExpression(currentNode->right);

    // Executa a operação aritmética baseada no operador do nó atual.
    switch (currentNode->data) {
        case '+':
            return esquerda + direita;
        case '-':
            return esquerda - direita;
        case '*':
            return esquerda * direita;
        case '/':
            // Prevenção de erro fatal por divisão por zero.
            if (direita == 0.0) {
                printf("Erro: Divisao por zero!\n");
                exit(1);
            }
            return esquerda / direita;
        default:
            return 0.0;
    }
}

// -----------------------------------------------------------
// Programa principal.
int main() {
    char expressao[200];

    // Solicita a expressão infixa ao usuário (ex: "3 + (4 * 5)").
    printf("Digite a expressao infixa: ");
    fgets(expressao, 200, stdin);
    expressao[strcspn(expressao, "\n")] = '\0'; // Remove o \n final capturado pelo fgets.

    // Monta a árvore a partir da entrada fornecida.
    Node* raiz = montarArvoreExpressao(expressao);

    // Se a montagem ocorreu com sucesso, calcula e exibe o resultado final.
    if (raiz != NULL) {
        printf("\nArvore criada com sucesso.\n");
        double resultado = evaluateExpression(raiz);
        printf("\nResultado final: %.2lf\n", resultado);
    } else {
        printf("\nNao foi possivel criar a arvore (erro na expressao).\n");
    }

    return 0;
}
