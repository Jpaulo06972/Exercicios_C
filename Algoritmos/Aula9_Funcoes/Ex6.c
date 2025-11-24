#include <stdio.h>
#include <string.h>
#include <ctype.h> // Necessário para as funções com char

int qtdCarcter(char text[100], char achar){
    int qtd = 0, tamanho;

    tamanho = strlen(text);
    
    for (int i = 0; i < tamanho; i++)
    {
        if(tolower(text[i]) == tolower(achar))
        {
            qtd++;
        }

    }
    return qtd;
}

int main(){
    char find;
    char text[100]; // buffer maior para capturar entradas longas
    int cont = 0;
    
    printf("Digite uma string com no maximo 20 caracteres: ");
    scanf(" %[^\n]", text);
    
    printf("Digite o caracter a ser contado na string: ");
    scanf(" %c", &find);

    cont = qtdCarcter(text, find);

    printf("Na string '%s' possui %d '%c'\n", text, cont, toupper(find));
        
    return 0;
}