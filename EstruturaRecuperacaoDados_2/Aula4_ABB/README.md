# Aula 4 - Árvore Binária de Busca (ABB) 🌲

Este módulo contém a implementação completa de uma **Árvore Binária de Busca (ABB)** em C, incluindo funções iterativas e recursivas de inserção/remoção, percurso em-ordem, busca do menor elemento, contagem de nós, tratamento de exceções e testes unitários automatizados.

---

## 📂 Estrutura de Arquivos

```text
Aula4_ABB/
├── src/
│   ├── core/
│   │   ├── arvore_core.c   # Implementação comentada da lógica da árvore
│   │   ├── arvore_core.h   # Cabeçalho com structs TreeNode e Tree
│   │   └── error.h         # Enumeração de códigos de erro (TreeStatus)
│   ├── ui/
│   │   ├── interface.c     # Leitura, buscas, relatórios e menu interativo (1-9)
│   │   └── interface.h     # Protótipos das funções da interface de usuário
│   └── main.c              # Ponto de entrada do programa interativo
└── testes/
    └── tests_Arvore.c      # Suíte de testes unitários normais e de exceção
```

---

## ⚡ Como Compilar e Executar

### 1. Executar o Menu Interativo (`app`)
```bash
gcc -Wall -Wextra src/main.c src/core/arvore_core.c src/ui/interface.c -I src/core -I src/ui -o app
./app
```

### 2. Executar a Suíte de Testes Unitários (`test_runner`)
```bash
gcc -Wall -Wextra src/core/arvore_core.c src/ui/interface.c testes/tests_Arvore.c -I src/core -I src/ui -o test_runner
./test_runner
```

---

## 🧪 Casos de Teste Cobertos

1. **Testes de Uso Normal**:
   - Inicialização e pré-condições da árvore (`test_createTree`).
   - Inserção iterativa (`test_insert`) e recursiva (`test_insertRecursive`).
   - Remoção iterativa (`test_removeTreeNode`) e recursiva (`test_removeRecursive`) cobrindo nós folha, intermediários e nó raiz.
   - Busca binária de chaves (`test_findABB`).
   - Busca do menor valor (`test_findSmallABB`).
   - Contagem total de nós (`test_countNode`).

2. **Testes de Erro / Exceções**:
   - Tratamento de ponteiros NULOS (`ERR_TREE_NULL`).
   - Operações em árvores vazias (`ERR_INVALID_INPUT` / `NULL`).
   - Bloqueio de chaves duplicadas (`ERR_INVALID_INPUT`).
   - Tentativa de remoção de nós inexistentes (`ERR_INVALID_INPUT`).
