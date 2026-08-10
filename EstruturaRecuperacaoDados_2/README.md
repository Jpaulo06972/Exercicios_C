# Estruturas de Dados II - Exercícios em C 🚀

Repositório da disciplina de **Estruturas de Dados / Recuperação de Dados II** (3º Semestre Faculdade).
O repositório contém implementações completas em linguagem C (ISO C99/C11) de estruturas de dados fundamentais, incluindo módulo **Core** (lógica de ponteiros e manipulação de memória), módulo **UI** (menu interativo no terminal e tratamento de erros) e **Suíte de Testes Unitários Automatizados**.

---

## 📂 Estrutura do Repositório

```text
Exercicios_C/EstruturaRecuperacaoDados_2/
├── Aula1_Listas/       # Lista Simplesmente Encadeada (Gestão de Livros)
├── Aula2_Pilha/        # Pilha Encadeada (LIFO - Last-In, First-Out)
├── Aula3_Fila/         # Fila Encadeada (FIFO - First-In, First-Out)
├── Aula4_ABB/          # Árvore Binária de Busca (ABB - Binary Search Tree)
├── Aula5_AVL/          # Árvore AVL (Balanceamento Automático)
└── Aula6_Grafos/       # Algoritmos e Representação de Grafos
```

---

## 🌲 Aula 4 - Árvore Binária de Busca (ABB)

A **Árvore Binária de Busca (ABB)** é uma estrutura hierárquica na qual cada nó possui no máximo dois filhos (`left` e `right`), satisfazendo a propriedade fundamental da ABB:
- **Subárvore Esquerda**: Todos os nós possuem chave **menor** que o nó atual.
- **Subárvore Direita**: Todos os nós possuem chave **maior** que o nó atual.

### 🛠️ Funcionalidades Implementadas (`src/core/arvore_core.c`)

1. **Criação e Alocação**:
   - `createNode(int value)`: Aloca dinamicamente um nó `TreeNode` na memória Heap.
   - `createTree()`: Instancia a estrutura descritora principal `Tree`.
2. **Inserção**:
   - `insert(Tree* tree, int value)`: Inserção iterativa em tempo $O(h)$.
   - `insertRecursive(Tree* tree, int value)`: Inserção recursiva com rejeição automática de chaves duplicadas (`ERR_INVALID_INPUT`).
3. **Remoção**:
   - `removeTreeNode(Tree* tree, int value)`: Remoção iterativa de nós (grau 0: folha, grau 1: 1 filho, grau 2: 2 filhos).
   - `removeRecursive(Tree* tree, int value)`: Remoção recursiva mantendo reconexão dos ponteiros e tratamento de remoção da raiz principal.
4. **Desalocação de Memória**:
   - `freeTree(Tree* tree)` / `freeTreeNode(TreeNode* root)`: Percurso em pós-ordem para desalocação de todos os nós e liberação da Heap.

### 🖥️ Módulo de Interface (`src/ui/interface.c`)

- **Funções de Leitura e Exibição**:
  - `findABB(Tree* tree, int value)`: Busca binária por chave na árvore.
  - `findSmallABB(Tree* tree)`: Localização do nó com o menor valor (extremidade esquerda).
  - `countNode(TreeNode* root)`: Contagem recursiva da quantidade total de nós.
  - `dislpay(TreeNode* root)`: Percurso em-ordem simétrica (impressão ordenada).
  - `handleStatus(TreeStatus status)`: Tradução dos enums de erro/sucesso para o usuário.
  - `readPositiveInt(const char* prompt)`: Leitura sanitizada com limpeza do buffer do teclado.

- **Menu Interativo (Opções 1 a 9)**:
  1. Inserir um Novo Valor na Árvore (Iterativo)
  2. Inserir um Novo Valor na Árvore com Recursividade
  3. Remover um Valor da Árvore (Iterativo)
  4. Remover um Valor da Árvore com Recursividade
  5. Buscar um Valor na Árvore
  6. Imprimir Todos os Elementos em Ordem
  7. Contar a Quantidade de Nós na Árvore
  8. Buscar o Menor Valor da Árvore
  9. Sair

---

## 🧪 Suítes de Testes Unitários Automatizados

Cada módulo possui uma suíte de testes dedicada localizada no diretório `testes/`, cobrindo tanto casos normais de uso quanto **testes de erro e cenários de exceção**:

- **Ponteiros Nulos** (`ERR_TREE_NULL`, `ERR_STACK_NULL`, `ERR_QUEUE_NULL`, `ERR_LIST_NULL`).
- **Estruturas Vazias / Underflow** (`ERR_TREE_EMPTY`, `ERR_STACK_EMPTY`, `ERR_QUEUE_EMPTY`, `ERR_EMPTY_LIST`).
- **Chaves Duplicadas / Nós Inexistentes** (`ERR_INVALID_INPUT`, `ERR_INVALID_PARAM`).

### ⚡ Como Compilar e Rodar os Testes

#### 1. Testes da Árvore (Aula4_ABB)
```bash
cd Aula4_ABB
gcc -Wall -Wextra src/core/arvore_core.c src/ui/interface.c testes/tests_Arvore.c -I src/core -I src/ui -o test_runner
./test_runner
```

#### 2. Aplicação Interativa da Árvore (Aula4_ABB)
```bash
cd Aula4_ABB
gcc -Wall -Wextra src/main.c src/core/arvore_core.c src/ui/interface.c -I src/core -I src/ui -o app
./app
```

#### 3. Testes da Pilha (Aula2_Pilha)
```bash
cd Aula2_Pilha
gcc -Wall -Wextra src/core/pilha_core.c testes/tests_Pilha.c -I src/core -o test_runner
./test_runner
```

#### 4. Testes da Fila (Aula3_Fila)
```bash
cd Aula3_Fila
gcc -Wall -Wextra src/core/fila_core.c testes/tests_Fila.c -I src/core -o test_runner
./test_runner
```

#### 5. Testes da Lista Encadeada (Aula1_Listas)
```bash
cd Aula1_Listas
gcc -Wall -Wextra src/core/lista_core.c src/core/lista_insert.c src/core/lista_remove.c src/ui/interface.c testes/teste_lista.c -I src/core -I src/ui -o test_runner
./test_runner
```

---

## ⚙️ Tecnologias e Boas Práticas

- **Linguagem C**: Compilação sem avisos (`-Wall -Wextra`).
- **Gestão Manual de Memória**: Uso rigoroso de `malloc()` e `free()` com verificações anti-vazamento.
- **Desenvolvimento Guiado por Assertivas**: Testes unitários com a biblioteca `<assert.h>`.
- **Tratamento Robusto de Erros**: Sinalização via enums tipados (`TreeStatus`, `StackStatus`, `QueueStatus`, `Status`).
