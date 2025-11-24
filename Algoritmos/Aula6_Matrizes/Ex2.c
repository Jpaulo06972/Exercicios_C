#include <stdio.h>
#include <stdbool.h>

int main()
{
    int i, j, posi1, posi2;
    float maior = -99999;
    float matriz[5][5] = {
        {12,45,67,89,23},
        {34,56,78,90,11},
        {22,44,66,88,10},
        {91,73,54,36,18},
        {5,15,25,35,45}
    };   
    
    for(i = 0; i < 5; i ++)
    {
        for(j = 0; j < 5; j ++)
        {
            if (matriz[i][j] > maior)
            {
                maior = matriz[i][j];
                posi1 = i;
                posi2 = j;
            }
        }
    }
    printf("Maior Numero da Matriz[%d][%d]: %f", posi1 + 1, posi2 + 1, maior);
    
    return 0;
}    


    