#include <stdio.h>
#include <stdbool.h>

bool eh_PrimoRec(int n, int divisor){
    
    if (divisor == 1) return true;
    if (n % divisor == 0) return false;
    else return eh_PrimoRec(n, divisor - 1);
}

bool eh_Primo(int n){
    
    if (n <= 2) return (n == 2);
    else return  eh_PrimoRec(n, n - 1);
}

int main()
{
    int num;
    
    printf("Digite um numero: ");
    scanf("%d", &num);
    
    if (eh_Primo(num)) printf("%d eh primo", num);
    else printf("%d nao eh primo", num);

    return 0;
}
