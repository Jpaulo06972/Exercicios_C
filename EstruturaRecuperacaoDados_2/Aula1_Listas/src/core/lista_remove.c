#include <stdlib.h>
#include <assert.h>
#include "lista_core.h"
#include "lista_remove.h"
#include "error.h"

// --------------------------------------------- //
//      Função Remove no Início da Lista
// --------------------------------------------- //
// Desaloca o primeiro nó da lista encadeada e reajusta o ponteiro descritor de início.
Status removeFront(List* list){

    // Proteção contra ponteiros nulos informados como parâmetro da função
    if (list == NULL) return ERR_LIST_NULL;

    // Impede a operação se a lista já estiver vazia para evitar violação de acesso à memória
    if (list->head == NULL) return ERR_EMPTY_LIST;

    // Salva a referência do nó atual da cabeça antes de desconectá-lo
    Book *toDelete = list->head;

    // Atualiza o ponteiro de início da lista para o segundo elemento (próximo nó)
    list->head = toDelete->nextNode;

    // Libera o bloco de memória dinâmica alocado para o nó removido (evita vazamento de memória)
    free(toDelete);

    // Decrementa o contador de elementos no descritor
    list->size--;

    return STATUS_OK; // Retorna status de sucesso
}

// --------------------------------------------- //
//       Função Remove no Fim da Lista
// --------------------------------------------- //
// Localiza o último nó, desfaz o encadeamento a partir do penúltimo e desaloca a memória do elemento final.
Status removeBack(List* list){

    // Garante que o descritor da lista é um ponteiro válido
    if (list == NULL) return ERR_LIST_NULL;

    // Interrompe se a lista não possuir elementos para exclusão
    if (list->head == NULL) return ERR_EMPTY_LIST;

    // Caso de borda: Se a lista possui exatamente 1 nó, a remoção zera o ponteiro de início
    if (list->head->nextNode == NULL)
    {
        free(list->head);
        list->head = NULL;
        list->size--;
        return STATUS_OK;
    }

    // Ponteiro iterador iniciado na cabeça da lista
    Book *current = list->head;

    // Avança pela lista até posicionar 'current' exatamente no penúltimo elemento
    // (aquele cujo 'nextNo->nextNo' é NULL)
    while (current->nextNode->nextNode != NULL)
    {
        current = current->nextNode;
    }

    // Libera a memória alocada para o último nó
    free(current->nextNode);

    // Anula o ponteiro do penúltimo nó, transformando-o no novo nó final da lista
    current->nextNode = NULL;

    // Atualiza a contagem de elementos
    list->size--;

    return STATUS_OK;
}

// --------------------------------------------- //
//   Função Remove Acima do Limite de Preço
// --------------------------------------------- //
// Varre a lista completa e exclui todos os nós cujo preço seja superior ao limite fornecido.
Status removeOverPrice(List* list, float limit){

    // Validação da lista instanciada
    if (list == NULL) return ERR_LIST_NULL;

    // Retorna erro caso a lista esteja totalmente vazia
    if (list->head == NULL) return ERR_EMPTY_LIST;

    // Ponteiro de varredura atual
    Book *current = list->head;
    // Ponteiro para rastrear o nó imediatamente anterior (necessário para religar os nós adjacentes)
    Book *prev = NULL;

    // Percorre cada elemento da lista encadeada sequencialmente
    while (current != NULL)
    {
        // Verifica se o item atual ultrapassa a regra de preço estabelecida
        if (current->price > limit)
        {
            // Guarda o nó a ser removido temporariamente
            Book *aux = current;

            // Subcaso 1: É o primeiro nó da lista (cabeça), mas há outros elementos depois dele
            if (prev == NULL)
            {
                list->head = current->nextNode;
                current = list->head;
            }
            // Subcaso 3: É um nó intermediário ou o último nó
            else
            {
                prev->nextNode = current->nextNode; // Ignoira o nó atual religando o anterior ao próximo
                current = current->nextNode;
            }

            // Libera a memória heap do nó excluído e atualiza o tamanho global
            free(aux);
            list->size--;
        }
        else
        {
            // Se o nó não atende à condição de remoção, avança os dois ponteiros mantendo a rastreabilidade
            prev = current;
            current = current->nextNode;
        }
    }

    return STATUS_OK;
}

// --------------------------------------------- //
//       Função para Liberar Toda a Lista
// --------------------------------------------- //
// Destrói a estrutura por completo, desalocando individualmente cada nó da lista e por fim o cabeçalho.
Status freeList(List *list)
{

    // Valida se o ponteiro informado é válido
    if (list == NULL) return ERR_LIST_NULL;

    // Se já estiver limpa, apenas desaloca a estrutura descritora
    if (list->head == NULL)
    {
        free(list);
        return STATUS_OK;
    }

    Book *current = list->head;
    Book *nextNode = NULL;

    // Iteração para desalocar elemento por elemento sem perder a referência do próximo
    while (current != NULL)
    {
        // Armazena temporariamente o próximo nó da cadeia antes de liberar o atual
        nextNode = current->nextNode;
        free(current);
        // Avança o ponteiro de varredura
        current = nextNode;
    }

    // Libera a estrutura de controle (List) alocada no início
    free(list);
    return STATUS_OK;
}

// --------------------------------------------- //
//   Função Remove Livros com Código Duplicado
// --------------------------------------------- //
// Varre a lista completa e remove todos os nós que possuem código de livro duplicado.
Status removeDuplicateCode(List *list)
{

    // Proteção contra ponteiro nulo informado como parâmetro da função
    if (list == NULL)
        return ERR_LIST_NULL;

    // Impede a operação se a lista estiver vazia para evitar erro de memória
    if (list->head == NULL)
        return ERR_EMPTY_LIST;

    // Ponteiro de varredura principal iniciado na cabeça da lista
    Book *current = list->head;

    // Laço externo: percorre a lista elemento por elemento até o final
    while (current != NULL)
    {

        // Ponteiro para manter a referência do nó anterior ao nó comparado
        Book *previous = current;

        // Ponteiro comparador iniciado no próximo nó após o nó atual
        Book *compare = current->nextNode;

        // Laço interno: compara o nó atual com todos os nós subsequentes
        while (compare != NULL)
        {

            // Verifica se o código do livro atual é igual ao código do livro em comparação
            if (current->code == compare->code)
            {

                // Salva temporariamente a referência do nó duplicado que será removido
                Book *toDelete = compare;

                // Avança o ponteiro de comparação para o próximo nó antes de desalocar
                compare = compare->nextNode;

                // Desconecta o nó duplicado religando o nó anterior diretamente ao próximo nó
                previous->nextNode = toDelete->nextNode;

                // Libera a memória heap alocada para o nó duplicado
                free(toDelete);

                // Decrementa a quantidade de elementos armazenados na lista
                list->size--;
            }
            else
            {
                // Atualiza o nó anterior para o nó comparado atual
                previous = compare;

                // Avança o ponteiro de comparação para o próximo nó
                compare = compare->nextNode;
            }
        }

        // Avança o ponteiro de varredura principal para o próximo nó da lista
        current = current->nextNode;
    }

    return STATUS_OK; // Retorna status de sucesso após a remoção de todas as duplicatas
}
