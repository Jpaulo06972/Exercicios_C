#include <stdio.h>   // Para operacoes de entrada e saida
#include <stdlib.h>  // Funcoes auxiliares da biblioteca padrao
#include <stdbool.h> // Habilita o tipo booleano (bool, true, false)

// Funcao que valida a regra de multiplicacao matricial, calcula o produto C = A x B e imprime os resultados
bool MultMatriz(int linhasA, int colunasA, int matrizA[linhasA][colunasA], int linhasB, int colunasB, int matrizB[linhasB][colunasB]){

    // Regra da algebra linear: o numero de colunas da Matriz A deve ser estritamente igual ao numero de linhas da Matriz B
    if (colunasA != linhasB) {
        printf("Nao eh possivel calcular o produto de A x B\n");
        return false; // Retorna falso para abortar o calculo
    }
  

    printf("\nMatriz A: \n");
    // Imprime os elementos de Matriz A formatados em tabela
    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasA; j++) {
            printf("%d\t", matrizA[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("\nMatriz B: \n");
    // Imprime os elementos de Matriz B formatados em tabela
    for (int i = 0; i < linhasB; i++) {
        for (int j = 0; j < colunasB; j++) {
            printf("%d\t", matrizB[i][j]);
        }
        printf("\n");
    }

    // Instancia a matriz resultante C com dimensao (linhasA x colunasB)
    int matrizC[linhasA][colunasB];
    
    // Algoritmo de multiplicacao matricial O(N^3)
    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasB; j++) {
            matrizC[i][j] = 0; // Inicializa a celula (i,j) com zero antes do acumulatorio
            // Somatorio do produto escalar da linha i de A pela coluna j de B
            for (int k = 0; k < colunasA; k++) {
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }

    printf("\nMatriz C (A x B): \n");
    // Imprime a matriz resultante C
    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasB; j++) {
            printf("%d\t", matrizC[i][j]);
        }
        printf("\n");
    }
    
    return true; // Retorna verdadeiro indicando multiplicacao bem-sucedida
}


int main(){
    int m, n, y, o;

    // Coleta o tamanho da Matriz A
    printf("Digite a Quantidade de Linhas e Colunas da Matriz A: ");
    scanf("%d %d", &m, &n);

    // Valida a entrada garantindo que nao existam dimensoes negativas
    while ((m < 0) || (n < 0)){
        printf("VALOR INVALIDO!!\n");
        printf("Digite a Quantidade de Linhas e Colunas da Matriz A: ");
        scanf("%d %d", &m, &n);
    }

    // Coleta o tamanho da Matriz B
    printf("Digite a Quantidade de Linhas e Colunas da Matriz B: ");
    scanf("%d %d", &y, &o);

    // Valida a entrada para evitar dimensoes negativas em B
    while ((y < 0) || (o < 0)){
        printf("VALOR INVALIDO!!\n");
        printf("Digite a Quantidade de Linhas e Colunas da Matriz B: ");
        scanf("%d %d", &y, &o);
    }

    // Instancia as matrizes A e B com as dimensoes validadas
    int a[m][n];
    int b[y][o];
    
    // Le os elementos para a Matriz A
    for (int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("Valor Matriz A[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\n");

    // Le os elementos para a Matriz B
    for (int i = 0; i < y; i++)
    {
        for(int j = 0; j < o; j++)
        {
            printf("Valor Matriz b[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    printf("\n");
    // Invoca o calculo da multiplicacao de matrizes
    MultMatriz(m, n, a, y, o, b);
    
    return 0; // Finalizacao com sucesso
}   