#include <stdio.h>

int Soma(int a, int *b)
{
    return(a + *b);
}

int main()
{
    int num1 = 3, num2 = 4;
    int *p = &num2;
    int s = Soma(*p, &num1);
    printf("Soma = %d", s);    
    return 0;
}