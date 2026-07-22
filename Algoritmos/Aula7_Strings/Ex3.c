#include <stdio.h>  // Biblioteca padrao de entrada/saida (printf, scanf)
#include <string.h> // Fornece funcoes para manipulacao de strings (strlen, strcmp)
#include <ctype.h>  // Fornece funcoes para analise e tratamento de caracteres (tolower, toupper)

int main(){
    // 'textInvertido' armazena a string invertida (10 caracteres + 1 para o terminador nulo '\0')
    char textInvertido[11];
    // 'text' e o buffer de entrada para capturar a string digitada pelo usuario (ate 100 caracteres)
    char text[100];
    // 'tamanho' guarda a quantidade de caracteres, 'i' e o contador de loop e 'result' guarda a resposta de strcmp()
    int tamanho, i, result;
      
    // Pede a entrada de uma string ao usuario
    printf("Digite uma string com no maximo 10 caracteres: ");
    // Le a frase completa com espacos ate o pressionamento da tecla ENTER (\n)
    scanf(" %[^\n]", text);

    // Obtem o tamanho exato da string digitada
    tamanho = strlen(text);

    // Valida se o tamanho atende a restricao maxima de 10 caracteres
    while(tamanho > 10){
        printf("Digite novamente uma string com no maximo 10 caracteres: ");
        scanf(" %[^\n]", text); 
        tamanho = strlen(text);
    }
    
    // Inverte a string: copia os caracteres de 'text' para 'textInvertido' em ordem contraria
    for (i = 0; i < tamanho; i++)
    {
        // Mapeia o elemento do indice 'i' para a posicao simetrica oposta (tamanho - i - 1)
        textInvertido[tamanho - i - 1] = text[i];
        
    }
    
    // Insere o caractere nulo '\0' no final da string invertida para delimitar seu encerramento na memoria
    textInvertido[tamanho] = '\0';

    // Compara a string original com a string invertida utilizando a funcao strcmp()
    // strcmp() retorna 0 se ambas as strings forem exatamente iguais caractere por caractere
    result = strcmp(text, textInvertido);
    
    // Se a comparacao retornar 0, significa que a palavra/frase e idêntica lida de tras para frente (palindromo)
    if (result == 0){
        printf("Esse texto é palindromo: %s\n", text);
    } else{
        // Caso contrario, as duas versoes sao diferentes, logo nao e um palindromo
        printf("Esse texto não é palindromo: %s\n", text);
    }

    // Retorna 0 para indicar a conclusao bem-sucedida do programa
    return 0;
}