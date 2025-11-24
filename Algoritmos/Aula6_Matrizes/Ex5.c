#include <stdio.h>
#include <stdbool.h>

int main()
{
    int i, j, k;
    int m, n, y, o;

    // Pede o Tamanho da Matriz A
    printf("Digite a Quantidade de Linhas e Colunas da Matriz A: ");
    scanf("%d %d", &m, &n);

    // Verifica se os valores não são menores que 0
    while ((m < 0) || (n < 0)){
        printf("VALOR INVALIDO!!\n");
        printf("Digite a Quantidade de Linhas e Colunas da Matriz A: ");
        scanf("%d %d", &m, &n);
    }

    // Pede o Tamanho da Matriz B
    printf("Digite a Quantidade de Linhas e Colunas da Matriz B: ");
    scanf("%d %d", &y, &o);

    // Verifica se os valores não são menores que 0
    while ((y < 0) || (o < 0)){
        printf("VALOR INVALIDO!!\n");
        printf("Digite a Quantidade de Linhas e Colunas da Matriz B: ");
        scanf("%d %d", &y, &o);
    }

    // Declara as matrizes
    int a[m][n];
    int b[y][o];
    int c[m][o];

    // Verifica se é possivel calcular o produto de A x B
    if (n == y)
    {     
        // Pede os valores da Matriz A
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

        // Exibe Matriz A
        for (i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                printf("%d\t", a[i][j]);
            }
            printf("\n");
        }


        printf("\n");
        // Pede os valores da Matriz B
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

        // Exibe Matriz B
        for (i = 0; i < y; i++)
        {
            for(j = 0; j < o; j++)
            {
                printf("%d\t", b[i][j]);
            }
            printf("\n");
        }


     
        // Monta o Produto de C = A X B
        for (i = 0; i < m; i++)
        {
            for(j = 0; j < o; j++)
            {
                // Ele limpa o cara para não haver lixo
                c[i][j] = 0;

                // No loop o K tem que ser menor que N pois é a quantidade de contas para ele achar quantidade 
                // de vezes que ele vai ter que multiplicar e somar para achar o valor.
                for (k = 0; k < n; k++)
                { 
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        printf("\n");
        printf("Matriz C: \n");

        // Exibe Matriz C
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