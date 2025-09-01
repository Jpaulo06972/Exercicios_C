#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, i;

    printf("Digite o tamanho dos vetores (1 - 20): ");
    scanf("%d", &n);

    while ((n > 20) || (n <= 0)){
        printf("VALOR INVALIDO!!\n");
        printf("Digite novamente o tamanho dos vetores (1 - 20): ");
        scanf("%d", &n);
    }

	int vetX[n];
    int vetY[n];
    int vetZ[n];
        
    for (i = 0; i < n; i ++)
    {
        printf("Digite o %d valor do vetor X: ", i + 1);
        scanf("%d", &vetX[i]);

        printf("Digite o %d valor do vetor Y: ", i + 1);
        scanf("%d", &vetY[i]);

        
    }

    printf("Vetor Z:");
    
    for (i = 0; i < n; i ++)
    {
        vetZ[i] = vetX[i] * vetY[i];
        printf(" %d", vetZ[i]);
    }

    return 0;
}    