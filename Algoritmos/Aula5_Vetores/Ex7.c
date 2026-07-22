// Inclusão de bibliotecas essenciais para entrada/saída e valores booleanos
#include <stdio.h>
#include <stdbool.h>

int main()
{
    // Variáveis 'i' e 'j' para os laços encadeados do algoritmo de ordenação
    int i, j;
    // Vetor de 20 inteiros a ser ordenado
    int vet[20] = {25, 4, 18, 13, 20, 7, 35, 6, 11, 12, 27, 2, 41, 45, 14, 33, 16, 8, 10, 21};
    // Variável auxiliar para realizar a troca (swap) de valores entre posições vizinhas
    int temp;

    // Laço externo do Bubble Sort: controla a quantidade de passadas necessárias (N-1 passadas)
    for (i = 0; i < 20 - 1; i ++){

        // Laço interno do Bubble Sort: compara elementos adjacentes. A cada passada 'i', o maior elemento restante é posicionado no final, reduzindo o limite de busca (20 - i - 1)
        for (j = 0; j < 20 - i - 1; j ++){            
            // Condição para ordenação crescente: se o elemento atual for maior que o próximo, troca-os de lugar
            if (vet[j] > vet[j+1]){
                // Salva temporariamente o valor da posição atual para não perder o dado
                temp = vet[j];
                // Move o menor valor da posição (j+1) para a posição anterior (j)
                vet[j] = vet[j+1];
                // Atribui o maior valor guardado em 'temp' para a posição posterior (j+1)
                vet[j+1] = temp;
            }            
        }
    }

    printf("Vetor ordenado: ");
    // Laço para imprimir todos os elementos do vetor já devidamente ordenados em ordem crescente
    for(i = 0; i < 20; i++){
        printf(" %d", vet[i]);
    }

    // Sinaliza o sucesso na execução do programa
    return 0;
}

 