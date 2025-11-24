#include <stdio.h>

int main(){

    int a = 5, b= 13, temp = a;
    
    a = b;
    b = temp;

    printf(" Valor de A = %i\n Valor de B = %i", a, b);
    return 0;
}