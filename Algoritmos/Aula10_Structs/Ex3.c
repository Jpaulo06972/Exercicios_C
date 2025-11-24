#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[50];
    int idade;
} Pessoa;


const char* maisVelha(const Pessoa *p1, const Pessoa *p2){
    if (p1->idade > p2->idade){
        return p1->nome;
        
    } else{
        return p2->nome;
    }
}

int main(){
   
    Pessoa p1 = {"Joao Paulo", 18};
    Pessoa p2 = {"Maria", 48};
    
    const char *velha = maisVelha(&p1, &p2);
    printf("Pessoa mais velha eh %s", velha);
    return 0;    
}