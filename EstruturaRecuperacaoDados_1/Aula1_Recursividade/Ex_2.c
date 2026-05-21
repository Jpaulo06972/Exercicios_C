#include <stdio.h>


int Fatorial(int n){
    if (n == 1) return 1;
    else return (n * Fatorial(n - 1));
}

int main(){

    int num, fat;
    
    printf("Digite um numero: ");
    scanf("%d", &num);

    fat = Fatorial(num);

    printf("%d o fatorial eh: %d", num, fat);

    return 0;
}