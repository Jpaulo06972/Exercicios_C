#include <stdio.h>  // Biblioteca padrão para entrada/saída de dados (printf, scanf).
#include <stdlib.h> // Biblioteca padrão para alocação dinâmica e liberação de memória (malloc, free).
#include <string.h> // Biblioteca para manipulação de strings (strcpy).
#include <stdbool.h>// Suporte ao tipo de dado booleano nativo (bool, true, false).
#include <ctype.h>  // Manipulação e validação de caracteres.

// Estrutura que representa cada elemento (nó) da Fila de Pacientes.
typedef struct Pacientes{
    char nome[50];          // Armazena o nome do paciente.
    int idade;              // Armazena a idade do paciente.
    int id;                 // Identificador único / número da senha de atendimento do paciente.
    struct Pacientes* next; // Ponteiro para o próximo paciente na ordem de chegada.
} Pacientes;

// Estrutura descritora da Fila (guarda as extremidades do container FIFO - First In, First Out).
typedef struct Fila{
    Pacientes* primeiro; // Ponteiro para o paciente na frente da fila (o próximo a ser atendido).
    Pacientes* ultimo;   // Ponteiro para o paciente no final da fila (o último que chegou).
} Fila;

// Aloca dinamicamente e inicializa um novo nó do tipo Pacientes.
Pacientes* criaNo(char newNome[50], int newIdade, int newId){
    // Aloca a memória necessária para a struct do novo paciente na Heap.
    Pacientes* newNode = (Pacientes*) malloc (sizeof(Pacientes));
    
    // Copia o nome recebido por parâmetro para o campo da estrutura alocada.
    strcpy(newNode->nome, newNome);
    
    // Inicializa a idade e o ID do paciente.
    newNode->idade = newIdade;
    newNode->id = newId;
    
    // Por ser recém-criado, seu próximo ponteiro aponta para NULL (ainda não possui sucessor).
    newNode->next = NULL;
    
    // Retorna o ponteiro para o nó inicializado.
    return newNode;
}

// Insere um novo paciente no final da fila (Operação Enqueue em Fila FIFO).
Fila* adiciona(Fila* f, char newNome[50], int newIdade, int newId){
    // Cria o novo nó de paciente.
    Pacientes* newPaciente = criaNo(newNome, newIdade, newId);

    // Caso a fila esteja completamente vazia:
    // O novo elemento passa a ser simultaneamente o primeiro e o último paciente da fila.
    if (f->ultimo == NULL){ 
        f->primeiro = newPaciente;
        f->ultimo = newPaciente;
    } else {
        // Caso a fila já possua elementos:
        // O atual último elemento aponta para o novo paciente, que passa a ser o novo último.
        f->ultimo->next = newPaciente;
        f->ultimo = newPaciente;
    }
    // Retorna a estrutura de gerenciamento da fila atualizada.
    return f;
}

// Remove o paciente do início da fila (Operação Dequeue em Fila FIFO - atende quem esperou mais tempo).
Fila* remover(Fila* f){
    // Se a fila estiver vazia, não há paciente para remover/atender.
    if(f->primeiro == NULL) return f;

    // Guarda temporariamente o ponteiro do paciente do início (cabeça).
    Pacientes* temp = f->primeiro;
    
    // O ponteiro 'primeiro' avança para o segundo paciente da fila.
    f->primeiro = f->primeiro->next;

    // Se após a remoção a fila ficou totalmente vazia, atualiza também o ponteiro 'ultimo' para NULL.
    if (f->primeiro == NULL){ 
        f->ultimo = NULL;
    }

    // Libera a memória do paciente atendido que foi removido da fila.
    free(temp);
    
    // Retorna a fila atualizada.
    return f;
}

// Verifica se a fila está totalmente sem elementos.
int filaEstaVazia(Fila* f){
    // A fila é considerada vazia se seu primeiro ponteiro for igual a NULL.
    return (f->primeiro == NULL); 
}

// Percorre e imprime na tela todos os pacientes atualmente aguardando na fila na ordem de atendimento.
void imprimeLista(Fila* f){
    Pacientes* current = f->primeiro;
    printf("\n========= FILA DE PACIENTES ATUAL =========\n");
    
    // Avisa caso não haja nenhum paciente na fila.
    if (filaEstaVazia(f)) {
        printf("A fila esta vazia.\n");
    }
    
    // Navega do primeiro até o último paciente exibindo suas informações.
    while(current != NULL){
        printf("Nome: %s\n", current->nome);
        printf("Idade: %d\n", current->idade);
        printf("ID (Senha): %d\n\n", current->id);
        current = current->next; // Avança para o próximo paciente da fila.
    }
    printf("===========================================\n");
}

// Desaloca toda a memória utilizada por todos os nós de pacientes e pela própria estrutura de fila.
void limpaFila(Fila* f){
    Pacientes* current = f->primeiro;
    
    // Varre cada nó da fila liberando a memória alocada individualmente.
    while (current != NULL)
    {
        Pacientes* temp = current;
        current = current->next;
        free(temp);
    }
    
    // Libera a estrutura principal que controlava a fila.
    free(f);
}

// Interface interativa via menu para manipular a fila de atendimento do hospital.
void menu(){
    // Aloca dinamicamente a estrutura de controle da Fila na memória Heap.
    Fila* minhaFila = (Fila*) malloc(sizeof(Fila));
    
    // Inicializa a fila vazia (ambos os ponteiros nulos).
    minhaFila->primeiro = NULL;
    minhaFila->ultimo = NULL;

    int opcao = 0;
    int idCounter = 1; // Contador para geração sequencial e automática das senhas/IDs.

    // Loop do menu principal de opções.
    do
    {
        // Exibição do cabeçalho formatado do menu.
        printf("\n================================================================\n");
        printf("                         MENU - FILA DE PACIENTES                 \n");
        printf("1 - Adicionar Paciente.                                           \n");
        printf("2 - Chamar (Remover) Proximo Paciente.                            \n");
        printf("3 - Exibir Fila de Pacientes.                                     \n");
        printf("4 - Verificar se a fila esta vazia.                               \n");
        printf("5 - Sair.                                                         \n");
        printf("==================================================================\n");
        printf("Digite a opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1: // Enqueue: cadastra e insere um paciente no final da fila.
            {
                printf("================================================================\n");
                printf("                     1 - Adicionar Paciente.                    \n");
                printf("================================================================\n");
                char nome[50];
                int idade;
                
                // Leitura do nome do paciente.
                printf("Digite o Nome: ");
                scanf(" %[^\n]", nome);
                
                // Leitura da idade do paciente.
                printf("Digite a Idade: ");
                scanf(" %d", &idade);
                
                // Enfileira o paciente com a senha gerada sequencialmente.
                minhaFila = adiciona(minhaFila, nome, idade, idCounter);
                
                printf("\nPaciente '%s' (Senha: %d) adicionado a fila.\n", nome, idCounter);
                idCounter++; // Incrementa a senha para o próximo paciente.
                break;
            }

            case 2: // Dequeue: chama/atende o primeiro paciente da fila.
            {
                printf("================================================================\n");
                printf("              2 - Chamar (Remover) Proximo Paciente.            \n");
                printf("================================================================\n");
                
                // Checa se existem pacientes aguardando atendimento.
                if (filaEstaVazia(minhaFila)) {
                    printf("\nA fila esta vazia. Nao ha pacientes para chamar.\n");
                } else {
                    // Armazena temporariamente os dados para exibir mensagem de chamada.
                    char nomeRemovido[50];
                    strcpy(nomeRemovido, minhaFila->primeiro->nome);
                    int idRemovido = minhaFila->primeiro->id;

                    // Remove o primeiro paciente da fila.
                    minhaFila = remover(minhaFila);
                    printf("\nChamando paciente: %s (Senha: %d)\n", nomeRemovido, idRemovido);
                }
                break;
            }

            case 3: // Exibe a lista ordenada de todos os pacientes na fila.
            {
                printf("================================================================\n");
                printf("                   3 - Exibir Fila de Pacientes.                \n");
                printf("================================================================\n");
                
                imprimeLista(minhaFila);
                break;
            }

            case 4: // Checa o status de ocupação da fila.
            {
                printf("================================================================\n");
                printf("                 4 - Verificar se a fila esta vazia.            \n");
                printf("================================================================\n");
                
                if (filaEstaVazia(minhaFila)) {
                    printf("\nA fila ESTA VAZIA.\n");
                } else {
                    printf("\nA fila NAO ESTA VAZIA.\n");
                }
                break;
            }
            case 5: // Encerra a aplicação.
                printf("\nSaindo e limpando a memoria da fila...\n");
                break;                

            default:
                printf("\nValor Invalido. Digite Novamente.\n\n");
                break;
        }

    } while (opcao != 5);
    
    // Executa a limpeza da memória alocada antes do encerramento.
    limpaFila(minhaFila);
}

// Ponto de entrada do programa C.
int main(){
    menu(); // Inicia a execução chamando a função de menu.
    return 0;
}