// Include guard para evitar inclusão múltipla deste cabeçalho durante a compilação
#ifndef ERRORS_H
#define ERRORS_H

// Enumeração de códigos de retorno para padronizar a sinalização de status de erro ou sucesso nas operações do sistema.
// Centralizar o tratamento de erros através desse enum evita falhas silenciosas e facilita a comunicação entre a lógica de dados (core) e a interface gráfica/linha de comando (ui).
typedef enum {
    STATUS_OK = 0,             // Indica execução sem intercorrências
    ERR_LIST_NULL,             // Ocorre quando um ponteiro nulo é repassado, prevenindo acessos indevidos à memória (segmentation fault)
    ERR_NO_MEMORY,             // Sinaliza falha na alocação dinâmica de memória via malloc ao tentar criar nós ou a estrutura da lista
    ERR_EMPTY_LIST,            // Protege a aplicação contra operações de remoção ou leitura em listas sem elementos registrados
    ERR_INVALID_PARAM          // Identifica quando os dados passados para as funções violam pré-condições da regra de negócio (ex: limites inválidos)
} Status;

#endif
