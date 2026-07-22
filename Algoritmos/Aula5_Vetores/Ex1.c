// Inclusão de bibliotecas essenciais para operações de entrada/saída e tipos booleanos
#include <stdio.h>
#include <stdbool.h>

int main()
{
    // Declaração de variáveis para armazenar a quantidade de elementos (n) e o índice de iteração (i)
    int n, i;

    // Solicita ao usuário o tamanho desejado para os vetores
    printf("Digite o tamanho dos vetores (1 - 20): ");
    scanf("%d", &n);

    // Validação de entrada: garante que o tamanho informado esteja estritamente no intervalo de 1 a 20 para evitar acessos inválidos de memória
    while ((n > 20) || (n <= 0)){
        printf("VALOR INVALIDO!!\n");
        printf("Digite novamente o tamanho dos vetores (1 - 20): ");
        scanf("%d", &n);
    }

    // Alocação de Vetores de Tamanho Variável (VLA) com base na quantidade 'n' informada
    int vetX[n];
    int vetY[n];
    int vetZ[n];
        
    // Laço para ler sequencialmente os dados dos vetores X e Y inseridos pelo usuário
    for (i = 0; i < n; i ++)
    {
        // Lê o i-ésimo elemento do vetor X (exibe i+1 para apresentar índice de forma didática ao usuário)
        printf("Digite o %d valor do vetor X: ", i + 1);
        scanf("%d", &vetX[i]);

        // Lê o elemento correspondente da mesma posição no vetor Y
        printf("Digite o %d valor do vetor Y: ", i + 1);
        scanf("%d", &vetY[i]);
    }

    printf("Vetor Z:");
    
    // Laço para realizar a multiplicação elemento a elemento dos vetores X e Y, armazenando em Z
    for (i = 0; i < n; i ++)
    {
        // Multiplica os valores da mesma posição em X e Y e atribui ao vetor Z
        vetZ[i] = vetX[i] * vetY[i];
        // Exibe o valor do elemento resultante
        printf(" %d", vetZ[i]);
    }

    // Sinaliza o encerramento bem-sucedido do programa
    return 0;
}    