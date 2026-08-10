// Biblioteca padrão para alocação de memória dinâmica (malloc, free)
#include <stdlib.h>
// Biblioteca para manipulação de strings (inclusão preventiva para extensões futuras)
#include <string.h>
// Biblioteca padrão de entrada e saída (usada para funções de impressão como printf)
#include <stdio.h>
// Inclui o cabeçalho local com a definição das estruturas TreeNode e Tree, além dos protótipos
#include "arvore_core.h"
// Inclui as definições dos códigos de status de retorno e erros do sistema
#include "error.h"

// --------------------------------------------- //
//         Função para Criar um Novo Nó          //
// --------------------------------------------- //
// Aloca memória dinamicamente na Heap para um nó individual e inicializa seus valores.
TreeNode* createNode(int value){

    // Pedimos ao sistema operacional um espaço na Heap com o tamanho exato da struct TreeNode
    TreeNode* newNode = (TreeNode*) malloc (sizeof(TreeNode));

    // Valida se a alocação foi bem-sucedida ou se o sistema ficou sem memória (malloc retornou NULL)
    // Retorna NULL imediatamente para quem chamou tratar essa falha de memória RAM
    if (newNode == NULL) return NULL;

    // Armazena o valor inteiro informado dentro do campo 'value' do nó recém-criado
    newNode->value = value;

    // Inicializa os ponteiros dos nós filhos como NULL, pois o nó acabou de ser criado e não possui ramificações
    newNode->left  = NULL;
    // O ponteiro da direita também aponta para NULL inicialmente
    newNode->right = NULL;

    // Retorna o ponteiro do nó criado, alocado e pronto para ser vinculado à árvore
    return newNode;
}


// --------------------------------------------- //
//     Função para Criar a Árvore Principal      //
// --------------------------------------------- //
// Instancia a estrutura descritora que gerencia a referência principal da árvore (a raiz).
Tree* createTree(){

    // Aloca espaço na memória Heap para a estrutura descritora principal 'Tree'
    Tree* tree = (Tree*) malloc (sizeof(Tree));

    // Verifica se a alocação de memória para a estrutura descritora falhou
    if (tree == NULL) return NULL;

    // Inicializa o ponteiro da raiz ('root') como NULL, indicando que a árvore nasce totalmente vazia
    tree->root = NULL;

    // Retorna o ponteiro da estrutura descritora da árvore inicializada
    return tree;
}


// --------------------------------------------- //
//                Função de Insert               //
// --------------------------------------------- //
// Adiciona um novo elemento na Árvore Binária de Busca (ABB) usando uma abordagem iterativa (com laço while).
TreeStatus insert(Tree* tree, int value){
    
    // Valida se o ponteiro da árvore recebido existe na memória antes de operá-lo
    // Retorna código de erro informando que o ponteiro da árvore é inválido (nulo)
    if (tree == NULL) return ERR_TREE_NULL;

    // Aloca a memória na Heap e cria um novo nó contendo o valor desejado
    TreeNode* newNode = createNode(value);

    // Verifica se a alocação do nó falhou por falta de memória RAM no sistema
    // Retorna código de erro notificando estouro/falha de alocação de memória
    if (newNode == NULL) return ERR_OUT_OF_MEMORY;

    // Trata o caso inicial: se a árvore estiver vazia (raiz é NULL), o novo nó torna-se o primeiro elemento
    if (tree->root == NULL){
        
        // Define o nó recém-criado como sendo a própria raiz da árvore
        tree->root = newNode;

        // Retorna status indicando sucesso na inserção da raiz
        return STATUS_SUCCESS;
    }

    // Inicializa o ponteiro de navegação 'current' na raiz para percorrer a árvore
    TreeNode* current = tree->root;
    // Guarda a referência do nó pai para conectar o novo nó quando acharmos a posição vaga
    TreeNode* father  = NULL;

    // Navega pela árvore binária de busca até encontrar um ponteiro folha (NULL)
    while(current != NULL){

        // Atualiza a referência do pai para o nó atual antes de descer para o próximo nível
        father = current;

        // Verifica se o valor já existe na árvore (regra da ABB: não aceita chaves duplicadas)
        if (current->value == value) {
            // Como o nó 'newNode' já havia sido alocado, precisamos liberá-lo para não gerar leak de memória
            free(newNode);
            // Retorna erro informando que a entrada é inválida (valor duplicado)
            return ERR_INVALID_INPUT;
        }

        // Aplica a propriedade fundamental da ABB para decidir se avança para a esquerda ou para a direita
        if (newNode->value < current->value){
            // Se o novo valor for menor que o nó atual, desce pelo ramo esquerdo
            current = current->left;
        } else {
            // Se o novo valor for maior que o nó atual, desce pelo ramo direito
            current = current->right;
        }
    }

    // Encontrada a posição nula, verifica se o novo elemento ficará à direita ou à esquerda do nó pai
    if (newNode->value > father->value) {
        // Se for maior que o valor do pai, conecta como filho da direita
        father->right = newNode;
    } else {
        // Se for menor que o valor do pai, conecta como filho da esquerda
        father->left = newNode;
    }

    // Retorna status de sucesso na operação de inserção
    return STATUS_SUCCESS;
}


// --------------------------------------------- //
//    Função de Insert Node com Recursividade    //
// --------------------------------------------- //
// Função auxiliar interna (static) que percorre a árvore recursivamente e conecta o novo nó na posição correta.
static TreeStatus insertNodeRecursive(TreeNode* root, TreeNode* newNode){

    // Verifica se o novo valor deve ser posicionado na subárvore da esquerda (novo valor < nó atual)
    if (newNode->value < root->value){

        // Verifica se alcançou o fim da ramificação à esquerda (folha)
        if (root->left == NULL) {

            // Conecta o novo nó no ponteiro vago da esquerda
            root->left = newNode;

            // Retorna sucesso encerrando as chamadas recursivas
            return STATUS_SUCCESS;         
        } 

        // Caso ainda existam nós à esquerda, chama a função recursivamente descendo para o filho esquerdo
        return insertNodeRecursive(root->left, newNode);

    // Caso o valor a ser inserido seja exatamente igual ao do nó atual (duplicata detectada)
    } else if (newNode->value == root->value){

        // Libera a memória do nó alocado que não será utilizado para impedir vazamento de memória
        free(newNode);

        // Retorna o código de erro para informar entrada inválida por chave duplicada
        return ERR_INVALID_INPUT;

    // Se o novo valor for maior que o valor do nó atual, devemos caminhar pela direita
    } else {
        
        // Verifica se alcançou o fim da ramificação à direita (folha)
        if (root->right == NULL) {

            // Conecta o novo nó no ponteiro vago da direita
            root->right = newNode;

            // Retorna sucesso encerrando as chamadas recursivas
            return STATUS_SUCCESS;         
        } 

        // Caso ainda existam nós à direita, chama a função recursivamente descendo para o filho direito
        return insertNodeRecursive(root->right, newNode);
    }
}

// --------------------------------------------- //
//       Função de Insert com Recursividade      //
// --------------------------------------------- //
// Ponto de entrada público para inserção recursiva na árvore (valida estado inicial e dispara a recursão).
TreeStatus insertRecursive(Tree* tree, int value){
    
    // Valida se o ponteiro da estrutura da árvore recebido é válido
    // Retorna erro caso o ponteiro para a árvore seja nulo
    if (tree == NULL) return ERR_TREE_NULL;

    // Aloca a memória na Heap para criar o nó com o valor especificado
    TreeNode* newNode = createNode(value);

    // Verifica se o processo de criação do nó falhou por indisponibilidade de RAM
    // Retorna erro por falha de alocação de memória
    if (newNode == NULL) return ERR_OUT_OF_MEMORY;

    // Verifica se a árvore está totalmente vazia (raiz aponta para NULL)
    if (tree->root == NULL){
        
        // O nó recém-criado assume o papel de raiz principal da árvore
        tree->root = newNode;

        // Retorna status de sucesso
        return STATUS_SUCCESS;
    }

    // Delega a inserção navegando recursivamente a partir da raiz da árvore
    return insertNodeRecursive(tree->root, newNode);
}


// --------------------------------------------- //
//               Função de Remove                //
// --------------------------------------------- //
// Remove um nó contendo o valor especificado da árvore, garantindo a reorganização dos ponteiros (iterativo).
TreeStatus removeTreeNode(Tree* tree, int value){

    // Valida se a estrutura da árvore recebida existe na memória
    // Retorna erro de ponteiro nulo para a árvore
    if (tree == NULL) return ERR_TREE_NULL;

    // Guarda ponteiros de rastreamento: 'current' para o nó a ser removido e 'father' para o seu pai
    TreeNode* current = tree->root;
    TreeNode* father  = NULL;

    // Percorre os ramos da árvore binária até encontrar o nó que contém o valor buscado
    while (current != NULL && current->value != value){
        
        // Atualiza a referência do pai antes de caminhar no percurso
        father = current;

        // Decide a direção da navegação comparando o valor buscado com o nó atual
        if (value < current->value){
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // Se navegou até o fim (NULL) e não achou o nó com o valor informado, retorna erro de entrada inválida
    if (current == NULL) return ERR_INVALID_INPUT;

    // CASO 1: O nó a ser removido é folha (0 filhos) ou possui apenas 1 filho (grau 0 ou 1)
    if (current->left == NULL || current->right == NULL){

        // Identifica qual é o único filho existente (ou NULL caso seja um nó folha sem filhos)
        TreeNode* aux = (current->left != NULL) ? current->left : current->right;

        // Se 'father' for NULL, significa que o nó a ser removido é a própria RAIZ da árvore
        if (father == NULL){
            // Atualiza a raiz da árvore para apontar para o filho restante (ou NULL se a árvore esvaziar)
            tree->root = aux;

        // Se o nó a ser removido for o filho da ESQUERDA do nó pai
        } else if (father->left == current){
            // Atualiza o ponteiro esquerdo do pai para conectar diretamente ao filho substituinte 'aux'
            father->left = aux;
        
        // Se o nó a ser removido for o filho da DIREITA do nó pai
        } else {
            // Atualiza o ponteiro direito do pai para conectar diretamente ao filho substituinte 'aux'
            father->right = aux;
        }

        // Deleta a memória alocada do nó removido para evitar vazamentos de memória (memory leak)
        free(current);

        // Retorna status informando sucesso na remoção
        return STATUS_SUCCESS;

    // CASO 2: O nó a ser removido possui 2 filhos (grau 2)
    } else {

        // Prepara a substituição procurando um nó para assumir a posição do nó que será excluído
        TreeNode* successor = current->right;
        TreeNode* successorFather = current;

        // Caminha até o nó mais à esquerda no ramo a partir de 'current'
        while(successor->left != NULL){

            // Atualiza o pai do nó substituto
            successorFather = successor;

            // Avança para o nó mais à esquerda
            successor = successor->left;
        }

        // Ajusta as conexões se o nó substituto não for o próprio filho imediato
        if (successorFather != current){
            // O pai do substituto adota a subárvore direita do substituto na sua ponte esquerda
            successorFather->left = successor->right;
            // O substituto recebe a subárvore direita do nó que está sendo removido
            successor->right = current->right;
        }

        // O substituto recebe a subárvore esquerda do nó que está sendo removido
        successor->left = current->left;

        // Reconecta a referência do nó pai ('father') para apontar para o novo substituto
        if (father == NULL){
            // Se o nó removido era a raiz principal, o substituto assume o topo da árvore
            tree->root = successor;
        } else if(father->left == current){
            // Se o nó removido era o filho esquerdo do pai, reconecta a esquerda do pai no substituto
            father->left = successor;
        } else {
            // Se o nó removido era o filho direito do pai, reconecta a direita do pai no substituto
            father->right = successor;
        }

        // Desaloca a memória do nó que foi removido e substituído
        free(current);

        // Retorna status indicando sucesso na remoção
        return STATUS_SUCCESS;
    }
}


// --------------------------------------------- //
//    Função de Remove Node com Recursividade    //
// --------------------------------------------- //
// Função auxiliar privada (static) que percorre recursivamente a árvore para remover o nó desejado.
static TreeStatus removeNodeRecursive(Tree* tree, TreeNode* root, TreeNode* father, int value){

    // Valida se atingiu o fim de um ramo sem encontrar o valor desejado (evita acessar NULL->value)
    if (root == NULL) {
        // Retorna erro sinalizando que o valor informado não existe na árvore
        return ERR_INVALID_INPUT;
    }

    // Navega para a subárvore da esquerda se o valor buscado for menor que o valor do nó atual
    if (value < root->value) {
        // Chamada recursiva descendo pelo ramo esquerdo, passando o nó atual como pai
        return removeNodeRecursive(tree, root->left, root, value);
    // Navega para a subárvore da direita se o valor buscado for maior que o valor do nó atual
    } else if (value > root->value){
        // Chamada recursiva descendo pelo ramo direito, passando o nó atual como pai
        return removeNodeRecursive(tree, root->right, root, value);
    } 

    // CASO 1: O nó a ser removido tem no máximo 1 filho (0 filhos ou 1 subárvore ligada a ele)
    if (root->left == NULL || root->right == NULL){

        // Identifica o único filho existente (ou NULL caso seja um nó folha sem filhos)
        TreeNode* aux = (root->left != NULL) ? root->left : root->right;

        // Se 'father' for NULL, significa que o nó a ser removido é a própria RAIZ principal da árvore
        if (father == NULL){
            // Atualiza a raiz da estrutura descritora principal 'tree' apontando para 'aux'
            tree->root = aux;

        // Se o nó a ser removido for o filho da ESQUERDA do seu nó pai
        } else if (father->left == root){
            // Atualiza o ponteiro esquerdo do pai para conectar diretamente ao filho substituinte 'aux'
            father->left = aux;
        
        // Se o nó a ser removido for o filho da DIREITA do seu nó pai
        } else {
            // Atualiza o ponteiro direito do pai para conectar diretamente ao filho substituinte 'aux'
            father->right = aux;
        }

        // Libera a memória alocada do nó removido para evitar vazamentos de memória (memory leak)
        free(root);

        // Retorna status informando sucesso na remoção
        return STATUS_SUCCESS;

    // CASO 2: O nó a ser removido possui 2 filhos (grau 2)    
    } else {

        // Prepara a substituição buscando o menor elemento na subárvore da direita (sucessor em-ordem)
        TreeNode* successor = root->right;
        TreeNode* successorFather = root;

        // Navega para a esquerda enquanto houver filhos à esquerda para encontrar o menor valor
        while(successor->left != NULL){

            // Atualiza o pai do substituto antes de descer
            successorFather = successor;

            // Avança para o filho da esquerda
            successor = successor->left;
        }

        // Se o substituto não for o próprio filho imediato à direita do nó a ser removido
        if (successorFather != root){
            // O pai do substituto herda a subárvore direita do substituto na sua ponte esquerda
            successorFather->left = successor->right;
            // O substituto assume a subárvore direita do nó que está sendo removido
            successor->right = root->right;
        }

        // O substituto assume a subárvore esquerda do nó que está sendo removido
        successor->left = root->left;

        // Reconecta a referência do nó pai ('father') para apontar para o novo substituto
        if (father == NULL){
            // Se o nó removido era a raiz principal, o substituto assume o topo da árvore
            tree->root = successor;
        } else if(father->left == root){
            // Se o nó removido era o filho esquerdo do pai, reconecta a esquerda do pai no substituto
            father->left = successor;
        } else {
            // Se o nó removido era o filho direito do pai, reconecta a direita do pai no substituto
            father->right = successor;
        }

        // Desaloca a memória do nó que foi removido e substituído
        free(root);

        // Retorna status indicando sucesso na remoção
        return STATUS_SUCCESS;
    } 
}

// --------------------------------------------- //
//       Função de Remove com Recursividade      //
// --------------------------------------------- //
// Ponto de entrada público para remoção recursiva na árvore (valida o descritor e dispara a recursão).
TreeStatus removeRecursive(Tree* tree, int value){

    // Valida se o ponteiro da estrutura da árvore recebido é válido
    // Retorna erro caso o ponteiro para a árvore seja nulo
    if (tree == NULL) return ERR_TREE_NULL;

    // Se a árvore estiver vazia (raiz nula), retorna erro informando que o elemento não foi encontrado
    if (tree->root == NULL) return ERR_INVALID_INPUT;

    // Chama a função recursiva auxiliar passando a árvore, a raiz inicial e NULL para o pai inicial
    return removeNodeRecursive(tree, tree->root, NULL, value);
}


// --------------------------------------------- //
//     Função para Liberar os Nós da Árvore      //
// --------------------------------------------- //
// Libera recursivamente a memória de todos os nós da árvore usando o percurso em Pós-Ordem.
static void freeTreeNode(TreeNode* root){

    // Verifica se o nó recebido não é nulo antes de prosseguir com a desalocação
    if (root != NULL) {

        // Libera primeiramente todos os nós da subárvore à esquerda de forma recursiva
        freeTreeNode(root->left);
        // Libera em seguida todos os nós da subárvore à direita de forma recursiva
        freeTreeNode(root->right);

        // Com ambos os filhos desalocados com segurança, libera a memória do nó atual
        free(root);
    }
}


// --------------------------------------------- //
//   Função para Liberar a Estrutura da Árvore   //
// --------------------------------------------- //
// Desaloca toda a memória alocada para a árvore (todos os nós e a estrutura descritora principal).
void freeTree(Tree* tree){

    // Se o ponteiro recebido para a estrutura da árvore for NULL, encerra imediatamente sem ação
    if (tree == NULL) return;

    // Se a árvore contiver elementos encadeados, invoca a função para desalocar todos os nós
    if (tree->root != NULL){
        // Chama a função estática recursiva para desalocar a estrutura de nós a partir da raiz
        freeTreeNode(tree->root);
    }
    
    // Libera a memória alocada para a estrutura descritora da árvore 'Tree' em si
    free(tree);
}
