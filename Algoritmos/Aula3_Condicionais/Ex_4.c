#include <stdio.h>
#include <stdbool.h>

int main()
{
	float lado1, lado2, lado3; 

	printf("Digite 1 lado do triângulo: ");
	scanf("%f", &lado1);
	
	printf("Digite 2 lado do triângulo: ");
	scanf("%f", &lado2);
	
	printf("Digite 3 lado do triângulo: ");
	scanf("%f", &lado3);
    
    if (((lado1 + lado2)>lado3) || ((lado2 + lado3)>lado1) || ((lado1 + lado3)>lado2)){
        printf("Esse triângulo é válido");
    } else{
        printf("Esse triângulo é inválido");
    }
	return 0;
}





