#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, i, j;

    printf("Digite o tamanho da Matriz (1 - 20): ");
    scanf("%d", &n);

    while ((n > 20) || (n <= 0)){
        printf("VALOR INVALIDO!!\n");
        printf("Digite novamente o tamanho dos vetores (1 - 20): ");
        scanf("%d", &n);
    }

    float matriz[n][n];
    
    for(i = 0; i < n; i ++)
    {
        for(j = 0; j < n; j ++)
        {
            printf("Digite o valor da Matriz[%d][%d]: ", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }
    
    printf("Matriz: \n");
    
    for(i = 0; i < n; i ++)
    {
        for(j = 0; j < n; j ++)
        {
            printf("%f\t", matriz[i][j]);
        }
        printf("\n");
    }

    
    return 0;
}    


    