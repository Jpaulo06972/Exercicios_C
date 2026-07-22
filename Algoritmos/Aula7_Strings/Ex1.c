#include <stdio.h>  // Fornece funcoes de entrada e saida padrao (printf, scanf)
#include <string.h> // Fornece funcoes para manipulacao de strings, como strlen()
#include <ctype.h>  // Necessario para funcoes de conversao de caracteres, como tolower() e toupper()

int main(){
    // 'find' armazena o caractere individual informado pelo usuario para busca
    char find;
    // 'text' aloca um vetor de char (buffer) com capacidade de 100 caracteres para armazenar o texto lido
    char text[100];
    // 'tamanho' armazena a quantidade de caracteres da string e 'i' e o indice para o laço de repeticao
    int tamanho, i;
    // 'cont' acumula o numero de vezes que o caractere procurado aparece no texto
    int cont = 0;
    
    // Solicita a frase/palavra inicial ao usuario
    printf("Digite uma string com no maximo 20 caracteres: ");
    // Especificador " %[^\n]" le toda a sequencia de caracteres incluindo espacos ate encontrar o ENTER (\n)
    // O espaco no inicio descarta eventuais caracteres brancos remanescentes no buffer de entrada
    scanf(" %[^\n]", text);

    // Obtem o comprimento exato da string digitada descartando o caractere nulo final '\0'
    tamanho = strlen(text);

    // Garante que o usuario digite uma string que atenda ao limite estabelecido (maximo de 20 caracteres)
    while(tamanho > 21){
        printf("Digite novamente uma string com no maximo 20 caracteres: ");
        scanf(" %[^\n]", text); 
        tamanho = strlen(text);
    }

    // Solicita o caractere que sera contado na string
    printf("Digite o caracter a ser contado na string: ");
    // " %c" le um unico caractere ignorando eventuais quebras de linha remanescentes
    scanf(" %c", &find);

    // Itera sequencialmente sobre cada posicao da string (de 0 ate 'tamanho - 1')
    for (i = 0; i < tamanho; i++)
    {
        // Converte o caractere da string e o caractere procurado para minusculo (tolower) antes de comparar,
        // permitindo a contagem independente do caractere ser maiusculo ou minusculo (case-insensitive)
        if(tolower(text[i]) == tolower(find)){
            cont ++; // Incrementa o contador ao encontrar correspondencia
        }        
    }

    // Imprime o resultado formatando o caractere de busca em maiusculo (toupper) para destaque visual
    printf("Na string %s possui %d '%c'\n", text, cont, toupper(find));
        
    // Encerra o programa indicando execucao bem-sucedida
    return 0;
}