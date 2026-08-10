# Aula 1 - Lista Simplesmente Encadeada 📚

Este módulo contém a implementação de uma **Lista Simplesmente Encadeada** em C para gerenciamento de acervo de livros, incluindo inserção na cabeça/cauda, remoção por critérios (preço/código duplicado), módulo de interface interativa e suíte de testes unitários automatizados.

---

## 📂 Estrutura de Arquivos

```text
Aula1_Listas/
├── src/
│   ├── core/
│   │   ├── lista_core.c    # Criação da lista e alocação de nós (Book)
│   │   ├── lista_core.h    # Definição das structs Book e List
│   │   ├── lista_insert.c  # Funções de inserção (insertFront, insertBack)
│   │   ├── lista_insert.h
│   │   ├── lista_remove.c  # Funções de remoção (removeFront, removeBack, removeOverPrice, removeDuplicateCode, freeList)
│   │   ├── lista_remove.h
│   │   └── error.h         # Enumeração de status (Status)
│   ├── ui/
│   │   ├── interface.c     # Interface do usuário, validações de entrada e menu
│   │   └── interface.h
│   └── main.c              # Ponto de entrada do programa interativo
└── testes/
    └── teste_lista.c       # Suíte de testes unitários normais e de exceção
```

---

## ⚡ Como Compilar e Executar (Copiar e Colar)

### 🚀 Executar a Aplicação Interativa (`app`)
```bash
gcc -Wall -Wextra src/main.c src/core/lista_core.c src/core/lista_insert.c src/core/lista_remove.c src/ui/interface.c -I src/core -I src/ui -o app
./app
```

### 🧪 Executar a Suíte de Testes Unitários (`test_runner`)
```bash
gcc -Wall -Wextra src/core/lista_core.c src/core/lista_insert.c src/core/lista_remove.c src/ui/interface.c testes/teste_lista.c -I src/core -I src/ui -o test_runner
./test_runner
```
