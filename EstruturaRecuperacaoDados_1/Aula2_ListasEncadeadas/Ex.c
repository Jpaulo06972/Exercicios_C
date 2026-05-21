#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h> // Necessário para as funções com char

// Node struct 
typedef struct Cliente{
    char nome[50];
    long cpf;
    long contato;
    struct Cliente* next;

} Cliente;

Cliente* createNode(char n[50], long c, long cont){

    Cliente* NewNode = (Cliente*) malloc (sizeof(Cliente));
    strcpy(NewNode->nome, n);
    NewNode->cpf = c;
    NewNode->contato = cont;
    NewNode->next = NULL;
    return NewNode;
}

Cliente* inserirFront(Cliente* head){

    char newNome[50];
    long newCpf;
    long newContato;
    printf("Digite o Nome: ");
    scanf(" %[^\n]", newNome);
    printf("Digite o Cpf: ");
    scanf(" %ld", &newCpf);
    printf("Digite o Contato: ");
    scanf(" %ld", &newContato);

    Cliente* NewNode = createNode(newNome, newCpf, newContato);
    NewNode->next = head;
    return NewNode;

}

Cliente* inserirBack(Cliente* head, char newNome[50], long newCpf, long newContato){

    Cliente* NewNode = createNode(newNome, newCpf, newContato);
    if(head == NULL) return NewNode;

    Cliente* current = head;

    while(current->next != NULL) current = current->next;
    current->next = NewNode;

    printf("\nCadastro Realizado com Sucesso!!\n\n");
    return head;
}

void free_list(Cliente* head){
    Cliente* current = head;
    while(current != NULL){
        Cliente* temp = current;
        current = current->next;
        free(temp);
    }
}

void print_list(Cliente* head){
    Cliente* current = head;
    
    if (head == NULL) {
        printf("\nNao ha clientes cadastrados.\n");
        return;
    }

    while (current != NULL)
    {
        printf("\nPessoa\n");
        printf("Nome: %s\n", current->nome);
        printf("CPF: %ld\n", current->cpf);
        printf("Contato: %ld\n", current->contato);
        current = current->next;
    }
    printf("\n");
}

Cliente* remove_front(Cliente* head){
    if(head == NULL) return NULL;
    Cliente* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Cliente* remove_back(Cliente* head){
    if (head == NULL) return NULL;
    if (head->next == NULL){
        free(head);
        head = NULL;
        printf("\nCadastro Removido com Sucesso!!!\n\n"); 
        return head;
    }
    Cliente* current = head;
    while (current->next->next != NULL) current = current->next;
    free(current->next);
    current->next = NULL;
    printf("\nCadastro Removido com Sucesso!!!\n\n");
    return head;
}

Cliente* remove_at(Cliente* head, int pos){
    if (head == NULL || pos < 0){
        printf("\nPosicao Invalida ou Lista Vazia!!!\n\n"); // Mensagem ligeiramente ajustada
        return head;
    }
    
    if (pos == 0) {
        printf("\nCadastro Removido com Sucesso!!!\n\n"); // Adiciona feedback para remoção no front
        return remove_front(head);
    }

    Cliente* current = head;
    int index = 0;
    
    // Procura o nó ANTERIOR ao que será removido
    while (current->next != NULL && index < pos - 1){
        current = current->next;
        index++;
    }

    // Se o índice for maior ou igual ao tamanho da lista - 1, a posição é inválida ou o último nó
    if (current->next == NULL || index < pos - 1) { 
         printf("\nPosicao Invalida!!!\n\n");
         return head;
    }
    
    Cliente* temp = current->next;
    current->next = temp->next;
    free(temp);
    printf("\nCadastro Removido com Sucesso!!!\n\n"); 
    return head;
}

void consultarCpf(Cliente* head){
    long cpf_busca;
    printf("Digite o CPF do Cliente a ser Consultado: ");
    scanf(" %ld", &cpf_busca);

    Cliente* current = head;
    bool encontrado = false;

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
            break;
        }
        current = current->next;
    }

    if (!encontrado){
        printf("\nCliente com CPF %ld nao encontrado.\n\n", cpf_busca);
    }
}
// -------------------------------------------------------------

void menu(){

    Cliente* head = NULL;

    int opcao = 0;

    do
    {
        // Pede para usuario escolher a opção..
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
            head = remove_at(head, posicao);
            break;
        }

        case 3:
        {
            printf("================================================================\n");
            printf("                      3 - Exibir Clientes.                      \n");
            printf("================================================================\n");
            print_list(head);
            break;
        }

        case 4:
        {
            printf("================================================================\n");
            printf("                4 - Consultar Cliente pelo CPF.                 \n");
            printf("================================================================\n");
            consultarCpf(head); // Chamada da nova função
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
    
    free_list(head);

    return;

}

int main(){

    menu();
    return 0;
        
}