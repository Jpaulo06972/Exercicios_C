#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool eh_par(int a)
{
    if ((a % 2) == 0){
        return(true);
    }else{
        return(false);
    }
}

double lee()
{
    double num;
    printf("Digite um numero: ");
    scanf("%lf", &num);
    return num;
}

double fracionario(double a)
{
    return a - (int)a;
}

int fatorial(int a)
{
    int fat = 1;

    for(int i = 0; i < a; i++)
    {
        fat = fat * (a - i);
    }

    return fat;
}

int pares(int a, int b)
{

    if (a < b)
    {
        printf("Numeros pares entre %d e %d:\n", a, b);
        for (int i = a; i <= b; i++)
        {
            if ((i % 2) == 0)
            {
                printf("%d\t", i);
            }
        }
    }else{
        printf("Numeros pares entre %d e %d:\n", b, a);
        for (int i = b; i <= a; i++)
        {
            if ((i % 2) == 0)
            {
                printf("%d\t", i);
            }
        }
    }

    return 0;
}

int len(char a[100])
{
    return strlen(a);
}

int qtdCarcter(char text[100], char achar){
    int qtd = 0, tamanho;

    tamanho = strlen(text);

    for (int i = 0; i < tamanho; i++)
    {

        if(tolower(text[i]) == tolower(achar))
        {
            qtd++;
        }

    }
    return qtd;
}

void copia(const char* origem, char* destino) {

    int tamanho = strlen(origem);
    for (int i = 0; i <= tamanho; i++) {
        destino[i] = origem[i];
    }
}

int pali(char text[100]){

    int tamanho, result;
    char textInvertido[100];

    tamanho = strlen(text);

    for (int i = 0; i < tamanho; i++)
    {
        textInvertido[tamanho - i - 1] = text[i];
    }

    textInvertido[tamanho] = '\0';

    result = strcmp(text, textInvertido);

    if (result == 0){
        return 1;
    } else{
        return 0;
    }
}

void converte(const char* text, char* new){
    int tamanho;

    tamanho = strlen(text);

    for (int i = 0; i < tamanho; i++)
    {
        new[i] = toupper(text[i]);
    }

    new[tamanho] = '\0';

}

void PrintVector(int sz, int vec[sz]){

    printf("Valores do vetor:\n");
    for (int i = 0; i < sz; i++)
    {
        printf("%d\n", vec[i]);
    }
}

void Swap(int *a, int *b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;

    printf("\nNovo valor de A: %d\n", *a);
    printf("Novo valor de B: %d\n", *b);

}

void OrdenarCrescente(int sz, int vec[sz]){
    int temp;

    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz - i - 1; j++)
        {

            if (vec[j] > vec[j + 1]){
                temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }

    printf("Vetor ordenado: ");
    for(int i = 0; i < sz; i++)
    {
        printf(" %d", vec[i]);
    }
    printf("\n\n");
}

void SeparaParImpar(int sz, int vec[sz], int vPar[], int vImpar[], int *szPar, int *szImpar){

    int contPar = 0, contImpar = 0;

    for (int i = 0; i < sz; i++)
    {
        if ((vec[i] % 2) == 0)
        {
            contPar++;
        } else{
            contImpar++;
        }
    }

    *szPar = contPar;
    *szImpar = contImpar;

    int idxP = 0, idI = 0;

    for (int i = 0; i < sz; i++)
    {
        if ((vec[i] % 2) == 0)
        {
            vPar[idxP++] = vec[i];
        } else{
            vImpar[idI++] = vec[i];
        }
    }

    printf("Vetores Pares:\n");
    for (int i = 0; i < contPar; i++)
    {
        printf(" %d\t", vPar[i]);
    }

    printf("\nVetores Impares:\n");
    for (int i = 0; i < contImpar; i++)
    {
        printf(" %d\t", vImpar[i]);
    }

    printf("\n\n");
}

void printMatriz(int nRows, int nCols, int matriz[nRows][nCols]){

    printf("Matriz: \n");

    for(int i = 0; i < nRows; i ++)
    {
        for(int j = 0; j < nCols; j ++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

}

bool MultMatriz(int linhasA, int colunasA, int matrizA[linhasA][colunasA], int linhasB, int colunasB, int matrizB[linhasB][colunasB]){

    if (colunasA != linhasB) {
        printf("Nao eh possivel calcular o produto de A x B\n");
        return false;
    }

    printf("\nMatriz A: \n");
    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasA; j++) {
            printf("%d\t", matrizA[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("\nMatriz B: \n");
    for (int i = 0; i < linhasB; i++) {
        for (int j = 0; j < colunasB; j++) {
            printf("%d\t", matrizB[i][j]);
        }
        printf("\n");
    }

    int matrizC[linhasA][colunasB];

    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasB; j++) {
            matrizC[i][j] = 0;
            for (int k = 0; k < colunasA; k++) {
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }

    printf("\nMatriz C (A x B): \n");
    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasB; j++) {
            printf("%d\t", matrizC[i][j]);
        }
    printf("\n");

    return true;
}

int main()
{

    int opcao = 0;

    do
    {

        printf("================================================================\n");
        printf("                                MENU                            \n");
        printf("1  - Retorna se inteiro eh par.                                 \n");
        printf("2  - Le um numero real e retona a parte fracionara.             \n");
        printf("3  - Retorna o fatorial de um inteiro positivo.                 \n");
        printf("4  - Escreve pares entre A e B.                                 \n");
        printf("5  - Retorna o tamanho da string.                               \n");
        printf("6  - Retorna qtd de vezes que um caractere aparece na string.   \n");
        printf("7  - Copia uma string para outra.                               \n");
        printf("8  - Retorna se a string eh um palindromo.                      \n");
        printf("9  - Converte string para maiusculo.                            \n");
        printf("10 - Imprime o Vetor.                                           \n");
        printf("11 - Faz swap entre dois inteiros.                              \n");
        printf("12 - Ordena o vetor em ordem crescente.                         \n");
        printf("13 - Separa os elemento de um vetor em pares e impares.         \n");
        printf("14 - Imprime uma matriz.                                        \n");
        printf("15 - Multiilicacao matriz.                                      \n");
        printf("0 - Sair.                                                       \n");
        printf("================================================================\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {

            case 1:
            {
                printf("===============================================================\n");
                printf("                1 - Retorna se inteiro eh par.                 \n");
                printf("===============================================================\n");

                int num;
                bool par;
                printf("Digite um numero: ");
                scanf("%d", &num);

                par = eh_par(num);

                if (par == true){
                    printf("O numero %d eh par\n", num);
                    printf("\n");
                }else{
                    printf("O numero %d nao eh par\n", num);
                    printf("\n");
                }
                break;
            }

            case 2:
            {
                printf("===============================================================\n");
                printf("       2 - Le um numero real e retona a parte fracionara.      \n");
                printf("===============================================================\n");

                double num, frac;
                num  = lee();
                frac = fracionario(num);

                printf("Valor lido: %f\n", num);
                printf("Valor da parte fracionaria: %f", frac);
                printf("\n");
                printf("\n");

                break;
            }

            case 3:
            {
                printf("===============================================================\n");
                printf("          3 - Retorna o fatorial de um inteiro positivo.       \n");
                printf("===============================================================\n");

                int num = 0, fat;

                while (num <= 0)
                {
                    printf("Digite um numero inteiro positivo: ");
                    scanf("%d", &num);
                }

                fat = fatorial(num);

                printf("Valor: %d\n", num);
                printf("Fatorial do valor: %d\n", fat);
                printf("\n");

                break;
            }

            case 4:
            {
                printf("===============================================================\n");
                printf("                 4 - Escreve pares entre A e B.                \n");
                printf("===============================================================\n");

                int num1, num2;

                printf("Digite Valor de A: ");
                scanf("%d", &num1);
                printf("Digite Valor de B: ");
                scanf("%d", &num2);

                pares(num1, num2);
                printf("\n");

                break;
            }

            case 5:
            {
                printf("===============================================================\n");
                printf("               5 - Retorna o tamanho da string.                \n");
                printf("===============================================================\n");

                int tamanho;
                char text[100];

                printf("Digite uma string: ");
                scanf("%[^\n]", text);

                tamanho = len(text);

                printf("Essa string: %s\n", text);
                printf("Tem o tamanho de : %d\n", tamanho);
                printf("\n");

                break;
            }

            case 6:
            {
                printf("===============================================================\n");
                printf("  6 - Retorna qtd de vezes que um caractere aparece na string. \n");
                printf("===============================================================\n");

                char find;
                char text[100];
                int cont = 0;

                printf("Digite uma string com no maximo 20 caracteres: ");
                scanf(" %[^\n]", text);

                printf("Digite o caracter a ser contado na string: ");
                scanf(" %c", &find);

                cont = qtdCarcter(text, find);

                printf("Na string '%s' possui %d '%c'\n", text, cont, toupper(find));
                printf("\n");

                break;
            }

            case 7:
            {
                printf("===============================================================\n");
                printf("             7 - Copia uma string para outra.                  \n");
                printf("===============================================================\n");

                char text[100], copiaStr[100];
                printf("Digite uma string: ");
                scanf(" %[^\n]", text);

                copia(text, copiaStr);

                printf("String copiada: %s\n", copiaStr);
                printf("\n");

                break;
            }

            case 8:
            {
                printf("===============================================================\n");
                printf("          8 - Retorna se a string eh um palindromo.            \n");
                printf("===============================================================\n");

                char text[100];
                int eh_palin;

                printf("Digite uma string: ");
                scanf(" %[^\n]", text);

                eh_palin = pali(text);

                if (eh_palin)
                {
                    printf("Esse texto eh palindromo: %s\n", text);
                }else {
                    printf("Esse texto nao eh palindromo: %s\n", text);
                }

                printf("\n");

                break;
            }

            case 9:
            {
                printf("===============================================================\n");
                printf("             9 - Converte string para maiusculo.               \n");
                printf("===============================================================\n");

                char text[100], new[100];
                printf("Digite uma string: ");
                scanf(" %[^\n]", text);

                converte(text, new);

                printf("String convertida: %s\n", new);
                printf("\n");

                break;
            }

            case 10:
            {
                printf("===============================================================\n");
                printf("                     10 - Imprime o Vetor.                     \n");
                printf("===============================================================\n");

                int sz;

                printf("Digite o tamanho do vetor: ");
                scanf("%d", &sz);

                int vet[sz];

                for (int i = 0; i < sz; i++)
                {
                    printf("Digite o valor do vet[%d]: ", i);
                    scanf("%d", &vet[i]);
                }

                PrintVector(sz, vet);
                printf("\n");

                break;
            }

            case 11:
            {
                printf("===============================================================\n");
                printf("               11 - Faz swap entre dois inteiros.              \n");
                printf("===============================================================\n");

                int num1, num2;

                printf("Digite Valor de A: ");
                scanf("%d", &num1);
                printf("Digite Valor de B: ");
                scanf("%d", &num2);

                int *pt1 = &num1;
                int *pt2 = &num2;

                Swap(pt1, pt2);
                printf("\n");

                break;
            }

            case 12:
            {
                printf("===============================================================\n");
                printf("            12 - Ordena o vetor em ordem crescente.            \n");
                printf("===============================================================\n");

                int sz;

                printf("Digite o tamanho do vetor: ");
                scanf("%d", &sz);

                int vet[sz];

                for (int i = 0; i < sz; i++)
                {
                    printf("Digite o valor do vet[%d]: ", i);
                    scanf("%d", &vet[i]);
                }

                OrdenarCrescente(sz, vet);

                break;
            }

            case 13:
            {
                printf("===============================================================\n");
                printf("    13 - Separa os elemento de um vetor em pares e impares.    \n");
                printf("===============================================================\n");

                int sz;

                printf("Digite o tamanho do vetor: ");
                scanf("%d", &sz);

                int vet[sz];
                int vetPar[sz];
                int vetImpar[sz];
                int tamPar, tamIpar;

                for (int i = 0; i < sz; i++)
                {
                    printf("Digite o valor do vet[%d]: ", i);
                    scanf("%d", &vet[i]);
                }

                SeparaParImpar(sz, vet, vetPar, vetImpar ,&tamPar, &tamIpar);

                break;
            }

            case 14:
            {
                printf("===============================================================\n");
                printf("                    14 - Imprime uma matriz.                   \n");
                printf("===============================================================\n");

                int m, n;

                printf("Digite o tamanho da Matriz[x][y]: ");
                scanf("%d %d", &m, &n);

                int matriz[m][n];

                for(int i = 0; i < m; i ++)
                {
                    for(int j = 0; j < n; j ++)
                    {
                        printf("Digite o valor da Matriz[%d][%d]: ", i, j);
                        scanf("%d", &matriz[i][j]);
                    }
                }

                printMatriz(m, n, matriz);

                break;
            }

            case 15:
            {
                printf("===============================================================\n");
                printf("                 15 - Multiilicacao matriz.                    \n");
                printf("===============================================================\n");

                int m, n, y, o;

                printf("Digite a Quantidade de Linhas e Colunas da Matriz A: ");
                scanf("%d %d", &m, &n);

                while ((m < 0) || (n < 0)){
                    printf("VALOR INVALIDO!!\n");
                    printf("Digite a Quantidade de Linhas e Colunas da Matriz A: ");
                    scanf("%d %d", &m, &n);
                }

                printf("Digite a Quantidade de Linhas e Colunas da Matriz B: ");
                scanf("%d %d", &y, &o);

                while ((y < 0) || (o < 0)){
                    printf("VALOR INVALIDO!!\n");
                    printf("Digite a Quantidade de Linhas e Colunas da Matriz B: ");
                    scanf("%d %d", &y, &o);
                }

                int a[m][n];
                int b[y][o];

                for (int i = 0; i < m; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        printf("Valor Matriz A[%d][%d]: ", i, j);
                        scanf("%d", &a[i][j]);
                    }
                }

                printf("\n");

                for (int i = 0; i < y; i++)
                {
                    for(int j = 0; j < o; j++)
                    {
                        printf("Valor Matriz b[%d][%d]: ", i, j);
                        scanf("%d", &b[i][j]);
                    }
                }

                printf("\n");
                MultMatriz(m, n, a, y, o, b);
                break;
            }

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Valor Invalido Digite a Nova Opcao\n");
                printf("\n");
                break;
        }

    } while (opcao != 0);

	return 0;
}
