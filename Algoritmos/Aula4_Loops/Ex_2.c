#include <stdio.h>
#include <stdbool.h>

int main()
{
	int num = 1, cont = 0, maior = -99999, menor = 99999; 
    
    while (num != 0)
    {
        printf("Digite um numero(se for 0 sai do codigo): ");
        scanf("%d", &num);

        if(num != 0)
        {
            if (num > maior) maior = num;        
            if (num < menor) menor = num;

            cont ++;
        } else {
            break;
        }
    }
    
    printf("Quantidade de numero digitados : %d\n", cont);
	printf("Maior numero : %d\n", maior);
    printf("Menor numero : %d\n", menor);
    
	return 0;
}
