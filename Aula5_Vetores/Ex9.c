#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, i;
    int cont = 0;
    int vetX[10];
    
    for (i = 0; i < 10; i++){
        printf("Digite o valor da posição %d = ", i+1);
        scanf("%d", &vetX[i]);
        
        if (vetX[i] < 0) break;
         cont ++;
        
    }
    
    for (i = 0; i < cont; i++)printf("%d ", vetX[i]);

    
    return 0;
}    