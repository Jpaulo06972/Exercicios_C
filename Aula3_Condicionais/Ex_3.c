#include <stdio.h>
#include <stdbool.h>

int main()
{
	float nota; 

	printf("Digite sua nota: ");
	scanf("%f", &nota);

    if (nota < 5)
    {
        printf("Insuficiente");
        
    } else if (nota < 7) {
        printf("Regular");
        
    } else if (nota < 9) {
        printf("Bom");
        
    }else if (nota > 10){
        printf("Nota invalida");
    }else {
        printf("Excelente");
    }

	return 0;
}
