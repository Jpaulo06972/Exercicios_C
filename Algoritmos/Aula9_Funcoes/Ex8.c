#include <stdio.h>
#include <string.h>
#include <ctype.h>

int pali(char text[100]){

    int tamanho, result;
    char textInvertido[100];

    tamanho = strlen(text);

    for (int i = 0; i < tamanho; i++)
    {
        textInvertido[tamanho - i - 1] = text[i];
    }

    textInvertido[tamanho] = '\0';

    result = strcmp(text, textInvertido);

    if (result == 0){
        return 1;
    } else{
        return 0;
    }
}

int main(){
    char text[100];
    int eh_palin;

    printf("Digite uma string: ");
    scanf(" %[^\n]", text);

    eh_palin = pali(text);

    if (eh_palin)
    {
        printf("Esse texto eh palindromo: %s\n", text);
    }else {
        printf("Esse texto nao eh palindromo: %s\n", text);
    }
    return 0;
}
