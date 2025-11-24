#include <stdio.h>

void OrdenarCrescente(int sz, int vec[sz]){
    int temp;

    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz - i - 1; j++)
        { 
            if (vec[j] > vec[j + 1]){
                temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }

    printf("Vetor ordenado: ");
    for(int i = 0; i < sz; i++)
    {
        printf(" %d", vec[i]);
    }
    
}

int main(){

    int sz;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &sz);

    int vet[sz];

    for (int i = 0; i < sz; i++)
    {
        printf("Digite o valor do vet[%d]: ", i);
        scanf("%d", &vet[i]);
    }

    OrdenarCrescente(sz, vet);

    return 0;
}