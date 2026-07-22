// Inclui biblioteca padrao para funcoes de entrada e saida
#include <stdio.h>
// Inclui biblioteca para suporte a operacoes booleanas
#include <stdbool.h>

int main()
{
	// Inicializa 'num' diferente de 0 para entrar no laço, 'cont' para contagem de elementos digitados,
	// e os extremos 'maior' e 'menor' com limites sentinela
	int num = 1, cont = 0, maior = -99999, menor = 99999; 
    
    // Mantem a leitura repetida de numeros ate que a flag/condicao de parada (num == 0) seja acionada
    while (num != 0)
    {
        printf("Digite um numero(se for 0 sai do codigo): ");
        scanf("%d", &num);

        // Processa apenas numeros validos (diferentes de zero), ignorando o zero como valor de entrada
        if(num != 0)
        {
            // Atualiza o maior valor encontrado ate o momento
            if (num > maior) maior = num;        
            // Atualiza o menor valor encontrado ate o momento
            if (num < menor) menor = num;

            // Incrementa o contador de numeros validos inseridos
            cont ++;
        } else {
            // Interrompe imediatamente a execucao do laço ao receber o valor 0
            break;
        }
    }
    
    // Imprime o total de entradas processadas e os valores maximo e minimo registrados
    printf("Quantidade de numero digitados : %d\n", cont);
	printf("Maior numero : %d\n", maior);
    printf("Menor numero : %d\n", menor);
    
    // Encerra o programa com sucesso
	return 0;
}
