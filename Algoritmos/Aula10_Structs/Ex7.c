#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h> // Necessário para as funções com char

struct Pessoa{
    char nome[50];
    int idade;
}; 


int imprimePessoa(struct Pessoa p[], int tamanho){
      
    int possui, indice;
    char encontrar[50];
    char achar[50];
        
    printf("\nDigite o nome da pessoa a ser encontrada: ");
    scanf(" %[^\n]", encontrar);

    for (int i = 0; encontrar[i] != '\0'; i++) encontrar[i] = toupper(encontrar[i]);
    
    for (int i = 0; i < tamanho; i++){

        strcpy(achar, p[i].nome);

        for (int j = 0; achar[j] != '\0'; j++) achar[j] = toupper(achar[j]);

        possui = strcmp(achar, encontrar);

        if (possui == 0){
            indice = i;
        }
    }

    
    return indice;
    
}

int main(){
    
    int cont = 2, indice;
    struct Pessoa p[cont];

    for(int i = 0; i < cont; i++)
    {  
        printf("Digite os Dados da %d\n", i + 1);      
        printf("Nome: ");
        scanf(" %[^\n]", p[i].nome);

        printf("Idade: ");
        scanf("%d", &p[i].idade);
    }
    
    indice = imprimePessoa(p, cont);
    printf("Indice da pessoa %d\n", indice);    
    printf("Se for (-1) a pessoal nao foi encontrada");   
    
    return 0;    
}
