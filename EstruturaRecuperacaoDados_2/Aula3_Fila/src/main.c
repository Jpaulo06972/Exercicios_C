#include <stdio.h>

#include "core/fila_core.h"

#include "ui/interface.h"

int main() {

    Queue* myQueue = createQueue();

    if (myQueue != NULL) {

        runMenu(myQueue);

        destroyQueue(myQueue);

    } else {

        printf("Erro Critico: Falha ao inicializar a fila por falta de memoria.\n");
    }

    return 0;
}
