#include <stdio.h>   // Biblioteca padrão para funções de entrada e saída (printf, scanf).
#include <stdlib.h>  // Biblioteca padrão para alocação dinâmica de memória (malloc, free).
#include <string.h>  // Biblioteca para manipulação de cadeias de caracteres (strcpy).
#include <stdbool.h> // Define o tipo de dado booleano nativo (bool, true, false).
#include <ctype.h>   // Fornece funções para verificação e conversão de caracteres.

// Definição da estrutura do nó da lista encadeada (Cliente).
// Cada nó armazena os dados cadastrais do cliente e o ponteiro que o conecta ao próximo nó da lista.
typedef struct Cliente{
    char nome[50];        // Array de caracteres para armazenar o nome do cliente.
    long cpf;             // Inteiro longo para armazenar o CPF (evita estouro de capacidade de inteiros normais).
    long contato;         // Inteiro longo para armazenar o número de telefone/contato.
    struct Cliente* next; // Ponteiro para o próximo nó do tipo 'Cliente' na sequência encadeada.

} Cliente;

// Função responsável pela alocação dinâmica e inicialização de um novo nó da lista.
// Recebe os dados por parâmetro e devolve o ponteiro para a memória recém-alocada.
Cliente* createNode(char n[50], long c, long cont){

    // Reservando espaço na memória heap para a estrutura Cliente.
    Cliente* NewNode = (Cliente*) malloc (sizeof(Cliente));
    
    // Copia a string contendo o nome para o campo correspondente dentro do novo nó.
    strcpy(NewNode->nome, n);
    
    // Atribuição direta dos valores numéricos aos campos da estrutura.
    NewNode->cpf = c;
    NewNode->contato = cont;
    
    // O ponteiro 'next' é inicializado como NULL pois o novo nó ainda não está encadeado a nenhum sucessor.
    NewNode->next = NULL;
    
    // Retorna o ponteiro do novo nó pronto para ser encadeado.
    return NewNode;
}

// Insere um novo nó no início (cabeça) da lista encadeada.
// Complexidade de tempo O(1) - tempo constante.
Cliente* inserirFront(Cliente* head){

    // Buffer local para leitura dos dados cadastrais a partir do teclado.
    char newNome[50];
    long newCpf;
    long newContato;
    
    // Leitura interativa das informações do novo cliente.
    printf("Digite o Nome: ");
    scanf(" %[^\n]", newNome); // Lê a linha completa, incluindo espaços em branco, ignorando o \n inicial.
    printf("Digite o Cpf: ");
    scanf(" %ld", &newCpf);
    printf("Digite o Contato: ");
    scanf(" %ld", &newContato);

    // Aloca o novo nó com os dados lidos.
    Cliente* NewNode = createNode(newNome, newCpf, newContato);
    
    // Faz o novo nó apontar para a antiga cabeça da lista.
    NewNode->next = head;
    
    // Retorna o novo nó, que agora passa a ser a nova cabeça (início) da lista.
    return NewNode;

}

// Insere um novo nó no final (cauda) da lista encadeada.
// Complexidade de tempo O(N) - percorre toda a lista até achar o último ponteiro NULL.
Cliente* inserirBack(Cliente* head, char newNome[50], long newCpf, long newContato){

    // Cria e aloca dinamicamente o novo nó que será inserido ao final.
    Cliente* NewNode = createNode(newNome, newCpf, newContato);
    
    // Caso especial: se a lista estiver vazia, o novo nó torna-se a própria cabeça.
    if(head == NULL) return NewNode;

    // Ponteiro auxiliar de navegação para percorrer a lista sem perder a referência do início (head).
    Cliente* current = head;

    // Percorre os nós sequencialmente até encontrar o último elemento (cujo campo 'next' é NULL).
    while(current->next != NULL) current = current->next;
    
    // Faz o antigo último nó apontar para o novo nó recém-criado.
    current->next = NewNode;

    printf("\nCadastro Realizado com Sucesso!!\n\n");
    
    // Retorna a cabeça original da lista, mantendo a estrutura preservada.
    return head;
}

// Libera toda a memória alocada dinamicamente para os nós da lista encadeada.
// Evita vazamentos de memória (memory leaks) antes do encerramento do programa.
void free_list(Cliente* head){
    Cliente* current = head;
    
    // Itera por todos os nós até o fim da lista.
    while(current != NULL){
        // Guarda a referência do nó atual antes de avançar o ponteiro para o próximo.
        Cliente* temp = current;
        current = current->next;
        
        // Libera a memória do nó que ficou para trás.
        free(temp);
    }
}

// Exibe na tela todos os registros de clientes armazenados na lista encadeada.
void print_list(Cliente* head){
    Cliente* current = head;
    
    // Verificação de lista vazia para feedback ao usuário.
    if (head == NULL) {
        printf("\nNao ha clientes cadastrados.\n");
        return;
    }

    // Percorre a lista do primeiro ao último nó exibindo os campos formatados.
    while (current != NULL)
    {
        printf("\nPessoa\n");
        printf("Nome: %s\n", current->nome);
        printf("CPF: %ld\n", current->cpf);
        printf("Contato: %ld\n", current->contato);
        
        // Avança o ponteiro de navegação para o próximo elemento da lista.
        current = current->next;
    }
    printf("\n");
}

// Remove o primeiro nó da lista (cabeça).
Cliente* remove_front(Cliente* head){
    // Se a lista já estiver vazia, nada precisa ser removido.
    if(head == NULL) return NULL;
    
    // Armazena temporariamente a cabeça atual para poder liberar sua memória posteriormente.
    Cliente* temp = head;
    
    // Atualiza a cabeça para o segundo elemento da lista.
    head = head->next;
    
    // Desaloca o primeiro nó original.
    free(temp);
    
    // Retorna a nova cabeça da lista.
    return head;
}

// Remove o último nó da lista encadeada (cauda).
Cliente* remove_back(Cliente* head){
    // Caso 1: lista vazia.
    if (head == NULL) return NULL;
    
    // Caso 2: lista possui apenas um elemento.
    if (head->next == NULL){
        free(head);
        head = NULL;
        printf("\nCadastro Removido com Sucesso!!!\n\n"); 
        return head;
    }
    
    // Caso 3: lista com 2 ou mais elementos.
    // Navega com 'current' até o PENÚLTIMO nó (cujo next->next é NULL).
    Cliente* current = head;
    while (current->next->next != NULL) current = current->next;
    
    // Libera a memória do último nó (current->next).
    free(current->next);
    
    // O penúltimo nó passa a ser o novo último nó, apontando para NULL.
    current->next = NULL;
    
    printf("\nCadastro Removido com Sucesso!!!\n\n");
    return head;
}

// Remove um nó em uma posição (índice 0-indexado) específica.
Cliente* remove_at(Cliente* head, int pos){
    // Validação de entrada: posição negativa ou lista vazia.
    if (head == NULL || pos < 0){
        printf("\nPosicao Invalida ou Lista Vazia!!!\n\n");
        return head;
    }
    
    // Remoção na posição 0 equivale a remover da frente.
    if (pos == 0) {
        printf("\nCadastro Removido com Sucesso!!!\n\n");
        return remove_front(head);
    }

    Cliente* current = head;
    int index = 0;
    
    // Procura o nó ANTERIOR ao nó que será efetivamente removido (posição pos - 1).
    while (current->next != NULL && index < pos - 1){
        current = current->next;
        index++;
    }

    // Se o próximo nó for NULL ou não atingiu pos - 1, a posição é maior que o tamanho da lista.
    if (current->next == NULL || index < pos - 1) { 
         printf("\nPosicao Invalida!!!\n\n");
         return head;
    }
    
    // Guarda o nó que será removido em 'temp'.
    Cliente* temp = current->next;
    
    // Reformula os ponteiros: ajusta o nó anterior para apontar para o nó seguinte ao removido.
    current->next = temp->next;
    
    // Libera o nó removido da memória.
    free(temp);
    
    printf("\nCadastro Removido com Sucesso!!!\n\n"); 
    return head;
}

// Pesquisa linear na lista encadeada por um cliente a partir de seu CPF.
void consultarCpf(Cliente* head){
    long cpf_busca;
    printf("Digite o CPF do Cliente a ser Consultado: ");
    scanf(" %ld", &cpf_busca);

    Cliente* current = head;
    bool encontrado = false;

    // Itera nó a nó verificando se o CPF coincide com o valor buscado.
    while(current != NULL){
        if (current->cpf == cpf_busca){
            printf("\n================================================================\n");
            printf("                   Cliente Encontrado (CPF: %ld)                   \n", cpf_busca);
            printf("================================================================\n");
            printf("Nome: %s\n", current->nome);
            printf("CPF: %ld\n", current->cpf);
            printf("Contato: %ld\n", current->contato);
            printf("================================================================\n\n");
            encontrado = true;
            break; // Interrompe a busca assim que encontra o registro.
        }
        current = current->next;
    }

    // Se percorreu toda a lista sem encontrar o registro, avisa o usuário.
    if (!encontrado){
        printf("\nCliente com CPF %ld nao encontrado.\n\n", cpf_busca);
    }
}

// Função principal de menu de opções interativo.
void menu(){

    // Inicializa a cabeça da lista como NULL (lista vazia).
    Cliente* head = NULL;

    int opcao = 0;

    // Loop do menu mantido até a escolha da opção de saída (5).
    do
    {
        // Exibe opções do menu interativo
        printf("================================================================\n");
        printf("                              MENU                              \n");
        printf("1 - Cadastrar Cliente.                                          \n");
        printf("2 - Excluir Cliente.                                            \n");
        printf("3 - Exibir Clientes.                                            \n");
        printf("4 - Consultar Cliente pelo CPF.                                 \n");
        printf("5 - Sair.                                                       \n");
        printf("================================================================\n");
        printf("Digite a opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            printf("================================================================\n");
            printf("                     1 - Cadastrar Cliente.                     \n");
            printf("================================================================\n");
            char nome[50];
            long cpf;
            long contato;
            printf("Digite o Nome: ");
            scanf(" %[^\n]", nome);
            printf("Digite o Cpf: ");
            scanf(" %ld", &cpf);
            printf("Digite o Contato: ");
            scanf(" %ld", &contato);
            
            // Insere o novo cliente ao final da lista encadeada.
            head = inserirBack(head, nome, cpf, contato);
            break;
        }

        case 2:
        {
            printf("================================================================\n");
            printf("                      2 - Excluir Cliente.                      \n");
            printf("================================================================\n");
            int posicao;
            printf("Digite a Posicao a ser Removida: "); 
            scanf(" %d", &posicao);
            
            // Remove o nó da posição especificada pelo usuário.
            head = remove_at(head, posicao);
            break;
        }

        case 3:
        {
            printf("================================================================\n");
            printf("                      3 - Exibir Clientes.                      \n");
            printf("================================================================\n");
            // Imprime a lista completa de clientes cadastrados.
            print_list(head);
            break;
        }

        case 4:
        {
            printf("================================================================\n");
            printf("                4 - Consultar Cliente pelo CPF.                 \n");
            printf("================================================================\n");
            // Pesquisa um cliente específico na lista pelo CPF.
            consultarCpf(head);
            break;
        }
        case 5:
            printf("Saindo...\n");
            break;        

        default:
            printf("Valor Invalido Digite Novamente\n\n");
            break;
        }

    } while (opcao != 5);
    
    // Antes de encerrar o programa, libera toda a memória dinamicamente alocada para os nós da lista.
    free_list(head);

    return;

}

// Função de entrada do programa C.
int main(){

    // Executa a interface do menu principal.
    menu();
    return 0;
        
}