#include <stdio.h>
#include <stdbool.h>

bool eh_par(int a)
{
    if ((a % 2) == 0){
        return(true);
    }else{
        return(false);
    }
}

int main()
{
	int num = 6;
    bool par;
    
    par = eh_par(num);

    if (par == 1){
        printf("O numero %d eh par", num);
    }else{
        printf("O numero %d nao eh par", num);
    }
    
	return 0;
}
