// Inclui a biblioteca padrao de entrada e saida de dados
#include <stdio.h>

// Funcao principal que executa o calculo de IMC
int main(){
    
    // Usa 'double' para armazenar peso, altura e o calculo de IMC com casas decimais
    double peso, altura, imc;

    // Solicita o peso em quilogramas
    printf("Digite o seu Peso Atual KG: ");
    // Le o valor do peso digitado pelo usuario
    scanf("%lf", &peso);
    
    // Solicita a altura em metros
    printf("Digite a sua Altura: ");
    // Le o valor da altura digitada pelo usuario
    scanf("%lf", &altura);
    
    // Aplica a formula do IMC: peso dividido pela altura ao quadrado (altura * altura)
    imc = peso / (altura * altura);
    
    // Quebra de linha para separacao estetica no terminal
    printf("\n");
    // Imprime o peso com 1 casa decimal
    printf("Peso: %.1lf\n", peso);
    // Imprime a altura arredondada/sem casas decimais conforme a formatacao original
    printf("Altura: %.lf\n", altura);
    // Imprime o valor do IMC calculated com 2 casas decimais
    printf("IMC: %.2lf\n", imc);
    
    // Encerra a execucao da funcao main retornando 0
    return 0;

}