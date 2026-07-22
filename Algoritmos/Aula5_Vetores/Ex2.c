// Inclusão de bibliotecas de entrada/saída padrão e booleanos
#include <stdio.h>
#include <stdbool.h>

int main()
{
    // Declaração do tamanho do vetor 'n' e índice 'i'
    int n, i; 
    // Inicializa 'maior' com um valor extremamente baixo e 'menor' com um valor elevado para que qualquer número do vetor atualize os limites na primeira comparação
    int maior = -9999, menor = 9999; 

    // Solicita o tamanho do vetor ao usuário
    printf("Digite o tamanho dos vetores (1 - 20): ");
    scanf("%d", &n);

    // Validação de entrada: garante que 'n' esteja dentro dos limites aceitáveis (entre 1 e 20)
    while ((n > 20) || (n <= 0)){
        printf("VALOR INVALIDO!!\n");
        printf("Digite novamente o tamanho dos vetores (1 - 20): ");
        scanf("%d", &n);
    }

    // Alocação de memória para o vetor X de tamanho dinâmico 'n'
	int vetX[n];

    // Laço para preencher o vetor X com os valores informados pelo usuário
    for (i = 0; i < n; i ++)
    {
        printf("Digite o %d valor do vetor X: ", i+1);
        scanf("%d", &vetX[i]);
    }

    printf("Vetor X = ");

    // Percorre o vetor X para exibir seus elementos e determinar simultaneamente os valores máximo e mínimo
    for (i = 0; i < n; i ++)
    {
        // Se o elemento corrente for maior que o valor armazenado em 'maior', atualiza a variável com o novo valor máximo
        if (vetX[i] > maior) maior = vetX[i];        
        // Se o elemento corrente for menor que o valor armazenado em 'menor', atualiza a variável com o novo valor mínimo
        if (vetX[i] < menor) menor = vetX[i];

        // Imprime o elemento corrente do vetor
        printf(" %d", vetX[i]);
    
    }   

    printf("\n");

    // Exibe os maiores e menores valores encontrados no vetor
    printf("Maior numero = %d\n", maior);
    printf("Menor numero = %d\n", menor);       

    // Finaliza o programa retornando código de sucesso 0
    return 0;
}    