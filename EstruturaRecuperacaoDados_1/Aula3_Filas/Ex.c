#include <stdio.h> // Inclui a biblioteca padrão de Entrada/Saída (para funções como printf, scanf).
#include <stdlib.h> // Inclui a biblioteca padrão (para funções como malloc, free, exit).
#include <string.h> // Inclui a biblioteca de manipulação de strings (para strcpy).
#include <stdbool.h> // Inclui a biblioteca para usar o tipo booleano (bool, true, false).
#include <ctype.h> // Inclui funções para manipulação de caracteres.

// Define a estrutura para armazenar os dados de cada paciente (será o "nó" da lista).
typedef struct Pacientes{
    char nome[50];         // Array de caracteres para guardar o nome.
    int idade;             // Inteiro para guardar a idade.
    int id;                // Inteiro para guardar o ID de chamada.
    struct Pacientes* next; // Ponteiro para o PRÓXIMO nó 'Pacientes'.
} Pacientes; // Define 'Pacientes' como um apelido para 'struct Pacientes'.

// Define a estrutura que gerencia a Fila como um todo.
typedef struct Fila{
    Pacientes* primeiro; // Ponteiro para o primeiro nó 'Pacientes' na fila.
    Pacientes* ultimo;   // Ponteiro para o último nó 'Pacientes' na fila.
} Fila; // Define 'Fila' como um apelido para 'struct Fila'.

// Função para criar um novo nó do tipo Pacientes.
Pacientes* criaNo(char newNome[50], int newIdade, int newId){
    Pacientes* newNode = (Pacientes*) malloc (sizeof(Pacientes));
    strcpy(newNode->nome, newNome);
    newNode->idade = newIdade;
    newNode->id = newId;
    newNode->next = NULL;
    return newNode;
}

// Insere no final da fila (operação Enqueue)
Fila* adiciona(Fila* f, char newNome[50], int newIdade, int newId){
    Pacientes* newPaciente = criaNo(newNome, newIdade, newId);

    if (f->ultimo == NULL){ // Verifica se a fila está vazia
        f->primeiro = newPaciente;
        f->ultimo = newPaciente;
    } else {
        f->ultimo->next = newPaciente;
        f->ultimo = newPaciente;
    }
    return f;
}

// Remove do INÍCIO da fila (operação Dequeue)
Fila* remover(Fila* f){
    if(f->primeiro == NULL) return f; // Fila vazia, não há o que remover.

    Pacientes* temp = f->primeiro;
    f->primeiro = f->primeiro->next;

    if (f->primeiro == NULL){ // Verifica se, APÓS a remoção, a fila ficou vazia.
        f->ultimo = NULL;
    }

    free(temp);
    return f;
}

// Verifica se a fila está vazia.
int filaEstaVazia(Fila* f){
    // --- CORREÇÃO DE BUG ---
    // O código original usava (f->primeiro = NULL), que é uma ATRIBUIÇÃO.
    // O correto é (f->primeiro == NULL), que é uma COMPARAÇÃO.
    return (f->primeiro == NULL); 
}

// Imprime os dados de todos os pacientes na fila.
void imprimeLista(Fila* f){
    Pacientes* current = f->primeiro;
    printf("\n========= FILA DE PACIENTES ATUAL =========\n");
    if (filaEstaVazia(f)) {
        printf("A fila esta vazia.\n");
    }
    
    while(current != NULL){
        printf("Nome: %s\n", current->nome);
        // --- CORREÇÃO DE BUG ---
        // O código original usava %s para 'idade' e 'id', que são inteiros (int).
        // O correto é usar %d.
        printf("Idade: %d\n", current->idade);
        printf("ID (Senha): %d\n\n", current->id);
        current = current->next;
    }
    printf("===========================================\n");
}

// Libera toda a memória alocada para a fila.
void limpaFila(Fila* f){
    Pacientes* current = f->primeiro;
    while (current != NULL)
    {
        Pacientes* temp = current;
        current = current->next;
        free(temp); // Libera cada nó
    }
    free(f); // Libera a estrutura da Fila
}

// ================================================================
//               NOVO MENU BASEADO NO SEU EXEMPLO
// ================================================================
void menu(){
    // 1. Inicializa a estrutura da Fila
    Fila* minhaFila = (Fila*) malloc(sizeof(Fila));
    minhaFila->primeiro = NULL;
    minhaFila->ultimo = NULL;

    int opcao = 0;
    int idCounter = 1; // Para gerar IDs/Senhas automaticamente

    do
    {
        // Pede para usuario escolher a opção
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
            case 1: // Adicionar Paciente
            {
                printf("================================================================\n");
                printf("                     1 - Adicionar Paciente.                    \n");
                printf("================================================================\n");
                char nome[50];
                int idade;
                
                printf("Digite o Nome: ");
                scanf(" %[^\n]", nome); // Espaço antes de %[^\n] para consumir o newline anterior
                printf("Digite a Idade: ");
                scanf(" %d", &idade);
                
                // Chama a função 'adiciona' do seu código
                minhaFila = adiciona(minhaFila, nome, idade, idCounter);
                
                printf("\nPaciente '%s' (Senha: %d) adicionado a fila.\n", nome, idCounter);
                idCounter++; // Incrementa o ID para o próximo
                break;
            }

            case 2: // Chamar (Remover) Próximo Paciente
            {
                printf("================================================================\n");
                printf("              2 - Chamar (Remover) Proximo Paciente.            \n");
                printf("================================================================\n");
                
                if (filaEstaVazia(minhaFila)) {
                    printf("\nA fila esta vazia. Nao ha pacientes para chamar.\n");
                } else {
                    // Pega o nome do paciente antes de remover (opcional, mas bom para feedback)
                    char nomeRemovido[50];
                    strcpy(nomeRemovido, minhaFila->primeiro->nome);
                    int idRemovido = minhaFila->primeiro->id;

                    // Chama a função 'remove' do seu código
                    minhaFila = remover(minhaFila);
                    printf("\nChamando paciente: %s (Senha: %d)\n", nomeRemovido, idRemovido);
                }
                break;
            }

            case 3: // Exibir Fila de Pacientes
            {
                printf("================================================================\n");
                printf("                   3 - Exibir Fila de Pacientes.                \n");
                printf("================================================================\n");
                
                // Chama a função 'imprimeLista' do seu código
                imprimeLista(minhaFila);
                break;
            }

            case 4: // Verificar se a fila está vazia
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
            case 5: // Sair
                printf("\nSaindo e limpando a memoria da fila...\n");
                break;                

            default:
                printf("\nValor Invalido. Digite Novamente.\n\n");
                break;
        }

    } while (opcao != 5);
    
    // 2. Limpa toda a memória alocada antes de sair
    limpaFila(minhaFila);
}

// ================================================================
//                      FUNÇÃO PRINCIPAL
// ================================================================
int main(){
    menu(); // Chama o menu
    return 0;
}