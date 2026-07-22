#include <stdio.h>  // Entrada e saída padrão.
#include <stdbool.h>// Tipo booleano (bool, true, false).
#include <stdlib.h> // Alocação dinâmica de memória (malloc, free).

// Função recursiva para verificar se um número 'n' é primo testando se possui divisores de 'divisor' até 2.
bool eh_PrimoRec(int n, int divisor){

    // Casos base de exclusão: números menores ou iguais a 1 não são primos por definição.
    if (n <= 1) return false;
    
    // Caso base de sucesso: se reduzimos o divisor até 1 sem encontrar nenhuma divisão exata, n é primo.
    if (divisor == 1) return true; 
    
    // Se o resto da divisão por 'divisor' for 0, encontramos um fator intermediário; logo, não é primo.
    if (n % divisor == 0) return false;
    
    // Passo recursivo: continua testando com o próximo divisor menor.
    return eh_PrimoRec(n, divisor - 1);
}

// Função recursiva para contar a quantidade de números primos no intervalo de 1 até n.
// Essa contagem é fundamental para sabermos o tamanho exato de memória a ser alocado dinamicamente.
int contaPrimos(int n){
    // Caso base: abaixo do menor número primo (2), a contagem de primos é 0.
    if (n < 2) return 0;
    
    // Se 'n' for primo, soma 1 à quantidade total de primos encontrados do intervalo (n - 1 até 1).
    if (eh_PrimoRec(n, n - 1)) return 1 + contaPrimos(n - 1);
    
    // Caso contrário, não soma nada e apenas continua contando para os números menores (n - 1).
    else return contaPrimos(n - 1);
}

// Função recursiva para preencher o vetor dinâmico com os números primos encontrados de 'n' até 2.
// 'index' controla a posição atual do vetor onde o próximo primo deve ser inserido.
int preenche(int n, int *vetor, int index){
    // Caso base: ao atingir valores menores que 2, termina o preenchimento e retorna a quantidade de inserções efetuadas.
    if (n < 2) return index;
    
    // Se 'n' for primo, insere o número no vetor na posição 'index' e avança para a próxima posição (index + 1).
    if (eh_PrimoRec(n, n - 1)){ 
        vetor[index] = n;
        return preenche(n - 1, vetor, index + 1);
    } else {
        // Se 'n' não for primo, ignora a inserção e mantém o mesmo 'index' para o próximo candidato.
        return preenche(n - 1, vetor, index);
    }
    
}

int main()
{
    // Variáveis para receber a entrada do usuário e o total de números primos calculados.
    int num, qtd;
    
    // Solicita o limite superior do intervalo.
    printf("Digite um numero: ");
    scanf("%d", &num);
    
    // Conta quantos números primos existem entre 1 e 'num'.
    qtd = contaPrimos(num);

    // Aloca dinamicamente exatamente o espaço necessário na memória para armazenar os 'qtd' inteiros primos.
    int *vet = (int*) malloc(qtd * sizeof(int));

    // Popula o vetor alocado utilizando a rotina recursiva de preenchimento.
    preenche(num, vet, 0);

    // Exibe os números primos armazenados no vetor.
    printf("Primos de 1 ate %d:\n", num);

    // Itera sobre os elementos do vetor dinâmico para imprimir cada número primo encontrado.
    for (int i = 0; i < qtd; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");

    // Libera a memória alocada dinamicamente para evitar vazamentos de memória (memory leak).
    free(vet);

    return 0;
}
