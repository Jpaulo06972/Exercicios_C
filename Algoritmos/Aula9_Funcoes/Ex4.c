#include <stdio.h> // Inclui biblioteca para leitura e impressao de dados

// Imprime todos os numeros pares compreendidos no intervalo entre 'a' e 'b', independentemente de qual eh o maior
int pares(int a, int b)
{
    // Verifica se 'a' eh o limite inferior do intervalo
    if (a < b)
    {
        // Percorre de 'a' ate 'b' de forma crescente
        for (int i = a; i <= b; i++)
        {
            // Filtra e imprime apenas os numeros que sao divisiveis por 2
            if ((i % 2) == 0)
            {
                printf("%d\n", i);
            }
        }
    }else{
        // Tratamento para quando 'b' for menor ou igual a 'a', iterando do menor ('b') ate o maior ('a')
        for (int i = b; i <= a; i++)
        {
            // Filtra e imprime apenas os numeros cuja divisao por 2 possui resto zero
            if ((i % 2) == 0)
            {
                printf("%d\n", i);
            }
        }
    }

    return 0; // Retorna status basico indicando fim do processamento
}

int main()
{
    int num1, num2;
     
    // Solicita a entrada dos dois limites numéricos do intervalo ao usuario
    printf("Digite Valor de A: ");
    scanf("%d", &num1);
    printf("Digite Valor de B: ");
    scanf("%d", &num2);

    // Invoca o procedimento para exibir os pares contidos entre os valores informados
    pares(num1, num2);

    return 0; // Finalizacao normal do programa
}