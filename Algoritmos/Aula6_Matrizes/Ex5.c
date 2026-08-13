#include <stdio.h>
#include <stdbool.h>

int main()
{

    int i, j, k;

    int m, n, y, o;

    printf("Digite a Quantidade de Linhas e Colunas da Matriz A: ");
    scanf("%d %d", &m, &n);

    while ((m < 0) || (n < 0)){
        printf("VALOR INVALIDO!!\n");
        printf("Digite a Quantidade de Linhas e Colunas da Matriz A: ");
        scanf("%d %d", &m, &n);
    }

    printf("Digite a Quantidade de Linhas e Colunas da Matriz B: ");
    scanf("%d %d", &y, &o);

    while ((y < 0) || (o < 0)){
        printf("VALOR INVALIDO!!\n");
        printf("Digite a Quantidade de Linhas e Colunas da Matriz B: ");
        scanf("%d %d", &y, &o);
    }

    int a[m][n];

    int b[y][o];

    int c[m][o];

    if (n == y)
    {

        for (i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                printf("Valor Matriz A[%d][%d]: ", i, j);
                scanf("%d", &a[i][j]);
            }
        }

        printf("\n");
        printf("Matriz A: \n");

        for (i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {

                printf("%d\t", a[i][j]);
            }

            printf("\n");
        }

        printf("\n");

        for (i = 0; i < y; i++)
        {
            for(j = 0; j < o; j++)
            {
                printf("Valor Matriz B[%d][%d]: ", i, j);
                scanf("%d", &b[i][j]);
            }
        }

        printf("\n");
        printf("Matriz B: \n");

        for (i = 0; i < y; i++)
        {
            for(j = 0; j < o; j++)
            {
                printf("%d\t", b[i][j]);
            }
            printf("\n");
        }

        for (i = 0; i < m; i++)
        {

            for(j = 0; j < o; j++)
            {

                c[i][j] = 0;

                for (k = 0; k < n; k++)
                {

                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        printf("\n");
        printf("Matriz C: \n");

        for (i = 0; i < m; i++)
        {
            for(j = 0; j < o; j++)
            {
                printf("%d\t", c[i][j]);
            }
            printf("\n");
        }
    } else {

        printf("Nao eh possivel calcular o produto de A x B");
    }

    return 0;
}
