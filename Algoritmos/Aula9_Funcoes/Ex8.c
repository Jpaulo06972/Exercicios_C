#include <stdio.h>  // Biblioteca padrao para operacoes de E/S
#include <string.h> // Manipulacao de strings (strlen e strcmp)
#include <ctype.h>  // Utilitarios de caracteres

// Funcao que verifica se a string informada eh um palindromo (se lida da esquerda para direita eh igual da direita para esquerda)
int pali(char text[100]){

    int tamanho, result;
    char textInvertido[100];

    // Calcula o tamanho da string para mapear os indices de inversao
    tamanho = strlen(text);
 
    // Monta a string invertida preenchendo as posicoes de tras para frente
    for (int i = 0; i < tamanho; i++)
    {
        textInvertido[tamanho - i - 1] = text[i];        
    }

    // Adiciona explicitamente o caractere nulo ('\0') para delimitar o fim do texto invertido
    textInvertido[tamanho] = '\0';
    
    // Compara a string original com a invertida (retorna 0 se forem identicas)
    result = strcmp(text, textInvertido);

    // Retorna 1 para verdadeiro (palindromo) ou 0 para falso
    if (result == 0){
        return 1;
    } else{
        return 0;
    }
}

int main(){
    char text[100]; // Buffer para receber o texto digitado
    int eh_palin;
    
    printf("Digite uma string: ");
    scanf(" %[^\n]", text); // Le a frase digitada
    
    // Chama a funcao que verifica a condicao de palindromo
    eh_palin = pali(text);

    // Exibe a mensagem de acordo com a resposta booleana recebida
    if (eh_palin)
    {
        printf("Esse texto eh palindromo: %s\n", text);
    }else {
        printf("Esse texto nao eh palindromo: %s\n", text);
    }
    return 0; // Termino normal da execucao
}