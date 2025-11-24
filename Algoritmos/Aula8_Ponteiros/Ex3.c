#include <stdio.h>

int main()
{
    double var1 = 7, var2 = 8, multi;
    double *pt1 = &var1;
    double *pt2 = &var2;
    
    multi = *pt1 * *pt2;
    *pt2 = *pt2 / 2;   
    
    printf("Valor da multiplicacao: %f\n", multi);
    printf("Valor da Var1: %f\n", *pt1);
    printf("Novo valor da Var2: %f\n", *pt2);
    
    return 0;
}