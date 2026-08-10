# Aula 3 - Fila Encadeada (Queue) 🚶‍♂️🚶‍♀️

Este módulo contém a implementação de uma **Fila Encadeada (FIFO - First-In, First-Out)** em C, incluindo operações de enfileiramento (`enqueue`), desenfileiramento (`dequeue`), destruição/liberação de memória (`destroyQueue`), interface interativa via terminal e suíte de testes unitários automatizados.

---

## 📂 Estrutura de Arquivos

```text
Aula3_Fila/
├── src/
│   ├── core/
│   │   ├── fila_core.c     # Lógica da fila (enqueue, dequeue, createQueue, destroyQueue)
│   │   ├── fila_core.h     # Definição das structs QueueNode e Queue (head, tail, size)
│   │   └── error.h         # Enumeração de códigos de erro (QueueStatus)
│   ├── ui/
│   │   ├── interface.c     # Exibição visual da fila e menu do usuário
│   │   └── interface.h
│   └── main.c              # Ponto de entrada do programa interativo
└── testes/
    └── tests_Fila.c        # Suíte de testes unitários normais e de exceção
```

---

## ⚡ Como Compilar e Executar (Copiar e Colar)

### 🚀 Executar a Aplicação Interativa (`app`)
```bash
gcc -Wall -Wextra src/main.c src/core/fila_core.c src/ui/interface.c -I src/core -I src/ui -o app
./app
```

### 🧪 Executar a Suíte de Testes Unitários (`test_runner`)
```bash
gcc -Wall -Wextra src/core/fila_core.c testes/tests_Fila.c -I src/core -o test_runner
./test_runner
```
