#include <stdio.h>

int main()
{
    int var1 = 7, var2 = 8, var3 = 9, soma;
    int *pt1 = &var1;
    int *pt2 = &var2;
    
    soma = *pt1 + *pt2;
    
    pt1 = &var3;
    *pt1 = 10;
    
    printf("A soma de %d + %d: %d\n", var1, var2, soma);
    printf("Novo valor de Var3: %d", var3);
    
    return 0;
}