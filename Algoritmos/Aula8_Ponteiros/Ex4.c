#include <stdio.h>

int main()
{
    int num1 = 10, num2 = 20, num3 = 30;
    int *pt1 = &num1;
    int *pt2 = &num2;
    int *pt3 = &num3;

    *pt1 = 100;
    pt1 = &num2;
    *pt1 = 200;
    pt1 = &num3;
    *pt1 = 300;

    printf("Num1: %d\n", num1);
    printf("Num2: %d\n", num2);
    printf("Num3: %d\n", num3);
    
    return 0;
}