#include <stdio.h> // Inclui suporte a I/O

// Recebe dois ponteiros de inteiros e realiza a troca direta de seus valores na memoria
void Swap(int *a, int *b){
    int temp;

    // Salva temporariamente o valor contido no endereco 'a'
    temp = *a;
    // Substitui o valor do endereco 'a' pelo valor contido no endereco 'b'
    *a = *b;
    // Grava o valor armazenado em 'temp' no endereco 'b'
    *b = temp;

    // Imprime os novos valores alterados de forma direta nos enderecos fornecidos
    printf("Novo valor de A: %d\n", *a);
    printf("Novo valor de B: %d\n", *b);
    
}

int main(){

    int num1, num2;

    // Coleta dois inteiros fornecidos pelo usuario
    printf("Digite Valor de A: ");
    scanf("%d", &num1);
    printf("Digite Valor de B:");
    scanf("%d", &num2);

    // Cria ponteiros inicializados com os enderecos das variaveis num1 e num2
    int *pt1 = &num1;
    int *pt2 = &num2; 

    // Executa o procedimento Swap passando os dois ponteiros como parametros por referencia
    Swap(pt1, pt2);

    return 0; // Sucesso na execucao
}