#include <stdio.h>
#include <string.h>

struct Pessoa{
    char nome[50];
    int idade;
};


void imprimePessoa(struct Pessoa p){
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
}

int main(){
    struct Pessoa p;
    
    strcpy(p.nome, "Joao Paulo");
    p.idade = 18;

    imprimePessoa(p);
    return 0;
    
}