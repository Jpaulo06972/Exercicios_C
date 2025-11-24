#include <stdio.h>
#include <string.h>
#include <ctype.h> // Necessário para as funções com char

int main(){
    char text[150]; // buffer maior para capturar entradas longas
    int i, j, contVogais = 0, contConsoantes = 0;
    int vogais[5] = {'a', 'e', 'i', 'o', 'u'};
      
    printf("Digite uma String aqui: ");
    scanf(" %[^\n]", text);

     
     
    for (i = 0; text[i] != '\0'; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (text[i] == vogais[j])
            {
                contVogais ++;
            }
        }        
    }
    //printf("%d\n", strlen(text));
    contConsoantes = strlen(text) - contVogais;

    printf("Essa String: %s\n", text);
    printf("%d Vogais \n", contVogais);
    printf("%d Consoantes \n", contConsoantes);

    return 0;
}