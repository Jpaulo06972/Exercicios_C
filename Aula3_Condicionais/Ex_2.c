#include <stdio.h>
#include <stdbool.h>

int main()
{
	int idade; 
	float peso;

	printf("Digite sua idade: ");
	scanf("%d", &idade);


    printf("Digite seu peso: ");
	scanf("%f", &peso);
	
	if (((idade > 16) && (idade < 69)) && (peso >= 50))
	{
	    printf("Voce este apto para doar sangue");
	}else{
	    printf("Voce nao esta apto para doar sangue");
	}

	return 0;
}
