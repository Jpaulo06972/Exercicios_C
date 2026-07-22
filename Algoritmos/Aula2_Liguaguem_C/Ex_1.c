// Inclui a biblioteca padrao de entrada e saida (stdio.h) para permitir o uso de funcoes de impressao como printf
#include <stdio.h>

// Ponto de entrada principal do programa C
int main(){

    // Declara as variaveis de teste 'a' e 'b' com valores iniciais e cria 'temp'
    // armazenando temporariamente o valor de 'a' para evitar a perda do dado durante a troca
    int a = 5, b= 13, temp = a;
    
    // Sobrescreve o valor de 'a' copiando o valor contido em 'b'
    a = b;
    // Atribui a 'b' o valor original de 'a' que havia sido salvo na variavel 'temp'
    b = temp;

    // Exibe no console os valores das variaveis apos a operacao de troca
    printf(" Valor de A = %i\n Valor de B = %i", a, b);
    
    // Indica a finalizacao bem-sucedida do programa para o sistema operacional
    return 0;
}