// Importação das bibliotecas para suporte a operações de entrada/saída e tratamento de strings.
#include <stdio.h>
#include <string.h>

// Definição do tipo 'Pessoa' via typedef, consolidando atributos de nome e idade em um único tipo de dados.
typedef struct{
    char nome[50]; // Guarda o nome do indivíduo.
    int idade;     // Guarda a idade em formato inteiro.
} Pessoa;

// Função que recebe ponteiros constantes para duas structs Pessoa e retorna o ponteiro para a string do nome da pessoa mais velha.
// O tipo de retorno 'const char*' sinaliza que o texto retornado é somente para leitura.
const char* maisVelha(const Pessoa *p1, const Pessoa *p2){
    // Avalia se o valor do campo 'idade' apontado por p1 é superior ao apontado por p2.
    if (p1->idade > p2->idade){
        // Retorna o endereço da string 'nome' pertencente a p1.
        return p1->nome;
    } else{
        // Caso a idade de p2 seja maior ou igual, retorna o nome de p2.
        return p2->nome;
    }
}

int main(){
    // Inicialização das estruturas no momento da declaração utilizando listas de valores (literal de struct).
    Pessoa p1 = {"Joao Paulo", 18};
    Pessoa p2 = {"Maria", 48};
    
    // Invoca a função repassando os endereços de memória das duas instâncias e obtém o nome da pessoa mais velha.
    const char *velha = maisVelha(&p1, &p2);
    
    // Exibe a mensagem com o nome capturado.
    printf("Pessoa mais velha eh %s", velha);
    
    // Finaliza o programa retornando 0 (sucesso).
    return 0;    
}