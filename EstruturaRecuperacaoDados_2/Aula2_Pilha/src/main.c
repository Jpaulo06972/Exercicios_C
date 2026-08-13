#include <stdio.h>

#include "core/pilha_core.h"

#include "ui/interface.h"

int main() {

    Stack* myStack = createStack();

    if (myStack != NULL) {

        runMenu(myStack);

        destroyStack(myStack);

    } else {

        printf("Erro Critico: Falha ao inicializar a pilha por falta de memoria.\n");
    }

    return 0;
}
