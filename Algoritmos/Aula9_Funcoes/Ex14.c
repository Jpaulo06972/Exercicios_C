#include <stdio.h>  // Operacoes de E/S padrao
#include <stdlib.h> // Biblioteca auxiliar C

// Imprime uma matriz bidimensional formatada em linhas e colunas
void printMatriz(int nRows, int nCols, int matriz[nRows][nCols]){

    printf("Matriz: \n");
    
    // Itera sobre cada linha da matriz
    for(int i = 0; i < nRows; i ++)
    {
        // Itera sobre cada coluna da linha atual
        for(int j = 0; j < nCols; j ++)
        {
            printf("%d\t", matriz[i][j]); // Imprime o valor seguido de tabulacao para formatacao visual
        }
        printf("\n"); // Pula linha ao final do processamento de cada linha da matriz
    }
    
}

int main(){
    int m, n;

    // Coleta as dimensoes (linhas e colunas) da matriz
    printf("Digite o tamanho da Matriz[x][y]: ");
    scanf("%d %d", &m, &n);
    
    // Declara a matriz com dimensoes informadas em tempo de execucao (VLA bidimensional)
    int matriz[m][n];

    // Preenche a matriz capturando os elementos posicao a posicao
    for(int i = 0; i < m; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            printf("Digite o valor da Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    // Exibe a matriz formatada chamando a funcao printMatriz
    printMatriz(m, n, matriz);    
    
    return 0; // Termino normal de execucao
}   