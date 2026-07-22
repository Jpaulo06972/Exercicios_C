#include <stdio.h>  // Operacoes padrao de entrada/saida
#include <string.h> // Manipulacao de strings (strlen)
#include <ctype.h>  // Manipulacao de caracteres (toupper)

// Converte todos os caracteres de uma string de origem para maiusculas na string de destino
void converte(const char* text, char* new){
    int tamanho;

    // Obtem o tamanho do texto para controlar o laço de repeticao
    tamanho = strlen(text);

    // Percorre cada posicao do vetor aplicando a conversao de caractere
    for (int i = 0; i < tamanho; i++)
    {
        // Converte o caractere atual para caixa alta usando toupper()
        new[i] = toupper(text[i]);
    }
    
    // Adiciona o caractere delimitador nulo ('\0') no final do novo vetor para manter a integridade da string
    new[tamanho] = '\0';

}

int main() {
    // Vetores para armazenar a string original e a string resultante em caixa alta
    char text[100], new[100];
    
    printf("Digite uma string: ");
    scanf(" %[^\n]", text); // Le a string completa incluindo espacos

    // Chama a funcao de conversao para caixa alta
    converte(text, new);

    // Exibe o texto convertido
    printf("String convertida: %s\n", new);

    return 0; // Termino normal
}