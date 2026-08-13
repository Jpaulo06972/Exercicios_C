#include <stdio.h>
#include "core/arvore_core.h"
#include "ui/interface.h"

int main() {

    Tree* myTree = createTree();

    if (myTree != NULL){

        runMenu(myTree);

        freeTree(myTree);
    } else {

        printf("Erro ao iniciar a arvore.\n");
    }

    return 0;
}
