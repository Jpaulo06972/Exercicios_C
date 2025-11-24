#include <stdio.h>

int main(){
    
    double salario, porcent, novoSalario;

    printf("Digite o seu salário atual: ");
    scanf("%lf", &salario);
    
    printf("Digite a percentual de reajuste: ");
    scanf("%lf", &porcent);
    
    novoSalario = salario * (1 + porcent / 100);
    
    printf("\n");
    printf("Salário Atual: %.2lf\n", salario);
    printf("Percentual de Reajuste: %.lf\n", porcent);
    printf("Salário com Reajuste: %.2lf\n", novoSalario);
    
    return 0;

}