// Trava de inclusão do cabeçalho da interface
#ifndef INTERFACE_H
#define INTERFACE_H

// Inclui o cabeçalho do core para reconhecer as structs da fila
#include "../core/fila_core.h"
// Inclui o cabeçalho de erros para formatar o status visualmente
#include "../core/error.h"

// --------------------------------------------- //
//          Protótipos do Módulo de UI           //
// --------------------------------------------- //

// Traduz o enum QueueStatus em mensagens claras exibidas no terminal
void handleStatus(QueueStatus status);

// Lê e valida um número inteiro positivo digitado pelo usuário, tratando entradas inválidas
int readPositiveInt(const char* prompt);

// Percorre e exibe na tela todos os elementos da fila no formato visual
void displayQueue(const Queue* queue);

// Exibe o menu interativo no console e gerencia as escolhas do usuário
void runMenu(Queue* queue);

#endif // INTERFACE_H
