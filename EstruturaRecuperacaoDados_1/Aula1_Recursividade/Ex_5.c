#include <stdio.h>  // Biblioteca padrão para entrada/saída de dados.
#include <stdbool.h>// Tipo booleano (bool, true, false).
#include <stdlib.h> // Alocação dinâmica de memória (malloc, free).

// Função recursiva de ordenação (baseada no algoritmo Bubble Sort).
// A cada passagem recursiva, empurra o maior elemento para o final do subvetor e reduz o escopo de análise em 1.
void novaPosicao(int n[], int tamanho){

    // Caso base: se o tamanho do subvetor a analisar for menor que 2, ele já está ordenado.
    if (tamanho < 2) return;

    // Varre o vetor comparando pares consecutivos de elementos.
    // 'tamanho - 1' garante a varredura até o penúltimo elemento, comparando com seu sucessor (n[i+1]).
    for (int i = 0; i < tamanho - 1; i++){
        // Se o elemento atual for maior que o próximo, troca a posição de ambos (swap) para garantir a ordem crescente.
        if (n[i] > n[i + 1]){
            int temp = n[i];
            n[i] = n[i + 1];
            n[i + 1] = temp;

        }    
    }
    // Chamada recursiva: como o maior elemento da iteração atual foi posicionado no fim,
    // ordena recursivamente o restante do vetor ignorando a última posição já resolvida.
    novaPosicao(n, tamanho - 1);
}

int main()
{
    // Variável para armazenar a quantidade total de elementos do vetor.
    int qtd;
    
    // Solicita o número de elementos ao usuário.
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &qtd);

    // Aloca dinamicamente o espaço necessário na memória para guardar os 'qtd' inteiros do vetor.
    int *vet = (int*) malloc(qtd * sizeof(int));

    // Preenche o vetor coletando os valores digitados pelo usuário.
    printf("Digite os valores do vetor:\n");
    for (int i = 0; i < qtd; i++){
        printf("Vet[%d]: ", i);
        scanf("%d", &vet[i]);
    }
     
    // Chama a função recursiva para ordenar o vetor.
    novaPosicao(vet, qtd);
    
    // Exibe o vetor devidamente ordenado em ordem crescente.
    printf("\n\nVetor Ordenado:\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");

    // Libera o bloco de memória alocado dinamicamente ao término do uso.
    free(vet);

    return 0;
}
