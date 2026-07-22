#include <stdio.h>
#include <assert.h>
#include <string.h>

// Importação das interfaces da camada Core para execução de testes unitários automatizados
#include "../src/core/lista_core.h"
#include "../src/core/lista_insert.h"
#include "../src/core/lista_remove.h"

// -------------------------------------------------------------
// Teste 1: Validação de Inicialização da Lista
// -------------------------------------------------------------
// Garante que a função de criação aloque o descritor e defina o estado inicial correto (lista vazia com tamanho zero).
void teste_criarLista(){

    // Instancia uma nova lista via módulo Core
    List* lista = criarLista();

    // Asserções para validar pré-condições da lista recém-criada
    assert(lista != NULL);        // Valida se o ponteiro alocado não é nulo
    assert(lista->inicio == NULL); // Confirma que não há nós apontados inicialmente
    assert(lista->tamanho == 0);   // Confirma que a contagem de elementos é zero

    // Limpa a memória utilizada durante o teste unitário
    liberarLista(lista);
    printf("[PASSOU] - Teste Criar Lista\n");
}

// -------------------------------------------------------------
// Teste 2: Inserção no Início da Lista (LIFO/Cabeça)
// -------------------------------------------------------------
// Testa se múltiplos elementos inseridos na frente ajustam corretamente a nova cabeça da lista.
void teste_insertFront(){

    List* lista = criarLista();

    // Insere o primeiro elemento -> Estado final esperado: [A]
    insertFront(lista, "Livro A", 101, 25.0);
    assert(lista->tamanho == 1);
    assert(strcmp(lista->inicio->name, "Livro A") == 0); // Valida se 'A' tornou-se o nó inicial

    // Insere no início -> Estado final esperado: [B -> A]
    insertFront(lista, "Livro B", 102, 10.0);
    assert(lista->tamanho == 2);
    assert(strcmp(lista->inicio->name, "Livro B") == 0); // Valida se 'B' assumiu a nova cabeça

    // Insere no início -> Estado final esperado: [C -> B -> A]
    insertFront(lista, "Livro C", 103, 34.0);
    assert(lista->tamanho == 3);
    assert(strcmp(lista->inicio->name, "Livro C") == 0); // Valida se 'C' assumiu a nova cabeça

    liberarLista(lista);
    printf("[PASSOU] - Teste Insert Front\n");
}

// -------------------------------------------------------------
// Teste 3: Inserção no Fim da Lista (FIFO/Cauda)
// -------------------------------------------------------------
// Verifica se a inserção no final mantém a ordem cronológica de inclusão e encadeamento dos ponteiros.
void teste_insertBack(){

    List* lista = criarLista();

    // Insere A -> Lista: [A]
    insertBack(lista, "Livro A", 101, 25.0);
    assert(lista->tamanho == 1);
    assert(strcmp(lista->inicio->name, "Livro A") == 0);

    // Insere B -> Lista: [A -> B]
    insertBack(lista, "Livro B", 102, 10.0);
    assert(lista->tamanho == 2);
    assert(strcmp(lista->inicio->name, "Livro A") == 0); // 'A' deve permanecer na cabeça
    assert(strcmp(lista->inicio->nextNo->name, "Livro B") == 0); // 'B' deve ser o próximo elemento

    // Insere C -> Lista: [A -> B -> C]
    insertBack(lista, "Livro C", 103, 34.0);
    assert(lista->tamanho == 3);
    assert(strcmp(lista->inicio->name, "Livro A") == 0);
    assert(strcmp(lista->inicio->nextNo->name, "Livro B") == 0);
    assert(strcmp(lista->inicio->nextNo->nextNo->name, "Livro C") == 0); // 'C' deve ser o elemento final

    liberarLista(lista);
    printf("[PASSOU] - Teste Insert Back\n");
}

// -------------------------------------------------------------
// Teste 4: Remoção do Primeiro Elemento
// -------------------------------------------------------------
// Garante que ao remover a cabeça da lista, o segundo elemento seja promovido a novo início.
void teste_removeFront(){

    List* lista = criarLista();

    // Prepara a lista com 2 itens: [A -> B]
    insertBack(lista, "Livro A", 101, 25.0);
    insertBack(lista, "Livro B", 102, 40.0);
    assert(lista->tamanho == 2);

    // Remove 'Livro A' (primeiro item)
    removeFront(lista);

    // Valida se o tamanho reduziu e se 'Livro B' é a nova cabeça
    assert(lista->tamanho == 1);
    assert(strcmp(lista->inicio->name, "Livro B") == 0);

    liberarLista(lista);
    printf("[PASSOU] - Teste Remove Front\n");
}

// -------------------------------------------------------------
// Teste 5: Remoção do Último Elemento
// -------------------------------------------------------------
// Verifica se a remoção no fim desaloca o último nó e anula o ponteiro do penúltimo elemento.
void teste_removeBack(){

    List* lista = criarLista();

    // Prepara a lista com 3 elementos: [A -> B -> C]
    insertBack(lista, "Livro A", 101, 25.0);
    insertBack(lista, "Livro B", 102, 40.0);
    insertBack(lista, "Livro C", 103, 30.0);
    assert(lista->tamanho == 3);

    // Remove 'Livro C' (último item)
    removeBack(lista);

    // Confirma redução de tamanho e que o novo fim é 'Livro B'
    assert(lista->tamanho == 2);
    assert(strcmp(lista->inicio->name, "Livro A") == 0);
    assert(strcmp(lista->inicio->nextNo->name, "Livro B") == 0);

    liberarLista(lista);
    printf("[PASSOU] - Teste Remove Back\n");
}

// -------------------------------------------------------------
// Teste 6: Remoção Condicional por Preço Limite
// -------------------------------------------------------------
// Avalia a filtragem da lista removendo apenas os elementos que excedam determinado patamar de preço.
void teste_removeOverPrice(){

    List* lista = criarLista();

    // Carga de dados para o teste de filtragem por critério
    insertBack(lista, "Livro A", 101, 25.0); // Preço <= 35.0 (Mantido)
    insertBack(lista, "Livro B", 102, 45.0); // Preço > 35.0 (Removido)
    insertBack(lista, "Livro C", 103, 10.0); // Preço <= 35.0 (Mantido)
    insertBack(lista, "Livro D", 104, 50.0); // Preço > 35.0 (Removido)
    insertBack(lista, "Livro E", 105, 36.0); // Preço > 35.0 (Removido)
    insertBack(lista, "Livro F", 106, 20.0); // Preço <= 35.0 (Mantido)
    insertBack(lista, "Livro G", 107, 15.0); // Preço <= 35.0 (Mantido)

    // Aplica o filtro eliminando nós com valor superior a R$ 35.0
    removeOverPrice(lista, 35.0);

    // Validações: devem restar 4 livros (25.0, 10.0, 20.0, 15.0)
    assert(lista->tamanho == 4); 
    assert(lista->inicio->preco == 25.0);        // Primeiro item restante
    assert(lista->inicio->nextNo->preco == 10.0); // Segundo item restante

    liberarLista(lista);
    printf("[PASSOU] - Teste Remove Over Price\n");
}

// -------------------------------------------------------------
// Executor Principal da Suíte de Testes
// -------------------------------------------------------------
int main(){
    printf("\n=== RODANDO SUÍTE DE TESTES UNITÁRIOS ===\n\n");

    // Executa individualmente cada caso de teste
    teste_criarLista();
    teste_insertFront();
    teste_insertBack();
    teste_removeFront();
    teste_removeBack();
    teste_removeOverPrice();

    printf("\n>>> TODOS OS TESTES PASSARAM COM SUCESSO! <<<\n\n");
    return 0; // Sucesso da suíte
}