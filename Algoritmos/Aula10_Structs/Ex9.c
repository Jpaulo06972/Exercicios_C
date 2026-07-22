// Inclusão de cabeçalhos padrão para E/S, ordenação e manipulação de strings, tipos booleanos e caracteres.
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h> // Disponibiliza rotinas para manipulação de caracteres.

// Definição da estrutura Pessoa contendo atributos de nome e idade.
struct Pessoa{
    char nome[50];
    int idade;
}; 

// Função que ordena um vetor de structs Pessoa em ordem alfabética de acordo com o campo 'nome' utilizando o algoritmo Bubble Sort, e depois imprime os nomes ordenados.
void imprimePessoa(struct Pessoa p[], int tamanho){

    // Variável auxiliar do tipo 'struct Pessoa' para permitir a troca direta de todos os atributos de dois elementos.
    struct Pessoa temp;
    // Flag de controle da ordenação (Bubble Sort): inicia em 1 para garantir a primeira execução do loop.
    int swap = 1;

    // Repete o ciclo enquanto trocas entre elementos adjacentes forem realizadas no vetor.
    while (swap != 0)
    {
        // Reseta o indicador de troca a cada passagem pelo vetor.
        swap = 0;
        
        // Compara pares de elementos vizinhos do início até a penúltima posição (tamanho - 1).
        for (int i = 0; i < tamanho - 1; i++)
        {
            // strcmp compara as duas strings e retorna um valor positivo se o nome em p[i] for alfabeticamente maior que em p[i+1].
            if (strcmp(p[i].nome, p[i+1].nome) > 0) { // Compara os nomes em ordem alfabética
                temp = p[i]; // Guarda a struct completa da esquerda na variável temporária
                p[i] = p[i+1]; // Substitui o elemento da esquerda pelo da direita
                p[i+1] = temp; // Posiciona a struct temporária no elemento da direita
                swap = 1; // Sinaliza que ocorreu pelo menos uma troca nesta varredura
            }
        }          
    }

    // Percorre o vetor de structs já ordenado e exibe cada nome na tela.
    for (int i = 0; i < tamanho; i++) printf(" %s\n", p[i].nome);
}

int main(){
    
    // Define a capacidade de 5 cadastros no vetor.
    int cont = 5;
    // Declara o vetor de estruturas Pessoa com o tamanho definido em 'cont'.
    struct Pessoa p[cont];

    // Laço para leitura interativa dos nomes digitados pelo usuário.
    for(int i = 0; i < cont; i++)
    {  
        printf("Digite os Dados da %d\n", i + 1);      
        printf("Nome: ");
        scanf(" %[^\n]", p[i].nome);
    }
    
    // Chama a função para ordenar o vetor por nome e exibir a lista resultante.
    imprimePessoa(p, cont);
        
    // Encerra a função principal com retorno 0 (sucesso).
    return 0;    
}
