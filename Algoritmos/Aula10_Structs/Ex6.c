// Inclusão de bibliotecas padrão para entrada/saída, strings e suporte a tipos booleanos.
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Estrutura que agrupa as informações de cada indivíduo.
struct Pessoa{
    char nome[50]; // Nome da pessoa.
    int idade;     // Idade da pessoa.
}; 

// Função que percorre e imprime o conteúdo de cada elemento de um vetor de estruturas Pessoa.
// Em C, vetores decaem para ponteiros ao serem passados a funções, tornando necessário informar a quantidade de elementos via 'tamanho'.
void imprimePessoa(struct Pessoa p[], int tamanho){
    // Itera sobre todos os elementos do vetor de structs.
    for (int i = 0; i < tamanho; i++){
        // Exibe o número sequencial da pessoa (ajustado com i + 1 para o usuário).
        printf("\nPessoa %d", i + 1);
        // Exibe o nome contido na i-ésima posição.
        printf("\nNome: %s\n", p[i].nome);
        // Exibe a idade contida na i-ésima posição.
        printf("Idade: %d\n", p[i].idade);   
    }
}

int main(){
    // Define a quantidade total de cadastros a serem lidos.
    int cont = 2;
    // Declaração de um vetor de structs Pessoa com capacidade determinada por 'cont'.
    struct Pessoa p[cont];

    // Laço para solicitar e capturar os dados do usuário para cada registro do vetor.
    for(int i = 0; i < cont; i++)
    {  
        // Mensagem indicativa da pessoa atual no cadastro.
        printf("Digite os Dados da %d pessoa\n", i + 1);      
        printf("Nome: ");
        // Utiliza " %[^\n]" para capturar nomes compostos com espaços.
        // O espaço antes do '%' consome eventuais caracteres de nova linha ('\n') deixados no buffer de entrada.
        scanf(" %[^\n]", p[i].nome);

        printf("Idade: ");
        // Captura o inteiro da idade e armazena diretamente no membro da struct apontado por &p[i].idade.
        scanf("%d", &p[i].idade);
    }

    // Envia o array de structs e seu tamanho para a função de exibição.
    imprimePessoa(p, cont);      
    
    // Retorna 0 para indicar sucesso na execução do programa.
    return 0;    
}
