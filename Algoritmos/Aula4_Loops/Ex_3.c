#include <stdio.h>
#include <stdbool.h>

int main()
{
	int num = 1, i, fat; 
    
    while (num >= 0)
    {
        fat = 1;

        printf("Digite um numero (negativo sai): ");
        scanf("%d", &num);

        if (num < 0) break;

        for (i = 1; i <= num; i ++)
        {
            fat = fat * i; 
        }

        printf("O fatorial de = %d eh %d\n", num, fat);
    }
    
	return 0;
}
