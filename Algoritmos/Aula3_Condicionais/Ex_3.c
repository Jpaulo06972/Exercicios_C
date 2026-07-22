// Inclui a biblioteca padrao para entrada e saida de dados
#include <stdio.h>
// Inclui definicoes de tipos booleanos
#include <stdbool.h>

int main()
{
	// Variavel para armazenar a pontuacao/nota do aluno
	float nota; 

	// Solicita o valor da nota
	printf("Digite sua nota: ");
	// Le o valor em ponto flutuante digitado
	scanf("%f", &nota);

    // Estrutura de decisao encadeada para classificar a nota por faixas de desempenho
    if (nota < 5)
    {
        // Notas abaixo de 5 sao classificadas como Insuficiente
        printf("Insuficiente");
        
    } else if (nota < 7) {
        // Notas entre 5.0 e 6.99 pertencem a faixa Regular
        printf("Regular");
        
    } else if (nota < 9) {
        // Notas entre 7.0 e 8.99 pertencem a faixa Bom
        printf("Bom");
        
    }else if (nota > 10){
        // Trata a entrada de notas superiores ao limite maximo de 10 como valor invalido
        printf("Nota invalida");
    }else {
        // Notas entre 9.0 e 10.0 sao classificadas como Excelente
        printf("Excelente");
    }

	// Finaliza o programa com sucesso
	return 0;
}
