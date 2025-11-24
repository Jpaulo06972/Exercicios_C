#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void novaPosicao(int n[], int tamanho){

    if (tamanho < 2) return;

    for (int i = 0; i < tamanho; i++){
        if (n[i] > n[i + 1]){
            int temp = n[i];
            n[i] = n[i + 1];
            n[i + 1] = temp;

        }    
    }
    novaPosicao(n, tamanho - 1);
}

int main()
{
    int qtd;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &qtd);

    int *vet = (int*) malloc(qtd * sizeof(int));

    printf("Digite os valores do vetor:\n");
    for (int i = 0; i < qtd; i++){
        printf("Vet[%d]: ", i);
        scanf("%d", &vet[i]);
    }
     
    novaPosicao(vet, qtd);
    
    printf("\n\nVetor Ordenado:\n");
    for (int i = 0; i < qtd; i++) { // agora imprime na ordem correta
        printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;
}
