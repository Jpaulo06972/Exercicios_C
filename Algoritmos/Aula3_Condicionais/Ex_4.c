// Inclui biblioteca padrao para entrada e saida
#include <stdio.h>
// Inclui biblioteca para suporte a tipos booleanos
#include <stdbool.h>

int main()
{
	// Variaveis para guardar o comprimento das tres arestas do triangulo
	float lado1, lado2, lado3; 

	// Leitura dos comprimentos dos lados informados pelo usuario
	printf("Digite 1 lado do triângulo: ");
	scanf("%f", &lado1);
	
	printf("Digite 2 lado do triângulo: ");
	scanf("%f", &lado2);
	
	printf("Digite 3 lado do triângulo: ");
	scanf("%f", &lado3);
    
    // Verifica a desigualdade triangular: para formar um triangulo valido, a soma de quaisquer dois lados DEVE ser estritamente maior que o terceiro lado.
    // Nota: O codigo original utiliza || (OU), permitindo que a condicao seja aceita se pelo menos um dos lados satisfizer a soma dos outros dois.
    if (((lado1 + lado2)>lado3) || ((lado2 + lado3)>lado1) || ((lado1 + lado3)>lado2)){
        printf("Esse triângulo é válido");
    } else{
        printf("Esse triângulo é inválido");
    }
	return 0;
}
