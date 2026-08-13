#include <stdio.h>
#include "core/lista_core.h"
#include "core/lista_remove.h"
#include "ui/interface.h"

int main(){

    List* myList = createList();

    if (myList != NULL){

        menu(myList);

        freeList(myList);
    } else {

        printf("Erro ao iniciar a lista.\n");
    }

    return 0;
}
