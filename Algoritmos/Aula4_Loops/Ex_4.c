#include <stdio.h>
#include <stdbool.h>

int main()
{
	int tent = 3, senha = 1234, i, digSenha; 
    
    for (i = 1; i <= tent; i ++)
    {
        printf("Digite a senha: ");
        scanf("%d", &digSenha);
    
        if (digSenha == senha){
            printf("Acesso liberado\n");
            break;
        } else {
            printf("Acesso negado\n");
        }
    }

    if (digSenha != senha) printf("Limite máximo de tentativas excedido. Usuário bloqueado!\n");
    
	return 0;
}