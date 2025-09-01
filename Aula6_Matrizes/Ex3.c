#include <stdio.h>
#include <stdbool.h>

int main()
{
    int i, j;
    int matriz[5][3] = {
        {12,34,56},
        {78,90,11},
        {22,44,66},
        {88,10,99},
        {5,15,25}
    };

    int transp[3][5];
     
    for(i = 0; i < 5; i ++)
    {
        for(j = 0; j < 3; j ++)
        {                        
            transp[j][i] = matriz[i][j];            
        }
    }

    printf("Matriz Normal: \n");
 
    for(i = 0; i < 5; i ++)
    {
        for(j = 0; j < 3; j ++)
        {         
            printf("%d\t", matriz[i][j]);            
        }
        printf("\n");
    }

    printf("\n");
    printf("Matriz Transposta: \n");

    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 5; j ++)
        {         
            printf("%d\t", transp[i][j]);            
        }
        printf("\n");
    }
    
    return 0;
}    


    