// Guard contra inclusões repetidas
#ifndef INTERFACE_H
#define INTERFACE_H

#include "../core/lista_core.h" // Necessário para reconhecer as structs List e Book
#include "../core/error.h"      // Inclui a definição do enum Status para formatação de feedback visual

// --------------------------------------------- //
//       Protótipos do Módulo de Interface (UI)
// --------------------------------------------- //

// Converte os códigos de enum Status do Core em mensagens explicativas no console para o usuário
void handleStatus(Status st);

// Captura e valida a entrada de números inteiros positivos via terminal, exibindo mensagem personalizada
int validateInt(const char *message);

// Captura e valida a entrada de números de ponto flutuante positivos via terminal, exibindo mensagem personalizada
float validateFloat(const char *message);

// Captura e valida a entrada de texto/string via terminal, exibindo mensagem personalizada
void validateString(const char *message, char *buffer, int size);

// Faz a leitura da lista e verifica qual livro possui maior preço 
Book* findBiggerPrice(List* list);

// Exibe o menu principal interativo e processa os comandos e operações do usuário
void menu(List* list);

#endif // INTERFACE_H
