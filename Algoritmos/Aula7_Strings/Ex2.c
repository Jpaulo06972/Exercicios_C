#include <stdio.h>  // Biblioteca padrao para operacoes de entrada e saida (printf, scanf)
#include <string.h> // Biblioteca com funcoes para manipulacao de strings (strlen)
#include <ctype.h>  // Biblioteca com funcoes para tratamento de caracteres (tolower, toupper)

int main(){
    // 'textInvertido' reserva 11 bytes (10 caracteres + 1 caractere nulo '\0' para encerrar a string)
    char textInvertido[11];
    // 'text' aloca um buffer maior (100 caracteres) para leitura segura da entrada do usuario
    char text[100];
    // 'tamanho' guarda a quantidade de caracteres da string e 'i' e o contador do laço
    int tamanho, i;
      
    // Solicita a frase ou palavra ao usuario
    printf("Digite uma string com no maximo 10 caracteres: ");
    // Le caracteres incluindo espacos ate a tecla ENTER (\n) ser pressionada
    scanf(" %[^\n]", text);

    // Calcula a quantidade de caracteres lidos
    tamanho = strlen(text);

    // Loop de validacao para restringir o tamanho maximo a 10 caracteres
    while(tamanho > 10){
        printf("Digite novamente uma string com no maximo 10 caracteres: ");
        scanf(" %[^\n]", text); 
        tamanho = strlen(text);
    }
    
    // Laço de inversao de caracteres: percorre do indice 0 ate 'tamanho - 1'
    for (i = 0; i < tamanho; i++)
    {
        // Posiciona o caractere da posicao atual 'i' na posicao simetrica invertida (tamanho - i - 1)
        // Por exemplo, para tamanho 5: o indice 0 vai para a posicao 4, o indice 1 vai para a posicao 3, etc.
        textInvertido[tamanho - i - 1] = text[i];
        
    }
    
    // Adiciona o terminador nulo '\0' no final do vetor invertido para marcar formalmente o fim da string em linguagem C
    textInvertido[tamanho] = '\0';

    // Exibe a string original e o resultado invertido
    printf("Texto original: %s\n", text);
    printf("Texto invertido: %s\n", textInvertido);

    // Retorna 0 para indicar termino normal do programa
    return 0;
}