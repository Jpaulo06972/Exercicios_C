#include <stdio.h>
#include <string.h>
#include <ctype.h>

int len(char a[100])
{

    return strlen(a);
}

int main()
{
    int tamanho;
	char text[100];

    printf("Digite uma string: ");
    scanf("%[^\n]", text);

    tamanho = len(text);

    printf("Essa string: %s\n", text);
    printf("Tem o tamanho de : %d\n", tamanho);

	return 0;
}
