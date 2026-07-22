#include <stdio.h> // Biblioteca padrao para operacoes de entrada e saida de dados

int main()
{
    // Define variáveis inteiras com valores iniciais e a variavel soma para armazenar o resultado da adicao
    int var1 = 7, var2 = 8, var3 = 9, soma;
    
    // Inicializa ponteiros com os enderecos de memoria das duas primeiras variaveis
    int *pt1 = &var1;
    int *pt2 = &var2;
    
    // Calcula a soma acessando indiretamente os valores de var1 e var2 através do desreferenciamento dos ponteiros
    soma = *pt1 + *pt2;
    
    // Redireciona o ponteiro pt1 para apontar para uma nova posicao de memoria (var3)
    pt1 = &var3;
    
    // Modifica diretamente o valor armazenado na memoria de var3 através do ponteiro pt1
    *pt1 = 10;
    
    // Exibe a soma calculada anteriormente e o novo valor atribuido a var3 via ponteiro
    printf("A soma de %d + %d: %d\n", var1, var2, soma);
    printf("Novo valor de Var3: %d", var3);
    
    return 0; // Indica que o programa finalizou sem erros
}