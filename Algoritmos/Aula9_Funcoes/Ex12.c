#include <stdio.h> // Inclui funcionalidades de entrada e saida padrao

// Ordena um vetor de inteiros em ordem crescente utilizando o algoritmo Bubble Sort (Ordenacao por Bolha)
void OrdenarCrescente(int sz, int vec[sz]){
    int temp;

    // Laço externo controla o numero de passadas completas pelo vetor
    for (int i = 0; i < sz; i++)
    {
        // Laço interno compara elementos adjacentes ate a porcao ainda nao ordenada
        for (int j = 0; j < sz - i - 1; j++)
        { 
            // Se o elemento atual for maior que o proximo, efetua a troca para 'subir' o maior valor
            if (vec[j] > vec[j + 1]){
                temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }

    // Exibe os elementos do vetor ja devidamente ordenados
    printf("Vetor ordenado: ");
    for(int i = 0; i < sz; i++)
    {
        printf(" %d", vec[i]);
    }
    
}

int main(){

    int sz;

    // Solicita o tamanho do vetor ao usuario
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &sz);

    // Aloca o vetor no tamanho definido
    int vet[sz];

    // Preenche o vetor com os elementos digitados pelo usuario
    for (int i = 0; i < sz; i++)
    {
        printf("Digite o valor do vet[%d]: ", i);
        scanf("%d", &vet[i]);
    }

    // Chama a funcao de ordenacao crescente
    OrdenarCrescente(sz, vet);

    return 0; // Finalizacao com sucesso
}