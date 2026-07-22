#include <stdio.h> // Inclui suporte para impressoes via console

// Funcao iterativa para calculo do fatorial de um numero inteiro positivos
int fatorial(int a)
{
    // Inicializa a variavel acumuladora com 1 (elemento neutro da multiplicacao)
    int fat = 1;

    // Itera 'a' vezes multiplicando o acumulador pelos fatores decrescentes (a, a-1, a-2, ...)
    for(int i = 0; i < a; i++)
    {
        fat = fat * (a - i);
    }     

    // Retorna o resultado final acumulado do fatorial
    return fat;
}

int main()
{
    int num = 7, fat;
    
    // Executa a funcao de fatorial para o numero definido
    fat = fatorial(num);

    // Exibe o numero de entrada e seu respectivo fatorial
    printf("Valor: %d\n", num);
    printf("Valor fatorial: %d", fat);
    return 0; // Termino de execucao
}