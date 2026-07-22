#include <stdio.h>   // Biblioteca padrao para funcoes de entrada/saida (printf)
#include <stdbool.h> // Inclui suporte a constantes e tipos booleanos

int main()
{
    // 'i' e 'j' sao iteradores para percorrer a matriz 10x10
    // 'posi1' e 'posi2' armazenarao os indices do maior elemento encontrado
    int i, j, posi1, posi2;
    
    // Acumulador inicializado em 0 para somar todos os elementos da 4ª linha (indice 3)
    float soma = 0;
    
    // Inicializado com um valor alto para encontrar o menor elemento da 5ª coluna (indice 4)
    float menor = 99999;
    
    // Inicializado com um valor baixo para identificar o maior elemento na diagonal principal
    float maior = -9999;
    
    // Matriz quadrada 10x10 preenchida com numeros decimais (ponto flutuante)
    float matriz[10][10] = {
        {12,34,56,78,90,11,22,44,66,88},
        {15,25,35,45,55,65,75,85,95,5},
        {19,29,39,49,59,69,79,89,99,9},
        {13,23,33,43,53,63,73,83,93,3},
        {14,24,34,44,54,64,74,84,94,4},
        {16,26,36,46,56,66,76,86,96,6},
        {17,27,37,47,57,67,77,87,97,7},
        {18,28,38,48,58,68,78,88,98,8},
        {21,31,41,51,61,71,81,91,1,2},
        {10,20,30,40,50,60,70,80,90,100}
    };
     
    // Laço externo para percorrer as 10 linhas da matriz
    for(i = 0; i < 10; i ++)
    {
        // Laço interno para percorrer as 10 colunas de cada linha
        for(j = 0; j < 10; j ++)
        {
            // Condicao para identificar se o elemento pertence a linha 4 (indice 3 da matriz)
            if (i == 3)
            {
                // Acumula o valor do elemento atual no somatorio total da linha
                soma = soma + matriz[i][j];
            }

            // Condicao para identificar se o elemento pertence a coluna 5 (indice 4 da matriz)
            if (j == 4)
            {
                // Se o valor na coluna 5 for menor que o registrado, atualiza a variavel 'menor'
                if (matriz[i][j] < menor)
                {
                    menor = matriz[i][j];
                }
            }

            // Testa se o elemento na diagonal principal (onde linha e coluna possuem o mesmo indice i) e o maior
            if(matriz[i][i] > maior) 
            {
                // Guarda o maior valor e armazena suas coordenadas correspondentes
                maior = matriz[i][j];
                posi1 = i;
                posi2 = j;
            }
            
        }
    }
    // Exibe a soma calculada dos elementos da linha 4 (indice 3)
    printf("Soma da linha 4: %f\n", soma);
    // Exibe o menor elemento localizado na coluna 5 (indice 4)
    printf("Menor Elemento da Coluna 5: %f\n", menor);
    // Exibe o maior elemento encontrado para a diagonal principal e suas coordenadas
    printf("Maior Elemento da Diagonal da Matriz[%d][%d]: %f", posi1, posi2, maior);    
    
    // Finaliza o programa indicando execucao bem-sucedida
    return 0;
}

    