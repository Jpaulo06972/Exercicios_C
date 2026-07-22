#include <stdio.h> // Inclui funcoes padrao de entrada e saida

// Funcao auxiliar responsavel por solicitar e ler um numero real do teclado
double lee()
{
    double num;
    printf("Digite um numero: ");
    scanf("%lf", &num); // Le um valor de ponto flutuante de dupla precisao (%lf)
    return num;         // Retorna o valor lido para quem chamou
}

// Funcao que isola e retorna apenas a parte decimal/fracionaria de um numero
double fracionario(double a)
{
    // Subtrai a parte inteira (obtida por conversao explicita/cast para int) do valor real original
    return a - (int)a;     
}

int main()
{
    double num, frac;

    // Obtem a entrada do usuario por meio da funcao dedicada 'lee'
    num = lee();
    
    // Obtem a parte fracionaria do numero chamando a funcao 'fracionario'
    frac = fracionario(num);

    // Apresenta o numero original e sua parte fracionaria isolada
    printf("Valor lido: %f\n", num);
    printf("Valor da parte fracionaria: %f", frac);
    return 0; // Finalizacao correta da execucao
}