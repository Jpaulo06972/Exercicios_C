#include <stdio.h> // Inclui a biblioteca padrao para permitir operacoes de entrada e saida (como printf)

int main()
{
    // Armazena os valores iniciais e declara uma variavel auxiliar para dar suporte a troca de valores
    int var1 = 7, var2 = 8, temp;
    
    // Cria ponteiros apontando para os enderecos de memoria das variaveis var1 e var2
    int *pt1 = &var1;
    int *pt2 = &var2;
    
    // Realiza a troca (swap) dos valores apontados, utilizando o operador de desreferenciamento (*)
    temp = *pt1;   // Salva temporariamente o valor contido na memoria de var1
    *pt1 = *pt2;   // Substitui o valor no endereco de var1 pelo valor de var2
    *pt2 = temp;   // Escreve o valor armazenado em temp no endereco de var2
    
    // Imprime na tela o resultado da troca para confirmar a alteracao direta na memoria
    printf("Novo valor de Var1 %d\n", var1);
    printf("Novo valor de Var2 %d", var2);

    return 0; // Finaliza a execucao da funcao principal retornando status de sucesso
}