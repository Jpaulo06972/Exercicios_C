#include <stdio.h>
#include <stdbool.h>

int main()
{
    int i;
    int n = 6;
    int vet[10] = {1,2,3,4,5,6};
    int novoValor = 25;
    int posi = 3;

    for (i = n; i > posi; i--)
    {
        vet[i] = vet[i - 1];
    }
    
    vet[posi] = novoValor;
    
    n ++;

    printf("Vetor atualizado:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
    
    printf("\n");
    
    return 0;
} 

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int i;
    int n = 6;
    int vet[10] = {1,2,3,4,5,6};
    int posi = 2;

    for (i = posi; i < n - 1; i++)
    {
        vet[i] = vet[i + 1];
    }
    
    n --;

    printf("Vetor atualizado:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
    
    printf("\n");
    
    return 0;
}    