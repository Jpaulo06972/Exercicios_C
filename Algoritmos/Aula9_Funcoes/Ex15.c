#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool MultMatriz(int linhasA, int colunasA, int matrizA[linhasA][colunasA], int linhasB, int colunasB, int matrizB[linhasB][colunasB]){

    if (colunasA != linhasB) {
        printf("Nao eh possivel calcular o produto de A x B\n");
        return false;
    }

    printf("\nMatriz A: \n");

    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasA; j++) {
            printf("%d\t", matrizA[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("\nMatriz B: \n");

    for (int i = 0; i < linhasB; i++) {
        for (int j = 0; j < colunasB; j++) {
            printf("%d\t", matrizB[i][j]);
        }
        printf("\n");
    }

    int matrizC[linhasA][colunasB];

    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasB; j++) {
            matrizC[i][j] = 0;

            for (int k = 0; k < colunasA; k++) {
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }

    printf("\nMatriz C (A x B): \n");

    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasB; j++) {
            printf("%d\t", matrizC[i][j]);
        }
        printf("\n");
    }

    return true;
}

int main(){
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

    for (int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("Valor Matriz A[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\n");

    for (int i = 0; i < y; i++)
    {
        for(int j = 0; j < o; j++)
        {
            printf("Valor Matriz b[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    printf("\n");

    MultMatriz(m, n, a, y, o, b);

    return 0;
}
