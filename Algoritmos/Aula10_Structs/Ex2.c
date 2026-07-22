// Inclusão das bibliotecas padrão para funções de E/S (stdio.h) e manipulação de cadeias de caracteres (string.h).
#include <stdio.h>
#include <string.h>

// Uso do 'typedef' aliado ao 'struct' para criar o apelido de tipo 'Pessoa'.
// Isso simplifica a declaração de variáveis no código, dispensando o uso da palavra-chave 'struct' a cada declaração.
typedef struct{
    char nome[50]; // Armazena a sequência de caracteres correspondente ao nome.
    int idade;     // Armazena a idade como valor numérico inteiro.
} Pessoa;

// Função de impressão que recebe um ponteiro constante para Pessoa ('const Pessoa *p').
// A passagem por ponteiro evita copiar a struct inteira na memória (otimização de desempenho),
// enquanto o qualificador 'const' impede alterações acidentais nos dados apontados.
void imprimePessoa(const Pessoa *p){
    // O operador seta (->) é empregado para desreferenciar o ponteiro e acessar o atributo 'nome' diretamente.
    printf("Nome: %s\n", p->nome);
    // Acessa e exibe o atributo 'idade' a partir do endereço armazenado em 'p'.
    printf("Idade: %d\n", p.idade);
}

int main(){
    // Instancia uma variável do tipo Pessoa utilizando o tipo abreviado.
    Pessoa p;
    
    // Copia a string "Joao Paulo" para o vetor de caracteres do membro 'nome'.
    strcpy(p.nome, "Joao Paulo");
    // Atribui o valor 18 ao atributo 'idade'.
    p.idade = 18;

    // Passa o endereço de memória de 'p' (&p) para evitar duplicar a estrutura durante a chamada da função.
    imprimePessoa(&p);
    
    // Retorna código 0 indicando que o programa executou com sucesso.
    return 0;    
}

