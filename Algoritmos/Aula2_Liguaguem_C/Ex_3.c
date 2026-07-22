// Inclui a biblioteca padrao de E/S para leitura e escrita formatada
#include <stdio.h>

// Funcao principal do programa
int main(){
    
    // Utiliza 'double' para permitir precisao decimal ao lidar com valores monetarios e porcentagens
    double salario, porcent, novoSalario;

    // Pede a insercao do valor atual do salario
    printf("Digite o seu salário atual: ");
    // Le o salario como um numero de ponto flutuante de dupla precisao (%lf)
    scanf("%lf", &salario);
    
    // Pede o percentual de aumento/reajuste a ser aplicado
    printf("Digite a percentual de reajuste: ");
    // Le a taxa percentual informada pelo usuario
    scanf("%lf", &porcent);
    
    // Calcula o novo salario aplicando a taxa de reajuste (multiplica o salario por 1 + porcentagem/100)
    novoSalario = salario * (1 + porcent / 100);
    
    // Insere uma quebra de linha para organizar visualmente a saida dos resultados
    printf("\n");
    // Exibe o salario original formatado com 2 casas decimais
    printf("Salário Atual: %.2lf\n", salario);
    // Exibe o percentual digitado formatado sem casas decimais
    printf("Percentual de Reajuste: %.lf\n", porcent);
    // Exibe o novo salario reajustado com 2 casas decimais
    printf("Salário com Reajuste: %.2lf\n", novoSalario);
    
    // Finaliza o programa retornando 0
    return 0;

}