#include <stdio.h>  // Fornece funcoes de entrada e saida padrao (printf, scanf)
#include <string.h> // Fornece funcoes para operacoes em strings (strcpy, strcat, strlen)
#include <ctype.h>  // Fornece funcoes de manipulacao de caracteres

int main(){
    // 'nomeCompleto' aloca 100 caracteres para ser o buffer de destino da junçao do nome com o sobrenome
    char nomeCompleto[100];
    // 'nome' reserva 50 caracteres para capturar o primeiro nome do usuario
    char nome[50];
    // 'sobrenome' reserva 50 caracteres para capturar o sobrenome do usuario
    char sobrenome[50];
      
    // Solicita o primeiro nome
    printf("Digite o seu nome: ");
    // Le o nome descartando brancos iniciais e aceitando espacos ate encontrar a quebra de linha (\n)
    scanf(" %[^\n]", nome);

    // Solicita o sobrenome
    printf("Digite o seu sobrenome: ");
    // Le o sobrenome ate o ENTER (\n)
    scanf(" %[^\n]", sobrenome);

    // Inicializa 'nomeCompleto' copiando o contéudo do primeiro nome para ele
    strcpy(nomeCompleto, nome);
    // Adiciona um espaço em branco ao final da string 'nomeCompleto' para separar nome e sobrenome
    strcat(nomeCompleto, " ");
    // Anexa o sobrenome ao final de 'nomeCompleto', completando a concatenaçao
    strcat(nomeCompleto, sobrenome);

    // Imprime o resultado da string concatenada
    printf("Nome completo: %s\n", nomeCompleto);
    // Exibe o numero total de caracteres contidos na string final através de strlen()
    printf("Tamanho total da string: %lu\n", strlen(nomeCompleto));
    // Acessa diretamente a primeira posicao da string (indice 0)
    printf("Primeira letra: %c\n", nomeCompleto[0]);
    // Obtem o ultimo caractere acessando o indice correspondente a (tamanho total - 1)
    printf("Ultima letra: %c\n", nomeCompleto[strlen(nomeCompleto) - 1]);

    // Retorna 0 informando ao SO que o programa executou corretamente
    return 0;
}