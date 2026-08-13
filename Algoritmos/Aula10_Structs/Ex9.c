#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

struct Pessoa{
    char nome[50];
    int idade;
};

void imprimePessoa(struct Pessoa p[], int tamanho){

    struct Pessoa temp;

    int swap = 1;

    while (swap != 0)
    {

        swap = 0;

        for (int i = 0; i < tamanho - 1; i++)
        {

            if (strcmp(p[i].nome, p[i+1].nome) > 0) {
                temp = p[i];
                p[i] = p[i+1];
                p[i+1] = temp;
                swap = 1;
            }
        }
    }

    for (int i = 0; i < tamanho; i++) printf(" %s\n", p[i].nome);
}

int main(){

    int cont = 5;

    struct Pessoa p[cont];

    for(int i = 0; i < cont; i++)
    {
        printf("Digite os Dados da %d\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", p[i].nome);
    }

    imprimePessoa(p, cont);

    return 0;
}
