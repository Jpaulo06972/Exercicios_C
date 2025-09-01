#include <stdio.h>

int main(){
    
    double peso, altura, imc;

    printf("Digite o seu Peso Atual KG: ");
    scanf("%lf", &peso);
    
    printf("Digite a sua Altura: ");
    scanf("%lf", &altura);
    
    imc = peso / (altura * altura);
    
    printf("\n");
    printf("Peso: %.1lf\n", peso);
    printf("Altura: %.lf\n", altura);
    printf("IMC: %.2lf\n", imc);
    
    return 0;

}