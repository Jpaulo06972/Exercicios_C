// Inclusão de bibliotecas necessárias para E/S e tipos booleanos
#include <stdio.h>
#include <stdbool.h>

int main()
{
    // Declaração das variáveis de apoio para controle da dimensão (n) e iteração (i)
    int n, i; 

    // Solicita a quantidade de elementos para os vetores
    printf("Digite o tamanho dos vetores (1 - 20): ");
    scanf("%d", &n);

    // Validação de entrada: garante que 'n' esteja dentro do intervalo de 1 a 20
    while ((n > 20) || (n <= 0)){
        printf("VALOR INVALIDO!!\n");
        printf("Digite novamente o tamanho dos vetores (1 - 20): ");
        scanf("%d", &n);
    }

    // Aloca os vetores X (original) e Y (inverso) com dimensão n
	int vetX[n];
    int vetY[n];

    // Laço para inserção dos valores pelo usuário em vetX
    for (i = 0; i < n; i ++)
    {
        printf("Digite o %d valor do vetor X: ", i+1);
        scanf("%d", &vetX[i]);
    }

    printf("Vetor X = ");

    // Exibe os elementos de X e popula o vetor Y na ordem inversa
    for (i = 0; i < n; i ++)
    {   
        // Calcula o índice correspondente da posição oposta (n - i - 1) para armazenar o valor em vetY de trás para frente
        int idx = n - i - 1;
        vetY[idx] = vetX[i];
        // Imprime o valor original de vetX
        printf(" %d", vetX[i]);        
    
    }  

    printf("\n");
    printf("Vetor Y = ");

    // Exibe o vetor Y, cujos elementos foram copiados na ordem inversa em relação a X
    for (i = 0; i < n; i ++) 
    {
        printf(" %d", vetY[i]); 
    }
    return 0;
}    