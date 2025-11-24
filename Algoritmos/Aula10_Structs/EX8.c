#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Pessoa{
    char nome[50];
    int idade;
}; 


void imprimePessoa(struct Pessoa p[], int tamanho){

    int velha = -9999, indice;
    for (int i = 0; i < tamanho; i++){
    
        if (velha < p[i].idade)
        {
            indice = i;
        }
    }
    printf("\nPessoa Mais Velha");
    printf("\nNome: %s\n", p[indice].nome);
    printf("Idade: %d\n", p[indice].idade);  
}

int main(){
    
    int cont = 2;
    struct Pessoa p[cont];

    for(int i = 0; i < cont; i++)
    {  
        printf("Digite os Dados da %d pessoa\n", i + 1);      
        printf("Nome: ");
        scanf(" %[^\n]", p[i].nome);

        printf("Idade: ");
        scanf("%d", &p[i].idade);
    }

    imprimePessoa(p, cont);      
    
    return 0;    
}
