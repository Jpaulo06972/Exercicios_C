#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    char iniciais[50];

    char nome[150];

    int tamanho, i, j = 0;

    printf("Digite um nome com no maximo 100 caracteres: ");

    scanf(" %[^\n]", nome);

    tamanho = strlen(nome);

    while(tamanho > 100){
        printf("Digite novamente um nome com no maximo 10 0caracteres: ");
        scanf(" %[^\n]", nome);
        tamanho = strlen(nome);
    }

    iniciais[j++] = toupper(nome[0]);

    for (i = 0; i < tamanho; i++)
    {

        if(nome[i] == ' ')
        {

            iniciais[j++] = toupper(nome[i + 1]);
        }

    }

    iniciais[j] = '\0';

    printf("Nome original: %s\n", nome);
    printf("Iniciais: %s\n", iniciais);

    return 0;
}
