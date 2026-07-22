#include <stdio.h> // Biblioteca padrão de I/O para exibição de texto e leitura de entradas do usuário.

// Função recursiva para calcular o fatorial de um número inteiro positivo n (n!).
// O fatorial multiplica o valor por todos os seus antecessores até atingir o caso base 1.
int Fatorial(int n){
    // Caso base da recursão: por definição matemática, 1! = 1.
    // Interrompe novas chamadas recursivas, permitindo o retorno dos produtos acumulados.
    if (n == 1) return 1;
    
    // Passo recursivo: multiplica o valor atual 'n' pelo fatorial do seu antecessor (n - 1).
    else return (n * Fatorial(n - 1));
}

int main(){

    // Declaração das variáveis para capturar o número do usuário e armazenar o fatorial calculado.
    int num, fat;
    
    // Solicita a entrada de um número inteiro para o cálculo do fatorial.
    printf("Digite um numero: ");
    scanf("%d", &num);

    // Inicia a cadeia de chamadas recursivas para calcular n!
    fat = Fatorial(num);

    // Exibe o resultado da operação de fatorial.
    printf("%d o fatorial eh: %d", num, fat);

    // Conclui a execução da função principal com código de sucesso.
    return 0;
}