// ==========================================
// PRIMEIRA PARTE: INSERÇÃO EM VETOR COM SHIFT DIREITA
// ==========================================
#include <stdio.h>
#include <stdbool.h>

int main()
{
    // Variável para iterar nos laços
    int i;
    // Quantidade de elementos atualmente preenchidos no vetor (6 elementos)
    int n = 6;
    // Vetor com capacidade para 10 inteiros, contendo 6 valores iniciais
    int vet[10] = {1,2,3,4,5,6};
    // Valor que se deseja inserir no vetor
    int novoValor = 25;
    // Posição (índice 3) onde o novo valor será inserido
    int posi = 3;

    // Deslocamento para a direita (Shift Right): percorre do final ('n') até a posição de inserção ('posi')
    // Move cada elemento uma posição para a frente para abrir espaço no índice 'posi' sem perder dados
    for (i = n; i > posi; i--)
    {
        vet[i] = vet[i - 1];
    }
    
    // Insere o novo valor no espaço liberado na posição desejada
    vet[posi] = novoValor;
    
    // Incrementa a contagem de elementos válidos no vetor
    n ++;

    printf("Vetor atualizado:\n");
    // Exibe todos os elementos do vetor atualizado com o elemento inserido
    for (i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
    
    printf("\n");
    
    return 0;
} 

// ==========================================
// SEGUNDA PARTE: REMOÇÃO EM VETOR COM SHIFT ESQUERDA
// ==========================================
#include <stdio.h>
#include <stdbool.h>

int main()
{
    // Variável de controle do laço
    int i;
    // Número de elementos iniciais no vetor
    int n = 6;
    // Vetor inicial contendo 6 elementos
    int vet[10] = {1,2,3,4,5,6};
    // Índice do elemento que será removido (índice 2, correspondente ao valor 3)
    int posi = 2;

    // Deslocamento para a esquerda (Shift Left): a partir da posição de remoção até a penúltima posição válida
    // Sobrescreve o elemento removido puxando cada elemento seguinte uma posição para a esquerda
    for (i = posi; i < n - 1; i++)
    {
        vet[i] = vet[i + 1];
    }
    
    // Decrementa o número total de elementos válidos após a remoção
    n --;

    printf("Vetor atualizado:\n");
    // Exibe o vetor com o elemento devidamente removido e tamanho reduzido
    for (i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
    
    printf("\n");
    
    return 0;
}    