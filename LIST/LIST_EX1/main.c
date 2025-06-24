#include <stdio.h>
#include <stdlib.h>
#include "listTad.h"

int main(){

    List* li = createList();
    insertStart(li,2);
    insertStart(li,3);
    insertEnd(li,4);
    printList(li);
    printf("Tamano da lista: %d\n",size(li));


    return 0;   
}