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

    for (i = 0; i < n; i ++)
    {
        printf("Digite o %d valor do vetor X: ", i+1);
        scanf("%d", &vetX[i]);
    }

    printf("Vetor X = ");

    for (i = 0; i < n; i ++)
    {   
        int idx = n - i - 1;
        vetY[idx] = vetX[i];
        printf(" %d", vetX[i]);        
    
    }  

    printf("\n");
    printf("Vetor Y = ");

    for (i = 0; i < n; i ++) 
    {
        printf(" %d", vetY[i]); 
    }
    return 0;
}    