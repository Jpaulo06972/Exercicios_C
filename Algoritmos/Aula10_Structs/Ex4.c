// Inclusão de cabeçalhos padrão do C para manipular fluxos de E/S e funções utilitárias de strings.
#include <stdio.h>
#include <string.h>

// Definição de tipo estruturado 'Pessoa' usando a palavra-chave typedef.
typedef struct{
    char nome[50]; // Membro para armazenar a string com a identificação/nome.
    int idade;     // Membro para armazenar o valor numérico da idade.
} Pessoa;

// Função utilitária para exibição dos dados de uma Pessoa.
// A passagem de parâmetro usa um ponteiro para constante ('const Pessoa *p'),
// o que garante eficiência por evitar cópia na pilha e protege a struct contra alterações acidentais.
void imprimePessoa(const Pessoa *p){
    // Acessa o membro 'nome' através da desreferenciação do ponteiro 'p' usando o operador de seta (->).
    printf("Nome: %s\n", p->nome);
    // Acessa o membro 'idade' através do ponteiro 'p' e formata como valor inteiro na saída.
    printf("Idade: %d\n", p->idade);
}

int main(){
    // Declaração e inicialização direta da struct 'Pessoa' utilizando lista de inicializadores entre chaves.
    Pessoa p = {"Joao Paulo", 18};
    
    // Transmite o endereço de memória de 'p' (&p) para a função de impressão.
    imprimePessoa(&p);
    
    // Retorna 0 para indicar o encerramento correto do programa.
    return 0;    
}
