// Inclui biblioteca padrao para exibir mensagens no terminal via printf
#include <stdio.h>
// Inclui a biblioteca stdbool.h para utilizar o tipo booleano (bool, true, false) em C
#include <stdbool.h>

int main()
{
    // Define os valores inteiros das variaveis para avaliar o comportamento de expressoes logicas e relacionais
    int a = 20, b = 0, c = 1, d = 10;
    
    // Avalia se o resultado da operacao aritmetica (20 - 0 + 10 = 30) e maior ou igual a 1 (verdadeiro/1)
    bool teste1 = (a - b + d) >= c;
    // Exibe o valor booleano resultante (1 para verdadeiro, 0 para falso)
    printf("A conta 1 é %d\n", teste1);
    
    // Avalia se 'a' e maior que 'a+d' (falso) OU se 'c' e maior que 'b' (verdadeiro); o operador || retorna verdadeiro se ao menos um lado for verdadeiro
    bool teste2 = (a > (a + d)) || (c > b);
    printf("A conta 2 é %d\n", teste2);
    
    // Avalia se produto a*d e maior que c+a E se a e maior que b; o operador && exige que ambas as condicoes sejam verdadeiras
    bool teste3 = ((a * d) > (c + a)) && (a > b);
    printf("A conta 3 é %d\n", teste3);
    
    // Avalia divisao inteira (20/1 = 20 >= 0.9) E se produto (0*10 = 0 < 0, que e falso), resultando em falso
    bool teste4 = (((a + b) / c) >= 0.9) && ((b * d) < 0);
    printf("A conta 4 é %d\n", teste4);
    
    // Testa precedencia de operadores sem parenteses extras ao redor do AND: && possui maior precedencia que ||
    bool teste5 = (((a + c) / d) > 0.3) && (((b - c) < 0)) || ((c + a) > d);
    printf("A conta 5 é %d\n", teste5);
    
    // Demonstra que a adicao explicita de parenteses agrupando o AND mantem a mesma prioridade de avaliacao da expressao anterior
    bool teste6 = ((((a + c) / d) > 0.3) && ((b - c) < 0)) || ((c + a) > d);
    printf("A conta 6 é %d\n", teste6);
    
    // Retorna 0 finalizando a execucao
    return 0;
}
