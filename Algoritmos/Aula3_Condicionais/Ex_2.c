// Inclui suporte a operacoes basicas de entrada/saida de dados
#include <stdio.h>
// Inclui suporte a definicoes do tipo booleano
#include <stdbool.h>

int main()
{
	// Variaveis para armazenar os criterios necessarios de elegibilidade para doacao de sangue
	int idade; 
	float peso;

	// Solicita a idade do doador
	printf("Digite sua idade: ");
	// Guarda a idade lida
	scanf("%d", &idade);

	// Solicita o peso em kg do doador
    printf("Digite seu peso: ");
	// Guarda o peso lido
	scanf("%f", &peso);
	
	// Verifica a regra de negocio para doacao: idade entre 17 e 68 anos (estritamente > 16 e < 69) E peso minimo de 50kg
	if (((idade > 16) && (idade < 69)) && (peso >= 50))
	{
	    // Executado quando todos os criterios biometricos e de idade sao satisfeitos simultaneamente
	    printf("Voce este apto para doar sangue");
	}else{
	    // Executado quando pelo menos uma das condicoes exigidas nao e atendida
	    printf("Voce nao esta apto para doar sangue");
	}

	// Finaliza a funcao main
	return 0;
}
