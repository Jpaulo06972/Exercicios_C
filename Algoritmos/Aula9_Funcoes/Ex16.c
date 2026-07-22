#include <stdio.h>    // Entrada e saida padrao (printf, scanf)
#include <stdbool.h>  // Suporte a tipos booleanos (bool, true, false)
#include <string.h>   // Funcoes de manipulacao de strings (strlen, strcmp)
#include <ctype.h>    // Funcoes de manipulacao de caracteres (tolower, toupper)

// Opção 1: verifica se um numero inteiro eh par testando a divisibilidade por 2
bool eh_par(int a)
{
    if ((a % 2) == 0){
        return(true); // Retorna verdadeiro se o resto da divisao por 2 for zero
    }else{
        return(false); // Retorna falso para numeros impares
    }
}

// Opção 2: solicita e le um numero real do teclado em formato double
double lee()
{
    double num;
    printf("Digite um numero: ");
    scanf("%lf", &num); // Le o numero de ponto flutuante (%lf)
    return num;         // Retorna o valor fornecido
}

// Opção 2 (auxiliar): isola e retorna a parte fracionaria do numero real
double fracionario(double a)
{
    return a - (int)a; // Subtrai a parte inteira (cast para int) do valor original
}

// Opção 3: calcula o fatorial de um numero inteiro positivo de forma iterativa
int fatorial(int a)
{
    int fat = 1; // Inicializa o acumulador com o elemento neutro da multiplicacao

    for(int i = 0; i < a; i++)
    {
        fat = fat * (a - i); // Multiplica consecutivamente pelos fatores decrescentes
    }     

    return fat; // Retorna o valor do fatorial calculado
}

// Opção 4: imprime todos os numeros pares contidos no intervalo entre A e B
int pares(int a, int b)
{
    // Trata a iteracao crescente conforme a ordem entre os dois limites informados
    if (a < b)
    {
        printf("Numeros pares entre %d e %d:\n", a, b);
        for (int i = a; i <= b; i++)
        {
            if ((i % 2) == 0)
            {
                printf("%d\t", i); // Exibe o numero se for divisivel por 2
            }
        }
    }else{
        printf("Numeros pares entre %d e %d:\n", b, a);
        for (int i = b; i <= a; i++)
        {
            if ((i % 2) == 0)
            {
                printf("%d\t", i); // Exibe o numero se for divisivel por 2
            }
        }
    }

    return 0;
}

// Opção 5: retorna a quantidade de caracteres de uma string usando strlen
int len(char a[100])
{    
    return strlen(a); // Retorna o tamanho total da cadeia de caracteres
}

// Opção 6: conta a frequencia de um caractere na string de modo case-insensitive
int qtdCarcter(char text[100], char achar){
    int qtd = 0, tamanho;

    tamanho = strlen(text); // Obtem a extensao do texto
    
    for (int i = 0; i < tamanho; i++)
    {
        // Converte ambos os caracteres para minusculo para desconsiderar diferencas de caixa
        if(tolower(text[i]) == tolower(achar))
        {
            qtd++; // Incrementa contador ao encontrar caractere correspondente
        }

    }
    return qtd; // Retorna o total acumulado
}

// Opção 7: realiza a copia de uma string para outra incluindo o caractere de termino nulo ('\0')
void copia(const char* origem, char* destino) {
    
    int tamanho = strlen(origem);
    for (int i = 0; i <= tamanho; i++) { // Percorre ate 'tamanho' para copiar tambem o '\0'
        destino[i] = origem[i];
    }
}

// Opção 8: verifica se a string informada eh um palindromo
int pali(char text[100]){

    int tamanho, result;
    char textInvertido[100];

    tamanho = strlen(text);
 
    // Inverte a sequencia de caracteres do texto original
    for (int i = 0; i < tamanho; i++)
    {
        textInvertido[tamanho - i - 1] = text[i];        
    }

    textInvertido[tamanho] = '\0'; // Adiciona o terminador de string nulo
    
    // Compara a string original com a invertida
    result = strcmp(text, textInvertido);

    if (result == 0){
        return 1; // Retorna 1 para confirmar palindromo
    } else{
        return 0; // Retorna 0 caso nao seja palindromo
    }
}

// Opção 9: converte todos os caracteres da string para caixa alta
void converte(const char* text, char* new){
    int tamanho;

    tamanho = strlen(text);

    // Transforma cada caractere individualmente em maiusculo
    for (int i = 0; i < tamanho; i++)
    {
        new[i] = toupper(text[i]);
    }
    
    new[tamanho] = '\0'; // Garante o caractere nulo ao final do vetor

}

// Opção 10: exibe os elementos de um vetor
void PrintVector(int sz, int vec[sz]){

    printf("Valores do vetor:\n");
    for (int i = 0; i < sz; i++) 
    {
        printf("%d\n", vec[i]); // Imprime cada elemento do vetor
    }
}

// Opção 11: realiza a troca de valores entre dois inteiros recebidos por ponteiros
void Swap(int *a, int *b){
    int temp;

    temp = *a; // Guarda o valor do primeiro endereco de memoria
    *a = *b;   // Copia o valor do segundo endereco para o primeiro
    *b = temp; // Grava o valor armazenado em temp no segundo endereco

    printf("\nNovo valor de A: %d\n", *a);
    printf("Novo valor de B: %d\n", *b);
    
}

// Opção 12: ordena um vetor de inteiros em ordem crescente usando Bubble Sort
void OrdenarCrescente(int sz, int vec[sz]){
    int temp;

    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz - i - 1; j++)
        { 
            // Compara elementos adjacentes e permuta se estiverem fora de ordem
            if (vec[j] > vec[j + 1]){
                temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }

    // Imprime o resultado do vetor ordenado
    printf("Vetor ordenado: ");
    for(int i = 0; i < sz; i++)
    {
        printf(" %d", vec[i]);
    }
    printf("\n\n");
}

// Opção 13: separa os elementos de um vetor em dois vetores (pares e impares) e atualiza tamanhos via ponteiro
void SeparaParImpar(int sz, int vec[sz], int vPar[], int vImpar[], int *szPar, int *szImpar){
    
    int contPar = 0, contImpar = 0;

    // Contabiliza ocorrencias de numeros pares e impares
    for (int i = 0; i < sz; i++)
    {
        if ((vec[i] % 2) == 0)
        {
            contPar++;
        } else{
            contImpar++;
        }
    }
    
    // Atualiza os tamanhos de saída por referencia
    *szPar = contPar;
    *szImpar = contImpar;

    int idxP = 0, idI = 0;
    
    // Distribui os elementos para os vetores de destino
    for (int i = 0; i < sz; i++)
    {        
        if ((vec[i] % 2) == 0)
        {
            vPar[idxP++] = vec[i];
        } else{
            vImpar[idI++] = vec[i];
        }             
    }
    
    // Exibe os vetores de pares e impares gerados
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

// Opção 14: exibe os elementos de uma matriz bidimensional formatados
void printMatriz(int nRows, int nCols, int matriz[nRows][nCols]){

    printf("Matriz: \n");
    
    for(int i = 0; i < nRows; i ++)
    {
        for(int j = 0; j < nCols; j ++)
        {
            printf("%d\t", matriz[i][j]); // Formata exibicao em tabela com tabulacoes
        }
        printf("\n");
    }

    printf("\n\n");
    
}

// Opção 15: executa a multiplicacao de duas matrizes (A x B = C) apos validar compatibilidade de dimensoes
bool MultMatriz(int linhasA, int colunasA, int matrizA[linhasA][colunasA], int linhasB, int colunasB, int matrizB[linhasB][colunasB]){

    // Valida regra matricial: colunas de A devem ser iguais as linhas de B
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
    
    // Calcula a matriz produto C
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

// Bloco principal: menu interativo para selecao e execucao de cada exercicio
int main()
{
    // Variavel de controle para armazenamento da opcao selecionada pelo usuario
    int opcao = 0;

    // Estrutura de repeticao 'do-while' para manter o menu ativo ate que o usuario digite 0 (Sair)
    do
    {
        // Exibe o cabeçalho interativo do menu principal com todas as opcoes disponiveis
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

        // Estrutura condicional 'switch' para desviar a execucao conforme o codigo da opcao digitada
        switch (opcao)
        {
            // Case 1: le um numero e verifica sua paridade
            case 1:
            {                
                printf("===============================================================\n");
                printf("                1 - Retorna se inteiro eh par.                 \n");      
                printf("===============================================================\n");

                int num;
                bool par;
                printf("Digite um numero: ");
                scanf("%d", &num);

                // Executa a verificacao booleana de paridade
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

            // Case 2: le um valor real e extrai sua parte fracionaria
            case 2:
            {
                printf("===============================================================\n");
                printf("       2 - Le um numero real e retona a parte fracionara.      \n");      
                printf("===============================================================\n");

                double num, frac;
                num  = lee();
                frac = fracionario(num); // Isola os decimais

                printf("Valor lido: %f\n", num);
                printf("Valor da parte fracionaria: %f", frac);
                printf("\n");
                printf("\n");

                break;
            }

            // Case 3: le um numero estritamente positivo e calcula seu fatorial
            case 3:
            {
                printf("===============================================================\n");
                printf("          3 - Retorna o fatorial de um inteiro positivo.       \n");      
                printf("===============================================================\n");

                int num = 0, fat;
                // Laço de validacao da entrada para forcar valor maior que zero
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

            // Case 4: le dois limites inteiros e lista todos os numeros pares no intervalo
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

                pares(num1, num2); // Imprime a sequencia de pares
                printf("\n");

                break;
            }

            // Case 5: calcula a quantidade de caracteres de uma string lida do teclado
            case 5:
            {
                printf("===============================================================\n");
                printf("               5 - Retorna o tamanho da string.                \n");      
                printf("===============================================================\n");

                int tamanho;
                char text[100]; // Buffer local para a frase
                
                printf("Digite uma string: ");
                scanf("%[^\n]", text);

                tamanho = len(text);

                printf("Essa string: %s\n", text);
                printf("Tem o tamanho de : %d\n", tamanho);
                printf("\n");

                break;
            }

            // Case 6: conta ocorrencias de um caractere alvo dentro da string informada
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

                cont = qtdCarcter(text, find); // Executa busca case-insensitive

                printf("Na string '%s' possui %d '%c'\n", text, cont, toupper(find));
                printf("\n");

                break;
            }

            // Case 7: copia o conteudo de uma string para uma segunda variavel de string
            case 7:
            {
                printf("===============================================================\n");
                printf("             7 - Copia uma string para outra.                  \n");      
                printf("===============================================================\n");

                char text[100], copiaStr[100];
                printf("Digite uma string: ");
                scanf(" %[^\n]", text); 

                copia(text, copiaStr); // Efetua a copia caractere a caractere

                printf("String copiada: %s\n", copiaStr);
                printf("\n");

                break;
            }

            // Case 8: testa se um texto lido eh um palindromo
            case 8:
            {
                printf("===============================================================\n");
                printf("          8 - Retorna se a string eh um palindromo.            \n");      
                printf("===============================================================\n");

                char text[100];
                int eh_palin;
                
                
                printf("Digite uma string: ");
                scanf(" %[^\n]", text);
                
                eh_palin = pali(text); // Inverte e compara com strcmp

                if (eh_palin)
                {
                    printf("Esse texto eh palindromo: %s\n", text);
                }else {
                    printf("Esse texto nao eh palindromo: %s\n", text);
                }

                printf("\n");

                break;
            }
            // Case 9: converte o texto digitado para maiusculas
            case 9:
            {
                printf("===============================================================\n");
                printf("             9 - Converte string para maiusculo.               \n");      
                printf("===============================================================\n");

                char text[100], new[100];
                printf("Digite uma string: ");
                scanf(" %[^\n]", text); 

                converte(text, new); // Aplica toupper em todos os elementos

                printf("String convertida: %s\n", new);
                printf("\n");

                break;
            }

            // Case 10: le um vetor de inteiros e imprime seus elementos
            case 10:
            {
                printf("===============================================================\n");
                printf("                     10 - Imprime o Vetor.                     \n");      
                printf("===============================================================\n");

                int sz;

                printf("Digite o tamanho do vetor: ");
                scanf("%d", &sz);

                int vet[sz];

                // Preenche o vetor
                for (int i = 0; i < sz; i++)
                {
                    printf("Digite o valor do vet[%d]: ", i);
                    scanf("%d", &vet[i]);
                }

                PrintVector(sz, vet); // Imprime elemento a elemento                      
                printf("\n");
                
                break;
            }
            // Case 11: realiza a troca de valores entre duas variaveis inteiras via ponteiros
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

                Swap(pt1, pt2); // Executa a troca direta nos enderecos   
                printf("\n");          
                
                break;
            }
            // Case 12: ordena um vetor informado em ordem crescente
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

                OrdenarCrescente(sz, vet); // Executa ordenacao Bubble Sort  
                
                break;
            } 
            // Case 13: divide um vetor em dois vetores (um de pares e um de impares)
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

                SeparaParImpar(sz, vet, vetPar, vetImpar ,&tamPar, &tamIpar); // Separa e imprime os vetores
                
                break;
            } 
            // Case 14: le e exibe uma matriz bidimensional formatada
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
                
                printMatriz(m, n, matriz); // Imprime a matriz no console 
                
                break;
            } 
            // Case 15: le duas matrizes e efetua a multiplicacao matricial (A x B)
            case 15:
            {
                printf("===============================================================\n");
                printf("                 15 - Multiilicacao matriz.                    \n");      
                printf("===============================================================\n");

                int m, n, y, o;

                // Coleta dimensoes da Matriz A
                printf("Digite a Quantidade de Linhas e Colunas da Matriz A: ");
                scanf("%d %d", &m, &n);

                // Garante que as dimensoes sao validas
                while ((m < 0) || (n < 0)){
                    printf("VALOR INVALIDO!!\n");
                    printf("Digite a Quantidade de Linhas e Colunas da Matriz A: ");
                    scanf("%d %d", &m, &n);
                }

                // Coleta dimensoes da Matriz B
                printf("Digite a Quantidade de Linhas e Colunas da Matriz B: ");
                scanf("%d %d", &y, &o);

                // Garante que as dimensoes sao validas
                while ((y < 0) || (o < 0)){
                    printf("VALOR INVALIDO!!\n");
                    printf("Digite a Quantidade de Linhas e Colunas da Matriz B: ");
                    scanf("%d %d", &y, &o);
                }

                int a[m][n];
                int b[y][o];
                
                // Preenche Matriz A
                for (int i = 0; i < m; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        printf("Valor Matriz A[%d][%d]: ", i, j);
                        scanf("%d", &a[i][j]);
                    }
                }

                printf("\n");
                
                // Preenche Matriz B
                for (int i = 0; i < y; i++)
                {
                    for(int j = 0; j < o; j++)
                    {
                        printf("Valor Matriz b[%d][%d]: ", i, j);
                        scanf("%d", &b[i][j]);
                    }
                }

                printf("\n");
                MultMatriz(m, n, a, y, o, b); // Calcula e imprime a matriz resultante                            
                break;
            }             
            // Case 0: opcao para encerramento do programa
            case 0:
                printf("Saindo...\n");
                break;

            // Default: mensagem de alerta para opcoes invalidas nao listadas no menu
            default:
                printf("Valor Invalido Digite a Nova Opcao\n");
                printf("\n");
                break;
        }


    } while (opcao != 0); // Continua no laço ate opcao ser igual a 0
    
	return 0; // Finalizacao com sucesso
}