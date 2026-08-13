#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    char nomeCompleto[100];

    char nome[50];

    char sobrenome[50];

    printf("Digite o seu nome: ");

    scanf(" %[^\n]", nome);

    printf("Digite o seu sobrenome: ");

    scanf(" %[^\n]", sobrenome);

    strcpy(nomeCompleto, nome);

    strcat(nomeCompleto, " ");

    strcat(nomeCompleto, sobrenome);

    printf("Nome completo: %s\n", nomeCompleto);

    printf("Tamanho total da string: %lu\n", strlen(nomeCompleto));

    printf("Primeira letra: %c\n", nomeCompleto[0]);

    printf("Ultima letra: %c\n", nomeCompleto[strlen(nomeCompleto) - 1]);

    return 0;
}
