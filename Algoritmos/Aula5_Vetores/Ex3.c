#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, i, idx_Menor, idx_Maior; 
    int maior = -9999, menor = 9999; 

    printf("Digite o tamanho dos vetores (1 - 20): ");
    scanf("%d", &n);

    while ((n > 20) || (n <= 0)){
        printf("VALOR INVALIDO!!\n");
        printf("Digite novamente o tamanho dos vetores (1 - 20): ");
        scanf("%d", &n);
    }

	int vetX[n];

    for (i = 0; i < n; i ++)
    {
        printf("Digite o %d valor do vetor X: ", i+1);
        scanf("%d", &vetX[i]);
    }

    printf("Vetor X = ");

    for (i = 0; i < n; i ++)
    {
        if (vetX[i] > maior)
        {
            maior = vetX[i];
            idx_Maior = i;        
        }
        if (vetX[i] < menor)
        {
            menor = vetX[i];
            idx_Menor = i;
        } 
    
    }   

    printf("\n");

    printf("Indice do maior numero = %d\n", idx_Maior + 1);
    printf("Indice do menor numero = %d\n", idx_Menor + 1);       

    return 0;
}    