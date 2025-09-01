#include <stdio.h>
#include <stdbool.h>

int main()
{
	int num, i; 
    bool eh_primo = true;

	printf("Digite um numero inteiro: ");
	scanf("%d", &num);

    for (i = 2; i <= num / 2; i ++)
    {
        if ((num % i) == 0) eh_primo = false;
    }

    if (eh_primo) 
    {        
        printf("Este numero %d e primo.", num);
    } else { 
        printf("Este numero %d nao eh primo.", num);        
    }

    
	return 0;
}
