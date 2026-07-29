// Trava de inclusão para evitar que este arquivo seja carregado múltiplas vezes na compilação
#ifndef ERROR_H
#define ERROR_H

// Enumeração que define os códigos de status padronizados para o retorno das operações da fila
typedef enum {
    STATUS_SUCCESS = 0,     // Indica que a operação foi executada com sucesso
    ERR_QUEUE_NULL,         // Indica erro quando um ponteiro para a fila é nulo (evita crash)
    ERR_OUT_OF_MEMORY,      // Sinaliza falha na alocação de memória (malloc retornou NULL)
    ERR_QUEUE_EMPTY,        // Protege contra tentativa de remoção ou leitura em fila vazia
    ERR_INVALID_INPUT       // Indica que o parâmetro passado é inválido ou violou uma regra
} QueueStatus;

#endif // ERROR_H