#include <stdio.h>   // Fornece funcoes padrao para exibiçao de texto no terminal (printf)
#include <stdbool.h> // Inclui suporte para dados do tipo booleano

int main()
{
    // Declara os indices de controle 'i' (para linhas) e 'j' (para colunas)
    int i, j;
    
    // Declara e inicializa uma matriz original de dimensao 5x3 de inteiros (5 linhas e 3 colunas)
    int matriz[5][3] = {
        {12,34,56},
        {78,90,11},
        {22,44,66},
        {88,10,99},
        {5,15,25}
    };

    // Declara a matriz transposta com dimensoes invertidas (3 linhas por 5 colunas),
    // pois a transposição de uma matriz de ordem M x N resulta em uma matriz de ordem N x M
    int transp[3][5];
     
    // Percorre cada linha da matriz original (de 0 a 4)
    for(i = 0; i < 5; i ++)
    {
        // Percorre cada coluna da linha atual da matriz original (de 0 a 2)
        for(j = 0; j < 3; j ++)
        {                        
            // Troca a posicao relativa dos elementos: a linha 'i' e coluna 'j' da matriz de origem
            // sao copiadas para a linha 'j' e coluna 'i' da matriz transposta
            transp[j][i] = matriz[i][j];            
        }
    }

    printf("Matriz Normal: \n");
 
    // Exibe a matriz original no seu formato original (5x3)
    for(i = 0; i < 5; i ++)
    {
        for(j = 0; j < 3; j ++)
        {         
            // Imprime o elemento seguido de tabulaçao (\t) para formatacao em colunas
            printf("%d\t", matriz[i][j]);            
        }
        // Insere quebra de linha ao fim de cada linha percorrida
        printf("\n");
    }

    printf("\n");
    printf("Matriz Transposta: \n");

    // Exibe a matriz transposta no seu novo formato (3x5)
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 5; j ++)
        {         
            // Imprime o elemento transposto mantendo a organizacao visual por colunas
            printf("%d\t", transp[i][j]);            
        }
        // Nova linha ao final do envio dos dados de cada linha transposta
        printf("\n");
    }
    
    // Sinaliza o encerramento correto da funcao main
    return 0;
}

    