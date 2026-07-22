// Inclui suporte a operacoes de E/S padrao
#include <stdio.h>
// Inclui suporte ao tipo booleano
#include <stdbool.h>

int main()
{
	// Inicializa variaveis: 'num' com valor positivo para entrar no laço while, 'i' para iteracao e 'fat' para guardar a multiplicacao acumulada
	int num = 1, i, fat; 
    
    // Loop para calcular o fatorial de multiplos numeros ate que o usuario digite um valor negativo
    while (num >= 0)
    {
        // Reinicializa o acumulador do fatorial em 1 a cada nova iteracao
        fat = 1;

        printf("Digite um numero (negativo sai): ");
        scanf("%d", &num);

        // Flag de parada: interrompe o laço caso o usuario digite um valor negativo
        if (num < 0) break;

        // Laço para calcular o fatorial (n! = 1 * 2 * 3 * ... * n)
        for (i = 1; i <= num; i ++)
        {
            // Acumula o produto dos inteiros consecutivos
            fat = fat * i; 
        }

        // Exibe o fatorial calculado para o numero fornecido
        printf("O fatorial de = %d eh %d\n", num, fat);
    }
    
    // Encerra o programa
	return 0;
}
