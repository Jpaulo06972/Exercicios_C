#include <stdio.h>   // Biblioteca padrão para entrada/saída de dados.
#include <stdbool.h> // Inclui o tipo de dado booleano (true/false) nativo no C99.

// Função auxiliar recursiva para checar se 'n' é divisível por algum número menor que ele.
// O parâmetro 'divisor' decresce a cada chamada para testar se existe algum divisor exato além de 1 e n.
bool eh_PrimoRec(int n, int divisor){
    
    // Caso base de sucesso: se testamos todos os divisores até chegar em 1 e nenhum dividiu 'n' exatamente,
    // significa que 'n' não possui divisores além de 1 e dele mesmo, portanto é primo.
    if (divisor == 1) return true;
    
    // Caso base de falha: se o resto da divisão de 'n' por 'divisor' for 0, encontramos um divisor exato.
    // Isso prova imediatamente que 'n' não é primo (é um número composto).
    if (n % divisor == 0) return false;
    
    // Passo recursivo: testa o próximo divisor menor (divisor - 1).
    else return eh_PrimoRec(n, divisor - 1);
}

// Função wrapper (interface) para a verificação de números primos.
// Trata casos limites (números <= 2) e prepara a chamada da função recursiva.
bool eh_Primo(int n){
    
    // Números menores ou iguais a 1 não são primos; o número 2 é o único primo par.
    // Retorna true somente se n for exatamente 2.
    if (n <= 2) return (n == 2);
    
    // Para números maiores que 2, inicia o teste de divisibilidade partindo do antecessor imediato (n - 1).
    else return eh_PrimoRec(n, n - 1);
}

int main()
{
    // Variável para armazenar o número a ser testado.
    int num;
    
    // Interage com o usuário para obter o número inteiro desejado.
    printf("Digite um numero: ");
    scanf("%d", &num);
    
    // Avalia o retorno da função e imprime a mensagem apropriada.
    if (eh_Primo(num)) printf("%d eh primo", num);
    else printf("%d nao eh primo", num);

    // Retorna 0 para indicar término normal do programa.
    return 0;
}
