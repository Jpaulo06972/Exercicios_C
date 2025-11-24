#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h> // Necessário para as funções com char

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
            if (strcmp(p[i].nome, p[i+1].nome) > 0) { // compara nomes
                temp = p[i]; // guarda o da esquerda
                p[i] = p[i+1]; // move o da direita para a esquerda
                p[i+1] = temp; // move o que estava guardado para a direita
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
