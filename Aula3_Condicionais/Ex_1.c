#include <stdio.h>
#include <stdbool.h>

int main()
{
    int a = 20, b = 0, c = 1, d = 10;
    
    bool teste1 = (a - b + d) >= c;
    printf("A conta 1 é %d\n", teste1);
    
    bool teste2 = (a > (a + d)) || (c > b);
    printf("A conta 2 é %d\n", teste2);
    
    bool teste3 = ((a * d) > (c + a)) && (a > b);
    printf("A conta 3 é %d\n", teste3);
    
    bool teste4 = (((a + b) / c) >= 0.9) && ((b * d) < 0);
    printf("A conta 4 é %d\n", teste4);
    
    bool teste5 = (((a + c) / d) > 0.3) && (((b - c) < 0)) || ((c + a) > d);
    printf("A conta 5 é %d\n", teste5);
    
    bool teste6 = ((((a + c) / d) > 0.3) && ((b - c) < 0)) || ((c + a) > d);
    printf("A conta 6 é %d\n", teste6);
    
    return 0;
}
