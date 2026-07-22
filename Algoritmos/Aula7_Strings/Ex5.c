#include <stdio.h>  // Biblioteca padrao para entrada e saida de dados (printf, scanf)
#include <string.h> // Funcoes para manipulacao de strings, como strlen()
#include <ctype.h>  // Funcoes para analise e conversao de caracteres, como toupper()

int main(){
    // 'iniciais' armazena a sequencia de letras iniciais extraidas do nome (buffer de 50 chars)
    char iniciais[50];
    // 'nome' aloca espaco suficiente (150 chars) para capturar nomes compostos longos
    char nome[150];
    // 'tamanho' armazena o numero de caracteres do nome, 'i' percorre a string original e 'j' controla o indice de 'iniciais'
    int tamanho, i, j = 0;
      
    // Pede ao usuario para informar um nome completo
    printf("Digite um nome com no maximo 100 caracteres: ");
    // Le a linha inteira incluindo os espacos em branco ate a tecla ENTER (\n)
    scanf(" %[^\n]", nome);

    // Obtem o tamanho exato da string lida
    tamanho = strlen(nome);

    // Valida se o tamanho do nome informado respeita a restricao de no maximo 100 caracteres
    while(tamanho > 100){
        printf("Digite novamente um nome com no maximo 10 0caracteres: ");
        scanf(" %[^\n]", nome); 
        tamanho = strlen(nome);
    }
    
    // Captura a primeira letra do primeiro nome (indice 0), converte-a para maiuscula (toupper)
    // e armazena no vetor 'iniciais' na posicao 0, pós-incrementando 'j' para a proxima insercao
    iniciais[j++] = toupper(nome[0]); 
    
    // Itera por todos os caracteres da string original buscando espacos em branco que separam as palavras
    for (i = 0; i < tamanho; i++)
    {
        // Sempre que encontra um caractere de espaco (' '), identifica que o caractere seguinte (i + 1) e o inicio de um novo sobrenome/nome
        if(nome[i] == ' ')
        {
            // Converte o caractere seguinte (nome[i + 1]) para maiusculo e o insere na proxima posicao disponivel em 'iniciais'
            iniciais[j++] = toupper(nome[i + 1]);
        }
        
    }
    // Adiciona o terminador nulo '\0' no final da string de iniciais para garantir a correta formatacao e impressao em C
    iniciais[j] = '\0';

    // Exibe o nome original e a string contendo todas as iniciais extraidas
    printf("Nome original: %s\n", nome);
    printf("Iniciais: %s\n", iniciais);

    // Encerra a execucao do programa retornando 0
    return 0;
}