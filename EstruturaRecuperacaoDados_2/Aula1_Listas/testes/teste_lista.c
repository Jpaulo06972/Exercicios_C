#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "../src/core/lista_core.h"
#include "../src/core/lista_insert.h"
#include "../src/core/lista_remove.h"
#include "../src/ui/interface.h"
#include "../src/core/error.h"

void test_createList(){

    List* list = createList();

    assert(list != NULL);
    assert(list->head == NULL);
    assert(list->size == 0);

    freeList(list);
    printf("[PASSOU] - Teste Criar Lista\n");
}

void test_insertFront(){

    List* list = createList();

    insertFront(list, "Livro A", 101, 25.0);
    assert(list->size == 1);
    assert(strcmp(list->head->name, "Livro A") == 0);

    insertFront(list, "Livro B", 102, 10.0);
    assert(list->size == 2);
    assert(strcmp(list->head->name, "Livro B") == 0);

    insertFront(list, "Livro C", 103, 34.0);
    assert(list->size == 3);
    assert(strcmp(list->head->name, "Livro C") == 0);

    freeList(list);
    printf("[PASSOU] - Teste Insert Front\n");
}

void test_insertBack(){

    List* list = createList();

    insertBack(list, "Livro A", 101, 25.0);
    assert(list->size == 1);
    assert(strcmp(list->head->name, "Livro A") == 0);

    insertBack(list, "Livro B", 102, 10.0);
    assert(list->size == 2);
    assert(strcmp(list->head->name, "Livro A") == 0);
    assert(strcmp(list->head->nextNode->name, "Livro B") == 0);

    insertBack(list, "Livro C", 103, 34.0);
    assert(list->size == 3);
    assert(strcmp(list->head->name, "Livro A") == 0);
    assert(strcmp(list->head->nextNode->name, "Livro B") == 0);
    assert(strcmp(list->head->nextNode->nextNode->name, "Livro C") == 0);

    freeList(list);
    printf("[PASSOU] - Teste Insert Back\n");
}

void test_removeFront(){

    List* list = createList();

    insertBack(list, "Livro A", 101, 25.0);
    insertBack(list, "Livro B", 102, 40.0);
    assert(list->size == 2);

    removeFront(list);

    assert(list->size == 1);
    assert(strcmp(list->head->name, "Livro B") == 0);

    freeList(list);
    printf("[PASSOU] - Teste Remove Front\n");
}

void test_removeBack(){

    List* list = createList();

    insertBack(list, "Livro A", 101, 25.0);
    insertBack(list, "Livro B", 102, 40.0);
    insertBack(list, "Livro C", 103, 30.0);
    assert(list->size == 3);

    removeBack(list);

    assert(list->size == 2);
    assert(strcmp(list->head->name, "Livro A") == 0);
    assert(strcmp(list->head->nextNode->name, "Livro B") == 0);

    freeList(list);
    printf("[PASSOU] - Teste Remove Back\n");
}

void test_removeOverPrice(){

    List* list = createList();

    insertBack(list, "Livro A", 101, 25.0);
    insertBack(list, "Livro B", 102, 45.0);
    insertBack(list, "Livro C", 103, 10.0);
    insertBack(list, "Livro D", 104, 50.0);
    insertBack(list, "Livro E", 105, 36.0);
    insertBack(list, "Livro F", 106, 20.0);
    insertBack(list, "Livro G", 107, 15.0);

    removeOverPrice(list, 35.0);

    assert(list->size == 4);
    assert(list->head->price == 25.0);
    assert(list->head->nextNode->price == 10.0);

    freeList(list);
    printf("[PASSOU] - Teste Remove Over Price\n");
}

void test_findBiggerPrice(){

    List* list = createList();

    Book* temp;

    insertBack(list, "Livro A", 101, 25.0);
    insertBack(list, "Livro B", 102, 45.0);
    insertBack(list, "Livro C", 103, 10.0);
    insertBack(list, "Livro D", 104, 50.0);
    insertBack(list, "Livro E", 105, 36.0);
    insertBack(list, "Livro F", 106, 20.0);
    insertBack(list, "Livro G", 107, 15.0);

    temp = findBiggerPrice(list);

    assert(temp != NULL);
    assert(strcmp(temp->name, "Livro D") == 0);
    assert(temp->code == 104);
    assert(temp->price == 50.0);

    removeOverPrice(list, 35.0);

    temp = findBiggerPrice(list);

    assert(temp != NULL);
    assert(strcmp(temp->name, "Livro A") == 0);
    assert(temp->code == 101);
    assert(temp->price == 25.0);

    freeList(list);
    printf("[PASSOU] - Teste Exibe Livro com Maior Valor\n");

}

void test_removeDuplicateCode(){

    List* list = createList();

    insertBack(list, "Livro A", 101, 25.0);
    insertBack(list, "Livro B", 102, 45.0);
    insertBack(list, "Livro C", 102, 10.0);
    insertBack(list, "Livro D", 103, 50.0);

    removeDuplicateCode(list);

    assert(list->size == 3);
    assert(list->head->code == 101);
    assert(list->head->nextNode->code == 102);
    assert(list->head->nextNode->nextNode->code == 103);

    freeList(list);
    printf("[PASSOU] - Teste Remove Duplicate Code\n");

}

void test_listErrors_NullPointer(){

    assert(insertFront(NULL, "Livro X", 999, 10.0) == ERR_LIST_NULL);
    assert(insertBack(NULL, "Livro X", 999, 10.0) == ERR_LIST_NULL);
    assert(removeFront(NULL) == ERR_LIST_NULL);
    assert(removeBack(NULL) == ERR_LIST_NULL);
    assert(removeOverPrice(NULL, 50.0) == ERR_LIST_NULL);
    assert(removeDuplicateCode(NULL) == ERR_LIST_NULL);
    assert(findBiggerPrice(NULL) == NULL);
    assert(freeList(NULL) == ERR_LIST_NULL);

    printf("[PASSOU] - Teste de Erro: Ponteiro Nulo na Lista\n");
}

void test_listErrors_EmptyList(){

    List* list = createList();

    assert(removeFront(list) == ERR_EMPTY_LIST);
    assert(removeBack(list) == ERR_EMPTY_LIST);
    assert(removeOverPrice(list, 50.0) == ERR_EMPTY_LIST);
    assert(removeDuplicateCode(list) == ERR_EMPTY_LIST);
    assert(findBiggerPrice(list) == NULL);

    freeList(list);
    printf("[PASSOU] - Teste de Erro: Lista Vazia (Underflow)\n");
}

int main(){
    printf("\n=== RODANDO SUÍTE DE TESTES UNITÁRIOS DA LISTA ===\n\n");

    test_createList();
    test_insertFront();
    test_insertBack();
    test_removeFront();
    test_removeBack();
    test_removeOverPrice();
    test_findBiggerPrice();
    test_removeDuplicateCode();

    test_listErrors_NullPointer();
    test_listErrors_EmptyList();

    printf("\n>>> TODOS OS TESTES PASSARAM COM SUCESSO! <<<\n\n");
    return 0;
}
