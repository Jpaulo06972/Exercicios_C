// Inclusão de bibliotecas de padrão de entrada e saída e booleanos
#include <stdio.h>
#include <stdbool.h>

int main()
{
    // Variável para iterar sobre o vetor
    int i = 0;
    // Contador de elementos que estão abaixo da média aritmética calculada
    int menor_Media = 0;
    // Variável em ponto flutuante (double) para acumular o somatório e depois armazenar a média exata
    double media = 0;
    // Vetor contendo 20 números reais em ponto flutuante
    double vet[20] = {25, 4, 18, 13, 20, 7, 35, 6, 11, 12, 27, 2, 41, 45, 14, 33, 16, 8, 10, 21};

    // Primeiro laço: calcula a soma de todos os elementos presentes no vetor
    for (i = 0; i < 20; i ++)
    {
        // Acumula o valor de cada posição do vetor na variável de soma/média
        media = media + vet[i];
    }

    // Calcula a média aritmética dividindo a soma acumulada pela quantidade total de elementos (20.0)
    media = media / 20.0;

    // Segundo laço: compara individualmente cada valor do vetor em relação à média calculada
    for (i = 0; i < 20; i ++)
    {
        // Incrementa o contador caso o valor da posição atual seja menor do que a média obtida
        if (media > vet[i]) menor_Media ++;
    }    

    // Imprime o valor da média calculada
    printf("Quantidade de numeros menor que a media = %f\n", media);
    // Imprime o total de elementos do vetor que ficaram abaixo da média
    printf("Quantidade de numeros menor que a media = %d\n", menor_Media);
        
    // Encerra o programa com o retorno 0
    return 0;
}    