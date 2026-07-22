// Inclui biblioteca de E/S padrao
#include <stdio.h>
// Inclui tipo booleano
#include <stdbool.h>

int main()
{
	// Configura limite de tentativas (3), senha correta (1234), iterador de laço e variavel de entrada da senha
	int tent = 3, senha = 1234, i, digSenha; 
    
    // Laço deterministico executando no maximo 3 vezes para validar a autenticacao
    for (i = 1; i <= tent; i ++)
    {
        printf("Digite a senha: ");
        scanf("%d", &digSenha);
    
        // Compara a senha informada com a senha esperada
        if (digSenha == senha){
            printf("Acesso liberado\n");
            // Interrompe as tentativas restantes em caso de sucesso na autenticacao
            break;
        } else {
            // Notifica o erro de digite da senha para a tentativa atual
            printf("Acesso negado\n");
        }
    }

    // Apos esgotar todas as tentativas, se a ultima senha digitada continuar errada, bloqueia o usuario
    if (digSenha != senha) printf("Limite máximo de tentativas excedido. Usuário bloqueado!\n");
    
    // Retorna 0 para o sistema operacional
	return 0;
}