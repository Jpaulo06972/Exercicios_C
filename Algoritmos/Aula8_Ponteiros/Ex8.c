#include <stdio.h> // Inclui biblioteca padrao para exibir dados na tela

// Funcao que recebe o primeiro parâmetro como valor inteiro 'a' e o segundo como ponteiro 'b'
int Soma(int a, int *b)
{
    // Soma o valor passado diretamente em 'a' com o valor contido no endereco recebido em 'b'
    return(a + *b);
}

int main()
{
    // Declara e inicializa as variaveis que fornecem os dados para a soma
    int num1 = 3, num2 = 4;
    // Cria um ponteiro 'p' que armazena o endereco da variavel 'num2'
    int *p = &num2;
    
    // Desreferencia 'p' (*p) para passar o valor de num2 (4) por valor como primeiro argumento,
    // e passa o endereco de num1 (&num1) como segundo argumento (esperado como ponteiro)
    int s = Soma(*p, &num1);
    
    // Imprime o resultado final da adicao
    printf("Soma = %d", s);    
    return 0; // Encerra a execucao com sucesso
}