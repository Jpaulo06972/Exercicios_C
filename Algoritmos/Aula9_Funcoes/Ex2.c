#include <stdio.h>

double lee()
{
    double num;
    printf("Digite um numero: ");
    scanf("%lf", &num);
    return num;
}

double fracionario(double a)
{
    return a - (int)a;     
}

int main()
{
    double num, frac;

    num = lee();
    frac = fracionario(num);

    printf("Valor lido: %f\n", num);
    printf("Valor da parte fracionaria: %f", frac);
    return 0;
}