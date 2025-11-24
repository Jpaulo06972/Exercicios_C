#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    char nome[50];
    int idade;
} Pessoa;


bool imprimePessoa(const Pessoa *p){
    if(p->idade < 18){
        return false;
    } else{
        return true;
    }    
}

int main(){
    bool maior;
    Pessoa p = {"Joao Paulo", 18};
    
    maior = imprimePessoa(&p);
    printf("Pessoa eh maior %d", maior);
    return 0;    
}
