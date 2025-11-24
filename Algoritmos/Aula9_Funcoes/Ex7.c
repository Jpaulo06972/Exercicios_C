#include <stdio.h>
#include <string.h>
#include <ctype.h> // Necessário para as funções com char

void copia(const char* origem, char* destino) {
    
    int tamanho = strlen(origem);
    for (int i = 0; i <= tamanho; i++) { // inclui '\0'
        destino[i] = origem[i];
    }
}

int main(){
    char text[100], copiaStr[100];
    printf("Digite uma string: ");
    scanf(" %[^\n]", text); 

    copia(text, copiaStr);

    printf("String copiada: %s\n", copiaStr);
    printf("\n");
        
    return 0;
}