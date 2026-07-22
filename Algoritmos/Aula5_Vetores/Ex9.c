// Inclusão de bibliotecas de suporte para E/S e condicionais booleanas
#include <stdio.h>
#include <stdbool.h>

int main()
{
    // Declaração do índice i e variável de apoio n
    int n, i;
    // Contador para armazenar a quantidade exata de números não-negativos inseridos antes da interrupção
    int cont = 0;
    // Vetor com capacidade máxima para 10 elementos
    int vetX[10];
    
    // Laço para leitura de até 10 valores fornecidos pelo usuário
    for (i = 0; i < 10; i++){
        printf("Digite o valor da posição %d = ", i+1);
        scanf("%d", &vetX[i]);
        
        // Critério de parada: ao detectar um número negativo, o comando 'break' encerra imediatamente o laço de leitura
        if (vetX[i] < 0) break;
        // Caso o valor seja válido (positivo ou zero), incrementa o total de elementos válidos no vetor
        cont ++;
        
    }
    
    // Imprime apenas os valores válidos armazenados até o momento da interrupção (limitado por 'cont')
    for (i = 0; i < cont; i++)printf("%d ", vetX[i]);

    // Finalização do programa com sucesso
    return 0;
}    