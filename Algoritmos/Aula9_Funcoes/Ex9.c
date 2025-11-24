#include <stdio.h>
#include <string.h>
#include <ctype.h> // Necessário para as funções com char

void converte(const char* text, char* new){
    int tamanho;

    tamanho = strlen(text);

    for (int i = 0; i < tamanho; i++)
    {
        new[i] = toupper(text[i]);
    }
    
    new[tamanho] = '\0';

}

int main() {
    char text[100], new[100];
    printf("Digite uma string: ");
    scanf(" %[^\n]", text); 

    converte(text, new);

    printf("String convertida: %s\n", new);

    return 0;
}