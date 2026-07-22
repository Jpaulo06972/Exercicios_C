// Inclusão de bibliotecas para E/S (stdio.h), manipulação de strings (string.h) e suporte a tipos booleanos bool/true/false (stdbool.h).
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Criação do tipo customizado 'Pessoa' contendo campos de nome e idade.
typedef struct{
    char nome[50]; // Armazena a string com o nome da pessoa.
    int idade;     // Armazena a idade em formato inteiro.
} Pessoa;

// Função que verifica a maioridade de uma pessoa a partir de seu ponteiro.
// O parâmetro 'const Pessoa *p' permite leitura eficiente dos dados sem clonar a struct na memória.
bool imprimePessoa(const Pessoa *p){
    // Testa se o membro 'idade' apontado por p é menor que a idade limite de 18 anos.
    if(p->idade < 18){
        // Retorna 'false' (0) caso a pessoa seja menor de idade.
        return false;
    } else{
        // Retorna 'true' (1) caso a pessoa tenha 18 anos ou mais.
        return true;
    }    
}

int main(){
    // Variável booleana para guardar o retorno da verificação.
    bool maior;
    // Declaração e inicialização da instância de Pessoa.
    Pessoa p = {"Joao Paulo", 18};
    
    // Avalia a maioridade passando o endereço de memória (&p) e armazena o resultado em 'maior'.
    maior = imprimePessoa(&p);
    
    // Exibe o resultado numérico do valor booleano (1 indica verdadeiro/maior de idade, 0 indica falso).
    printf("Pessoa eh maior %d", maior);
    
    // Retorna 0 para indicar sucesso na execução.
    return 0;    
}
