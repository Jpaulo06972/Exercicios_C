#include <stdio.h>   // Inclui a biblioteca padrao para operacoes de entrada e saida (printf, scanf)
#include <stdbool.h> // Inclui suporte ao tipo de dado booleano (true/false)

int main()
{
    // 'n' guarda a dimensao de linhas e colunas da matriz quadrada (n x n)
    // 'i' controla o indice da linha e 'j' controla o indice da coluna nos laços
    int n, i, j;

    // Solicita ao usuario que informe a dimensao desejada para a matriz
    printf("Digite o tamanho da Matriz (1 - 20): ");
    scanf("%d", &n);

    // Valida o tamanho fornecido para garantir que fique dentro do intervalo suportado (1 a 20)
    // Mantem o programa em loop ate que o usuario digite um valor seguro, evitando estouro de memoria
    while ((n > 20) || (n <= 0)){
        printf("VALOR INVALIDO!!\n");
        printf("Digite novamente o tamanho dos vetores (1 - 20): ");
        scanf("%d", &n);
    }

    // Cria a matriz de ponto flutuante com a dimensão n x n (VLA - Variable Length Array)
    float matriz[n][n];
    
    // Laço externo: itera pelas linhas da matriz (de 0 ate n-1)
    for(i = 0; i < n; i ++)
    {
        // Laço interno: itera pelas colunas de cada linha (de 0 ate n-1)
        for(j = 0; j < n; j ++)
        {
            // Le o valor em ponto flutuante para a celula especificamente localizada na linha i, coluna j
            printf("Digite o valor da Matriz[%d][%d]: ", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }
    
    printf("Matriz: \n");
    
    // Laço duplo para exibiçao tabular da matriz preenchida
    for(i = 0; i < n; i ++)
    {
        for(j = 0; j < n; j ++)
        {
            // Imprime o valor da celula seguido de uma tabulaçao (\t) para manter o alinhamento visual
            printf("%f\t", matriz[i][j]);
        }
        // Insere uma quebra de linha ao final de cada linha da matriz para formar a grade
        printf("\n");
    }

    // Sinaliza a finalizaçao bem-sucedida do programa ao sistema operacional
    return 0;
}

    