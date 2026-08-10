# Aula 2 - Pilha Encadeada (Stack) 🥞

Este módulo contém a implementação de uma **Pilha Encadeada (LIFO - Last-In, First-Out)** em C, incluindo operações de empilhamento (`push`), desempilhamento (`pop`), desalocação dinâmica (`destroyStack`), interface gráfica/terminal interativa e suíte de testes unitários automatizados.

---

## 📂 Estrutura de Arquivos

```text
Aula2_Pilha/
├── src/
│   ├── core/
│   │   ├── pilha_core.c    # Lógica da pilha (push, pop, createStack, destroyStack)
│   │   ├── pilha_core.h    # Definição das structs StackNode e Stack
│   │   └── error.h         # Enumeração de códigos de erro (StackStatus)
│   ├── ui/
│   │   ├── interface.c     # Exibição gráfica no console e menu do usuário
│   │   └── interface.h
│   └── main.c              # Ponto de entrada do programa interativo
└── testes/
    └── tests_Pilha.c       # Suíte de testes unitários normais e de exceção
```

---

## ⚡ Como Compilar e Executar (Copiar e Colar)

### 🚀 Executar a Aplicação Interativa (`app`)
```bash
gcc -Wall -Wextra src/main.c src/core/pilha_core.c src/ui/interface.c -I src/core -I src/ui -o app
./app
```

### 🧪 Executar a Suíte de Testes Unitários (`test_runner`)
```bash
gcc -Wall -Wextra src/core/pilha_core.c testes/tests_Pilha.c -I src/core -o test_runner
./test_runner
```
