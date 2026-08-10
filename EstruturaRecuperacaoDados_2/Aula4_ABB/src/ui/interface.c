// Inclui biblioteca padrão para entrada e saída de dados (printf, scanf, getchar)
#include <stdio.h>
// Inclui suporte ao tipo booleano (true/false)
#include <stdbool.h>

// Inclui o módulo de lógica da árvore (Core)
#include "../core/arvore_core.h"
// Inclui o cabeçalho das funções da interface (UI)
#include "interface.h"

// --------------------------------------------- //
//        Tratamento e Exibição de Status        //
// --------------------------------------------- //
// Traduz o código de status retornado pelas funções do Core em mensagens amigáveis no console.
void handleStatus(TreeStatus status){

    // Avalia o código de status retornado
    switch (status) {
        // Caso de sucesso na operação    
        case STATUS_SUCCESS:
            // Exibe mensagem de confirmação de sucesso
            printf("\n[SUCESSO] Operacao realizada com sucesso!\n\n");
            break;

        // Caso onde o ponteiro para a árvore é nulo (NULL)    
        case ERR_TREE_NULL:    
            // Exibe mensagem de erro de árvore não inicializada
            printf("\n[ERRO] A arvore nao foi inicializada (ponteiro NULL)!\n\n");
            // Sai do switch
            break;
        
        // Caso falte memória RAM no sistema
        case ERR_OUT_OF_MEMORY:
            // Exibe mensagem de memória insuficiente
            printf("\n[ERRO] Memoria RAM insuficiente para realizar a operacao!\n\n");
            // Sai do switch
            break;

        // Caso de tentativa de operação em árvore vazia
        case ERR_TREE_EMPTY:
            // Exibe mensagem de árvore vazia
            printf("\n[ERRO] A arvore esta vazia! Nao ha itens para operar.\n\n");
            // Sai do switch
            break;
        
        // Caso de parâmetros ou entradas inválidas
        case ERR_INVALID_INPUT:   
            // Exibe mensagem de entrada inválida
            printf("\n[ERRO] Valor ou parametro informado eh invalido!\n\n");
            // Sai do switch
            break;

        // Caso genérico/padrão    
        default:
            // Sai do switch
            break;
    }
}

// --------------------------------------------- //
//    Validação de Entrada de Inteiro Positivo   //
// --------------------------------------------- //
// Lê um número inteiro do teclado garantindo que seja maior que zero e limpa o buffer em caso de erro.
int readPositiveInt(const char* prompt){

    // Variável para armazenar o valor lido do teclado
    int inputVal = 0;

    // Repete a leitura até o usuário digitar um valor válido (maior que 0)
    do {

        // Exibe a mensagem personalizada para solicitar o dado 
        printf("%s", prompt);

        // Tenta fazer a leitura de um número inteiro digitado
        if(scanf("%d", &inputVal) == 1){
            // Se leu um número, verifica se é menor ou igual a zero
            if (inputVal <= 0){

                // Alerta o usuário para digitar um valor positivo
                printf("\n[VALOR INVALIDO] Por favor, digite um valor maior que 0!\n"); 
            }
        } else {
            // Se o usuário digitou letras ou caracteres inválidos, limpa o buffer do teclado
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            // Mantém inputVal em 0 para forçar uma nova tentativa no laço
            inputVal = 0;
        }
    } while (inputVal <= 0); // Continua no loop enquanto o valor for <= 0
    
    // Retorna o valor inteiro devidamente validado
    return inputVal;
}


// --------------------------------------------- //
//            Função de Buscar Valor             //
// --------------------------------------------- //
// Realiza a busca de um valor inteiro na Árvore Binária de Busca e retorna o nó correspondente.
TreeNode* findABB(Tree* tree, int value){

    // Valida se o ponteiro da árvore é válido antes de iniciar a busca
    if (tree == NULL) return NULL;
    
    // Inicia o ponteiro de busca a partir do nó raiz da árvore
    TreeNode* current = tree->root;

    // Percorre a árvore até encontrar o elemento desejado ou atingir um ponteiro NULL
    while (current != NULL) {
        
        // Se o valor do nó atual for exatamente o procurado, retorna a referência desse nó
        if (current->value == value) return current;

        // Aplica a lógica da ABB: se o valor buscado for maior que o atual vai para a direita, senão esquerda
        if (value > current->value){
            current = current->right;
        } else {
            current = current->left;
        }
    }
    
    // Retorna NULL caso o laço encerre sem encontrar o valor na árvore
    return NULL;
}


// --------------------------------------------- //
//    Função para Contar a Quantidade de Nós     //
// --------------------------------------------- //
// Calcula recursivamente o número total de nós existentes a partir da raiz fornecida.
int countNode(TreeNode* root){

    // Se o nó atual for válido (diferente de NULL), realiza a contagem
    if (root != NULL){

        // Conta recursivamente a subárvore esquerda, soma a subárvore direita e adiciona 1 (nó atual)
        return (countNode(root->left) + countNode(root->right) + 1);
    }

    // Caso base da recursão: nó NULL não contribui para a contagem (retorna 0)
    return 0;
}


// --------------------------------------------- //
//        Função para Imprimir em Ordem          //
// --------------------------------------------- //
// Percorre os nós da árvore em Ordem Simétrica (In-Order: Esquerda, Raiz, Direita), imprimindo os valores.
void dislpay(TreeNode* root){

    // Garante que o nó atual não é nulo antes de fazer o percurso e a exibição
    if (root != NULL){

        // Visita recursivamente todos os elementos localizados na subárvore da esquerda
        dislpay(root->left);

        // Imprime o valor do nó atual formatado no terminal
        printf("%d -> ", root->value);

        // Visita recursivamente todos os elementos localizados na subárvore da direita
        dislpay(root->right);
    }
}


// --------------------------------------------- //
//        Função de Buscar o Menor Valor         //
// --------------------------------------------- //
// Localiza o nó que contém o menor valor armazenado na Árvore Binária de Busca.
TreeNode* findSmallABB(Tree* tree){

    // Valida se o ponteiro da árvore existe e se a árvore contém ao menos um nó raiz
    if (tree == NULL || tree->root == NULL) return NULL;
    
    // Inicia a busca a partir da raiz da árvore
    TreeNode* current = tree->root;

    // Na ABB, o menor valor sempre estará no nó mais à esquerda; navega até a última extremidade esquerda
    while (current->left != NULL) {
        
        // Avança o ponteiro para o filho da esquerda
        current = current->left;
    }
    
    // Retorna o ponteiro do nó com o menor valor encontrado na extremidade esquerda
    return current;
}


// --------------------------------------------- //
//            Menu Principal Interativo          //
// --------------------------------------------- //
// Renderiza a interface do menu e conecta as opções digitadas às funções do Core e da UI.
void runMenu(Tree* tree){

    // Variável que guarda a opção escolhida pelo usuário no menu
    int option = 0;

    // Variável temporária para armazenar o número a ser inserido, removido ou buscado na árvore
    int inputVal;

    // Variável que recebe o status retornado pelas operações do Core
    TreeStatus status;

    // Laço principal que mantém o menu ativo até a opção de saída (9) ser escolhida
    do{
        // Exibição do cabeçalho visual do menu interativo
        printf("================================================================\n");
        printf("                              MENU                              \n");
        printf("1 - Inserir um Novo Valor na Árvore.                            \n");
        printf("2 - Inserir um Novo Valor na Árvore com Recursividade.          \n");
        printf("3 - Remover um Valor da Árvore.                                 \n");
        printf("4 - Remover um Valor da Árvore com Recursividade.               \n");
        printf("5 - Buscar um Valor na Árvore.                                  \n");
        printf("6 - Imprimir Todos os Elementos em Ordem.                       \n");
        printf("7 - Contar a Quantidade de Nós na Árvore.                       \n");
        printf("8 - Buscar o Menor Valor da Árvore.                             \n");
        printf("9 - Sair.                                                       \n");
        printf("================================================================\n");

        // Solicita e valida a opção desejada do menu
        option = readPositiveInt("Digite a sua opcao: ");

        // Processa a ação correspondente à opção selecionada
        switch (option) {
           
            // Opção 1: Inserir elemento na árvore (Iterativo)
            case 1: {
                // Banner da opção 1
                printf("================================================================\n");
                printf("             1 - Inserir um Novo Valor na Árvore.               \n");
                printf("================================================================\n");

                // Lê o valor inteiro a ser adicionado
                inputVal = readPositiveInt("Digite o valor para inserir: ");

                // Chama a função do Core para inserir o elemento iterativamente
                status = insert(tree, inputVal);

                // Processa e exibe a mensagem de retorno da operação
                handleStatus(status);

                // Interrompe o switch
                break;
            }

            // Opção 2: Inserir elemento na árvore com recursividade
            case 2: {
                // Banner da opção 2
                printf("================================================================\n");
                printf("     2 - Inserir um Novo Valor na Árvore com Recursividade.     \n");
                printf("================================================================\n");

                // Lê o valor inteiro a ser adicionado
                inputVal = readPositiveInt("Digite o valor para inserir: ");

                // Chama a função do Core para inserir o elemento recursivamente
                status = insertRecursive(tree, inputVal);

                // Processa e exibe a mensagem de retorno da operação
                handleStatus(status);

                // Interrompe o switch
                break;
            }

            // Opção 3: Remover um elemento da árvore (Iterativo)
            case 3: {
                // Banner da opção 3
                printf("================================================================\n");
                printf("                 3 - Remover um Valor da Árvore.                \n");
                printf("================================================================\n");

                // Lê o valor inteiro a ser removido
                inputVal = readPositiveInt("Digite o valor para remover: ");

                // Chama a função do Core para remover o elemento iterativamente
                status = removeTreeNode(tree, inputVal);

                // Processa e exibe a mensagem de retorno da operação
                handleStatus(status);

                // Interrompe o switch
                break;
            }

            // Opção 4: Remover um elemento da árvore com recursividade
            case 4: {
                // Banner da opção 4
                printf("================================================================\n");
                printf("         4 - Remover um Valor da Árvore com Recursividade.      \n");
                printf("================================================================\n");

                // Lê o valor inteiro a ser removido
                inputVal = readPositiveInt("Digite o valor para remover: ");

                // Chama a função do Core para remover o elemento recursivamente
                status = removeRecursive(tree, inputVal);

                // Processa e exibe a mensagem de retorno da operação
                handleStatus(status);

                // Interrompe o switch
                break;
            }

            // Opção 5: Buscar um valor na árvore
            case 5: {
                // Banner da opção 5
                printf("================================================================\n");
                printf("                  5 - Buscar um Valor na Árvore.                \n");
                printf("================================================================\n");

                // Lê o valor a ser buscado
                inputVal = readPositiveInt("Digite o valor para buscar: ");

                // Chama a função de busca na ABB
                TreeNode* foundNode = findABB(tree, inputVal);

                // Exibe o resultado da busca
                if (foundNode != NULL) {
                    printf("\n[SUCESSO] O valor %d foi ENCONTRADO na arvore!\n\n", foundNode->value);
                } else {
                    printf("\n[NAO ENCONTRADO] O valor %d NAO existe na arvore.\n\n", inputVal);
                }

                // Interrompe o switch
                break;
            }

            // Opção 6: Imprimir todos os elementos da árvore em ordem
            case 6: {
                // Banner da opção 6
                printf("================================================================\n");
                printf("             6 - Imprimir Todos os Elementos em Ordem.          \n");
                printf("================================================================\n");

                // Verifica se a árvore está vazia antes de tentar imprimir
                if (tree == NULL || tree->root == NULL) {
                    printf("\n[ARVORE VAZIA] Nao ha elementos para exibir.\n\n");
                } else {
                    printf("\nElementos da Arvore (Em Ordem): ");
                    // Chama a função recursiva de impressão em ordem simétrica
                    dislpay(tree->root);
                    printf("NULL\n\n");
                }

                // Interrompe o switch
                break;
            }

            // Opção 7: Contar a quantidade total de nós na árvore
            case 7: {
                // Banner da opção 7
                printf("================================================================\n");
                printf("             7 - Contar a Quantidade de Nós na Árvore.          \n");
                printf("================================================================\n");

                // Chama a função que conta a quantidade de nós recursivamente
                int totalNodes = countNode(tree == NULL ? NULL : tree->root);

                // Exibe a contagem total obtida
                printf("\nA arvore possui um total de %d no(s).\n\n", totalNodes);

                // Interrompe o switch
                break;
            }

            // Opção 8: Buscar o menor valor presente na árvore
            case 8: {
                // Banner da opção 8
                printf("================================================================\n");
                printf("               8 - Buscar o Menor Valor da Árvore.              \n");
                printf("================================================================\n");

                // Chama a função para encontrar o nó com o menor valor
                TreeNode* smallNode = findSmallABB(tree);

                // Exibe o resultado encontrado
                if (smallNode != NULL) {
                    printf("\n[SUCESSO] O menor valor na arvore eh: %d\n\n", smallNode->value);
                } else {
                    printf("\n[ARVORE VAZIA] A arvore nao possui elementos.\n\n");
                }

                // Interrompe o switch
                break;
            }

            // Opção 9: Encerrar o programa
            case 9: {
                // Mensagem de despedida ao sair
                printf("\nSaindo do programa... Ate logo!\n\n");

                // Interrompe o switch
                break;  
            }

            // Caso padrão para opções inválidas fora do intervalo (1-9)
            default: {
                // Exibe alerta de opção inválida
                printf("\nOpcao invalida! Digite um numero entre 1 e 9.\n\n");

                // Interrompe o switch
                break;
            }
        }

    } while (option != 9); // Permanece no loop até o usuário escolher a opção 9
}
