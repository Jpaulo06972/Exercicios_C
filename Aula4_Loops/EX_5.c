#include <stdio.h>
#include <stdbool.h>

int main()
{
	int num1, num2, num3, num4, num5;
	bool mustStop = false;
    
    printf("Digite um número inteiro: ");
    scanf("%d", &num1);
    
    printf("Digite um número inteiro: ");
    scanf("%d", &num2);
    
    printf("Digite um número inteiro: ");
    scanf("%d", &num3);
    
    printf("Digite um número inteiro: ");
    scanf("%d", &num4);
    
    printf("Digite um número inteiro: ");
    scanf("%d", &num5);
    
    while(!mustStop){
        mustStop = true;
        
        if (num1 > num2){
            int temp = num1;
            num1 = num2;
            num2 = temp;
            mustStop = false;
        }
        
        if (num2 > num3){
            int temp = num2;
            num2 = num3;
            num3 = temp;
            mustStop = false;
        }
        
        if (num3 > num4){
            int temp = num3;
            num3 = num4;
            num4 = temp;
            mustStop = false;
        }
        
        if (num4 > num5){
            int temp = num4;
            num4 = num5;
            num5 = temp;
            mustStop = false;
        }
        
    }
    printf("%d, %d, %d, %d, %d", num1, num2, num3, num4, num5);
	return 0;
}    