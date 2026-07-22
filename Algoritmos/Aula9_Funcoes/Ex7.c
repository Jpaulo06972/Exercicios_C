#include <stdio.h>  // Operacoes de entrada e saida padrao
#include <string.h> // Funcoes de inspecao de string (strlen)
#include <ctype.h>  // Utilitarios de caractere

// Funcao de copia customizada que transfere os caracteres da string de origem para a de destino
void copia(const char* origem, char* destino) {
    
    int tamanho = strlen(origem);
    // Percorre ate 'tamanho' (inclusivo, com <=) para copiar tambem o caractere de terminação nula ('\0')
    for (int i = 0; i <= tamanho; i++) {
        destino[i] = origem[i]; // Copia o caractere da posicao i
    }
}

int main(){
    // Declara os vetores de char para armazenar a string original e a copia destino
    char text[100], copiaStr[100];
    
    printf("Digite uma string: ");
    scanf(" %[^\n]", text); // Le a frase digitada ate a quebra de linha

    // Executa o procedimento de copia
    copia(text, copiaStr);

    // Exibe a string copiada com sucesso para validacao
    printf("String copiada: %s\n", copiaStr);
    printf("\n");
        
    return 0; // Finalizacao com sucesso
}