#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[50];
    int idade;
} Pessoa;


void imprimePessoa(const Pessoa *p){
    printf("Nome: %s\n", p->nome);
    printf("Idade: %d\n", p->idade);
}

int main(){
    Pessoa p;
    
    strcpy(p.nome, "Joao Paulo");
    p.idade = 18;

    imprimePessoa(&p);
    return 0;    
}
