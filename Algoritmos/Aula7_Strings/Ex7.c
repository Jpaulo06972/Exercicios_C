#include <stdio.h>  // Biblioteca padrao de entrada e saida (printf, scanf)
#include <string.h> // Biblioteca para manipulacao de strings
#include <ctype.h>  // Biblioteca para funcoes com caracteres

int main(){
    // Buffer alocado com 150 caracteres para suportar frases longas digitadas pelo usuario
    char text[150];
    // Indice de controle 'i' para iterar sobre os caracteres do texto
    int i;
      
    // Solicita uma frase/texto ao usuario
    printf("Digite uma String aqui: ");
    // Le o texto completo com espacos ate o pressionamento da tecla ENTER (\n)
    scanf(" %[^\n]", text);
        
    // Laço para percorrer a string caractere a caractere ate chegar ao terminador nulo '\0'
    for(i = 0; text[i] != '\0'; i++)
    {
        // Se o caractere atual for um espaco em branco (' '), insere uma quebra de linha (\n)
        // Esse procedimento faz com que a proxima palavra seja impressa em uma nova linha no terminal
        if(text[i] == ' ')
        {
            printf("\n");
        }
        // Imprime o caractere atual na tela
        printf("%c", text[i]);
    }

    // Finaliza o programa retornando 0 ao sistema operacional
    return 0;
}