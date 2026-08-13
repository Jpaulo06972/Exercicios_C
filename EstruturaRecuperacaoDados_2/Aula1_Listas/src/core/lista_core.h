#ifndef LISTA_CORE_H
#define LISTA_CORE_H

typedef struct Book{
    char name[50];
    int code;
    float price;
    struct Book* nextNode;
} Book;

typedef struct List{
    Book* head;
    int size;
} List;

Book* createNewNode(const char* newName, int newCode, float newPrice);

List* createList();

#endif
