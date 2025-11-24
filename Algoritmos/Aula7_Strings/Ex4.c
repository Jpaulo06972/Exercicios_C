#include <stdio.h>
#include <string.h>
#include <ctype.h> // Necessário para as funções com char

int main(){
    char nomeCompleto[100];
    char nome[50];
    char sobrenome[50]; // buffer maior para capturar entradas longas
      
    printf("Digite o seu nome: ");
    scanf(" %[^\n]", nome);

    printf("Digite o seu sobrenome: ");
    scanf(" %[^\n]", sobrenome);

    strcpy(nomeCompleto, nome); // Copia o nome para nomeCompleto
    strcat(nomeCompleto, " "); // Adiciona espaço
    strcat(nomeCompleto, sobrenome); // Adiciona sobrenome

    printf("Nome completo: %s\n", nomeCompleto);
    printf("Tamanho total da string: %lu\n", strlen(nomeCompleto));
    printf("Primeira letra: %c\n", nomeCompleto[0]);
    printf("Ultima letra: %c\n", nomeCompleto[strlen(nomeCompleto) - 1]);

    return 0;
    
}