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

## ⚡ Guia Rápido: Copiar e Colar (Compilar e Rodar)

Abaixo estão todos os comandos prontos para **copiar, colar e rodar** em cada um dos módulos do projeto:

### 1. 📚 Aula 1 - Lista Simplesmente Encadeada (`Aula1_Listas`)

- **Rodar Testes Unitários Automatizados**:
```bash
cd Aula1_Listas && gcc -Wall -Wextra src/core/lista_core.c src/core/lista_insert.c src/core/lista_remove.c src/ui/interface.c testes/teste_lista.c -I src/core -I src/ui -o test_runner && ./test_runner
```

- **Rodar Aplicação Interativa (Menu)**:
```bash
cd Aula1_Listas && gcc -Wall -Wextra src/main.c src/core/lista_core.c src/core/lista_insert.c src/core/lista_remove.c src/ui/interface.c -I src/core -I src/ui -o app && ./app
```

---

### 2. 🥞 Aula 2 - Pilha Encadeada (`Aula2_Pilha`)

- **Rodar Testes Unitários Automatizados**:
```bash
cd Aula2_Pilha && gcc -Wall -Wextra src/core/pilha_core.c testes/tests_Pilha.c -I src/core -o test_runner && ./test_runner
```

- **Rodar Aplicação Interativa (Menu)**:
```bash
cd Aula2_Pilha && gcc -Wall -Wextra src/main.c src/core/pilha_core.c src/ui/interface.c -I src/core -I src/ui -o app && ./app
```

---

### 3. 🚶‍♂️🚶‍♀️ Aula 3 - Fila Encadeada (`Aula3_Fila`)

- **Rodar Testes Unitários Automatizados**:
```bash
cd Aula3_Fila && gcc -Wall -Wextra src/core/fila_core.c testes/tests_Fila.c -I src/core -o test_runner && ./test_runner
```

- **Rodar Aplicação Interativa (Menu)**:
```bash
cd Aula3_Fila && gcc -Wall -Wextra src/main.c src/core/fila_core.c src/ui/interface.c -I src/core -I src/ui -o app && ./app
```

---

### 4. 🌲 Aula 4 - Árvore Binária de Busca (`Aula4_ABB`)

- **Rodar Testes Unitários Automatizados**:
```bash
cd Aula4_ABB && gcc -Wall -Wextra src/core/arvore_core.c src/ui/interface.c testes/tests_Arvore.c -I src/core -I src/ui -o test_runner && ./test_runner
```

- **Rodar Aplicação Interativa (Menu)**:
```bash
cd Aula4_ABB && gcc -Wall -Wextra src/main.c src/core/arvore_core.c src/ui/interface.c -I src/core -I src/ui -o app && ./app
```

---

## 🧪 Rodar TODOS os Testes do Repositório de Uma Vez só

Para compilar e validar todas as suítes de testes em sequência:

```bash
(cd Aula1_Listas && gcc -Wall -Wextra src/core/lista_core.c src/core/lista_insert.c src/core/lista_remove.c src/ui/interface.c testes/teste_lista.c -I src/core -I src/ui -o test_runner && ./test_runner) && (cd Aula2_Pilha && gcc -Wall -Wextra src/core/pilha_core.c testes/tests_Pilha.c -I src/core -o test_runner && ./test_runner) && (cd Aula3_Fila && gcc -Wall -Wextra src/core/fila_core.c testes/tests_Fila.c -I src/core -o test_runner && ./test_runner) && (cd Aula4_ABB && gcc -Wall -Wextra src/core/arvore_core.c src/ui/interface.c testes/tests_Arvore.c -I src/core -I src/ui -o test_runner && ./test_runner)
```

---

## ⚙️ Tecnologias e Boas Práticas

- **Linguagem C**: Compilação sem avisos (`-Wall -Wextra`).
- **Gestão Manual de Memória**: Uso de `malloc()` e `free()` com verificações rigorosas anti-vazamento.
- **Desenvolvimento Guiado por Assertivas**: Testes unitários com a biblioteca `<assert.h>`.
- **Tratamento Robusto de Erros**: Sinalização via enums tipados (`TreeStatus`, `StackStatus`, `QueueStatus`, `Status`).
