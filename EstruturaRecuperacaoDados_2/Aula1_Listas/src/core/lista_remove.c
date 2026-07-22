#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "lista_core.h"
#include "lista_remove.h"
#include "error.h"

// --------------------------------------------- //
//      Função Remove no Início da Lista
// --------------------------------------------- //
// Desaloca o primeiro nó da lista encadeada e reajusta o ponteiro descritor de início.
Status removeFront(List* lista) {

    // Proteção contra ponteiros nulos informados como parâmetro da função
    if (lista == NULL) return ERR_LIST_NULL;

    // Impede a operação se a lista já estiver vazia para evitar violação de acesso à memória
    if (lista->inicio == NULL) return ERR_EMPTY_LIST;

    // Salva a referência do nó atual da cabeça antes de desconectá-lo
    Book* toDelete = lista->inicio;

    // Atualiza o ponteiro de início da lista para o segundo elemento (próximo nó)
    lista->inicio = toDelete->nextNo;
    
    // Libera o bloco de memória dinâmica alocado para o nó removido (evita vazamento de memória)
    free(toDelete);

    // Decrementa o contador de elementos no descritor
    lista->tamanho--;

    return STATUS_OK; // Retorna status de sucesso
}

// --------------------------------------------- //
//       Função Remove no Fim da Lista
// --------------------------------------------- //
// Localiza o último nó, desfaz o encadeamento a partir do penúltimo e desaloca a memória do elemento final.
Status removeBack(List* lista) {

    // Garante que o descritor da lista é um ponteiro válido
    if (lista == NULL) return ERR_LIST_NULL;

    // Interrompe se a lista não possuir elementos para exclusão
    if (lista->inicio == NULL) return ERR_EMPTY_LIST;

    // Caso de borda: Se a lista possui exatamente 1 nó, a remoção zera o ponteiro de início
    if (lista->inicio->nextNo == NULL) {
        free(lista->inicio);
        lista->inicio = NULL;
        lista->tamanho--;
        return STATUS_OK;
    }

    // Ponteiro iterador iniciado na cabeça da lista
    Book* current = lista->inicio;

    // Avança pela lista até posicionar 'current' exatamente no penúltimo elemento
    // (aquele cujo 'nextNo->nextNo' é NULL)
    while (current->nextNo->nextNo != NULL) {
        current = current->nextNo;
    }

    // Libera a memória alocada para o último nó
    free(current->nextNo);

    // Anula o ponteiro do penúltimo nó, transformando-o no novo nó final da lista
    current->nextNo = NULL;

    // Atualiza a contagem de elementos
    lista->tamanho--;

    return STATUS_OK;
}

// --------------------------------------------- //
//   Função Remove Acima do Limite de Preço
// --------------------------------------------- //
// Varre a lista completa e exclui todos os nós cujo preço seja superior ao limite fornecido.
Status removeOverPrice(List* lista, float limite) {
    
    // Validação da lista instanciada
    if (lista == NULL) return ERR_LIST_NULL;

    // Retorna erro caso a lista esteja totalmente vazia
    if (lista->inicio == NULL) return ERR_EMPTY_LIST;

    // Ponteiro de varredura atual
    Book* current = lista->inicio;
    // Ponteiro para rastrear o nó imediatamente anterior (necessário para religar os nós adjacentes)
    Book* anterior = NULL;

    // Percorre cada elemento da lista encadeada sequencialmente
    while (current != NULL) {
        // Verifica se o item atual ultrapassa a regra de preço estabelecida
        if (current->preco > limite) {
            // Guarda o nó a ser removido temporariamente
            Book* aux = current;

            // Subcaso 1: Era o único elemento restante da lista
            if (lista->tamanho == 1) {
                lista->inicio = NULL;
                current = NULL;
            } 
            // Subcaso 2: É o primeiro nó da lista (cabeça), mas há outros elementos depois dele
            else if (anterior == NULL) {
                lista->inicio = current->nextNo;
                current = lista->inicio;
            } 
            // Subcaso 3: É um nó intermediário ou o último nó
            else {
                anterior->nextNo = current->nextNo; // Ignoira o nó atual religando o anterior ao próximo
                current = current->nextNo;
            }

            // Libera a memória heap do nó excluído e atualiza o tamanho global
            free(aux);
            lista->tamanho--;
        } 
        else {
            // Se o nó não atende à condição de remoção, avança os dois ponteiros mantendo a rastreabilidade
            anterior = current;
            current = current->nextNo;
        }
    }

    return STATUS_OK;
}

// --------------------------------------------- //
//       Função para Liberar Toda a Lista
// --------------------------------------------- //
// Destrói a estrutura por completo, desalocando individualmente cada nó da lista e por fim o cabeçalho.
Status liberarLista(List* lista) {
    
    // Valida se o ponteiro informado é válido
    if (lista == NULL) return ERR_LIST_NULL;

    // Se já estiver limpa, apenas desaloca a estrutura descritora
    if (lista->inicio == NULL) {
        free(lista);
        return STATUS_OK;
    }

    Book* current = lista->inicio;
    Book* nextNode = NULL;

    // Iteração para desalocar elemento por elemento sem perder a referência do próximo
    while (current != NULL) {
        // Armazena temporariamente o próximo nó da cadeia antes de liberar o atual
        nextNode = current->nextNo;
        free(current);
        // Avança o ponteiro de varredura
        current = nextNode;
    }

    // Libera a estrutura de controle (List) alocada no início
    free(lista);
    return STATUS_OK;
}