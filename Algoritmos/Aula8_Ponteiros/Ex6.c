#include <stdio.h> // Inclui funcoes de entrada e saida padrao

// Funcao que recebe o primeiro argumento por valor ('a') e o segundo por referencia ('b', um ponteiro)
int Soma(int a, int *b)
{
    // Soma o valor direto de 'a' com o valor contido no endereco apontado por 'b' (*b) e retorna o resultado
    return(a + *b);
}

int main()
{
    // Define os operandos da adicao
    int num1 = 3, num2 = 4;
    
    // Chama a funcao Soma passando num1 por valor e o endereco de memoria (&num2) por referencia
    int s = Soma(num1, &num2); 

    // Imprime o resultado da adicao calculado pela funcao
    printf("Soma = %d", s);    
    return 0; // Finaliza o programa indicando execucao bem-sucedida
}