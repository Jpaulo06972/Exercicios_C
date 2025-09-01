#include <stdio.h>
#include <stdbool.h>

int main()
{
	int opcao, valor1, valor2;
	int soma, sub, mult, divi;
	
	printf("1.Adição\n");
	printf("2.Subtração\n");
	printf("3.Multiplicação\n");
	printf("4.Divisão\n");
	printf("Escolha uma opção: ");
	scanf("%d", &opcao);
	
	switch(opcao){
	    case 1:
	        printf("Digite o número 1: ");
	        scanf("%d", &valor1);
	        printf("Digite o número 2: ");
	        scanf("%d", &valor2);
	        soma = valor1 + valor2;
	        printf("Resultado da soma = %d", soma);
	        break;
	        
	   case 2:
	        printf("Digite o número 1: ");
	        scanf("%d", &valor1);
	        printf("Digite o número 2: ");
	        scanf("%d", &valor2);
	        soma = valor1 - valor2;
	        printf("Resultado da subtração = %d", soma);
	        break;
	        
	   case 3:
	        printf("Digite o número 1: ");
	        scanf("%d", &valor1);
	        printf("Digite o número 2: ");
	        scanf("%d", &valor2);
	        soma = valor1 * valor2;
	        printf("Resultado da multiplicação = %d", soma);
	        break;
	        
	   case 4:
	        printf("Digite o número 1: ");
	        scanf("%d", &valor1);
	        printf("Digite o número 2: ");
	        scanf("%d", &valor2);
	        soma = valor1 / valor2;
	        printf("Resultado da divisão = %d", soma);
	        break;
	        
	   default:
	        printf("Opção inválida");
	        break;
	        
	}

	
	return 0;
}
