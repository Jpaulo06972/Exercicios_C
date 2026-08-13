#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct Pacientes{
    char nome[50];
    int idade;
    int id;
    struct Pacientes* next;
} Pacientes;

typedef struct Fila{
    Pacientes* primeiro;
    Pacientes* ultimo;
} Fila;

Pacientes* criaNo(char newNome[50], int newIdade, int newId){

    Pacientes* newNode = (Pacientes*) malloc (sizeof(Pacientes));

    strcpy(newNode->nome, newNome);

    newNode->idade = newIdade;
    newNode->id = newId;

    newNode->next = NULL;

    return newNode;
}

Fila* adiciona(Fila* f, char newNome[50], int newIdade, int newId){

    Pacientes* newPaciente = criaNo(newNome, newIdade, newId);

    if (f->ultimo == NULL){
        f->primeiro = newPaciente;
        f->ultimo = newPaciente;
    } else {

        f->ultimo->next = newPaciente;
        f->ultimo = newPaciente;
    }

    return f;
}

Fila* remover(Fila* f){

    if(f->primeiro == NULL) return f;

    Pacientes* temp = f->primeiro;

    f->primeiro = f->primeiro->next;

    if (f->primeiro == NULL){
        f->ultimo = NULL;
    }

    free(temp);

    return f;
}

int filaEstaVazia(Fila* f){

    return (f->primeiro == NULL);
}

void imprimeLista(Fila* f){
    Pacientes* current = f->primeiro;
    printf("\n========= FILA DE PACIENTES ATUAL =========\n");

    if (filaEstaVazia(f)) {
        printf("A fila esta vazia.\n");
    }

    while(current != NULL){
        printf("Nome: %s\n", current->nome);
        printf("Idade: %d\n", current->idade);
        printf("ID (Senha): %d\n\n", current->id);
        current = current->next;
    }
    printf("===========================================\n");
}

void limpaFila(Fila* f){
    Pacientes* current = f->primeiro;

    while (current != NULL)
    {
        Pacientes* temp = current;
        current = current->next;
        free(temp);
    }

    free(f);
}

void menu(){

    Fila* minhaFila = (Fila*) malloc(sizeof(Fila));

    minhaFila->primeiro = NULL;
    minhaFila->ultimo = NULL;

    int opcao = 0;
    int idCounter = 1;

    do
    {

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
            case 1:
            {
                printf("================================================================\n");
                printf("                     1 - Adicionar Paciente.                    \n");
                printf("================================================================\n");
                char nome[50];
                int idade;

                printf("Digite o Nome: ");
                scanf(" %[^\n]", nome);

                printf("Digite a Idade: ");
                scanf(" %d", &idade);

                minhaFila = adiciona(minhaFila, nome, idade, idCounter);

                printf("\nPaciente '%s' (Senha: %d) adicionado a fila.\n", nome, idCounter);
                idCounter++;
                break;
            }

            case 2:
            {
                printf("================================================================\n");
                printf("              2 - Chamar (Remover) Proximo Paciente.            \n");
                printf("================================================================\n");

                if (filaEstaVazia(minhaFila)) {
                    printf("\nA fila esta vazia. Nao ha pacientes para chamar.\n");
                } else {

                    char nomeRemovido[50];
                    strcpy(nomeRemovido, minhaFila->primeiro->nome);
                    int idRemovido = minhaFila->primeiro->id;

                    minhaFila = remover(minhaFila);
                    printf("\nChamando paciente: %s (Senha: %d)\n", nomeRemovido, idRemovido);
                }
                break;
            }

            case 3:
            {
                printf("================================================================\n");
                printf("                   3 - Exibir Fila de Pacientes.                \n");
                printf("================================================================\n");

                imprimeLista(minhaFila);
                break;
            }

            case 4:
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
            case 5:
                printf("\nSaindo e limpando a memoria da fila...\n");
                break;

            default:
                printf("\nValor Invalido. Digite Novamente.\n\n");
                break;
        }

    } while (opcao != 5);

    limpaFila(minhaFila);
}

int main(){
    menu();
    return 0;
}
