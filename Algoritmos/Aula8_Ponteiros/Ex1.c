#include <stdio.h>

int main()
{
    int var1 = 7, var2 = 8, temp;
    int *pt1 = &var1;
    int *pt2 = &var2;
    
    temp = *pt1;
    *pt1 = *pt2;
    *pt2 = temp;
    
    printf("Novo valor de Var1 %d\n", var1);
    printf("Novo valor de Var2 %d", var2);

    return 0;
}