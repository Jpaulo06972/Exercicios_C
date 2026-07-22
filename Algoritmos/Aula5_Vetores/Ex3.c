// Inclusão de bibliotecas padrão para manipulação de I/O e valores booleanos
#include <stdio.h>
#include <stdbool.h>

int main()
{
    // Declaração de n (tamanho), i (contador), e variáveis para armazenar a posição (índice) do menor e maior elemento
    int n, i, idx_Menor, idx_Maior; 
    // Valorações extremas de partida para garantir que o primeiro elemento do vetor substitua ambos os valores
    int maior = -9999, menor = 9999; 

    // Solicita o número de elementos a ser inserido no vetor
    printf("Digite o tamanho dos vetores (1 - 20): ");
    scanf("%d", &n);

    // Valida o limite do vetor para que fique estritamente dentro da faixa permitida (1 a 20)
    while ((n > 20) || (n <= 0)){
        printf("VALOR INVALIDO!!\n");
        printf("Digite novamente o tamanho dos vetores (1 - 20): ");
        scanf("%d", &n);
    }

    // Criação do vetor dinâmico vetX com dimensão n
	int vetX[n];

    // Laço para leitura e armazenamento dos dados no vetor vetX
    for (i = 0; i < n; i ++)
    {
        printf("Digite o %d valor do vetor X: ", i+1);
        scanf("%d", &vetX[i]);
    }

    printf("Vetor X = ");

    // Percorre o vetor para localizar onde estão armazenados o maior e o menor valor
    for (i = 0; i < n; i ++)
    {
        // Se encontrar um valor maior que o atual pré-estabelecido, salva tanto o valor quanto a sua posição (índice i)
        if (vetX[i] > maior)
        {
            maior = vetX[i];
            idx_Maior = i;        
        }
        // Se encontrar um valor menor que o atual pré-estabelecido, salva tanto o valor quanto a sua posição (índice i)
        if (vetX[i] < menor)
        {
            menor = vetX[i];
            idx_Menor = i;
        } 
    
    }   

    printf("\n");

    // Imprime a posição (1-indexada) do maior e menor elemento para facilitar a visualização do usuário (somando 1 ao índice base zero)
    printf("Indice do maior numero = %d\n", idx_Maior + 1);
    printf("Indice do menor numero = %d\n", idx_Menor + 1);       

    // Finaliza o fluxo do programa com retorno 0
    return 0;
}    