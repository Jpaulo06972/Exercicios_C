#include <stdio.h>   // Para operacoes de entrada e saida de dados
#include <string.h>  // Para manipulacao de cadeias de caracteres (ex: strlen)
#include <ctype.h>   // Fornece utilitarios para analise e conversao de caracteres

// Encapsula a funcao strlen para calcular a quantidade de caracteres de uma string
int len(char a[100])
{    
    // Retorna o total de caracteres lidos ate encontrar o caractere nulo de termino ('\0')
    return strlen(a);
}

int main()
{
    int tamanho;
	char text[100]; // Buffer de memoria para armazenar a string informada pelo usuario
    
    // Solicita a frase e usa o especificador %[^\n] para ler a linha inteira incluindo espacos
    printf("Digite uma string: ");
    scanf("%[^\n]", text);

    // Calcula o tamanho do texto chamando a funcao customizada 'len'
    tamanho = len(text);

    // Apresenta a string lida e o total de caracteres contabilizados
    printf("Essa string: %s\n", text);
    printf("Tem o tamanho de : %d\n", tamanho);
    
	return 0; // Finaliza o programa sem erros
}
