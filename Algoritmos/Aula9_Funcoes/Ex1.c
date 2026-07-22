#include <stdio.h>   // Fornece operacoes de entrada/saida de dados
#include <stdbool.h> // Habilita o tipo booleano nativo (bool) e os literais 'true' e 'false'

// Avalia a paridade de um numero inteiro recebido como parâmetro
bool eh_par(int a)
{
    // Testa se o resto da divisao do numero por 2 eh igual a zero
    if ((a % 2) == 0){
        return(true); // Retorna verdadeiro quando o numero eh divisivel por 2
    }else{
        return(false); // Retorna falso quando o numero eh impar
    }
}

int main()
{
	int num = 6; // Numero de teste para a verificacao
    bool par;   // Variavel booleana para receber o resultado da funcao
    
    // Chama a funcao eh_par passando o valor num como argumento
    par = eh_par(num);

    // Avalia o resultado obtido para exibir a mensagem adequada ao usuario
    if (par == 1){
        printf("O numero %d eh par", num);
    }else{
        printf("O numero %d nao eh par", num);
    }
    
	return 0; // Indica execucao concluida com exito
}
