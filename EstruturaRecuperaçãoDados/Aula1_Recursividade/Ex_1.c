#include <stdio.h>


int Soma(int n){
    if (n == 1) return 1;
    else return (n + Soma(n - 1));
}

int main(){

    int num, soma;
    
    printf("Digite um numero: ");
    scanf("%d", &num);

    soma = Soma(num);

    printf("%d soma dos numeros: %d", num, soma);

    return 0;
}