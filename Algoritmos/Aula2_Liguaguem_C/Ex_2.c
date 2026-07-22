// Inclui a biblioteca padrao para operacoes de entrada e saida de dados
#include <stdio.h>

// Funcao principal onde a execucao do programa se inicia
int main(){
    
    // Declara variaveis inteiras para armazenar a quantidade total de segundos
    // e os valores convertidos para minutos e horas
    int segundos, minutos, horas;

    // Solicita ao usuario que informe o tempo total decorrido em segundos
    printf("Digite a quantidade de segundos: ");
    // Le o valor fornecido pelo usuario e armazena no endereco de memoria de 'segundos'
    scanf("%d", &segundos);
    
    // Converte o total de segundos para minutos dividindo por 60 (divisao inteira desconsidera o resto)
    minutos = segundos / 60;
    // Converte a quantidade de minutos obtida em horas inteiras dividindo novamente por 60
    horas = minutos / 60;
    
    // Imprime na tela o total original em segundos e os equivalentes calculados em minutos e horas
    printf("Quantidade de Segundos: %i\n", segundos);
    printf("Quantidade de Minutos: %i\n", minutos);
    printf("Quantidade de Horas: %i\n", horas);
    
    // Retorna 0 informando que o programa finalizou sem erros
    return 0;

}