// Inclusão das bibliotecas padrão para E/S, manipulação de textos e valores booleanos.
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Estrutura Pessoa agrupando o nome e a idade.
struct Pessoa{
    char nome[50]; // Vetor de char para armazenar o nome.
    int idade;     // Inteiro para armazenar a idade.
}; 

// Função responsável por identificar e exibir os dados da pessoa com maior idade no vetor.
void imprimePessoa(struct Pessoa p[], int tamanho){

    // Inicializa 'velha' com um valor negativo arbitrariamente baixo para garantir comparações iniciais,
    // e 'indice' para guardar a posição da pessoa com maior idade.
    int velha = -9999, indice;
    
    // Itera por todos os elementos do vetor de structs Pessoa.
    for (int i = 0; i < tamanho; i++){
    
        // Verifica se a idade da i-ésima pessoa é maior do que o valor de referência em 'velha'.
        if (velha < p[i].idade)
        {
            // Guarda o índice da pessoa atual.
            indice = i;
        }
    }
    
    // Imprime na tela o cabeçalho e os atributos da pessoa na posição salva em 'indice'.
    printf("\nPessoa Mais Velha");
    printf("\nNome: %s\n", p[indice].nome);
    printf("Idade: %d\n", p[indice].idade);  
}

int main(){
    
    // Quantidade de cadastros a serem preenchidos.
    int cont = 2;
    // Declara um vetor de estruturas Pessoa.
    struct Pessoa p[cont];

    // Laço para entrada dos dados digitados via teclado para cada posição do vetor.
    for(int i = 0; i < cont; i++)
    {  
        printf("Digite os Dados da %d pessoa\n", i + 1);      
        printf("Nome: ");
        // O formato " %[^\n]" ignora espaços em branco/novas linhas residuais no buffer e lê o nome completo.
        scanf(" %[^\n]", p[i].nome);

        printf("Idade: ");
        // Armazena a idade lida no campo 'idade' do i-ésimo elemento.
        scanf("%d", &p[i].idade);
    }

    // Chama a função para buscar e imprimir a pessoa mais velha.
    imprimePessoa(p, cont);      
    
    // Encerra a execução do programa com sucesso.
    return 0;    
}
