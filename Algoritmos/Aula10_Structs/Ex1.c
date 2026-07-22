// Inclusão das bibliotecas necessárias para entrada/saída padrão e manipulação de strings.
#include <stdio.h>
#include <string.h>

// Definição da estrutura 'Pessoa', permitindo agrupar dados heterogêneos relacionados a uma pessoa.
struct Pessoa{
    char nome[50]; // Array para armazenar o nome da pessoa (até 49 caracteres úteis + terminação nula).
    int idade;     // Armazena a idade da pessoa como valor inteiro.
};

// Função responsável por imprimir os atributos de uma Pessoa.
// Recebe a struct por valor (cópia), o que garante que os dados originais não serão alterados na leitura.
void imprimePessoa(struct Pessoa p){
    // Exibe o texto contido no atributo 'nome' acessado via operador ponto.
    printf("Nome: %s\n", p.nome);
    // Exibe o valor numérico armazenado no atributo 'idade'.
    printf("Idade: %d\n", p.idade);
}

int main(){
    // Declaração de uma variável do tipo 'struct Pessoa' na pilha (stack).
    struct Pessoa p;
    
    // Utiliza-se strcpy para copiar os caracteres para o vetor 'p.nome', já que vetores de char não aceitam atribuição direta de string literal.
    strcpy(p.nome, "Joao Paulo");
    // Atribui diretamente o valor inteiro 18 ao membro 'idade'.
    p.idade = 18;

    // Invoca a função repassando a struct preenchida para exibição no terminal.
    imprimePessoa(p);
    
    // Retorna 0 para indicar ao sistema operacional que a execução foi concluída sem erros.
    return 0;
}