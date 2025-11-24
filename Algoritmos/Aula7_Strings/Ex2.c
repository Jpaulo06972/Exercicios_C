#include <stdio.h>
#include <string.h>
#include <ctype.h> // Necessário para as funções com char

int main(){
    char textInvertido[11];
    char text[100]; // buffer maior para capturar entradas longas
    int tamanho, i;
      
    printf("Digite uma string com no maximo 10 caracteres: ");
    scanf(" %[^\n]", text);

    tamanho = strlen(text);

    while(tamanho > 10){
        printf("Digite novamente uma string com no maximo 10 caracteres: ");
        scanf(" %[^\n]", text); 
        tamanho = strlen(text);
    }
    
    for (i = 0; i < tamanho; i++)
    {
        textInvertido[tamanho - i - 1] = text[i];
        
    }
    
    textInvertido[tamanho] = '\0';

    printf("Texto original: %s\n", text);
    printf("Texto invertido: %s\n", textInvertido);

    return 0;
}