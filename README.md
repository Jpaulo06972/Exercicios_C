# 💻 EXERCÍCIOS_C - Coleção de Projetos e Estruturas de Dados em C

Portfólio completo da disciplina de **Algoritmos e Estruturas de Dados / Recuperação de Dados** (3º Semestre Faculdade).
O repositório está organizado em 3 grandes pilares acadêmicos, abrangendo desde os fundamentos da linguagem C até estruturas de dados dinâmicas avançadas e árvores binárias de busca.

---

## 🚀 Estrutura do Repositório

```text
Exercicios_C/
├── Algoritmos/                   # Módulo 1: Fundamentos da Linguagem C (Vetores, Matrizes, Ponteiros, Structs)
├── EstruturaRecuperacaoDados_1/   # Módulo 2: Estruturas de Dados Iniciais e Projetos Práticos (Pilha, Fila, Lista, Calculadora, Undo/Redo)
└── EstruturaRecuperacaoDados_2/   # Módulo 3: Estruturas Avançadas Modularizadas (Core/UI), Suítes de Testes Unitários e Árvores (ABB)
```

---

## ⚡ Guia Rápido: Copiar e Colar (Compilar e Rodar)

### 1. 📘 Módulo 1: Algoritmos Fundamentais (`Algoritmos/`)

- **Exemplo - Laços de Repetição (Aula 4)**:
```bash
cd Algoritmos/Aula4_Loops && gcc -Wall -Wextra Ex_1.c -o ex1 && ./ex1
```
- **Exemplo - Ponteiros (Aula 8)**:
```bash
cd Algoritmos/Aula8_Ponteiros && gcc -Wall -Wextra Ex_1.c -o ex1 && ./ex1
```
- **Exemplo - Structs (Aula 10)**:
```bash
cd Algoritmos/Aula10_Structs && gcc -Wall -Wextra Ex_1.c -o ex1 && ./ex1
```

---

### 2. 📗 Módulo 2: Estrutura e Recuperação de Dados I (`EstruturaRecuperacaoDados_1/`)

- **Recursividade (Aula 1)**:
```bash
cd EstruturaRecuperacaoDados_1/Aula1_Recursividade && gcc -Wall -Wextra Ex_1.c -o ex1 && ./ex1
```
- **Listas Encadeadas (Aula 2)**:
```bash
cd EstruturaRecuperacaoDados_1/Aula2_ListasEncadeadas && gcc -Wall -Wextra Ex.c -o ex && ./ex
```
- **Projeto Calculadora de Expressões**:
```bash
cd EstruturaRecuperacaoDados_1/Calculadora && gcc -Wall -Wextra Ex.c -o calc && ./calc
```
- **Projeto Parênteses Balanceados**:
```bash
cd EstruturaRecuperacaoDados_1/ParentesesBalanceados && gcc -Wall -Wextra Ex.c -o par && ./par
```

---

### 3. 📕 Módulo 3: Estrutura e Recuperação de Dados II (`EstruturaRecuperacaoDados_2/`)

#### 📚 Aula 1 - Lista Simplesmente Encadeada
- **Testes Unitários**:
```bash
cd EstruturaRecuperacaoDados_2/Aula1_Listas && gcc -Wall -Wextra src/core/lista_core.c src/core/lista_insert.c src/core/lista_remove.c src/ui/interface.c testes/teste_lista.c -I src/core -I src/ui -o test_runner && ./test_runner
```
- **Aplicação Interativa (Menu)**:
```bash
cd EstruturaRecuperacaoDados_2/Aula1_Listas && gcc -Wall -Wextra src/main.c src/core/lista_core.c src/core/lista_insert.c src/core/lista_remove.c src/ui/interface.c -I src/core -I src/ui -o app && ./app
```

#### 🥞 Aula 2 - Pilha Encadeada (LIFO)
- **Testes Unitários**:
```bash
cd EstruturaRecuperacaoDados_2/Aula2_Pilha && gcc -Wall -Wextra src/core/pilha_core.c testes/tests_Pilha.c -I src/core -o test_runner && ./test_runner
```
- **Aplicação Interativa (Menu)**:
```bash
cd EstruturaRecuperacaoDados_2/Aula2_Pilha && gcc -Wall -Wextra src/main.c src/core/pilha_core.c src/ui/interface.c -I src/core -I src/ui -o app && ./app
```

#### 🚶‍♂️🚶‍♀️ Aula 3 - Fila Encadeada (FIFO)
- **Testes Unitários**:
```bash
cd EstruturaRecuperacaoDados_2/Aula3_Fila && gcc -Wall -Wextra src/core/fila_core.c testes/tests_Fila.c -I src/core -o test_runner && ./test_runner
```
- **Aplicação Interativa (Menu)**:
```bash
cd EstruturaRecuperacaoDados_2/Aula3_Fila && gcc -Wall -Wextra src/main.c src/core/fila_core.c src/ui/interface.c -I src/core -I src/ui -o app && ./app
```

#### 🌲 Aula 4 - Árvore Binária de Busca (ABB)
- **Testes Unitários**:
```bash
cd EstruturaRecuperacaoDados_2/Aula4_ABB && gcc -Wall -Wextra src/core/arvore_core.c src/ui/interface.c testes/tests_Arvore.c -I src/core -I src/ui -o test_runner && ./test_runner
```
- **Aplicação Interativa (Menu)**:
```bash
cd EstruturaRecuperacaoDados_2/Aula4_ABB && gcc -Wall -Wextra src/main.c src/core/arvore_core.c src/ui/interface.c -I src/core -I src/ui -o app && ./app
```

---

## 🧪 Rodar TODOS os Testes do Módulo 3 de Uma Vez Só
```bash
(cd EstruturaRecuperacaoDados_2/Aula1_Listas && gcc -Wall -Wextra src/core/lista_core.c src/core/lista_insert.c src/core/lista_remove.c src/ui/interface.c testes/teste_lista.c -I src/core -I src/ui -o test_runner && ./test_runner) && (cd EstruturaRecuperacaoDados_2/Aula2_Pilha && gcc -Wall -Wextra src/core/pilha_core.c testes/tests_Pilha.c -I src/core -o test_runner && ./test_runner) && (cd EstruturaRecuperacaoDados_2/Aula3_Fila && gcc -Wall -Wextra src/core/fila_core.c testes/tests_Fila.c -I src/core -o test_runner && ./test_runner) && (cd EstruturaRecuperacaoDados_2/Aula4_ABB && gcc -Wall -Wextra src/core/arvore_core.c src/ui/interface.c testes/tests_Arvore.c -I src/core -I src/ui -o test_runner && ./test_runner)
```

---

## ⚙️ Compilação Genérica
Para qualquer arquivo `.c` individual do repositório:
```bash
gcc -Wall -Wextra nome_do_arquivo.c -o programa && ./programa
```
