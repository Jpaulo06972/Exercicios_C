#include <stdio.h>
#include <stdbool.h>

int main()
{
    int i, j, posi1, posi2;
    float soma = 0;
    float menor = 99999;
    float maior = -9999;
    float matriz[10][10] = {
        {12,34,56,78,90,11,22,44,66,88},
        {15,25,35,45,55,65,75,85,95,5},
        {19,29,39,49,59,69,79,89,99,9},
        {13,23,33,43,53,63,73,83,93,3},
        {14,24,34,44,54,64,74,84,94,4},
        {16,26,36,46,56,66,76,86,96,6},
        {17,27,37,47,57,67,77,87,97,7},
        {18,28,38,48,58,68,78,88,98,8},
        {21,31,41,51,61,71,81,91,1,2},
        {10,20,30,40,50,60,70,80,90,100}
    };
     
    for(i = 0; i < 10; i ++)
    {
        for(j = 0; j < 10; j ++)
        {
            if (i == 3)
            {
                soma = soma + matriz[i][j];
            }

            if (j == 4)
            {
                if (matriz[i][j] < menor)
                {
                    menor = matriz[i][j];
                }
            }

           if(matriz[i][i] > maior) 
            {
                maior = matriz[i][j];
                posi1 = i;
                posi2 = j;
            }
            
        }
    }
    printf("Soma da linha 4: %f\n", soma);
    printf("Menor Elemento da Coluna 5: %f\n", menor);
    printf("Maior Elemento da Diagonal da Matriz[%d][%d]: %f", posi1, posi2, maior);    
    
    return 0;
}    


    