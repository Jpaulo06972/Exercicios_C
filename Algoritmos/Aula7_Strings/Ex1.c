#include <stdio.h>
#include <string.h>
#include <ctype.h> // Necessário para as funções com char

int main(){
    char find;
    char text[100]; // buffer maior para capturar entradas longas
    int tamanho, i;
    int cont = 0;
    
    printf("Digite uma string com no maximo 20 caracteres: ");
    scanf(" %[^\n]", text);

    tamanho = strlen(text);

    while(tamanho > 21){
        printf("Digite novamente uma string com no maximo 20 caracteres: ");
        scanf(" %[^\n]", text); 
        tamanho = strlen(text);
    }

    printf("Digite o caracter a ser contado na string: ");
    scanf(" %c", &find);

    for (i = 0; i < tamanho; i++)
    {
        if(tolower(text[i]) == tolower(find)){
            cont ++;
        }        
    }

    printf("Na string %s possui %d '%c'\n", text, cont, toupper(find));
        
    return 0;
}