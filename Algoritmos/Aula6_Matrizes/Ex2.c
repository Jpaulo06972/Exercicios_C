#include <stdio.h>   // Biblioteca padrao para funcoes de entrada e saida (printf)
#include <stdbool.h> // Biblioteca para suporte a valores booleanos (true/false)

int main()
{
    // 'i' e 'j' sao variaveis de controle para iterar sobre linhas e colunas da matriz
    // 'posi1' e 'posi2' armazenarao os indices da linha e coluna onde o maior valor foi localizado
    int i, j, posi1, posi2;
    
    // Inicializa 'maior' com um valor extremamente baixo (-99999) para garantir que
    // qualquer elemento valido da matriz seja maior que a referencia inicial na primeira comparaçao
    float maior = -99999;
    
    // Declara e inicializa uma matriz de dimensao 5x5 com valores numericos em ponto flutuante
    float matriz[5][5] = {
        {12,45,67,89,23},
        {34,56,78,90,11},
        {22,44,66,88,10},
        {91,73,54,36,18},
        {5,15,25,35,45}
    };   
    
    // Itera por todas as 5 linhas da matriz (indices 0 a 4)
    for(i = 0; i < 5; i ++)
    {
        // Itera por todas as 5 colunas de cada linha (indices 0 a 4)
        for(j = 0; j < 5; j ++)
        {
            // Verifica se o valor na posicao atual matriz[i][j] supera o maior valor conhecido
            if (matriz[i][j] > maior)
            {
                // Atualiza a variavel 'maior' com o novo valor maximo encontrado
                maior = matriz[i][j];
                // Guarda a coordenada exata (linha e coluna) do maior elemento
                posi1 = i;
                posi2 = j;
            }
        }
    }
    
    // Exibe o maior elemento e sua posiçao indexada a partir de 1 (+1) para leitura humana amigavel
    printf("Maior Numero da Matriz[%d][%d]: %f", posi1 + 1, posi2 + 1, maior);
    
    // Retorna 0 para indicar a conclusao bem-sucedida do programa
    return 0;
}

    