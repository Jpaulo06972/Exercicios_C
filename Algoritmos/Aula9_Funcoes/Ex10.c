#include <stdio.h> // Inclui funcionalidade de entrada e saida padrao

// Recebe o tamanho 'sz' e o vetor de tamanho variavel (VLA) para exibicao dos seus elementos
void PrintVector(int sz, int vec[sz]){

    printf("Valores do vetor:\n");
    // Itera por todos os elementos do vetor até atingir a dimensao informada
    for (int i = 0; i < sz; i++) 
    {
        printf("%d\n", vec[i]); // Imprime o elemento correspondente ao indice 'i'
    }
}

int main(){

    int sz;

    // Le o tamanho desejado pelo usuario para dimensionamento dinamico no stack (VLA)
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &sz);

    // Declara o vetor com tamanho definido em tempo de execucao (Variable Length Array)
    int vet[sz];

    // Preenche o vetor coletando os inteiros informados no console
    for (int i = 0; i < sz; i++)
    {
        printf("Digite o valor do vet[%d]: ", i);
        scanf("%d", &vet[i]);
    }

    // Chama a funcao responsavel pela impressao dos elementos contidos no vetor
    PrintVector(sz, vet);

    return 0; // Finalizacao com sucesso
}