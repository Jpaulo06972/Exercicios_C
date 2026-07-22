#include <stdio.h>  // Biblioteca para funcoes de entrada e saídas de dados (printf, scanf)
#include <string.h> // Biblioteca com utilitarios para manipulacao de strings (strlen)
#include <ctype.h>  // Biblioteca para operacoes com caracteres

int main(){
    // Buffer de 150 caracteres para armazenar a frase/string informada pelo usuario
    char text[150];
    // Contador de indice 'i' (percorre o texto), 'j' (percorre o vetor de vogais)
    // 'contVogais' acumula a quantidade de vogais e 'contConsoantes' armazena o calculo de consoantes/outros caracteres
    int i, j, contVogais = 0, contConsoantes = 0;
    // Vetor contendo os caracteres correspondentes as 5 vogais minusculas para checagem
    int vogais[5] = {'a', 'e', 'i', 'o', 'u'};
      
    // Solicita que o usuario digite uma string
    printf("Digite uma String aqui: ");
    // Le a frase completa com espacos ate o pressionamento da tecla ENTER (\n)
    scanf(" %[^\n]", text);

    // Percorre a string caractere a caractere ate alcançar o terminador nulo '\0'
    for (i = 0; text[i] != '\0'; i++)
    {
        // Laço interno para testar o caractere atual da string contra cada uma das 5 vogais
        for (j = 0; j < 5; j++)
        {
            // Se o caractere atual corresponder a qualquer uma das vogais, incrementa 'contVogais'
            if (text[i] == vogais[j])
            {
                contVogais ++;
            }
        }        
    }

    // Estima o total de consoantes/demais caracteres subtraindo o numero de vogais do tamanho total da string
    contConsoantes = strlen(text) - contVogais;

    // Exibe a string lida e os resultados obtidos da contagem
    printf("Essa String: %s\n", text);
    printf("%d Vogais \n", contVogais);
    printf("%d Consoantes \n", contConsoantes);

    // Sinaliza o encerramento correto do programa ao SO
    return 0;
}