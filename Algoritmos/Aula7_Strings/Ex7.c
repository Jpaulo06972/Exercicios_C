#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    char text[150];

    int i;

    printf("Digite uma String aqui: ");

    scanf(" %[^\n]", text);

    for(i = 0; text[i] != '\0'; i++)
    {

        if(text[i] == ' ')
        {
            printf("\n");
        }

        printf("%c", text[i]);
    }

    return 0;
}
