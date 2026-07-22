// Guard contra inclusões repetidas
#ifndef INTERFACE_H
#define INTERFACE_H

#include "../core/lista_core.h" // Necessário para reconhecer as structs List e Book
#include "../core/error.h"      // Inclui a definição do enum Status para formatação de feedback visual

// --------------------------------------------- //
//       Protótipos do Módulo de Interface (UI)
// --------------------------------------------- //

// Converte os códigos de enum Status do Core em mensagens explicativas no console para o usuário
void trataStatus(Status st);

// Captura e valida a entrada de números inteiros positivos via terminal, sanitizando o buffer
int validaInt();

// Captura e valida a entrada de números de ponto flutuante positivos via terminal
float validaFloat();

// Exibe o menu principal interativo e processa os comandos e operações do usuário
void menu(List* lista);

#endif // INTERFACE_H