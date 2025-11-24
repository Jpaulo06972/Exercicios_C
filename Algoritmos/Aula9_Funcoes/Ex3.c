#include <stdio.h>

int fatorial(int a)
{
    int fat = 1;

    for(int i = 0; i < a; i++)
    {
        fat = fat * (a - i);
    }     

    return fat;
}

int main()
{
    int num = 7, fat;
    
    fat = fatorial(num);

    printf("Valor: %d\n", num);
    printf("Valor fatorial: %d", fat);
    return 0;
}