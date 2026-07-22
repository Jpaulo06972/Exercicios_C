#include <stdio.h>  // Biblioteca padrao para operacoes de E/S
#include <string.h> // Contem operacoes para manipualacao de strings como strlen
#include <ctype.h>  // Fornece funcoes de tratamento de caracteres como tolower e toupper

// Conta as ocorrencias de um determinado caractere na string de maneira case-insensitive (sem diferenca entre maiuscula e minuscula)
int qtdCarcter(char text[100], char achar){
    int qtd = 0, tamanho;

    // Obtem o tamanho total do texto para definir o limite da busca
    tamanho = strlen(text);
    
    // Iteracao caractere a caractere pelo vetor
    for (int i = 0; i < tamanho; i++)
    {
        // Converte ambos para minusculo via tolower() para realizar uma comparacao insensivel a caixa
        if(tolower(text[i]) == tolower(achar))
        {
            qtd++; // Incrementa o contador quando ha correspondencia
        }

    }
    return qtd; // Retorna o total de ocorrencias encontradas
}

int main(){
    char find;
    char text[100]; // Buffer para armazenar o texto digitado
    int cont = 0;
    
    // Le o texto digitado ignorando quebras de linha anteriores
    printf("Digite uma string com no maximo 20 caracteres: ");
    scanf(" %[^\n]", text);
    
    // Le o caractere alvo a ser buscado (o espaco antes de %c consome espacos/newlines pendentes no buffer)
    printf("Digite o caracter a ser contado na string: ");
    scanf(" %c", &find);

    // Invoca a funcao de contagem
    cont = qtdCarcter(text, find);

    // Exibe o total encontrado exibindo o caractere buscado em maiusculo (via toupper)
    printf("Na string '%s' possui %d '%c'\n", text, cont, toupper(find));
        
    return 0; // Termino normal da execucao
}