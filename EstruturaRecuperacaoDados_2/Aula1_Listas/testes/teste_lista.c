#include <stdio.h>
#include <assert.h>
#include <string.h>

// Importação das interfaces da camada Core para execução de testes unitários automatizados
#include "../src/core/lista_core.h"
#include "../src/core/lista_insert.h"
#include "../src/core/lista_remove.h"
#include "../src/ui/interface.h"

// -------------------------------------------------------------
// Teste 1: Validação de Inicialização da Lista
// -------------------------------------------------------------
// Garante que a função de criação aloque o descritor e defina o estado inicial correto (lista vazia com tamanho zero).
void test_createList(){

    // Instancia uma nova lista via módulo Core
    List* list = createList();

    // Asserções para validar pré-condições da lista recém-criada
    assert(list != NULL);        // Valida se o ponteiro alocado não é nulo
    assert(list->head == NULL); // Confirma que não há nós apontados inicialmente
    assert(list->size == 0);   // Confirma que a contagem de elementos é zero

    // Limpa a memória utilizada durante o teste unitário
    freeList(list);
    printf("[PASSOU] - Teste Criar Lista\n");
}

// -------------------------------------------------------------
// Teste 2: Inserção no Início da Lista (LIFO/Cabeça)
// -------------------------------------------------------------
// Testa se múltiplos elementos inseridos na frente ajustam corretamente a nova cabeça da lista.
void test_insertFront(){

    List* list = createList();

    // Insere o primeiro elemento -> Estado final esperado: [A]
    insertFront(list, "Livro A", 101, 25.0);
    assert(list->size == 1);
    assert(strcmp(list->head->name, "Livro A") == 0); // Valida se 'A' tornou-se o nó inicial

    // Insere no início -> Estado final esperado: [B -> A]
    insertFront(list, "Livro B", 102, 10.0);
    assert(list->size == 2);
    assert(strcmp(list->head->name, "Livro B") == 0); // Valida se 'B' assumiu a nova cabeça

    // Insere no início -> Estado final esperado: [C -> B -> A]
    insertFront(list, "Livro C", 103, 34.0);
    assert(list->size == 3);
    assert(strcmp(list->head->name, "Livro C") == 0); // Valida se 'C' assumiu a nova cabeça

    freeList(list);
    printf("[PASSOU] - Teste Insert Front\n");
}

// -------------------------------------------------------------
// Teste 3: Inserção no Fim da Lista (FIFO/Cauda)
// -------------------------------------------------------------
// Verifica se a inserção no final mantém a ordem cronológica de inclusão e encadeamento dos ponteiros.
void test_insertBack(){

    List* list = createList();

    // Insere A -> Lista: [A]
    insertBack(list, "Livro A", 101, 25.0);
    assert(list->size == 1);
    assert(strcmp(list->head->name, "Livro A") == 0);

    // Insere B -> Lista: [A -> B]
    insertBack(list, "Livro B", 102, 10.0);
    assert(list->size == 2);
    assert(strcmp(list->head->name, "Livro A") == 0); // 'A' deve permanecer na cabeça
    assert(strcmp(list->head->nextNode->name, "Livro B") == 0); // 'B' deve ser o próximo elemento

    // Insere C -> Lista: [A -> B -> C]
    insertBack(list, "Livro C", 103, 34.0);
    assert(list->size == 3);
    assert(strcmp(list->head->name, "Livro A") == 0);
    assert(strcmp(list->head->nextNode->name, "Livro B") == 0);
    assert(strcmp(list->head->nextNode->nextNode->name, "Livro C") == 0); // 'C' deve ser o elemento final

    freeList(list);
    printf("[PASSOU] - Teste Insert Back\n");
}

// -------------------------------------------------------------
// Teste 4: Remoção do Primeiro Elemento
// -------------------------------------------------------------
// Garante que ao remover a cabeça da lista, o segundo elemento seja promovido a novo início.
void test_removeFront(){

    List* list = createList();

    // Prepara a lista com 2 itens: [A -> B]
    insertBack(list, "Livro A", 101, 25.0);
    insertBack(list, "Livro B", 102, 40.0);
    assert(list->size == 2);

    // Remove 'Livro A' (primeiro item)
    removeFront(list);

    // Valida se o tamanho reduziu e se 'Livro B' é a nova cabeça
    assert(list->size == 1);
    assert(strcmp(list->head->name, "Livro B") == 0);

    freeList(list);
    printf("[PASSOU] - Teste Remove Front\n");
}

// -------------------------------------------------------------
// Teste 5: Remoção do Último Elemento
// -------------------------------------------------------------
// Verifica se a remoção no fim desaloca o último nó e anula o ponteiro do penúltimo elemento.
void test_removeBack(){

    List* list = createList();

    // Prepara a lista com 3 elementos: [A -> B -> C]
    insertBack(list, "Livro A", 101, 25.0);
    insertBack(list, "Livro B", 102, 40.0);
    insertBack(list, "Livro C", 103, 30.0);
    assert(list->size == 3);

    // Remove 'Livro C' (último item)
    removeBack(list);

    // Confirma redução de tamanho e que o novo fim é 'Livro B'
    assert(list->size == 2);
    assert(strcmp(list->head->name, "Livro A") == 0);
    assert(strcmp(list->head->nextNode->name, "Livro B") == 0);

    freeList(list);
    printf("[PASSOU] - Teste Remove Back\n");
}

// -------------------------------------------------------------
// Teste 6: Remoção Condicional por Preço Limite
// -------------------------------------------------------------
// Avalia a filtragem da lista removendo apenas os elementos que excedam determinado patamar de preço.
void test_removeOverPrice(){

    List* list = createList();

    // Carga de dados para o teste de filtragem por critério
    insertBack(list, "Livro A", 101, 25.0); // Preço <= 35.0 (Mantido)
    insertBack(list, "Livro B", 102, 45.0); // Preço > 35.0 (Removido)
    insertBack(list, "Livro C", 103, 10.0); // Preço <= 35.0 (Mantido)
    insertBack(list, "Livro D", 104, 50.0); // Preço > 35.0 (Removido)
    insertBack(list, "Livro E", 105, 36.0); // Preço > 35.0 (Removido)
    insertBack(list, "Livro F", 106, 20.0); // Preço <= 35.0 (Mantido)
    insertBack(list, "Livro G", 107, 15.0); // Preço <= 35.0 (Mantido)

    // Aplica o filtro eliminando nós com valor superior a R$ 35.0
    removeOverPrice(list, 35.0);

    // Validações: devem restar 4 livros (25.0, 10.0, 20.0, 15.0)
    assert(list->size == 4); 
    assert(list->head->price == 25.0);        // Primeiro item restante
    assert(list->head->nextNode->price == 10.0); // Segundo item restante

    freeList(list);
    printf("[PASSOU] - Teste Remove Over Price\n");
}

// -------------------------------------------------------------
// Teste 7: Exibe Livro com Maior Preço da Lista
// -------------------------------------------------------------
// Avalia a filtragem da lista removendo apenas os elementos que excedam determinado patamar de preço.
void test_findBiggerPrice(){

    List* list = createList();

    Book* temp;

    // Carga de dados para o teste de filtragem por critério
    insertBack(list, "Livro A", 101, 25.0); // Preço <= 35.0 (Mantido)
    insertBack(list, "Livro B", 102, 45.0); // Preço > 35.0 (Removido)
    insertBack(list, "Livro C", 103, 10.0); // Preço <= 35.0 (Mantido)
    insertBack(list, "Livro D", 104, 50.0); // Preço > 35.0 (Removido)
    insertBack(list, "Livro E", 105, 36.0); // Preço > 35.0 (Removido)
    insertBack(list, "Livro F", 106, 20.0); // Preço <= 35.0 (Mantido)
    insertBack(list, "Livro G", 107, 15.0); // Preço <= 35.0 (Mantido)

    // Faz a leitura da lista e retorna o livro com maior preço
    temp = findBiggerPrice(list);

    assert(strcmp(temp->name, "Livro D") == 0); 
    assert(temp->code == 104); 
    assert(temp->price == 50.0);    

    // Aplica o filtro eliminando nós com valor superior a R$ 35.0
    removeOverPrice(list, 35.0);

    // Faz a leitura novamenteß da lista e retorna o livro com maior preço
    temp = findBiggerPrice(list);

    // Validações: devem restar 4 livros (25.0, 10.0, 20.0, 15.0)
    assert(strcmp(temp->name, "Livro A") == 0); 
    assert(temp->code == 101); 
    assert(temp->price == 25.0); 

    freeList(list);
    printf("[PASSOU] - Teste Exibe Livro com Maior Valor\n");

}

// -------------------------------------------------------------
// Teste 8: Remoção de Livros com Código Duplicado
// -------------------------------------------------------------
// Remove livros com códigos duplicados na lista.
void test_removeDuplicateCode(){

    List* list = createList();

    // Carga de dados para o teste de filtragem por critério
    insertBack(list, "Livro A", 101, 25.0); // Mantido
    insertBack(list, "Livro B", 102, 45.0); // Mantido
    insertBack(list, "Livro C", 102, 10.0); // Removido
    insertBack(list, "Livro D", 103, 50.0); // Mantido

    // Chama função para remover livros com códigos duplicados
    removeDuplicateCode(list);

    // Validações: devem restar 3 livros (25.0, 45.0, 50.0)
    assert(list->size == 3); 
    assert(list->head->code == 101); // Primeiro item restante
    assert(list->head->nextNode->code == 102); // Segundo item restante
    assert(list->head->nextNode->nextNode->code == 103); // Segundo item restante

    freeList(list);
    printf("[PASSOU] - Teste Remove Duplicate Code\n");

}

// -------------------------------------------------------------
// Executor Principal da Suíte de Testes
// -------------------------------------------------------------
int main(){
    printf("\n=== RODANDO SUÍTE DE TESTES UNITÁRIOS ===\n\n");

    // Executa individualmente cada caso de teste
    test_createList();
    test_insertFront();
    test_insertBack();
    test_removeFront();
    test_removeBack();
    test_removeOverPrice();
    test_findBiggerPrice();
    test_removeDuplicateCode();

    printf("\n>>> TODOS OS TESTES PASSARAM COM SUCESSO! <<<\n\n");
    return 0; // Sucesso da suíte
}
