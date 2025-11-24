#include <stdio.h>
#include <stdlib.h>

void printMatriz(int nRows, int nCols, int matriz[nRows][nCols]){

    printf("Matriz: \n");
    
    for(int i = 0; i < nRows; i ++)
    {
        for(int j = 0; j < nCols; j ++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    
}

int main(){
    int m, n;

    printf("Digite o tamanho da Matriz[x][y]: ");
    scanf("%d %d", &m, &n);
    
    int matriz[m][n];

    for(int i = 0; i < m; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            printf("Digite o valor da Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    printMatriz(m, n, matriz);    
    
    return 0;
}   