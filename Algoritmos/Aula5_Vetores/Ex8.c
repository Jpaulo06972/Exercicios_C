// Inclusão das bibliotecas padrão para I/O e tipos booleanos
#include <stdio.h>
#include <stdbool.h>

int main()
{
    // Variáveis 'i' e 'j' para controle dos laços encadeados do algoritmo de ordenação
    int i, j;
    // Vetor inicializado com 20 inteiros desordenados
    int vet[20] = {25, 4, 18, 13, 20, 7, 35, 6, 11, 12, 27, 2, 41, 45, 14, 33, 16, 8, 10, 21};
    // Variável auxiliar usada no processo de troca (swap) de posição entre dois elementos
    int temp;

    // Laço externo do Bubble Sort: controla o número total de passadas (N - 1 passadas)
    for (i = 0; i < 20 - 1; i ++){

        // Laço interno do Bubble Sort: compara elementos vizinhos ajustando o limite a cada iteração externa (20 - i - 1)
        for (j = 0; j < 20 - i - 1; j ++){            
            // Condição para ordenação DECRESCENTE: se o elemento atual for MENOR que o seguinte, eles são trocados para que os maiores números fiquem na frente
            if (vet[j] < vet[j+1]){
                // Guarda o valor menor em uma variável temporária
                temp = vet[j];
                // Move o valor maior (posição j+1) para a posição anterior (j)
                vet[j] = vet[j+1];
                // Coloca o valor menor (guardado em temp) na posição posterior (j+1)
                vet[j+1] = temp;
            }            
        }
    }

    printf("Vetor ordenado: ");
    // Exibe a sequência de elementos do vetor organizados em ordem decrescente
    for(i = 0; i < 20; i++){
        printf(" %d", vet[i]);
    }

    // Retorna 0 para indicar término bem-sucedido
    return 0;
}

 