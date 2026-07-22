#include <stdio.h> // Inclui biblioteca padrao I/O

// Recebe um inteiro por valor 'a' e um ponteiro de inteiro 'b' para somar seus conteudos
int Soma(int a, int *b)
{
    // Acessa o valor armazenado no endereco de memoria de 'b' usando desreferenciacao e soma com 'a'
    return(a + *b);
}

int main()
{
    // Inicializa duas variaveis inteiras com os valores a serem somados
    int num1 = 3, num2 = 4;
    // Declara o ponteiro 'p' que armazena explicitamente o endereco de memoria da variavel 'num2'
    int *p = &num2;
    
    // Passa 'num1' diretamente por valor e 'p' (que ja guarda o endereco de 'num2') como argumento ponteiro
    int s = Soma(num1, p);
    
    // Imprime a soma obtida no terminal
    printf("Soma = %d", s);    
    return 0; // Finalizacao normal do programa
}