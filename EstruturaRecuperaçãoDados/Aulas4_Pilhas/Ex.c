#include <stdio.h> // Para funções de entrada/saída (printf, scanf).
#include <stdlib.h> // Para alocação de memória (malloc, free).
#include <string.h> // Para manipulação de strings (strcpy).
#include <stdbool.h> // Para usar o tipo 'bool' (true, false).
#include <ctype.h> // Para manipulação de caracteres (não usado aqui, mas estava no original).

// --- ESTRUTURA DO NÓ ---
// Define a estrutura para armazenar os dados de cada elemento (nó) da pilha.
// Trocamos 'Pacientes' por 'Livro' para um exemplo clássico de pilha.
typedef struct Livro{
    char titulo[50];       // Título do livro.
    int anoPublicacao;     // Ano de publicação.
    long isbn;             // ISBN (usando long para um número maior).
    struct Livro* next;    // Ponteiro para o PRÓXIMO nó (o livro abaixo na pilha).
} Livro; // Apelido para 'struct Livro'.

// --- ESTRUTURA DA PILHA ---
// Define a estrutura que gerencia a Pilha como um todo.
// Renomeamos 'ultimo' para 'topo', que é o termo correto para Pilha.
typedef struct Pilha{
    Livro* topo; // Ponteiro para o elemento no topo da pilha.
} Pilha; // Apelido para 'struct Pilha'.

// Função para criar um novo nó (Livro).
Livro* criaNoLivro(char newTitulo[50], int newAno, long newIsbn){
    Livro* novoNo = (Livro*) malloc (sizeof(Livro));
    strcpy(novoNo->titulo, newTitulo);
    novoNo->anoPublicacao = newAno;
    novoNo->isbn = newIsbn;
    novoNo->next = NULL; // O próximo é nulo por padrão.
    return novoNo;
}

// --- PUSH ---
// Insere um novo elemento no TOPO da pilha.
// (O que antes era 'adiciona').
Pilha* empilhar(Pilha* P, char newTitulo[50], int newAno, long newIsbn){
    Livro* novoLivro = criaNoLivro(newTitulo, newAno, newIsbn);
    // O 'next' do novo livro aponta para o antigo topo.
    novoLivro->next = P->topo;
    // O topo da pilha agora é o novo livro.
    P->topo = novoLivro;
    return P;
}

// --- POP ---
// Remove o elemento do TOPO da pilha.
// (O que antes era 'remover').
Pilha* desempilhar(Pilha* P){
    // Se 'topo' for NULL, a pilha já está vazia.
    if(P->topo == NULL) {
        printf("\nA pilha esta vazia. Nao e possivel desempilhar.\n");
        return P; 
    }
    
    Livro* temp = P->topo; // Guarda o topo atual para liberar a memória.
    P->topo = P->topo->next; // O topo passa a ser o próximo elemento.
    
    printf("\nLivro '%s' (ISBN: %ld) removido do topo.\n", temp->titulo, temp->isbn);
    free(temp); // Libera a memória do antigo topo.
    return P;
}

// Verifica se a pilha está vazia.
int pilhaEstaVazia(Pilha* P){
    // A pilha está vazia se o topo for nulo.
    return (P->topo == NULL); 
}

// Imprime os dados de todos os elementos na pilha (do topo para a base).
void imprimePilha(Pilha* P){
    Livro* current = P->topo; // Começa pelo topo.
    printf("\n========= PILHA DE LIVROS ATUAL =========\n");
    if (pilhaEstaVazia(P)) {
        printf("A pilha esta vazia.\n");
    }
    
    while(current != NULL){
        printf("Titulo: %s\n", current->titulo);
        printf("Ano: %d\n", current->anoPublicacao);
        printf("ISBN: %ld\n\n", current->isbn);
        current = current->next; // Move para o próximo (o de baixo).
    }
    printf("===========================================\n");
}

// Libera toda a memória alocada para a pilha.
void limpaPilha(Pilha* P){
    Livro* current = P->topo;
    while (current != NULL){
        Livro* temp = current;
        current = current->next;
        free(temp); // Libera cada nó (Livro).
    }
    free(P); // Libera a estrutura da Pilha em si.
}

// ================================================================
//                       MENU PRINCIPAL
// ================================================================
void menu(){
    // 1. Inicializa a estrutura da Pilha
    Pilha* minhaPilha = (Pilha*) malloc(sizeof(Pilha));
    minhaPilha->topo = NULL; // A pilha começa vazia (topo nulo).

    int opcao = 0;

    do
    {
        // Pede para usuario escolher a opção
        printf("\n================================================================\n");
        printf("                MENU - PILHA DE LIVROS                  \n");
        printf("1 - Empilhar Livro (Push).                                  \n");
        printf("2 - Desempilhar Livro (Pop).                                \n");
        printf("3 - Mostrar Pilha Completa.                                 \n");
        printf("4 - Verificar se a pilha esta vazia.                        \n");
        printf("5 - Sair.                                                   \n");
        printf("================================================================\n");
        printf("Digite a opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1: // Empilhar Livro (Push)
            {
                printf("================================================================\n");
                printf("                     1 - Empilhar Livro.                        \n");
                printf("================================================================\n");
                char titulo[50];
                int ano;
                long isbn;
                
                printf("Digite o Titulo: ");
                scanf(" %[^\n]", titulo); // Espaço para consumir o newline anterior
                printf("Digite o Ano de Publicacao: ");
                scanf(" %d", &ano);
                printf("Digite o ISBN (apenas numeros): ");
                scanf(" %ld", &isbn);
                
                minhaPilha = empilhar(minhaPilha, titulo, ano, isbn);
                
                printf("\nLivro '%s' adicionado ao topo da pilha.\n", titulo);
                break;
            }

            case 2: // Desempilhar Livro (Pop)
            {
                printf("================================================================\n");
                printf("                   2 - Desempilhar Livro.                       \n");
                printf("================================================================\n");
                
                // A função desempilhar() já tem uma verificação se está vazia.
                minhaPilha = desempilhar(minhaPilha);
                break;
            }

            case 3: // Mostrar Pilha Completa
            {
                printf("================================================================\n");
                printf("                  3 - Mostrar Pilha Completa.                   \n");
                printf("================================================================\n");
                
                imprimePilha(minhaPilha);
                break;
            }

            case 4: // Verificar se a pilha está vazia
            {
                printf("================================================================\n");
                printf("                4 - Verificar se a pilha esta vazia.            \n");
                printf("================================================================\n");
                
                if (pilhaEstaVazia(minhaPilha)) {
                    printf("\nA pilha ESTA VAZIA.\n");
                } else {
                    printf("\nA pilha NAO ESTA VAZIA.\n");
                }
                break;
            }
            case 5: // Sair
                printf("\nSaindo e limpando a memoria da pilha...\n");
                break;                

            default:
                printf("\nValor Invalido. Digite Novamente.\n\n");
                break;
        }

    } while (opcao != 5);
    
    // 2. Limpa toda a memória alocada antes de sair
    limpaPilha(minhaPilha);
}

// ================================================================
//                      FUNÇÃO PRINCIPAL
// ================================================================
int main(){
    menu(); // Chama o menu
    return 0;
}