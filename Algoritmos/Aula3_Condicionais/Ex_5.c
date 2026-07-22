// Inclui operacoes de entrada e saida padrao
#include <stdio.h>
// Inclui suporte para tipos e literais booleanos
#include <stdbool.h>

int main()
{
	// Declara a opcao de menu e os operandos para as operacoes aritmeticas
	int opcao, valor1, valor2;
	// Declara variaveis para armazenar os resultados das operacoes
	int soma, sub, mult, divi;
	
	// Exibe o menu interativo com as opcoes disponiveis para a calculadora
	printf("1.Adição\n");
	printf("2.Subtração\n");
	printf("3.Multiplicação\n");
	printf("4.Divisão\n");
	printf("Escolha uma opção: ");
	// Captura a escolha do usuario
	scanf("%d", &opcao);
	
	// Estrutura de controle condicional 'switch' para direcionar a execucao conforme a opcao escolhida
	switch(opcao){
	    case 1:
	        // Solicitacao e leitura dos dois operandos para adicao
	        printf("Digite o número 1: ");
	        scanf("%d", &valor1);
	        printf("Digite o número 2: ");
	        scanf("%d", &valor2);
	        // Efetua a adicao e exibe o resultado
	        soma = valor1 + valor2;
	        printf("Resultado da soma = %d", soma);
	        break; // Interrompe o switch para nao executar os casos seguintes
	        
	   case 2:
	        // Solicitacao e leitura dos dois operandos para subtracao
	        printf("Digite o número 1: ");
	        scanf("%d", &valor1);
	        printf("Digite o número 2: ");
	        scanf("%d", &valor2);
	        // Efetua a subtracao e exibe o resultado
	        soma = valor1 - valor2;
	        printf("Resultado da subtração = %d", soma);
	        break;
	        
	   case 3:
	        // Solicitacao e leitura dos dois operandos para multiplicacao
	        printf("Digite o número 1: ");
	        scanf("%d", &valor1);
	        printf("Digite o número 2: ");
	        scanf("%d", &valor2);
	        // Efetua a multiplicacao e exibe o resultado
	        soma = valor1 * valor2;
	        printf("Resultado da multiplicação = %d", soma);
	        break;
	        
	   case 4:
	        // Solicitacao e leitura dos dois operandos para divisao inteira
	        printf("Digite o número 1: ");
	        scanf("%d", &valor1);
	        printf("Digite o número 2: ");
	        scanf("%d", &valor2);
	        // Efetua a divisao inteira e exibe o resultado
	        soma = valor1 / valor2;
	        printf("Resultado da divisão = %d", soma);
	        break;
	        
	   default:
	        // Captura qualquer valor digitado que nao corresponda as opcoes de 1 a 4
	        printf("Opção inválida");
	        break;
	        
	}

	// Finaliza a execucao da funcao main
	return 0;
}
