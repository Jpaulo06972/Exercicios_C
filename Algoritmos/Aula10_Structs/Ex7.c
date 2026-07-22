// Inclusão de bibliotecas essenciais para E/S, operações com strings, tipos booleanos e caracteres.
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h> // Disponibiliza a função toupper() para conversão de caracteres em caixa alta.

// Estrutura que representa uma Pessoa.
struct Pessoa{
    char nome[50];
    int idade;
}; 

// Função responsável por buscar uma pessoa pelo nome no vetor recebido, retornando o índice de sua posição.
// Ela normaliza os caracteres para maiúsculas antes de comparar, tornando a busca insensível a caixa (case-insensitive).
int imprimePessoa(struct Pessoa p[], int tamanho){
      
    int possui, indice;
    char encontrar[50]; // Armazena a string informada pelo usuário para a busca.
    char achar[50];     // Cópia auxiliar do nome cadastrado no vetor para normalização.
        
    // Solicita a entrada da string a ser buscada.
    printf("\nDigite o nome da pessoa a ser encontrada: ");
    scanf(" %[^\n]", encontrar);

    // Percorre a string digitada convertendo cada caractere para maiúsculo via toupper até o terminador nulo '\0'.
    for (int i = 0; encontrar[i] != '\0'; i++) encontrar[i] = toupper(encontrar[i]);
    
    // Itera sobre todos os elementos cadastrados no vetor de pessoas.
    for (int i = 0; i < tamanho; i++){

        // Copia o nome original do elemento 'p[i]' para 'achar', evitando alterar os dados originais do vetor.
        strcpy(achar, p[i].nome);

        // Transforma a cópia local do nome cadastrado em maiúsculas.
        for (int j = 0; achar[j] != '\0'; j++) achar[j] = toupper(achar[j]);

        // strcmp retorna 0 se as duas strings forem exatamente iguais.
        possui = strcmp(achar, encontrar);

        // Caso haja correspondência de nomes, registra a posição da pessoa no vetor.
        if (possui == 0){
            indice = i;
        }
    }

    // Retorna o índice armazenado.
    return indice;
}

int main(){
    
    int cont = 2, indice;
    struct Pessoa p[cont]; // Cria um vetor de structs Pessoa de tamanho 'cont'.

    // Laço de leitura dos dados das pessoas a serem cadastradas.
    for(int i = 0; i < cont; i++)
    {  
        printf("Digite os Dados da %d\n", i + 1);      
        printf("Nome: ");
        scanf(" %[^\n]", p[i].nome);

        printf("Idade: ");
        scanf("%d", &p[i].idade);
    }
    
    // Chama a função de busca e recupera o índice do nome pesquisado.
    indice = imprimePessoa(p, cont);
    
    // Exibe a posição encontrada e informação orientativa da busca.
    printf("Indice da pessoa %d\n", indice);    
    printf("Se for (-1) a pessoal nao foi encontrada");   
    
    return 0;    
}
