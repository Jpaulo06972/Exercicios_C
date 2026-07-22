// Inclui biblioteca de entrada e saida padrao
#include <stdio.h>
// Inclui biblioteca para trabalhar com o tipo booleano (true/false)
#include <stdbool.h>

int main()
{
	// Declara o numero a ser verificado e a variavel de controle do laço de repeticao
	int num, i; 
    // Flag booleana assumindo inicialmente que o numero e primo (true)
    bool eh_primo = true;

	// Solicita a entrada do numero inteiro ao usuario
	printf("Digite um numero inteiro: ");
	scanf("%d", &num);

    // Itera do menor divisor possivel (2) ate a metade do numero (num / 2)
    // Otimizacao: nenhum numero possui divisores inteiros proprios maiores que sua metade
    for (i = 2; i <= num / 2; i ++)
    {
        // Se encontrar qualquer divisor com resto zero, o numero nao e primo
        if ((num % i) == 0) eh_primo = false;
    }

    // Verifica o estado da flag apos testar as divisoes
    if (eh_primo) 
    {        
        // Exibe mensagem confirmando a primalidade do numero
        printf("Este numero %d e primo.", num);
    } else { 
        // Exibe mensagem informando que o numero possui divisores alem de 1 e dele mesmo
        printf("Este numero %d nao eh primo.", num);        
    }

    // Encerra o programa
	return 0;
}
