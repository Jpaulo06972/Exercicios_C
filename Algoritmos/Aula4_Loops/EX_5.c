// Inclui operacoes de entrada e saida
#include <stdio.h>
// Inclui definicao do tipo booleano (bool, true, false)
#include <stdbool.h>

int main()
{
	// Declara variaveis para armazenar os cinco numeros inteiros a serem ordenados
	int num1, num2, num3, num4, num5;
	// Flag booleana de parada para o algoritmo de ordenacao (Bubble Sort simples sem vetores)
	bool mustStop = false;
    
    // Leitura sequencial dos 5 numeros inteiros a partir do teclado
    printf("Digite um número inteiro: ");
    scanf("%d", &num1);
    
    printf("Digite um número inteiro: ");
    scanf("%d", &num2);
    
    printf("Digite um número inteiro: ");
    scanf("%d", &num3);
    
    printf("Digite um número inteiro: ");
    scanf("%d", &num4);
    
    printf("Digite um número inteiro: ");
    scanf("%d", &num5);
    
    // Repete a ordenacao ate que nenhuma troca de posicao seja realizada em uma passada completa
    while(!mustStop){
        // Assume temporariamente que a lista ja esta ordenada
        mustStop = true;
        
        // Compara o 1º e 2º numeros; se estiverem fora de ordem crescente, troca-os e força uma nova passada
        if (num1 > num2){
            int temp = num1;
            num1 = num2;
            num2 = temp;
            mustStop = false;
        }
        
        // Compara o 2º e 3º numeros; faz a troca se o 2º for maior que o 3º
        if (num2 > num3){
            int temp = num2;
            num2 = num3;
            num3 = temp;
            mustStop = false;
        }
        
        // Compara o 3º e 4º numeros; faz a troca se o 3º for maior que o 4º
        if (num3 > num4){
            int temp = num3;
            num3 = num4;
            num4 = temp;
            mustStop = false;
        }
        
        // Compara o 4º e 5º numeros; faz a troca se o 4º for maior que o 5º
        if (num4 > num5){
            int temp = num4;
            num4 = num5;
            num5 = temp;
            mustStop = false;
        }
        
    }
    // Exibe os 5 numeros em ordem crescente apos a conclusao da ordenacao
    printf("%d, %d, %d, %d, %d", num1, num2, num3, num4, num5);
	return 0;
}