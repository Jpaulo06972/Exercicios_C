// Inclusão das bibliotecas básicas de suporte para E/S e tipo booleano
#include <stdio.h>
#include <stdbool.h>

int main()
{
    // Variável para iterar sobre as posições do vetor
    int i;
    // Contadores inicializados com zero para evitar acúmulo em lixo de memória
    int cont_Par = 0;
    // Contador específico para identificar números múltiplos de 5
    int cont_M5 = 0;
    // Inicialização direta do vetor com 20 elementos inteiros predefinidos para teste
    int vet[20] = {25, 4, 18, 13, 20, 7, 35, 6, 11, 12, 27, 2, 41, 45, 14, 33, 16, 8, 10, 21};

    // Percorre cada uma das 20 posições do vetor para análise condicional
    for (i = 0; i < 20; i ++)
    {
        // Utiliza o operador de resto da divisão (%) por 2: se der zero, o número é par
        if ((vet[i] % 2) == 0) cont_Par ++;
        // Utiliza o operador de resto da divisão (%) por 5: se der zero, o número é múltiplo de 5
        if ((vet[i] % 5) == 0) cont_M5 ++;
    }

    // Exibe o total acumulado de números pares encontrados no vetor
    printf("Quantidade de numeros pares = %d\n", cont_Par);
    // Exibe o total acumulado de múltiplos de 5 encontrados no vetor
    printf("Quantidade de multiplos de 5 = %d\n", cont_M5);

    // Retorna 0 para sinalizar execução concluída com sucesso
    return 0;
}    