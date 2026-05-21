#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool eh_PrimoRec(int n, int divisor){

    if (n <= 1) return false;
    if (divisor == 1) return true; 
    if (n % divisor == 0) return false;
    
    return eh_PrimoRec(n, divisor - 1);
}

int contaPrimos(int n){
    if (n < 2) return 0;
    if (eh_PrimoRec(n, n -1 )) return 1 + contaPrimos(n - 1);
    else return contaPrimos(n - 1);
}

int preenche(int n, int *vetor, int index){
    if (n < 2) return index;
    if (eh_PrimoRec(n, n - 1)){ 
        vetor[index] = n;
        return preenche(n - 1, vetor, index + 1);
    } else {
        return preenche(n - 1, vetor, index);
    }
    
}

int main()
{
    int num, qtd;
    
    printf("Digite um numero: ");
    scanf("%d", &num);
    
    qtd = contaPrimos(num);

    int *vet = (int*) malloc(qtd * sizeof(int));

    preenche(num, vet, 0);

    printf("Primos de 1 ate %d:\n", num);

    for (int i = 0; i < qtd; i++) { // agora imprime na ordem correta
        printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;
}
