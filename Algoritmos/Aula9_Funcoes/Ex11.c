#include <stdio.h>

void Swap(int *a, int *b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;

    printf("Novo valor de A: %d\n", *a);
    printf("Novo valor de B: %d\n", *b);
    
}

int main(){

    int num1, num2;

    printf("Digite Valor de A: ");
    scanf("%d", &num1);
    printf("Digite Valor de B:");
    scanf("%d", &num2);

    int *pt1 = &num1;
    int *pt2 = &num2; 

    Swap(pt1, pt2);

    return 0;
}