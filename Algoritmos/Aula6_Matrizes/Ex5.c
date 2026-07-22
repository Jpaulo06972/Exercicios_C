#include <stdio.h>   // Biblioteca padrao para funcoes de entrada e saida de dados (printf, scanf)
#include <stdbool.h> // Inclui definições do tipo booleano

int main()
{
    // Variaveis de controle de laços de repetiçao:
    // 'i' (percorre linhas), 'j' (percorre colunas), 'k' (percorre a dimensao comum de multiplicacao)
    int i, j, k;
    // Dimensoes das matrizes:
    // 'm' (linhas de A), 'n' (colunas de A), 'y' (linhas de B), 'o' (colunas de B)
    int m, n, y, o;

    // Pede o tamanho da Matriz A (dimensoes m x n)
    printf("Digite a Quantidade de Linhas e Colunas da Matriz A: ");
    scanf("%d %d", &m, &n);

    // Valida as dimensoes de A para impedir entradas negativas que causariam comportamentos indefinidos
    while ((m < 0) || (n < 0)){
        printf("VALOR INVALIDO!!\n");
        printf("Digite a Quantidade de Linhas e Colunas da Matriz A: ");
        scanf("%d %d", &m, &n);
    }

    // Pede o tamanho da Matriz B (dimensoes y x o)
    printf("Digite a Quantidade de Linhas e Colunas da Matriz B: ");
    scanf("%d %d", &y, &o);

    // Valida as dimensoes de B para impedir valores negativos
    while ((y < 0) || (o < 0)){
        printf("VALOR INVALIDO!!\n");
        printf("Digite a Quantidade de Linhas e Colunas da Matriz B: ");
        scanf("%d %d", &y, &o);
    }

    // Declaraçoes das matrizes dinamicas conforme dimensoes informadas (Variable Length Arrays - VLA):
    // Matriz A tem ordem m x n
    int a[m][n];
    // Matriz B tem ordem y x o
    int b[y][o];
    // Matriz resultante C tera obrigatoriamente a quantidade de linhas de A ('m') e colunas de B ('o')
    int c[m][o];

    // Regra fundamental da algebra linear para multiplicacao matricial:
    // O numero de colunas da matriz A ('n') DEVE ser rigorosamente igual ao numero de linhas da matriz B ('y')
    if (n == y)
    {     
        // Solicita ao usuario a entrada de cada elemento da Matriz A (linha por linha, coluna por coluna)
        for (i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                printf("Valor Matriz A[%d][%d]: ", i, j);
                scanf("%d", &a[i][j]);
            }
        }

        printf("\n");
        printf("Matriz A: \n");

        // Exibe o conteudo da Matriz A organizada em formato tabular
        for (i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                // Tabulaçao para manter o alinhamento das colunas
                printf("%d\t", a[i][j]);
            }
            // Quebra de linha apos imprimir os elementos de cada linha
            printf("\n");
        }


        printf("\n");
        // Solicita a entrada dos elementos para a Matriz B
        for (i = 0; i < y; i++)
        {
            for(j = 0; j < o; j++)
            {
                printf("Valor Matriz B[%d][%d]: ", i, j);
                scanf("%d", &b[i][j]);
            }
        }

        printf("\n");
        printf("Matriz B: \n");

        // Exibe os elementos da Matriz B formatados em grade
        for (i = 0; i < y; i++)
        {
            for(j = 0; j < o; j++)
            {
                printf("%d\t", b[i][j]);
            }
            printf("\n");
        }

        // Algoritmo de multiplicacao de matrizes C = A x B:
        // O laço mais externo 'i' percorre cada linha da Matriz A
        for (i = 0; i < m; i++)
        {
            // O segundo laço 'j' percorre cada coluna da Matriz B
            for(j = 0; j < o; j++)
            {
                // Zera a posicao c[i][j] antes de iniciar a soma do produto escalar (limpa lixo de memoria)
                c[i][j] = 0;

                // O laço 'k' realiza o produto escalar entre a linha 'i' de A e a coluna 'j' de B.
                // O limite 'n' representa a quantidade de termos a multiplicar e somar.
                for (k = 0; k < n; k++)
                { 
                    // Acumula a multiplicacao do elemento A[i][k] pelo elemento B[k][j]
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        printf("\n");
        printf("Matriz C: \n");

        // Exibe a matriz resultante C (dimensao m x o)
        for (i = 0; i < m; i++)
        {
            for(j = 0; j < o; j++)
            {
                printf("%d\t", c[i][j]);
            }
            printf("\n");
        }
    } else {
        // Exibe mensagem de erro caso as dimensoes sejam incompativeis para a multiplicacao
        printf("Nao eh possivel calcular o produto de A x B");
    }

    // Sinaliza encerramento correto do programa
    return 0;
}