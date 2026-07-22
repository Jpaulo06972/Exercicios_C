#include <stdio.h> // Inclui suporte a entrada e saida de dados

int main()
{
    // Declara variaveis de ponto flutuante de dupla precisao (double) e a variavel para o produto
    double var1 = 7, var2 = 8, multi;
    
    // Associa ponteiros de tipo double aos enderecos de memoria de var1 e var2
    double *pt1 = &var1;
    double *pt2 = &var2;
    
    // Efetua a multiplicacao obtendo os valores diretamente dos enderecos de memoria apontados
    multi = *pt1 * *pt2;
    
    // Atualiza diretamente o valor na memoria de var2 dividindo o conteudo apontado por pt2 por 2
    *pt2 = *pt2 / 2;   
    
    // Exibe o resultado do produto guardado na variavel 'multi'
    printf("Valor da multiplicacao: %f\n", multi);
    // Exibe o valor de var1 obtido de forma indireta acessando o ponteiro pt1
    printf("Valor da Var1: %f\n", *pt1);
    // Exibe o novo valor de var2 apos ter sido alterado diretamente na memoria via pt2
    printf("Novo valor da Var2: %f\n", *pt2);
    
    return 0; // Sinaliza o encerramento correto do programa
}