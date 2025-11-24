#include <stdio.h>

int pares(int a, int b)
{
    if (a < b)
    {
        for (int i = a; i <= b; i++)
        {
            if ((i % 2) == 0)
            {
                printf("%d\n", i);
            }
        }
    }else{
        for (int i = b; i <= a; i++)
        {
            if ((i % 2) == 0)
            {
                printf("%d\n", i);
            }
        }
    }

    return 0;
}

int main()
{
    int num1, num2;
     
    printf("Digite Valor de A: ");
    scanf("%d", &num1);
    printf("Digite Valor de B: ");
    scanf("%d", &num2);

    pares(num1, num2);

    return 0;
}