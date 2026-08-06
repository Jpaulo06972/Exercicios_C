// Trava de inclusão do cabeçalho da interface
#ifndef INTERFACE_H
#define INTERFACE_H

// Inclui o cabeçalho do core para reconhecer as structs da pilha
#include "../core/pilha_core.h"
// Inclui o cabeçalho de erros para formatar o status visualmente
#include "../core/error.h"

// --------------------------------------------- //
//          Protótipos do Módulo de UI           //
// --------------------------------------------- //

// Traduz o enum StackStatus em mensagem claras exibida no terminal
void handleStatus(StackStatus status);

// Lê e valida um número inteiro positivo digitado pelo usuário, tratando entradas inválidas
int readPositiveInt(const char* prompt);

// Percorre e exibe na tela todos os elementos da pilha no formato visual
void displayStack(const Stack* stack);

// Exibe o menu interativo no console e gerencia as escolhas do usuário
void runMenu(Stack* stack);

#endif // INTERFACE_H