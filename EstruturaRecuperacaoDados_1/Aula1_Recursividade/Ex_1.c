#include <stdio.h> // Inclui as funções de entrada e saída padrão (como printf e scanf) para interação com o usuário.

// Função recursiva para calcular o somatório acumulado de 1 até n.
// A recursão resolve o problema reduzindo-o a subproblemas menores (n + soma dos números anteriores).
int Soma(int n){
    // Caso base: quando n atinge 1, o somatório atinge sua menor unidade conhecida.
    // Interrompe o empilhamento de chamadas recursivas e inicia o retorno dos valores.
    if (n == 1) return 1;
    
    // Passo recursivo: soma o número atual 'n' ao resultado da soma de todos os números menores (n - 1).
    else return (n + Soma(n - 1));
}

int main(){

    // Variaveis locais para armazenar a entrada do usuário e o resultado final da soma.
    int num, soma;
    
    // Solicita e realiza a leitura do número até o qual a soma será calculada.
    printf("Digite um numero: ");
    scanf("%d", &num);

    // Inicia o processo recursivo de soma a partir do número fornecido.
    soma = Soma(num);

    // Apresenta na tela o resultado obtido.
    printf("%d soma dos numeros: %d", num, soma);

    // Finaliza a execução do programa principal retornando código de sucesso.
    return 0;
}