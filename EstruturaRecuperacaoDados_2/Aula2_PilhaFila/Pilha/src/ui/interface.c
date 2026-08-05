// Inclui biblioteca padrão para entrada e saída de dados (printf, scanf, getchar)
#include <stdio.h>
// Inclui suporte ao tipo booleano (true/false)
#include <stdbool.h>

// Inclui o módulo de lógica da pilha (Core)
#include "../core/pilha_core.h"
// Inclui o cabeçalho das funções da interface (UI)
#include "interface.h"

// --------------------------------------------- //
//        Tratamento e Exibição de Status        //
// --------------------------------------------- //
// Traduz o código de status retornado pelas funções do Core em mensagem amigáveis no console.
void handleStatus(StackStatus status){

    // Avalia o código de status retornado
    switch (status) {
        // Caso de sucesso na operação    
        case STATUS_SUCCESS:
            // Exibe mensagem de confirmação de sucesso
            printf("\n[SUCESSO] Operacao realizada com sucesso!\n\n");
            break;

        // Caso onde o ponteiro para a pilha é nulo (NULL)    
        case ERR_STACK_NULL:    
            // Exibe mensagem de erro de pilha não inicializada
            printf("\n[ERRO] A pilha nao foi inicializada (ponteiro NULL)!\n\n");
            // Sai do switch
            break;
        
        // Caso falte memória RAM no sistema
        case ERR_OUT_OF_MEMORY:
            // Exibe mensagem de memória insuficiente
            printf("\n[ERRO] Memoria RAM insuficiente para realizar a operacao!\n\n");
            // Sai do switch
            break;

        // Caso de tentativa de operação em pilha vazia
        case ERR_STACK_EMPTY:
            // Exibe mensagem de pilha vazia
            printf("\n[ERRO] A pilha esta vazia! Nao ha itens para operar.\n\n");
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
//      Validação de Entrada de Inteiro Positivo //
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
//          Exibição Visual da Pilha             //
// --------------------------------------------- //
// Percorre a pilha da cabeça até a cauda e imprime todos os valores na tela.
void displayStack(const Stack* stack){

    // Valida se a estrutura da pilha existe
    if (stack == NULL){
        // Exibe erro caso o ponteiro seja nulo
        printf("[ERRO] - A pilha informada nao existe!");
        // Encerra a função 
        return;
    }

    // Verifica se a pilha está vazia
    if (stack->head == NULL){
        // Exibe mensagem informativa de pilha vazia
        printf("\n[INFO] A pilha esta vazia!\n\n");
        // Encerra a função 
        return;
    }

    // Cria um ponteiro temporário para percorrer os nós a partir da cabeça
    const StackNode* currentNode = stack->head;

    // Imprime o cabeçalho explicativo da exibição
    printf("\nElementos da pilha (Topo -> Base): ");

    // Percorre todos os nós da pilha imprimindo cada valor
    while (currentNode != NULL){
        // Imprime o valor do nó atual formatado com seta
        printf("%d -> ", currentNode->value);

        // Avança o ponteiro auxiliar para o próximo nó
        currentNode = currentNode->next;
    }

    // Imprime o marcador NULL ao final da sequência para indicar o fim da pilha
    printf("NULL\n\n");
}

// --------------------------------------------- //
//            Menu Principal Interativo          //
// --------------------------------------------- //
// Renderiza a interface do menu e conecta as opções digitadas às funções do Core.
void runMenu(Stack* stack){

    // Variável que guarda a opção escolhida pelo usuário
    int option = 0;

    // Variável temporária para armazenar o número a ser inserido na pilha
    int inputVal;

    // Variável que recebe o status retornado pelas operações do Core
    StackStatus status;

    // Laço principal que mantém o menu ativo até a opção de saída ser escolhida
    do{
        // Cabeçalho visual do menu
        printf("================================================================\n");
        printf("                              MENU                              \n");
        printf("1 - Push (Adicionar valor ao topo da pilha)                     \n");
        printf("2 - Pop (Remover o valor do topo da pilha)                      \n");
        printf("3 - Exibir os elementos da pilha                                \n");
        printf("4 - Sair do programa                                            \n");
        printf("================================================================\n");

        // Solicita a valida a opção desejada do menu
        option = readPositiveInt("Digite a sua opcao: ");

        // Processa a ação correspondente à opção selecionada
        switch (option) {
           
            // Opção 1: Inserir elemento na pilha (Push) 
            case 1: {
                // Banner da opção 1
                printf("================================================================\n");
                printf("                 1 - Adicionar Novo Elemento                    \n");
                printf("================================================================\n");

                // Lê o valor inteiro a ser adicionado
                inputVal = readPositiveInt("Digite o valor para inserir: ");

                // Chama a função do Core para inserir o elemento no topo da pilha
                status = push(stack, inputVal);

                // Processa e exibe a mensagem de retorno da operação
                handleStatus(status);

                // Interrompe o switch
                break;
            }

            // Opção 2: Remover elemento da pilha (Pop)
            case 2: {
                // Banner da opção 2
                printf("================================================================\n");
                printf("                2 - Remover o Elemento do Topo                  \n");
                printf("================================================================\n");

                // Chama função do Core para remover o elemento do topo da pilha
                status = pop(stack);

                // Processa e exibe a mensagem de retorno da operação
                handleStatus(status);

                // Interrompe o switch
                break;
            }

            // Opção 3: Exibir elementos da pilha
            case 3: {
                // Banner da opção 3
                printf("================================================================\n");
                printf("                3 - Exibir Conteudo da Pilha                    \n");
                printf("================================================================\n");

                // Chama a função de exibição visual da pilha
                displayStack(stack);

                // Interrompe o switch
                break;
            }

            // Opção 4: Encerrar o programa
            case 4: {
                // Mensagem de despedida ao sair
                printf("\nSaindo do programa... Ate logo!\n\n");

                // Interrompe o switch
                break;  
            }

            // Caso padrão para opção fora do intervalo
            default: {
                // Exibe alerta de opção inválida
                printf("\nOpcao invalida! Digite um numero valido do menu.\n\n");

                // Interrompe o switch
                break;
            }
        }

    } while (option != 4); // Permanece no loop até o usuário escolher a opção 4
}