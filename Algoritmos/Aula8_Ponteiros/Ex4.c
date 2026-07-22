#include <stdio.h> // Inclui funcionalidade basica de I/O

int main()
{
    // Define tres variaveis inteiras com valores iniciais distintos
    int num1 = 10, num2 = 20, num3 = 30;
    
    // Declara ponteiros apontando individualmente para cada uma das tres variaveis
    int *pt1 = &num1;
    int *pt2 = &num2;
    int *pt3 = &num3;

    // Altera o valor de num1 para 100 através da desreferenciacao de pt1
    *pt1 = 100;
    
    // Reatribui o endereco guardado em pt1 para passar a apontar para num2
    pt1 = &num2;
    // Modifica o valor no endereco atual de pt1 (agora num2) para 200
    *pt1 = 200;
    
    // Reatribui pt1 novamente, fazendo-o apontar para num3
    pt1 = &num3;
    // Modifica o valor no endereco de num3 para 300
    *pt1 = 300;

    // Imprime os valores finais de todas as variaveis para demonstrar que foram alteradas indiretamente
    printf("Num1: %d\n", num1);
    printf("Num2: %d\n", num2);
    printf("Num3: %d\n", num3);
    
    return 0; // Encerra o programa com sucesso
}